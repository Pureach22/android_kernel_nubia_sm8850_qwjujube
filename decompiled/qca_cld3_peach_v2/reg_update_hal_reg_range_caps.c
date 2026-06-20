__int64 __fastcall reg_update_hal_reg_range_caps(
        __int64 a1,
        int a2,
        int a3,
        int a4,
        int a5,
        unsigned __int8 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 psoc_obj; // x0
  _DWORD *v21; // x8
  const char *v22; // x2

  if ( !a1 )
  {
    v22 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x51u, 2u, v22, a7, a8, a9, a10, a11, a12, a13, a14, "reg_update_hal_reg_range_caps");
    return 16;
  }
  psoc_obj = reg_get_psoc_obj(a1, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !psoc_obj )
  {
    v22 = "%s: psoc reg component is NULL";
    goto LABEL_7;
  }
  if ( a6 >= 4u )
  {
    __break(0x5512u);
    if ( a6 <= 4u )
      JUMPOUT(0x220838);
    return reg_chan_in_range();
  }
  else
  {
    v21 = (_DWORD *)(psoc_obj + 48LL * a6 + 93088);
    v21[8] = a2;
    v21[9] = a3;
    v21[10] = a4;
    v21[11] = a5;
    return 0;
  }
}
