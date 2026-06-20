__int64 __fastcall lim_set_csa_chan_param_11be(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  unsigned int v14; // w2

  if ( !a3 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: invalid input parameter",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_set_csa_chan_param_11be");
  v12 = *(_QWORD *)(a1 + 16);
  if ( !v12 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: invalid input parameter",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_set_csa_chan_param_11be");
  v14 = *(_DWORD *)(a2 + 12);
  if ( v14 == 7 )
  {
    if ( (*(_BYTE *)(a1 + 10075) & 2) != 0 )
    {
      v14 = 7;
    }
    else
    {
      *a3 = 3;
      v12 = *(_QWORD *)(a1 + 16);
      v14 = *(_DWORD *)(a2 + 12);
    }
  }
  return wlan_cm_sta_set_chan_param(
           v12,
           *(_DWORD *)(a2 + 4),
           v14,
           *(unsigned __int16 *)(a2 + 16),
           *(unsigned __int8 *)(a2 + 19),
           *(unsigned __int8 *)(a2 + 20),
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11);
}
