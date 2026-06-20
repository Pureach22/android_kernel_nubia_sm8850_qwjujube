__int64 __fastcall trace_event_raw_event_walt_cfs_mvp_task_template(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13, v7, 56);
    if ( result )
    {
      v10 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v10;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a2 + 148);
      *(_DWORD *)(result + 32) = *(_DWORD *)(a3 + 328);
      *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 40);
      v11 = *(_QWORD *)(a3 + 320);
      *(_DWORD *)(result + 48) = a4;
      *(_QWORD *)(result + 40) = v11;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
