__int64 __fastcall trace_event_raw_event_sched_pipeline_swapped(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  _QWORD *v8; // x9
  _QWORD *v9; // x11
  __int64 v10; // x12
  unsigned int v11; // w8
  __int64 v12; // x10
  int v13; // w8
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v5, 72);
    if ( result )
    {
      v8 = &init_task;
      if ( a2 )
      {
        v9 = (_QWORD *)(a2 - 5184);
        if ( (_UNKNOWN *)a2 == &vendor_data_pad )
          v9 = &init_task;
        v10 = v9[291];
        *(_QWORD *)(result + 8) = v9[290];
        *(_QWORD *)(result + 16) = v10;
        LODWORD(v10) = walt_scale_demand_divisor;
        *(_DWORD *)(result + 40) = *((_DWORD *)v9 + 450);
        *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 364);
        *(_DWORD *)(result + 56) = *(unsigned __int16 *)(a2 + 158);
        *(_DWORD *)(result + 64) = *(_DWORD *)(a2 + 32) / (unsigned int)v10;
        if ( a3 )
          goto LABEL_7;
      }
      else
      {
        *(_QWORD *)(result + 8) = 0;
        *(_QWORD *)(result + 16) = 0;
        *(_DWORD *)(result + 40) = -1;
        *(_DWORD *)(result + 48) = -1;
        *(_DWORD *)(result + 56) = -1;
        *(_DWORD *)(result + 64) = -1;
        if ( a3 )
        {
LABEL_7:
          v11 = walt_scale_demand_divisor;
          if ( (_UNKNOWN *)a3 != &vendor_data_pad )
            v8 = (_QWORD *)(a3 - 5184);
          v12 = v8[291];
          *(_QWORD *)(result + 24) = v8[290];
          *(_QWORD *)(result + 32) = v12;
          *(_DWORD *)(result + 44) = *((_DWORD *)v8 + 450);
          *(_DWORD *)(result + 52) = *(_DWORD *)(a3 + 364);
          *(_DWORD *)(result + 60) = *(unsigned __int16 *)(a3 + 158);
          v13 = *(_DWORD *)(a3 + 32) / v11;
          goto LABEL_12;
        }
      }
      v13 = -1;
      *(_QWORD *)(result + 24) = 0;
      *(_QWORD *)(result + 32) = 0;
      *(_DWORD *)(result + 44) = -1;
      *(_DWORD *)(result + 52) = -1;
      *(_DWORD *)(result + 60) = -1;
LABEL_12:
      *(_DWORD *)(result + 68) = v13;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
