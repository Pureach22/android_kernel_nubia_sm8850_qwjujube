__int64 __fastcall cm_roam_result_info_event(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int64 v18; // x8
  _BOOL4 v19; // w25
  _BOOL4 v20; // w24
  int v21; // w5
  __int16 v22; // w20
  unsigned __int64 v23; // x28
  unsigned int v24; // w27
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x0
  unsigned int v30; // w9
  int v31; // w12
  char v32; // w8
  int v33; // w8
  unsigned __int16 *v34; // x23
  __int64 v35; // x8
  unsigned __int64 v36; // x23
  unsigned int v37; // w21
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x4
  __int64 v42; // x0
  __int64 result; // x0
  int v44; // w25
  unsigned int v45; // w25
  __int64 v46; // x1
  __int64 v47; // x2
  __int64 v48; // x3
  __int64 v49; // x4
  __int64 v50; // x0
  int v51; // w10
  int v52; // w25
  char v53; // w22
  int v54; // w21
  unsigned int v55; // w9
  bool v56; // cc
  char v57; // w9
  __int64 v58; // [xsp+0h] [xbp-60h] BYREF
  unsigned __int64 v59; // [xsp+8h] [xbp-58h]
  __int64 v60; // [xsp+10h] [xbp-50h]
  __int64 v61; // [xsp+18h] [xbp-48h]
  __int64 v62; // [xsp+20h] [xbp-40h]
  __int64 v63; // [xsp+28h] [xbp-38h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+30h] [xbp-30h]
  __int64 v65; // [xsp+38h] [xbp-28h]
  __int64 v66; // [xsp+40h] [xbp-20h]
  int v67; // [xsp+48h] [xbp-18h]
  __int64 v68; // [xsp+58h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(unsigned int *)(a3 + 12);
  v19 = v18 < 0x21;
  v20 = *(_BYTE *)a4 != 1 || *(unsigned __int16 *)(a4 + 2) != 1;
  LODWORD(v62) = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  if ( (_DWORD)v18 == 36 )
  {
    v21 = *(_DWORD *)(a3 + 16);
    if ( v21 == 5 )
    {
      v22 = 37;
    }
    else
    {
      if ( v21 != 6 )
      {
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: vdev:%d Unsupported abort reason:%d",
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   "cm_roam_result_info_event",
                   (unsigned __int8)a5,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62);
        goto LABEL_39;
      }
      v22 = 38;
    }
    v37 = *(_DWORD *)(a3 + 4);
    v67 = 0;
    v65 = 0;
    v66 = 0;
    v63 = 0;
    time_of_the_day_us = 0;
    qdf_mem_set(&v63, 0x24u, 0);
    HIWORD(v63) = (unsigned __int8)a5;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v42 = ktime_get(time_of_the_day_us, v38, v39, v40, v41);
    LOBYTE(v67) = 2;
    HIWORD(v67) = v22;
    v65 = 1000LL * v37;
    v66 = v42 / 1000;
    result = host_diag_event_report_payload(3360, 36, &v63);
  }
  else
  {
    v23 = 0x118002010uLL >> v18;
    qdf_mem_set(&v58, 0x24u, 0);
    v24 = *(_DWORD *)(a3 + 4);
    HIWORD(v58) = (unsigned __int8)a5;
    v59 = qdf_get_time_of_the_day_us();
    v29 = ktime_get(v59, v25, v26, v27, v28);
    LOBYTE(v62) = 2;
    v31 = *(_DWORD *)(a3 + 8);
    v30 = *(_DWORD *)(a3 + 12);
    WORD1(v62) = v30;
    v32 = BYTE1(v62);
    v60 = 1000LL * v24;
    v61 = v29 / 1000;
    BYTE1(v62) |= 1u;
    if ( v31 == 2 || v30 <= 0x2A && ((1LL << v30) & 0x70E0000000CLL) != 0 )
      BYTE1(v62) = v32 & 0xFE;
    if ( *(_WORD *)(a4 + 4) )
    {
      LOWORD(v33) = *(_WORD *)(a4 + 4) - 1;
      v34 = (unsigned __int16 *)(a4 + 97);
      if ( (v33 & 0xFFF8) != 0 )
        v33 = 8;
      else
        v33 = (unsigned __int16)v33;
      v35 = (unsigned int)(v33 + 1);
      while ( *((_BYTE *)v34 - 1) != 1 )
      {
        --v35;
        v34 += 30;
        if ( !v35 )
          goto LABEL_19;
      }
      qdf_mem_copy(&v58, v34, 6u);
      v36 = *(unsigned int *)v34 | ((unsigned __int64)v34[2] << 32);
    }
    else
    {
LABEL_19:
      v36 = 0;
    }
    v44 = v19 & v23;
    if ( *(_DWORD *)(a3 + 20) | *(unsigned __int16 *)(a3 + 24) )
      qdf_mem_copy(&v58, (const void *)(a3 + 20), 6u);
    host_diag_event_report_payload(3359, 36, &v58);
    qdf_mem_set(&v58, 0x24u, 0);
    if ( v44 )
    {
      v45 = *(_DWORD *)(a3 + 4);
      HIWORD(v58) = (unsigned __int8)a5;
      v59 = qdf_get_time_of_the_day_us();
      v50 = ktime_get(v59, v46, v47, v48, v49);
      v51 = *(_DWORD *)(a3 + 12);
      v60 = 1000LL * v45;
      v61 = v50 / 1000;
      WORD1(v62) = v51;
      host_diag_event_report_payload(3360, 36, &v58);
    }
    v52 = *(unsigned __int8 *)(a2 + 4);
    v53 = BYTE1(v62);
    v54 = *(_DWORD *)(a3 + 12);
    LOBYTE(v63) = 0;
    result = wlan_mlme_get_bmiss_skip_full_scan_value(a1, &v63);
    if ( v52 == 2 && (v53 & 1) == 0 )
    {
      v55 = (unsigned __int8)v54 - 33;
      if ( (v20 | (unsigned __int8)v63) == 1 )
      {
        v56 = v55 > 1;
        v57 = !v20;
        if ( v56 )
          v57 = 1;
        if ( (v57 & 1) != 0 || (v63 & 1) == 0 )
          goto LABEL_39;
      }
      else if ( v55 > 1 )
      {
        goto LABEL_39;
      }
      result = cm_roam_beacon_loss_disconnect_event(a1, v36, a5);
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
