void tpd_suspend_work()
{
  void (__fastcall *v0)(_QWORD); // x8
  __int64 v1; // x0

  v0 = *(void (__fastcall **)(_QWORD))(tpd_cdev + 3160);
  if ( v0 )
  {
    v1 = *(_QWORD *)(tpd_cdev + 3104);
    if ( *((_DWORD *)v0 - 1) != -1066802076 )
      __break(0x8228u);
    v0(v1);
  }
}
