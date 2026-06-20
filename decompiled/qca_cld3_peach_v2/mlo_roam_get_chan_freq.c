__int64 __fastcall mlo_roam_get_chan_freq(
        unsigned __int8 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned __int16 a8)
{
  unsigned __int16 *v8; // x30
  int v9; // w8

  if ( !a2 )
    return 0;
  v9 = *(unsigned __int8 *)(a2 + 2497);
  if ( !*(_BYTE *)(a2 + 2497) )
    return 0;
  if ( *(_DWORD *)(a2 + 2500) == a1 )
    return *(unsigned int *)(a2 + 2512);
  if ( v9 == 1 )
    return 0;
  if ( *(_DWORD *)(a2 + 2552) == a1 )
    return *(unsigned int *)(a2 + 2564);
  if ( v9 == 2 )
    return 0;
  if ( *(_DWORD *)(a2 + 2604) != a1 )
  {
    if ( v9 != 3 )
    {
      __break(0x5512u);
      __stxr(a8, v8);
      JUMPOUT(0x6D0378);
    }
    return 0;
  }
  return *(unsigned int *)(a2 + 2616);
}
