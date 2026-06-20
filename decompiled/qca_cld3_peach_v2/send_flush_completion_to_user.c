__int64 send_flush_completion_to_user()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  __int64 result; // x0
  _BYTE v9[4]; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v10; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v12[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = 0;
  v9[0] = 0;
  cds_get_and_reset_log_completion((char *)&v11 + 4, &v11, &v10, v9);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Sending flush done to userspace reason code %d",
    v0,
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    "send_flush_completion_to_user",
    v10);
  v12[0] = HIDWORD(v11);
  v12[1] = v11;
  v12[2] = v10;
  v12[3] = 3;
  result = host_diag_event_report_payload(2727, 16, v12);
  if ( v9[0] == 1 )
    result = _cds_trigger_recovery(33, "send_flush_completion_to_user", 817);
  _ReadStatusReg(SP_EL0);
  return result;
}
