__int64 __fastcall trace_event_raw_event_tracing_eva_frame_from_sw(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        int a8,
        __int64 a9)
{
  __int64 v15; // x8
  int offsets_tracing_eva_frame_from_sw; // w0
  __int64 result; // x0
  int v18; // w8
  int v19; // w9
  const char *v20; // x11
  __int64 v21; // x23
  const char *v22; // x1
  __int64 v23; // x27
  size_t v24; // x24
  int v25; // w8
  void *v26; // x23
  const char *v27; // x1
  size_t v28; // x24
  __int64 v29; // [xsp+8h] [xbp-68h]
  __int64 v30; // [xsp+10h] [xbp-60h]
  _QWORD v31[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v32; // [xsp+48h] [xbp-28h] BYREF
  const char *v33; // [xsp+50h] [xbp-20h]
  __int64 v34; // [xsp+58h] [xbp-18h]
  const char *v35; // [xsp+60h] [xbp-10h]
  __int64 v36; // [xsp+68h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a1 + 72);
  memset(v31, 0, sizeof(v31));
  if ( (v15 & 0x2C0) == 0
    || (v15 & 0x100) != 0
    || (v29 = a3, v30 = a7, result = _trace_trigger_soft_disabled(a1), a3 = v29, a7 = v30, (result & 1) == 0) )
  {
    v34 = 0;
    v35 = nullptr;
    v32 = 0;
    v33 = nullptr;
    offsets_tracing_eva_frame_from_sw = trace_event_get_offsets_tracing_eva_frame_from_sw(&v32, a3, a7);
    result = trace_event_buffer_reserve(v31, a1, offsets_tracing_eva_frame_from_sw + 48LL);
    if ( result )
    {
      v18 = v32;
      v19 = v34;
      v20 = v33;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 32) = v19;
      v21 = result + (unsigned __int16)v18;
      *(_DWORD *)(result + 16) = v18;
      if ( v20 )
        v22 = v20;
      else
        v22 = "(null)";
      v23 = result;
      v24 = HIWORD(v18) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v18), v22, v24);
      *(_BYTE *)(v21 + v24) = 0;
      v25 = *(_DWORD *)(v23 + 32);
      v26 = (void *)(v23 + (unsigned __int16)v25);
      if ( v35 )
        v27 = v35;
      else
        v27 = "(null)";
      v28 = HIWORD(v25) - 1LL;
      memcpy(v26, v27, v28);
      *((_BYTE *)v26 + v28) = 0;
      *(_DWORD *)(v23 + 20) = a4;
      *(_DWORD *)(v23 + 24) = a5;
      *(_DWORD *)(v23 + 28) = a6;
      *(_DWORD *)(v23 + 36) = a8;
      *(_QWORD *)(v23 + 40) = a9;
      result = trace_event_buffer_commit(v31);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
