unsigned __int64 __fastcall qdf_thread_run(__int64 a1, __int64 a2)
{
  int v2; // w4
  unsigned __int64 v3; // x0
  unsigned __int64 v5; // x19
  unsigned int v12; // w9

  v2 = (unsigned __int16)qdf_thread_id++;
  v3 = kthread_create_on_node(a1, a2, 0xFFFFFFFFLL, "qdf %u", v2);
  if ( v3 > 0xFFFFFFFFFFFFF000LL )
    return 0;
  v5 = v3;
  _X0 = (unsigned int *)(v3 + 64);
  __asm { PRFM            #0x11, [X0] }
  do
    v12 = __ldxr(_X0);
  while ( __stxr(v12 + 1, _X0) );
  if ( !v12 || (((v12 + 1) | v12) & 0x80000000) != 0 )
    refcount_warn_saturate();
  wake_up_process(v5);
  return v5;
}
