class Vehicle:
    def __init__(self, vid, model, year):
        self.vid = vid
        self.model = model
        self.year = int(year)

    def __str__(self):
        return f"VID: {self.vid} | {self.model} ({self.year})"
    def __eq__(self, other):
        if isinstance(other, Vehicle):
            return self.vid == other.vid
        return False

    def is_new(self, n):
        return (2026 - self.year) <= n


# 2. Subclasses
class Car(Vehicle):
    def __init__(self, vid, model, year, fuel_type, doors):
        super().__init__(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = int(doors)

    def __str__(self):
        return f"[Car]        VID: {self.vid} | {self.model} ({self.year}) | Fuel: {self.fuel_type} | {self.doors} Doors"


class Truck(Vehicle):
    def __init__(self, vid, model, year, max_load, axles):
        super().__init__(vid, model, year)
        self.max_load = int(max_load)
        self.axles = int(axles)

    def __str__(self):
        return f"[Truck]      VID: {self.vid} | {self.model} ({self.year}) | Load: {self.max_load}kg | {self.axles} Axles"


class Motorcycle(Vehicle):
    def __init__(self, vid, model, year, engine_cc, m_type):
        super().__init__(vid, model, year)
        self.engine_cc = int(engine_cc)
        self.type = m_type

    def __str__(self):
        return f"[Motorcycle] VID: {self.vid} | {self.model} ({self.year}) | Eng: {self.engine_cc}cc | Type: {self.type}"


# 3. Save Function
def save_fleet_to_file(vehicles, filename):
    with open(filename, 'w') as file:
        for v in vehicles:
            if isinstance(v, Car):
                file.write(f"Car,{v.vid},{v.model},{v.year},{v.fuel_type},{v.doors}\n")
            elif isinstance(v, Truck):
                file.write(f"Truck,{v.vid},{v.model},{v.year},{v.max_load},{v.axles}\n")
            elif isinstance(v, Motorcycle):
                file.write(f"Motorcycle,{v.vid},{v.model},{v.year},{v.engine_cc},{v.type}\n")


# 4. Load Function
def load_fleet_from_file(filename):
    print(f"Loading fleet data from '{filename}'...")
    vehicles = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                parts = line.strip().split(',')
                if len(parts) < 6:
                    continue

                v_type = parts[0]
                vid = parts[1]
                model = parts[2]
                year = int(parts[3])

                # Reconstructing objects manually based on type
                if v_type == 'Car':
                    vehicles.append(Car(vid, model, year, parts[4], parts[5]))
                elif v_type == 'Truck':
                    vehicles.append(Truck(vid, model, year, parts[4], parts[5]))
                elif v_type == 'Motorcycle':
                    vehicles.append(Motorcycle(vid, model, year, parts[4], parts[5]))

        print(f"{len(vehicles)} vehicles loaded successfully.")
    except FileNotFoundError:
        print("File not found.")

    return vehicles


if __name__ == "__main__":
    my_fleet = [
        Car("V001", "Tesla Model 3", 2023, "Electric", 4),
        Truck("T101", "Volvo FH16", 2019, 25000, 6),
        Motorcycle("M301", "Yamaha R1", 2024, 998, "Sport"),
        Car("V002", "Toyota Corolla", 2018, "Petrol", 4),
        Truck("T102", "Mercedes Actros", 2021, 18000, 4),
        Motorcycle("M302", "Harley Davidson", 2015, 1200, "Cruiser")
    ]

    save_fleet_to_file(my_fleet, "fleet.txt")

    loaded_fleet = load_fleet_from_file("fleet.txt")

    print("\n--- All Vehicles ---")
    for vehicle in loaded_fleet:
        print(vehicle)

    print("\n--- Recent Vehicles (Last 4 Years) ---")
    for vehicle in loaded_fleet:
        if vehicle.is_new(
                5):
            print(vehicle)

    print("\n--- Electric Cars Only ---")
    for vehicle in loaded_fleet:
        if isinstance(vehicle, Car) and vehicle.fuel_type == "Electric":
            print(vehicle)
