__int64 __fastcall pmo_tgt_update_target_suspend_acked_flag(__int64 a1, unsigned int a2)
{
  _DWORD *v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v4 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 376);
  if ( !v4 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: update_target_suspend_acked_flag is null",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "pmo_tgt_update_target_suspend_acked_flag");
  if ( *(v4 - 1) != -1344763252 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v4)(a1, a2);
}
