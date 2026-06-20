_QWORD *__fastcall process_mem_seq_stop(__int64 a1, unsigned int *_X1)
{
  _QWORD *result; // x0
  int v8; // w8

  if ( (unsigned __int64)_X1 > 1 && (unsigned __int64)_X1 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X1] }
    do
      v8 = __ldxr(_X1);
    while ( __stlxr(v8 - 1, _X1) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      return kgsl_mem_entry_destroy(_X1);
    }
    else if ( v8 <= 0 )
    {
      return (_QWORD *)refcount_warn_saturate(_X1, 3);
    }
  }
  return result;
}
