__int64 __fastcall sde_crtc_state_find_plane_fb_modes(__int64 a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 *v6; // x8
  __int64 v7; // x10
  __int64 v8; // x9
  unsigned __int64 *v9; // x9
  __int64 v10; // t1
  unsigned __int64 v11; // x19
  int v12; // w4
  _DWORD *v13; // x9

  if ( a1 )
  {
    *a2 = 0;
    *a3 = 0;
    *a4 = 0;
    v4 = *(_QWORD *)(a1 + 328);
    v5 = *(_QWORD *)(v4 + 8);
    v6 = *(__int64 **)(v5 + 840);
    while ( 1 )
    {
      if ( v6 == (__int64 *)(v5 + 840) )
      {
        LODWORD(v11) = 0;
        return (unsigned int)v11;
      }
      v7 = *((unsigned int *)v6 + 437);
      if ( ((*(_DWORD *)(a1 + 12) >> v7) & 1) != 0 )
      {
        v8 = *(_QWORD *)(v4 + 24) + 32 * v7;
        v10 = *(_QWORD *)(v8 + 8);
        v9 = (unsigned __int64 *)(v8 + 8);
        if ( !v10 )
          v9 = (unsigned __int64 *)(v6 + 220);
        v11 = *v9;
        if ( *v9 )
        {
          if ( v11 >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_22DED9, "sde_crtc_state_find_plane_fb_modes");
            return (unsigned int)v11;
          }
          v12 = *(_DWORD *)(v11 + 1520);
          if ( v12 <= 1 )
          {
            v13 = a2;
            if ( v12 )
            {
              v13 = a3;
              if ( v12 != 1 )
              {
LABEL_17:
                printk(&unk_24FAF9, "sde_crtc_state_find_plane_fb_modes");
                goto LABEL_21;
              }
            }
            goto LABEL_3;
          }
          if ( v12 != 2 )
          {
            v13 = a4;
            if ( v12 != 3 )
              goto LABEL_17;
LABEL_3:
            ++*v13;
          }
        }
      }
      v4 = *(_QWORD *)(a1 + 328);
      v6 = (__int64 *)*v6;
      v5 = *(_QWORD *)(v4 + 8);
    }
  }
  printk(&unk_279EAB, "sde_crtc_state_find_plane_fb_modes");
LABEL_21:
  LODWORD(v11) = -22;
  return (unsigned int)v11;
}
