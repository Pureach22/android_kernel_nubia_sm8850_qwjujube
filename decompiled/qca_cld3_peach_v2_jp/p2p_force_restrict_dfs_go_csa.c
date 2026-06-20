__int64 __fastcall p2p_force_restrict_dfs_go_csa(__int64 a1, char a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v15; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a1 + 16) != 3 )
    return 4;
  v15 = v3;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
    return 4;
  *(_BYTE *)(comp_private_obj + 960) = a2 & 1;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: P2P force restrict %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "p2p_force_restrict_dfs_go_csa",
    a2 & 1,
    v2,
    v15);
  return 0;
}
