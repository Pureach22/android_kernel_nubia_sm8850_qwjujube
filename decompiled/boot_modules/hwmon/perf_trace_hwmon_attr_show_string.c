_DWORD *__fastcall perf_trace_hwmon_attr_show_string(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v7; // x22
  _DWORD *result; // x0
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v11; // w20
  __int64 v12; // x30
  _QWORD *v13; // x9
  int v14; // w11
  char *v15; // x22
  const char *v16; // x9
  int v17; // w10
  __int64 v18; // x23
  _DWORD *v19; // x21
  const char *v20; // x1
  int v21; // w8
  char *v22; // x22
  const char *v23; // x1
  size_t v24; // x23
  __int64 v25; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v27; // [xsp+10h] [xbp-30h] BYREF
  __int64 v28; // [xsp+18h] [xbp-28h] BYREF
  const char *v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  const char *v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v7 = v4;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = nullptr;
  v28 = 0;
  v29 = nullptr;
  v27 = nullptr;
  v26 = 0;
  result = (_DWORD *)trace_event_get_offsets_hwmon_attr_show_string(&v28, a3, a4);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v11 = (((_DWORD)result + 31) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v11, &v27, &v26);
    if ( result )
    {
      v12 = v7;
      v13 = v27;
      v14 = v28;
      v27[31] = &v25;
      v13[29] = &vars0;
      v15 = (char *)result + (unsigned __int16)v14;
      v13[32] = v12;
      v13[33] = 5;
      v16 = v29;
      v17 = v30;
      v18 = HIWORD(v14) - 1LL;
      result[2] = a2;
      v19 = result;
      result[3] = v14;
      result[4] = v17;
      if ( v16 )
        v20 = v16;
      else
        v20 = "(null)";
      memcpy(v15, v20, HIWORD(v14) - 1LL);
      v15[v18] = 0;
      v21 = v19[4];
      v22 = (char *)v19 + (unsigned __int16)v21;
      if ( v31 )
        v23 = v31;
      else
        v23 = "(null)";
      v24 = HIWORD(v21) - 1LL;
      memcpy(v22, v23, v24);
      v22[v24] = 0;
      result = (_DWORD *)perf_trace_run_bpf_submit(v19, v11, v26, a1, 1, v27, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
