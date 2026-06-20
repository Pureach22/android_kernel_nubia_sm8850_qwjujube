__int64 __fastcall trace_event_raw_event_msm_vidc_buffer_dma_ops(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        __int64 a5,
        __int64 a6,
        char a7,
        int a8)
{
  __int64 v14; // x8
  int offsets_msm_vidc_buffer_dma_ops; // w0
  __int64 result; // x0
  int v17; // w8
  const char *v18; // x11
  __int64 v19; // x27
  __int64 v20; // x24
  const char *v21; // x1
  size_t v22; // x25
  const char *v23; // x10
  int v24; // w8
  void *v25; // x22
  const char *v26; // x1
  size_t v27; // x21
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
    offsets_msm_vidc_buffer_dma_ops = trace_event_get_offsets_msm_vidc_buffer_dma_ops(&v29);
    result = trace_event_buffer_reserve(v28, a1, offsets_msm_vidc_buffer_dma_ops + 56LL);
    if ( result )
    {
      v17 = v29;
      v18 = v30;
      v19 = result;
      *(_DWORD *)(result + 40) = v31;
      v20 = result + (unsigned __int16)v17;
      *(_DWORD *)(result + 8) = v17;
      if ( v18 )
        v21 = v18;
      else
        v21 = "(null)";
      v22 = HIWORD(v17) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v17), v21, v22);
      *(_BYTE *)(v20 + v22) = 0;
      v23 = v32;
      v24 = *(_DWORD *)(v19 + 40);
      *(_BYTE *)(v19 + 24) = a4;
      *(_QWORD *)(v19 + 32) = a5;
      v25 = (void *)(v19 + (unsigned __int16)v24);
      if ( v23 )
        v26 = v23;
      else
        v26 = "(null)";
      *(_QWORD *)(v19 + 16) = a3;
      v27 = HIWORD(v24) - 1LL;
      memcpy(v25, v26, v27);
      *((_BYTE *)v25 + v27) = 0;
      *(_BYTE *)(v19 + 44) = a7;
      *(_DWORD *)(v19 + 48) = a8;
      result = trace_event_buffer_commit(v28);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
