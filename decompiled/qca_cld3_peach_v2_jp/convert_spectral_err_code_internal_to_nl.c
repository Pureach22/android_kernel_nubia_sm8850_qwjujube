__int64 __fastcall convert_spectral_err_code_internal_to_nl(
        int a1,
        _DWORD *a2,
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

  if ( a1 > 2 )
  {
    if ( a1 != 3 )
    {
      if ( a1 == 4 )
      {
        *a2 = 3;
        return 0;
      }
      goto LABEL_8;
    }
    *a2 = 2;
    return 0;
  }
  else
  {
    if ( a1 != 1 )
    {
      if ( a1 == 2 )
      {
        *a2 = 1;
        return 0;
      }
LABEL_8:
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid spectral error code %u",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "convert_spectral_err_code_internal_to_nl",
        v10,
        v11);
      return 16;
    }
    *a2 = 0;
    return 0;
  }
}
