__int64 __fastcall reg_set_default_country(
        __int64 a1,
        const void *a2,
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
  __int64 v12; // x19
  const char *v14; // x2

  if ( a2 )
  {
    psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( psoc_obj )
    {
      v12 = psoc_obj;
      qdf_trace_msg(
        0x51u,
        4u,
        "%s: set default_country: %s",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "reg_set_default_country",
        a2);
      qdf_mem_copy((void *)(v12 + 91102), a2, 3u);
      return 0;
    }
    v14 = "%s: psoc reg component is NULL";
  }
  else
  {
    v14 = "%s: country is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "reg_set_default_country");
  return 4;
}
