#include <zephyr/kernel.h>

#include "../lvgl_zephyr_project/ui/ui.h"
#include <time.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <stdio.h>
#include <lvgl_private.h>

lv_obj_t* watchface;

static const int32_t sleep_time_ms = 1000;  
LOG_MODULE_REGISTER(my_app_module, LOG_LEVEL_INF);

int main(void)
{       
        int ret;
        static char buf[25] = {0};
       
        const struct device *display;
        display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        if (!device_is_ready(display))
        {
                printk("Error: display not ready\r\n");
                return 0;
        }

        k_sleep(K_MSEC(100));

        ret = display_blanking_off(display);
        if (ret < 0 && ret != -ENOSYS)
        {
                printk("Failed to turn blanking off (error %d)", ret);
                return 0;
        }

        /*init generated ui*/
        ui_init("");
       // lv_screen_load(my_screen_create());

        /*create watchfacescreen*/
        watchface = watchface_create();
        lv_screen_load(watchface);
        lv_timer_handler();

        while (1)
        {

                time_t now = time(NULL);

                struct tm *tm_info = localtime(&now);
                LOG_INF("Time: %02d : %02d : %02d\n",
                       tm_info->tm_hour,
                       tm_info->tm_min,
                       tm_info->tm_sec);
                sprintf(buf, " %02d : %02d : %02d\n", tm_info->tm_hour,
                        tm_info->tm_min,
                        tm_info->tm_sec);

                /*TODO : make time variable same for each watchface*/
                lv_subject_copy_string(&dsiplay_time, buf);
               // lv_subject_copy_string(&time_variable, buf);

                /*Must be called periodically*/
                lv_timer_handler();

                /*Sleep*/
                k_msleep(sleep_time_ms);
        }
        return 0;
}
