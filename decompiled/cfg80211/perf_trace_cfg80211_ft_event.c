__int64 __fastcall perf_trace_cfg80211_ft_event(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x25
  __int64 v8; // x19
  __int64 v10; // x8
  int v11; // w26
  int v12; // w28
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w21
  _QWORD *v15; // x9
  __int64 v16; // x22
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  __int64 v20; // x8
  int *v21; // x8
  __int16 v22; // w9
  int v23; // w8
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(result + 104);
  v26[0] = 0;
  v11 = *(_DWORD *)(a4 + 8);
  v25 = 0;
  v12 = *(_DWORD *)(a4 + 32);
  v24 = v10;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v24) )
  {
    v14 = ((v11 + v12 + 87) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v26, &v25);
    if ( result )
    {
      v15 = (_QWORD *)v26[0];
      *(_QWORD *)(v26[0] + 232LL) = &vars0;
      v16 = result;
      v15[31] = &v24;
      v15[32] = v5;
      v15[33] = 5;
      *(_DWORD *)(result + 72) = (v11 + 76) | (v12 << 16);
      *(_DWORD *)(result + 60) = (v11 << 16) | 0x4C;
      v17 = *(const char **)(a2 + 504);
      if ( !v17 )
        v17 = *(const char **)(a2 + 392);
      v18 = strnlen(v17, 0x20u);
      if ( v18 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v18 == 32 )
          v19 = 32;
        else
          v19 = v18 + 1;
        if ( v19 < 0x21 )
        {
          sized_strscpy(v16 + 8, v17);
          v20 = *(_QWORD *)(a3 + 304);
          *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v16 + 48) = v20;
          *(_DWORD *)(v16 + 56) = *(_DWORD *)(a3 + 224);
          if ( *(_QWORD *)a4 )
            memcpy((void *)(v16 + *(unsigned __int16 *)(v16 + 60)), *(const void **)a4, *(_QWORD *)(a4 + 8));
          v21 = *(int **)(a4 + 16);
          if ( v21 )
          {
            v22 = *((_WORD *)v21 + 2);
            v23 = *v21;
            *(_WORD *)(v16 + 68) = v22;
            *(_DWORD *)(v16 + 64) = v23;
            if ( !*(_QWORD *)(a4 + 24) )
            {
LABEL_16:
              result = perf_trace_run_bpf_submit(v16, v14, v25, v8, 1, v26[0], StatusReg + v24, 0);
              goto LABEL_17;
            }
          }
          else
          {
            *(_WORD *)(v16 + 68) = 0;
            *(_DWORD *)(v16 + 64) = 0;
            if ( !*(_QWORD *)(a4 + 24) )
              goto LABEL_16;
          }
          memcpy((void *)(v16 + *(unsigned __int16 *)(v16 + 72)), *(const void **)(a4 + 24), *(_QWORD *)(a4 + 32));
          goto LABEL_16;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x3B25C60);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
