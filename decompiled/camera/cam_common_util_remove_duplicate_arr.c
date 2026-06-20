__int64 __fastcall cam_common_util_remove_duplicate_arr(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  int i; // w9
  int v4; // w10

  if ( a1 )
  {
    v2 = 1;
    if ( a2 >= 2 )
    {
      for ( i = 1; i != a2; ++i )
      {
        if ( v2 )
        {
          v4 = 0;
          while ( *(_DWORD *)(a1 + 4LL * i) != *(_DWORD *)(a1 + 4LL * v4) )
          {
            if ( v2 == ++v4 )
              goto LABEL_4;
          }
        }
        else
        {
          v4 = 0;
        }
        if ( v4 == v2 )
LABEL_4:
          *(_DWORD *)(a1 + 4LL * v2++) = *(_DWORD *)(a1 + 4LL * i);
      }
    }
    return v2;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_util_remove_duplicate_arr",
      58,
      "Null input array");
    return 0;
  }
}
