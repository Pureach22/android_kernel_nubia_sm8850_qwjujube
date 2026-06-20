__int64 __fastcall kgsl_ioctl_gpumem_sync_cache_bulk_compat(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x8
  unsigned int v4; // w9
  unsigned int v5; // w10
  __int64 result; // x0
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v8; // [xsp+8h] [xbp-18h]
  unsigned int v9; // [xsp+Ch] [xbp-14h]
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  v4 = a3[1];
  v5 = a3[2];
  v10 = 0;
  v7 = v3;
  v8 = v4;
  v9 = v5;
  result = kgsl_ioctl_gpumem_sync_cache_bulk(a1, a2, &v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
