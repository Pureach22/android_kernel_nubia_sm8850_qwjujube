__int64 __fastcall coresight_disclaim_device(__int64 result)
{
  __int64 v1; // x19
  _DWORD *v2; // x8
  __int64 v3; // x8
  _DWORD *v4; // x8

  if ( !result )
  {
    __break(0x800u);
    return result;
  }
  v1 = result;
  writel_relaxed(3316436565LL, *(_QWORD *)(result + 40) + 4016LL);
  __dsb(0xFu);
  v2 = *(_DWORD **)(v1 + 40);
  if ( *(_BYTE *)(v1 + 32) == 1 )
  {
    if ( (unsigned int)readl_relaxed(v2 + 1001) == 2 )
    {
LABEL_4:
      if ( *(_BYTE *)(v1 + 32) == 1 )
      {
        writel_relaxed(2, *(_QWORD *)(v1 + 40) + 4004LL);
        __isb(0xFu);
      }
      else
      {
        v4 = *(_DWORD **)(v1 + 48);
        if ( *(v4 - 1) != -166272269 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v4)(2, 4004, 1, 0);
        __isb(0xFu);
      }
      goto LABEL_11;
    }
  }
  else
  {
    if ( *(v2 - 1) != -340433967 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v2)(4004, 1, 0) == 2 )
      goto LABEL_4;
  }
  __break(0x800u);
LABEL_11:
  v3 = *(_QWORD *)(v1 + 40);
  __dsb(0xFu);
  return writel_relaxed(0, v3 + 4016);
}
