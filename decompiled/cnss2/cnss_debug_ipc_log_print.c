__int64 __fastcall cnss_debug_ipc_log_print(
        __int64 result,
        _QWORD a2,
        _QWORD a3,
        unsigned int a4,
        unsigned int a5,
        const char *a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 v9; // x21
  unsigned int v10; // w22
  _QWORD v11[4]; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v12[3]; // [xsp+38h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = &a9;
  v11[1] = v11;
  v11[2] = 0;
  v11[3] = 4294967280LL;
  v12[0] = a6;
  v12[1] = v11;
  if ( cnss_kernel_log_level >= a4 && a4 <= 6 )
  {
    v9 = result;
    v10 = a5;
    printk(*(&off_59CE8 + a4), v12);
    a5 = v10;
    result = v9;
  }
  if ( cnss_ipc_log_level >= a5 )
    result = ipc_log_string();
  _ReadStatusReg(SP_EL0);
  return result;
}
