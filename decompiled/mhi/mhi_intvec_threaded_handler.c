__int64 __fastcall mhi_intvec_threaded_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64, unsigned int *); // x9
  int v5; // w0
  __int64 (__fastcall *v6)(__int64, __int64, unsigned int *); // x11
  __int64 v7; // x1
  int v8; // w21
  int v9; // w0
  __int64 v10; // x10
  unsigned int v11; // w20
  __int64 v12; // x9
  const char *v13; // x3
  int v14; // w9
  const char *v15; // x4
  const char *v16; // x5
  const char *v17; // x6
  __int64 v18; // x8
  int v19; // w21
  void (__fastcall *v20)(__int64, __int64); // x8
  void (__fastcall *v22)(__int64, __int64); // x8
  unsigned int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_write_lock_irq(a2 + 320);
  if ( (*(_WORD *)(a2 + 336) & 0xFDE) == 0 )
    goto LABEL_72;
  v3 = *(_QWORD *)(a2 + 32);
  v4 = *(__int64 (__fastcall **)(__int64, __int64, unsigned int *))(a2 + 568);
  v23 = 0;
  if ( *((_DWORD *)v4 - 1) != -748163823 )
    __break(0x8229u);
  v5 = v4(a2, v3 + 72, &v23);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, unsigned int *))(a2 + 568);
  v7 = *(_QWORD *)(a2 + 40) + 40LL;
  if ( v5 )
    v8 = 256;
  else
    v8 = BYTE1(v23);
  v23 = 0;
  if ( *((_DWORD *)v6 - 1) != -748163823 )
    __break(0x822Bu);
  v9 = v6(a2, v7, &v23);
  v10 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 192LL);
  if ( v9 )
    v11 = 10;
  else
    v11 = v23;
  if ( !v10 || *(_DWORD *)(v10 + 24) )
    goto LABEL_59;
  v12 = *(unsigned int *)(a2 + 344);
  if ( (unsigned int)v12 <= 9 )
    v13 = mhi_ee_str[v12];
  else
    v13 = "INVALID_EE";
  v14 = *(_DWORD *)(a2 + 348);
  if ( v14 <= 3 )
  {
    if ( v14 <= 1 )
    {
      if ( !v14 )
      {
        v15 = "RESET";
        goto LABEL_37;
      }
      if ( v14 == 1 )
      {
        v15 = "READY";
        goto LABEL_37;
      }
LABEL_36:
      v15 = "Unknown state";
      goto LABEL_37;
    }
    if ( v14 == 2 )
      v15 = "M0";
    else
      v15 = "M1";
  }
  else
  {
    if ( v14 > 5 )
    {
      switch ( v14 )
      {
        case 6:
          v15 = "M3_FAST";
          goto LABEL_37;
        case 7:
          v15 = "BHI";
          goto LABEL_37;
        case 255:
          v15 = "SYS ERROR";
          goto LABEL_37;
      }
      goto LABEL_36;
    }
    if ( v14 == 4 )
      v15 = "M2";
    else
      v15 = "M3";
  }
LABEL_37:
  if ( v11 > 9 )
  {
    v16 = "INVALID_EE";
    if ( v8 > 3 )
      goto LABEL_39;
LABEL_45:
    if ( v8 > 1 )
    {
      if ( v8 == 2 )
        v17 = "M0";
      else
        v17 = "M1";
    }
    else if ( v8 )
    {
      v17 = "READY";
    }
    else
    {
      v17 = "RESET";
    }
    goto LABEL_58;
  }
  v16 = mhi_ee_str[v11];
  if ( v8 <= 3 )
    goto LABEL_45;
LABEL_39:
  if ( v8 <= 5 )
  {
    if ( v8 == 4 )
      v17 = "M2";
    else
      v17 = "M3";
  }
  else
  {
    switch ( v8 )
    {
      case 6:
        v17 = "M3_FAST";
        break;
      case 7:
        v17 = "BHI";
        break;
      case 255:
        v17 = "SYS ERROR";
        break;
      default:
        v17 = "Unknown state";
        break;
    }
  }
LABEL_58:
  ipc_log_string(
    *(_QWORD *)(v10 + 32),
    "[D][%s] local ee: %s state: %s device ee: %s state: %s\n",
    "mhi_intvec_threaded_handler",
    v13,
    v15,
    v16,
    v17);
LABEL_59:
  if ( v8 != 255 )
  {
LABEL_72:
    raw_write_unlock_irq(a2 + 320);
    goto LABEL_73;
  }
  v18 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 192LL);
  if ( v18 && !*(_DWORD *)(v18 + 24) )
    ipc_log_string(*(_QWORD *)(v18 + 32), "[D][%s] System error detected\n", "mhi_intvec_threaded_handler");
  v19 = mhi_tryset_pm_state(a2, 256);
  raw_write_unlock_irq(a2 + 320);
  if ( v19 == 256 )
  {
    if ( v11 - 5 >= 2 && v11 )
    {
      if ( v11 == 3 )
      {
        if ( *(_QWORD *)(a2 + 160) && (unsigned int)(*(_DWORD *)(a2 + 348) - 2) <= 4 )
        {
          mhi_report_error(a2);
          v20 = *(void (__fastcall **)(__int64, __int64))(a2 + 480);
          if ( *((_DWORD *)v20 - 1) != 1183736653 )
            __break(0x8228u);
          v20(a2, 4);
          *(_DWORD *)(a2 + 344) = 3;
          _wake_up(a2 + 456, 3, 0, 0);
        }
        goto LABEL_73;
      }
    }
    else
    {
      v22 = *(void (__fastcall **)(__int64, __int64))(a2 + 480);
      if ( *((_DWORD *)v22 - 1) != 1183736653 )
        __break(0x8228u);
      v22(a2, 7);
      *(_DWORD *)(a2 + 344) = v11;
    }
    _wake_up(a2 + 456, 3, 0, 0);
    mhi_pm_sys_err_handler(a2);
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return 1;
}
