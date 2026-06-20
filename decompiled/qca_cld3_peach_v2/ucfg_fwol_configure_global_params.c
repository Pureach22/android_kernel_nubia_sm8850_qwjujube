__int64 __fastcall ucfg_fwol_configure_global_params(__int64 a1, __int64 a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  __int64 v14; // x0
  const char *v15; // x3

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    result = fwol_set_ilp_config(a2, *(unsigned int *)(psoc_obj + 1308));
    if ( (_DWORD)result )
      return result;
    v14 = fwol_get_psoc_obj(a1);
    if ( v14 )
      return fwol_configure_hw_assist(a2, *(_BYTE *)(v14 + 1316));
    v15 = "ucfg_fwol_get_hw_assist_config";
  }
  else
  {
    v15 = "ucfg_fwol_get_ilp_config";
  }
  qdf_trace_msg(0x66u, 2u, "%s: Failed to get FWOL obj", v5, v6, v7, v8, v9, v10, v11, v12, v15);
  return 16;
}
