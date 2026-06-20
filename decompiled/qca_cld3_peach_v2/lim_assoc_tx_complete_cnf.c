__int64 __fastcall lim_assoc_tx_complete_cnf(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x24
  unsigned int v14; // w21
  const char *v17; // x3

  v13 = jiffies;
  v14 = a3;
  if ( lim_assoc_tx_complete_cnf___last_ticks - jiffies + 125 < 0 )
  {
    if ( a3 )
      v17 = "fail";
    else
      v17 = "success";
    qdf_trace_msg(0x35u, 4u, "Assoc req TX: %s (%d)", a5, a6, a7, a8, a9, a10, a11, a12, v17, a3);
    lim_assoc_tx_complete_cnf___last_ticks = v13;
  }
  if ( a4 )
    wlan_send_tx_complete_event(a1, a2, a4, v14, 4);
  if ( v14 )
  {
    if ( v14 == 3 )
    {
      v14 = 1;
      *(_DWORD *)(a1 + 21664) = 2;
      if ( !a2 )
        goto LABEL_14;
    }
    else
    {
      v14 = 2;
      *(_DWORD *)(a1 + 21664) = 3;
      if ( !a2 )
        goto LABEL_14;
    }
    goto LABEL_13;
  }
  *(_DWORD *)(a1 + 21664) = 1;
  if ( a2 )
LABEL_13:
    _qdf_nbuf_free(a2);
LABEL_14:
  lim_diag_event_report(a1, 79, 0, v14);
  return 0;
}
