__int64 __fastcall os_if_qmi_wfds_send_ut_cmd_req_msg(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  const char *v24; // x2
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // [xsp+0h] [xbp-50h] BYREF
  __int64 v36; // [xsp+8h] [xbp-48h]
  __int64 v37; // [xsp+10h] [xbp-40h]
  __int64 v38; // [xsp+18h] [xbp-38h]
  __int64 v39; // [xsp+20h] [xbp-30h]
  __int64 v40; // [xsp+28h] [xbp-28h]
  __int64 v41; // [xsp+30h] [xbp-20h]
  __int64 v42; // [xsp+38h] [xbp-18h]
  __int64 v43; // [xsp+40h] [xbp-10h]
  __int64 v44; // [xsp+48h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  v2 = _qdf_mem_malloc(0x148u, "os_if_qmi_wfds_send_ut_cmd_req_msg", 520);
  if ( v2 )
  {
    v3 = v2;
    v4 = _qdf_mem_malloc(4u, "os_if_qmi_wfds_send_ut_cmd_req_msg", 524);
    if ( !v4 )
    {
      v23 = 2;
LABEL_13:
      _qdf_mem_free(v3);
      goto LABEL_14;
    }
    v13 = v4;
    *(_DWORD *)v3 = *(_DWORD *)a1;
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(v3 + 12) = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(v3 + 16) = *(_DWORD *)(a1 + 16);
    *(_WORD *)(v3 + 20) = *(_WORD *)(a1 + 20);
    *(_BYTE *)(v3 + 22) = *(_BYTE *)(a1 + 28);
    *(_BYTE *)(v3 + 28) = *(_BYTE *)(a1 + 22);
    *(_BYTE *)(v3 + 23) = *(_BYTE *)(a1 + 29);
    *(_BYTE *)(v3 + 29) = *(_BYTE *)(a1 + 23);
    *(_BYTE *)(v3 + 24) = *(_BYTE *)(a1 + 30);
    *(_BYTE *)(v3 + 30) = *(_BYTE *)(a1 + 24);
    *(_BYTE *)(v3 + 25) = *(_BYTE *)(a1 + 31);
    *(_BYTE *)(v3 + 31) = *(_BYTE *)(a1 + 25);
    *(_BYTE *)(v3 + 26) = *(_BYTE *)(a1 + 32);
    *(_BYTE *)(v3 + 32) = *(_BYTE *)(a1 + 26);
    *(_BYTE *)(v3 + 27) = *(_BYTE *)(a1 + 33);
    *(_BYTE *)(v3 + 33) = *(_BYTE *)(a1 + 27);
    if ( *(_DWORD *)a1 == 3 )
    {
      *(_BYTE *)(v3 + 35) = *(_BYTE *)(a1 + 38);
      *(_BYTE *)(v3 + 51) = *(_BYTE *)(a1 + 34);
      *(_BYTE *)(v3 + 36) = *(_BYTE *)(a1 + 39);
      *(_BYTE *)(v3 + 52) = *(_BYTE *)(a1 + 35);
      *(_BYTE *)(v3 + 37) = *(_BYTE *)(a1 + 40);
      *(_BYTE *)(v3 + 53) = *(_BYTE *)(a1 + 36);
      *(_BYTE *)(v3 + 38) = *(_BYTE *)(a1 + 41);
      *(_BYTE *)(v3 + 54) = *(_BYTE *)(a1 + 37);
      *(_WORD *)(v3 + 68) = *(_WORD *)(a1 + 42);
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: cmd: %u for duration: %u s, flush period: %u ms",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "os_if_qmi_wfds_send_ut_cmd_req_msg",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44);
    v14 = os_if_qmi_txn_init();
    if ( v14 )
    {
      v23 = v14;
      v24 = "%s: QMI txn for WFDS unit test cmd init failed %d";
    }
    else
    {
      v25 = os_if_qmi_send_request((__int64)&qmi_wfds, 0, (__int64)&v35, 5, 0x16Cu);
      if ( v25 )
      {
        v23 = v25;
        qdf_trace_msg(
          0x48u,
          4u,
          "%s: QMI WFDS UT command request send failed %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "os_if_qmi_wfds_send_ut_cmd_req_msg",
          v25);
        os_if_qmi_txn_cancel();
        goto LABEL_12;
      }
      v23 = os_if_qmi_txn_wait();
      if ( !v23 )
        goto LABEL_12;
      v24 = "%s: Wait for unit test cmd response timed out %d";
    }
    qdf_trace_msg(0x48u, 4u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "os_if_qmi_wfds_send_ut_cmd_req_msg", v23);
LABEL_12:
    _qdf_mem_free(v13);
    goto LABEL_13;
  }
  v23 = 2;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v23;
}
