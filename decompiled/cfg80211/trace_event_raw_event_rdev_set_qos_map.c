__int64 __fastcall trace_event_raw_event_rdev_set_qos_map(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x9
  long double v19; // q0
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v20);
  if ( !result )
    goto LABEL_14;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 < 0x21 )
    {
      sized_strscpy(v10 + 8, v9);
      v13 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v10 + 48) = v13;
      *(_DWORD *)(v10 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 )
      {
        *(_BYTE *)(v10 + 60) = *(_BYTE *)a4;
        v14 = *(_QWORD *)(a4 + 1);
        *(_QWORD *)(v10 + 69) = *(_QWORD *)(a4 + 9);
        *(_QWORD *)(v10 + 61) = v14;
        v15 = *(_QWORD *)(a4 + 33);
        v16 = *(_QWORD *)(a4 + 17);
        v17 = *(_QWORD *)(a4 + 25);
        *(_WORD *)(v10 + 101) = *(_WORD *)(a4 + 41);
        *(_QWORD *)(v10 + 93) = v15;
        *(_QWORD *)(v10 + 85) = v17;
        *(_QWORD *)(v10 + 77) = v16;
        v18 = *(_QWORD *)(a4 + 43);
        *(_QWORD *)(v10 + 111) = *(_QWORD *)(a4 + 51);
        *(_QWORD *)(v10 + 103) = v18;
      }
      else
      {
        *(_BYTE *)(v10 + 60) = 0;
        *(_QWORD *)(v10 + 61) = 0;
        *(_QWORD *)(v10 + 69) = 0;
        *(_QWORD *)(v10 + 77) = 0;
        *(_QWORD *)(v10 + 85) = 0;
        *(_QWORD *)(v10 + 93) = 0;
        *(_WORD *)(v10 + 101) = 0;
        *(_QWORD *)(v10 + 103) = 0;
        *(_QWORD *)(v10 + 111) = 0;
      }
      result = trace_event_buffer_commit(v20);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v19 = _fortify_panic(7, 32);
  return perf_trace_rdev_set_qos_map(v19);
}
