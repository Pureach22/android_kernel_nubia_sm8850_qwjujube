void __fastcall sde_vbif_set_xin_halt(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v4; // w8
  unsigned int v5; // w8

  if ( a1 && a2 )
  {
    v2 = *(_QWORD *)(a1 + 152);
    if ( (*(_QWORD *)(v2 + 22008) & 0x100000000LL) != 0 && v2 )
    {
      mutex_lock(a1 + 3696);
      if ( (*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x400000000LL) != 0
        && *(_DWORD *)(a1 + 3664) == 1
        && (v4 = *(_DWORD *)(a1 + 3656), v4 <= 6)
        && ((1 << v4) & 0x64) != 0
        || (v5 = *(_DWORD *)(a1 + 3656), v5 <= 4) && ((1 << v5) & 0x1A) != 0 )
      {
        mutex_unlock(a1 + 3696);
        if ( (_drm_debug & 4) == 0 )
          JUMPOUT(0x13DA00);
        JUMPOUT(0x13DA08);
      }
      JUMPOUT(0x13DA28);
    }
    JUMPOUT(0x13DA30);
  }
  JUMPOUT(0x13DB04);
}
