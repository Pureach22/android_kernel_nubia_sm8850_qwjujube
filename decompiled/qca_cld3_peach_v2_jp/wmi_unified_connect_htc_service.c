__int64 __fastcall wmi_unified_connect_htc_service(__int64 a1, __int64 a2)
{
  unsigned __int8 wmi_endpoint_count; // w0
  __int64 result; // x0
  unsigned __int8 v6; // w25
  __int64 v7; // x26
  _DWORD *v8; // x8
  __int64 *v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  __int16 v19; // w9
  __int64 v20; // x8
  __int64 v21; // x26
  __int64 v22; // x8
  __int64 *v23; // x0
  __int64 v24; // x25
  __int64 v25; // x8
  __int64 *v26; // x0
  __int64 v27; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v28; // [xsp+10h] [xbp-A0h]
  __int64 v29; // [xsp+18h] [xbp-98h]
  __int64 v30; // [xsp+20h] [xbp-90h]
  void *v31; // [xsp+28h] [xbp-88h]
  __int64 (__fastcall *v32)(); // [xsp+30h] [xbp-80h]
  __int64 v33; // [xsp+38h] [xbp-78h]
  __int64 v34; // [xsp+40h] [xbp-70h]
  __int64 v35; // [xsp+48h] [xbp-68h]
  __int64 v36; // [xsp+50h] [xbp-60h]
  __int64 v37; // [xsp+58h] [xbp-58h]
  __int64 v38; // [xsp+60h] [xbp-50h]
  __int64 v39; // [xsp+68h] [xbp-48h]
  __int64 v40; // [xsp+70h] [xbp-40h]
  __int64 (__fastcall *v41)(); // [xsp+78h] [xbp-38h]
  __int64 v42; // [xsp+80h] [xbp-30h]
  __int64 v43; // [xsp+88h] [xbp-28h]
  __int64 v44; // [xsp+90h] [xbp-20h] BYREF
  __int64 v45; // [xsp+98h] [xbp-18h]
  __int64 v46; // [xsp+A0h] [xbp-10h]
  __int64 v47; // [xsp+A8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(*(_QWORD *)(a1 + 760) + 32LL) = a2;
  wmi_endpoint_count = htc_get_wmi_endpoint_count(a2);
  if ( wmi_endpoint_count > 3u )
  {
    result = 5;
    goto LABEL_11;
  }
  if ( !wmi_endpoint_count )
    goto LABEL_10;
  v6 = wmi_endpoint_count;
  v7 = *(_QWORD *)(a1 + 760);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = nullptr;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = 0;
  v30 = 0;
  v31 = nullptr;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  qdf_mem_set(&v27, 0x88u, 0);
  qdf_mem_set(&v44, 0x18u, 0);
  v8 = *(_DWORD **)(v7 + 5240);
  v28 = 0;
  LOBYTE(v29) = 0;
  v32 = wmi_control_rx;
  v33 = 0;
  v37 = 0;
  v34 = 0;
  v30 = v7;
  v31 = &wmi_htc_tx_complete;
  v41 = wmi_htc_log_pkt;
  v9 = *(__int64 **)(v7 + 32);
  LOWORD(v27) = *v8;
  result = htc_connect_service(v9, (unsigned __int16 *)&v27, (__int64)&v44);
  if ( (_DWORD)result )
    goto LABEL_5;
  if ( *(_BYTE *)(v7 + 24) == 1 )
    ((void (__fastcall *)(_QWORD, _QWORD, __int64))htc_set_async_ep)(*(_QWORD *)(v7 + 32), HIDWORD(v45), 1);
  v19 = v46;
  *(_DWORD *)(v7 + 5208) = HIDWORD(v45);
  *(_WORD *)(v7 + 5220) = v19;
  if ( v6 == 1 )
  {
LABEL_10:
    v20 = *(_QWORD *)(a1 + 760);
    *(_QWORD *)(a1 + 64) = a2;
    result = 0;
    *(_DWORD *)(a1 + 28) = *(_DWORD *)(v20 + 5208);
    *(_WORD *)(a1 + 32) = *(_WORD *)(v20 + 5220);
    goto LABEL_11;
  }
  v21 = *(_QWORD *)(a1 + 760);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = nullptr;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = 0;
  v30 = 0;
  v31 = nullptr;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  qdf_mem_set(&v27, 0x88u, 0);
  qdf_mem_set(&v44, 0x18u, 0);
  v22 = *(_QWORD *)(v21 + 5240);
  v28 = 0;
  LOBYTE(v29) = 0;
  v37 = 0;
  v31 = &wmi_htc_tx_complete;
  v32 = wmi_control_rx;
  v33 = 0;
  v34 = 0;
  v30 = v21;
  v41 = wmi_htc_log_pkt;
  v23 = *(__int64 **)(v21 + 32);
  LOWORD(v27) = *(_DWORD *)(v22 + 4);
  result = htc_connect_service(v23, (unsigned __int16 *)&v27, (__int64)&v44);
  if ( !(_DWORD)result )
  {
    if ( *(_BYTE *)(v21 + 24) == 1 )
      ((void (__fastcall *)(_QWORD, _QWORD, __int64))htc_set_async_ep)(*(_QWORD *)(v21 + 32), HIDWORD(v45), 1);
    *(_DWORD *)(v21 + 5212) = HIDWORD(v45);
    *(_WORD *)(v21 + 5222) = v46;
    if ( v6 == 2 )
      goto LABEL_10;
    v24 = *(_QWORD *)(a1 + 760);
    v45 = 0;
    v46 = 0;
    v44 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = nullptr;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = nullptr;
    v33 = 0;
    v30 = 0;
    v31 = nullptr;
    v28 = 0;
    v29 = 0;
    v27 = 0;
    qdf_mem_set(&v27, 0x88u, 0);
    qdf_mem_set(&v44, 0x18u, 0);
    v25 = *(_QWORD *)(v24 + 5240);
    v28 = 0;
    LOBYTE(v29) = 0;
    v37 = 0;
    v31 = &wmi_htc_tx_complete;
    v32 = wmi_control_rx;
    v33 = 0;
    v34 = 0;
    v30 = v24;
    v41 = wmi_htc_log_pkt;
    v26 = *(__int64 **)(v24 + 32);
    LOWORD(v27) = *(_DWORD *)(v25 + 8);
    result = htc_connect_service(v26, (unsigned __int16 *)&v27, (__int64)&v44);
    if ( !(_DWORD)result )
    {
      if ( *(_BYTE *)(v24 + 24) == 1 )
        ((void (__fastcall *)(_QWORD, _QWORD, __int64))htc_set_async_ep)(*(_QWORD *)(v24 + 32), HIDWORD(v45), 1);
      *(_DWORD *)(v24 + 5216) = HIDWORD(v45);
      *(_WORD *)(v24 + 5224) = v46;
      goto LABEL_10;
    }
  }
LABEL_5:
  if ( (unsigned int)(unsigned __int16)v27 - 263 <= 0xFFFFFFFD )
  {
    v18 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to connect to WMI CONTROL service status:%d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wmi_connect_pdev_htc_service",
      (unsigned int)result);
    result = v18;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
