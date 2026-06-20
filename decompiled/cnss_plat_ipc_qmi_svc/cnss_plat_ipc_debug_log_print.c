__int64 __fastcall cnss_plat_ipc_debug_log_print(
        __int64 a1,
        const char *a2,
        const char *a3,
        const char *a4,
        const char *a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 result; // x0
  __int64 v12; // x21
  _QWORD v13[4]; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v14[3]; // [xsp+38h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = &a9;
  v13[1] = v13;
  v13[2] = 0;
  v13[3] = 4294967272LL;
  v14[0] = a5;
  v14[1] = v13;
  if ( a4 )
  {
    v12 = a1;
    printk("%scnss_plat: %pV", a4, v14);
    a1 = v12;
  }
  result = ipc_log_string(a1, "[%s] %s: %pV", a2, a3, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
