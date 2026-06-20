unsigned __int64 __fastcall kgsl_drawobj_create_timestamp_syncobj(__int64 a1, unsigned int *a2, int a3)
{
  unsigned __int64 v6; // x19
  __int64 v7; // x0
  int v8; // w0
  int v9; // w20
  _DWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = kgsl_drawobj_sync_create(a1, a2);
  if ( v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    v7 = _kmalloc_cache_noprof(_check_object_size, 3520, 120);
    *(_QWORD *)(v6 + 56) = v7;
    if ( v7 )
    {
      v11[0] = a2[1];
      v11[1] = a3;
      v8 = drawobj_add_sync_timestamp(a1, v6, v11);
      if ( v8 )
      {
        v9 = v8;
        kgsl_drawobj_destroy(v6);
        v6 = v9;
      }
    }
    else
    {
      kgsl_drawobj_destroy(v6);
      v6 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
