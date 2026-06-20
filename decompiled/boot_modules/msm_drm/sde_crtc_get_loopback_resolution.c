__int64 __fastcall sde_crtc_get_loopback_resolution(__int64 result, __int64 a2, _DWORD *a3, unsigned int *a4)
{
  int v4; // w10
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w10

  *a3 = 0;
  *a4 = 0;
  if ( *(_BYTE *)(result + 6921) == 1 )
  {
    v4 = *(_DWORD *)(result + 2048);
    if ( v4 )
    {
      if ( (*(_BYTE *)(result + 2060) & 1) != 0 )
      {
        v6 = *(_DWORD *)(result + 2064);
        v5 = *(_DWORD *)(result + 2068);
        if ( v4 == 1 )
        {
LABEL_46:
          *a3 = v6;
          *a4 = v5;
          return result;
        }
      }
      else
      {
        v5 = 0;
        v6 = 0;
        if ( v4 == 1 )
          goto LABEL_46;
      }
      if ( (*(_BYTE *)(result + 2652) & 1) != 0 )
      {
        v6 += *(_DWORD *)(result + 2656);
        if ( v5 <= *(_DWORD *)(result + 2660) )
          v5 = *(_DWORD *)(result + 2660);
      }
      if ( v4 == 2 )
        goto LABEL_46;
      if ( (*(_BYTE *)(result + 3244) & 1) != 0 )
      {
        v6 += *(_DWORD *)(result + 3248);
        if ( v5 <= *(_DWORD *)(result + 3252) )
          v5 = *(_DWORD *)(result + 3252);
      }
      if ( v4 == 3 )
        goto LABEL_46;
      if ( (*(_BYTE *)(result + 3836) & 1) != 0 )
      {
        v6 += *(_DWORD *)(result + 3840);
        if ( v5 <= *(_DWORD *)(result + 3844) )
          v5 = *(_DWORD *)(result + 3844);
      }
      if ( v4 == 4 || (*(_BYTE *)(result + 4428) & 1) == 0 && v4 == 5 )
        goto LABEL_46;
    }
    else
    {
      v7 = *(_DWORD *)(a2 + 2192);
      if ( !v7 )
      {
LABEL_45:
        v5 = 0;
        v6 = 0;
        goto LABEL_46;
      }
      if ( (unsigned int)(v7 - 9) > 0xFFFFFFF7 )
      {
        v6 = *(_DWORD *)(result + 6928);
        v5 = *(_DWORD *)(result + 6932);
        if ( v7 != 1 )
        {
          v6 += *(_DWORD *)(result + 6948);
          if ( v5 <= *(_DWORD *)(result + 6952) )
            v5 = *(_DWORD *)(result + 6952);
          if ( v7 != 2 )
          {
            v6 += *(_DWORD *)(result + 6968);
            if ( v5 <= *(_DWORD *)(result + 6972) )
              v5 = *(_DWORD *)(result + 6972);
            if ( v7 != 3 )
            {
              v6 += *(_DWORD *)(result + 6988);
              if ( v5 <= *(_DWORD *)(result + 6992) )
                v5 = *(_DWORD *)(result + 6992);
              if ( v7 != 4 )
              {
                v6 += *(_DWORD *)(result + 7008);
                if ( v5 <= *(_DWORD *)(result + 7012) )
                  v5 = *(_DWORD *)(result + 7012);
                if ( v7 != 5 )
                {
                  v6 += *(_DWORD *)(result + 7028);
                  if ( v5 <= *(_DWORD *)(result + 7032) )
                    v5 = *(_DWORD *)(result + 7032);
                  if ( v7 != 6 )
                  {
                    v6 += *(_DWORD *)(result + 7048);
                    if ( v5 <= *(_DWORD *)(result + 7052) )
                      v5 = *(_DWORD *)(result + 7052);
                    if ( v7 != 7 )
                    {
                      v6 += *(_DWORD *)(result + 7068);
                      if ( v5 <= *(_DWORD *)(result + 7072) )
                        v5 = *(_DWORD *)(result + 7072);
                    }
                  }
                }
              }
            }
          }
        }
        goto LABEL_46;
      }
    }
    __break(0x5512u);
    goto LABEL_45;
  }
  return result;
}
