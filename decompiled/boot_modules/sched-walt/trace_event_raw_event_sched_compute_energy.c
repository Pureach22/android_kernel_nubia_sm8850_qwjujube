__int64 __fastcall trace_event_raw_event_sched_compute_energy(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        __int64 a8)
{
  __int64 v11; // x8
  __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x9
  unsigned __int16 *v19; // x8
  int v20; // w8
  _QWORD v22[7]; // [xsp+8h] [xbp-38h] BYREF

  v11 = a1;
  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v16 & 0x2C0) == 0
    || (v16 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v11 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v22, v11, 176);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v18 = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 20) = *(_QWORD *)(a2 + 2328);
      v19 = (unsigned __int16 *)&vendor_data_pad;
      if ( (_UNKNOWN *)a2 != &init_task )
        v19 = (unsigned __int16 *)(a2 + 5184);
      *(_QWORD *)(result + 12) = v18;
      *(_QWORD *)(result + 32) = v19[79];
      v20 = *(_DWORD *)(a2 + 40);
      *(_QWORD *)(result + 48) = a5;
      *(_DWORD *)(result + 56) = a3;
      *(_QWORD *)(result + 64) = a4;
      *(_DWORD *)(result + 72) = a7;
      *(_DWORD *)(result + 40) = v20;
      *(_QWORD *)(result + 80) = a6;
      *(_DWORD *)(result + 88) = *(_DWORD *)(a8 + 96);
      *(_DWORD *)(result + 92) = *(_DWORD *)(a8 + 100);
      *(_DWORD *)(result + 96) = *(_DWORD *)(a8 + 104);
      *(_QWORD *)(result + 104) = *(_QWORD *)a8;
      *(_QWORD *)(result + 112) = *(_QWORD *)(a8 + 8);
      *(_QWORD *)(result + 120) = *(_QWORD *)(a8 + 16);
      *(_QWORD *)(result + 128) = *(_QWORD *)(a8 + 32);
      *(_QWORD *)(result + 136) = *(_QWORD *)(a8 + 40);
      *(_QWORD *)(result + 144) = *(_QWORD *)(a8 + 48);
      *(_QWORD *)(result + 152) = *(_QWORD *)(a8 + 64);
      *(_QWORD *)(result + 160) = *(_QWORD *)(a8 + 72);
      *(_QWORD *)(result + 168) = *(_QWORD *)(a8 + 80);
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
