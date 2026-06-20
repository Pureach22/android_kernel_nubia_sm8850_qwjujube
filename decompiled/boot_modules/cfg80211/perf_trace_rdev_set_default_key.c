__int64 __fastcall perf_trace_rdev_set_default_key(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        char a6,
        char a7)
{
  __int64 v7; // x30
  __int64 v8; // x27
  __int64 v11; // x19
  __int64 v15; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v17; // x9
  __int64 v18; // x23
  const char *v19; // x27
  size_t v20; // x0
  unsigned __int64 v21; // x2
  __int64 v22; // x8
  __int64 v23; // x5
  __int64 v24; // x2
  int v25; // w9
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  int v27; // [xsp+8h] [xbp-18h]
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v27 = a4;
  v8 = v7;
  v11 = result;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v15 = *(_QWORD *)(result + 104);
  v28 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    result = perf_trace_buf_alloc(68, v29, &v28);
    if ( result )
    {
      v17 = (_QWORD *)v29[0];
      v18 = result;
      *(_QWORD *)(v29[0] + 232LL) = &vars0;
      v17[33] = 5;
      v17[31] = &v26;
      v17[32] = v8;
      v19 = *(const char **)(a2 + 504);
      if ( !v19 )
        v19 = *(const char **)(a2 + 392);
      v20 = strnlen(v19, 0x20u);
      if ( v20 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v20 == 32 )
          v21 = 32;
        else
          v21 = v20 + 1;
        if ( v21 < 0x21 )
        {
          sized_strscpy(v18 + 8, v19);
          v22 = *(_QWORD *)(a3 + 304);
          v23 = v29[0];
          *(_QWORD *)(v18 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v18 + 48) = v22;
          LODWORD(v22) = v27;
          v24 = v28;
          v25 = *(_DWORD *)(a3 + 224);
          *(_BYTE *)(v18 + 64) = a5;
          *(_BYTE *)(v18 + 65) = a6 & 1;
          *(_DWORD *)(v18 + 56) = v25;
          *(_DWORD *)(v18 + 60) = v22;
          *(_BYTE *)(v18 + 66) = a7 & 1;
          result = perf_trace_run_bpf_submit(v18, 68, v24, v11, 1, v23, StatusReg + v15, 0);
          goto LABEL_12;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0xFFFFFFFFFF417AE4LL);
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
