__int64 __fastcall wlan_cfr_psoc_obj_create_handler(__int64 a1)
{
  _QWORD *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19

  v2 = (_QWORD *)_qdf_mem_malloc(0x10u, "wlan_cfr_psoc_obj_create_handler", 167);
  if ( v2 )
  {
    *v2 = a1;
    wlan_objmgr_psoc_component_obj_attach(a1, 0x1Eu, (__int64)v2, 0);
    return 0;
  }
  else
  {
    v11 = 2;
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to allocate cfr_ctx object\n",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_cfr_psoc_obj_create_handler");
  }
  return v11;
}
