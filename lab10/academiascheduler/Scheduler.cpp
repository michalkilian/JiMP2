//
// Created by Michał on 2018-05-21.
//

#include "Scheduler.h"

namespace academia {
    int SchedulingItem::CourseId() const { return course_id; }

    int SchedulingItem::RoomId() const { return room_id; }

    int SchedulingItem::TeacherId() const { return teacher_id; }

    int SchedulingItem::TimeSlot() const { return time_slot; }

    int SchedulingItem::Year() const { return year; }

    void SchedulingItem::setRoom_id(int room_id) {
        SchedulingItem::room_id = room_id;
    }

    void SchedulingItem::setTime_slot(int time_slot) {
        SchedulingItem::time_slot = time_slot;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        this->SchedulingItems.push_back(item);
    }

    std::size_t Schedule::Size() const {
        return this->SchedulingItems.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
        return this->SchedulingItems[index];
    }

    Schedule Schedule::OfTeacher(int teacherId) const {
        std::vector<SchedulingItem> schedulingItemsOfTeacher(this->SchedulingItems.size());
        auto it = std::copy_if(this->SchedulingItems.begin(), this->SchedulingItems.end(),
                               schedulingItemsOfTeacher.begin(),
                               [teacherId](SchedulingItem item) { return (item.TeacherId() == teacherId); });
        schedulingItemsOfTeacher.resize(std::distance(schedulingItemsOfTeacher.begin(), it));

        return Schedule{schedulingItemsOfTeacher};
    }

    Schedule Schedule::OfRoom(int roomId) const {
        std::vector<SchedulingItem> schedulingItemsOfRoom(this->SchedulingItems.size());
        auto it = std::copy_if(this->SchedulingItems.begin(), this->SchedulingItems.end(),
                               schedulingItemsOfRoom.begin(),
                               [roomId](SchedulingItem item) { return (item.RoomId() == roomId); });
        schedulingItemsOfRoom.resize(std::distance(schedulingItemsOfRoom.begin(), it));

        return Schedule{schedulingItemsOfRoom};
    }

    Schedule Schedule::OfYear(int year) const {
        std::vector<SchedulingItem> schedulingItemsOfYear(this->SchedulingItems.size());
        auto it = std::copy_if(this->SchedulingItems.begin(), this->SchedulingItems.end(),
                               schedulingItemsOfYear.begin(),
                               [year](SchedulingItem item) { return (item.Year() == year); });
        schedulingItemsOfYear.resize(std::distance(schedulingItemsOfYear.begin(), it));

        return Schedule{schedulingItemsOfYear};
    }

    std::vector<int> Schedule::AvailableTimeSlots(int maximumTimeSlot) const {
        std::vector<int> unavailableTimeSlots;
        std::vector<int> availableTimeSlots;

        for (auto item : this->SchedulingItems) {
            if (item.TimeSlot() <= maximumTimeSlot)
                unavailableTimeSlots.push_back(item.TimeSlot());
        }
        for (int i = 1; i <= maximumTimeSlot; i++) {
            if (std::find(unavailableTimeSlots.begin(), unavailableTimeSlots.end(), i) == unavailableTimeSlots.end())
                availableTimeSlots.push_back(i);
        }
        return availableTimeSlots;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        std::vector<SchedulingItem> schedulingItems;
        std::vector<std::pair<int, int>> roomsAndTimeSlots;

        for (auto yearCourse = courses_of_year.begin(); yearCourse != courses_of_year.end(); ++yearCourse) {
            for (int course : yearCourse->second) {
                int courseNumber = 0;
                for (auto teacherCourse = teacher_courses_assignment.begin();
                     teacherCourse != teacher_courses_assignment.end(); ++teacherCourse) {
                    for (int courseT : teacherCourse->second) {
                        if (courseT == course) {
                            courseNumber++;
                        }
                    }
                }
                if (courseNumber > n_time_slots) {
                    throw NoViableSolutionFound{};
                }
            }
        }

        for (auto teacherCourse = teacher_courses_assignment.begin();
             teacherCourse != teacher_courses_assignment.end(); ++teacherCourse) {
            for (int course : teacherCourse->second) {
                for (auto yearCourse = courses_of_year.begin(); yearCourse != courses_of_year.end(); ++yearCourse) {
                    if (yearCourse->second.find(course) != yearCourse->second.end()) {
                        schedulingItems.push_back(
                                SchedulingItem(course, teacherCourse->first, 0, 0, yearCourse->first));
                    }
                }
            }
        }

        for (auto room : rooms) {
            for (int timeSlot = 1; timeSlot <= n_time_slots; timeSlot++) {
                roomsAndTimeSlots.push_back(std::make_pair<int, int>(std::move(room), std::move(timeSlot)));
            }
        }

        if (schedulingItems.size() > roomsAndTimeSlots.size()) {
            throw NoViableSolutionFound{};
        }

        for (int i = 0; i < schedulingItems.size(); i++) {
            schedulingItems[i].setRoom_id(roomsAndTimeSlots[i].first);
            schedulingItems[i].setTime_slot(roomsAndTimeSlots[i].second);
        }

        return Schedule{schedulingItems};
    }
}