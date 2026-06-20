unsigned int *__fastcall cam_context_getref(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int *result; // x0
  unsigned int v4; // w20
  unsigned int v10; // w9

  v1 = *(_DWORD *)(a1 + 404);
  result = (unsigned int *)(a1 + 404);
  if ( v1 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v10 = __ldxr(result);
      while ( v10 == v1 && __stxr(v1 + 1, result) );
      v4 = v1;
      if ( v10 == v1 )
        break;
      v4 = 0;
      v1 = v10;
    }
    while ( v10 );
  }
  else
  {
    v4 = 0;
  }
  if ( (((v4 + 1) | v4) & 0x80000000) == 0 )
  {
    if ( v4 )
      goto LABEL_13;
    goto LABEL_12;
  }
  result = (unsigned int *)refcount_warn_saturate();
  if ( !v4 )
  {
LABEL_12:
    result = (unsigned int *)_warn_printk("%s fail\n", "cam_context_getref");
    __break(0x800u);
  }
LABEL_13:
  if ( (debug_mdl & 2) != 0 && !debug_priority )
    return (unsigned int *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             debug_mdl & 2,
                             4,
                             "cam_context_getref",
                             811,
                             "ctx device hdl %ld, ref count %d, dev_name %s",
                             *(unsigned int *)(a1 + 60),
                             *(_DWORD *)(a1 + 404),
                             (const char *)a1);
  return result;
}
