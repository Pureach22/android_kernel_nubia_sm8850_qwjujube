__int64 __fastcall trace_event_raw_event_rdev_assoc(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v7; // x8
  int v8; // w24
  int v9; // w23
  int v10; // w25
  __int64 result; // x0
  __int64 v12; // x20
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  __int64 v17; // x8
  __int16 v18; // w9
  int v19; // w8
  int *v20; // x8
  __int16 v21; // w9
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 *v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11
  _QWORD *v34; // x9
  __int64 v35; // x8
  __int64 v36; // x12
  _QWORD v37[7]; // [xsp+8h] [xbp-38h] BYREF

  v37[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v37, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_22;
  }
  v8 = *((_DWORD *)a4 + 6);
  v9 = *((_DWORD *)a4 + 64);
  v10 = 32 * (a4[33] != 0);
  result = trace_event_buffer_reserve(v37);
  if ( !result )
    goto LABEL_22;
  v12 = result;
  *(_DWORD *)(result + 80) = (v8 << 16) | 0xA8;
  *(_DWORD *)(result + 160) = (v8 + 168) | (v9 << 16);
  *(_DWORD *)(result + 164) = (v9 + v8 + 168) | (v10 << 16);
  v13 = *(const char **)(a2 + 504);
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_27;
  }
  if ( v14 == 32 )
    v15 = 32;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x21 )
  {
LABEL_27:
    _fortify_panic(7, 32);
    if ( (a3 & 0x200000000000000LL) != 0 )
      JUMPOUT(0x958CC);
    JUMPOUT(0x967F0);
  }
  sized_strscpy(v12 + 8, v13);
  v16 = *(_QWORD *)(a3 + 304);
  *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
  *(_QWORD *)(v12 + 48) = v16;
  *(_DWORD *)(v12 + 56) = *(_DWORD *)(a3 + 224);
  v17 = *a4;
  if ( !*a4 )
  {
    *(_WORD *)(v12 + 64) = 0;
    *(_DWORD *)(v12 + 60) = 0;
    v20 = (int *)a4[2];
    if ( v20 )
      goto LABEL_12;
LABEL_14:
    *(_WORD *)(v12 + 70) = 0;
    *(_DWORD *)(v12 + 66) = 0;
    goto LABEL_15;
  }
  v18 = *(_WORD *)(v17 + 76);
  v19 = *(_DWORD *)(v17 + 72);
  *(_WORD *)(v12 + 64) = v18;
  *(_DWORD *)(v12 + 60) = v19;
  v20 = (int *)a4[2];
  if ( !v20 )
    goto LABEL_14;
LABEL_12:
  v21 = *((_WORD *)v20 + 2);
  v22 = *v20;
  *(_WORD *)(v12 + 70) = v21;
  *(_DWORD *)(v12 + 66) = v22;
LABEL_15:
  *(_BYTE *)(v12 + 72) = *((_BYTE *)a4 + 152);
  *(_DWORD *)(v12 + 76) = *((_DWORD *)a4 + 39);
  if ( a4[1] )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 80)), (const void *)a4[1], a4[3]);
  v23 = *(__int64 *)((char *)a4 + 185);
  v24 = *(__int64 *)((char *)a4 + 169);
  v25 = *(__int64 *)((char *)a4 + 177);
  *(_WORD *)(v12 + 108) = *(_WORD *)((char *)a4 + 193);
  *(_QWORD *)(v12 + 100) = v23;
  *(_QWORD *)(v12 + 92) = v25;
  *(_QWORD *)(v12 + 84) = v24;
  v26 = *(__int64 *)((char *)a4 + 211);
  v27 = *(__int64 *)((char *)a4 + 195);
  v28 = *(__int64 *)((char *)a4 + 203);
  *(_WORD *)(v12 + 134) = *(_WORD *)((char *)a4 + 219);
  *(_QWORD *)(v12 + 126) = v26;
  *(_QWORD *)(v12 + 118) = v28;
  *(_QWORD *)(v12 + 110) = v27;
  v29 = *(__int64 *)((char *)a4 + 221);
  *(_DWORD *)(v12 + 144) = *(_DWORD *)((char *)a4 + 229);
  *(_QWORD *)(v12 + 136) = v29;
  v30 = *(__int64 *)((char *)a4 + 233);
  *(_DWORD *)(v12 + 156) = *(_DWORD *)((char *)a4 + 241);
  *(_QWORD *)(v12 + 148) = v30;
  if ( a4[31] )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 160)), (const void *)a4[31], a4[32]);
  if ( a4[33] )
  {
    v31 = (__int64 *)a4[33];
    v33 = v31[2];
    v32 = v31[3];
    v34 = (_QWORD *)(v12 + *(unsigned __int16 *)(v12 + 164));
    v36 = *v31;
    v35 = v31[1];
    v34[2] = v33;
    v34[3] = v32;
    *v34 = v36;
    v34[1] = v35;
  }
  result = trace_event_buffer_commit(v37);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
