__int64 __fastcall cbo_release(__int64 a1)
{
  __int64 v2; // x20
  int v10; // w8

  if ( *(_DWORD *)(a1 + 88) )
    cbo_dispatch(0, a1, 0xFFFF, &cbo_release_args);
  v2 = *(_QWORD *)(a1 + 104);
  _X0 = (unsigned int *)(v2 + 16);
  __asm { PRFM            #0x11, [X0] }
  do
    v10 = __ldxr(_X0);
  while ( __stlxr(v10 - 1, _X0) );
  if ( v10 == 1 )
  {
    __dmb(9u);
    printk(&unk_103E6, "____destroy_server_info", v2);
    kfree(v2);
  }
  else if ( v10 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  return kfree(a1);
}
