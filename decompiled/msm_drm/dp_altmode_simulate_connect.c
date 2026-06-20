__int64 __fastcall dp_altmode_simulate_connect(__int64 a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x9
  __int64 v5; // t2
  void (__fastcall *v6)(_QWORD); // x8

  *(_BYTE *)(a1 + 8) = a2;
  v2 = 8;
  *(_BYTE *)(a1 - 24) = a2 ^ 1;
  *(_BYTE *)(a1 + 10) = a2;
  v5 = a1 - 16;
  v3 = *(_QWORD *)(a1 - 16);
  v4 = *(_QWORD *)(v5 + 8);
  if ( (a2 & 1) != 0 )
    v2 = 0;
  v6 = *(void (__fastcall **)(_QWORD))(v4 + v2);
  if ( *((_DWORD *)v6 - 1) != 711998475 )
    __break(0x8228u);
  v6(v3);
  return 0;
}
