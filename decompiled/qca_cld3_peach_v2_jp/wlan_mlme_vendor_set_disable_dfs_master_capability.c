__int64 __fastcall wlan_mlme_vendor_set_disable_dfs_master_capability(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w4

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v13 = psoc_ext_obj_fl;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: current dfs_master_capable %d set disable %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_mlme_vendor_set_disable_dfs_master_capability",
    *(unsigned __int8 *)(psoc_ext_obj_fl + 3168),
    a2 & 1);
  if ( (a2 & 1) != 0 )
    v22 = 0;
  else
    v22 = *(_BYTE *)(cfg_psoc_get_values(a1) + 4997);
  *(_BYTE *)(v13 + 3168) = v22;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: new dfs_master_capable %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_mlme_vendor_set_disable_dfs_master_capability");
  policy_mgr_dfs_master_cfg_changed(a1, *(_BYTE *)(v13 + 3168));
  return 0;
}
