__int64 __fastcall fwol_psoc_object_destroyed_notification(__int64 a1)
{
  __int64 psoc_obj; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
    return 2;
  v3 = psoc_obj;
  v4 = wlan_objmgr_psoc_component_obj_detach(a1, 0x1Du, psoc_obj);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to detach psoc_ctx from psoc",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "fwol_psoc_object_destroyed_notification");
    return v13;
  }
  else
  {
    _qdf_mem_free(v3);
    return 0;
  }
}
