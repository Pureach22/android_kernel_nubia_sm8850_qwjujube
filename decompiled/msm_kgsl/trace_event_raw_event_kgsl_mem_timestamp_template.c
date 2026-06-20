__int64 __fastcall trace_event_raw_event_kgsl_mem_timestamp_template(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6)
{
  __int64 v10; // x8
  const char *v11; // x24
  int v12; // w25
  __int64 result; // x0
  __int64 v14; // x23
  int v15; // w8
  size_t v16; // x25
  __int64 v17; // x26
  int v18; // w8
  __int64 v19; // x24
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (v19 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v19, (result & 1) == 0) )
  {
    if ( *(_QWORD *)(a2 + 8) )
      v11 = *(const char **)(a2 + 8);
    else
      v11 = "(null)";
    v12 = strlen(v11) + 1;
    result = trace_event_buffer_reserve(v20);
    if ( result )
    {
      v14 = result + 68;
      v15 = (v12 << 16) | 0x44;
      v16 = (unsigned __int16)v12 - 1LL;
      v17 = result;
      *(_DWORD *)(result + 8) = v15;
      memcpy((void *)(result + 68), v11, v16);
      *(_BYTE *)(v14 + v16) = 0;
      *(_QWORD *)(v17 + 16) = *(_QWORD *)(a3 + 32);
      *(_QWORD *)(v17 + 24) = *(_QWORD *)(a3 + 48);
      kgsl_get_memory_usage((char *)(v17 + 36), 0x10u, *(_QWORD *)(a3 + 80));
      *(_DWORD *)(v17 + 52) = *(_DWORD *)(a3 + 248);
      *(_DWORD *)(v17 + 56) = a4;
      v18 = *(_DWORD *)(a3 + 80);
      *(_DWORD *)(v17 + 60) = a5;
      *(_DWORD *)(v17 + 64) = a6;
      *(_DWORD *)(v17 + 32) = (unsigned __int8)v18 >> 5;
      result = trace_event_buffer_commit(v20);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
