__int64 __fastcall trace_event_raw_event_msm_vidc_driver(__int64 a1)
{
  __int64 v2; // x8
  int offsets_msm_vidc_driver; // w0
  __int64 result; // x0
  int v5; // w8
  int v6; // w9
  const char *v7; // x12
  int v8; // w10
  int v9; // w11
  __int64 v10; // x19
  _DWORD *v11; // x22
  const char *v12; // x1
  size_t v13; // x20
  int v14; // w8
  char *v15; // x19
  const char *v16; // x1
  size_t v17; // x20
  int v18; // w8
  char *v19; // x19
  const char *v20; // x1
  size_t v21; // x20
  int v22; // w8
  char *v23; // x19
  const char *v24; // x1
  size_t v25; // x20
  _QWORD v26[6]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v27; // [xsp+38h] [xbp-48h] BYREF
  const char *v28; // [xsp+40h] [xbp-40h]
  __int64 v29; // [xsp+48h] [xbp-38h]
  const char *v30; // [xsp+50h] [xbp-30h]
  __int64 v31; // [xsp+58h] [xbp-28h]
  const char *v32; // [xsp+60h] [xbp-20h]
  __int64 v33; // [xsp+68h] [xbp-18h]
  const char *v34; // [xsp+70h] [xbp-10h]
  __int64 v35; // [xsp+78h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 72);
  memset(v26, 0, sizeof(v26));
  if ( (v2 & 0x2C0) == 0 || (v2 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v33 = 0;
    v34 = nullptr;
    v31 = 0;
    v32 = nullptr;
    v29 = 0;
    v30 = nullptr;
    v27 = 0;
    v28 = nullptr;
    offsets_msm_vidc_driver = trace_event_get_offsets_msm_vidc_driver(&v27);
    result = trace_event_buffer_reserve(v26, a1, offsets_msm_vidc_driver + 24LL);
    if ( result )
    {
      v5 = v27;
      v6 = v29;
      v7 = v28;
      v8 = v31;
      *(_DWORD *)(result + 8) = v27;
      *(_DWORD *)(result + 12) = v6;
      v9 = v33;
      v10 = result + (unsigned __int16)v5;
      v11 = (_DWORD *)result;
      *(_DWORD *)(result + 16) = v8;
      *(_DWORD *)(result + 20) = v9;
      if ( v7 )
        v12 = v7;
      else
        v12 = "(null)";
      v13 = HIWORD(v5) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v5), v12, v13);
      *(_BYTE *)(v10 + v13) = 0;
      v14 = v11[3];
      v15 = (char *)v11 + (unsigned __int16)v14;
      if ( v30 )
        v16 = v30;
      else
        v16 = "(null)";
      v17 = HIWORD(v14) - 1LL;
      memcpy(v15, v16, v17);
      v15[v17] = 0;
      v18 = v11[4];
      v19 = (char *)v11 + (unsigned __int16)v18;
      if ( v32 )
        v20 = v32;
      else
        v20 = "(null)";
      v21 = HIWORD(v18) - 1LL;
      memcpy(v19, v20, v21);
      v19[v21] = 0;
      v22 = v11[5];
      v23 = (char *)v11 + (unsigned __int16)v22;
      if ( v34 )
        v24 = v34;
      else
        v24 = "(null)";
      v25 = HIWORD(v22) - 1LL;
      memcpy(v23, v24, v25);
      v23[v25] = 0;
      result = trace_event_buffer_commit(v26);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
