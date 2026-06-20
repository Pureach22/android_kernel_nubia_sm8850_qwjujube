const char *__fastcall nubia_get_rf_band_by_gpio(__int64 a1, unsigned int a2)
{
  const char *result; // x0
  __int64 v4; // x11

  result = "unknow";
  if ( a1 && a2 )
  {
    v4 = a2;
    for ( result = (const char *)(a1 + 8);
          *((_DWORD *)result - 2) != (unsigned __int8)nubia_rf_gpio1_v
       || *((_DWORD *)result - 1) != (unsigned __int8)nubia_rf_gpio2_v;
          result += 20 )
    {
      if ( !--v4 )
        return "unknow";
    }
  }
  return result;
}
