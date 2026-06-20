__int64 __fastcall trace_event_raw_event_alloc_req_msg_class(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  int v5; // w0
  __int64 result; // x0
  int v7; // w8
  int v8; // w10
  int v9; // w11
  void *v10; // x21
  __int64 v11; // x20
  const char *v12; // x11
  __int64 v13; // x22
  bool v14; // zf
  const char *v15; // x1
  int v16; // w8
  void *v17; // x21
  const char *v18; // x1
  size_t v19; // x22
  unsigned __int64 v20; // x8
  _BYTE *v21; // x11
  __int64 v22; // x9
  __int64 v23; // x10
  char v24; // t1
  _QWORD v25[6]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v26; // [xsp+38h] [xbp-48h] BYREF
  const char *v27; // [xsp+40h] [xbp-40h]
  __int64 v28; // [xsp+48h] [xbp-38h]
  const char *v29; // [xsp+50h] [xbp-30h]
  __int64 v30; // [xsp+58h] [xbp-28h]
  __int64 v31; // [xsp+60h] [xbp-20h]
  __int64 v32; // [xsp+68h] [xbp-18h]
  __int64 v33; // [xsp+70h] [xbp-10h]
  __int64 v34; // [xsp+78h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, sizeof(v25));
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = nullptr;
    v26 = 0;
    v27 = nullptr;
    v5 = ((__int64 (__fastcall *)(__int64 *, __int64))trace_event_get_offsets_alloc_req_msg_class)(&v26, a2);
    result = trace_event_buffer_reserve(v25, a1, v5 + 40LL);
    if ( result )
    {
      v7 = v26;
      v8 = v30;
      v9 = v32;
      *(_DWORD *)(result + 24) = v28;
      v10 = (void *)(result + (unsigned __int16)v7);
      *(_DWORD *)(result + 12) = v7;
      v11 = result;
      *(_DWORD *)(result + 32) = v8;
      *(_DWORD *)(result + 36) = v9;
      v12 = v27;
      v13 = HIWORD(v7) - 1LL;
      v14 = v27 == nullptr;
      *(_DWORD *)(result + 8) = *(_DWORD *)a2;
      if ( v14 )
        v15 = "(null)";
      else
        v15 = v12;
      memcpy(v10, v15, HIWORD(v7) - 1LL);
      *((_BYTE *)v10 + v13) = 0;
      v16 = *(_DWORD *)(v11 + 24);
      v17 = (void *)(v11 + (unsigned __int16)v16);
      if ( v29 )
        v18 = v29;
      else
        v18 = "(null)";
      *(_QWORD *)(v11 + 16) = *(_QWORD *)(a2 + 12);
      v19 = HIWORD(v16) - 1LL;
      memcpy(v17, v18, v19);
      *((_BYTE *)v17 + v19) = 0;
      *(_DWORD *)(v11 + 28) = *(_DWORD *)(a2 + 28);
      if ( *(_DWORD *)(a2 + 28) )
      {
        v20 = 0;
        v21 = (_BYTE *)(a2 + 34);
        v22 = v11 + *(unsigned __int16 *)(v11 + 32);
        v23 = v11 + *(unsigned __int16 *)(v11 + 36);
        do
        {
          *(_WORD *)(v22 + 2 * v20) = *((_WORD *)v21 - 1);
          v24 = *v21;
          v21 += 4;
          *(_BYTE *)(v23 + v20++) = v24;
        }
        while ( v20 < *(unsigned int *)(a2 + 28) );
      }
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
