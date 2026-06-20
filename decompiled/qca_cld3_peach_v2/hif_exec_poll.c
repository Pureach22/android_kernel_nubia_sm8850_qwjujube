__int64 __fastcall hif_exec_poll(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x25
  int v4; // w22
  __int64 v6; // x24
  __int64 v7; // x19
  int v8; // w23
  unsigned int v9; // w21
  __int64 *v10; // x26
  __int64 v11; // x0
  int v12; // w2
  _DWORD *v13; // x9
  __int64 v14; // x0
  _BYTE *v15; // x27
  int v16; // w23
  int v17; // w0
  int v19; // w22
  int v20; // w28
  unsigned int v21; // w9
  unsigned int v27; // w11
  __int64 v28; // x27
  __int64 v29; // x0
  int v30; // w2
  __int64 (__fastcall *v32)(_QWORD); // x8
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 v35; // x8
  int v36; // w10
  unsigned int v37; // w21
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x1
  __int64 v41; // x8
  unsigned __int64 v42; // x9
  unsigned int v43; // w9
  __int64 v44; // x10
  __int64 v45; // x19
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x20
  __int64 v49; // x21
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 is_one_msi; // x0
  __int64 v54; // x1
  __int64 v55; // x0
  int v56; // w2
  __int64 v57; // x22
  __int64 v58; // x0
  int v59; // w2
  unsigned int v61; // w10
  char v62; // [xsp+0h] [xbp-30h]
  __int64 v63; // [xsp+8h] [xbp-28h] BYREF
  __int64 v64; // [xsp+10h] [xbp-20h]
  __int64 v65; // [xsp+18h] [xbp-18h]
  __int64 v66; // [xsp+20h] [xbp-10h]
  __int64 v67; // [xsp+28h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = a2;
  v6 = a1 - 6208;
  v67 = v2;
  v7 = *(_QWORD *)(a1 - 6200);
  v8 = *(_DWORD *)(a1 - 5972);
  v9 = *(_DWORD *)(StatusReg + 40);
  v10 = (__int64 *)(a1 - 3496);
  *(_QWORD *)(a1 - 3496) = sched_clock(a1, a2);
  v11 = *(_QWORD *)(a1 - 6200);
  v12 = *(_DWORD *)(a1 - 5976);
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v66 = 3;
  hif_hist_record_event(v11, (__int64)&v63, v12);
  v62 = v8;
  v13 = *(_DWORD **)(a1 - 5952);
  v14 = *(_QWORD *)(a1 - 5960);
  v15 = (_BYTE *)(a1 - 3488);
  if ( v4 )
    v16 = (v4 << v8) - 1;
  else
    v16 = 0;
  *v15 = 0;
  if ( *(v13 - 1) != -4250500 )
    __break(0x8229u);
  v17 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v13)(v14, (unsigned int)v16, v9);
  _X8 = (unsigned int *)(a1 - 3280);
  v19 = v17;
  v20 = v17;
  v21 = *(_DWORD *)(a1 - 3280);
  do
  {
    if ( !v21 )
    {
      if ( (*v15 & 1) == 0 && v17 < v16 )
      {
        v28 = v6;
        goto LABEL_18;
      }
      is_one_msi = pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(v7 + 576) + 40LL));
      v28 = v6;
      if ( (is_one_msi & 1) != 0
        && !*(_DWORD *)(a1 - 3504)
        && (unsigned __int64)(sched_clock(is_one_msi, v54) - *(_QWORD *)(a1 - 3272)) >= 0x5F5E100 )
      {
        v65 = 0;
        v66 = 0;
        v55 = *(_QWORD *)(a1 - 6200);
        v63 = 0;
        v64 = 0;
        v56 = *(_DWORD *)(a1 - 5976);
        LODWORD(v66) = 8;
        hif_hist_record_event(v55, (__int64)&v63, v56);
        goto LABEL_18;
      }
      v58 = *(_QWORD *)(a1 - 6200);
      v59 = *(_DWORD *)(a1 - 5976);
      v65 = 0;
      v63 = 0;
      v64 = 0;
      v66 = 7;
      v33 = hif_hist_record_event(v58, (__int64)&v63, v59);
      if ( v9 <= 0x1F )
      {
        v20 = v16;
        goto LABEL_23;
      }
      goto LABEL_55;
    }
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v27 = __ldxr(_X8);
      if ( v27 != v21 )
        break;
      if ( !__stlxr(v21 + 1, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v27 == v21;
    v21 = v27;
  }
  while ( !_ZF );
  v28 = v6;
  if ( v17 >= v16 )
    v20 = v16 - 1;
  else
    v20 = v17;
LABEL_18:
  v29 = *(_QWORD *)(a1 - 6200);
  v30 = *(_DWORD *)(a1 - 5976);
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v66 = 6;
  hif_hist_record_event(v29, (__int64)&v63, v30);
  napi_complete_done(a1, 0);
  _X8 = (unsigned int *)(v7 + 676);
  __asm { PRFM            #0x11, [X8] }
  do
    v61 = __ldxr(_X8);
  while ( __stxr(v61 - 1, _X8) );
  v32 = *(__int64 (__fastcall **)(_QWORD))(a1 - 5936);
  if ( *((_DWORD *)v32 - 1) != -836874276 )
    __break(0x8228u);
  v33 = v32(v28);
  if ( v9 >= 0x20 )
    goto LABEL_55;
  ++*(_DWORD *)(a1 + 72LL * v9 - 5824);
LABEL_23:
  v35 = a1 - 5832 + 72LL * v9;
  v36 = *(_DWORD *)(v35 + 12) + v19;
  ++*(_DWORD *)(v35 + 4);
  *(_DWORD *)(v35 + 12) = v36;
  ++*(_DWORD *)(StatusReg + 16);
  v37 = *(_DWORD *)(StatusReg + 40);
  v38 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v38;
  if ( !v38 || !*(_QWORD *)(StatusReg + 16) )
    v33 = preempt_schedule(v33);
  v39 = sched_clock(v33, v34);
  if ( v37 >= 0x20 )
    goto LABEL_55;
  v41 = a1 - 5832 + 72LL * v37;
  v42 = v39 - *v10;
  if ( v42 > *(_QWORD *)(v41 + 48) )
    *(_QWORD *)(v41 + 48) = v42;
  v43 = (unsigned int)(v42 / 0x3E8) / 0x1F4;
  if ( v43 >= 3 )
    v43 = 3;
  v44 = *(_QWORD *)(a1 - 6200);
  ++*(_DWORD *)(v41 + 4LL * v43 + 56);
  if ( *(_BYTE *)(v44 + 26436) == 1 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v45 = *(unsigned int *)(StatusReg + 40);
    v46 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v46;
    if ( !v46 || !*(_QWORD *)(StatusReg + 16) )
      v39 = preempt_schedule(v39);
    v47 = sched_clock(v39, v40);
    v48 = *v10;
    ++*(_DWORD *)(StatusReg + 16);
    v49 = *(_QWORD *)((char *)&ksoftirqd + _ReadStatusReg(TPIDR_EL1));
    v50 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v50;
    if ( v50 && *(_QWORD *)(StatusReg + 16) )
    {
      if ( (unsigned int)v45 < 0x20 )
        goto LABEL_36;
LABEL_55:
      __break(0x5512u);
    }
    v57 = v47;
    preempt_schedule_notrace(v47);
    v47 = v57;
    if ( (unsigned int)v45 >= 0x20 )
      goto LABEL_55;
LABEL_36:
    v51 = 2952;
    if ( StatusReg == v49 )
      v51 = 3208;
    *(_QWORD *)(v28 + v51 + 8 * v45) += v47 - v48;
  }
  _ReadStatusReg(SP_EL0);
  if ( v20 )
    return (unsigned int)((v20 + 1) >> v62);
  else
    return 0;
}
