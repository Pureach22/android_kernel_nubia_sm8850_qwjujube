__int64 __fastcall init_deinit_mlo_tsf_sync_support(__int64 a1, __int64 a2)
{
  char v3; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v3 = wmi_service_enabled(a1, 296);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: mlo_tsf_sync_enab %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "init_deinit_mlo_tsf_sync_support",
    v3 & 1);
  return mlo_update_tsf_sync_support(a2, v3 & 1);
}
