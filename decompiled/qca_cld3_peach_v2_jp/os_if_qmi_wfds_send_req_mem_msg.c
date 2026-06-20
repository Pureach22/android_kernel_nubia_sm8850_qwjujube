__int64 __fastcall os_if_qmi_wfds_send_req_mem_msg(unsigned int *a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned int v6; // w20
  __int64 v7; // x9
  _DWORD *v8; // x12
  unsigned int *v9; // x13
  __int64 v10; // x15
  __int64 v11; // x14
  unsigned int v12; // w15
  __int64 v13; // x15
  __int64 v14; // x21
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
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
  v2 = _qdf_mem_malloc(0x4008u, "os_if_qmi_wfds_send_req_mem_msg", 221);
  if ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = _qdf_mem_malloc(4u, "os_if_qmi_wfds_send_req_mem_msg", 225);
    if ( !v4 )
    {
      v6 = 2;
LABEL_23:
      _qdf_mem_free((__int64)v3);
      goto LABEL_24;
    }
    v5 = *a1;
    if ( (unsigned int)v5 > 8 )
      goto LABEL_4;
    *v3 = v5;
    if ( (_DWORD)v5 )
    {
      v7 = 0;
      v8 = v3 + 4;
      v9 = a1 + 4;
      while ( 1 )
      {
        v10 = (__int64)&a1[512 * v7 + 2];
        v11 = (__int64)&v3[512 * v7 + 2];
        *(_WORD *)v11 = *(_WORD *)v10;
        v12 = *(_DWORD *)(v10 + 4);
        *(_DWORD *)(v11 + 4) = v12;
        if ( v12 > 0xFF )
          break;
        if ( v12 )
        {
          v13 = 0;
          do
          {
            if ( v13 == 255 )
              __break(0x5512u);
            *(_QWORD *)&v8[2 * v13] = *(_QWORD *)&v9[2 * v13];
            ++v13;
          }
          while ( *(_DWORD *)(v11 + 4) > (unsigned int)v13 );
        }
        ++v7;
        v8 += 512;
        v9 += 512;
        if ( v7 == v5 )
          goto LABEL_16;
      }
LABEL_4:
      v6 = 4;
LABEL_22:
      _qdf_mem_free(v4);
      goto LABEL_23;
    }
LABEL_16:
    v14 = v4;
    v15 = os_if_qmi_txn_init();
    if ( v15 )
    {
      v6 = v15;
      v24 = "%s: QMI txn init failed for WFDS mem req message %d";
    }
    else
    {
      v25 = os_if_qmi_send_request((__int64)&qmi_wfds, 0, (__int64)&v35, 2, 0x3FDCu);
      if ( v25 )
      {
        v6 = v25;
        qdf_trace_msg(
          0x48u,
          4u,
          "%s: QMI WFDS mem request send failed %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "os_if_qmi_wfds_send_req_mem_msg",
          v25,
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
        os_if_qmi_txn_cancel();
        goto LABEL_21;
      }
      v6 = os_if_qmi_txn_wait();
      if ( !v6 )
        goto LABEL_21;
      v24 = "%s: Wait for QMI WFDS mem response timed out %d";
    }
    qdf_trace_msg(
      0x48u,
      4u,
      v24,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "os_if_qmi_wfds_send_req_mem_msg",
      v6,
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
LABEL_21:
    v4 = v14;
    goto LABEL_22;
  }
  v6 = 2;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v6;
}
