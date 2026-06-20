void tpd_resume_work()
{
  __int64 v0; // x19
  void (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v0 = tpd_cdev;
  v1 = *(void (__fastcall **)(_QWORD))(tpd_cdev + 3152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(tpd_cdev + 3104);
    if ( *((_DWORD *)v1 - 1) != -1066802076 )
      __break(0x8228u);
    v1(v2);
    *(_DWORD *)(v0 + 1192) = 0;
  }
}
