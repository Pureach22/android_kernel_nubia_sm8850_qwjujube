__int64 __fastcall extract_thermal_stats_tlv(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        unsigned int *a4,
        unsigned int *a5,
        __int64 a6,
        _DWORD *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v15; // w22
  unsigned int *v16; // x27
  __int64 v24; // x1
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w4
  __int64 v37; // x23
  __int64 v38; // x4
  int v39; // w24
  _DWORD *v40; // x9
  _DWORD *v41; // x8
  int v42; // w10
  __int64 v44; // [xsp+0h] [xbp-10h]
  __int64 v45; // [xsp+8h] [xbp-8h]

  v15 = 4;
  if ( a2 )
  {
    v16 = *(unsigned int **)a2;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: thermal temperature %d level %d",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "extract_thermal_stats_tlv",
      *(unsigned int *)(*(_QWORD *)a2 + 8LL),
      *(unsigned int *)(*(_QWORD *)a2 + 12LL));
    v24 = v16[1];
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3672LL);
    if ( *((_DWORD *)v25 - 1) != -2112860426 )
      __break(0x8228u);
    *a7 = v25(a1, v24);
    *a3 = v16[2];
    v34 = v16[3];
    if ( v34 >= 4 )
      v34 = 4;
    *a4 = v34;
    if ( v16[4] )
    {
      v35 = *(_DWORD *)(*(_QWORD *)a2 + 16LL);
      if ( v35 >= 5 )
        v36 = 5;
      else
        v36 = *(_DWORD *)(*(_QWORD *)a2 + 16LL);
      *a5 = v36;
      if ( v36 <= *(_DWORD *)(a2 + 40) )
      {
        v37 = *(_QWORD *)(a2 + 32);
        if ( v37 )
        {
          if ( v35 )
          {
            v38 = 0;
            v39 = 0;
            do
            {
              v40 = (_DWORD *)(v37 + 24LL * (unsigned __int8)v39);
              v41 = (_DWORD *)(a6 + 20LL * (unsigned __int8)v39);
              *v41 = v40[1];
              v41[1] = v40[2];
              v41[2] = v40[3];
              v41[3] = v40[4];
              v42 = v40[5];
              v41[4] = v42;
              LODWORD(v45) = v42;
              LODWORD(v44) = v40[4];
              qdf_trace_msg(
                0x31u,
                8u,
                "%s: level %d, start temp %d, end temp %d, total time low %d, total time high %d, counter %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "populate_thermal_stats",
                v38,
                (unsigned int)v40[1],
                (unsigned int)v40[2],
                (unsigned int)v40[3],
                v44,
                v45);
              v38 = (unsigned __int8)++v39;
            }
            while ( *a5 > (unsigned __int8)v39 );
          }
        }
        else
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: wmi_tt_stats Null",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "populate_thermal_stats");
        }
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: therm_throt_levels:%u oob num_temp_range_stats:%u",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "populate_thermal_stats");
      }
    }
    return 0;
  }
  return v15;
}
