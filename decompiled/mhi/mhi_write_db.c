__int64 __fastcall mhi_write_db(__int64 a1, __int64 a2, unsigned int a3)
{
  void (*v3)(void); // x8
  _DWORD *v7; // x8

  v3 = *(void (**)(void))(a1 + 576);
  if ( *((_DWORD *)v3 - 1) != -242010890 )
    __break(0x8228u);
  v3();
  v7 = *(_DWORD **)(a1 + 576);
  if ( *(v7 - 1) != -242010890 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(a1, a2, a3);
}
