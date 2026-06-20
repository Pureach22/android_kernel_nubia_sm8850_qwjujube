__int64 __fastcall mhi_db_brstmode(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  void (__fastcall *v5)(__int64, __int64); // x9
  __int64 v7; // x19
  unsigned int v8; // w21
  _DWORD *v9; // x8

  if ( *(_BYTE *)(a2 + 1) == 1 )
  {
    *(_QWORD *)(a2 + 16) = a4;
    v5 = *(void (__fastcall **)(__int64, __int64))(result + 576);
    v7 = result;
    v8 = a4;
    if ( *((_DWORD *)v5 - 1) != -242010890 )
      __break(0x8229u);
    v5(result, a3 + 4);
    v9 = *(_DWORD **)(v7 + 576);
    if ( *(v9 - 1) != -242010890 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v9)(v7, a3, v8);
    *(_BYTE *)(a2 + 1) = 0;
  }
  return result;
}
