__int64 __fastcall reg_get_country_max_allowed_bw(
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
  __int64 v9; // x0
  __int64 psoc_obj; // x0
  const char *v12; // x2

  v9 = *(_QWORD *)(a1 + 80);
  if ( v9 )
  {
    psoc_obj = reg_get_psoc_obj(v9, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( psoc_obj )
      return *(unsigned int *)(psoc_obj + 93972);
    v12 = "%s: psoc reg component is NULL";
  }
  else
  {
    v12 = "%s: psoc is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "reg_get_country_max_allowed_bw");
  return 0;
}
