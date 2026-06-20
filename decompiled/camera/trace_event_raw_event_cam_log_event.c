__int64 __fastcall trace_event_raw_event_cam_log_event(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x8
  int offsets_cam_log_event; // w0
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  const char *v13; // x11
  __int64 v14; // x24
  __int64 v15; // x21
  const char *v16; // x1
  size_t v17; // x22
  int v18; // w8
  void *v19; // x21
  const char *v20; // x1
  size_t v21; // x22
  _QWORD v22[6]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v23; // [xsp+38h] [xbp-28h] BYREF
  const char *v24; // [xsp+40h] [xbp-20h]
  __int64 v25; // [xsp+48h] [xbp-18h]
  const char *v26; // [xsp+50h] [xbp-10h]
  __int64 v27; // [xsp+58h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, sizeof(v22));
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v25 = 0;
    v26 = nullptr;
    v23 = 0;
    v24 = nullptr;
    offsets_cam_log_event = trace_event_get_offsets_cam_log_event(&v23);
    result = trace_event_buffer_reserve(v22, a1, offsets_cam_log_event + 32LL);
    if ( result )
    {
      v11 = v23;
      v12 = v25;
      v13 = v24;
      v14 = result;
      *(_DWORD *)(result + 8) = v23;
      *(_DWORD *)(result + 12) = v12;
      v15 = result + (unsigned __int16)v11;
      if ( v13 )
        v16 = v13;
      else
        v16 = "(null)";
      v17 = HIWORD(v11) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v11), v16, v17);
      *(_BYTE *)(v15 + v17) = 0;
      v18 = *(_DWORD *)(v14 + 12);
      v19 = (void *)(v14 + (unsigned __int16)v18);
      if ( v26 )
        v20 = v26;
      else
        v20 = "(null)";
      v21 = HIWORD(v18) - 1LL;
      memcpy(v19, v20, v21);
      *((_BYTE *)v19 + v21) = 0;
      *(_QWORD *)(v14 + 16) = a4;
      *(_QWORD *)(v14 + 24) = a5;
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
