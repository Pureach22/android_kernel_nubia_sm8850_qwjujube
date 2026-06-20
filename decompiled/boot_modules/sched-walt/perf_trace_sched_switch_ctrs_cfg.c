__int64 __fastcall perf_trace_sched_switch_ctrs_cfg(__int64 result, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  int v9; // w9
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x9
  __int64 v16; // x2
  __int64 v17; // x5
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v6) )
    goto LABEL_19;
  result = perf_trace_buf_alloc(68, v20, &v19);
  if ( !result )
    goto LABEL_19;
  v8 = (_QWORD *)v20[0];
  *(_QWORD *)(v20[0] + 232LL) = &v21;
  v8[33] = 5;
  v8[31] = &v18;
  v8[32] = v3;
  if ( a2 < 0x20 )
  {
    v9 = *(_DWORD *)((char *)&cntenset_val + *((_QWORD *)&_per_cpu_offset + a2));
    if ( (v9 & 1) != 0 )
    {
      _WriteStatusReg(PMSELR_EL0, 0);
      __isb(0xFu);
      v10 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
      if ( (v9 & 2) != 0 )
      {
LABEL_7:
        _WriteStatusReg(PMSELR_EL0, 1u);
        __isb(0xFu);
        v11 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
        if ( (v9 & 4) != 0 )
          goto LABEL_8;
        goto LABEL_14;
      }
    }
    else
    {
      v10 = 0;
      if ( (v9 & 2) != 0 )
        goto LABEL_7;
    }
    v11 = 0;
    if ( (v9 & 4) != 0 )
    {
LABEL_8:
      _WriteStatusReg(PMSELR_EL0, 2u);
      __isb(0xFu);
      v12 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
      if ( (v9 & 8) != 0 )
        goto LABEL_9;
      goto LABEL_15;
    }
LABEL_14:
    v12 = 0;
    if ( (v9 & 8) != 0 )
    {
LABEL_9:
      _WriteStatusReg(PMSELR_EL0, 3u);
      __isb(0xFu);
      v13 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
      if ( (v9 & 0x10) != 0 )
        goto LABEL_10;
      goto LABEL_16;
    }
LABEL_15:
    v13 = 0;
    if ( (v9 & 0x10) != 0 )
    {
LABEL_10:
      _WriteStatusReg(PMSELR_EL0, 4u);
      __isb(0xFu);
      v14 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
      if ( (v9 & 0x20) != 0 )
      {
LABEL_11:
        _WriteStatusReg(PMSELR_EL0, 5u);
        __isb(0xFu);
        v15 = (unsigned __int16)_ReadStatusReg(PMXEVTYPER_EL0);
LABEL_18:
        v16 = v19;
        v17 = v20[0];
        *(_DWORD *)(result + 8) = a2;
        *(_QWORD *)(result + 16) = v10;
        *(_QWORD *)(result + 24) = v11;
        *(_QWORD *)(result + 32) = v12;
        *(_QWORD *)(result + 40) = v13;
        *(_QWORD *)(result + 48) = v14;
        *(_QWORD *)(result + 56) = v15;
        result = perf_trace_run_bpf_submit(result, 68, v16, v4, 1, v17, StatusReg + v6, 0);
LABEL_19:
        _ReadStatusReg(SP_EL0);
        return result;
      }
LABEL_17:
      v15 = 0;
      goto LABEL_18;
    }
LABEL_16:
    v14 = 0;
    if ( (v9 & 0x20) != 0 )
      goto LABEL_11;
    goto LABEL_17;
  }
  __break(0x5512u);
  if ( (_DWORD)StatusReg )
    JUMPOUT(0x116AF4);
  return _bpf_trace_sched_switch_with_ctrs();
}
