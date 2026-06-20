__int64 __fastcall coresight_write32(__int64 a1, unsigned int a2, unsigned int a3)
{
  _DWORD *v4; // x8

  if ( *(_BYTE *)(a1 + 32) == 1 )
    return writel(a2, *(_QWORD *)(a1 + 40) + a3);
  v4 = *(_DWORD **)(a1 + 48);
  if ( *(v4 - 1) != -166272269 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))v4)(a2, a3, 0, 0);
}
