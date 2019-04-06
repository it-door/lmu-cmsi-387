//implementing Runnable to run on multiple threads

public class Philosopher implements Runnable {

    private final Object leftFork;
    private final Object rightFork;

    Philosopher(Object left, Object right) {
        this.leftFork = left;
        this.rightFork = right;
    }

    private void doAction(String action) throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " " + action);
        Thread.sleep((int) (Math.random() * 100));
    }

    private double elapsedTimeInSecond(long start, long end) {
        long elapsedTime = end - start;
        return (double) elapsedTime / 1_000_000_000;
    }

    @Override
    public void run() {
        long start = System.nanoTime();
        try {
            while (true) {
                doAction("is thinking at " + elapsedTimeInSecond(start, System.nanoTime()) + " seconds"); // thinking
                synchronized (leftFork) {
                    doAction("picked up left fork at " + elapsedTimeInSecond(start, System.nanoTime()) + " seconds");
                    synchronized (rightFork) {
                        doAction("picked up right fork " + elapsedTimeInSecond(start, System.nanoTime()) + " seconds and is now eating"); // eating
                        doAction("put down right fork at " + elapsedTimeInSecond(start, System.nanoTime()));
                    }
                    doAction("put down left fork at " + elapsedTimeInSecond(start, System.nanoTime()) + " seconds and is now returning to thinking");
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}