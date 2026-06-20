__int64 __fastcall cfg_p2p_get_device_addr_admin(__int64 a1, _BYTE *a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    *a2 = *(_BYTE *)(v12 + 272) & 1;
    return 0;
  }
  else
  {
    *a2 = 0;
    qdf_trace_msg(0x4Eu, 2u, "%s: p2p psoc null", v4, v5, v6, v7, v8, v9, v10, v11, "cfg_p2p_get_device_addr_admin");
    return 4;
  }
}
