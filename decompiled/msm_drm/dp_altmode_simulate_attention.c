__int64 __fastcall dp_altmode_simulate_attention(__int64 a1, __int16 a2)
{
  __int64 v2; // x8
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0

  v2 = *(_QWORD *)(a1 - 8);
  *(_BYTE *)(a1 + 8) = (a2 & 0x80) != 0;
  *(_BYTE *)(a1 + 9) = HIBYTE(a2) & 1;
  if ( v2 )
  {
    v3 = *(void (__fastcall **)(_QWORD))(v2 + 16);
    if ( v3 )
    {
      v4 = *(_QWORD *)(a1 - 16);
      if ( *((_DWORD *)v3 - 1) != 711998475 )
        __break(0x8228u);
      v3(v4);
    }
  }
  return 0;
}
