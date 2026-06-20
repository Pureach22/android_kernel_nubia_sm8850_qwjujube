__int64 __fastcall sde_crtc_get_displays_affected(__int64 a1, __int64 a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w10
  unsigned int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10

  if ( !a1 || !a2 )
  {
    printk(&unk_22700A, "_sde_crtc_get_displays_affected");
    return 0;
  }
  if ( *(_BYTE *)(a2 + 483) == 1 )
  {
    if ( *(_WORD *)(a2 + 560) && *(_WORD *)(a2 + 562) )
    {
      v2 = *(unsigned __int16 *)(a2 + 556);
      v3 = *(unsigned __int16 *)(a2 + 496) >> 1;
      if ( *(unsigned __int16 *)(a2 + 560) + v2 > v3 )
      {
        if ( v2 >= v3 )
          v4 = 2;
        else
          v4 = 3;
        goto LABEL_21;
      }
      goto LABEL_11;
    }
    goto LABEL_20;
  }
  if ( (*(_BYTE *)(a1 + 2196) & 1) != 0 )
  {
LABEL_11:
    v4 = 1;
    goto LABEL_21;
  }
  v5 = *(unsigned int *)(a1 + 2192);
  if ( !(_DWORD)v5 )
  {
LABEL_20:
    v4 = 0;
LABEL_21:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "affected displays 0x%x\n", v4);
    return v4;
  }
  if ( (unsigned int)(v5 - 10) >= 0xFFFFFFF7 )
  {
    v6 = 0;
    v4 = 0;
    v7 = a2 + 556;
    do
    {
      if ( v7 && *(_WORD *)(v7 + 4) && *(_WORD *)(v7 + 6) )
        v4 |= 1LL << v6;
      ++v6;
      v7 += 8;
    }
    while ( v5 != v6 );
    goto LABEL_21;
  }
  __break(0x5512u);
  return sde_crtc_reset_sw_state();
}
