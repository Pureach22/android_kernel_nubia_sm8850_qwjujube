__int64 __fastcall trace_event_raw_event_rdev_channel_switch(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  int v8; // w23
  int v9; // w24
  __int64 result; // x0
  __int64 v11; // x20
  const char *v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x8
  __int64 v16; // x8
  char v17; // cf
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 && (result = _trace_trigger_soft_disabled(a1), (result & 1) != 0)
    || (v8 = *(_DWORD *)(a4 + 224), v9 = *(_DWORD *)(a4 + 228), (result = trace_event_buffer_reserve(v18)) == 0) )
  {
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = result;
  *(_DWORD *)(result + 96) = (v8 << 17) | 0x69;
  *(_DWORD *)(result + 100) = (2 * v8 + 105) | (v9 << 17);
  v12 = *(const char **)(a2 + 504);
  if ( !v12 )
    v12 = *(const char **)(a2 + 392);
  v13 = strnlen(v12, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v11 + 8, v12);
      v15 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v11 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v11 + 48) = v15;
      *(_DWORD *)(v11 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 && *(_QWORD *)a4 )
      {
        *(_DWORD *)(v11 + 60) = **(_DWORD **)a4;
        *(_DWORD *)(v11 + 64) = *(_DWORD *)(*(_QWORD *)a4 + 4LL);
        *(_DWORD *)(v11 + 68) = *(unsigned __int16 *)(*(_QWORD *)a4 + 8LL);
        *(_DWORD *)(v11 + 72) = *(_DWORD *)(a4 + 8);
        *(_DWORD *)(v11 + 76) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v11 + 80) = *(unsigned __int16 *)(a4 + 28);
        *(_DWORD *)(v11 + 84) = *(_DWORD *)(a4 + 16);
        *(_WORD *)(v11 + 88) = *(_WORD *)(a4 + 30);
      }
      else
      {
        *(_QWORD *)(v11 + 82) = 0;
        *(_QWORD *)(v11 + 76) = 0;
        *(_QWORD *)(v11 + 68) = 0;
        *(_QWORD *)(v11 + 60) = 0;
      }
      *(_BYTE *)(v11 + 90) = *(_BYTE *)(a4 + 408);
      *(_BYTE *)(v11 + 91) = *(_BYTE *)(a4 + 409);
      *(_BYTE *)(v11 + 92) = *(_BYTE *)(a4 + 410);
      memcpy(
        (void *)(v11 + *(unsigned __int16 *)(v11 + 96)),
        *(const void **)(a4 + 208),
        2LL * *(unsigned int *)(a4 + 224));
      v16 = *(unsigned int *)(a4 + 228);
      if ( (_DWORD)v16 )
        memcpy((void *)(v11 + *(unsigned __int16 *)(v11 + 100)), *(const void **)(a4 + 216), 2 * v16);
      *(_BYTE *)(v11 + 104) = *(_BYTE *)(a4 + 411);
      result = trace_event_buffer_commit(v18);
      goto LABEL_17;
    }
  }
  _fortify_panic(7, 32);
  if ( v17 )
    JUMPOUT(0xE470C);
  return perf_trace_rdev_channel_switch();
}
