__int64 __fastcall lim_update_he_6gop_assoc_resp(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  unsigned int v13; // w8

  if ( *(_BYTE *)(a3 + 8764) == 1 )
  {
    if ( (*(_BYTE *)(a2 + 3) & 0x20) != 0 )
    {
      v13 = *(_DWORD *)(a3 + 7176);
      if ( v13 )
      {
        if ( v13 >= (*(_BYTE *)(a2 + 13) & 3u) )
          v13 = *(_BYTE *)(a2 + 13) & 3;
        *(_DWORD *)(result + 852) = v13;
        if ( v13 == 3 )
        {
          v13 = *(_DWORD *)(a3 + 7176);
          *(_DWORD *)(result + 852) = v13;
        }
        *(_DWORD *)(result + 48) = v13;
      }
    }
    else
    {
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: 6G operation info not present in beacon",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_update_he_6gop_assoc_resp",
               v11,
               v12);
    }
  }
  return result;
}
