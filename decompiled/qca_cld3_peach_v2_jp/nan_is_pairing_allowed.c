__int64 __fastcall nan_is_pairing_allowed(
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
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
      return *(unsigned __int8 *)(comp_private_obj + 228)
           & ((unsigned __int16)(*(_WORD *)(comp_private_obj + 232) & 0x100) >> 8);
    v11 = "%s: psoc_nan_obj is NULL";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  qdf_trace_msg(0x53u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "nan_is_pairing_allowed");
  return 0;
}
