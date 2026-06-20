__int64 __fastcall dp_bridge_hpd_get(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x0
  _QWORD *v7; // x19

  if ( a1 && a2 )
  {
    v6 = (_QWORD *)devm_kmalloc(a1, 256, 3520);
    if ( v6 )
    {
      *v6 = a1;
      v6[24] = a2;
      v6[10] = a3;
      v7 = v6;
      _mutex_init(v6 + 26, "&bridge_hpd->hpd_lock", &dp_bridge_hpd_get___key);
      v7[11] = 0xFFFFFFFE00000LL;
      v7[12] = v7 + 12;
      v7[13] = v7 + 12;
      v7[14] = dp_bridge_hpd_work;
      init_timer_key(v7 + 15, &delayed_work_timer_fn, 0x200000, 0, 0);
      v7[7] = dp_bridge_hpd_simulate_connect;
      v7[8] = dp_bridge_hpd_simulate_attention;
      v7[4] = dp_bridge_hpd_register;
      return (__int64)(v7 + 1);
    }
    else
    {
      return -12;
    }
  }
  else
  {
    printk(&unk_2486D8, "dp_bridge_hpd_get");
    return -22;
  }
}
