__int64 __fastcall aw22xxx_multi_breath_pattern_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w8
  unsigned __int64 v7; // x0
  __int64 v8; // x1
  __int64 v10; // x20
  __int64 v11; // x1
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  if ( sscanf(s, "%x", &v12) == 1 )
  {
    v6 = v12;
    *(_DWORD *)(v5 + 760) = v12;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        read_idx = 0;
        if ( (kthread_status & 1) == 0 )
        {
          if ( write_idx )
          {
            v7 = kthread_create_on_node(aw22xxx_play, v5 - 16, 0xFFFFFFFFLL, &unk_13346, "aw22xxx_play");
            if ( v7 <= 0xFFFFFFFFFFFFF000LL )
            {
              v10 = v7;
              wake_up_process();
              cfg_update_kthread = v10;
              kthread_status = 1;
              printk("kthread_create done\n", v11);
            }
            else
            {
              kthread_status = 0;
              cfg_update_kthread = v7;
              printk("kthread_create error\n", v8);
            }
          }
        }
      }
    }
    else
    {
      read_idx = 0;
      write_idx = 0;
      if ( kthread_status == 1 )
        kthread_status = 0;
      aw22xxx_i2c_write((__int64 *)(v5 - 16), 255, 0);
      aw22xxx_i2c_write((__int64 *)(v5 - 16), 5, 0);
      aw22xxx_i2c_write((__int64 *)(v5 - 16), 4, 1);
      aw22xxx_i2c_write((__int64 *)(v5 - 16), 2, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
