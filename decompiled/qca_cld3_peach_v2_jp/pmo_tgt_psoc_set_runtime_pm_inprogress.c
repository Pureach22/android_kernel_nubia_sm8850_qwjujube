__int64 __fastcall pmo_tgt_psoc_set_runtime_pm_inprogress(__int64 a1, char a2)
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

  v4 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 408);
  if ( v4 )
  {
    if ( *(v4 - 1) != -1344763252 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v4)(a1, a2 & 1);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: pmo ops is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pmo_tgt_psoc_set_runtime_pm_inprogress");
    return 29;
  }
}
