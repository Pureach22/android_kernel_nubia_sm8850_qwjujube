__int64 __fastcall aw22xxx_play(__int64 a1)
{
  __int64 v2; // x0

  ((void (*)(void))aw22xxx_init_cfg_update_array)();
  aw22xxx_set_breath_data(a1, user_para_data);
  while ( 1 )
  {
    v2 = msleep((unsigned __int8)duration / 0x1Eu);
    if ( read_idx == write_idx )
    {
      kthread_status = 0;
      read_idx = 0;
      write_idx = 0;
      queue_work_on(32, system_wq, a1 + 560);
      v2 = printk(&unk_1369E, "aw22xxx_play");
      if ( (kthread_status & 1) != 0 )
        goto LABEL_4;
    }
    else if ( (kthread_status & 1) != 0 )
    {
      goto LABEL_4;
    }
    aw22xxx_i2c_write(a1, 255, 0);
    aw22xxx_i2c_write(a1, 5, 0);
    aw22xxx_i2c_write(a1, 4, 1);
    aw22xxx_i2c_write(a1, 2, 0);
    v2 = printk(&unk_132F7, "aw22xxx_play");
LABEL_4:
    if ( (unsigned int)(25 * read_idx) > 0x61A8 )
      break;
    aw22xxx_set_breath_data(a1, &user_para_data[25 * read_idx]);
    ++read_idx;
  }
  __break(0x5512u);
  return aw22xxx_init_cfg_update_array(v2);
}
