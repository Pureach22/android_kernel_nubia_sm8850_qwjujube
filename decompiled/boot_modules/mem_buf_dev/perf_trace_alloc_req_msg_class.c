_DWORD *__fastcall perf_trace_alloc_req_msg_class(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x23
  _DWORD *result; // x0
  __int64 v7; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v9; // w21
  _QWORD *v10; // x9
  int v11; // w11
  int v12; // w8
  _DWORD *v13; // x22
  int v14; // w10
  char *v15; // x23
  const char *v16; // x9
  bool v17; // zf
  __int64 v18; // x24
  const char *v19; // x1
  int v20; // w8
  char *v21; // x23
  const char *v22; // x1
  size_t v23; // x24
  unsigned __int64 v24; // x8
  _BYTE *v25; // x11
  char *v26; // x9
  char *v27; // x10
  char v28; // t1
  __int64 v29; // [xsp+0h] [xbp-60h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-50h] BYREF
  __int64 v32; // [xsp+18h] [xbp-48h] BYREF
  const char *v33; // [xsp+20h] [xbp-40h]
  __int64 v34; // [xsp+28h] [xbp-38h]
  const char *v35; // [xsp+30h] [xbp-30h]
  __int64 v36; // [xsp+38h] [xbp-28h]
  __int64 v37; // [xsp+40h] [xbp-20h]
  __int64 v38; // [xsp+48h] [xbp-18h]
  __int64 v39; // [xsp+50h] [xbp-10h]
  __int64 v40; // [xsp+58h] [xbp-8h]
  __int64 v41; // [xsp+60h] [xbp+0h] BYREF

  v4 = v2;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = nullptr;
  v31 = nullptr;
  v30 = 0;
  result = (_DWORD *)((__int64 (__fastcall *)(__int64 *))trace_event_get_offsets_alloc_req_msg_class)(&v32);
  v7 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    v9 = (((_DWORD)result + 51) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v9, &v31, &v30);
    if ( result )
    {
      v10 = v31;
      v11 = v38;
      v31[31] = &v29;
      v12 = v34;
      v10[29] = &v41;
      v13 = result;
      v10[32] = v4;
      v10[33] = 5;
      v14 = v32;
      LODWORD(v10) = v36;
      result[6] = v12;
      result[3] = v14;
      v15 = (char *)result + (unsigned __int16)v14;
      result[8] = (_DWORD)v10;
      result[9] = v11;
      v16 = v33;
      v17 = v33 == nullptr;
      v18 = HIWORD(v14) - 1LL;
      result[2] = *(_DWORD *)a2;
      if ( v17 )
        v19 = "(null)";
      else
        v19 = v16;
      memcpy((char *)result + (unsigned __int16)v14, v19, HIWORD(v14) - 1LL);
      v15[v18] = 0;
      v20 = v13[6];
      v21 = (char *)v13 + (unsigned __int16)v20;
      if ( v35 )
        v22 = v35;
      else
        v22 = "(null)";
      *((_QWORD *)v13 + 2) = *(_QWORD *)(a2 + 12);
      v23 = HIWORD(v20) - 1LL;
      memcpy(v21, v22, v23);
      v21[v23] = 0;
      v13[7] = *(_DWORD *)(a2 + 28);
      if ( *(_DWORD *)(a2 + 28) )
      {
        v24 = 0;
        v25 = (_BYTE *)(a2 + 34);
        v26 = (char *)v13 + *((unsigned __int16 *)v13 + 16);
        v27 = (char *)v13 + *((unsigned __int16 *)v13 + 18);
        do
        {
          *(_WORD *)&v26[2 * v24] = *((_WORD *)v25 - 1);
          v28 = *v25;
          v25 += 4;
          v27[v24++] = v28;
        }
        while ( v24 < *(unsigned int *)(a2 + 28) );
      }
      result = (_DWORD *)perf_trace_run_bpf_submit(v13, v9, v30, a1, 1, v31, StatusReg + v7, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
