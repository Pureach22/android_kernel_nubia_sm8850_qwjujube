__int64 __fastcall ucfg_coex_register_cfg_updated_handler(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8

  if ( a2 )
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: invalid coex type: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_coex_register_cfg_updated_handler",
      a2);
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x21u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: %s:%u, Failed to get coex psoc object",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_psoc_get_coex_obj_fl",
      "ucfg_coex_register_cfg_updated_handler",
      40);
    return 4;
  }
  v22 = comp_private_obj;
  result = 0;
  *(_QWORD *)(v22 + 8) = a3;
  return result;
}
