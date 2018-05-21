//
// Created by Michał on 2018-05-21.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdexcept>

namespace academia {
    class NoViableSolutionFound : public std::runtime_error {
    public:
        NoViableSolutionFound() : std::runtime_error("NoViableSolutionFound") {};
    };

    class SchedulingItem {
    public:
        SchedulingItem() {};

        SchedulingItem(int course, int teacher, int room, int time, int y) {
            course_id = course;
            teacher_id = teacher;
            room_id = room;
            time_slot = time;
            year = y;
        }

        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;

        void setRoom_id(int room_id);

        void setTime_slot(int time_slot);

    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule {
    public:
        Schedule() {};

        Schedule(std::vector<SchedulingItem> schedulingItemsVector) : SchedulingItems{schedulingItemsVector} {};

        void InsertScheduleItem(const SchedulingItem &item);

        std::size_t Size() const;

        SchedulingItem operator[](int index) const;

        Schedule OfTeacher(int teacherId) const;

        Schedule OfRoom(int roomId) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int maximumTimeSlot) const;

    private:
        std::vector<SchedulingItem> SchedulingItems;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;

    };

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;

    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H