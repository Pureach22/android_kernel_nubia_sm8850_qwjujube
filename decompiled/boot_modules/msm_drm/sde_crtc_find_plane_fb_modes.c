__int64 __fastcall sde_crtc_find_plane_fb_modes(_QWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v4; // x9
  __int64 *i; // x8
  unsigned __int64 v6; // x19
  unsigned __int64 v7; // x9
  int v8; // w4
  _DWORD *v9; // x9

  if ( a1 )
  {
    *a2 = 0;
    *a3 = 0;
    *a4 = 0;
    v4 = *a1;
    for ( i = *(__int64 **)(*a1 + 840LL); ; i = (__int64 *)*i )
    {
      if ( i == (__int64 *)(v4 + 840) )
      {
        LODWORD(v6) = 0;
        return (unsigned int)v6;
      }
      if ( ((*(_DWORD *)(a1[251] + 12LL) >> *((_DWORD *)i + 437)) & 1) != 0 )
      {
        v6 = (unsigned __int64)(i - 1);
        if ( i == (__int64 *)&unk_8 || v6 > 0xFFFFFFFFFFFFF000LL || (v7 = i[220]) == 0 || v7 >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_22DED9, "sde_crtc_find_plane_fb_modes");
          return (unsigned int)v6;
        }
        v8 = *(_DWORD *)(v7 + 1520);
        if ( v8 <= 1 )
        {
          v9 = a2;
          if ( v8 )
          {
            v9 = a3;
            if ( v8 != 1 )
            {
LABEL_17:
              printk(&unk_24FAF9, "sde_crtc_find_plane_fb_modes");
              goto LABEL_21;
            }
          }
          goto LABEL_3;
        }
        if ( v8 != 2 )
        {
          v9 = a4;
          if ( v8 != 3 )
            goto LABEL_17;
LABEL_3:
          ++*v9;
        }
      }
      v4 = *a1;
    }
  }
  printk(&unk_279EAB, "sde_crtc_find_plane_fb_modes");
LABEL_21:
  LODWORD(v6) = -22;
  return (unsigned int)v6;
}
