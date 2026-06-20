__int64 __fastcall trace_event_raw_event_print_tcp(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x8
  int offsets_print_tcp; // w0
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  const char *v13; // x10
  __int64 v14; // x23
  int v15; // w11
  void *v16; // x20
  __int64 v17; // x8
  const char *v18; // x1
  __int64 v19; // x21
  int v20; // w8
  void *v21; // x20
  const char *v22; // x1
  size_t v23; // x21
  __int64 v24; // [xsp+8h] [xbp-68h]
  __int64 v25; // [xsp+10h] [xbp-60h]
  _QWORD v26[6]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v27; // [xsp+48h] [xbp-28h] BYREF
  const char *v28; // [xsp+50h] [xbp-20h]
  __int64 v29; // [xsp+58h] [xbp-18h]
  const char *v30; // [xsp+60h] [xbp-10h]
  __int64 v31; // [xsp+68h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v26, 0, sizeof(v26));
  if ( (v8 & 0x2C0) == 0
    || (v8 & 0x100) != 0
    || (v24 = a3, v25 = a4, result = _trace_trigger_soft_disabled(a1), a3 = v24, a4 = v25, (result & 1) == 0) )
  {
    v29 = 0;
    v30 = nullptr;
    v27 = 0;
    v28 = nullptr;
    offsets_print_tcp = trace_event_get_offsets_print_tcp(&v27, a3, a4);
    result = trace_event_buffer_reserve(v26, a1, offsets_print_tcp + 48LL);
    if ( result )
    {
      v11 = v27;
      v12 = v29;
      *(_QWORD *)(result + 8) = a2;
      v13 = v28;
      *(_DWORD *)(result + 20) = v11;
      *(_DWORD *)(result + 24) = v12;
      v14 = result;
      v15 = *(_DWORD *)(a2 + 112);
      v16 = (void *)(result + (unsigned __int16)v11);
      v17 = HIWORD(v11);
      if ( v13 )
        v18 = v13;
      else
        v18 = "(null)";
      v19 = v17 - 1;
      *(_DWORD *)(result + 16) = v15;
      memcpy(v16, v18, v17 - 1);
      *((_BYTE *)v16 + v19) = 0;
      v20 = *(_DWORD *)(v14 + 24);
      v21 = (void *)(v14 + (unsigned __int16)v20);
      if ( v30 )
        v22 = v30;
      else
        v22 = "(null)";
      v23 = HIWORD(v20) - 1LL;
      memcpy(v21, v22, v23);
      *((_BYTE *)v21 + v23) = 0;
      *(_WORD *)(v14 + 28) = *(_WORD *)a5;
      *(_WORD *)(v14 + 30) = *(_WORD *)(a5 + 2);
      *(_DWORD *)(v14 + 32) = *(_DWORD *)(a5 + 4);
      *(_DWORD *)(v14 + 36) = *(_DWORD *)(a5 + 8);
      *(_BYTE *)(v14 + 40) = (*(_WORD *)(a5 + 12) & 0x200) != 0;
      *(_BYTE *)(v14 + 41) = (*(_WORD *)(a5 + 12) & 0x1000) != 0;
      *(_BYTE *)(v14 + 42) = *(_BYTE *)(a5 + 13) & 1;
      result = trace_event_buffer_commit(v26);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
