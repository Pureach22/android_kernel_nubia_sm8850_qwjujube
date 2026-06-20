unsigned int *__fastcall cam_context_putref(__int64 a1)
{
  unsigned int *result; // x0
  int v8; // w8

  if ( *(_DWORD *)(a1 + 404) )
  {
    result = (unsigned int *)(a1 + 404);
    __asm { PRFM            #0x11, [X0] }
    do
      v8 = __ldxr(result);
    while ( __stlxr(v8 - 1, result) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      result = (unsigned int *)cam_node_put_ctxt_to_free_list();
    }
    else if ( v8 <= 0 )
    {
      result = (unsigned int *)refcount_warn_saturate();
    }
  }
  else
  {
    result = (unsigned int *)_warn_printk(
                               "ctx %s %d state %d devhdl %X\n",
                               (const char *)a1,
                               *(_DWORD *)(a1 + 32),
                               *(_DWORD *)(a1 + 240),
                               *(_DWORD *)(a1 + 60));
    __break(0x800u);
  }
  if ( (debug_mdl & 2) != 0 && !debug_priority )
    return (unsigned int *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             debug_mdl & 2,
                             4,
                             "cam_context_putref",
                             799,
                             "ctx device hdl %ld, ref count %d, dev_name %s",
                             *(unsigned int *)(a1 + 60),
                             *(_DWORD *)(a1 + 404),
                             (const char *)a1);
  return result;
}
