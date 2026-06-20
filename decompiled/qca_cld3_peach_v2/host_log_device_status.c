__int64 __fastcall host_log_device_status(__int16 a1)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 result; // x0
  __int16 v10; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v11; // [xsp+Eh] [xbp-12h] BYREF
  __int16 v12; // [xsp+16h] [xbp-Ah]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1;
  v12 = 0;
  v11 = 0;
  qdf_mem_set(&v11, 0xAu, 0);
  result = host_diag_event_report_payload(1664, 12, &v10, v1, v2, v3, v4, v5, v6, v7, v8);
  _ReadStatusReg(SP_EL0);
  return result;
}
