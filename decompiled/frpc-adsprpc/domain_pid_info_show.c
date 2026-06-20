__int64 __fastcall domain_pid_info_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  const char *v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = nullptr;
  v5 = 0;
  LODWORD(result) = fastrpc_get_domain_pid_info(a1 - 80, (__int64 *)v6, &v5);
  if ( !(_DWORD)result )
  {
    sysfs_emit(a3, "%s", v6[0]);
    kfree(v6[0]);
    LODWORD(result) = v5;
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
