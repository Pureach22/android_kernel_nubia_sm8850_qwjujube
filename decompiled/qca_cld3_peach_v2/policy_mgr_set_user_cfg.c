__int64 __fastcall policy_mgr_set_user_cfg(__int64 a1, _WORD *a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v23; // x2

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( a2 )
    {
      v12 = *(unsigned int *)(context + 2220);
      *(_WORD *)(context + 1672) = *a2;
      v13 = context;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: dbs_selection_plcy 0x%x",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "policy_mgr_set_user_cfg",
        v12);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev_priority_list 0x%x",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "policy_mgr_set_user_cfg",
        *(unsigned int *)(v13 + 2224));
      *(_BYTE *)(v13 + 2104) = *(_BYTE *)(v13 + 2201);
      return 0;
    }
    v23 = "%s: Invalid User Config";
  }
  else
  {
    v23 = "%s: Invalid context";
  }
  qdf_trace_msg(0x4Fu, 2u, v23, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_set_user_cfg");
  return 16;
}
