#include <bits/ios_base.h>
#include <sstream>
#include "Serialization.h"

using namespace std;
namespace academia {
    Serializer::Serializer(std::stringstream *out) {
        out_ = out;
    }

    Serializer::Serializer(ostream *out) {
    }

    Room::Room(int number, string name, academia::Room::Type type) {
        id_ = number;
        name_ = name;
        type_ = type;
    }

    //==================

    void Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", ToString(type_));
        serializer->Footer("room");
    }

    //=================
    Building::Building(int number, string name, vector<academia::Room> rooms) {
        id_ = number;
        name_ = name;
        for (int i = 0; i < rooms.size(); ++i) {
            rooms_.push_back(rooms[i]);
        }
    }

    vector<reference_wrapper<const Serializable>> Building::VectorToReferenceVector() const {
        vector<reference_wrapper<const Serializable>> result;
        for (int i = 0; i < rooms_.size(); ++i) {
            result.emplace_back(cref(rooms_[i]));
        }
        return result;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms", VectorToReferenceVector());
        serializer->Footer("building");
    }

    int Building::Id() {
        return id_;
    }

    //=================
    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        if (out_->str().back() != '{') {
            Separate();
        }
        *out_ << "\"" + field_name + "\": " + to_string(value);
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        if (out_->str().back() != '{') {
            Separate();
        }
        *out_ << "\"" + field_name + "\": " + to_string(value);
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if (out_->str().back() != '{') {
            Separate();
        }
        *out_ << "\"" + field_name + "\": \"" + value + "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        if (out_->str().back() != '{') {
            Separate();
        }
        *out_ << "\"" + field_name + "\": \"" + to_string(value) + "\"";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const academia::Serializable>> &value) {
        if (out_->str().back() != '{') {
            Separate();
        }
        *out_ << "\"" + field_name + "\": [";
        for (int i = 0; i < value.size(); ++i) {
            if (out_->str().back() != '[') {
                *out_ << ", ";
            }
            value[i].get().Serialize(this);
        }
        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }

    //====================

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" + field_name + ">" + value + "<\\" + field_name + ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const vector<reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" + field_name + ">";
        for (int i = 0; i < value.size(); ++i) {
            value[i].get().Serialize(this);
        }
        *out_ << "<\\" + field_name + ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" + object_name + ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" + object_name + ">";
    }


    //===============
    BuildingRepository::BuildingRepository(vector<academia::Building> buildings) {
        for (int i = 0; i < buildings.size(); ++i) {
            buildings_.push_back(buildings[i]);
        }
    }

    vector<reference_wrapper<const Serializable>> BuildingRepository::VectorToReferenceVector() const {
        vector<reference_wrapper<const Serializable>> result;
        for (int i = 0; i < buildings_.size(); ++i) {
            result.emplace_back(cref(buildings_[i]));
        }
        return result;
    }

    void BuildingRepository::StoreAll(Serializer *serializer) {
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", VectorToReferenceVector());
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(Building building) {
        buildings_.push_back(building);
    }

    BuildingRepository::BuildingRepository() {}

    BuildingRepository::BuildingRepository(Building building) {
        buildings_.push_back(building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int number) const {
        for (int i = 0; i < buildings_.size(); ++i) {
            if (buildings_[i].id_ == number) {
                return buildings_[i];
            }
        }
    }
}