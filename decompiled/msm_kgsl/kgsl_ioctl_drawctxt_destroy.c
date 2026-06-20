__int64 __fastcall kgsl_ioctl_drawctxt_destroy(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 owner; // x0
  int v11; // w8

  owner = kgsl_context_get_owner(a1, *a3);
  if ( !owner )
    return -22;
  _X19 = (unsigned int *)owner;
  kgsl_context_detach(owner);
  __asm { PRFM            #0x11, [X19] }
  do
    v11 = __ldxr(_X19);
  while ( __stlxr(v11 - 1, _X19) );
  if ( v11 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy((__int64)_X19);
  }
  else if ( v11 <= 0 )
  {
    refcount_warn_saturate(_X19, 3);
  }
  return 0;
}
