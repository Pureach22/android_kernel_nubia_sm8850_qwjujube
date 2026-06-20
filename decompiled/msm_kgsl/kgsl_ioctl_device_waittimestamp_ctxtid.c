__int64 __fastcall kgsl_ioctl_device_waittimestamp_ctxtid(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 owner; // x0
  void (__fastcall *v7)(__int64, __int64, __int64, int *); // x8
  __int64 v8; // x21
  __int64 v9; // x4
  __int64 v10; // x5
  int (__fastcall *v11)(__int64, unsigned int *, __int64, __int64, __int64, __int64); // x8
  void (__fastcall *v12)(__int64, unsigned int *, __int64, int *); // x8
  int v18; // w8
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v20 = 0;
  owner = kgsl_context_get_owner();
  if ( owner )
  {
    _X19 = (unsigned int *)owner;
    if ( v4 )
    {
      v7 = *(void (__fastcall **)(__int64, __int64, __int64, int *))(*(_QWORD *)(v4 + 8752) + 64LL);
      if ( *((_DWORD *)v7 - 1) != -362688460 )
        __break(0x8228u);
      v7(v4, owner, 2, &v20);
    }
    v9 = *(unsigned int *)(a3 + 4);
    v10 = *(unsigned int *)(a3 + 8);
    v11 = *(int (__fastcall **)(__int64, unsigned int *, __int64, __int64, __int64, __int64))(*(_QWORD *)(v4 + 8752)
                                                                                            + 56LL);
    if ( *((_DWORD *)v11 - 1) != 1546841175 )
      __break(0x8228u);
    v8 = v11(v4, _X19, v9, v10, v9, v10);
    if ( v4 )
    {
      v12 = *(void (__fastcall **)(__int64, unsigned int *, __int64, int *))(*(_QWORD *)(v4 + 8752) + 64LL);
      if ( *((_DWORD *)v12 - 1) != -362688460 )
        __break(0x8228u);
      v12(v4, _X19, 2, &v20);
    }
    __asm { PRFM            #0x11, [X19] }
    do
      v18 = __ldxr(_X19);
    while ( __stlxr(v18 - 1, _X19) );
    if ( v18 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X19);
    }
    else if ( v18 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
  }
  else
  {
    v8 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
