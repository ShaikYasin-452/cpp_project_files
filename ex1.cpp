import java.util.*;

interface Vechile{
    public void carOff();
}
class  Car{

    private  boolean state=false;
     private  String brand;
     private  String number;

     public Car(String brand, String number){
        this.brand=brand;
        this.number=number;
        this.state=state;
     }

     public void display(){
        System.out.println("brand " +brand);
        System.out.println("number" +number);
        System.out.println("state" +state);
     }
     
     public String getBrand(){
        return brand;
     }
     public String getNumber(){
        return number;
     }
}

class SmartCar extends Car implements Vechile,Runnable{
    private int year;

    public SmartCar(String brand, String number, int year) {
        super(brand, number );                                                                   
        this.year=year;
    }

    @Override
    public void carOff() {
System.out.println("car is in off State");
       

        }
    

    @Override
    public void run() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
  public void starting(){
    System.out.println("vechile is in process of starting ");
  }
  public void running(){
    boolean engine=false;
           if(engine=false){
    System.out.println("enging not active");
  }else{
    engine=true;
    System.out.println("engine is active state");
  }
  }

  

}
class vehiclestatemanager {
     private  static  vehiclestatemanager instance;
     boolean engine;

     private vehiclestatemanager(){
        System.out.println("welcome to vechilestatemanager");
     }
     public static  vehiclestatemanager getInstance(){
              if(instance==null){
                     instance= new vehiclestatemanager();

              }
              return instance;

     }
     public void welcome(){
             try {
                 System.out.println("wellcome to animation");
                 Thread.sleep(5000);
             } catch (Exception e) {
                System.out.println("dont welcome");
             }
             System.out.println("side mirror unfold");
             System.out.println("ambient lights are glow");
     }

     public void startUp(){
       boolean engine=true;
        try {
            System.out.println("welcome to the car");
            Thread.sleep(10000);
        } catch (Exception e) {
            System.out.println("closed");
        }       
       System.out.println(" engine is stareted");
       System.out.println("ignition is started");

       }
       public void shutDown(){

        engine=false;
        System.out.println("good bye ");
        System.out.println("mirrors are closed");
        System.out.println("lights are off");
        System.out.println("animation is shutDown");

       }

     }




public class CarShutDown{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<SmartCar> cars= new ArrayList<>();
        vehiclestatemanager manager= vehiclestatemanager.getInstance();
        manager.welcome();
        manager.startUp();
        manager.shutDown();

        while (true) { 
                System.out.println("welcome to vechilemanagement");
                System.out.println("1.add vechile");
                System.out.println("2.view vechile details");
                System.out.println("3.search for vechile");
                System.out.println("4.exit");
                System.out.println("enter you option");
                int choice;

                try {
                    choice = sc.nextInt();
                    sc.nextLine();

                } catch (Exception e) {
                    System.out.println("enter valid option");
                     sc.nextLine();
                     continue;
                }
                  switch (choice) {
                      case 1:
                      System.out.println("enter brand name");
                      String brand=sc.nextLine();
                      System.out.println("enter number");
                      String number=sc.nextLine();
                      System.out.println("enter year");
                      int year=sc.nextInt();
                      System.out.println("");
                      cars.add(new SmartCar(brand, number, year));
                      System.out.println("car details added succesfully");
                        manager.welcome();

                        manager.startUp();
                                   
                                     manager.shutDown();
                                                                         
                
                          
                          break;

                          case 2:
                          if(cars.isEmpty()){
                            System.out.println("no car is found");

                          }else{
                            for(SmartCar car: cars){
                                car.display();
                            }
                          }
                          case 3:
                               System.out.println("search by number");
                               String searchNum=sc.nextLine();
                               boolean state=false;
                               for(SmartCar car: cars){
                                if(car.getNumber().equalsIgnoreCase(searchNum)){
                                    System.out.println("car found");
                                    car.display(); 
                                    state=true;

                                }
                               }   
                               if(!state)     System.out.println("car not found");                                         
                            case 4:
                                System.out.println("4.exit the car");                                                   
                      default:
                          throw new AssertionError();
                  }
    
        }
    }
    }