__int64 __fastcall reg_read_default_country(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  const char *v13; // x2

  if ( a2 )
  {
    psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( psoc_obj )
    {
      qdf_mem_copy(a2, (const void *)(psoc_obj + 91102), 3u);
      return 0;
    }
    v13 = "%s: psoc reg component is NULL";
  }
  else
  {
    v13 = "%s: country_code is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "reg_read_default_country");
  return 4;
}
