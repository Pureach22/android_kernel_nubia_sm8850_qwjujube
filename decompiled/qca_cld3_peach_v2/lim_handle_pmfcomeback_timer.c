__int64 __fastcall lim_handle_pmfcomeback_timer(
        __int64 a1,
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
  __int64 result; // x0
  __int64 v13; // x20
  int v14; // w8
  unsigned int v15; // w9
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( *(_DWORD *)(a1 + 7036) )
    return 16;
  v13 = a1 + 4096;
  if ( (*(_BYTE *)(a1 + 7024) & 0x10) == 0 )
    return 16;
  v14 = *(unsigned __int16 *)(a2 + 4);
  if ( *(_BYTE *)(a1 + 8049) )
  {
    if ( v14 == 30 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Already retry in progress",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "lim_handle_pmfcomeback_timer",
        v10,
        v11);
      return 0;
    }
    return 16;
  }
  if ( v14 != 30 || !*(_BYTE *)(a2 + 2400) || *(_BYTE *)(a2 + 2401) != 3 )
    return 16;
  v15 = (unsigned __int16)*(_DWORD *)(a2 + 2404);
  if ( v15 >= 0x5DC )
    v15 = 1500;
  if ( (*(_DWORD *)(a2 + 2404) & 0xFFFEu) >= 0xA )
    v17 = v15;
  else
    v17 = 10;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ASSOC res with eSIR_MAC_TRY_AGAIN_LATER recvd.Starting timer to wait timeout: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_handle_pmfcomeback_timer",
    v17,
    v10,
    v11);
  result = qdf_mc_timer_start(a1 + 7872, v17);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to start comeback timer",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "lim_handle_pmfcomeback_timer");
    return 16;
  }
  *(_BYTE *)(v13 + 3953) = 1;
  return result;
}
