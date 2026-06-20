__int64 __fastcall ml_nlink_vendor_cmd_handler(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x5
  __int64 v15; // x6
  unsigned int v16; // w8
  unsigned int v17; // w9
  __int64 v18; // x4
  __int64 v19; // x7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w8
  __int64 v29; // x22
  unsigned int v30; // w9
  unsigned int v31; // w10
  unsigned int v32; // w9
  char v33; // w10
  unsigned int v34; // w8
  __int64 v35; // x10
  __int64 v36; // x11
  __int64 v37; // x8
  __int64 result; // x0
  const char *v39; // x3
  __int64 v40; // x1
  unsigned int v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x19
  unsigned int v51; // w20
  __int64 v52; // [xsp+10h] [xbp-20h] BYREF
  __int64 v53; // [xsp+18h] [xbp-18h]
  int v54; // [xsp+20h] [xbp-10h]
  __int64 v55; // [xsp+28h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a3[4];
  v15 = a3[5];
  v16 = a3[2];
  v17 = a3[3];
  v18 = *a3;
  v19 = *((unsigned __int8 *)a3 + 4);
  v54 = 0;
  v53 = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: link ctrl %d mode %d reason %d num %d 0x%x 0x%x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ml_nlink_vendor_cmd_handler",
    v18,
    v14,
    v15,
    v19,
    v16,
    v17,
    0);
  v28 = *a3;
  if ( *a3 == 2 )
  {
    v32 = a3[5];
    v33 = *((_BYTE *)a3 + 4);
    LODWORD(v52) = a3[4];
    HIDWORD(v52) = v32;
    v34 = a3[2];
    BYTE4(v53) = v33;
    HIWORD(v53) = v34;
  }
  else
  {
    if ( v28 != 1 )
    {
      if ( !v28 )
      {
        v29 = *(_QWORD *)(a2 + 1360);
        if ( v29 && *(_QWORD *)(v29 + 2224) )
        {
          qdf_mutex_acquire(v29 + 1656);
          qdf_mem_set((void *)(*(_QWORD *)(v29 + 2224) + 1408LL), 0x14u, 0);
LABEL_13:
          qdf_mutex_release(v29 + 1656);
          goto LABEL_19;
        }
        v39 = "ml_nlink_clr_force_link_request";
        goto LABEL_18;
      }
LABEL_15:
      result = 4;
      goto LABEL_29;
    }
    v30 = a3[5];
    LODWORD(v52) = a3[4];
    HIDWORD(v52) = v30;
    v31 = a3[3];
    LOWORD(v53) = a3[2];
    WORD1(v53) = v31;
  }
  if ( (ml_nlink_validate_link_request(a1, a2, &v52) & 1) == 0 )
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: not supported", v20, v21, v22, v23, v24, v25, v26, v27, "ml_nlink_vendor_cmd_handler");
    goto LABEL_15;
  }
  v29 = *(_QWORD *)(a2 + 1360);
  if ( v29 && *(_QWORD *)(v29 + 2224) )
  {
    qdf_mutex_acquire(v29 + 1656);
    v36 = v52;
    v35 = v53;
    v37 = *(_QWORD *)(v29 + 2224);
    *(_DWORD *)(v37 + 1424) = v54;
    *(_QWORD *)(v37 + 1416) = v35;
    *(_QWORD *)(v37 + 1408) = v36;
    goto LABEL_13;
  }
  v39 = "ml_nlink_update_force_link_request";
LABEL_18:
  qdf_trace_msg(0x8Fu, 2u, "%s: mlo_ctx or sta_ctx null", v20, v21, v22, v23, v24, v25, v26, v27, v39);
LABEL_19:
  if ( a3[5] == 7 )
    v40 = 7;
  else
    v40 = 1;
  v41 = ml_nlink_state_change(a1, v40, 18, a3);
  result = 0;
  if ( v41 && v41 != 24 )
  {
    v50 = *(_QWORD *)(a2 + 1360);
    v51 = v41;
    if ( v50 && *(_QWORD *)(v50 + 2224) )
    {
      qdf_mutex_acquire(v50 + 1656);
      qdf_mem_set((void *)(*(_QWORD *)(v50 + 2224) + 1408LL), 0x14u, 0);
      qdf_mutex_release(v50 + 1656);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo_ctx or sta_ctx null",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "ml_nlink_clr_force_link_request");
    }
    result = v51;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
