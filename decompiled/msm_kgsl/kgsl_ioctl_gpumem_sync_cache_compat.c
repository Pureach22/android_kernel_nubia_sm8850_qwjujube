__int64 __fastcall kgsl_ioctl_gpumem_sync_cache_compat(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w8
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v9; // [xsp+10h] [xbp-20h]
  unsigned int v10; // [xsp+14h] [xbp-1Ch]
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a3[1];
  v8 = *a3;
  v4 = a3[2];
  v5 = a3[3];
  v9 = v3;
  v10 = v4;
  v6 = a3[4];
  v11 = v5;
  v12 = v6;
  result = kgsl_ioctl_gpumem_sync_cache(a1, a2, (__int64)&v8);
  _ReadStatusReg(SP_EL0);
  return result;
}
