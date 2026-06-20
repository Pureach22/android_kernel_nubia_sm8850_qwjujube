__int64 __fastcall trace_event_raw_event_kgsl_mmu_pagefault(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // w8
  int v11; // w9
  int v12; // w10
  const char *v13; // x12
  __int64 v14; // x21
  __int64 v15; // x24
  const char *v16; // x1
  size_t v17; // x22
  const char *v18; // x10
  int v19; // w8
  void *v20; // x20
  const char *v21; // x1
  size_t v22; // x19
  int v23; // w8
  void *v24; // x19
  const char *v25; // x1
  size_t v26; // x20
  __int64 v27; // x22
  __int64 v28; // [xsp+8h] [xbp-78h]
  __int64 v29; // [xsp+10h] [xbp-70h]
  _QWORD v30[6]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v31; // [xsp+48h] [xbp-38h] BYREF
  const char *v32; // [xsp+50h] [xbp-30h]
  __int64 v33; // [xsp+58h] [xbp-28h]
  const char *v34; // [xsp+60h] [xbp-20h]
  __int64 v35; // [xsp+68h] [xbp-18h]
  const char *v36; // [xsp+70h] [xbp-10h]
  __int64 v37; // [xsp+78h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v30, 0, sizeof(v30));
  if ( (v8 & 0x2C0) == 0
    || (v8 & 0x100) != 0
    || (v28 = a6,
        v29 = a2,
        v27 = a5,
        result = _trace_trigger_soft_disabled(a1),
        a6 = v28,
        a2 = v29,
        a5 = v27,
        (result & 1) == 0) )
  {
    v35 = 0;
    v36 = nullptr;
    v33 = 0;
    v34 = nullptr;
    v31 = 0;
    v32 = nullptr;
    trace_event_get_offsets_kgsl_mmu_pagefault(&v31, a2, a5, a6);
    result = trace_event_buffer_reserve(v30);
    if ( result )
    {
      v10 = v31;
      v11 = v33;
      v12 = v35;
      v13 = v32;
      v14 = result + (unsigned __int16)v31;
      *(_DWORD *)(result + 8) = v31;
      *(_DWORD *)(result + 28) = v11;
      *(_DWORD *)(result + 32) = v12;
      v15 = result;
      if ( v13 )
        v16 = v13;
      else
        v16 = "(null)";
      v17 = HIWORD(v10) - 1LL;
      memcpy((void *)(result + (unsigned __int16)v10), v16, v17);
      *(_BYTE *)(v14 + v17) = 0;
      v18 = v34;
      v19 = *(_DWORD *)(v15 + 28);
      *(_QWORD *)(v15 + 16) = a3;
      *(_DWORD *)(v15 + 24) = a4;
      v20 = (void *)(v15 + (unsigned __int16)v19);
      if ( v18 )
        v21 = v18;
      else
        v21 = "(null)";
      v22 = HIWORD(v19) - 1LL;
      memcpy(v20, v21, v22);
      *((_BYTE *)v20 + v22) = 0;
      v23 = *(_DWORD *)(v15 + 32);
      v24 = (void *)(v15 + (unsigned __int16)v23);
      if ( v36 )
        v25 = v36;
      else
        v25 = "(null)";
      v26 = HIWORD(v23) - 1LL;
      memcpy(v24, v25, v26);
      *((_BYTE *)v24 + v26) = 0;
      result = trace_event_buffer_commit(v30);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
