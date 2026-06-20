__int64 __fastcall qce_alloc_req_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *v5; // x9
  int v6; // w10
  __int64 result; // x0
  __int64 v8; // x8
  unsigned int v15; // w12
  unsigned int v18; // w12
  unsigned int v21; // w12
  unsigned int v24; // w12
  unsigned int v27; // w12
  unsigned int v30; // w12
  unsigned int v33; // w12
  unsigned int v36; // w11

  v5 = (_DWORD *)(a1 + 69512);
  v6 = *(_DWORD *)(a1 + 69512);
  if ( v6 + 1 <= 7 )
    result = (unsigned int)(v6 + 1);
  else
    result = 0;
  if ( (unsigned int)result >= 9 )
    goto LABEL_59;
  v8 = a1 + 2624;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v15 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v15 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v18 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v18 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v21 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v21 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v24 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v24 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v27 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v27 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v30 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v30 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
    goto LABEL_59;
  _X10 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
  __asm { PRFM            #0x11, [X10] }
  do
    v33 = __ldxr(_X10);
  while ( __stlxr(1u, _X10) );
  __dmb(0xBu);
  if ( !v33 )
    goto LABEL_57;
  result = (unsigned int)result <= 6 ? (unsigned int)(result + 1) : 0LL;
  if ( (unsigned int)result > 8 )
  {
LABEL_59:
    __break(0x5512u);
    return qce_sps_add_cmd(result, a2, a3, a4);
  }
  else
  {
    _X8 = (unsigned int *)(v8 + 7432LL * (unsigned int)result);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stlxr(1u, _X8) );
    __dmb(0xBu);
    if ( !v36 )
    {
LABEL_57:
      *v5 = result;
      return result;
    }
    printk(&unk_1561E, "qce_alloc_req_info", (unsigned int)v5[172]);
    return 4294967280LL;
  }
}
