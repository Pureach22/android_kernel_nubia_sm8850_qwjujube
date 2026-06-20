__int64 __fastcall trace_event_raw_event_print_udp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _WORD *a5,
        __int16 a6)
{
  __int64 v10; // x8
  int offsets_print_udp; // w0
  __int64 result; // x0
  int v13; // w8
  int v14; // w9
  const char *v15; // x10
  __int64 v16; // x24
  int v17; // w11
  void *v18; // x21
  __int64 v19; // x8
  const char *v20; // x1
  __int64 v21; // x22
  int v22; // w8
  void *v23; // x21
  const char *v24; // x1
  size_t v25; // x22
  __int16 v26; // w8
  __int64 v27; // [xsp+8h] [xbp-68h]
  __int64 v28; // [xsp+10h] [xbp-60h]
  _QWORD v29[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v30; // [xsp+48h] [xbp-28h] BYREF
  const char *v31; // [xsp+50h] [xbp-20h]
  __int64 v32; // [xsp+58h] [xbp-18h]
  const char *v33; // [xsp+60h] [xbp-10h]
  __int64 v34; // [xsp+68h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v29, 0, sizeof(v29));
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (v27 = a3, v28 = a4, result = _trace_trigger_soft_disabled(a1), a3 = v27, a4 = v28, (result & 1) == 0) )
  {
    v32 = 0;
    v33 = nullptr;
    v30 = 0;
    v31 = nullptr;
    offsets_print_udp = trace_event_get_offsets_print_udp(&v30, a3, a4);
    result = trace_event_buffer_reserve(v29, a1, offsets_print_udp + 40LL);
    if ( result )
    {
      v13 = v30;
      v14 = v32;
      *(_QWORD *)(result + 8) = a2;
      v15 = v31;
      *(_DWORD *)(result + 20) = v13;
      *(_DWORD *)(result + 24) = v14;
      v16 = result;
      v17 = *(_DWORD *)(a2 + 112);
      v18 = (void *)(result + (unsigned __int16)v13);
      v19 = HIWORD(v13);
      if ( v15 )
        v20 = v15;
      else
        v20 = "(null)";
      v21 = v19 - 1;
      *(_DWORD *)(result + 16) = v17;
      memcpy(v18, v20, v19 - 1);
      *((_BYTE *)v18 + v21) = 0;
      v22 = *(_DWORD *)(v16 + 24);
      v23 = (void *)(v16 + (unsigned __int16)v22);
      if ( v33 )
        v24 = v33;
      else
        v24 = "(null)";
      v25 = HIWORD(v22) - 1LL;
      memcpy(v23, v24, v25);
      *((_BYTE *)v23 + v25) = 0;
      *(_WORD *)(v16 + 28) = *a5;
      v26 = a5[1];
      *(_WORD *)(v16 + 32) = a6;
      *(_WORD *)(v16 + 30) = v26;
      result = trace_event_buffer_commit(v29);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
