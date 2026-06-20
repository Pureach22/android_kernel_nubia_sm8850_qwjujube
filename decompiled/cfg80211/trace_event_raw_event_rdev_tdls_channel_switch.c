// positive sp value has been detected, the output may be wrong!
__int64 __fastcall trace_event_raw_event_rdev_tdls_channel_switch(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int *a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v10; // x8
  __int64 result; // x0
  const char *v12; // x24
  __int64 v13; // x21
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  int v17; // w9
  _BYTE v18[48]; // [xsp-78h] [xbp-B8h] BYREF
  __int64 v19; // [xsp-48h] [xbp-88h]
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, sizeof(v18));
  if ( (v10 & 0x2C0) == 0 || (v10 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v18);
    if ( result )
    {
      v12 = *(const char **)(a2 + 504);
      v13 = result;
      if ( !v12 )
        v12 = *(const char **)(a2 + 392);
      v14 = strnlen(v12, 0x20u);
      if ( v14 == -1 )
        JUMPOUT(0x9EBA8);
      if ( v14 == 32 )
        v15 = 32;
      else
        v15 = v14 + 1;
      if ( v15 >= 0x21 )
        JUMPOUT(0x9EBB8);
      sized_strscpy(v13 + 8, v12);
      v16 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v13 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v13 + 48) = v16;
      *(_DWORD *)(v13 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 )
      {
        v17 = *a4;
        *(_WORD *)(v13 + 64) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v13 + 60) = v17;
        if ( !a6 )
          goto LABEL_16;
      }
      else
      {
        *(_WORD *)(v13 + 64) = 0;
        *(_DWORD *)(v13 + 60) = 0;
        if ( !a6 )
          goto LABEL_16;
      }
      if ( *(_QWORD *)a6 )
      {
        *(_DWORD *)(v13 + 68) = **(_DWORD **)a6;
        *(_DWORD *)(v13 + 72) = *(_DWORD *)(*(_QWORD *)a6 + 4LL);
        *(_DWORD *)(v13 + 76) = *(unsigned __int16 *)(*(_QWORD *)a6 + 8LL);
        *(_DWORD *)(v13 + 80) = *(_DWORD *)(a6 + 8);
        *(_DWORD *)(v13 + 84) = *(_DWORD *)(a6 + 12);
        *(_DWORD *)(v13 + 88) = *(unsigned __int16 *)(a6 + 28);
        *(_DWORD *)(v13 + 92) = *(_DWORD *)(a6 + 16);
        *(_WORD *)(v13 + 96) = *(_WORD *)(a6 + 30);
LABEL_17:
        result = trace_event_buffer_commit(&v20);
        goto LABEL_18;
      }
LABEL_16:
      *(_QWORD *)(v13 + 90) = 0;
      *(_QWORD *)(v13 + 84) = 0;
      *(_QWORD *)(v13 + 76) = 0;
      *(_QWORD *)(v13 + 68) = 0;
      goto LABEL_17;
    }
  }
LABEL_18:
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) != v19 )
    JUMPOUT(0x9EBA4);
  return result;
}
