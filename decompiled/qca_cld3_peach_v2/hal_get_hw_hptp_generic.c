__int64 __fastcall hal_get_hw_hptp_generic(
        __int64 result,
        __int64 a2,
        _DWORD *a3,
        _DWORD *a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x0
  __int64 v15; // x10
  int v18; // w0
  int v19; // w0
  __int64 v20; // x0
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x0

  if ( !result || !a2 )
    return qdf_trace_msg(
             0x46u,
             2u,
             "%s: Context is Null",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "hal_get_hw_hptp_generic");
  if ( !*(_BYTE *)(*(_QWORD *)(result + 74256) + 36LL * a5 + 20) )
  {
    v13 = *(_QWORD *)(a2 + 160);
    v15 = *(_QWORD *)(a2 + 104);
    if ( *(_DWORD *)(a2 + 116) )
    {
      if ( (*(_BYTE *)(v13 + 74224) & 1) != 0 )
        v18 = hal_read32_mb_1();
      else
        v18 = readl_8(v15 + *(int *)(v13 + 74264));
      *a3 = v18;
      v20 = *(_QWORD *)(a2 + 160);
      v21 = *(_QWORD *)(a2 + 104);
      v22 = v20 + 73728;
      v23 = *(int *)(v20 + 74268);
    }
    else
    {
      if ( (*(_BYTE *)(v13 + 74224) & 1) != 0 )
        v19 = hal_read32_mb_1();
      else
        v19 = readl_8(v15 + *(int *)(v13 + 74336));
      *a3 = v19;
      v24 = *(_QWORD *)(a2 + 160);
      v21 = *(_QWORD *)(a2 + 104);
      v22 = v24 + 73728;
      v23 = *(int *)(v24 + 74340);
    }
    if ( (*(_BYTE *)(v22 + 496) & 1) != 0 )
      result = hal_read32_mb_1();
    else
      result = readl_8(v21 + v23);
    *a4 = result;
  }
  return result;
}
