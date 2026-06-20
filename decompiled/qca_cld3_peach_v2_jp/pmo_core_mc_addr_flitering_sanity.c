__int64 __fastcall pmo_core_mc_addr_flitering_sanity(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  if ( (*(_BYTE *)(*(_QWORD *)comp_private_obj + 12LL) & 1) != 0 )
  {
    v11 = comp_private_obj;
    if ( (pmo_core_is_vdev_supports_offload(a1, v3, v4, v5, v6, v7, v8, v9, v10) & 1) != 0 )
    {
      if ( *(unsigned __int8 *)(v11 + 673) < 0x21u )
        return 0;
      v20 = "%s: Passed more than max supported MC address count :%d";
    }
    else
    {
      v20 = "%s: vdev in invalid opmode for mc addr filtering %d";
    }
    qdf_trace_msg(0x4Du, 8u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "pmo_core_mc_addr_flitering_sanity");
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: user disabled mc_addr_list using INI",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pmo_core_mc_addr_flitering_sanity");
  }
  return 4;
}
