__int64 __fastcall cti_dying_cpu(unsigned int a1)
{
  unsigned __int64 v1; // x27
  __int64 v2; // x19
  int v3; // w8

  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v1);
    JUMPOUT(0x8908);
  }
  v2 = cti_cpu_drvdata[a1];
  if ( v2 )
  {
    raw_spin_lock(v2 + 56);
    v3 = *(unsigned __int8 *)(v2 + 76);
    *(_BYTE *)(v2 + 77) = 0;
    if ( v3 == 1 )
      coresight_disclaim_device(*(_QWORD *)(v2 + 8));
    raw_spin_unlock(v2 + 56);
  }
  return 0;
}
