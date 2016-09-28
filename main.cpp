#include "mbed.h"
#include "mbed_events.h"

EventQueue queue;
Thread thread;
Ticker ticker;

int main() {
    // Begin dispatching events
    thread.start(Callback<void()>(&queue, &EventQueue::dispatch));

    // Simple call
    queue.call(printf, "hello!\r\n");

    // Using event as a callback
    ticker.attach_us(queue.event(printf, "tick\r\n"), 100000);
}
