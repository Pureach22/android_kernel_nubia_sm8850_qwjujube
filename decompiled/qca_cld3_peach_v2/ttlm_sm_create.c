__int64 __fastcall ttlm_sm_create(__int64 a1)
{
  int v2; // w3
  int v3; // w4
  int v4; // w5
  int v5; // w6
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  _QWORD v25[9]; // [xsp+8h] [xbp-48h] BYREF

  v25[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 104);
  v3 = *(unsigned __int8 *)(a1 + 105);
  v4 = *(unsigned __int8 *)(a1 + 106);
  v5 = *(unsigned __int8 *)(a1 + 109);
  memset(v25, 0, 64);
  v6 = scnprintf(v25, 64, "TTLM-Peer MLD:%02x:%02x:%02x:**:**:%02x", v2, v3, v4, v5);
  v14 = wlan_sm_create(
          (__int64)v25,
          a1,
          0,
          (__int64)&ttlm_sm_info,
          0xBu,
          (__int64)ttlm_sm_event_names,
          15,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13);
  if ( v14 )
  {
    *(_QWORD *)(a1 + 720) = v14;
    qdf_mutex_create(a1 + 656);
    qdf_mc_timer_init(a1 + 736, 0, (__int64)ttlm_req_timeout_cb, a1);
    v23 = 0;
  }
  else
  {
    v23 = 2;
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: TTLM state machine creation failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ttlm_sm_create");
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
