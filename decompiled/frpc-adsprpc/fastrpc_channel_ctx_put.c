__int64 __fastcall fastrpc_channel_ctx_put(__int64 result)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x9
  __int64 v5; // x19
  int v11; // w9

  _X8 = (unsigned int *)(result + 51664);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stlxr(v11 - 1, _X8) );
    if ( v11 != 1 )
      break;
    __dmb(9u);
    v2 = *(_QWORD *)(result + 64248);
    if ( v2 )
    {
      v3 = result;
      fastrpc_free_user(*(_QWORD *)(result + 64248));
      kfree(v2);
      result = v3;
      *(_QWORD *)(v3 + 64248) = 0;
    }
    _X8 = (_DWORD *)&unk_4A8;
    v4 = 50;
    while ( *(unsigned int *)((char *)_X8 + result) < 8 )
    {
      --v4;
      _X8 += 256;
      if ( !v4 )
      {
        v5 = result;
        ida_destroy(result + 51632);
        return kfree(v5);
      }
    }
    __break(0x5512u);
  }
  if ( v11 <= 0 )
    return refcount_warn_saturate(_X8, 3);
  return result;
}
