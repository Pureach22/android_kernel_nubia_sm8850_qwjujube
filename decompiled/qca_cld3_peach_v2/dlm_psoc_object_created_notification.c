__int64 __fastcall dlm_psoc_object_created_notification(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  v2 = _qdf_mem_malloc(0x38u, "dlm_psoc_object_created_notification", 124);
  if ( !v2 )
    return 16;
  v3 = v2;
  result = wlan_objmgr_psoc_component_obj_attach(a1, 0x20u, v2, 0);
  if ( (_DWORD)result )
  {
    v13 = result;
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: Failed to attach psoc_ctx with psoc",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dlm_psoc_object_created_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  return result;
}
