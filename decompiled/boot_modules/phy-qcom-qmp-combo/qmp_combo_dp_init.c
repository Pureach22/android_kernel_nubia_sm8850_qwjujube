__int64 __fastcall qmp_combo_dp_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned int v3; // w20
  void (__fastcall *v4)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 8);
  mutex_lock(v1 + 208);
  v3 = qmp_combo_com_init((_QWORD *)v1, 0);
  if ( !v3 )
  {
    v4 = *(void (__fastcall **)(_QWORD))(v2 + 240);
    if ( *((_DWORD *)v4 - 1) != -1494932575 )
      __break(0x8228u);
    v4(v1);
    ++*(_DWORD *)(v1 + 344);
  }
  mutex_unlock(v1 + 208);
  return v3;
}
