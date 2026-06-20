__int64 __fastcall trace_event_raw_event_drv_get_ftm_responder_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x8
  const char *v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  int v13; // w8
  int v14; // w9
  void *v15; // x21
  size_t v16; // x20
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v6 = strlen((const char *)(a3 + 1640)) + 1;
    result = trace_event_buffer_reserve(v17);
    if ( result )
    {
      v8 = result;
      *(_DWORD *)(result + 60) = (v6 << 16) | 0x40;
      v9 = *(_QWORD *)(a2 + 72);
      v10 = *(const char **)(v9 + 504);
      if ( !v10 )
        v10 = *(const char **)(v9 + 392);
      v11 = strnlen(v10, 0x20u);
      if ( v11 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v11 == 32 )
          v12 = 32;
        else
          v12 = v11 + 1;
        if ( v12 < 0x21 )
        {
          sized_strscpy(v8 + 8, v10);
          v13 = *(_DWORD *)(a3 + 4720);
          v14 = *(_DWORD *)(v8 + 60);
          *(_QWORD *)(v8 + 48) = a3;
          *(_DWORD *)(v8 + 40) = v13;
          v15 = (void *)(v8 + (unsigned __int16)v14);
          *(_BYTE *)(v8 + 56) = *(_BYTE *)(a3 + 5848);
          v16 = HIWORD(v14) - 1LL;
          memcpy(v15, (const void *)(a3 + 1640), v16);
          *((_BYTE *)v15 + v16) = 0;
          result = trace_event_buffer_commit(v17);
          goto LABEL_11;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x97120);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
