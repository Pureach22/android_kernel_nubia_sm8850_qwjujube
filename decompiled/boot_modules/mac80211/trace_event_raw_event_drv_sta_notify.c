__int64 __fastcall trace_event_raw_event_drv_sta_notify(__int64 a1, __int64 a2, __int64 a3, int a4, int *a5)
{
  __int64 v9; // x8
  int v10; // w24
  __int64 result; // x0
  __int64 v12; // x22
  __int64 v13; // x8
  const char *v14; // x23
  size_t v15; // x0
  unsigned __int64 v16; // x2
  int v17; // w9
  int v18; // w8
  void *v19; // x23
  size_t v20; // x24
  int v21; // w9
  _QWORD v22[7]; // [xsp+8h] [xbp-38h] BYREF

  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v10 = strlen((const char *)(a3 + 1640)) + 1;
    result = trace_event_buffer_reserve(v22);
    if ( result )
    {
      v12 = result;
      *(_DWORD *)(result + 60) = (v10 << 16) | 0x4C;
      v13 = *(_QWORD *)(a2 + 72);
      v14 = *(const char **)(v13 + 504);
      if ( !v14 )
        v14 = *(const char **)(v13 + 392);
      v15 = strnlen(v14, 0x20u);
      if ( v15 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v15 == 32 )
          v16 = 32;
        else
          v16 = v15 + 1;
        if ( v16 < 0x21 )
        {
          sized_strscpy(v12 + 8, v14);
          v17 = *(_DWORD *)(v12 + 60);
          v18 = *(_DWORD *)(a3 + 4720);
          *(_QWORD *)(v12 + 48) = a3;
          *(_DWORD *)(v12 + 40) = v18;
          v19 = (void *)(v12 + (unsigned __int16)v17);
          v20 = HIWORD(v17) - 1LL;
          *(_BYTE *)(v12 + 56) = *(_BYTE *)(a3 + 5848);
          memcpy(v19, (const void *)(a3 + 1640), v20);
          *((_BYTE *)v19 + v20) = 0;
          if ( a5 )
          {
            v21 = *a5;
            *(_WORD *)(v12 + 68) = *((_WORD *)a5 + 2);
            *(_DWORD *)(v12 + 64) = v21;
          }
          else
          {
            *(_WORD *)(v12 + 68) = 0;
            *(_DWORD *)(v12 + 64) = 0;
          }
          *(_DWORD *)(v12 + 72) = a4;
          result = trace_event_buffer_commit(v22);
          goto LABEL_14;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x8DD24);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
