__int64 __fastcall hif_hist_record_event(__int64 result, __int64 a2, unsigned __int8 a3)
{
  int v3; // w10
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x19
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x10
  int v10; // w20
  __int64 v11; // x11
  int v12; // w8
  unsigned __int64 StatusReg; // x8
  int v14; // w19
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x19
  unsigned __int64 v18; // x8
  int v19; // w20
  __int64 v20; // x9
  __int64 v21; // x20
  unsigned int v27; // w9
  unsigned int v28; // w9
  __int64 v29; // [xsp+8h] [xbp-8h]
  __int64 v30; // [xsp+8h] [xbp-8h]

  v3 = *(_DWORD *)(a2 + 24);
  if ( ((*(_QWORD *)(result + 608) >> v3) & 1) != 0 )
  {
    if ( a3 >= 0x12u )
      return qdf_trace_msg(61, 2, "%s: Invalid interrupt group id %d", "hif_hist_record_event", a3);
    _X8 = *(_QWORD *)(result + 8LL * a3 + 2608);
    if ( _X8 )
    {
      if ( (*(_DWORD *)_X8 & 0x80000000) != 0 )
        goto LABEL_39;
      v5 = _X8 + 24 + 32LL * (*(_DWORD *)_X8 & 0x1FF);
      if ( v3 > 4 )
      {
        if ( (unsigned int)(v3 - 6) >= 2 )
        {
          if ( v3 == 5 && *(_DWORD *)(v5 + 24) != 4 )
            return result;
        }
        else if ( *(_DWORD *)(v5 + 24) != 5 )
        {
          return result;
        }
        goto LABEL_39;
      }
      if ( v3 )
      {
        if ( v3 != 3 )
        {
          if ( v3 == 4 && *(_DWORD *)(a2 + 4) == *(_DWORD *)(a2 + 8) )
            return result;
          goto LABEL_39;
        }
        if ( *(_DWORD *)(v5 + 24) == 3 )
        {
          __isb(0xFu);
          *(_QWORD *)(v5 + 16) = _ReadStatusReg(CNTVCT_EL0);
          StatusReg = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(StatusReg + 16);
          v14 = *(_DWORD *)(StatusReg + 40);
          v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v15;
          if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
          {
            v21 = v5;
            result = preempt_schedule(result);
            v5 = v21;
          }
          *(_DWORD *)(v5 + 12) = v14;
          return result;
        }
LABEL_39:
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v27 = __ldxr((unsigned int *)_X8);
          v28 = v27 + 1;
        }
        while ( __stlxr(v28, (unsigned int *)_X8) );
        __dmb(0xBu);
        v16 = v28 & 0x1FF;
        v17 = _X8 + 32 * v16;
        if ( !*(_DWORD *)(a2 + 24) )
        {
          *(_DWORD *)(_X8 + 8) = v16;
          __isb(0xFu);
          *(_QWORD *)(_X8 + 16) = _ReadStatusReg(CNTVCT_EL0);
        }
        *(_BYTE *)(v17 + 24) = *(_BYTE *)a2;
        *(_DWORD *)(v17 + 28) = *(_DWORD *)(a2 + 4);
        *(_DWORD *)(v17 + 32) = *(_DWORD *)(a2 + 8);
        v18 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v18 + 16);
        v19 = *(_DWORD *)(v18 + 40);
        v20 = *(_QWORD *)(v18 + 16) - 1LL;
        *(_DWORD *)(v18 + 16) = v20;
        if ( !v20 || !*(_QWORD *)(v18 + 16) )
        {
          v29 = a2;
          result = preempt_schedule(result);
          a2 = v29;
        }
        *(_DWORD *)(v17 + 36) = v19;
        __isb(0xFu);
        *(_QWORD *)(v17 + 40) = _ReadStatusReg(CNTVCT_EL0);
        *(_DWORD *)(v17 + 48) = *(_DWORD *)(a2 + 24);
        return result;
      }
      if ( *(_DWORD *)(v5 + 24) != 3 )
        goto LABEL_39;
      v6 = *(unsigned int *)(_X8 + 8);
      if ( (((_WORD)v6 + 1) & 0x1FF) != (*(_DWORD *)_X8 & 0x1FF) )
        goto LABEL_39;
      if ( (unsigned int)v6 > 0x200 )
      {
        __break(0x5512u);
        goto LABEL_39;
      }
      v7 = _X8 + 24 + 32 * v6;
      __isb(0xFu);
      v8 = _ReadStatusReg(CNTVCT_EL0);
      v9 = _ReadStatusReg(SP_EL0);
      *(_QWORD *)(v7 + 16) = v8;
      ++*(_DWORD *)(v9 + 16);
      v10 = *(_DWORD *)(v9 + 40);
      v11 = *(_QWORD *)(v9 + 16) - 1LL;
      *(_DWORD *)(v9 + 16) = v11;
      if ( !v11 || !*(_QWORD *)(v9 + 16) )
      {
        v30 = _X8;
        result = preempt_schedule(result);
        _X8 = v30;
      }
      v12 = *(_DWORD *)(v7 + 16) - *(_DWORD *)(_X8 + 16);
      ++*(_DWORD *)(v7 + 4);
      *(_DWORD *)(v7 + 8) = v12;
      *(_DWORD *)(v7 + 12) = v10;
    }
  }
  return result;
}
