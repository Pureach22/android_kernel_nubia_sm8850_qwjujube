__int64 __fastcall qmp_combo_dp_configure(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x13
  void (__fastcall *v10)(_QWORD); // x8

  v2 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(v2 + 8);
  mutex_lock(v2 + 208);
  v5 = a2[2];
  v6 = a2[3];
  v7 = a2[4];
  *(_DWORD *)(v2 + 340) = *((_DWORD *)a2 + 10);
  v9 = *a2;
  v8 = a2[1];
  *(_QWORD *)(v2 + 324) = v6;
  *(_QWORD *)(v2 + 332) = v7;
  LOBYTE(v7) = *(_BYTE *)(v2 + 340);
  *(_QWORD *)(v2 + 316) = v5;
  *(_QWORD *)(v2 + 300) = v9;
  *(_QWORD *)(v2 + 308) = v8;
  if ( (v7 & 8) != 0 )
  {
    v10 = *(void (__fastcall **)(_QWORD))(v4 + 224);
    if ( *((_DWORD *)v10 - 1) != -1494932575 )
      __break(0x8228u);
    v10(v2);
    *(_BYTE *)(v2 + 340) &= ~8u;
  }
  mutex_unlock(v2 + 208);
  return 0;
}
