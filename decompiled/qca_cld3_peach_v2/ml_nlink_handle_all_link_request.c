__int64 __fastcall ml_nlink_handle_all_link_request(
        int a1,
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
  __int64 result; // x0
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
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  __int64 v49; // x8
  __int64 v50; // x9
  __int64 v51; // x10
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x22
  __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x10
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int16 v72; // w4
  int v73; // w8
  int v74; // w9
  char v75; // w6
  __int16 v76; // w7
  int v77; // w10
  int v78; // [xsp+0h] [xbp-70h]
  int v79; // [xsp+8h] [xbp-68h]
  int v80; // [xsp+10h] [xbp-60h]
  __int64 v81; // [xsp+18h] [xbp-58h]
  __int64 v82; // [xsp+20h] [xbp-50h] BYREF
  __int64 v83; // [xsp+28h] [xbp-48h]
  __int64 v84; // [xsp+30h] [xbp-40h]
  __int64 v85; // [xsp+38h] [xbp-38h] BYREF
  __int64 v86; // [xsp+40h] [xbp-30h]
  int v87; // [xsp+48h] [xbp-28h]
  __int64 v88; // [xsp+50h] [xbp-20h] BYREF
  __int64 v89; // [xsp+58h] [xbp-18h]
  int v90; // [xsp+60h] [xbp-10h]
  __int64 v91; // [xsp+68h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 1360);
  v90 = 0;
  v88 = 0;
  v89 = 0;
  v87 = 0;
  v85 = 0;
  v86 = 0;
  LODWORD(v84) = 0;
  v82 = 0;
  v83 = 0;
  if ( v11 && *(_QWORD *)(v11 + 2224) )
  {
    qdf_mem_set(&v85, 0x14u, 0);
    v23 = *(_QWORD *)(a2 + 1360);
    if ( v23 && *(_QWORD *)(v23 + 2224) )
    {
      qdf_mutex_acquire(v23 + 1656);
      v24 = *(_QWORD *)(v23 + 2224);
      v25 = *(_QWORD *)(v24 + 1368);
      v26 = *(_QWORD *)(v24 + 1376);
      LODWORD(v24) = *(_DWORD *)(v24 + 1384);
      v85 = v25;
      v86 = v26;
      v87 = v24;
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
        "ml_nlink_get_force_link_request");
    }
    qdf_mem_set(&v88, 0x14u, 0);
    v36 = *(_QWORD *)(a2 + 1360);
    if ( v36 && *(_QWORD *)(v36 + 2224) )
    {
      qdf_mutex_acquire(v36 + 1656);
      v37 = *(_QWORD *)(v36 + 2224);
      v39 = *(_QWORD *)(v37 + 1388);
      v38 = *(_QWORD *)(v37 + 1396);
      v90 = *(_DWORD *)(v37 + 1404);
      v88 = v39;
      v89 = v38;
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
        "ml_nlink_get_force_link_request");
    }
    if ( (ml_nlink_validate_request(a1, a2, (int)&v85, 1, (int)&v88, (int)&v82) & 1) != 0 )
      qdf_mem_copy(&v85, &v82, 0x14u);
    qdf_mem_set(&v88, 0x14u, 0);
    v48 = *(_QWORD *)(a2 + 1360);
    if ( v48 && *(_QWORD *)(v48 + 2224) )
    {
      qdf_mutex_acquire(v48 + 1656);
      v49 = *(_QWORD *)(v48 + 2224);
      v50 = *(_QWORD *)(v49 + 1408);
      v51 = *(_QWORD *)(v49 + 1416);
      LODWORD(v49) = *(_DWORD *)(v49 + 1424);
      v88 = v50;
      v89 = v51;
      v90 = v49;
      qdf_mutex_release(v48 + 1656);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo_ctx or sta_ctx null",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "ml_nlink_get_force_link_request");
    }
    if ( (ml_nlink_validate_request(a1, a2, (int)&v85, 2, (int)&v88, (int)&v82) & 1) != 0 )
      qdf_mem_copy(&v85, &v82, 0x14u);
    qdf_mem_set(&v88, 0x14u, 0);
    v60 = *(_QWORD *)(a2 + 1360);
    if ( v60 && *(_QWORD *)(v60 + 2224) )
    {
      qdf_mutex_acquire(v60 + 1656);
      v61 = *(_QWORD *)(v60 + 2224);
      v63 = *(_QWORD *)(v61 + 1428);
      v62 = *(_QWORD *)(v61 + 1436);
      v90 = *(_DWORD *)(v61 + 1444);
      v88 = v63;
      v89 = v62;
      qdf_mutex_release(v60 + 1656);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo_ctx or sta_ctx null",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "ml_nlink_get_force_link_request");
    }
    if ( (ml_nlink_validate_request(a1, a2, (int)&v85, 3, (int)&v88, (int)&v82) & 1) != 0 )
      qdf_mem_copy(&v85, &v82, 0x14u);
    v72 = WORD1(v86);
    v73 = BYTE4(v86);
    v74 = HIWORD(v86);
    v75 = v87;
    v76 = HIWORD(v87);
    v77 = *(unsigned __int16 *)(a3 + 12);
    *(_WORD *)a3 = v86;
    *(_WORD *)(a3 + 2) = v72;
    *(_BYTE *)(a3 + 4) = v73;
    *(_WORD *)(a3 + 6) = v74;
    *(_BYTE *)(a3 + 8) = v75;
    *(_WORD *)(a3 + 10) = v76;
    v80 = v77;
    v79 = v74;
    v78 = v73;
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
               v64,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               v71,
               "ml_nlink_handle_all_link_request",
               v78,
               v79,
               v80,
               v81,
               v82,
               v83,
               v84,
               v85);
  }
  else
  {
    result = qdf_trace_msg(
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
               "ml_nlink_handle_all_link_request");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
