__int64 __fastcall trace_event_raw_event_print_skb_gso(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        __int16 a4,
        __int16 a5,
        __int16 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v14; // x8
  int offsets_print_skb_gso; // w0
  __int64 result; // x0
  int v17; // w8
  int v18; // w9
  const char *v19; // x11
  int v20; // w9
  void *v21; // x20
  __int64 v22; // x8
  __int64 v23; // x19
  const char *v24; // x1
  __int64 v25; // x22
  int v26; // w8
  void *v27; // x19
  const char *v28; // x1
  size_t v29; // x20
  __int64 v30; // [xsp+8h] [xbp-68h]
  __int64 v31; // [xsp+10h] [xbp-60h]
  _QWORD v32[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v33; // [xsp+48h] [xbp-28h] BYREF
  const char *v34; // [xsp+50h] [xbp-20h]
  __int64 v35; // [xsp+58h] [xbp-18h]
  const char *v36; // [xsp+60h] [xbp-10h]
  __int64 v37; // [xsp+68h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v32, 0, sizeof(v32));
  if ( (v14 & 0x2C0) == 0
    || (v14 & 0x100) != 0
    || (v30 = a7, v31 = a8, result = _trace_trigger_soft_disabled(a1), a7 = v30, a8 = v31, (result & 1) == 0) )
  {
    v35 = 0;
    v36 = nullptr;
    v33 = 0;
    v34 = nullptr;
    offsets_print_skb_gso = trace_event_get_offsets_print_skb_gso(&v33, a7, a8);
    result = trace_event_buffer_reserve(v32, a1, offsets_print_skb_gso + 40LL);
    if ( result )
    {
      v17 = v33;
      v18 = v35;
      *(_QWORD *)(result + 8) = a2;
      v19 = v34;
      *(_DWORD *)(result + 32) = v17;
      *(_DWORD *)(result + 36) = v18;
      *(_DWORD *)(result + 16) = *(_DWORD *)(a2 + 112);
      v20 = *(_DWORD *)(a2 + 116);
      *(_WORD *)(result + 28) = a5;
      v21 = (void *)(result + (unsigned __int16)v17);
      v22 = HIWORD(v17);
      *(_WORD *)(result + 26) = a4;
      *(_WORD *)(result + 30) = a6;
      v23 = v22 - 1;
      *(_WORD *)(result + 24) = a3;
      if ( v19 )
        v24 = v19;
      else
        v24 = "(null)";
      v25 = result;
      *(_DWORD *)(result + 20) = v20;
      memcpy(v21, v24, v22 - 1);
      *((_BYTE *)v21 + v23) = 0;
      v26 = *(_DWORD *)(v25 + 36);
      v27 = (void *)(v25 + (unsigned __int16)v26);
      if ( v36 )
        v28 = v36;
      else
        v28 = "(null)";
      v29 = HIWORD(v26) - 1LL;
      memcpy(v27, v28, v29);
      *((_BYTE *)v27 + v29) = 0;
      result = trace_event_buffer_commit(v32);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
