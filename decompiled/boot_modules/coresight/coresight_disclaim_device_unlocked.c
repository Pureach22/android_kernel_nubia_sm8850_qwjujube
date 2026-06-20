__int64 __fastcall coresight_disclaim_device_unlocked(__int64 result)
{
  _DWORD *v1; // x8
  __int64 v2; // x19
  _DWORD *v3; // x8

  if ( !result )
    goto LABEL_10;
  v1 = *(_DWORD **)(result + 40);
  v2 = result;
  if ( *(_BYTE *)(result + 32) != 1 )
  {
    if ( *(v1 - 1) != -340433967 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v1)(4004, 1, 0);
    if ( (_DWORD)result == 2 )
      goto LABEL_4;
LABEL_10:
    __break(0x800u);
    return result;
  }
  result = readl_relaxed(v1 + 1001);
  if ( (_DWORD)result != 2 )
    goto LABEL_10;
LABEL_4:
  if ( *(_BYTE *)(v2 + 32) == 1 )
  {
    result = writel_relaxed(2, *(_QWORD *)(v2 + 40) + 4004LL);
    __isb(0xFu);
  }
  else
  {
    v3 = *(_DWORD **)(v2 + 48);
    if ( *(v3 - 1) != -166272269 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v3)(2, 4004, 1, 0);
    __isb(0xFu);
  }
  return result;
}
