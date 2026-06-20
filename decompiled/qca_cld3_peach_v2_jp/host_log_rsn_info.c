__int64 __fastcall host_log_rsn_info(const void *a1, const void *a2, const void *a3, const void *a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17[0] = 0;
  qdf_mem_copy((char *)&v16 + 4, a1, 4u);
  qdf_mem_copy(v17, a2, 4u);
  qdf_mem_copy(&v16, a3, 4u);
  qdf_mem_copy((char *)v17 + 4, a4, 4u);
  result = host_diag_event_report_payload(3163, 16, &v16, v7, v8, v9, v10, v11, v12, v13, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
