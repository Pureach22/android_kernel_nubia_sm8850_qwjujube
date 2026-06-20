__int64 __fastcall target_if_spectral_capabilities_event_handler(
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
  __int64 v11; // x8
  __int64 v12; // x8
  const char *v13; // x2
  const char *v14; // x2
  unsigned int v15; // w0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    if ( a2 )
    {
      psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
      if ( !psoc_from_scn_hdl )
      {
        v13 = "%s: psoc is null";
        goto LABEL_13;
      }
      v11 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
      if ( !v11 || (v12 = *(_QWORD *)(v11 + 16)) == 0 )
      {
        v13 = "%s: WMI handle is null";
        goto LABEL_13;
      }
      if ( (unsigned int)wmi_extract_spectral_caps_fixed_param(v12) )
      {
        v13 = "%s: Failed to extract fixed parameters";
LABEL_13:
        qdf_trace_msg(0x56u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_capabilities_event_handler");
        v15 = 16;
        goto LABEL_14;
      }
      v14 = "%s: Number of spectral_scan_bw_capabilities is less than one.";
    }
    else
    {
      v14 = "%s: WMI event buffer null";
    }
  }
  else
  {
    v14 = "%s: scn handle is null";
  }
  qdf_trace_msg(0x56u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_capabilities_event_handler");
  v15 = 4;
LABEL_14:
  result = qdf_status_to_os_return(v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
