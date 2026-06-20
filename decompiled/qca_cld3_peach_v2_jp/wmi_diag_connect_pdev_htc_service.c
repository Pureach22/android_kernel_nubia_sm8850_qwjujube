__int64 __fastcall wmi_diag_connect_pdev_htc_service(__int64 a1, __int64 *a2)
{
  __int64 v4; // x8
  unsigned int v5; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  _QWORD v16[17]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v17; // [xsp+90h] [xbp-20h] BYREF
  __int64 v18; // [xsp+98h] [xbp-18h]
  __int64 v19; // [xsp+A0h] [xbp-10h]
  __int64 v20; // [xsp+A8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 760);
  v16[4] = 0;
  v16[15] = 0;
  v16[2] = 0;
  v16[3] = v4;
  v16[14] = wmi_htc_log_pkt;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  v16[1] = 0;
  v16[5] = wmi_control_diag_rx;
  memset(&v16[6], 0, 64);
  v16[16] = 0;
  v16[0] = 263;
  v5 = htc_connect_service(a2, (unsigned __int16 *)v16, (__int64)&v17);
  if ( v5 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to connect to WMI DIAG service status:%d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wmi_diag_connect_pdev_htc_service",
      v5);
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 760);
    if ( *(_BYTE *)(v14 + 24) == 1 )
    {
      ((void (__fastcall *)(__int64 *, _QWORD, __int64))htc_set_async_ep)(a2, HIDWORD(v18), 1);
      v14 = *(_QWORD *)(a1 + 760);
    }
    *(_DWORD *)(v14 + 5248) = HIDWORD(v18);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
