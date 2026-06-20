__int64 __fastcall kgsl_ioctl_cmdstream_readtimestamp_ctxtid(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x21
  __int64 owner; // x0
  __int64 v7; // x2
  int (__fastcall *v8)(__int64, __int64, __int64, unsigned int *); // x8
  __int64 v9; // x20
  int v15; // w8

  v3 = *a1;
  owner = kgsl_context_get_owner(a1, *a3);
  if ( !owner )
    return -22;
  _X19 = (unsigned int *)owner;
  if ( v3 )
  {
    v7 = a3[1];
    v8 = *(int (__fastcall **)(__int64, __int64, __int64, unsigned int *))(*(_QWORD *)(v3 + 8752) + 64LL);
    if ( *((_DWORD *)v8 - 1) != -362688460 )
      __break(0x8228u);
    v9 = v8(v3, owner, v7, a3 + 2);
  }
  else
  {
    v9 = -22;
  }
  __asm { PRFM            #0x11, [X19] }
  do
    v15 = __ldxr(_X19);
  while ( __stlxr(v15 - 1, _X19) );
  if ( v15 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy((__int64)_X19);
  }
  else if ( v15 <= 0 )
  {
    refcount_warn_saturate(_X19, 3);
  }
  return v9;
}
