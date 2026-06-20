__int64 __fastcall trace_event_raw_event_local_chanctx(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  const char *v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x14
  __int64 v23; // d20
  __int64 v24; // d21
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v5 & 0x2C0) != 0 && (v5 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_31;
  }
  result = trace_event_buffer_reserve(v25);
  if ( !result )
    goto LABEL_31;
  v7 = *(_QWORD *)(a2 + 72);
  v8 = result;
  v9 = *(const char **)(v7 + 504);
  if ( !v9 )
    v9 = *(const char **)(v7 + 392);
  v10 = strnlen(v9, 0x20u);
  if ( v10 == -1 )
  {
    _fortify_panic(2);
    goto LABEL_36;
  }
  if ( v10 == 32 )
    v11 = 32;
  else
    v11 = v10 + 1;
  if ( v11 >= 0x21 )
  {
LABEL_36:
    _fortify_panic(7);
    *(_QWORD *)(v22 + 104) = v23;
    *(_QWORD *)(v22 + 112) = v24;
    JUMPOUT(0x924B8);
  }
  sized_strscpy(v8 + 8, v9);
  v12 = *(_QWORD *)(a3 + 152);
  if ( v12 )
    LODWORD(v12) = *(_DWORD *)(v12 + 4);
  *(_DWORD *)(v8 + 40) = v12;
  v13 = *(_QWORD *)(a3 + 152);
  if ( v13 )
    LODWORD(v13) = *(unsigned __int16 *)(v13 + 8);
  *(_DWORD *)(v8 + 44) = v13;
  *(_DWORD *)(v8 + 48) = *(_DWORD *)(a3 + 160);
  *(_DWORD *)(v8 + 52) = *(_DWORD *)(a3 + 164);
  *(_DWORD *)(v8 + 56) = *(unsigned __int16 *)(a3 + 180);
  *(_DWORD *)(v8 + 60) = *(_DWORD *)(a3 + 168);
  v14 = *(_QWORD *)(a3 + 184);
  if ( v14 )
    LODWORD(v14) = *(_DWORD *)(v14 + 4);
  *(_DWORD *)(v8 + 64) = v14;
  v15 = *(_QWORD *)(a3 + 184);
  if ( v15 )
    LODWORD(v15) = *(unsigned __int16 *)(v15 + 8);
  *(_DWORD *)(v8 + 68) = v15;
  *(_DWORD *)(v8 + 72) = *(_DWORD *)(a3 + 192);
  *(_DWORD *)(v8 + 76) = *(_DWORD *)(a3 + 196);
  *(_DWORD *)(v8 + 80) = *(unsigned __int16 *)(a3 + 212);
  *(_DWORD *)(v8 + 84) = *(_DWORD *)(a3 + 200);
  v16 = *(_QWORD *)(a3 + 216);
  if ( v16 )
    LODWORD(v16) = *(_DWORD *)(v16 + 4);
  *(_DWORD *)(v8 + 88) = v16;
  v17 = *(_QWORD *)(a3 + 216);
  if ( v17 )
    LODWORD(v17) = *(unsigned __int16 *)(v17 + 8);
  *(_DWORD *)(v8 + 92) = v17;
  v18 = *(_QWORD *)(a3 + 216);
  if ( v18 )
    LODWORD(v18) = *(_DWORD *)(a3 + 224);
  *(_DWORD *)(v8 + 96) = v18;
  v19 = *(_QWORD *)(a3 + 216);
  if ( v19 )
    LODWORD(v19) = *(_DWORD *)(a3 + 228);
  *(_DWORD *)(v8 + 100) = v19;
  v20 = *(_QWORD *)(a3 + 216);
  if ( v20 )
    LODWORD(v20) = *(unsigned __int16 *)(a3 + 244);
  *(_DWORD *)(v8 + 104) = v20;
  v21 = *(_QWORD *)(a3 + 216);
  if ( v21 )
    LODWORD(v21) = *(_DWORD *)(a3 + 232);
  *(_DWORD *)(v8 + 108) = v21;
  *(_BYTE *)(v8 + 112) = *(_BYTE *)(a3 + 252);
  *(_BYTE *)(v8 + 113) = *(_BYTE *)(a3 + 253);
  result = trace_event_buffer_commit(v25);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
