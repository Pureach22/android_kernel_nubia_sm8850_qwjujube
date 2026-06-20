__int64 __fastcall trace_event_raw_event_msm_v4l2_vidc_inst(__int64 a1)
{
  __int64 v2; // x8
  int offsets_msm_v4l2_vidc_inst; // w0
  __int64 result; // x0
  int v5; // w8
  int v6; // w9
  const char *v7; // x11
  __int64 v8; // x22
  __int64 v9; // x19
  const char *v10; // x1
  size_t v11; // x20
  int v12; // w8
  void *v13; // x19
  const char *v14; // x1
  size_t v15; // x20
  _QWORD v16[6]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v17; // [xsp+38h] [xbp-28h] BYREF
  const char *v18; // [xsp+40h] [xbp-20h]
  __int64 v19; // [xsp+48h] [xbp-18h]
  const char *v20; // [xsp+50h] [xbp-10h]
  __int64 v21; // [xsp+58h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, sizeof(v16));
  if ( (v2 & 0x2C0) == 0 || (v2 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v19 = 0;
    v20 = nullptr;
    v17 = 0;
    v18 = nullptr;
    offsets_msm_v4l2_vidc_inst = trace_event_get_offsets_msm_v4l2_vidc_inst(&v17);
    result = trace_event_buffer_reserve(v16, a1, offsets_msm_v4l2_vidc_inst + 16LL);
    if ( result )
    {
      v5 = v17;
      v6 = v19;
      v7 = v18;
      v8 = result;
      *(_DWORD *)(result + 8) = v17;
      *(_DWORD *)(result + 12) = v6;
      v9 = result + (unsigned __int16)v5;
      if ( v7 )
        v10 = v7;
      else
        v10 = "(null)";
      v11 = HIWORD(v5) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v5), v10, v11);
      *(_BYTE *)(v9 + v11) = 0;
      v12 = *(_DWORD *)(v8 + 12);
      v13 = (void *)(v8 + (unsigned __int16)v12);
      if ( v20 )
        v14 = v20;
      else
        v14 = "(null)";
      v15 = HIWORD(v12) - 1LL;
      memcpy(v13, v14, v15);
      *((_BYTE *)v13 + v15) = 0;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
