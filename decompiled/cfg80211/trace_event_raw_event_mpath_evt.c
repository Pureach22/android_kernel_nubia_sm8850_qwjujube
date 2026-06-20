__int64 __fastcall trace_event_raw_event_mpath_evt(__int64 a1, __int64 a2, __int64 a3, int *a4, int *a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  __int64 v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x8
  int v16; // w9
  int v17; // w9
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v18);
    if ( result )
    {
      v11 = *(const char **)(a2 + 504);
      v12 = result;
      if ( !v11 )
        v11 = *(const char **)(a2 + 392);
      v13 = strnlen(v11, 0x20u);
      if ( v13 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v13 == 32 )
          v14 = 32;
        else
          v14 = v13 + 1;
        if ( v14 < 0x21 )
        {
          sized_strscpy(v12 + 8, v11);
          v15 = *(_QWORD *)(a3 + 304);
          *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v12 + 48) = v15;
          *(_DWORD *)(v12 + 56) = *(_DWORD *)(a3 + 224);
          if ( a4 )
          {
            v16 = *a4;
            *(_WORD *)(v12 + 64) = *((_WORD *)a4 + 2);
            *(_DWORD *)(v12 + 60) = v16;
            if ( a5 )
            {
LABEL_12:
              v17 = *a5;
              *(_WORD *)(v12 + 70) = *((_WORD *)a5 + 2);
              *(_DWORD *)(v12 + 66) = v17;
LABEL_15:
              result = trace_event_buffer_commit(v18);
              goto LABEL_16;
            }
          }
          else
          {
            *(_WORD *)(v12 + 64) = 0;
            *(_DWORD *)(v12 + 60) = 0;
            if ( a5 )
              goto LABEL_12;
          }
          *(_WORD *)(v12 + 70) = 0;
          *(_DWORD *)(v12 + 66) = 0;
          goto LABEL_15;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x92A48);
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
