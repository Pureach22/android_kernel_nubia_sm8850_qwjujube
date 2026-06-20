__int64 __fastcall reg_update_hal_cap_wireless_modes(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_obj; // x0
  const char *v15; // x2

  if ( !a1 )
  {
    v15 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x51u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "reg_update_hal_cap_wireless_modes");
    return 16;
  }
  psoc_obj = reg_get_psoc_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !psoc_obj )
  {
    v15 = "%s: psoc reg component is NULL";
    goto LABEL_7;
  }
  if ( a3 >= 3u )
  {
    __break(0x5512u);
    return reg_update_hal_reg_range_caps();
  }
  else
  {
    *(_QWORD *)(psoc_obj + 48LL * a3 + 93112) |= a2;
    return 0;
  }
}
