public class BoundedBufferTest {

  public static void main(String[] args) {

    BoundedBuffer bb = new BoundedBuffer();
    try{
      bb.insert("Hello");
      System.out.println(bb.retrieve().equals("Hello"));
      bb.retrieve();
      bb.insert(3);
    } catch(InterruptedException e) {
      System.out.println(e);
    }



  }

}
