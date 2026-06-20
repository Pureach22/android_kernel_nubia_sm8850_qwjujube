__int64 __fastcall init_deinit_service_available_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v12; // x8
  __int64 result; // x0
  const char *v14; // x2

  if ( a1 )
  {
    psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
    if ( psoc_from_scn_hdl )
    {
      v12 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
      if ( v12 )
      {
        result = wmi_save_ext_service_bitmap(*(_QWORD *)(v12 + 16), a2, 0);
        if ( !(_DWORD)result )
          return result;
        v14 = "%s: Failed to save ext service bitmap";
      }
      else
      {
        v14 = "%s: target_psoc_info is null";
      }
    }
    else
    {
      v14 = "%s: psoc is null";
    }
  }
  else
  {
    v14 = "%s: scn handle NULL";
  }
  qdf_trace_msg(0x49u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "init_deinit_service_available_handler");
  return 4294967274LL;
}
