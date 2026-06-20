__int64 __fastcall ddr_stats_get_change_his(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w0
  __int64 v4; // x1
  __int64 v5; // x1
  unsigned int v6; // w19

  if ( drv && *(_QWORD *)(drv + 240) && *(_BYTE *)(*(_QWORD *)(drv + 8) + 36LL) == 1 )
  {
    mutex_lock(drv + 192);
    v2 = qmp_send(*(_QWORD *)(drv + 240), "{class: misc_debug, res: ddr_his}", 64);
    if ( !v2 )
    {
      v3 = readl_relaxed((unsigned int *)(*(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL) + 4LL));
      if ( v3 >= 0x15 )
      {
        printk(&unk_A209, v4);
      }
      else
      {
        v5 = *(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL) + ((16 * v3) | 8);
        if ( v5 )
        {
          _memcpy_fromio(a1, v5, 40);
          v6 = 0;
LABEL_8:
          mutex_unlock(drv + 192);
          return v6;
        }
      }
      printk(&unk_A326, v5);
      v6 = -22;
      goto LABEL_8;
    }
    v6 = v2;
    printk(&unk_A305, v2);
    goto LABEL_8;
  }
  return 4294967277LL;
}
