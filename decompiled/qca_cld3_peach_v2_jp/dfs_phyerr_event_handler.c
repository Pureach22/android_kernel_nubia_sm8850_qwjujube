__int64 __fastcall dfs_phyerr_event_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        int a11)
{
  __int64 v11; // x8
  __int64 v12; // x23
  __int64 result; // x0
  unsigned int v16; // w19
  const char *v17; // x2

  _ReadStatusReg(SP_EL0);
  v11 = a1[3];
  if ( !v11 )
  {
    v16 = 4;
    v17 = "%s: psoc is null";
LABEL_15:
    qdf_trace_msg(0x36u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "dfs_phyerr_event_handler");
    result = v16;
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_lmac_if_get_dfs_rx_ops");
    v16 = 4;
    v17 = "%s: dfs_rx_ops is null";
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(v12 + 688) )
  {
    v16 = 4;
    v17 = "%s: dfs_process_phyerr handler is null";
    goto LABEL_15;
  }
  if ( !a1[4] )
  {
    v16 = -22;
    v17 = "%s: pdev is null";
    goto LABEL_15;
  }
  if ( a11 )
  {
    while ( 1 )
    {
      result = wmi_extract_single_phyerr(*a1);
      if ( (_DWORD)result )
        break;
      if ( !a11 )
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    result = 0;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
