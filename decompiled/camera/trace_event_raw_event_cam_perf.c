__int64 __fastcall trace_event_raw_event_cam_perf(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  int offsets_cam_perf; // w0
  __int64 result; // x0
  int v9; // w8
  int v10; // w9
  const char *v11; // x11
  __int64 v12; // x23
  __int64 v13; // x20
  const char *v14; // x1
  size_t v15; // x21
  int v16; // w8
  void *v17; // x20
  const char *v18; // x1
  size_t v19; // x21
  _QWORD v20[6]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v21; // [xsp+38h] [xbp-28h] BYREF
  const char *v22; // [xsp+40h] [xbp-20h]
  __int64 v23; // [xsp+48h] [xbp-18h]
  const char *v24; // [xsp+50h] [xbp-10h]
  __int64 v25; // [xsp+58h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, sizeof(v20));
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v23 = 0;
    v24 = nullptr;
    v21 = 0;
    v22 = nullptr;
    offsets_cam_perf = trace_event_get_offsets_cam_perf(&v21);
    result = trace_event_buffer_reserve(v20, a1, offsets_cam_perf + 24LL);
    if ( result )
    {
      v9 = v21;
      v10 = v23;
      v11 = v22;
      v12 = result;
      *(_DWORD *)(result + 8) = v21;
      *(_DWORD *)(result + 12) = v10;
      v13 = result + (unsigned __int16)v9;
      if ( v11 )
        v14 = v11;
      else
        v14 = "(null)";
      v15 = HIWORD(v9) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v9), v14, v15);
      *(_BYTE *)(v13 + v15) = 0;
      v16 = *(_DWORD *)(v12 + 12);
      v17 = (void *)(v12 + (unsigned __int16)v16);
      if ( v24 )
        v18 = v24;
      else
        v18 = "(null)";
      v19 = HIWORD(v16) - 1LL;
      memcpy(v17, v18, v19);
      *((_BYTE *)v17 + v19) = 0;
      *(_QWORD *)(v12 + 16) = a4;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
