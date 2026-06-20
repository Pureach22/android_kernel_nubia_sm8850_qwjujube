__int64 __fastcall trace_event_raw_event_adreno_hw_fence_query(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v9; // x8
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  __int64 v13; // x22
  const char *v14; // x10
  void *v15; // x19
  __int64 v16; // x20
  const char *v17; // x1
  int v18; // w8
  void *v19; // x19
  const char *v20; // x1
  size_t v21; // x20
  __int64 v22; // [xsp+8h] [xbp-68h]
  __int64 v23; // [xsp+10h] [xbp-60h]
  _QWORD v24[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v25; // [xsp+48h] [xbp-28h] BYREF
  const char *v26; // [xsp+50h] [xbp-20h]
  __int64 v27; // [xsp+58h] [xbp-18h]
  const char *v28; // [xsp+60h] [xbp-10h]
  __int64 v29; // [xsp+68h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, sizeof(v24));
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v22 = a5, v23 = a6, result = _trace_trigger_soft_disabled(a1), a5 = v22, a6 = v23, (result & 1) == 0) )
  {
    v27 = 0;
    v28 = nullptr;
    v25 = 0;
    v26 = nullptr;
    trace_event_get_offsets_adreno_hw_fence_query(&v25, a5, a6);
    result = trace_event_buffer_reserve(v24);
    if ( result )
    {
      v11 = v25;
      v12 = v27;
      v13 = result;
      v14 = v26;
      *(_DWORD *)(result + 24) = a4;
      *(_DWORD *)(result + 28) = v11;
      *(_DWORD *)(result + 32) = v12;
      v15 = (void *)(result + (unsigned __int16)v11);
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      v16 = HIWORD(v11) - 1LL;
      if ( v14 )
        v17 = v14;
      else
        v17 = "(null)";
      memcpy(v15, v17, HIWORD(v11) - 1LL);
      *((_BYTE *)v15 + v16) = 0;
      v18 = *(_DWORD *)(v13 + 32);
      v19 = (void *)(v13 + (unsigned __int16)v18);
      if ( v28 )
        v20 = v28;
      else
        v20 = "(null)";
      v21 = HIWORD(v18) - 1LL;
      memcpy(v19, v20, v21);
      *((_BYTE *)v19 + v21) = 0;
      result = trace_event_buffer_commit(v24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
