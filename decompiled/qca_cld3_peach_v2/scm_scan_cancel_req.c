__int64 __fastcall scm_scan_cancel_req(
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
  __int64 v9; // x19
  int v10; // w4
  int v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  __int64 result; // x0
  int v22; // w8
  __int64 v23; // x9
  int v24; // w8
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  unsigned int v52; // w20
  __int64 v53; // [xsp+8h] [xbp-58h] BYREF
  __int64 v54; // [xsp+10h] [xbp-50h]
  __int64 v55; // [xsp+18h] [xbp-48h]
  __int64 v56; // [xsp+20h] [xbp-40h]
  __int64 v57; // [xsp+28h] [xbp-38h]
  __int64 v58; // [xsp+30h] [xbp-30h]
  __int64 v59; // [xsp+38h] [xbp-28h] BYREF
  __int64 v60; // [xsp+40h] [xbp-20h]
  __int64 v61; // [xsp+48h] [xbp-18h]
  __int64 v62; // [xsp+50h] [xbp-10h]
  __int64 v63; // [xsp+58h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 8);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 20);
      if ( *(_BYTE *)(v9 + 8) == 1 && v10 == 1 )
      {
        v11 = *(_DWORD *)(v9 + 16);
        v58 = 0;
        LODWORD(v55) = 3;
        HIDWORD(v53) = v11;
        v57 = *(_QWORD *)v9;
        if ( (wlan_serialization_is_cmd_present_in_active_queue(a2, a3, a4, a5, a6, a7, a8, a9, 0, (unsigned int *)&v53)
            & 1) == 0 )
        {
          if ( (wlan_serialization_is_cmd_present_in_pending_queue(
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  0,
                  (unsigned int *)&v53)
              & 1) != 0 )
            v51 = 0;
          else
            v51 = 4;
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: status: %d, reqid: %d, scanid: %d, vdevid: %d, type: %d",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "scm_scan_cancel_req",
            v51,
            *(unsigned int *)(v9 + 12),
            *(unsigned int *)(v9 + 16),
            *(unsigned int *)(v9 + 24),
            *(_DWORD *)(v9 + 20),
            v53,
            v54);
          v42 = 0;
          goto LABEL_22;
        }
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: status: %d, reqid: %d, scanid: %d, vdevid: %d, type: %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "scm_scan_cancel_req",
          1,
          *(unsigned int *)(v9 + 12),
          *(unsigned int *)(v9 + 16),
          *(unsigned int *)(v9 + 24),
          *(_DWORD *)(v9 + 20),
          v53,
          v54);
      }
      else
      {
        v22 = *(_DWORD *)(v9 + 16);
        v59 = 0;
        LODWORD(v60) = v22;
        v23 = *(_QWORD *)v9;
        LOBYTE(v62) = 3;
        v61 = v23;
        if ( (unsigned int)(v10 - 1) >= 4 )
        {
          qdf_trace_msg(
            0x15u,
            3u,
            "%s: invalid scan_cancel_req_type: %d",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "get_serialization_cancel_type");
          v24 = 1;
        }
        else
        {
          v24 = dword_B358F8[v10 - 1];
        }
        HIDWORD(v60) = v24;
        v25 = wlan_serialization_cancel_request((unsigned int *)&v59, a2, a3, a4, a5, a6, a7, a8, a9);
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: status: %d, reqid: %d, scanid: %d, vdevid: %d, type: %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "scm_scan_cancel_req",
          v25,
          *(unsigned int *)(v9 + 12),
          *(unsigned int *)(v9 + 16),
          *(unsigned int *)(v9 + 24),
          *(_DWORD *)(v9 + 20),
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63);
        if ( v25 - 1 >= 2 )
        {
          v42 = 0;
          if ( v25 && v25 != 4 )
            v42 = 4;
          goto LABEL_22;
        }
      }
      v42 = tgt_scan_cancel(v9);
LABEL_22:
      v52 = v42;
      wlan_objmgr_vdev_release_ref(*(_QWORD *)v9, 0xCu, *(unsigned int **)v9, v34, v35, v36, v37, v38, v39, v40, v41);
      _qdf_mem_free(v9);
      result = v52;
      goto LABEL_23;
    }
    v20 = "%s: Bodyptr is NULL";
  }
  else
  {
    v20 = "%s: msg received is NULL";
  }
  qdf_trace_msg(0x15u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "scm_scan_cancel_req");
  result = 29;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
