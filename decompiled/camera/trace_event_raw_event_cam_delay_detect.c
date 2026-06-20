__int64 __fastcall trace_event_raw_event_cam_delay_detect(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v14; // x8
  int offsets_cam_delay_detect; // w0
  __int64 result; // x0
  int v17; // w8
  int v18; // w9
  const char *v19; // x11
  __int64 v20; // x27
  __int64 v21; // x24
  const char *v22; // x1
  size_t v23; // x25
  int v24; // w8
  void *v25; // x24
  const char *v26; // x1
  size_t v27; // x25
  _QWORD v28[6]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v29; // [xsp+38h] [xbp-28h] BYREF
  const char *v30; // [xsp+40h] [xbp-20h]
  __int64 v31; // [xsp+48h] [xbp-18h]
  const char *v32; // [xsp+50h] [xbp-10h]
  __int64 v33; // [xsp+58h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v28, 0, sizeof(v28));
  if ( (v14 & 0x2C0) == 0 || (v14 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v31 = 0;
    v32 = nullptr;
    v29 = 0;
    v30 = nullptr;
    offsets_cam_delay_detect = trace_event_get_offsets_cam_delay_detect(&v29);
    result = trace_event_buffer_reserve(v28, a1, offsets_cam_delay_detect + 48LL);
    if ( result )
    {
      v17 = v29;
      v18 = v31;
      v19 = v30;
      v20 = result;
      *(_DWORD *)(result + 8) = v29;
      *(_DWORD *)(result + 12) = v18;
      v21 = result + (unsigned __int16)v17;
      if ( v19 )
        v22 = v19;
      else
        v22 = "(null)";
      v23 = HIWORD(v17) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v17), v22, v23);
      *(_BYTE *)(v21 + v23) = 0;
      v24 = *(_DWORD *)(v20 + 12);
      v25 = (void *)(v20 + (unsigned __int16)v24);
      if ( v32 )
        v26 = v32;
      else
        v26 = "(null)";
      v27 = HIWORD(v24) - 1LL;
      memcpy(v25, v26, v27);
      *((_BYTE *)v25 + v27) = 0;
      *(_QWORD *)(v20 + 16) = a4;
      *(_QWORD *)(v20 + 24) = a5;
      *(_DWORD *)(v20 + 32) = a6;
      *(_DWORD *)(v20 + 36) = a7;
      *(_DWORD *)(v20 + 40) = a8;
      result = trace_event_buffer_commit(v28);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
