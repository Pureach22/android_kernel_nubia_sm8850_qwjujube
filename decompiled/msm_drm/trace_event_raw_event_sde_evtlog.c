__int64 __fastcall trace_event_raw_event_sde_evtlog(
        __int64 a1,
        const char *a2,
        int a3,
        unsigned int a4,
        const void *a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  __int64 v13; // x22
  int v14; // w8
  size_t v15; // x24
  __int64 v16; // x25
  unsigned int v17; // w23
  int v18; // w9
  __int64 v19; // x10
  int v20; // w8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  const char *v24; // x23
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v25, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v24 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v24, (result & 1) == 0) )
  {
    v10 = a2 ? a2 : "(null)";
    v11 = strlen(v10) + 1;
    result = trace_event_buffer_reserve(v25, a1, v11 + 140LL);
    if ( result )
    {
      v13 = result + 140;
      v14 = (v11 << 16) | 0x8C;
      v15 = (unsigned __int16)v11 - 1LL;
      v16 = result;
      *(_DWORD *)(result + 12) = v14;
      *(_DWORD *)(result + 8) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
      memcpy((void *)(result + 140), v10, v15);
      *(_DWORD *)(v16 + 16) = a3;
      if ( a4 >= 0xF )
        v17 = 15;
      else
        v17 = a4;
      *(_BYTE *)(v13 + v15) = 0;
      memcpy((void *)(v16 + 80), a5, 4LL * v17);
      memset((void *)(v16 + 80 + 4LL * v17), 0, (4 * v17) ^ 0x3C);
      v18 = *(_DWORD *)(v16 + 88);
      v19 = *(_QWORD *)(v16 + 92);
      *(_QWORD *)(v16 + 20) = *(_QWORD *)(v16 + 80);
      v20 = *(_DWORD *)(v16 + 100);
      *(_DWORD *)(v16 + 28) = v18;
      *(_DWORD *)(v16 + 40) = v20;
      v22 = *(_QWORD *)(v16 + 104);
      v21 = *(_QWORD *)(v16 + 112);
      *(_QWORD *)(v16 + 32) = v19;
      v23 = *(_QWORD *)(v16 + 128);
      *(_QWORD *)(v16 + 44) = v22;
      *(_QWORD *)(v16 + 52) = v21;
      LODWORD(v22) = *(_DWORD *)(v16 + 120);
      LODWORD(v21) = *(_DWORD *)(v16 + 124);
      *(_QWORD *)(v16 + 68) = v23;
      *(_DWORD *)(v16 + 60) = v22;
      *(_DWORD *)(v16 + 64) = v21;
      *(_DWORD *)(v16 + 76) = *(_DWORD *)(v16 + 136);
      result = trace_event_buffer_commit(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
