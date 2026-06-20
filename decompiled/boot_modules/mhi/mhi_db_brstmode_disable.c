__int64 __fastcall mhi_db_brstmode_disable(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void (*v5)(void); // x9
  unsigned int v6; // w19
  _DWORD *v8; // x8

  *(_QWORD *)(a2 + 16) = a4;
  v5 = *(void (**)(void))(a1 + 576);
  v6 = a4;
  if ( *((_DWORD *)v5 - 1) != -242010890 )
    __break(0x8229u);
  v5();
  v8 = *(_DWORD **)(a1 + 576);
  if ( *(v8 - 1) != -242010890 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v8)(a1, a3, v6);
}
