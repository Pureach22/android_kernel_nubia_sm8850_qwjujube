void __fastcall perf_trace_sched_switch_with_ctrs(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v12; // x0
  _QWORD *v13; // x9
  unsigned __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x9
  int v19; // w9
  unsigned int v20; // w9
  unsigned int v21; // w10
  int v22; // w11
  unsigned __int64 v23; // x10
  __int64 v24; // x10
  unsigned __int64 v25; // x10
  __int64 v26; // x13
  __int64 v27; // x14
  __int64 v28; // x13
  unsigned __int64 v29; // x14
  char *v30; // x15
  __int64 v31; // x16
  __int64 v32; // x14
  unsigned __int64 v33; // x15
  char *v34; // x16
  __int64 v35; // x17
  __int64 v36; // x15
  unsigned __int64 v37; // x16
  char *v38; // x17
  __int64 v39; // x1
  __int64 v40; // x16
  unsigned __int64 v41; // x11
  char *v42; // x12
  __int64 v43; // x17
  __int64 v44; // x11
  unsigned __int64 v45; // x13
  char *v46; // x14
  __int64 v47; // x15
  unsigned __int64 v48; // x12
  __int64 v49; // x17
  __int64 v50; // x2
  unsigned __int64 v51; // x17
  char *v52; // x3
  __int64 v53; // x4
  unsigned __int64 v54; // x3
  char *v55; // x8
  __int64 v56; // x9
  __int64 v57; // x8
  __int64 v58; // x2
  __int64 v59; // x5
  __int64 v60; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v61; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v62[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v63; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = 0;
  v10 = *(_QWORD *)(a1 + 104);
  v61 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v10) || (v12 = perf_trace_buf_alloc(140, v62, &v61)) == 0 )
  {
LABEL_32:
    _ReadStatusReg(SP_EL0);
    JUMPOUT(0x5299C);
  }
  v13 = (_QWORD *)v62[0];
  *(_QWORD *)(v62[0] + 232LL) = &v63;
  v13[31] = &v60;
  v13[32] = v5;
  v13[33] = 5;
  v14 = _ReadStatusReg(SP_EL0);
  v15 = *(_QWORD *)(a3 + 2328);
  v16 = *(unsigned int *)(v14 + 40);
  *(_QWORD *)(v12 + 16) = *(_QWORD *)(a3 + 2320);
  *(_QWORD *)(v12 + 24) = v15;
  v17 = *(_QWORD *)(a4 + 2328);
  *(_QWORD *)(v12 + 32) = *(_QWORD *)(a4 + 2320);
  *(_QWORD *)(v12 + 40) = v17;
  if ( v14 == a3 )
  {
    if ( (a2 & 1) != 0 )
    {
      v18 = 256;
    }
    else
    {
      v19 = *(_DWORD *)(a3 + 48);
      if ( (v19 & 0x9000) != 0 )
      {
        v18 = 2;
      }
      else
      {
        if ( (~v19 & 0x402) != 0 )
          v20 = ((unsigned __int8)*(_DWORD *)(a3 + 1696) | (unsigned __int8)v19) & 0x7F;
        else
          v20 = 128;
        v21 = 0x80000000 >> __clz(v20);
        if ( v20 )
          v18 = v21;
        else
          v18 = 0;
      }
    }
    *(_QWORD *)(v12 + 48) = v18;
    *(_DWORD *)(v12 + 8) = *(_DWORD *)(a3 + 1800);
    *(_DWORD *)(v12 + 12) = *(_DWORD *)(a4 + 1800);
    if ( (unsigned int)v16 < 0x20 )
    {
      v22 = *(_DWORD *)((char *)&cntenset_val + *((_QWORD *)&_per_cpu_offset + v16));
      if ( v22 < 0 )
      {
        v23 = _ReadStatusReg(PMCCNTR_EL0);
        *(_QWORD *)(v12 + 56) = v23 - *(_QWORD *)((char *)&previous_ccnt + *((_QWORD *)&_per_cpu_offset + v16));
        *(_QWORD *)((char *)&previous_ccnt + *((_QWORD *)&_per_cpu_offset + v16)) = v23;
      }
      v24 = 0;
      if ( (v22 & 1) != 0 )
      {
        _WriteStatusReg(PMSELR_EL0, 0);
        __isb(0xFu);
        v25 = _ReadStatusReg(PMXEVCNTR_EL0);
        v26 = *((_QWORD *)&_per_cpu_offset + v16);
        v27 = *(_QWORD *)((char *)&previous_l1_cnts + v26);
        *(_QWORD *)((char *)&previous_l1_cnts + v26) = v25;
        v24 = v25 - v27;
      }
      if ( (v22 & 2) != 0 )
      {
        _WriteStatusReg(PMSELR_EL0, 1u);
        __isb(0xFu);
        v45 = _ReadStatusReg(PMXEVCNTR_EL0);
        v46 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v16);
        v47 = *((_QWORD *)v46 + 1);
        *((_QWORD *)v46 + 1) = v45;
        v28 = v45 - v47;
        if ( (v22 & 4) != 0 )
        {
LABEL_22:
          _WriteStatusReg(PMSELR_EL0, 2u);
          __isb(0xFu);
          v29 = _ReadStatusReg(PMXEVCNTR_EL0);
          v30 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v16);
          v31 = *((_QWORD *)v30 + 2);
          *((_QWORD *)v30 + 2) = v29;
          v32 = v29 - v31;
          if ( (v22 & 8) != 0 )
            goto LABEL_23;
          goto LABEL_28;
        }
      }
      else
      {
        v28 = 0;
        if ( (v22 & 4) != 0 )
          goto LABEL_22;
      }
      v32 = 0;
      if ( (v22 & 8) != 0 )
      {
LABEL_23:
        _WriteStatusReg(PMSELR_EL0, 3u);
        __isb(0xFu);
        v33 = _ReadStatusReg(PMXEVCNTR_EL0);
        v34 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v16);
        v35 = *((_QWORD *)v34 + 3);
        *((_QWORD *)v34 + 3) = v33;
        v36 = v33 - v35;
        if ( (v22 & 0x10) != 0 )
          goto LABEL_24;
        goto LABEL_29;
      }
