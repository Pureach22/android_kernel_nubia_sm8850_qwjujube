_DWORD *__fastcall perf_trace_spi_log_info(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x25
  const char *v7; // x23
  _DWORD *result; // x0
  __int64 v9; // x26
  unsigned __int64 StatusReg; // x27
  int v11; // w24
  unsigned int v12; // w20
  _QWORD *v13; // x9
  _DWORD *v14; // x22
  unsigned int v15; // w10
  _DWORD *v16; // x24
  size_t v17; // x25
  const char *v18; // x2
  __int64 *v19; // x8
  char *v20; // x0
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x12
  __int64 v25; // [xsp+0h] [xbp-40h] BYREF
  _QWORD arg[4]; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v27; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v29; // [xsp+40h] [xbp+0h] BYREF

  v5 = v3;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v7 = a2;
  else
    v7 = "(null)";
  v28[0] = 0;
  v27 = 0;
  result = (_DWORD *)strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = (int)result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = (((_DWORD)result + 284) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v12, v28, &v27);
    if ( result )
    {
      v13 = (_QWORD *)v28[0];
      *(_QWORD *)(v28[0] + 248LL) = &v25;
      v14 = result;
      v13[29] = &v29;
      v13[32] = v5;
      v13[33] = 5;
      LODWORD(v13) = (v11 + 17) | 0x1000000;
      v15 = (v11 << 16) + 65552;
      v16 = result + 4;
      result[2] = v15;
      result[3] = (_DWORD)v13;
      v17 = HIWORD(v15) - 1LL;
      memcpy(result + 4, v7, v17);
      *((_BYTE *)v16 + v17) = 0;
      v18 = *(const char **)a3;
      v19 = *(__int64 **)(a3 + 8);
      v20 = (char *)v14 + *((unsigned __int16 *)v14 + 6);
      v22 = v19[2];
      v21 = v19[3];
      v24 = *v19;
      v23 = v19[1];
      arg[2] = v22;
      arg[3] = v21;
      arg[0] = v24;
      arg[1] = v23;
      if ( vsnprintf(v20, 0x100u, v18, arg) >= 256 )
        __break(0x800u);
      result = (_DWORD *)perf_trace_run_bpf_submit(v14, v12, v27, a1, 1, v28[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
