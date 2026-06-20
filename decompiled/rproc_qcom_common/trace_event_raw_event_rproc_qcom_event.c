__int64 __fastcall trace_event_raw_event_rproc_qcom_event(__int64 a1)
{
  __int64 v2; // x8
  int offsets_rproc_qcom_event; // w0
  __int64 result; // x0
  int v5; // w8
  int v6; // w9
  const char *v7; // x12
  int v8; // w10
  __int64 v9; // x19
  __int64 v10; // x22
  const char *v11; // x1
  size_t v12; // x20
  int v13; // w8
  void *v14; // x19
  const char *v15; // x1
  size_t v16; // x20
  int v17; // w8
  void *v18; // x19
  const char *v19; // x1
  size_t v20; // x20
  _QWORD v21[6]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v22; // [xsp+48h] [xbp-38h] BYREF
  const char *v23; // [xsp+50h] [xbp-30h]
  __int64 v24; // [xsp+58h] [xbp-28h]
  const char *v25; // [xsp+60h] [xbp-20h]
  __int64 v26; // [xsp+68h] [xbp-18h]
  const char *v27; // [xsp+70h] [xbp-10h]
  __int64 v28; // [xsp+78h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, sizeof(v21));
  if ( (v2 & 0x2C0) == 0 || (v2 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v26 = 0;
    v27 = nullptr;
    v24 = 0;
    v25 = nullptr;
    v22 = 0;
    v23 = nullptr;
    offsets_rproc_qcom_event = trace_event_get_offsets_rproc_qcom_event(&v22);
    result = trace_event_buffer_reserve(v21, a1, offsets_rproc_qcom_event + 20LL);
    if ( result )
    {
      v5 = v22;
      v6 = v24;
      v7 = v23;
      v8 = v26;
      *(_DWORD *)(result + 8) = v22;
      *(_DWORD *)(result + 12) = v6;
      v9 = result + (unsigned __int16)v5;
      *(_DWORD *)(result + 16) = v8;
      v10 = result;
      if ( v7 )
        v11 = v7;
      else
        v11 = "(null)";
      v12 = HIWORD(v5) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v5), v11, v12);
      *(_BYTE *)(v9 + v12) = 0;
      v13 = *(_DWORD *)(v10 + 12);
      v14 = (void *)(v10 + (unsigned __int16)v13);
      if ( v25 )
        v15 = v25;
      else
        v15 = "(null)";
      v16 = HIWORD(v13) - 1LL;
      memcpy(v14, v15, v16);
      *((_BYTE *)v14 + v16) = 0;
      v17 = *(_DWORD *)(v10 + 16);
      v18 = (void *)(v10 + (unsigned __int16)v17);
      if ( v27 )
        v19 = v27;
      else
        v19 = "(null)";
      v20 = HIWORD(v17) - 1LL;
      memcpy(v18, v19, v20);
      *((_BYTE *)v18 + v20) = 0;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
