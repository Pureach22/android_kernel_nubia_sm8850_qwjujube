__int64 __fastcall trace_event_raw_event_drv_get_ringparam(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6)
{
  int v6; // s13
  __int64 v12; // x8
  __int64 result; // x0
  __int64 v14; // x8
  _DWORD *v15; // x23
  __int64 v16; // x24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  int v19; // s0
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v12 & 0x2C0) == 0 || (v12 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20);
    if ( result )
    {
      v14 = *(_QWORD *)(a2 + 72);
      v15 = (_DWORD *)result;
      v16 = *(_QWORD *)(v14 + 504);
      if ( !v16 )
        v16 = *(_QWORD *)(v14 + 392);
      v17 = strnlen((const char *)v16, 0x20u);
      if ( v17 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v17 == 32 )
          v18 = 32;
        else
          v18 = v17 + 1;
        if ( v18 < 0x21 )
        {
          sized_strscpy(v15 + 2, v16);
          v15[10] = *a3;
          v15[11] = *a4;
          v15[12] = *a5;
          v15[13] = *a6;
          result = trace_event_buffer_commit(v20);
          goto LABEL_11;
        }
      }
      _fortify_panic(7);
      *(_DWORD *)(v16 + 136) = v19;
      *(_DWORD *)(v16 + 140) = v6;
      JUMPOUT(0x91094);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
