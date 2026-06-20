__int64 __fastcall trace_event_raw_event_drv_stop_ap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x8
  const char *v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w9
  int v16; // w8
  void *v17; // x22
  size_t v18; // x23
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v8 = strlen((const char *)(a3 + 1640)) + 1;
    result = trace_event_buffer_reserve(v19);
    if ( result )
    {
      v10 = result;
      *(_DWORD *)(result + 60) = (v8 << 16) | 0x44;
      v11 = *(_QWORD *)(a2 + 72);
      v12 = *(const char **)(v11 + 504);
      if ( !v12 )
        v12 = *(const char **)(v11 + 392);
      v13 = strnlen(v12, 0x20u);
      if ( v13 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v13 == 32 )
          v14 = 32;
        else
          v14 = v13 + 1;
        if ( v14 < 0x21 )
        {
          sized_strscpy(v10 + 8, v12);
          v15 = *(_DWORD *)(v10 + 60);
          v16 = *(_DWORD *)(a3 + 4720);
          *(_QWORD *)(v10 + 48) = a3;
          *(_DWORD *)(v10 + 40) = v16;
          v17 = (void *)(v10 + (unsigned __int16)v15);
          v18 = HIWORD(v15) - 1LL;
          *(_BYTE *)(v10 + 56) = *(_BYTE *)(a3 + 5848);
          memcpy(v17, (const void *)(a3 + 1640), v18);
          *((_BYTE *)v17 + v18) = 0;
          *(_DWORD *)(v10 + 64) = *(_DWORD *)(a4 + 24);
          result = trace_event_buffer_commit(v19);
          goto LABEL_11;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x93AB8);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
