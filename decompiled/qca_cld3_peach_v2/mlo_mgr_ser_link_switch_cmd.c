__int64 __fastcall mlo_mgr_ser_link_switch_cmd(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x8
  int v14; // w9
  _QWORD *v16; // x20
  __int64 v17; // x8
  __int64 v18; // x11
  __int64 v19; // x12
  int v20; // w9
  int v21; // w10
  char is_link_recfg_in_progress; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  __int64 result; // x0
  __int64 v42; // x22
  unsigned int v43; // w21
  unsigned int v44[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v45)(); // [xsp+10h] [xbp-30h]
  __int64 v46; // [xsp+18h] [xbp-28h]
  __int64 v47; // [xsp+20h] [xbp-20h]
  __int64 v48; // [xsp+28h] [xbp-18h]
  __int64 v49; // [xsp+30h] [xbp-10h]
  __int64 v50; // [xsp+38h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  if ( !v10 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ML dev ctx NULL, reject link switch",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_mgr_ser_link_switch_cmd");
LABEL_8:
    result = 4;
    goto LABEL_13;
  }
  v11 = *(_QWORD *)(v10 + 3880);
  v12 = *a2;
  v14 = *(unsigned __int8 *)(a1 + 168);
  v48 = a1;
  *(_QWORD *)(v11 + 144) = v12;
  v16 = (_QWORD *)(v11 + 144);
  v17 = a2[4];
  v19 = a2[1];
  v18 = a2[2];
  v16[3] = a2[3];
  v16[4] = v17;
  v16[1] = v19;
  v16[2] = v18;
  v45 = mlo_mgr_ser_link_switch_cb;
  LODWORD(v17) = v14 << 16;
  v20 = *((unsigned __int8 *)a2 + 2);
  LODWORD(v46) = 40;
  v21 = *((unsigned __int8 *)a2 + 1);
  LODWORD(v47) = 35000;
  v44[0] = 30;
  v44[1] = v17 | (v20 << 8) | v21;
  BYTE4(v46) = 2;
  is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(a1);
  if ( *((_DWORD *)a2 + 6) != 4 && (is_link_recfg_in_progress & 1) == 0 )
  {
    v31 = wlan_serialization_request(v44, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( v31 == 1 )
    {
      v40 = "%s: Link switch cmd in active queue";
      goto LABEL_12;
    }
    if ( !v31 )
    {
      v40 = "%s: Link switch cmd in pending queue";
LABEL_12:
      qdf_trace_msg(0x8Fu, 8u, v40, v32, v33, v34, v35, v36, v37, v38, v39, "mlo_mgr_ser_link_switch_cmd");
      result = 0;
      goto LABEL_13;
    }
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Do not serialize link switch for reason %d link_recfg_in_prog %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "mlo_mgr_ser_link_switch_cmd");
  result = mlo_mgr_start_link_switch(a1);
  if ( (_DWORD)result )
  {
    v42 = *(_QWORD *)(a1 + 1360);
    v43 = result;
    qdf_mutex_acquire(v42 + 1656);
    *(_DWORD *)(*(_QWORD *)(v42 + 3880) + 164LL) = 6;
    qdf_mutex_release(v42 + 1656);
    mlo_mgr_link_switch_notify(a1, (__int64)v16);
    result = v43;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
