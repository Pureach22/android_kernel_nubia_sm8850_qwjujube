__int64 __fastcall cm_sm_create(_QWORD *a1)
{
  int v2; // w3
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 v21; // x4
  _QWORD v23[9]; // [xsp+8h] [xbp-48h] BYREF

  v23[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(*a1 + 104LL);
  memset(v23, 0, 64);
  v3 = scnprintf(v23, 64, "CM-%d", v2);
  v11 = wlan_sm_create(
          (__int64)v23,
          (__int64)a1,
          0,
          (__int64)&cm_sm_info,
          0x10u,
          (__int64)cm_sm_event_names,
          39,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10);
  if ( v11 )
  {
    a1[9] = v11;
    qdf_mutex_create((__int64)(a1 + 1));
    v20 = 0;
  }
  else
  {
    v21 = *(unsigned __int8 *)(*a1 + 104LL);
    v20 = 2;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d CM State Machine allocation failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "cm_sm_create",
      v21);
  }
  _ReadStatusReg(SP_EL0);
  return v20;
}
