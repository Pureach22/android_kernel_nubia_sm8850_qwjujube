__int64 __fastcall mhi_force_reset(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  const char *v4; // x0
  int v5; // w8
  const char *v6; // x4
  __int64 v7; // x8
  const char *v8; // x5

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( !v2 || *(_DWORD *)(v2 + 24) )
    goto LABEL_27;
  v3 = *(_QWORD *)(v2 + 32);
  v4 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
  v5 = *(_DWORD *)(a1 + 348);
  if ( v5 <= 3 )
  {
    if ( v5 <= 1 )
    {
      if ( !v5 )
      {
        v6 = "RESET";
        goto LABEL_23;
      }
      if ( v5 == 1 )
      {
        v6 = "READY";
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    if ( v5 == 2 )
      v6 = "M0";
    else
      v6 = "M1";
  }
  else
  {
    if ( v5 > 5 )
    {
      switch ( v5 )
      {
        case 6:
          v6 = "M3_FAST";
          goto LABEL_23;
        case 7:
          v6 = "BHI";
          goto LABEL_23;
        case 255:
          v6 = "SYS ERROR";
          goto LABEL_23;
      }
LABEL_22:
      v6 = "Unknown state";
      goto LABEL_23;
    }
    if ( v5 == 4 )
      v6 = "M2";
    else
      v6 = "M3";
  }
LABEL_23:
  v7 = *(unsigned int *)(a1 + 344);
  if ( (unsigned int)v7 <= 9 )
    v8 = mhi_ee_str[v7];
  else
    v8 = "INVALID_EE";
  ipc_log_string(v3, "[D][%s] Entered with pm_state:%s dev_state:%s ee:%s\n", "mhi_force_reset", v4, v6, v8);
LABEL_27:
  mhi_report_error(a1);
  mhi_soc_reset(a1);
  return mhi_rddm_download_status(a1);
}
