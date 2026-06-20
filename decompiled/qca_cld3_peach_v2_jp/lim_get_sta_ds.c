__int64 __fastcall lim_get_sta_ds(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        _WORD *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  __int64 v28; // x20
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  _QWORD v33[6]; // [xsp+20h] [xbp-40h] BYREF
  int v34; // [xsp+50h] [xbp-10h]
  __int64 v35; // [xsp+58h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  memset(v33, 0, sizeof(v33));
  result = dph_lookup_hash_entry(a6, a7, a8, a9, a10, a11, a12, a13, a1, a2, a4, a5 + 360);
  if ( !result )
  {
    if ( !(*(_DWORD *)a3 | *(unsigned __int16 *)(a3 + 4)) )
    {
      result = 0;
      goto LABEL_9;
    }
    result = dph_lookup_hash_entry(v19, v20, v21, v22, v23, v24, v25, v26, a1, (unsigned __int8 *)a3, a4, a5 + 360);
    if ( !result )
      goto LABEL_9;
  }
  v27 = *(unsigned __int8 *)(a5 + 10);
  v28 = result;
  if ( a2 )
  {
    v29 = *a2;
    v30 = a2[1];
    v31 = a2[2];
    v32 = a2[5];
  }
  else
  {
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Vdev %d STA found for %02x:%02x:%02x:**:**:%02x%s",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "lim_get_sta_ds",
    v27,
    v29,
    v30,
    v31,
    v32,
    v33);
  result = v28;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
