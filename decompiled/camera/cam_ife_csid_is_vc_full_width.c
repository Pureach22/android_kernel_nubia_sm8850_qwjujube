__int64 __fastcall cam_ife_csid_is_vc_full_width(__int64 a1)
{
  unsigned int v1; // w6
  int v2; // w7

  if ( *(_DWORD *)(a1 + 48) )
  {
    v1 = *(_DWORD *)(a1 + 52);
    if ( v1 > 4 )
    {
      v2 = 0;
LABEL_61:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_is_vc_full_width",
        449,
        "Invalid num_vc_dt:%d cid: %d",
        v1,
        v2);
      return 4294967274LL;
    }
    if ( v1 )
    {
      if ( *(_BYTE *)(a1 + 8) == 1 && *(_DWORD *)a1 > 3u )
        return 1;
      if ( v1 != 1 )
      {
        if ( *(_BYTE *)(a1 + 20) == 1 && *(_DWORD *)(a1 + 12) > 3u )
          return 1;
        if ( v1 != 2 )
        {
          if ( *(_BYTE *)(a1 + 32) == 1 && *(_DWORD *)(a1 + 24) > 3u )
            return 1;
          if ( v1 != 3 && *(_BYTE *)(a1 + 44) == 1 && *(_DWORD *)(a1 + 36) > 3u )
            return 1;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 104) )
  {
    v1 = *(_DWORD *)(a1 + 108);
    if ( v1 > 4 )
    {
      v2 = 1;
      goto LABEL_61;
    }
    if ( v1 )
    {
      if ( *(_BYTE *)(a1 + 64) == 1 && *(_DWORD *)(a1 + 56) > 3u )
        return 1;
      if ( v1 != 1 )
      {
        if ( *(_BYTE *)(a1 + 76) == 1 && *(_DWORD *)(a1 + 68) > 3u )
          return 1;
        if ( v1 != 2 )
        {
          if ( *(_BYTE *)(a1 + 88) == 1 && *(_DWORD *)(a1 + 80) > 3u )
            return 1;
          if ( v1 != 3 && *(_BYTE *)(a1 + 100) == 1 && *(_DWORD *)(a1 + 92) > 3u )
            return 1;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 160) )
  {
    v1 = *(_DWORD *)(a1 + 164);
    if ( v1 > 4 )
    {
      v2 = 2;
      goto LABEL_61;
    }
    if ( v1 )
    {
      if ( *(_BYTE *)(a1 + 120) == 1 && *(_DWORD *)(a1 + 112) > 3u )
        return 1;
      if ( v1 != 1 )
      {
        if ( *(_BYTE *)(a1 + 132) == 1 && *(_DWORD *)(a1 + 124) > 3u )
          return 1;
        if ( v1 != 2 )
        {
          if ( *(_BYTE *)(a1 + 144) == 1 && *(_DWORD *)(a1 + 136) > 3u )
            return 1;
          if ( v1 != 3 && *(_BYTE *)(a1 + 156) == 1 && *(_DWORD *)(a1 + 148) > 3u )
            return 1;
        }
      }
    }
  }
  if ( !*(_DWORD *)(a1 + 216) )
    return 0;
  v1 = *(_DWORD *)(a1 + 220);
  if ( v1 > 4 )
  {
    v2 = 3;
    goto LABEL_61;
  }
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(a1 + 176) == 1 && *(_DWORD *)(a1 + 168) > 3u )
    return 1;
  if ( v1 == 1 )
    return 0;
  if ( *(_BYTE *)(a1 + 188) == 1 && *(_DWORD *)(a1 + 180) > 3u )
    return 1;
  if ( v1 == 2 )
    return 0;
  if ( *(_BYTE *)(a1 + 200) == 1 && *(_DWORD *)(a1 + 192) > 3u )
    return 1;
  return v1 != 3 && *(_BYTE *)(a1 + 212) == 1 && *(_DWORD *)(a1 + 204) > 3u;
}
