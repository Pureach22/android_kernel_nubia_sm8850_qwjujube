__int64 __fastcall perf_trace_print_tcp(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x23
  __int64 result; // x0
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v13; // w21
  _QWORD *v14; // x9
  int v15; // w8
  int v16; // w10
  const char *v17; // x9
  __int64 v18; // x23
  int v19; // w11
  __int64 v20; // x22
  const char *v21; // x1
  size_t v22; // x24
  int v23; // w8
  void *v24; // x23
  const char *v25; // x1
  size_t v26; // x24
  __int64 v27; // x2
  _QWORD *v28; // x5
  __int64 v29; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-30h] BYREF
  __int64 v32; // [xsp+18h] [xbp-28h] BYREF
  const char *v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  const char *v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]
  __int64 v37; // [xsp+40h] [xbp+0h] BYREF

  v8 = v5;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = nullptr;
  v31 = nullptr;
  v30 = 0;
  result = trace_event_get_offsets_print_tcp(&v32, a3, a4);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = ((result + 59) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v13, &v31, &v30);
    if ( result )
    {
      v14 = v31;
      v31[31] = &v29;
      v15 = v34;
      v14[29] = &v37;
      v14[32] = v8;
      v14[33] = 5;
      v16 = v32;
      v17 = v33;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 20) = v16;
      *(_DWORD *)(result + 24) = v15;
      v18 = result + (unsigned __int16)v16;
      v19 = *(_DWORD *)(a2 + 112);
      v20 = result;
      if ( v17 )
        v21 = v17;
      else
        v21 = "(null)";
      v22 = HIWORD(v16) - 1LL;
      *(_DWORD *)(result + 16) = v19;
      memcpy((void *)(result + (unsigned __int16)v16), v21, v22);
      *(_BYTE *)(v18 + v22) = 0;
      v23 = *(_DWORD *)(v20 + 24);
      v24 = (void *)(v20 + (unsigned __int16)v23);
      if ( v35 )
        v25 = v35;
      else
        v25 = "(null)";
      v26 = HIWORD(v23) - 1LL;
      memcpy(v24, v25, v26);
      *((_BYTE *)v24 + v26) = 0;
      v27 = v30;
      v28 = v31;
      *(_WORD *)(v20 + 28) = *(_WORD *)a5;
      *(_WORD *)(v20 + 30) = *(_WORD *)(a5 + 2);
      *(_DWORD *)(v20 + 32) = *(_DWORD *)(a5 + 4);
      *(_DWORD *)(v20 + 36) = *(_DWORD *)(a5 + 8);
      *(_BYTE *)(v20 + 40) = (*(_WORD *)(a5 + 12) & 0x200) != 0;
      *(_BYTE *)(v20 + 41) = (*(_WORD *)(a5 + 12) & 0x1000) != 0;
      *(_BYTE *)(v20 + 42) = *(_BYTE *)(a5 + 13) & 1;
      result = perf_trace_run_bpf_submit(v20, v13, v27, a1, 1, v28, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
