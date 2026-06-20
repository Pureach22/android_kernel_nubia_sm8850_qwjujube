__int64 __fastcall lim_update_stads_eht_bw_320mhz(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned int v12; // w8
  bool v13; // cc
  int v14; // w8
  bool v15; // zf

  v12 = *(unsigned __int8 *)(result + 154);
  v13 = v12 > 0xD;
  v14 = (1 << v12) & 0x3001;
  v15 = v13 || v14 == 0;
  if ( !v15 && *(_BYTE *)(a2 + 932) && *(_DWORD *)(result + 7176) == 7 && (*(_BYTE *)(a2 + 935) & 2) != 0 )
  {
    *(_DWORD *)(a2 + 360) = 7;
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: ch_width %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_update_stads_eht_bw_320mhz",
             7,
             v10,
             v11);
  }
  return result;
}
