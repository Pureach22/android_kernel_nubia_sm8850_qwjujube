__int64 __fastcall mlo_sta_up_active_notify(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x9
  unsigned __int8 *v21; // x8
  unsigned __int8 *v22; // x22
  __int64 v23; // x10
  const char *v24; // x2
  __int64 result; // x0
  unsigned int v26; // w19
  int v27; // w11
  __int64 v28; // x9
  __int64 v29; // x11
  __int64 v30; // x10
  unsigned __int16 *v31; // x10
  unsigned int v32; // w9
  unsigned __int8 *v33; // x8
  _QWORD v34[4]; // [xsp+10h] [xbp-30h] BYREF
  int v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v24 = "%s: invalid vdev";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_sta_up_active_notify");
    result = 4;
    goto LABEL_33;
  }
  v9 = *(_QWORD *)(a1 + 1360);
  if ( !v9 )
  {
    v24 = "%s: invalid mlo_dev_ctx";
    goto LABEL_9;
  }
  v11 = *(unsigned __int8 *)(a1 + 93);
  qdf_mutex_acquire(v9 + 1656);
  v20 = *(unsigned __int8 **)(v9 + 2224);
  if ( !v20 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: invalid sta_ctx", v12, v13, v14, v15, v16, v17, v18, v19, "mlo_sta_up_active_notify");
    v26 = 4;
LABEL_32:
    qdf_mutex_release(v9 + 1656);
    result = v26;
    goto LABEL_33;
  }
  v21 = v20 + 200;
  if ( (v20[239] & 1) != 0 )
  {
    v22 = v20 + 200;
    v23 = a1;
    if ( v11 == v20[236] )
      goto LABEL_17;
    goto LABEL_13;
  }
  v23 = a1;
  if ( (v20[237] & 1) != 0 )
  {
    v22 = v20 + 200;
    if ( v11 == v20[236] )
    {
LABEL_25:
      v26 = 0;
      v22[37] = 1;
      goto LABEL_32;
    }
LABEL_13:
    v27 = 0;
    goto LABEL_15;
  }
  v27 = 1;
LABEL_15:
  v22 = v20 + 240;
  if ( (v20[279] & 1) == 0 )
  {
    if ( (v20[277] & 1) == 0 )
    {
      v32 = v27 ^ 1;
      goto LABEL_29;
    }
    if ( v11 == v20[276] )
      goto LABEL_25;
LABEL_26:
    if ( (v27 & 1) == 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: no free buffer of csa param for link %d in sta_ctx",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "mlo_sta_up_active_notify",
        v11);
      goto LABEL_31;
    }
    v32 = 0;
LABEL_29:
    v33 = &v21[40 * v32];
    v33[37] = 1;
    v33[36] = v11;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: mld mac %02x:%02x:%02x:**:**:%02x link id %d UP Active",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mlo_sta_up_active_notify",
      *(unsigned __int8 *)(v9 + 17),
      *(unsigned __int8 *)(v9 + 18),
      *(unsigned __int8 *)(v9 + 19),
      *(unsigned __int8 *)(v9 + 22),
      v11);
LABEL_31:
    v26 = 0;
    goto LABEL_32;
  }
  if ( v11 != v20[276] )
    goto LABEL_26;
LABEL_17:
  if ( (v22[37] & 1) != 0 )
    goto LABEL_25;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: mld mac %02x:%02x:%02x:**:**:%02x vdev id %d link id %d handle csa",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "mlo_sta_up_active_notify",
    *(unsigned __int8 *)(v9 + 17),
    *(unsigned __int8 *)(v9 + 18),
    *(unsigned __int8 *)(v9 + 19),
    *(unsigned __int8 *)(v9 + 22),
    *(unsigned __int8 *)(v23 + 168),
    v11);
  v34[0] = *(_QWORD *)v22;
  v29 = *((_QWORD *)v22 + 2);
  v28 = *((_QWORD *)v22 + 3);
  v30 = *((_QWORD *)v22 + 1);
  v35 = *((_DWORD *)v22 + 8);
  v34[2] = v29;
  v34[3] = v28;
  v34[1] = v30;
  v22[37] = 1;
  qdf_mutex_release(v9 + 1656);
  result = 0;
  if ( HIDWORD(v34[0]) )
  {
    v31 = *(unsigned __int16 **)(a1 + 32);
    if ( v31 )
    {
      if ( HIDWORD(v34[0]) != *v31 )
        mlo_mlme_handle_sta_csa_param(a1, (__int64)v34);
      result = 0;
    }
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
