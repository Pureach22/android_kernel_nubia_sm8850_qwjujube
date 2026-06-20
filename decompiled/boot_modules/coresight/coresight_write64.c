__int64 __fastcall coresight_write64(__int64 a1, __int64 a2, unsigned int a3)
{
  _DWORD *v4; // x8

  if ( *(_BYTE *)(a1 + 32) == 1 )
    return writeq(a2, *(_QWORD *)(a1 + 40) + a3);
  v4 = *(_DWORD **)(a1 + 48);
  if ( *(v4 - 1) != -166272269 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v4)(a2, a3, 0, 1);
}
