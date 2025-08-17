
class Bus:
    def __init__(self, name, seats):
        self.name = name
        self.seats = seats

    def show_seats(self):
        print("Available seats are:")
        for seat, details in self.seats.items():
            if details["name"] is None:
                print(seat)

    def book_seat(self):
        self.show_seats()
        seat = input("Enter the seat number you want to book (e.g. 1A): ")
        if seat in self.seats:
            if self.seats[seat]["name"] is None:
                name = input("Enter your name: ")
                age = input("Enter your age: ")
                gender = input("Enter your gender (M/F/O): ")
                self.seats[seat]["name"] = name
                self.seats[seat]["age"] = age
                self.seats[seat]["gender"] = gender
                print(f"You have booked seat {seat}.")
                return seat
            else:
                print("Sorry, that seat is already booked.")
        else:
            print("Sorry, invalid seat number.")
    
    def cancel_seat(self):
        seat = input("Enter the seat number you want to cancel (e.g. 1A): ")
        if seat in self.seats:
            if self.seats[seat]["name"] is not None:
                self.seats[seat]["name"] = None
                self.seats[seat]["age"] = None
                self.seats[seat]["gender"] = None
                print(f"You have cancelled seat {seat}.")
            else:
                print("Sorry, that seat is not booked.")
        else:
            print("Sorry, invalid seat number.")

# Define a function to create a new bus
def create_bus():
    name = input("Enter the bus name: ")
    seats = {}
    for i in range(1, 11):
        for j in ["A", "B", "C"]:
            seats[f"{i}{j}"] = {"name": None, "age": None, "gender": None}
    return Bus(name, seats)

# Define a function to generate a ticket
def generate_ticket(name, seat):
    price = 500  # Fixed price for all seats
    print(f"----------------------------")
    print(f"Name: {name}")
    print(f"Bus: {bus.name}")
    print(f"Seat: {seat}")
    print(f"Price: Rs.{price}")
    print(f"From: NASHIK")
    print(f"To  : PUNE")
    print(f"----------------------------")

# Define a loop to keep the program running until the user quits
print("Create a Bus WHich will Go from Nashik To Pune")
bus = create_bus()
while True:
    print(f"Welcome to {bus.name} bus reservation system!")
    print("Enter 1 to view available seats.")
    print("Enter 2 to book a seat.")
    print("Enter 3 to cancel a seat.")
    print("Enter 4 to create a new bus.")
    print("Enter 5 to quit.")
    choice = input("Enter your choice: ")
    if choice == "1":
        bus.show_seats()
    elif choice == "2":
        seat = bus.book_seat()
        if seat:
            name = input("Enter the passenger name: ")
            generate_ticket(name, seat)
    elif choice == "3":
        bus.cancel_seat()
    elif choice == "4":
        bus = create_bus()
    elif choice == "5":
        break
    else:
        print("Invalid choice. Please try again.")

