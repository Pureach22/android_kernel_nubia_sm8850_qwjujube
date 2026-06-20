__int64 __fastcall reg_get_psoc_obj(
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
  if ( a1 )
    return wlan_objmgr_psoc_get_comp_private_obj(a1, 0xDu);
  qdf_trace_msg(0x51u, 1u, "%s: psoc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "reg_get_psoc_obj");
  return 0;
}
