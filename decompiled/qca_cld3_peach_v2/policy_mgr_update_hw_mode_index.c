__int64 __fastcall policy_mgr_update_hw_mode_index(__int64 a1, unsigned int a2)
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

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_update_hw_mode_index");
  v12 = *(unsigned int *)(context + 1500);
  if ( (_DWORD)v12 == 0xFFFF )
    v12 = *(unsigned int *)(context + 1496);
  else
    *(_DWORD *)(context + 1496) = v12;
  *(_DWORD *)(context + 1500) = a2;
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: Updated: old_hw_mode_index:%d new_hw_mode_index:%d",
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "policy_mgr_update_hw_mode_index",
           v12,
           a2);
}
