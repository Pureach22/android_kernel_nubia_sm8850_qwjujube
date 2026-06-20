_DWORD *__fastcall perf_trace_dfc_ll_switch(__int64 a1, const char *a2, int a3, unsigned __int8 a4, void *a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  const char *v9; // x24
  _DWORD *result; // x0
  __int64 v11; // x28
  unsigned __int64 StatusReg; // x20
  int v13; // w26
  int v14; // w27
  unsigned int v15; // w23
  __int64 v16; // x30
  _QWORD *v17; // x9
  int v18; // w11
  _DWORD *v19; // x25
  size_t v20; // x26
  int v21; // w10
  _DWORD *v22; // x27
  char v23; // w8
  void *v24; // x1
  __int64 v25; // x8
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  int v27; // [xsp+Ch] [xbp-24h]
  void *src; // [xsp+10h] [xbp-20h]
  unsigned int v29; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  src = a5;
  v7 = v5;
  v27 = a3;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v9 = a2;
  else
    v9 = "(null)";
  v30[0] = 0;
  v29 = 0;
  result = (_DWORD *)strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = (int)result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = (_DWORD)result + 1;
    v15 = ((a4 + (_DWORD)result + 1 + 31) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v15, v30, &v29);
    if ( result )
    {
      v16 = v7;
      v17 = (_QWORD *)v30[0];
      v18 = (v13 + 21) | (a4 << 16);
      *(_QWORD *)(v30[0] + 248LL) = &v26;
      v19 = result + 5;
      v20 = (unsigned __int16)v14 - 1LL;
      v17[29] = &vars0;
      v17[32] = v16;
      v17[33] = 5;
      v21 = (v14 << 16) | 0x14;
      result[4] = v18;
      v22 = result;
      result[2] = v21;
      memcpy(result + 5, v9, v20);
      v23 = v27;
      v24 = src;
      *((_BYTE *)v19 + v20) = 0;
      *((_BYTE *)v22 + 12) = v23;
      v25 = *((unsigned __int16 *)v22 + 8);
      *((_BYTE *)v22 + 13) = a4;
      memcpy((char *)v22 + v25, v24, a4);
      result = (_DWORD *)perf_trace_run_bpf_submit(v22, v15, v29, a1, 1, v30[0], StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
