__int64 __fastcall lim_mgmt_link_recfg_req_tx_complete(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        int a11,
        __int64 a12)
{
  unsigned __int64 v12; // x8
  int v13; // w9
  unsigned int v14; // w19
  __int64 v16; // x21
  const char *v17; // x3
  __int64 v18; // x19

  if ( !a12 )
    goto LABEL_8;
  v12 = 34;
  if ( (*(_BYTE *)(*(_QWORD *)(a10 + 224) + 1LL) & 0x40) == 0 )
    v12 = 26;
  v13 = (*(_BYTE *)(a10 + 68) & 4) != 0 ? *(unsigned __int16 *)(a10 + 66) : 0;
  if ( v12 <= (unsigned int)(*(_DWORD *)(a10 + 112) + v13) )
  {
    v16 = jiffies;
    if ( lim_mgmt_link_recfg_req_tx_complete___last_ticks - jiffies + 125 >= 0 )
    {
      v14 = 0;
      if ( !a10 )
        return v14;
      goto LABEL_9;
    }
    if ( a11 )
      v17 = "fail";
    else
      v17 = "success";
    v18 = a10;
    qdf_trace_msg(0x35u, 4u, "Link Reconfiguration TX: %s (%d)", a1, a2, a3, a4, a5, a6, a7, a8, v17);
    a10 = v18;
    v14 = 0;
    lim_mgmt_link_recfg_req_tx_complete___last_ticks = v16;
    if ( a10 )
LABEL_9:
      _qdf_nbuf_free(a10);
  }
  else
  {
LABEL_8:
    v14 = 16;
    if ( a10 )
      goto LABEL_9;
  }
  return v14;
}
