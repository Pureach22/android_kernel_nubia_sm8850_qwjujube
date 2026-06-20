__int64 __fastcall trace_event_raw_event_link_station_add_mod(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v7; // x8
  int v8; // w23
  int v9; // w25
  int v10; // w24
  __int64 result; // x0
  __int64 v12; // x20
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  int v17; // w10
  int *v18; // x10
  __int16 v19; // w11
  int v20; // w10
  int *v21; // x9
  __int16 v22; // w10
  int v23; // w9
  __int64 *v24; // x9
  __int16 v25; // w10
  __int64 v26; // x12
  __int64 v27; // x9
  __int64 v28; // x11
  __int64 *v29; // t2
  __int64 *v30; // x9
  int v31; // w10
  __int64 v32; // x9
  _WORD *v33; // x8
  _QWORD v34[7]; // [xsp+8h] [xbp-38h] BYREF

  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v34, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_30;
  }
  v8 = *((unsigned __int8 *)a4 + 32);
  v9 = *((unsigned __int8 *)a4 + 72);
  v10 = *((unsigned __int8 *)a4 + 104);
  result = trace_event_buffer_reserve(v34);
  if ( !result )
    goto LABEL_30;
  v12 = result;
  *(_DWORD *)(result + 120) = (v8 + 132) | (v9 << 16);
  *(_DWORD *)(result + 76) = (v8 << 16) | 0x84;
  *(_DWORD *)(result + 128) = (v8 + 132 + v9) | (v10 << 16);
  v13 = *(const char **)(a2 + 504);
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_35;
  }
  if ( v14 == 32 )
    v15 = 32;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x21 )
  {
LABEL_35:
    _fortify_panic(7, 32);
    JUMPOUT(0xA9AA0);
  }
  sized_strscpy(v12 + 8, v13);
  v16 = *(_QWORD *)(a3 + 304);
  *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
  *(_QWORD *)(v12 + 48) = v16;
  v17 = *(_DWORD *)(a3 + 224);
  *(_DWORD *)(v12 + 60) = 0;
  *(_WORD *)(v12 + 64) = 0;
  *(_DWORD *)(v12 + 66) = 0;
  *(_DWORD *)(v12 + 56) = v17;
  *(_WORD *)(v12 + 70) = 0;
  v18 = (int *)*a4;
  if ( *a4 )
  {
    v19 = *((_WORD *)v18 + 2);
    v20 = *v18;
    *(_WORD *)(v12 + 64) = v19;
    *(_DWORD *)(v12 + 60) = v20;
  }
  v21 = (int *)a4[2];
  if ( v21 )
  {
    v22 = *((_WORD *)v21 + 2);
    v23 = *v21;
    *(_WORD *)(v12 + 70) = v22;
    *(_DWORD *)(v12 + 66) = v23;
  }
  *(_DWORD *)(v12 + 72) = *((_DWORD *)a4 + 2);
  if ( a4[3] && *((_BYTE *)a4 + 32) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 76)), (const void *)a4[3], *((unsigned __int8 *)a4 + 32));
  *(_QWORD *)(v12 + 80) = 0;
  *(_WORD *)(v12 + 104) = 0;
  *(_QWORD *)(v12 + 88) = 0;
  *(_QWORD *)(v12 + 96) = 0;
  v24 = (__int64 *)a4[5];
  if ( v24 )
  {
    v25 = *((_WORD *)v24 + 12);
    v26 = *v24;
    v29 = v24 + 1;
    v27 = v24[1];
    v28 = v29[1];
    *(_WORD *)(v12 + 104) = v25;
    *(_QWORD *)(v12 + 80) = v26;
    *(_QWORD *)(v12 + 88) = v27;
    *(_QWORD *)(v12 + 96) = v28;
  }
  *(_QWORD *)(v12 + 106) = 0;
  *(_DWORD *)(v12 + 114) = 0;
  v30 = (__int64 *)a4[6];
  if ( v30 )
  {
    v31 = *((_DWORD *)v30 + 2);
    v32 = *v30;
    *(_DWORD *)(v12 + 114) = v31;
    *(_QWORD *)(v12 + 106) = v32;
  }
  *(_BYTE *)(v12 + 118) = *((_BYTE *)a4 + 56);
  *(_BYTE *)(v12 + 119) = *((_BYTE *)a4 + 57);
  if ( a4[8] && *((_BYTE *)a4 + 72) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 120)), (const void *)a4[8], *((unsigned __int8 *)a4 + 72));
  *(_WORD *)(v12 + 124) = 0;
  v33 = (_WORD *)a4[11];
  if ( v33 )
    *(_WORD *)(v12 + 124) = *v33;
  if ( a4[12] && *((_BYTE *)a4 + 104) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 128)), (const void *)a4[12], *((unsigned __int8 *)a4 + 104));
  result = trace_event_buffer_commit(v34);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
