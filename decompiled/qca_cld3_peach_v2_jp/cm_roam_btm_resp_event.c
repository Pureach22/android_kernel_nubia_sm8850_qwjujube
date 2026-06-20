__int64 __fastcall cm_roam_btm_resp_event(
        _DWORD *a1,
        __int64 a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v14; // w19
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x0
  __int64 *v20; // x2
  int v21; // w10
  int v22; // w9
  unsigned int v24; // w23
  __int16 v25; // w20
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x0
  int v31; // w10
  __int64 result; // x0
  unsigned int v33; // w21
  __int64 v34; // x1
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x0
  char v39; // w10
  char v40; // w8
  int v41; // w11
  char v42; // w10
  __int64 v43; // [xsp+8h] [xbp-78h] BYREF
  unsigned __int64 v44; // [xsp+10h] [xbp-70h]
  __int64 v45; // [xsp+18h] [xbp-68h]
  __int64 v46; // [xsp+20h] [xbp-60h]
  __int64 v47; // [xsp+28h] [xbp-58h]
  __int64 v48; // [xsp+30h] [xbp-50h]
  int v49; // [xsp+38h] [xbp-48h]
  __int64 v50; // [xsp+40h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+48h] [xbp-38h]
  __int64 v52; // [xsp+50h] [xbp-30h]
  __int64 v53; // [xsp+58h] [xbp-28h]
  __int64 v54; // [xsp+60h] [xbp-20h]
  __int64 v55; // [xsp+68h] [xbp-18h]
  int v56; // [xsp+70h] [xbp-10h]
  __int64 v57; // [xsp+78h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  if ( (a4 & 1) != 0 )
  {
    v56 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    time_of_the_day_us = 0;
    qdf_mem_set(&v50, 0x34u, 0);
    v14 = a1[4];
    HIWORD(v50) = a3;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v19 = ktime_get(time_of_the_day_us, v15, v16, v17, v18);
    LOBYTE(v54) = 1;
    BYTE1(v55) = 23;
    v20 = &v50;
    v21 = a1[7];
    BYTE1(v54) = a1[6];
    BYTE3(v54) = v21;
    v22 = a1[15];
    v52 = 1000LL * v14;
    v53 = v19 / 1000;
    WORD1(v55) = v22;
LABEL_9:
    host_diag_event_report_payload(3361, 52, v20);
    result = 0;
    goto LABEL_10;
  }
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) )
    {
      v56 = 0;
      v54 = 0;
      v55 = 0;
      v52 = 0;
      v53 = 0;
      v50 = 0;
      time_of_the_day_us = 0;
      qdf_mem_set(&v50, 0x34u, 0);
      v24 = a1[4];
      v25 = a3;
      HIWORD(v50) = a3;
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      v30 = ktime_get(time_of_the_day_us, v26, v27, v28, v29);
      LOBYTE(v54) = 1;
      v31 = *(_DWORD *)(a2 + 16);
      BYTE1(v55) = 23;
      BYTE1(v54) = v31;
      v52 = 1000LL * v24;
      v53 = v30 / 1000;
      BYTE3(v54) = -1;
      host_diag_event_report_payload(3361, 52, &v50);
    }
    else
    {
      v25 = a3;
    }
    qdf_mem_set(&v43, 0x34u, 0);
    v33 = *(_DWORD *)(a2 + 20);
    HIWORD(v43) = v25;
    v44 = qdf_get_time_of_the_day_us();
    v38 = ktime_get(v44, v34, v35, v36, v37);
    v45 = 1000LL * v33;
    v46 = v38 / 1000;
    qdf_mem_copy(&v43, (const void *)(a2 + 8), 6u);
    v39 = *(_BYTE *)(a2 + 24);
    LOBYTE(v47) = 2;
    v40 = *(_BYTE *)(a2 + 28);
    v41 = *(_DWORD *)(a2 + 4);
    BYTE1(v48) = 21;
    v20 = &v43;
    LOBYTE(v48) = v39;
    v42 = *(_BYTE *)(a2 + 26);
    BYTE5(v47) = v41;
    BYTE6(v47) = v42;
    HIBYTE(v47) = HIBYTE(v47) & 1 | (2 * v40);
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev_id:%d btm data is NULL",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "cm_roam_btm_resp_event",
    a3);
  result = 16;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
