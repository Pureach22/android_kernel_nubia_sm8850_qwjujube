__int64 __fastcall sde_fence_deinit(__int64 result)
{
  int v7; // w9

  if ( !result )
    return printk(&unk_251018, "sde_fence_deinit");
  _X8 = (unsigned int *)(result + 12);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stlxr(v7 - 1, _X8) );
  if ( v7 == 1 )
  {
    __dmb(9u);
    return kfree(result);
  }
  else if ( v7 <= 0 )
  {
    return refcount_warn_saturate(result + 12, 3);
  }
  return result;
}
