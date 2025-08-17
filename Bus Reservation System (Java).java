import java.util.*;

class Bus {
  private String busn, driver, arrival, depart, from, to;
  public String seat[][];
  public int t_num = 1000;

  public Bus(
    String busn,
    String driver,
    String arrival,
    String depart,
    String from,
    String to
  ) {
    this.busn = busn;
    this.driver = driver;
    this.arrival = arrival;
    this.depart = depart;
    this.from = from;
    this.to = to;
    seat = new String[8][4];
    t_num = 1000;
    empty();
  }

  private void empty() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 4; j++) {
        seat[i][j] = "Empty";
      }
    }
  }

  public String getBusn() {
    return busn;
  }

  public void setBusn(String busn) {
    this.busn = busn;
  }

  public String getDriver() {
    return driver;
  }

  public void setDriver(String driver) {
    this.driver = driver;
  }

  public String getArrival() {
    return arrival;
  }

  public void setArrival(String arrival) {
    this.arrival = arrival;
  }

  public String getDepart() {
    return depart;
  }

  public void setDepart(String depart) {
    this.depart = depart;
  }

  public String getFrom() {
    return from;
  }

  public void setFrom(String from) {
    this.from = from;
  }

  public String getTo() {
    return to;
  }

  public void setTo(String to) {
    this.to = to;
  }

  public void position() {
    int s = 0;
    int p = 0;

    for (int i = 0; i < 8; i++) {
      System.out.print("\n");
      for (int j = 0; j < 4; j++) {
        s++;
        if (seat[i][j].equals("Empty")) {
          System.out.print(s + ".");
          System.out.print(seat[i][j] + " ");
          p++;
        } else {
          System.out.print(s + ".");
          System.out.print(seat[i][j] + " ");
        }
      }
    }

    System.out.print("\n\nThere are " + p + " seats empty in Bus No: " + busn);
  }
}

public class Main {
  private static int p = -1;
  private static int busN = 10;
  private static Bus[] bus;

  public static void vline(char ch) {
    System.out.println();
    for (int i = 60; i > 0; i--) System.out.print(ch);
  }

  public static Bus install() {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter bus no: ");
    String busn = scanner.nextLine();

    System.out.print("\nEnter Driver's name: ");
    String driver = scanner.nextLine();

    System.out.print("\nArrival time: ");
    String arrival = scanner.nextLine();

    System.out.print("\nDeparture: ");
    String depart = scanner.nextLine();

    System.out.print("\nFrom: ");
    String from = scanner.nextLine();

    System.out.print("\nTo: ");
    String to = scanner.nextLine();

    return new Bus(busn, driver, arrival, depart, from, to);
  }

  public static void allotment() {
    int seat;
    String number;

    Scanner scanner = new Scanner(System.in);
    System.out.print("Bus no: ");
    number = scanner.nextLine();

    int id = -1;
    for (int n = 0; n <= p; n++) {
      if (bus[n].getBusn().equals(number)) {
        id = n;
        break;
      }
    }
    if (id == -1) {
      System.out.println("Bus not found");
      return;
    }

    int passenger_t; //temp passenger
    int p_num; //no of passengers
    System.out.println("Enter no. of passengers: ");
    p_num = Integer.parseInt(scanner.next());

    for (passenger_t = 0; passenger_t <= p_num - 1; ++passenger_t) { 

     //1
     // System.out.print(passenger_t);  
     // System.out.print(passenger_t + p_num);
      System.out.print("\nEnter Seat Number: ");
      seat = Integer.parseInt(scanner.next());
      if (seat > 32) {
        System.out.print("\nThere are only 32 seats available in this bus.");
        continue;
      }

      System.out.print("Enter passanger's 'Firstname_lastname': ");
      bus[id].seat[seat / 4][(seat % 4) - 1] = scanner.next();
    }

    System.out.print(
      "Rs. " + 200 * p_num + " to be paid for the booking of the seat"
    );

    System.out.print("\n\nEnter ticket payment status:");
    System.out.print(
      "\n\tPress 1 is payment is done \n\tPress 2 is payment is pending or incomplete"
    );
    System.out.print("\n\tEnter status:");
    int ch_tf;
    ch_tf = Integer.parseInt(scanner.next());
    switch (ch_tf) {
      case 1:
        System.out.print("Seat reserved successfully\n\n");
        if (ch_tf ==1) 
        {
          //bus[p].t_num;
          int t_num = 1000; //ticket  number
          bus[p].t_num = bus[p].t_num + 1;
          System.out.print("Your ticket number is " + t_num);
        }
        break;
      case 2:
        System.out.print("Complete payment to reserve seat\n\n");
        break;
      default:
        System.out.print("Invalid input\n\n");
    }
  }

