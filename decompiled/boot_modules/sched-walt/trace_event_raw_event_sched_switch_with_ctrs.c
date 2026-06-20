__int64 __fastcall trace_event_raw_event_sched_switch_with_ctrs(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  int v4; // w23
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x9
  __int64 v12; // x11
  unsigned __int64 StatusReg; // x10
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x9
  int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // w10
  int v20; // w11
  __int64 v21; // x10
  __int64 v22; // x12
  unsigned __int64 v23; // x14
  char *v24; // x15
  __int64 v25; // x13
  __int64 v26; // x13
  unsigned __int64 v27; // x15
  char *v28; // x16
  __int64 v29; // x14
  __int64 v30; // x14
  unsigned __int64 v31; // x16
  char *v32; // x17
  __int64 v33; // x15
  __int64 v34; // x15
  unsigned __int64 v35; // x16
  char *v36; // x17
  __int64 v37; // x11
  __int64 v38; // x11
  unsigned __int64 v39; // x10
  unsigned __int64 v40; // x10
  __int64 v41; // x13
  __int64 v42; // x14
  unsigned __int64 v43; // x13
  char *v44; // x14
  __int64 v45; // x12
  unsigned __int64 v46; // x16
  __int64 v47; // x17
  __int64 v48; // x2
  unsigned __int64 v49; // x17
  char *v50; // x3
  __int64 v51; // x4
  unsigned __int64 v52; // x3
  char *v53; // x8
  __int64 v54; // x9
  _QWORD v56[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v56[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v56, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    v8 = a1;
    if ( (result & 1) != 0 )
      goto LABEL_31;
  }
  result = trace_event_buffer_reserve(v56, v8, 136);
  if ( !result )
    goto LABEL_31;
  v11 = *(_QWORD *)(a3 + 2328);
  v12 = *(_QWORD *)(a3 + 2320);
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = *(unsigned int *)(StatusReg + 40);
  *(_QWORD *)(result + 16) = v12;
  *(_QWORD *)(result + 24) = v11;
  v15 = *(_QWORD *)(a4 + 2328);
  *(_QWORD *)(result + 32) = *(_QWORD *)(a4 + 2320);
  *(_QWORD *)(result + 40) = v15;
  if ( StatusReg == a3 )
  {
    if ( (a2 & 1) != 0 )
    {
      v16 = 256;
    }
    else
    {
      v17 = *(_DWORD *)(a3 + 48);
      if ( (v17 & 0x9000) != 0 )
      {
        v16 = 2;
      }
      else
      {
        if ( (~v17 & 0x402) != 0 )
          v18 = ((unsigned __int8)*(_DWORD *)(a3 + 1696) | (unsigned __int8)v17) & 0x7F;
        else
          v18 = 128;
        v19 = 0x80000000 >> __clz(v18);
        if ( v18 )
          v16 = v19;
        else
          v16 = 0;
      }
    }
    *(_QWORD *)(result + 48) = v16;
    *(_DWORD *)(result + 8) = *(_DWORD *)(a3 + 1800);
    *(_DWORD *)(result + 12) = *(_DWORD *)(a4 + 1800);
    if ( (unsigned int)v14 < 0x20 )
    {
      v20 = *(_DWORD *)((char *)&cntenset_val + *((_QWORD *)&_per_cpu_offset + v14));
      if ( v20 < 0 )
      {
        v39 = _ReadStatusReg(PMCCNTR_EL0);
        *(_QWORD *)(result + 56) = v39 - *(_QWORD *)((char *)&previous_ccnt + *((_QWORD *)&_per_cpu_offset + v14));
        *(_QWORD *)((char *)&previous_ccnt + *((_QWORD *)&_per_cpu_offset + v14)) = v39;
        v21 = 0;
        if ( (v20 & 1) == 0 )
        {
LABEL_17:
          if ( (v20 & 2) == 0 )
            goto LABEL_18;
          goto LABEL_25;
        }
      }
      else
      {
        v21 = 0;
        if ( (v20 & 1) == 0 )
          goto LABEL_17;
      }
      _WriteStatusReg(PMSELR_EL0, 0);
      __isb(0xFu);
      v40 = _ReadStatusReg(PMXEVCNTR_EL0);
      v41 = *((_QWORD *)&_per_cpu_offset + v14);
      v42 = *(_QWORD *)((char *)&previous_l1_cnts + v41);
      *(_QWORD *)((char *)&previous_l1_cnts + v41) = v40;
      v21 = v40 - v42;
      if ( (v20 & 2) == 0 )
      {
LABEL_18:
        v22 = 0;
        if ( (v20 & 4) != 0 )
          goto LABEL_19;
        goto LABEL_26;
      }
LABEL_25:
      _WriteStatusReg(PMSELR_EL0, 1u);
      __isb(0xFu);
      v43 = _ReadStatusReg(PMXEVCNTR_EL0);
      v44 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v14);
      v45 = *((_QWORD *)v44 + 1);
      *((_QWORD *)v44 + 1) = v43;
      v22 = v43 - v45;
      if ( (v20 & 4) != 0 )
      {
LABEL_19:
        _WriteStatusReg(PMSELR_EL0, 2u);
        __isb(0xFu);
        v23 = _ReadStatusReg(PMXEVCNTR_EL0);
        v24 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v14);
        v25 = *((_QWORD *)v24 + 2);
        *((_QWORD *)v24 + 2) = v23;
        v26 = v23 - v25;
        if ( (v20 & 8) != 0 )
          goto LABEL_20;
        goto LABEL_27;
      }
LABEL_26:
      v26 = 0;
      if ( (v20 & 8) != 0 )
      {
LABEL_20:
        _WriteStatusReg(PMSELR_EL0, 3u);
        __isb(0xFu);
        v27 = _ReadStatusReg(PMXEVCNTR_EL0);
        v28 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v14);
        v29 = *((_QWORD *)v28 + 3);
        *((_QWORD *)v28 + 3) = v27;
        v30 = v27 - v29;
        if ( (v20 & 0x10) != 0 )
          goto LABEL_21;
        goto LABEL_28;
      }
LABEL_27:
      v30 = 0;
      if ( (v20 & 0x10) != 0 )
      {
LABEL_21:
        _WriteStatusReg(PMSELR_EL0, 4u);
        __isb(0xFu);
        v31 = _ReadStatusReg(PMXEVCNTR_EL0);
        v32 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v14);
        v33 = *((_QWORD *)v32 + 4);
        *((_QWORD *)v32 + 4) = v31;
        v34 = v31 - v33;
        if ( (v20 & 0x20) != 0 )
        {
LABEL_22:
          _WriteStatusReg(PMSELR_EL0, 5u);
          __isb(0xFu);
          v35 = _ReadStatusReg(PMXEVCNTR_EL0);
          v36 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v14);
          v37 = *((_QWORD *)v36 + 5);
          *((_QWORD *)v36 + 5) = v35;
          v38 = v35 - v37;
LABEL_30:
          v46 = _ReadStatusReg(AMEVCNTR00_EL0);
          v47 = *((_QWORD *)&_per_cpu_offset + v14);
          v48 = *(_QWORD *)((char *)&previous_amu_cnts + v47);
          *(_QWORD *)((char *)&previous_amu_cnts + v47) = v46;
          v49 = _ReadStatusReg(AMEVCNTR02_EL0);
          v50 = (char *)&previous_amu_cnts + *((_QWORD *)&_per_cpu_offset + v14);
          v51 = *((_QWORD *)v50 + 1);
          *((_QWORD *)v50 + 1) = v49;
          v52 = _ReadStatusReg(AMEVCNTR03_EL0);
          v53 = (char *)&previous_amu_cnts + *((_QWORD *)&_per_cpu_offset + v14);
          v54 = *((_QWORD *)v53 + 2);
          *((_QWORD *)v53 + 2) = v52;
          *(_QWORD *)(result + 64) = v21;
          *(_QWORD *)(result + 72) = v22;
          *(_QWORD *)(result + 112) = v46 - v48;
          *(_QWORD *)(result + 120) = v49 - v51;
          *(_QWORD *)(result + 80) = v26;
          *(_QWORD *)(result + 88) = v30;
          *(_QWORD *)(result + 96) = v34;
          *(_QWORD *)(result + 104) = v38;
          *(_QWORD *)(result + 128) = v52 - v54;
          result = trace_event_buffer_commit(v56);
LABEL_31:
          _ReadStatusReg(SP_EL0);
          return result;
        }
LABEL_29:
        v38 = 0;
        goto LABEL_30;
      }
LABEL_28:
      v34 = 0;
      if ( (v20 & 0x20) != 0 )
        goto LABEL_22;
      goto LABEL_29;
    }
    __break(0x5512u);
  }
  __break(0x800u);
  if ( v4 )
    JUMPOUT(0x116438);
  return perf_trace_sched_switch_with_ctrs();
}
