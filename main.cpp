#include <iostream>
#include <vector>

enum building_type {
  HOUSE,
  GARAGE,
  HANGAR,
  BATH
};
//-------------------------------------------------------------------
enum room_type {
  LIVING,
  CHILDREN,
  BATHROOM,
  KITCHEN,
  BEDROOM
};
//-------------------------------------------------------------------
enum level_number {
  FLOOR_1,
  FLOOR_2,
  FlOOR_3
};
//-------------------------------------------------------------------
struct Room {
  std::string name_room;
  int square_room = 0;
};
//-------------------------------------------------------------------
struct Floor {
  std::string name_floor;
  float height_floor = 0;
  int number_floor = 0;
  Room room;
};
//-------------------------------------------------------------------
struct Warm {
  bool stove = false;
};
//-------------------------------------------------------------------
struct Building {
  int plot_number = 0;
  std::string name_building;
  int build_number = 0;
  int square_building = 0;
  Warm warm;
  Floor floor;
};
//-------------------------------------------------------------------
std::string room_tp(room_type room) {
  if (room == LIVING) {
    return "Living room";
  } else if (room == CHILDREN) {
    return "Children's";
  } else if (room == BATHROOM) {
    return "Bathroom";
  } else if (room == KITCHEN) {
    return "Kitchen";
  } else if (room == BEDROOM) {
    return "Bedroom";
  } else
    return "Error";
}
//-------------------------------------------------------------------
std::string build_tp(building_type build) {
  if (build == HOUSE) {
    return "House";
  } else if (build == GARAGE) {
    return "Garage";
  } else if (build == HANGAR) {
    return "Hangar";
  } else if (build == BATH) {
    return "Bath";
  } else
    return "Error";
}
//-------------------------------------------------------------------
std::string level_tp(level_number floor) {
  if (floor == FLOOR_1) {
    return "Floor#1";
  } else if (floor == FLOOR_2) {
    return "Floor#2";
  } else if (floor == FlOOR_3) {
    return "Floor#3";
  } else
    return "Error";
}
//-------------------------------------------------------------------
std::string level(int numb) {
  if (numb == 1) {
    return level_tp(FLOOR_1);
  } else if (numb == 2) {
    return level_tp(FLOOR_2);
  } else if (numb == 3) {
    return level_tp(FlOOR_3);
  } else
    return "Error number floor";
}
//-------------------------------------------------------------------
bool add_stove(building_type name) {
  std::cout << "Install a stove in the " << build_tp(name)
            << "? <yes> / <no> " << std::endl;
  std::string answer;
  std::cin >> answer;
  if (answer == "yes") {
    return true;
  } else
    return false;
}
bool question(building_type name, int number) {
  std::string answer;
  std::cout << "Add an additional " << build_tp(name) << " on plot "
            << number << "? <yes> / <no> " << std::endl;
  std::cin >> answer;
  if (answer == "yes")
    return true;
  else
    return false;
}
//-------------------------------------------------------------------
void add_rooms(std::vector<Building> &data) {
  int floor_number = 1;
  int rooms = 0;
  Building build;
  std::string answer_floor;
  while (answer_floor != "no" || floor_number < 4) {
    std::cout << "Enter ceiling height " << floor_number << " sf" << std::endl;
    std::cin >> build.floor.height_floor;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter error!" << std::endl;
    }
    build.floor.name_floor = level(floor_number);
    std::string answer_room;
    while (answer_room != "no") {
      std::cout << "Arrange the rooms on the " << floor_number << " st floor" << std::endl
                << "-------------------------------------" << std::endl
                << room_tp(LIVING) << "    enter '0'" << std::endl
                << room_tp(CHILDREN) << "     enter '1'" << std::endl
                << room_tp(BATHROOM) << "       enter '2'" << std::endl
                << room_tp(KITCHEN) << "        enter '3'" << std::endl
                << room_tp(BEDROOM) << "        enter '4'" << std::endl;
      int numb;
      std::cin >> numb;
      switch (numb) {
        case 0:build.floor.room.name_room = room_tp(LIVING);
          build.floor.number_floor = floor_number;
          std::cout << "Enter area " << room_tp(LIVING) << std::endl;
          std::cin >> build.floor.room.square_room;
          break;
        case 1:build.floor.room.name_room = room_tp(CHILDREN);
          build.floor.number_floor = floor_number;
          std::cout << "Enter area " << room_tp(CHILDREN) << std::endl;
          std::cin >> build.floor.room.square_room;
          break;
        case 2:build.floor.room.name_room = room_tp(BATHROOM);
          build.floor.number_floor = floor_number;
          std::cout << "Enter area " << room_tp(BATHROOM) << std::endl;
          std::cin >> build.floor.room.square_room;
          break;
        case 3:build.floor.room.name_room = room_tp(KITCHEN);
          build.floor.number_floor = floor_number;
          std::cout << "Enter area " << room_tp(KITCHEN) << std::endl;
          std::cin >> build.floor.room.square_room;
          break;
        case 4:build.floor.room.name_room = room_tp(BEDROOM);
          build.floor.number_floor = floor_number;
          std::cout << "Enter area " << room_tp(BEDROOM) << std::endl;
          std::cin >> build.floor.room.square_room;
          break;
        default: std::cout << "Input Error!";
          break;
      }
      data.push_back(build);
      rooms++;
      if (rooms < 2)
        continue;
      else {
        std::cout << "Add a room on the floor? <yes> / <no>" << std::endl;
        std::cin >> answer_room;
        if (answer_room != "no")
          continue;
      }
    }//while rooms
    std::cout << "Add a floor in the house? <yes> / <no>" << std::endl;
    std::cin >> answer_floor;
    if (answer_floor != "no") {
      floor_number++;
      rooms = 0;
      continue;
    } else
      break;
  }//while floors
}
//-------------------------------------------------------------------
void add_building(building_type name, std::vector<Building> &data, int number) {
  std::string build_name = build_tp(name);
  Building build;
  int count = 1;
  bool cycle = true;
  while (cycle) {
    std::cout << "Enter " << build_name << " #" << count
              << " area" << " on plot " << number << std::endl;
    std::cin >> build.square_building;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter error!" << std::endl;
      continue;
    }
    build.plot_number = number;
    build.name_building = build_name;
    build.build_number = count;
    if (build_name == "House" || build_name == "Bath") {
      build.warm.stove = add_stove(name);
      if (build_name == "House") {
        add_rooms(data);
      }
    }
    data.push_back(build);
    count++;
    if (!question(name, number))
      cycle = false;
  }
}
//-------------------------------------------------------------------
void print_result(std::vector<Building> &data) {
  for (int i = 0; (i < data.size()); ++i) {
    std::cout << "--------------------------------------------" << std::endl
              << "Plot #" << data.at(i).plot_number << " "
              << data.at(i).name_building << " #"
              << data.at(i).build_number << " "
              << data.at(i).square_building << " m2.";
    if (data.at(i).name_building == build_tp(HOUSE) || data.at(i).name_building == build_tp(BATH)) {
      std::cout << " Stove availability  " << data.at(i).warm.stove << std::endl;
        } else
      std::cout << std::endl;
      }
    }
//-------------------------------------------------------------------
int main() {
  Building build;
  std::vector<Building> data{};
  std::cout << "Enter the number of plots" << std::endl;
  int plots;
  std::cin >> plots;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter error!" << std::endl;
  }
  std::string answer;
  int count = 1;
  do {
    add_building(HOUSE, data, count);
    if (question(building_type::GARAGE, count))
      add_building(building_type::GARAGE, data, count);
    if (question(building_type::HANGAR, count))
      add_building(building_type::HANGAR, data, count);
    if (question(building_type::BATH, count))
      add_building(building_type::BATH, data, count);
    count++;
  } while (count <= plots);
  //print_result(data);
  return 0;
}
