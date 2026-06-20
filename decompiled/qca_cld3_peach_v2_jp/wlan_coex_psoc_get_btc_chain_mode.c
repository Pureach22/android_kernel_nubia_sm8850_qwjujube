__int64 __fastcall wlan_coex_psoc_get_btc_chain_mode(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x8

  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x21u);
    if ( comp_private_obj )
    {
      v20 = (_DWORD *)comp_private_obj;
      *a2 = *v20;
      return 0;
    }
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: %s:%u, Failed to get coex psoc object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_coex_obj_fl",
      "wlan_coex_psoc_get_btc_chain_mode",
      198);
  }
  else
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: invalid param for getting btc chain mode",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_coex_psoc_get_btc_chain_mode");
  }
  return 4;
}
