__int64 __fastcall trace_event_raw_event_rdev_get_ftm_responder_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v14);
    if ( result )
    {
      v9 = *(const char **)(a2 + 504);
      v10 = result;
      if ( !v9 )
        v9 = *(const char **)(a2 + 392);
      v11 = strnlen(v9, 0x20u);
      if ( v11 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v11 == 32 )
          v12 = 32;
        else
          v12 = v11 + 1;
        if ( v12 < 0x21 )
        {
          sized_strscpy(v10 + 8, v9);
          v13 = *(_QWORD *)(a3 + 304);
          *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v10 + 48) = v13;
          *(_DWORD *)(v10 + 56) = *(_DWORD *)(a3 + 224);
          *(_DWORD *)(v10 + 72) = *(_DWORD *)(a4 + 4);
          *(_DWORD *)(v10 + 76) = *(_DWORD *)(a4 + 8);
          *(_DWORD *)(v10 + 80) = *(_DWORD *)(a4 + 12);
          *(_DWORD *)(v10 + 84) = *(_DWORD *)(a4 + 16);
          *(_DWORD *)(v10 + 88) = *(_DWORD *)(a4 + 20);
          *(_QWORD *)(v10 + 96) = *(_QWORD *)(a4 + 24);
          *(_DWORD *)(v10 + 104) = *(_DWORD *)(a4 + 32);
          *(_DWORD *)(v10 + 108) = *(_DWORD *)(a4 + 36);
          *(_DWORD *)(v10 + 112) = *(_DWORD *)(a4 + 40);
          result = trace_event_buffer_commit(v14);
          goto LABEL_11;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0xA077C);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
