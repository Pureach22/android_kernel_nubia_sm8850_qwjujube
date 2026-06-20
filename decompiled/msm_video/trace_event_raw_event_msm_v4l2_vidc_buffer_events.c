__int64 __fastcall trace_event_raw_event_msm_v4l2_vidc_buffer_events(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v12; // x8
  int offsets_msm_v4l2_vidc_buffer_events; // w0
  __int64 result; // x0
  unsigned __int16 v15; // w8
  int v16; // w9
  const char *v17; // x12
  int v18; // w10
  unsigned int v19; // w11
  __int64 v20; // x24
  __int64 v21; // x23
  const char *v22; // x1
  size_t v23; // x25
  int v24; // w8
  void *v25; // x24
  const char *v26; // x1
  size_t v27; // x25
  int v28; // w8
  void *v29; // x24
  const char *v30; // x1
  size_t v31; // x25
  __int64 v32; // x8
  __int64 v33; // x8
  _QWORD v34[6]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v35; // [xsp+38h] [xbp-38h] BYREF
  const char *v36; // [xsp+40h] [xbp-30h]
  __int64 v37; // [xsp+48h] [xbp-28h]
  const char *v38; // [xsp+50h] [xbp-20h]
  __int64 v39; // [xsp+58h] [xbp-18h]
  const char *v40; // [xsp+60h] [xbp-10h]
  __int64 v41; // [xsp+68h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v34, 0, sizeof(v34));
  if ( (v12 & 0x2C0) == 0 || (v12 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v39 = 0;
    v40 = nullptr;
    v37 = 0;
    v38 = nullptr;
    v35 = 0;
    v36 = nullptr;
    offsets_msm_v4l2_vidc_buffer_events = trace_event_get_offsets_msm_v4l2_vidc_buffer_events(&v35, a2);
    result = trace_event_buffer_reserve(v34, a1, offsets_msm_v4l2_vidc_buffer_events + 120LL);
    if ( result )
    {
      v15 = v35;
      v16 = v37;
      v17 = v36;
      v18 = v39;
      v19 = WORD1(v35);
      *(_DWORD *)(result + 8) = v35;
      *(_DWORD *)(result + 12) = v16;
      v20 = result + v15;
      v21 = result;
      *(_DWORD *)(result + 16) = v18;
      if ( v17 )
        v22 = v17;
      else
        v22 = "(null)";
      v23 = v19 - 1LL;
      memcpy((void *)(result + v15), v22, v23);
      *(_BYTE *)(v20 + v23) = 0;
      v24 = *(_DWORD *)(v21 + 12);
      v25 = (void *)(v21 + (unsigned __int16)v24);
      if ( v38 )
        v26 = v38;
      else
        v26 = "(null)";
      v27 = HIWORD(v24) - 1LL;
      memcpy(v25, v26, v27);
      *((_BYTE *)v25 + v27) = 0;
      v28 = *(_DWORD *)(v21 + 16);
      v29 = (void *)(v21 + (unsigned __int16)v28);
      if ( v40 )
        v30 = v40;
      else
        v30 = "(null)";
      v31 = HIWORD(v28) - 1LL;
      memcpy(v29, v30, v31);
      *((_BYTE *)v29 + v31) = 0;
      if ( a5 )
      {
        *(_DWORD *)(v21 + 20) = *(_DWORD *)(a5 + 32);
        *(_DWORD *)(v21 + 24) = *(_DWORD *)(a5 + 36);
        *(_DWORD *)(v21 + 28) = *(_DWORD *)(a5 + 44);
        v32 = *(_QWORD *)(a5 + 56);
        *(_QWORD *)(v21 + 48) = a7;
        *(_QWORD *)(v21 + 32) = v32;
        *(_QWORD *)(v21 + 40) = a6;
        *(_DWORD *)(v21 + 56) = *(_DWORD *)(a5 + 40);
        *(_DWORD *)(v21 + 60) = *(_DWORD *)(a5 + 48);
        *(_DWORD *)(v21 + 64) = *(_DWORD *)(a5 + 64);
        *(_QWORD *)(v21 + 72) = *(_QWORD *)(a5 + 72);
        *(_DWORD *)(v21 + 80) = *(_DWORD *)(a5 + 80);
        if ( a2 )
        {
LABEL_14:
          *(_QWORD *)(v21 + 88) = a2[529];
          *(_QWORD *)(v21 + 96) = a2[532];
          *(_QWORD *)(v21 + 104) = a2[530];
          v33 = a2[531];
LABEL_17:
          *(_QWORD *)(v21 + 112) = v33;
          result = trace_event_buffer_commit(v34);
          goto LABEL_18;
        }
      }
      else
      {
        *(_QWORD *)(v21 + 24) = 0;
        *(_QWORD *)(v21 + 32) = 0;
        *(_DWORD *)(v21 + 20) = -1;
        *(_QWORD *)(v21 + 40) = a6;
        *(_QWORD *)(v21 + 48) = a7;
        *(_QWORD *)(v21 + 56) = 0;
        *(_DWORD *)(v21 + 64) = 0;
        *(_QWORD *)(v21 + 72) = 0;
        *(_DWORD *)(v21 + 80) = 0;
        if ( a2 )
          goto LABEL_14;
      }
      v33 = 0;
      *(_QWORD *)(v21 + 96) = 0;
      *(_QWORD *)(v21 + 104) = 0;
      *(_QWORD *)(v21 + 88) = 0;
      goto LABEL_17;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
