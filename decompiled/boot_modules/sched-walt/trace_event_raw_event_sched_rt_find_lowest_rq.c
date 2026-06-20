__int64 __fastcall trace_event_raw_event_sched_rt_find_lowest_rq(__int64 a1, __int64 a2, int a3, int a4, __int64 *a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x8
  __int64 v15; // x8
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17, v8, 56);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v12 = *(_QWORD *)(a2 + 2320);
      v13 = *(_QWORD *)(a2 + 2328);
      *(_DWORD *)(result + 28) = a3;
      *(_DWORD *)(result + 32) = a4;
      *(_QWORD *)(result + 20) = v13;
      *(_QWORD *)(result + 12) = v12;
      v14 = &vendor_data_pad;
      if ( (_UNKNOWN *)a2 != &init_task )
        v14 = (_QWORD *)(a2 + 5184);
      *(_QWORD *)(result + 40) = v14[46];
      if ( a5 )
        v15 = *a5;
      else
        v15 = 0;
      *(_QWORD *)(result + 48) = v15;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
