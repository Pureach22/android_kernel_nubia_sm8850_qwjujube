__int64 __fastcall f_cdev_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x20
  _QWORD v10[6]; // [xsp+0h] [xbp-30h] BYREF

  v10[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 656);
  get_device(v3 + 136);
  if ( *(_BYTE *)(v3 + 1561) == 1 )
  {
    printk(&unk_8C5E, "f_cdev_open", v4, v5);
    put_device(v3 + 136);
    result = 4294967280LL;
    goto LABEL_8;
  }
  *(_QWORD *)(a2 + 32) = v3;
  if ( (*(_BYTE *)(v3 + 1560) & 1) == 0 )
  {
    memset(v10, 0, 40);
    init_wait_entry(v10, 0);
    v6 = prepare_to_wait_event(v3 + 1072, v10, 1);
    if ( (*(_BYTE *)(v3 + 1560) & 1) != 0 )
    {
LABEL_6:
      finish_wait(v3 + 1072, v10);
    }
    else
    {
      while ( !v6 )
      {
        schedule();
        v6 = prepare_to_wait_event(v3 + 1072, v10, 1);
        if ( *(_BYTE *)(v3 + 1560) == 1 )
          goto LABEL_6;
      }
      if ( (_DWORD)v6 )
      {
        v9 = v6;
        put_device(v3 + 136);
        result = v9;
        goto LABEL_8;
      }
    }
  }
  v7 = raw_spin_lock_irqsave(v3 + 1068);
  *(_BYTE *)(v3 + 1561) = 1;
  raw_spin_unlock_irqrestore(v3 + 1068, v7);
  usb_cser_start_rx(v3);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
