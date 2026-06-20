__int64 __fastcall trace_event_raw_event_rdev_change_beacon(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  int v6; // w26
  int v7; // w27
  int v8; // w25
  int v9; // w28
  int v10; // w21
  __int64 result; // x0
  __int64 v12; // x20
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  int v18; // [xsp+8h] [xbp-48h]
  int v19; // [xsp+Ch] [xbp-44h]
  _QWORD v21[7]; // [xsp+18h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v5 & 0x2C0) != 0 && (v5 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_23;
  }
  v6 = *(_DWORD *)(a4 + 96);
  v7 = *(_DWORD *)(a4 + 104);
  v8 = *(_DWORD *)(a4 + 128);
  v9 = *(_DWORD *)(a4 + 136);
  v10 = v7 + v6 + *(_DWORD *)(a4 + 112);
  v18 = *(_DWORD *)(a4 + 120);
  v19 = *(_DWORD *)(a4 + 112);
  result = trace_event_buffer_reserve(v21);
  if ( !result )
    goto LABEL_23;
  *(_DWORD *)(result + 64) = (v6 << 16) | 0x58;
  *(_DWORD *)(result + 68) = (v6 + 88) | (v7 << 16);
  v12 = result;
  *(_DWORD *)(result + 80) = (v10 + v18 + 88) | (v8 << 16);
  *(_DWORD *)(result + 84) = (v10 + v18 + v8 + 88) | (v9 << 16);
  *(_DWORD *)(result + 72) = (v7 + v6 + 88) | (v19 << 16);
  *(_DWORD *)(result + 76) = (v10 + 88) | (v18 << 16);
  v13 = *(const char **)(a2 + 504);
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_28;
  }
  if ( v14 == 32 )
    v15 = 32;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x21 )
  {
LABEL_28:
    _fortify_panic(7, 32);
    JUMPOUT(0x90C78);
  }
  sized_strscpy(v12 + 8, v13);
  v16 = *(_QWORD *)(a3 + 304);
  *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
  *(_QWORD *)(v12 + 48) = v16;
  *(_DWORD *)(v12 + 56) = *(_DWORD *)(a3 + 224);
  *(_DWORD *)(v12 + 60) = *(_DWORD *)a4;
  if ( *(_QWORD *)(a4 + 8) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 64)), *(const void **)(a4 + 8), *(_QWORD *)(a4 + 96));
  if ( *(_QWORD *)(a4 + 16) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 68)), *(const void **)(a4 + 16), *(_QWORD *)(a4 + 104));
  if ( *(_QWORD *)(a4 + 24) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 72)), *(const void **)(a4 + 24), *(_QWORD *)(a4 + 112));
  if ( *(_QWORD *)(a4 + 32) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 76)), *(const void **)(a4 + 32), *(_QWORD *)(a4 + 120));
  if ( *(_QWORD *)(a4 + 40) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 80)), *(const void **)(a4 + 40), *(_QWORD *)(a4 + 128));
  if ( *(_QWORD *)(a4 + 48) )
    memcpy((void *)(v12 + *(unsigned __int16 *)(v12 + 84)), *(const void **)(a4 + 48), *(_QWORD *)(a4 + 136));
  result = trace_event_buffer_commit(v21);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
