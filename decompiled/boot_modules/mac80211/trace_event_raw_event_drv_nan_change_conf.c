__int64 __fastcall trace_event_raw_event_drv_nan_change_conf(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  int v5; // w25
  __int64 v10; // x8
  int v11; // w24
  __int64 result; // x0
  __int64 v13; // x22
  __int64 v14; // x8
  const char *v15; // x23
  size_t v16; // x0
  unsigned __int64 v17; // x2
  int v18; // w9
  int v19; // w8
  void *v20; // x23
  size_t v21; // x24
  char v22; // w8
  int v23; // w10
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v10 & 0x2C0) == 0 || (v10 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v11 = strlen((const char *)(a3 + 1640)) + 1;
    result = trace_event_buffer_reserve(v24);
    if ( result )
    {
      v13 = result;
      *(_DWORD *)(result + 60) = (v11 << 16) | 0x48;
      v14 = *(_QWORD *)(a2 + 72);
      v15 = *(const char **)(v14 + 504);
      if ( !v15 )
        v15 = *(const char **)(v14 + 392);
      v16 = strnlen(v15, 0x20u);
      if ( v16 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v16 == 32 )
          v17 = 32;
        else
          v17 = v16 + 1;
        if ( v17 < 0x21 )
        {
          sized_strscpy(v13 + 8, v15);
          v18 = *(_DWORD *)(v13 + 60);
          v19 = *(_DWORD *)(a3 + 4720);
          *(_QWORD *)(v13 + 48) = a3;
          *(_DWORD *)(v13 + 40) = v19;
          v20 = (void *)(v13 + (unsigned __int16)v18);
          v21 = HIWORD(v18) - 1LL;
          *(_BYTE *)(v13 + 56) = *(_BYTE *)(a3 + 5848);
          memcpy(v20, (const void *)(a3 + 1640), v21);
          *((_BYTE *)v20 + v21) = 0;
          *(_BYTE *)(v13 + 64) = *(_BYTE *)a4;
          v22 = *(_BYTE *)(a4 + 1);
          *(_DWORD *)(v13 + 68) = a5;
          *(_BYTE *)(v13 + 65) = v22;
          result = trace_event_buffer_commit(v24);
          goto LABEL_11;
        }
      }
      _fortify_panic(7);
      *(_DWORD *)(a4 + 144) = v23;
      *(_DWORD *)(a4 + 148) = v5;
      JUMPOUT(0x94C9C);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
