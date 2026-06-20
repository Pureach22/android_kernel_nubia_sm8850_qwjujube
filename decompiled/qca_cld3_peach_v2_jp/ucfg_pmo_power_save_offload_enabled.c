__int64 __fastcall ucfg_pmo_power_save_offload_enabled(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( *(_BYTE *)(comp_private_obj + 24) )
    v10 = *(_DWORD *)(comp_private_obj + 44) != 0;
  else
    v10 = *(_DWORD *)(comp_private_obj + 44);
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: powersave offload enabled type:%d",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "ucfg_pmo_power_save_offload_enabled",
    (unsigned __int8)v10);
  return v10;
}
