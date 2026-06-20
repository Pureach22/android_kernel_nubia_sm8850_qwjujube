__int64 __fastcall mhi_process_ev_work(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x22
  const char *v7; // x0
  int v8; // w8
  const char *v9; // x4
  __int64 v10; // x8
  const char *v11; // x5
  unsigned int v12; // w8
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // x8

  v1 = result - 208;
  v2 = *(_QWORD *)(result - 208);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 16) + 192LL);
  if ( !v3 || *(_DWORD *)(v3 + 24) )
    goto LABEL_27;
  v4 = result;
  v5 = *(_QWORD *)(v3 + 32);
  v6 = result - 208;
  v7 = to_mhi_pm_state_str(*(_DWORD *)(v2 + 336));
  v8 = *(_DWORD *)(v2 + 348);
  if ( v8 <= 3 )
  {
    if ( v8 <= 1 )
    {
      if ( !v8 )
      {
        v9 = "RESET";
        goto LABEL_23;
      }
      if ( v8 == 1 )
      {
        v9 = "READY";
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    if ( v8 == 2 )
      v9 = "M0";
    else
      v9 = "M1";
  }
  else
  {
    if ( v8 > 5 )
    {
      switch ( v8 )
      {
        case 6:
          v9 = "M3_FAST";
          goto LABEL_23;
        case 7:
          v9 = "BHI";
          goto LABEL_23;
        case 255:
          v9 = "SYS ERROR";
          goto LABEL_23;
      }
LABEL_22:
      v9 = "Unknown state";
      goto LABEL_23;
    }
    if ( v8 == 4 )
      v9 = "M2";
    else
      v9 = "M3";
  }
LABEL_23:
  v10 = *(unsigned int *)(v2 + 344);
  if ( (unsigned int)v10 <= 9 )
    v11 = mhi_ee_str[v10];
  else
    v11 = "INVALID_EE";
  ipc_log_string(v5, "[D][%s] Enter with pm_state:%s MHI_STATE:%s ee:%s\n", "mhi_process_ev_work", v7, v9, v11);
  v1 = v6;
  result = v4;
LABEL_27:
  v12 = *(_DWORD *)(v2 + 336);
  if ( v12 != 1 && v12 <= 0x7F )
  {
    v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(result + 40);
    if ( *((_DWORD *)v13 - 1) != 1550939421 )
      __break(0x8228u);
    return v13(v2, v1, 0xFFFFFFFFLL);
  }
  return result;
}
