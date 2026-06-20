__int64 __fastcall qcrypto_tfm_complete(__int64 a1, _QWORD *a2, __int64 a3, int a4)
{
  __int64 v4; // x23
  __int64 v9; // x0
  __int64 v10; // x20
  unsigned int v11; // w22
  _QWORD *i; // x9
  _QWORD *v13; // x8
  __int64 v14; // x10
  unsigned int v21; // w9
  unsigned int v22; // w21
  __int64 result; // x0
  _DWORD *v25; // x12
  __int64 v26; // x12
  unsigned int v29; // w12
  unsigned int v32; // w12
  unsigned int v34; // w9

  v4 = *(_QWORD *)(a1 + 32);
  v9 = raw_spin_lock_irqsave(v4 + 52);
  *(_DWORD *)(a3 + 32) = a4;
  v10 = v9;
  v11 = 0;
  for ( i = (_QWORD *)*a2; (_QWORD *)*a2 != a2; ++v11 )
  {
    if ( *((_DWORD *)i + 8) == -115 )
      break;
    v13 = (_QWORD *)i[1];
    if ( (_QWORD *)*v13 == i && (v14 = *i, *(_QWORD **)(*i + 8LL) == i) )
    {
      *(_QWORD *)(v14 + 8) = v13;
      *v13 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
    }
    *i = 0xDEAD000000000100LL;
    i[1] = 0xDEAD000000000122LL;
    llist_add_batch(i + 2, i + 2, v4 + 224);
    _X8 = (unsigned int *)(v4 + 232);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 + 1, _X8) );
    i = (_QWORD *)*a2;
  }
  v22 = *(_DWORD *)(v4 + 232);
  if ( v22 > *(_DWORD *)(v4 + 340) )
    *(_DWORD *)(v4 + 340) = v22;
  if ( v11 > *(_DWORD *)(v4 + 344) )
    *(_DWORD *)(v4 + 344) = v11;
  if ( v22 >= 0x190 )
  {
    _X8 = (unsigned int *)(v4 + 284);
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v34 = __ldxr(_X8);
      if ( v34 != 1 )
        break;
      if ( !__stlxr(0, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v34 == 1 )
      ++*(_DWORD *)(v4 + 316);
  }
  result = raw_spin_unlock_irqrestore(v4 + 52, v10);
  while ( *(_QWORD *)(v4 + 224) )
  {
    if ( (*(_BYTE *)(a1 + 253) & 1) != 0 )
    {
      result = 32;
      v25 = (_DWORD *)(v4 + 328);
    }
    else
    {
      v26 = *(_QWORD *)(v4 + 296);
      result = *(unsigned int *)(v4 + 288);
      ++*(_DWORD *)(v4 + 332);
      if ( !v26 || !*(_DWORD *)(v26 + 248) )
        goto LABEL_27;
      v25 = (_DWORD *)(v4 + 336);
      if ( v22 < 0x40 )
        return result;
    }
    ++*v25;
LABEL_27:
    _X14 = (unsigned int *)(v4 + 280);
    __asm { PRFM            #0x11, [X14] }
    while ( 1 )
    {
      v29 = __ldxr(_X14);
      if ( v29 )
        break;
      if ( !__stlxr(1u, _X14) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !v29 )
      return queue_work_on(result, *(_QWORD *)(v4 + 240), v4 + 248);
    _X13 = (unsigned int *)(v4 + 280);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v32 = __ldxr(_X13);
      if ( v32 != 1 )
        break;
      if ( !__stlxr(2u, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v32 )
      return result;
  }
  return result;
}
