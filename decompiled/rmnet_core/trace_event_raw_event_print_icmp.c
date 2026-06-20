__int64 __fastcall trace_event_raw_event_print_icmp(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        char a4,
        __int16 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v12; // x8
  int offsets_print_icmp; // w0
  __int64 result; // x0
  int v15; // w8
  int v16; // w9
  const char *v17; // x10
  int v18; // w9
  void *v19; // x20
  __int64 v20; // x8
  __int64 v21; // x21
  const char *v22; // x1
  __int64 v23; // x19
  int v24; // w8
  void *v25; // x19
  const char *v26; // x1
  size_t v27; // x20
  __int64 v28; // [xsp+8h] [xbp-68h]
  __int64 v29; // [xsp+10h] [xbp-60h]
  _QWORD v30[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v31; // [xsp+48h] [xbp-28h] BYREF
  const char *v32; // [xsp+50h] [xbp-20h]
  __int64 v33; // [xsp+58h] [xbp-18h]
  const char *v34; // [xsp+60h] [xbp-10h]
  __int64 v35; // [xsp+68h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v30, 0, sizeof(v30));
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (v28 = a6, v29 = a7, result = _trace_trigger_soft_disabled(a1), a6 = v28, a7 = v29, (result & 1) == 0) )
  {
    v33 = 0;
    v34 = nullptr;
    v31 = 0;
    v32 = nullptr;
    offsets_print_icmp = trace_event_get_offsets_print_icmp(&v31, a6, a7);
    result = trace_event_buffer_reserve(v30, a1, offsets_print_icmp + 40LL);
    if ( result )
    {
      v15 = v31;
      v16 = v33;
      *(_QWORD *)(result + 8) = a2;
      v17 = v32;
      *(_DWORD *)(result + 28) = v15;
      *(_DWORD *)(result + 32) = v16;
      v18 = *(_DWORD *)(a2 + 112);
      *(_BYTE *)(result + 22) = a4;
      v19 = (void *)(result + (unsigned __int16)v15);
      v20 = HIWORD(v15);
      *(_WORD *)(result + 20) = a3;
      v21 = v20 - 1;
      *(_DWORD *)(result + 16) = v18;
      if ( v17 )
        v22 = v17;
      else
        v22 = "(null)";
      *(_WORD *)(result + 24) = a5;
      v23 = result;
      memcpy(v19, v22, v20 - 1);
      *((_BYTE *)v19 + v21) = 0;
      v24 = *(_DWORD *)(v23 + 32);
      v25 = (void *)(v23 + (unsigned __int16)v24);
      if ( v34 )
        v26 = v34;
      else
        v26 = "(null)";
      v27 = HIWORD(v24) - 1LL;
      memcpy(v25, v26, v27);
      *((_BYTE *)v25 + v27) = 0;
      result = trace_event_buffer_commit(v30);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
