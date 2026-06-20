__int64 __fastcall trace_event_raw_event_drv_wake_tx_queue(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x8
  const char *v12; // x22
  int *v13; // x24
  size_t v14; // x0
  unsigned __int64 v15; // x2
  int v16; // w9
  int v17; // w8
  void *v18; // x22
  size_t v19; // x23
  int v20; // w9
  __int64 v21; // x0
  void *v22; // x3
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v23, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  v8 = strlen((const char *)(a3 + 1640)) + 1;
  result = trace_event_buffer_reserve(v23);
  if ( !result )
    goto LABEL_14;
  v10 = result;
  *(_DWORD *)(result + 60) = (v8 << 16) | 0x48;
  v11 = *(_QWORD *)(a2 + 72);
  v12 = *(const char **)(v11 + 504);
  if ( !v12 )
    v12 = *(const char **)(v11 + 392);
  v13 = *(int **)(a4 + 240);
  v14 = strnlen(v12, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v10 + 8, v12);
      v16 = *(_DWORD *)(v10 + 60);
      v17 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v10 + 48) = a3;
      *(_DWORD *)(v10 + 40) = v17;
      v18 = (void *)(v10 + (unsigned __int16)v16);
      v19 = HIWORD(v16) - 1LL;
      *(_BYTE *)(v10 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v18, (const void *)(a3 + 1640), v19);
      *((_BYTE *)v18 + v19) = 0;
      if ( v13 )
      {
        v20 = *v13;
        *(_WORD *)(v10 + 68) = *((_WORD *)v13 + 2);
        *(_DWORD *)(v10 + 64) = v20;
      }
      else
      {
        *(_WORD *)(v10 + 68) = 0;
        *(_DWORD *)(v10 + 64) = 0;
      }
      *(_BYTE *)(v10 + 70) = *(_BYTE *)(a4 + 249);
      *(_BYTE *)(v10 + 71) = *(_BYTE *)(a4 + 248);
      result = trace_event_buffer_commit(v23);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v21 = _fortify_panic(7);
  __arm_mte_set_tag(&STACK[0xCA0], v22);
  return perf_trace_drv_wake_tx_queue(v21);
}
