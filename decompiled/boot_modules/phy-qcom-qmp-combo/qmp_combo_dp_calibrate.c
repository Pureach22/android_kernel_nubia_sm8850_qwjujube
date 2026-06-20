__int64 __fastcall qmp_combo_dp_calibrate(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w20

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 8);
  mutex_lock(v1 + 208);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 232);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 1426351319 )
      __break(0x8228u);
    v4 = v3(v1);
  }
  else
  {
    v4 = 0;
  }
  mutex_unlock(v1 + 208);
  return v4;
}
