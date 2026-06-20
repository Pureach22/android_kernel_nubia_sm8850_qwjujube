__int64 __fastcall gsi_stop_db_channel(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x4
  __int64 v7; // x21
  int v8; // w5
  unsigned int v9; // w19
  _DWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_stop_db_channel", 3696);
    v9 = -8;
    goto LABEL_14;
  }
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_stop_db_channel", 3701, a1);
    v9 = -6;
    goto LABEL_14;
  }
  if ( a1 >= 0x25 )
    goto LABEL_21;
  v5 = gsi_ctx + 448 * a1;
  v6 = *(unsigned int *)(v5 + 304);
  if ( (_DWORD)v6 != 2 )
  {
    if ( (_DWORD)v6 == 3 )
    {
      v9 = 0;
      goto LABEL_14;
    }
    if ( (_DWORD)v6 != 4 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_stop_db_channel", 3714, v6);
      v9 = -7;
      goto LABEL_14;
    }
  }
  v7 = v5 + 184;
  mutex_lock(gsi_ctx + 28512, a2, a3, a4, v6);
  *(_DWORD *)(v7 + 264) = 0;
  if ( a1 == 36 )
LABEL_21:
    __break(0x5512u);
  ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16352);
  v11[0] = 11;
  v11[1] = a1;
  ((void (__fastcall *)(__int64, _QWORD, _DWORD *))gsihal_write_reg_n_fields)(55, *(unsigned int *)(gsi_ctx + 20), v11);
  if ( (unsigned int)wait_for_completion_timeout(v7 + 264, 50) )
  {
    v8 = *(_DWORD *)(v7 + 120);
    if ( (unsigned int)(v8 - 3) >= 2 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan=%lu unexpected state=%u\n", "gsi_stop_db_channel", 3736, a1, v8);
      v9 = -5;
    }
    else if ( v8 == 4 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan=%lu busy try again\n", "gsi_stop_db_channel", 3742, a1);
      v9 = -12;
    }
    else
    {
      v9 = 0;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_hdl=%lu timed out\n", "gsi_stop_db_channel", 3729, a1);
    v9 = -11;
  }
  mutex_unlock(gsi_ctx + 28512);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v9;
}
