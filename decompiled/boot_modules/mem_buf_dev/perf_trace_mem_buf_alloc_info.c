__int64 __fastcall perf_trace_mem_buf_alloc_info(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, _DWORD *a5)
{
  __int64 v5; // x30
  __int64 v8; // x24
  __int64 result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v13; // w21
  _QWORD *v14; // x9
  int v15; // w11
  int v16; // w8
  __int64 v17; // x22
  int v18; // w10
  const char *v19; // x8
  __int64 v20; // x24
  __int64 v21; // x25
  const char *v22; // x1
  int v23; // w8
  void *v24; // x23
  const char *v25; // x1
  size_t v26; // x24
  unsigned __int64 v27; // x8
  _BYTE *v28; // x11
  __int64 v29; // x9
  __int64 v30; // x10
  char v31; // t1
  __int64 v32; // [xsp+0h] [xbp-60h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD *v34; // [xsp+10h] [xbp-50h] BYREF
  __int64 v35; // [xsp+18h] [xbp-48h] BYREF
  const char *v36; // [xsp+20h] [xbp-40h]
  __int64 v37; // [xsp+28h] [xbp-38h]
  const char *v38; // [xsp+30h] [xbp-30h]
  __int64 v39; // [xsp+38h] [xbp-28h]
  __int64 v40; // [xsp+40h] [xbp-20h]
  __int64 v41; // [xsp+48h] [xbp-18h]
  __int64 v42; // [xsp+50h] [xbp-10h]
  __int64 v43; // [xsp+58h] [xbp-8h]
  __int64 vars0; // [xsp+60h] [xbp+0h] BYREF

  v8 = v5;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = nullptr;
  v35 = 0;
  v36 = nullptr;
  v34 = nullptr;
  v33 = 0;
  result = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, _DWORD *))trace_event_get_offsets_mem_buf_alloc_info)(
             &v35,
             a3,
             a4,
             a5);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = ((result + 51) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v13, &v34, &v33);
    if ( result )
    {
      v14 = v34;
      v15 = v41;
      v34[31] = &v32;
      v16 = v37;
      v14[29] = &vars0;
      v17 = result;
      v14[32] = v8;
      v14[33] = 5;
      v18 = v35;
      LODWORD(v14) = v39;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 20) = v18;
      *(_DWORD *)(result + 24) = v16;
      v19 = v36;
      *(_DWORD *)(result + 28) = (_DWORD)v14;
      *(_DWORD *)(result + 32) = v15;
      v20 = result + (unsigned __int16)v18;
      v21 = HIWORD(v18) - 1LL;
      if ( v19 )
        v22 = v19;
      else
        v22 = "(null)";
      memcpy((void *)(result + (unsigned __int16)v18), v22, HIWORD(v18) - 1LL);
      *(_BYTE *)(v20 + v21) = 0;
      v23 = *(_DWORD *)(v17 + 24);
      v24 = (void *)(v17 + (unsigned __int16)v23);
      if ( v38 )
        v25 = v38;
      else
        v25 = "(null)";
      v26 = HIWORD(v23) - 1LL;
      memcpy(v24, v25, v26);
      *((_BYTE *)v24 + v26) = 0;
      *(_DWORD *)(v17 + 16) = *a5;
      if ( *a5 )
      {
        v27 = 0;
        v28 = (char *)a5 + 6;
        v29 = v17 + *(unsigned __int16 *)(v17 + 28);
        v30 = v17 + *(unsigned __int16 *)(v17 + 32);
        do
        {
          *(_WORD *)(v29 + 2 * v27) = *((_WORD *)v28 - 1);
          v31 = *v28;
          v28 += 4;
          *(_BYTE *)(v30 + v27++) = v31;
        }
        while ( v27 < (unsigned int)*a5 );
      }
      result = perf_trace_run_bpf_submit(v17, v13, v33, a1, 1, v34, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
