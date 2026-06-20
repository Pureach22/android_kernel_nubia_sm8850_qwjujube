__int64 __fastcall pmo_is_apf_mode_enabled(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  char v10; // w8
  const char *v11; // x2

  if ( !a1 )
  {
    v11 = "%s: null psoc";
LABEL_6:
    qdf_trace_msg(0x4Du, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_is_apf_mode_enabled");
    v10 = 0;
    return v10 & 1;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
  {
    v11 = "%s: null psoc ctx";
    goto LABEL_6;
  }
  v10 = *(_BYTE *)(comp_private_obj + 124);
  return v10 & 1;
}
