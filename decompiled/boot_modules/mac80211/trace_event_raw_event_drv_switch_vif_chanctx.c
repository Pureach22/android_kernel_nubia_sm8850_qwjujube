__int64 __fastcall trace_event_raw_event_drv_switch_vif_chanctx(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v6; // x20
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x22
  __int64 v12; // x8
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 *v16; // x19
  _DWORD *v17; // x21
  const char *v18; // x8
  __int64 v19; // t1
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  LODWORD(v6) = a4;
  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v20);
  if ( !result )
    goto LABEL_14;
  v11 = result;
  *(_DWORD *)(result + 48) = (4784128 * v6) | 0x34;
  v12 = *(_QWORD *)(a2 + 72);
  v13 = *(const char **)(v12 + 504);
  if ( !v13 )
    v13 = *(const char **)(v12 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2);
    goto LABEL_19;
  }
  if ( v14 == 32 )
    v15 = 32;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x21 )
  {
LABEL_19:
    _fortify_panic(7);
    JUMPOUT(0x92D88);
  }
  sized_strscpy(v11 + 8, v13);
  *(_DWORD *)(v11 + 40) = v6;
  *(_DWORD *)(v11 + 44) = a5;
  if ( (int)v6 >= 1 )
  {
    v6 = (unsigned int)v6;
    v16 = (__int64 *)(a3 + 24);
    v17 = (_DWORD *)(*(unsigned __int16 *)(v11 + 48) + v11 + 37);
    do
    {
      v18 = (const char *)*(v16 - 3);
      *(_DWORD *)((char *)v17 - 37) = *(_DWORD *)v18;
      *((_BYTE *)v17 - 33) = *(_BYTE *)(*(v16 - 3) + 1128);
      *(v17 - 4) = *(_DWORD *)(*(v16 - 2) + 24);
      strncpy((char *)v17 - 32, v18 - 3080, 0x10u);
      --v6;
      *(v17 - 3) = *(_DWORD *)(*(_QWORD *)*(v16 - 1) + 4LL);
      *(v17 - 2) = *(unsigned __int16 *)(*(_QWORD *)*(v16 - 1) + 8LL);
      *(v17 - 1) = *(_DWORD *)(*(v16 - 1) + 8);
      *v17 = *(_DWORD *)(*(v16 - 1) + 12);
      v17[1] = *(unsigned __int16 *)(*(v16 - 1) + 28);
      v17[2] = *(_DWORD *)(*(v16 - 1) + 16);
      v17[3] = *(_DWORD *)(*(_QWORD *)*v16 + 4LL);
      v17[4] = *(unsigned __int16 *)(*(_QWORD *)*v16 + 8LL);
      v17[5] = *(_DWORD *)(*v16 + 8);
      v17[6] = *(_DWORD *)(*v16 + 12);
      v17[7] = *(unsigned __int16 *)(*v16 + 28);
      v19 = *v16;
      v16 += 4;
      v17[8] = *(_DWORD *)(v19 + 16);
      v17 = (_DWORD *)((char *)v17 + 73);
    }
    while ( v6 );
  }
  result = trace_event_buffer_commit(v20);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
