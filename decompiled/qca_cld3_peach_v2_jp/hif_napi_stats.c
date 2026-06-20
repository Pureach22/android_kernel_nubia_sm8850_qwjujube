__int64 __fastcall hif_napi_stats(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 i; // x20
  __int64 result; // x0
  __int64 v29; // [xsp+10h] [xbp-20h]
  __int64 v30; // [xsp+18h] [xbp-18h]
  __int64 v31; // [xsp+20h] [xbp-10h]

  if ( !a1 )
    return qdf_trace_msg(
             0x38u,
             8u,
             "%s: %s: napiid struct is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hif_napi_stats",
             "hif_napi_stats");
  v9 = a1 + 34;
  qdf_trace_msg(0x38u, 8u, "%s: NAPI CPU TABLE", a2, a3, a4, a5, a6, a7, a8, a9, "hif_napi_stats");
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: lilclhead=%d, bigclhead=%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hif_napi_stats",
    a1[418],
    a1[419]);
  for ( i = 0; i != 32; ++i )
  {
    LODWORD(v31) = v9[11];
    LODWORD(v30) = v9[9];
    LODWORD(v29) = v9[8];
    result = qdf_trace_msg(
               0x38u,
               8u,
               "%s: CPU[%02d]: state:%d crid=%02d clid=%02d crmk:0x%0lx thmk:0x%0lx frq:%d napi = 0x%08x lnk:%d",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "hif_napi_stats",
               (unsigned int)i,
               *v9,
               v9[1],
               v9[2],
               *((_QWORD *)v9 + 2),
               *((_QWORD *)v9 + 3),
               v29,
               v30,
               v31);
    v9 += 12;
  }
  return result;
}
