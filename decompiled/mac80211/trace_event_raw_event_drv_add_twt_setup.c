__int64 __fastcall trace_event_raw_event_drv_add_twt_setup(__int64 a1, __int64 a2, int *a3, _BYTE *a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x22
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  int v16; // w9
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17);
    if ( result )
    {
      v11 = *(_QWORD *)(a2 + 72);
      v12 = result;
      v13 = *(const char **)(v11 + 504);
      if ( !v13 )
        v13 = *(const char **)(v11 + 392);
      v14 = strnlen(v13, 0x20u);
      if ( v14 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v14 == 32 )
          v15 = 32;
        else
          v15 = v14 + 1;
        if ( v15 < 0x21 )
        {
          sized_strscpy(v12 + 8, v13);
          if ( a3 )
          {
            v16 = *a3;
            *(_WORD *)(v12 + 44) = *((_WORD *)a3 + 2);
            *(_DWORD *)(v12 + 40) = v16;
          }
          else
          {
            *(_WORD *)(v12 + 44) = 0;
            *(_DWORD *)(v12 + 40) = 0;
          }
          *(_BYTE *)(v12 + 46) = *a4;
          *(_BYTE *)(v12 + 47) = a4[3];
          *(_WORD *)(v12 + 48) = *(_WORD *)a5;
          *(_QWORD *)(v12 + 56) = *(_QWORD *)(a5 + 2);
          *(_BYTE *)(v12 + 64) = *(_BYTE *)(a5 + 10);
          *(_WORD *)(v12 + 66) = *(_WORD *)(a5 + 11);
          *(_BYTE *)(v12 + 68) = *(_BYTE *)(a5 + 13);
          result = trace_event_buffer_commit(v17);
          goto LABEL_14;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x977F8);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
