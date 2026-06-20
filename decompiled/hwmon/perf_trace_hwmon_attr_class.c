_DWORD *__fastcall perf_trace_hwmon_attr_class(__int64 a1, int a2, const char *a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v6; // x24
  const char *v9; // x22
  _DWORD *result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  int v13; // w25
  unsigned int v14; // w23
  _QWORD *v15; // x9
  unsigned int v16; // w10
  _DWORD *v17; // x25
  _DWORD *v18; // x21
  size_t v19; // x24
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v9 = a3;
  else
    v9 = "(null)";
  v24[0] = 0;
  v23 = 0;
  result = (_DWORD *)strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = (int)result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = (((_DWORD)result + 36) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v14, v24, &v23);
    if ( result )
    {
      v15 = (_QWORD *)v24[0];
      *(_QWORD *)(v24[0] + 248LL) = &v22;
      v15[29] = &v25;
      v15[32] = v6;
      v15[33] = 5;
      v16 = (v13 << 16) + 65560;
      v17 = result;
      result[2] = a2;
      result[3] = v16;
      v18 = result + 6;
      v19 = HIWORD(v16) - 1LL;
      memcpy(result + 6, v9, v19);
      *((_BYTE *)v18 + v19) = 0;
      v20 = v23;
      v21 = v24[0];
      *((_QWORD *)v17 + 2) = a4;
      result = (_DWORD *)perf_trace_run_bpf_submit(v17, v14, v20, a1, 1, v21, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
