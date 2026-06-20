__int64 __fastcall tdls_reset_nss(
        __int64 result,
        char a2,
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
  int v12; // w8
  int v13; // w8
  __int64 v14; // x19
  char v15; // w8

  if ( result )
  {
    if ( a2 == 3 && *(_BYTE *)(result + 214) == 1 )
    {
      v12 = *(_DWORD *)(result + 220);
      if ( !v12 || (v13 = v12 - 1, (*(_DWORD *)(result + 220) = v13) == 0) )
      {
        v14 = result;
        if ( *(_DWORD *)(result + 216) == 2 )
        {
          result = qdf_trace_msg(
                     0,
                     4u,
                     "%s: TDLS NSS switch is fully completed",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "tdls_reset_nss",
                     v10,
                     v11);
          v15 = 0;
          *(_BYTE *)(v14 + 214) = 0;
        }
        else
        {
          result = qdf_trace_msg(
                     0,
                     4u,
                     "%s: teardown done & NSS switch in progress",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "tdls_reset_nss",
                     v10,
                     v11);
          v15 = 1;
        }
        *(_BYTE *)(v14 + 215) = v15;
        *(_DWORD *)(v14 + 216) = 0;
      }
    }
  }
  return result;
}
