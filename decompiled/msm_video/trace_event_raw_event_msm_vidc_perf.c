__int64 __fastcall trace_event_raw_event_msm_vidc_perf(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x8
  const char *v11; // x8
  const char *v12; // x24
  int v13; // w25
  __int64 result; // x0
  __int64 v15; // x9
  __int64 v16; // x23
  int v17; // w8
  __int64 v18; // x25
  __int64 v19; // x26
  int v20; // w8
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v10 & 0x2C0) == 0 || (v10 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    v11 = (const char *)(a2 + 340);
    if ( !a2 )
      v11 = (const char *)&unk_84D69;
    if ( v11 )
      v12 = v11;
    else
      v12 = "(null)";
    v13 = strlen(v12) + 1;
    result = trace_event_buffer_reserve(v21, a1, v13 + 88LL);
    if ( result )
    {
      v15 = (unsigned __int16)v13;
      v16 = result;
      v17 = (v13 << 16) | 0x58;
      v18 = result + 88;
      v19 = v15 - 1;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 88), v12, v15 - 1);
      *(_BYTE *)(v18 + v19) = 0;
      if ( a2 )
      {
        *(_QWORD *)(v16 + 16) = *(_QWORD *)(a2 + 1944);
        *(_QWORD *)(v16 + 24) = *(_QWORD *)(a2 + 1952);
        *(_QWORD *)(v16 + 32) = *(_QWORD *)(a2 + 1960);
        *(_QWORD *)(v16 + 40) = *(_QWORD *)(a2 + 1968);
        *(_QWORD *)(v16 + 48) = *(_QWORD *)(a2 + 1976);
        *(_DWORD *)(v16 + 56) = *(_DWORD *)(a2 + 1984);
        *(_DWORD *)(v16 + 60) = *(_DWORD *)(a2 + 1988);
        v20 = *(_DWORD *)(a2 + 1992);
      }
      else
      {
        v20 = 0;
        *(_QWORD *)(v16 + 48) = 0;
        *(_QWORD *)(v16 + 56) = 0;
        *(_QWORD *)(v16 + 32) = 0;
        *(_QWORD *)(v16 + 40) = 0;
        *(_QWORD *)(v16 + 16) = 0;
        *(_QWORD *)(v16 + 24) = 0;
      }
      *(_DWORD *)(v16 + 64) = v20;
      *(_DWORD *)(v16 + 68) = a3;
      *(_QWORD *)(v16 + 72) = a4;
      *(_QWORD *)(v16 + 80) = a5;
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
