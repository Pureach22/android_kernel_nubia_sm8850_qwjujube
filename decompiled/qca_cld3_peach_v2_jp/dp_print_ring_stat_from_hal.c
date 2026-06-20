__int64 __fastcall dp_print_ring_stat_from_hal(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x22
  const char *str_from_hal_ring_type; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  const char *v24; // x19
  unsigned int v25; // w9
  __int64 v26; // x3
  unsigned int v27; // w10
  int v28; // w10
  __int64 v29; // x2
  void (*v30)(void); // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && a2 && *(_QWORD *)a2 )
  {
    v12 = result;
    str_from_hal_ring_type = dp_srng_get_str_from_hal_ring_type(a3, a4, a5, a6, a7, a8, a9, a10, a11);
    v23 = *(_DWORD **)a2;
    v24 = str_from_hal_ring_type;
    v25 = *(_DWORD *)(*(_QWORD *)a2 + 120LL);
    v26 = **(unsigned int **)(*(_QWORD *)a2 + 128LL);
    v27 = v26 - v25;
    if ( *(_DWORD *)(*(_QWORD *)a2 + 116LL) )
    {
      if ( (unsigned int)v26 >= v25 )
        v28 = v27 / v23[11];
      else
        v28 = (v27 + v23[9]) / v23[11];
      v29 = (unsigned int)v26;
      v26 = v25;
    }
    else
    {
      if ( (unsigned int)v26 <= v25 )
        v27 += v23[9];
      v28 = v27 / v23[11] - 1;
      v29 = v25;
      if ( a3 != 11 )
        v28 = v23[8] - v28;
    }
    DP_PRINT_STATS(
      "%s:SW: Head = %d Tail = %d Ring Usage = %u",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      str_from_hal_ring_type,
      v29,
      v26,
      (unsigned int)(100 * v28) / v23[8],
      -1,
      v39);
    v30 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v12 + 1128) + 74392LL) + 24LL);
    if ( *((_DWORD *)v30 - 1) != 1884881292 )
      __break(0x8228u);
    v30();
    result = DP_PRINT_STATS("%s:HW: Head = %d Tail = %d Ring Usage = %u", v31, v32, v33, v34, v35, v36, v37, v38, v24);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
