__int64 __fastcall hdd_update_smps_antenna_mode(__int64 a1, int a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v3 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 1452) = a2;
  sme_update_user_configured_nss(v3);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Successfully switched to mode: %d x %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_update_smps_antenna_mode",
    *(unsigned int *)(a1 + 1452),
    *(unsigned int *)(a1 + 1452));
  return 0;
}
