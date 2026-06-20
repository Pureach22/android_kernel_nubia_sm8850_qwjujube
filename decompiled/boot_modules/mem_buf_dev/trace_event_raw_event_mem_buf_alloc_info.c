__int64 __fastcall trace_event_raw_event_mem_buf_alloc_info(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        _DWORD *a5)
{
  __int64 v8; // x8
  int v9; // w0
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  int v13; // w10
  const char *v14; // x12
  int v15; // w9
  __int64 v16; // x20
  __int64 v17; // x21
  __int64 v18; // x22
  const char *v19; // x1
  int v20; // w8
  void *v21; // x20
  const char *v22; // x1
  size_t v23; // x22
  unsigned __int64 v24; // x8
  _BYTE *v25; // x11
  __int64 v26; // x9
  __int64 v27; // x10
  char v28; // t1
  unsigned int v29; // w22
  unsigned int v30; // [xsp+4h] [xbp-7Ch]
  _QWORD v31[6]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v32; // [xsp+38h] [xbp-48h] BYREF
  const char *v33; // [xsp+40h] [xbp-40h]
  __int64 v34; // [xsp+48h] [xbp-38h]
  const char *v35; // [xsp+50h] [xbp-30h]
  __int64 v36; // [xsp+58h] [xbp-28h]
  __int64 v37; // [xsp+60h] [xbp-20h]
  __int64 v38; // [xsp+68h] [xbp-18h]
  __int64 v39; // [xsp+70h] [xbp-10h]
  __int64 v40; // [xsp+78h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v31, 0, sizeof(v31));
  if ( (v8 & 0x2C0) == 0
    || (v8 & 0x100) != 0
    || (v30 = a4, v29 = a3, result = _trace_trigger_soft_disabled(a1), a4 = v30, a3 = v29, (result & 1) == 0) )
  {
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = nullptr;
    v32 = 0;
    v33 = nullptr;
    v9 = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, _DWORD *))trace_event_get_offsets_mem_buf_alloc_info)(
           &v32,
           a3,
           a4,
           a5);
    result = trace_event_buffer_reserve(v31, a1, v9 + 40LL);
    if ( result )
    {
      v11 = v32;
      v12 = v34;
      v13 = v36;
      v14 = v33;
      *(_DWORD *)(result + 20) = v32;
      *(_DWORD *)(result + 24) = v12;
      v15 = v38;
      *(_QWORD *)(result + 8) = a2;
      v16 = result + (unsigned __int16)v11;
      *(_DWORD *)(result + 28) = v13;
      *(_DWORD *)(result + 32) = v15;
      v17 = result;
      v18 = HIWORD(v11) - 1LL;
      if ( v14 )
        v19 = v14;
      else
        v19 = "(null)";
      memcpy((void *)(result + (unsigned __int16)v11), v19, HIWORD(v11) - 1LL);
      *(_BYTE *)(v16 + v18) = 0;
      v20 = *(_DWORD *)(v17 + 24);
      v21 = (void *)(v17 + (unsigned __int16)v20);
      if ( v35 )
        v22 = v35;
      else
        v22 = "(null)";
      v23 = HIWORD(v20) - 1LL;
      memcpy(v21, v22, v23);
      *((_BYTE *)v21 + v23) = 0;
      *(_DWORD *)(v17 + 16) = *a5;
      if ( *a5 )
      {
        v24 = 0;
        v25 = (char *)a5 + 6;
        v26 = v17 + *(unsigned __int16 *)(v17 + 28);
        v27 = v17 + *(unsigned __int16 *)(v17 + 32);
        do
        {
          *(_WORD *)(v26 + 2 * v24) = *((_WORD *)v25 - 1);
          v28 = *v25;
          v25 += 4;
          *(_BYTE *)(v27 + v24++) = v28;
        }
        while ( v24 < (unsigned int)*a5 );
      }
      result = trace_event_buffer_commit(v31);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