  public static void show() {
    String number;
    int id = -1;
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter bus no: ");
    number = scanner.nextLine();

    for (int n = 0; n <= p; n++) {
      if (bus[n].getBusn().equals(number)) {
        id = n;
        break;
      }
    }

    if (id == -1) {
      System.out.print("Bus Details Not Found");
      return;
    }

    vline('*');

    System.out.print(
      "\nBus no: \t" +
      bus[id].getBusn() +
      "\nDriver: \t" +
      bus[id].getDriver() +
      "\t\tArrival time: \t" +
      bus[id].getArrival() +
      "\tDeparture time:" +
      bus[id].getDepart() +
      "\nFrom: \t\t" +
      bus[id].getFrom() +
      "\t\tTo: \t\t" +
      bus[id].getTo() +
      "\n"
    );

    vline('*');

    bus[id].position();

    int a = 1;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 4; j++) {
        a++;

        if (bus[id].seat[i][j] != "Empty") System.out.print(
          "\nThe seat no " +
          (a - 1) +
          " is reserved for " +
          bus[id].seat[i][j] +
          "."
        );
      }
    }
  }

  public static void avail() {
    for (int n = 0; n <= p; n++) {
      vline('*');
      System.out.print(
        "\nBus no: \t" +
        bus[n].getBusn() +
        "\nDriver: \t" +
        bus[n].getDriver() +
        "\t\tArrival time: \t" +
        bus[n].getArrival() +
        "\tDeparture Time: \t" +
        bus[n].getDepart() +
        "\nFrom: \t\t" +
        bus[n].getFrom() +
        "\t\tTo: \t\t\t" +
        bus[n].getTo() +
        "\n"
      );
      vline('_');
    }
  }

  // // public static void print()

  // {

  //     String number;

  //     Scanner scanner = new Scanner(System.in);
  //     System.out.print("Bus no: ");
  //     number = scanner.nextLine();

  //     int id = -1;
  //     for (n = 0; n <= p; n++) {
  //       if (bus[n].getBusn().equals(number)) {
  //         id = n;
  //         break;
  //       }
  //     }
  //     if (id == -1) {
  //       System.out.println("Bus not found");
  //       return;
  //     }

  //     vline('*');

  //     time_t t = time(0); // get time now
  //     tm *now = localtime(&t);

  //     string filename = "BUS - " + to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday) + ".txt";

  //     ofstream MyFile(filename);

  //     MyFile << "> Bus no: \t" << bus[n].busn
  //            << "\n> Driver: \t" << bus[n].driver
  //            << "\nArrival time:\t" << bus[n].arrival << "\t\tDeparture time:\t" << bus[n].depart
  //            << "\nFrom:\t" << bus[n].from << "\t\tTo:\t" << bus[n].to << "\n.\n";

  //     vline('*');

  //     bus[0].position(n);

  //     int a = 1;

  //     for (int i = 0; i < 8; i++)

  //     {

  //       for (int j = 0; j < 4; j++)

  //       {

  //         a++;

  //         if (strcmp(bus[n].seat[i][j], "Empty") != 0)
  //           MyFile << "\nSEAT - " << (a - 1) << " => " << bus[n].seat[i][j] << ".";
  //         else
  //           MyFile << "\nSEAT - " << (a - 1) << " => Empty";
  //       }
  //     }

  //     cout << "Data saved in " << filename << "\n";

  //     MyFile.close();
  //     break;

  // }

  public static void main(String[] args) {
    bus = new Bus[busN];

    System.out.print("Micro-Project Bus Reservation system*");
    while (true) {
      System.out.print("\nMenu:");
      System.out.print(
        "\n\t1. Add Bus" +
        "\n\t2. Show current status" +
        "\n\t3. Bus Reservation" +
        "\n\t4. Buses Available" +
        "\n\t5. Exit"
      );

      System.out.print("\n\tEnter your choice:-> ");

      Scanner sc = new Scanner(System.in);
      int w = sc.nextInt();

      switch (w) {
        case 1:
          bus[++p] = install();
          //   System.out.print("--" + p + " bus added successfully");
          break;
        case 2:
          show();
          break;
        case 3:
          allotment();
          break;
        case 4:
          avail();
          break;
        case 5:
          System.out.print("Thanks For Using Our System...");
          System.out.print(
            "Code By : 06.Rupesh Bhadane.\n\t  02.Shweta Ahire.\n\t  10.Siya Chavan.\n\t  20.Rutuja Dorkar."
          );
      }
    }
  }
}