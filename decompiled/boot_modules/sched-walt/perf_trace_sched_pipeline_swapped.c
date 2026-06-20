__int64 __fastcall perf_trace_sched_pipeline_swapped(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x10
  _QWORD *v11; // x11
  __int64 v12; // x12
  unsigned int v13; // w8
  _QWORD *v14; // x9
  __int64 v15; // x10
  int v16; // w8
  __int64 v17; // x2
  __int64 v18; // x5
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(76, v21, &v20);
    if ( result )
    {
      v10 = (_QWORD *)v21[0];
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v10[31] = &v19;
      v10[32] = v4;
      v10[33] = 5;
      if ( a2 )
      {
        v11 = (_QWORD *)(a2 - 5184);
        if ( (_UNKNOWN *)a2 == &vendor_data_pad )
          v11 = &init_task;
        v12 = v11[291];
        *(_QWORD *)(result + 8) = v11[290];
        *(_QWORD *)(result + 16) = v12;
        LODWORD(v12) = walt_scale_demand_divisor;
        *(_DWORD *)(result + 40) = *((_DWORD *)v11 + 450);
        *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 364);
        *(_DWORD *)(result + 56) = *(unsigned __int16 *)(a2 + 158);
        *(_DWORD *)(result + 64) = *(_DWORD *)(a2 + 32) / (unsigned int)v12;
        if ( a3 )
          goto LABEL_8;
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
LABEL_8:
          v13 = walt_scale_demand_divisor;
          v14 = (_QWORD *)(a3 - 5184);
          if ( (_UNKNOWN *)a3 == &vendor_data_pad )
            v14 = &init_task;
          v15 = v14[291];
          *(_QWORD *)(result + 24) = v14[290];
          *(_QWORD *)(result + 32) = v15;
          *(_DWORD *)(result + 44) = *((_DWORD *)v14 + 450);
          *(_DWORD *)(result + 52) = *(_DWORD *)(a3 + 364);
          *(_DWORD *)(result + 60) = *(unsigned __int16 *)(a3 + 158);
          v16 = *(_DWORD *)(a3 + 32) / v13;
          goto LABEL_13;
        }
      }
      v16 = -1;
      *(_QWORD *)(result + 24) = 0;
      *(_QWORD *)(result + 32) = 0;
      *(_DWORD *)(result + 44) = -1;
      *(_DWORD *)(result + 52) = -1;
      *(_DWORD *)(result + 60) = -1;
LABEL_13:
      v17 = v20;
      v18 = v21[0];
      *(_DWORD *)(result + 68) = v16;
      result = perf_trace_run_bpf_submit(result, 76, v17, v6, 1, v18, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
