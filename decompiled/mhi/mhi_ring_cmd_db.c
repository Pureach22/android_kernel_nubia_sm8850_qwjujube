__int64 __fastcall mhi_ring_cmd_db(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  void (*v5)(void); // x8
  _DWORD *v6; // x8

  v3 = *(_QWORD *)(a2 + 48) - *(_QWORD *)(a2 + 32) + *(_QWORD *)(a2 + 8);
  **(_QWORD **)(a2 + 16) = v3;
  v4 = *(_QWORD *)(a2 + 88);
  v5 = *(void (**)(void))(a1 + 576);
  if ( *((_DWORD *)v5 - 1) != -242010890 )
    __break(0x8228u);
  v5();
  v6 = *(_DWORD **)(a1 + 576);
  if ( *(v6 - 1) != -242010890 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(a1, v4, (unsigned int)v3);
}
