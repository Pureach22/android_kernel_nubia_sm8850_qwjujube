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
  __int64 v15; // x0
  __int64 *v16; // x2
  int v17; // w10
  int v18; // w9
  unsigned int v20; // w23
  __int16 v21; // w20
  __int64 v22; // x0
  int v23; // w10
  __int64 result; // x0
  unsigned int v25; // w21
  __int64 v26; // x0
  char v27; // w10
  char v28; // w8
  int v29; // w11
  char v30; // w10
  __int64 v31; // [xsp+8h] [xbp-78h] BYREF
  unsigned __int64 v32; // [xsp+10h] [xbp-70h]
  __int64 v33; // [xsp+18h] [xbp-68h]
  __int64 v34; // [xsp+20h] [xbp-60h]
  __int64 v35; // [xsp+28h] [xbp-58h]
  __int64 v36; // [xsp+30h] [xbp-50h]
  int v37; // [xsp+38h] [xbp-48h]
  __int64 v38; // [xsp+40h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+48h] [xbp-38h]
  __int64 v40; // [xsp+50h] [xbp-30h]
  __int64 v41; // [xsp+58h] [xbp-28h]
  __int64 v42; // [xsp+60h] [xbp-20h]
  __int64 v43; // [xsp+68h] [xbp-18h]
  int v44; // [xsp+70h] [xbp-10h]
  __int64 v45; // [xsp+78h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  if ( (a4 & 1) != 0 )
  {
    v44 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    time_of_the_day_us = 0;
    qdf_mem_set(&v38, 0x34u, 0);
    v14 = a1[4];
    HIWORD(v38) = a3;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v15 = ktime_get();
    LOBYTE(v42) = 1;
    BYTE1(v43) = 23;
    v16 = &v38;
    v17 = a1[7];
    BYTE1(v42) = a1[6];
    BYTE3(v42) = v17;
    v18 = a1[15];
    v40 = 1000LL * v14;
    v41 = v15 / 1000;
    WORD1(v43) = v18;
LABEL_9:
    host_diag_event_report_payload(3361, 52, v16);
    result = 0;
    goto LABEL_10;
  }
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) )
    {
      v44 = 0;
      v42 = 0;
      v43 = 0;
      v40 = 0;
      v41 = 0;
      v38 = 0;
      time_of_the_day_us = 0;
      qdf_mem_set(&v38, 0x34u, 0);
      v20 = a1[4];
      v21 = a3;
      HIWORD(v38) = a3;
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      v22 = ktime_get();
      LOBYTE(v42) = 1;
      v23 = *(_DWORD *)(a2 + 16);
      BYTE1(v43) = 23;
      BYTE1(v42) = v23;
      v40 = 1000LL * v20;
      v41 = v22 / 1000;
      BYTE3(v42) = -1;
      host_diag_event_report_payload(3361, 52, &v38);
    }
    else
    {
      v21 = a3;
    }
    qdf_mem_set(&v31, 0x34u, 0);
    v25 = *(_DWORD *)(a2 + 20);
    HIWORD(v31) = v21;
    v32 = qdf_get_time_of_the_day_us();
    v26 = ktime_get();
    v33 = 1000LL * v25;
    v34 = v26 / 1000;
    qdf_mem_copy(&v31, (const void *)(a2 + 8), 6u);
    v27 = *(_BYTE *)(a2 + 24);
    LOBYTE(v35) = 2;
    v28 = *(_BYTE *)(a2 + 28);
    v29 = *(_DWORD *)(a2 + 4);
    BYTE1(v36) = 21;
    v16 = &v31;
    LOBYTE(v36) = v27;
    v30 = *(_BYTE *)(a2 + 26);
    BYTE5(v35) = v29;
    BYTE6(v35) = v30;
    HIBYTE(v35) = HIBYTE(v35) & 1 | (2 * v28);
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
