__int64 hdd_sysfs_print(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  __int64 v10; // x13
  __int64 result; // x0
  int v13; // w9
  int v14; // w8
  int v15; // w20
  int v16; // w0
  gcc_va_list va1; // [xsp+38h] [xbp-48h] BYREF
  gcc_va_list va; // [xsp+58h] [xbp-28h] BYREF
  __int64 v19; // [xsp+78h] [xbp-8h]

  va_start(va, a10);
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10 = *a1;
    va_copy(va1, va);
    result = vscnprintf(v10 + *((int *)a1 + 2), 4096LL - *((int *)a1 + 2), a2, va1);
    v13 = *((unsigned __int8 *)a1 + 12);
    v14 = *((_DWORD *)a1 + 2) + result;
    *((_DWORD *)a1 + 2) = v14;
    if ( v13 == 1 )
    {
      v15 = result;
      scnprintf(*a1 + v14, 4096LL - v14, "\n");
      result = (unsigned int)(v16 + v15);
      *((_DWORD *)a1 + 2) += result;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
