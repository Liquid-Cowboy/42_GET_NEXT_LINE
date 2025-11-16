# ⏭️ Get Next Line

**Get Next Line** will really test your memory management skills by having you play with a static buffer. Having a static variable means that each time the **Get Next Line** function's called, it will start with the value from the previous call. Since the goal is to **get the next line**, since our buffer can be of whatever length and since each line (from whatever file descriptor) can be of any size, we have to account for one of three conditions:
* We don't have a **'\n'** in our buffer : in which case we have to keep reading and saving to the static buffer.
* We do have a **'\n'** in our buffer: in which case we have to save until **'\n'** to the destination string and (if we have any chars following **'\n'**) keep the remainder for the next iteration;
* We don't find a **'\n'** but we do find a **'\0'**: in which case we have reached the **EOF**(end of file) and have to save everything up until the terminator character to the destination string.
