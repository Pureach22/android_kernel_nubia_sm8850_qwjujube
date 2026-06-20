__int64 __fastcall aw_i2c_suspend(__int64 a1)
{
  __int64 v1; // x19
  void (__fastcall *v2)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 752);
  v2 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 1480) + 56LL);
  if ( *((_DWORD *)v2 - 1) != -2072377296 )
    __break(0x8228u);
  v2(v1);
  mutex_unlock(v1 + 752);
  return 0;
}