LABEL_28:
      v36 = 0;
      if ( (v22 & 0x10) != 0 )
      {
LABEL_24:
        _WriteStatusReg(PMSELR_EL0, 4u);
        __isb(0xFu);
        v37 = _ReadStatusReg(PMXEVCNTR_EL0);
        v38 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v16);
        v39 = *((_QWORD *)v38 + 4);
        *((_QWORD *)v38 + 4) = v37;
        v40 = v37 - v39;
        if ( (v22 & 0x20) != 0 )
        {
LABEL_25:
          _WriteStatusReg(PMSELR_EL0, 5u);
          __isb(0xFu);
          v41 = _ReadStatusReg(PMXEVCNTR_EL0);
          v42 = (char *)&previous_l1_cnts + *((_QWORD *)&_per_cpu_offset + v16);
          v43 = *((_QWORD *)v42 + 5);
          *((_QWORD *)v42 + 5) = v41;
          v44 = v41 - v43;
LABEL_31:
          v48 = _ReadStatusReg(AMEVCNTR00_EL0);
          v49 = *((_QWORD *)&_per_cpu_offset + v16);
          v50 = *(_QWORD *)((char *)&previous_amu_cnts + v49);
          *(_QWORD *)((char *)&previous_amu_cnts + v49) = v48;
          v51 = _ReadStatusReg(AMEVCNTR02_EL0);
          v52 = (char *)&previous_amu_cnts + *((_QWORD *)&_per_cpu_offset + v16);
          v53 = *((_QWORD *)v52 + 1);
          *((_QWORD *)v52 + 1) = v51;
          v54 = _ReadStatusReg(AMEVCNTR03_EL0);
          v55 = (char *)&previous_amu_cnts + *((_QWORD *)&_per_cpu_offset + v16);
          v56 = *((_QWORD *)v55 + 2);
          *((_QWORD *)v55 + 2) = v54;
          v57 = v48 - v50;
          v58 = v61;
          v59 = v62[0];
          *(_QWORD *)(v12 + 64) = v24;
          *(_QWORD *)(v12 + 72) = v28;
          *(_QWORD *)(v12 + 80) = v32;
          *(_QWORD *)(v12 + 88) = v36;
          *(_QWORD *)(v12 + 96) = v40;
          *(_QWORD *)(v12 + 104) = v44;
          *(_QWORD *)(v12 + 112) = v57;
          *(_QWORD *)(v12 + 120) = v51 - v53;
          *(_QWORD *)(v12 + 128) = v54 - v56;
          perf_trace_run_bpf_submit(v12, 140, v58, a1, 1, v59, StatusReg + v10, 0);
          goto LABEL_32;
        }
LABEL_30:
        v44 = 0;
        goto LABEL_31;
      }
LABEL_29:
      v40 = 0;
      if ( (v22 & 0x20) != 0 )
        goto LABEL_25;
      goto LABEL_30;
    }
    __break(0x5512u);
  }
  __break(0x800u);
  JUMPOUT(0x529AC);
}
