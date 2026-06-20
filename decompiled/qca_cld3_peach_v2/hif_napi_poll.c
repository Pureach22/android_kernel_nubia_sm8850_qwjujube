__int64 __fastcall hif_napi_poll(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w19
  __int64 v12; // x20
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x27
  unsigned int v15; // w5
  __int64 v16; // x26
  _DWORD *v17; // x25
  int v18; // w1
  __int64 v19; // x8
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 (__fastcall *v29)(_QWORD); // x8
  int v30; // w22
  unsigned int v31; // w8
  int v32; // w23
  int v33; // w8
  unsigned int v34; // w24
  unsigned __int64 v35; // x8
  __int64 v36; // x28
  __int64 v37; // x24
  char v38; // w27
  unsigned int v39; // w10
  __int64 v40; // x8
  int v41; // w8
  __int64 v42; // x8
  unsigned int v44; // w27
  __int64 v45; // x0
  unsigned int v46; // w28
  __int64 v47; // x27
  _DWORD *v48; // x26
  __int64 v49; // x0
  unsigned int v50; // w0
  unsigned int v51; // w25
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v66; // w10

  if ( !a1 )
  {
    qdf_trace_msg(0x3Du, 2u, "%s: hif context is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "hif_napi_poll");
    return 0;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v15 = *(_DWORD *)(StatusReg + 40);
  if ( v15 >= 0x20 )
    goto LABEL_45;
  v16 = a2 + 448;
  v17 = (_DWORD *)(a2 + 448 + 72LL * v15);
  v11 = a3;
  v13 = a2;
  v18 = *(unsigned __int8 *)(a2 + 433) - 1;
  v12 = a1;
  v19 = (unsigned int)(v17[1] + 1);
  v17[1] = v19;
  hif_record_ce_desc_event(a1, v18, 24, 0, 0, v15, v19);
  v20 = ce_per_engine_service(v12, (unsigned int)*(unsigned __int8 *)(v13 + 433) - 1);
  v29 = *(__int64 (__fastcall **)(_QWORD))(v13 + 2752);
  v30 = v20;
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != 251140989 )
      __break(0x8228u);
    v20 = v29(v13 - 2696);
  }
  if ( v30 )
  {
    v31 = v30 / *(unsigned __int8 *)(v13 + 432);
    v17[3] += v30;
    if ( v31 <= 1 )
      v32 = 1;
    else
      v32 = v31;
    v33 = v32 - 1;
    if ( v32 - 1 < 64 )
    {
      if ( v33 < 0 )
        v33 = v32 + 14;
      v34 = v33 >> 4;
      if ( (unsigned int)(v33 >> 4) > 4 )
        goto LABEL_45;
    }
    else
    {
      v34 = 3;
      v20 = qdf_trace_msg(
              0x3Du,
              2u,
              "%s: Bad bucket#(%d) > QCA_NAPI_NUM_BUCKETS(%d) normalized %d, napi budget %d",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "hif_napi_poll",
              3,
              4,
              (unsigned int)v32,
              64);
    }
    ++v17[v34 + 5];
  }
  else
  {
    v32 = 0;
  }
  v35 = *(unsigned __int8 *)(v13 + 433) - 1LL;
  if ( v35 > 0xB )
  {
LABEL_45:
    __break(0x5512u);
LABEL_46:
    _X8 = (unsigned int *)(v12 + 672);
    __asm { PRFM            #0x11, [X8] }
    do
      v66 = __ldxr(_X8);
    while ( __stxr(v66 - 1, _X8) );
    goto LABEL_35;
  }
  v36 = *(_QWORD *)(v13 - 8);
  v37 = *(_QWORD *)(v12 + 8 * v35 + 480);
  if ( (*(_BYTE *)(v36 + 2440) & 2) == 0 )
  {
    v38 = 0;
    if ( !v37 )
      goto LABEL_35;
    goto LABEL_29;
  }
  ++*(_DWORD *)(StatusReg + 16);
  v39 = *(_DWORD *)(StatusReg + 40);
  v40 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v40;
  if ( !v40 || !*(_QWORD *)(StatusReg + 16) )
  {
    v44 = v39;
    preempt_schedule(v20);
    v39 = v44;
  }
  v38 = 0;
  if ( (~*(unsigned __int8 *)(v36 + 2440) & 0xC) == 0 && hif_napi_cpu_denylist_ref_count >= 1 )
  {
    v41 = *(unsigned __int8 *)(v13 + 434);
    if ( v39 == v41 )
    {
      v38 = 0;
      goto LABEL_28;
    }
    v45 = *(unsigned int *)(v13 + 436);
    v46 = v39;
    v47 = v16;
    v48 = v17;
    *(_QWORD *)(v13 + 440) = 1 << v41;
    irq_modify_status(v45, 0x2000, 0);
    v49 = _irq_apply_affinity_hint(*(unsigned int *)(v13 + 436), v13 + 440, 1);
    v50 = qdf_status_from_os_return(v49);
    v51 = qdf_status_to_os_return(v50);
    irq_modify_status(*(unsigned int *)(v13 + 436), 0, 0x2000);
    if ( v51 )
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Setting irq affinity hint: %d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "hif_napi_correct_cpu",
        v51);
      goto LABEL_43;
    }
    if ( v46 <= 0x1F )
    {
      ++*(_DWORD *)(v47 + 72LL * v46 + 16);
LABEL_43:
      v38 = 1;
      v17 = v48;
      if ( !v37 )
        goto LABEL_35;
      goto LABEL_29;
    }
    goto LABEL_45;
  }
LABEL_28:
  if ( v37 )
  {
LABEL_29:
    if ( !(v38 & 1 | !ce_check_rx_pending(v37)) && v30 )
      goto LABEL_35;
    v42 = (unsigned int)(v17[2] + 1);
    v17[2] = v42;
    hif_record_ce_desc_event(v12, *(_DWORD *)(v37 + 8), 25, 0, 0, 0, v42);
    if ( v32 >= v11 )
      --v11;
    else
      v11 = v32;
    napi_complete_done(v13, 0);
    hif_irq_enable(v12);
    goto LABEL_46;
  }
LABEL_35:
  hif_record_ce_desc_event(v12, *(unsigned __int8 *)(v13 + 433) - 1, 26, 0, 0, v11, *(unsigned __int8 *)(v13 + 433));
  return (unsigned int)v11;
}
