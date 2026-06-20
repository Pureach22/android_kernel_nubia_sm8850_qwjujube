__int64 __fastcall ml_nlink_validate_link_request(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  char v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v41; // [xsp+0h] [xbp-50h] BYREF
  __int64 v42; // [xsp+8h] [xbp-48h]
  __int64 v43; // [xsp+10h] [xbp-40h]
  __int64 v44; // [xsp+18h] [xbp-38h] BYREF
  __int64 v45; // [xsp+20h] [xbp-30h]
  __int64 v46; // [xsp+28h] [xbp-28h]
  __int64 v47; // [xsp+30h] [xbp-20h] BYREF
  __int64 v48; // [xsp+38h] [xbp-18h]
  __int64 v49; // [xsp+40h] [xbp-10h]
  __int64 v50; // [xsp+48h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 1360);
  LODWORD(v49) = 0;
  v47 = 0;
  v48 = 0;
  LODWORD(v46) = 0;
  v44 = 0;
  v45 = 0;
  LODWORD(v43) = 0;
  v41 = 0;
  v42 = 0;
  if ( v11 && *(_QWORD *)(v11 + 2224) )
  {
    qdf_mem_set(&v44, 0x14u, 0);
    v23 = *(_QWORD *)(a2 + 1360);
    if ( v23 && *(_QWORD *)(v23 + 2224) )
    {
      qdf_mutex_acquire(v23 + 1656);
      v24 = *(_QWORD *)(v23 + 2224);
      v25 = *(_QWORD *)(v24 + 1368);
      v26 = *(_QWORD *)(v24 + 1376);
      LODWORD(v24) = *(_DWORD *)(v24 + 1384);
      v44 = v25;
      v45 = v26;
      LODWORD(v46) = v24;
      qdf_mutex_release(v23 + 1656);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo_ctx or sta_ctx null",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "ml_nlink_get_force_link_request",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50);
    }
    qdf_mem_set(&v47, 0x14u, 0);
    v36 = *(_QWORD *)(a2 + 1360);
    if ( v36 && *(_QWORD *)(v36 + 2224) )
    {
      qdf_mutex_acquire(v36 + 1656);
      v37 = *(_QWORD *)(v36 + 2224);
      v39 = *(_QWORD *)(v37 + 1388);
      v38 = *(_QWORD *)(v37 + 1396);
      LODWORD(v49) = *(_DWORD *)(v37 + 1404);
      v47 = v39;
      v48 = v38;
      qdf_mutex_release(v36 + 1656);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo_ctx or sta_ctx null",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "ml_nlink_get_force_link_request",
        v41,
        v42,
        v43);
    }
    if ( (ml_nlink_validate_request(a1, a2, (__int64)&v44, 1u, (__int64)&v47, &v41) & 1) != 0 )
      qdf_mem_copy(&v44, &v41, 0x14u);
    v27 = ml_nlink_validate_request(a1, a2, (__int64)&v44, 2u, a3, &v41);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ml_nlink_validate_link_request",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50);
    v27 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v27 & 1;
}
