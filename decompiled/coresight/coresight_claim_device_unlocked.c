__int64 __fastcall coresight_claim_device_unlocked(__int64 a1)
{
  _DWORD *v1; // x8
  _DWORD *v3; // x8
  _DWORD *v5; // x8
  _DWORD *v6; // x8

  if ( !a1 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v1 = *(_DWORD **)(a1 + 40);
  if ( *(_BYTE *)(a1 + 32) == 1 )
  {
    if ( !(unsigned int)readl_relaxed(v1 + 1001) )
    {
LABEL_4:
      if ( *(_BYTE *)(a1 + 32) == 1 )
      {
        writel_relaxed(2, *(_QWORD *)(a1 + 40) + 4000LL);
      }
      else
      {
        v5 = *(_DWORD **)(a1 + 48);
        if ( *(v5 - 1) != -166272269 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v5)(2, 4000, 1, 0);
      }
      __isb(0xFu);
      v3 = *(_DWORD **)(a1 + 40);
      if ( *(_BYTE *)(a1 + 32) == 1 )
      {
        if ( (unsigned int)readl_relaxed(v3 + 1001) == 2 )
          return 0;
      }
      else
      {
        if ( *(v3 - 1) != -340433967 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v3)(4004, 1, 0) == 2 )
          return 0;
      }
      if ( *(_BYTE *)(a1 + 32) == 1 )
      {
        writel_relaxed(2, *(_QWORD *)(a1 + 40) + 4004LL);
      }
      else
      {
        v6 = *(_DWORD **)(a1 + 48);
        if ( *(v6 - 1) != -166272269 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v6)(2, 4004, 1, 0);
      }
      __isb(0xFu);
    }
  }
  else
  {
    if ( *(v1 - 1) != -340433967 )
      __break(0x8228u);
    if ( !((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v1)(4004, 1, 0) )
      goto LABEL_4;
  }
  return 4294967280LL;
}
