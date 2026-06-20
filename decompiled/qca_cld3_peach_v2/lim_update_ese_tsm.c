__int64 __fastcall lim_update_ese_tsm(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int v26; // w10

  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: TSM IE Present in Reassoc Rsp",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_update_ese_tsm");
  if ( !*(_BYTE *)(a3 + 2293) )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: TSM present but TSPEC IE not present",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "lim_update_ese_tsm");
  v25 = *(unsigned __int8 *)(a3 + 2036);
  if ( *(_BYTE *)(a3 + 2036) )
  {
    v26 = (*(unsigned __int16 *)(a3 + 2042) >> 11) & 7;
    if ( (~(0x33220110u >> (4 * ((*(unsigned __int16 *)(a3 + 2042) >> 11) & 7))) & 3) == 0 )
      goto LABEL_4;
    if ( v25 == 1 )
      return result;
    v26 = (*(unsigned __int16 *)(a3 + 2102) >> 11) & 7;
    if ( (~(0x33220110u >> (4 * ((*(unsigned __int16 *)(a3 + 2102) >> 11) & 7))) & 3) == 0 )
      goto LABEL_4;
    if ( v25 == 2 )
      return result;
    v26 = (*(unsigned __int16 *)(a3 + 2162) >> 11) & 7;
    if ( (~(0x33220110u >> (4 * ((*(unsigned __int16 *)(a3 + 2162) >> 11) & 7))) & 3) == 0 )
      goto LABEL_4;
    if ( v25 == 3 )
      return result;
    v26 = (*(unsigned __int16 *)(a3 + 2222) >> 11) & 7;
    if ( (~(0x33220110u >> (4 * ((*(unsigned __int16 *)(a3 + 2222) >> 11) & 7))) & 3) != 0 )
    {
      if ( v25 != 4 )
      {
        __break(0x5512u);
        return lim_update_vdev_rate_set(result, v15, v16);
      }
    }
    else
    {
LABEL_4:
      a2[7044] = v26;
      qdf_mem_copy(a2 + 7046, (const void *)(a3 + 2280), 4u);
      result = lim_send_sme_tsm_ie_ind(
                 a1,
                 (__int64)a2,
                 *(_BYTE *)(a3 + 2280),
                 *(_BYTE *)(a3 + 2281),
                 *(_WORD *)(a3 + 2282));
      if ( a2[7047] )
        ++a2[7050];
    }
  }
  return result;
}
