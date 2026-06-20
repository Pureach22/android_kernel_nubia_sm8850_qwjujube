size_t __fastcall perf_trace_slimbus_dbg(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x24
  const char *v7; // x22
  size_t result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  int v11; // w23
  int v12; // w27
  _QWORD *v13; // x9
  size_t v14; // x21
  int v15; // w8
  unsigned int v16; // w10
  size_t v17; // x23
  size_t v18; // x24
  const char *v19; // x2
  __int64 *v20; // x8
  char *v21; // x0
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 v25; // x12
  __int64 v26; // [xsp+0h] [xbp-40h] BYREF
  _QWORD arg[4]; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v28; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v30; // [xsp+40h] [xbp+0h] BYREF

  v5 = v3;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v7 = a2;
  else
    v7 = "(null)";
  v29[0] = 0;
  v28 = 0;
  result = strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 124, v29, &v28);
    if ( result )
    {
      v13 = (_QWORD *)v29[0];
      *(_QWORD *)(v29[0] + 248LL) = &v26;
      v14 = result;
      v13[29] = &v30;
      v15 = (v11 + 17) | 0x640000;
      v13[32] = v5;
      v13[33] = 5;
      v16 = (v11 << 16) + 65552;
      v17 = result + 16;
      *(_DWORD *)(result + 8) = v16;
      *(_DWORD *)(result + 12) = v15;
      v18 = HIWORD(v16) - 1LL;
      memcpy((void *)(result + 16), v7, v18);
      *(_BYTE *)(v17 + v18) = 0;
      v19 = *(const char **)a3;
      v20 = *(__int64 **)(a3 + 8);
      v21 = (char *)(v14 + *(unsigned __int16 *)(v14 + 12));
      v23 = v20[2];
      v22 = v20[3];
      v25 = *v20;
      v24 = v20[1];
      arg[2] = v23;
      arg[3] = v22;
      arg[0] = v25;
      arg[1] = v24;
      if ( vsnprintf(v21, 0x64u, v19, arg) >= 100 )
        __break(0x800u);
      result = perf_trace_run_bpf_submit(v14, (unsigned int)(v12 + 124), v28, a1, 1, v29[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
