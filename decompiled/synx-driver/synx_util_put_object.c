__int64 __fastcall synx_util_put_object(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x19
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  int v18; // w9

  _X8 = (unsigned int *)(result + 120);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stlxr(v18 - 1, _X8) );
  if ( v18 == 1 )
  {
    __dmb(9u);
    if ( result && (*(_BYTE *)(result + 124) & 2) != 0 )
    {
      v7 = result;
      if ( (unsigned int)synx_global_clear_subscribed_core(*(_DWORD *)(result + 344), 0, a3, a4, a5, a6)
        && (synx_debug & 1) != 0 )
      {
        printk(&unk_2867D, &unk_29207, "synx_util_destroy_coredata", 330, v11, v12);
      }
      synx_global_put_ref(*(unsigned int *)(v7 + 344), v8, v9, v10, v11, v12);
      result = v7;
    }
    return synx_util_object_destroy(result);
  }
  else if ( v18 <= 0 )
  {
    return refcount_warn_saturate(result + 120, 3);
  }
  return result;
}
