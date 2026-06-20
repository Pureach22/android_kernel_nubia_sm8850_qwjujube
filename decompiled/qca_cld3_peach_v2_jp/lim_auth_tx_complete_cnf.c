__int64 __fastcall lim_auth_tx_complete_cnf(
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
  __int64 v15; // x23
  const char *v16; // x3
  unsigned int v17; // w8
  int v18; // w9
  unsigned int v19; // w22
  _WORD *v20; // x8

  if ( a4 )
    wlan_send_tx_complete_event(a1, a2, a4, a3, 2);
  v15 = jiffies;
  if ( lim_auth_tx_complete_cnf___last_ticks - jiffies + 125 < 0 )
  {
    if ( a3 )
      v16 = "fail";
    else
      v16 = "success";
    qdf_trace_msg(0x35u, 4u, "Auth TX: %s (%d)", a5, a6, a7, a8, a9, a10, a11, a12, v16, a3);
    lim_auth_tx_complete_cnf___last_ticks = v15;
  }
  if ( a3 == 3 )
  {
    *(_DWORD *)(a1 + 21588) = 2;
    v19 = 1;
    if ( !a2 )
      goto LABEL_26;
    goto LABEL_25;
  }
  if ( a3 )
  {
    v19 = 2;
    *(_DWORD *)(a1 + 21588) = 3;
    if ( !a2 )
      goto LABEL_26;
    goto LABEL_25;
  }
  *(_DWORD *)(a1 + 21588) = 1;
  if ( !a2 )
  {
    qdf_trace_msg(0x35u, 8u, "%s: buf is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "lim_is_ack_for_sae_auth");
    goto LABEL_24;
  }
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
  {
    v18 = *(unsigned __int16 *)(a2 + 66);
    v17 = *(_DWORD *)(a2 + 112);
    if ( v17 + v18 <= 0x19 )
      goto LABEL_20;
  }
  else
  {
    v17 = *(_DWORD *)(a2 + 112);
    if ( v17 < 0x1A )
    {
      v18 = 0;
LABEL_20:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: buf_len %d less than min_len %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "lim_is_ack_for_sae_auth",
        v18 + v17,
        26);
      goto LABEL_24;
    }
  }
  v20 = *(_WORD **)(a2 + 224);
  if ( (*v20 & 0xF0) == 0xB0 && v20[12] == 3 )
  {
    v19 = 0;
LABEL_25:
    _qdf_nbuf_free(a2);
    goto LABEL_26;
  }
LABEL_24:
  lim_deactivate_and_change_timer(a1, 20);
  v19 = 0;
  if ( a2 )
    goto LABEL_25;
LABEL_26:
  lim_diag_event_report(a1, 78, 0, v19);
  return 0;
}
