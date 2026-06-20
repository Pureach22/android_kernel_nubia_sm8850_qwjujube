__int64 __fastcall hdd_display_napi_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 all; // x0
  unsigned int v17; // w20
  __int64 v18; // x19
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 i; // x20
  __int64 v29; // x8
  unsigned __int64 v30; // x23
  unsigned int *v31; // x25
  unsigned int v32; // w0
  unsigned int v33; // w24
  int v34; // w0
  unsigned int v35; // w24
  int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x5
  __int64 result; // x0
  __int64 v47; // [xsp+0h] [xbp-60h]
  __int64 v48; // [xsp+8h] [xbp-58h]
  __int64 v49; // [xsp+10h] [xbp-50h]
  __int64 v50; // [xsp+18h] [xbp-48h]
  _QWORD v51[3]; // [xsp+38h] [xbp-28h] BYREF
  char v52; // [xsp+50h] [xbp-10h]
  __int64 v53; // [xsp+58h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  memset(v51, 0, sizeof(v51));
  if ( _cds_get_context(61, (__int64)"hdd_napi_get_all", a1, a2, a3, a4, a5, a6, a7, a8)
    && (all = hif_napi_get_all()) != 0 )
  {
    v17 = *(_DWORD *)(all + 1680);
    v18 = all;
    v19 = hif_napi_cpu_denylist();
    qdf_trace_msg(
      0x33u,
      4u,
      "[NAPI %u][BL %d]:  scheds   polls   comps    done t-lim p-lim  corr  max_time napi-buckets(%d)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v17,
      v19,
      4);
    for ( i = 0; i != 12; ++i )
    {
      if ( ((*(_DWORD *)(v18 + 28) >> i) & 1) != 0 )
      {
        v29 = *(_QWORD *)(v18 + 40 + 8 * i);
        if ( v29 )
        {
          v30 = 0;
          v31 = (unsigned int *)(v29 + 3144);
          while ( v30 < (unsigned int)_sw_hweight64(_cpu_possible_mask) )
          {
            if ( v30 == 33
              || (scnprintf(v51, 25, " %d", v31[5]), v32 > 0x19)
              || (v33 = v32, scnprintf((char *)v51 + v32, 25 - v32, " %d", v31[6]), v35 = v34 + v33, v35 > 0x19)
              || (scnprintf((char *)v51 + v35, 25 - v35, " %d", v31[7]), v36 + v35 > 0x19) )
            {
              __break(0x5512u);
            }
            v37 = scnprintf((char *)v51 + v36 + v35, 25 - (v36 + v35), " %d", v31[8]);
            v45 = *v31;
            if ( (_DWORD)v45 )
            {
              LODWORD(v50) = v31[4];
              LODWORD(v49) = v31[10];
              LODWORD(v48) = v31[9];
              LODWORD(v47) = v31[3];
              qdf_trace_msg(
                0x33u,
                4u,
                "NAPI[%2d]CPU[%d]: %7d %7d %7d %7d %5d %5d %5d %9llu %s",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                (unsigned int)i,
                (unsigned int)v30,
                v45,
                v31[1],
                v31[2],
                v47,
                v48,
                v49,
                v50,
                *((_QWORD *)v31 + 6),
                v51);
            }
            ++v30;
            v31 += 18;
          }
        }
      }
    }
    hif_napi_stats(v18);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to retrieve napi structure",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_display_napi_stats");
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
