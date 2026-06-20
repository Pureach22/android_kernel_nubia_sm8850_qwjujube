__int64 __fastcall reg_get_domain_from_country_code(
        _DWORD *a1,
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
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 result; // x0
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: Invalid reg domain pointer";
LABEL_6:
    qdf_trace_msg(0x51u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "reg_get_domain_from_country_code", v10, v11);
    return 5;
  }
  result = 0;
  *a1 = 0;
  if ( !a2 )
  {
    v14 = "%s: Country code is NULL";
    goto LABEL_6;
  }
  return result;
}
