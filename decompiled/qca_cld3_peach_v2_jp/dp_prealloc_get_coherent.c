__int64 __fastcall dp_prealloc_get_coherent(
        unsigned int *a1,
        _QWORD *a2,
        _QWORD *a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        unsigned int a14)
{
  __int64 v15; // x19
  _QWORD *v16; // x8
  __int64 v17; // x9
  __int64 v18; // x21
  const char *str_from_hal_ring_type; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v15 = 0;
  v16 = &unk_15CE0;
  do
  {
    if ( *((_DWORD *)v16 - 6) == a14 && !*((_BYTE *)v16 - 16) )
    {
      v17 = *(v16 - 1);
      if ( v17 )
      {
        if ( *a1 <= *((_DWORD *)v16 - 5) )
        {
          *((_BYTE *)v16 - 16) = 1;
          *a2 = v17;
          *a3 = v16[1];
          *a4 = v16[2];
          v18 = *v16;
          *a1 = *((_DWORD *)v16 - 5);
          str_from_hal_ring_type = dp_srng_get_str_from_hal_ring_type(a14, a5, a6, a7, a8, a9, a10, a11, a12);
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: index %i -> ring type %s va-aligned %pK",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "dp_prealloc_get_coherent",
            (unsigned int)v15,
            str_from_hal_ring_type,
            v18);
          return v18;
        }
      }
    }
    ++v15;
    v16 += 6;
  }
  while ( v15 != 28 );
  v30 = dp_srng_get_str_from_hal_ring_type(a14, a5, a6, a7, a8, a9, a10, a11, a12);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: unable to allocate memory for ring type %s (%d) size %d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "dp_prealloc_get_coherent",
    v30,
    a14,
    *a1);
  return 0;
}
