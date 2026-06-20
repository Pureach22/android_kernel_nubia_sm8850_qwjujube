__int64 __fastcall ucfg_dcs_register_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !result )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs psoc private object is null",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "ucfg_dcs_register_cb");
  *(_QWORD *)(result + 1152) = a2;
  *(_QWORD *)(result + 1160) = a3;
  return result;
}
