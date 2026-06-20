__int64 __fastcall coresight_read32(__int64 a1, unsigned int a2)
{
  _DWORD *v2; // x8

  v2 = *(_DWORD **)(a1 + 40);
  if ( *(_BYTE *)(a1 + 32) == 1 )
    return readl((char *)v2 + a2);
  if ( *(v2 - 1) != -340433967 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))v2)(a2, 0, 0);
}
