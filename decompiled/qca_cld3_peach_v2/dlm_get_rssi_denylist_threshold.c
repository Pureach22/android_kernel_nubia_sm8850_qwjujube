__int64 __fastcall dlm_get_rssi_denylist_threshold(__int64 a1)
{
  __int64 pdev_obj; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  pdev_obj = dlm_get_pdev_obj(a1);
  v3 = *(_QWORD *)(a1 + 80);
  v4 = pdev_obj;
  psoc_obj = dlm_get_psoc_obj(v3);
  if ( v4 && psoc_obj )
    return *(unsigned int *)(psoc_obj + 44);
  qdf_trace_msg(
    0x6Du,
    2u,
    "%s: dlm_ctx or dlm_psoc_obj is NULL",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "dlm_get_rssi_denylist_threshold");
  return 0;
}
