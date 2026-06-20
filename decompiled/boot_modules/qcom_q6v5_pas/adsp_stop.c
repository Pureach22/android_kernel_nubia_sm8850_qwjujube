__int64 __fastcall adsp_stop(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  int v4; // w8
  int v5; // w21
  int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w20
  __int64 v10; // x21
  __int64 compatible_node; // x0
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x22
  unsigned __int64 v16; // x8
  int v17; // w24
  unsigned __int16 v18; // w8
  void *v19; // x0
  __int64 v20; // [xsp+8h] [xbp-68h] BYREF
  __int64 v21; // [xsp+10h] [xbp-60h]
  __int64 v22; // [xsp+18h] [xbp-58h]
  __int64 v23; // [xsp+20h] [xbp-50h]
  __int64 v24; // [xsp+28h] [xbp-48h]
  __int64 v25; // [xsp+30h] [xbp-40h]
  __int64 v26; // [xsp+38h] [xbp-38h]
  __int64 v27; // [xsp+40h] [xbp-30h]
  __int64 v28; // [xsp+48h] [xbp-28h]
  __int64 v29; // [xsp+50h] [xbp-20h]
  __int64 v30; // [xsp+58h] [xbp-18h]
  __int64 v31; // [xsp+60h] [xbp-10h]
  __int64 v32; // [xsp+68h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)qcom_q6v5_request_stop(v2 + 24, *(_QWORD *)(v2 + 1152)) == -110 )
  {
    dev_err(*(_QWORD *)v2, "timed out on wait\n");
    v3 = *(_QWORD *)(v2 + 72);
    if ( !v3 )
      goto LABEL_5;
  }
  else
  {
    v3 = *(_QWORD *)(v2 + 72);
    if ( !v3 )
      goto LABEL_5;
  }
  if ( (icc_set_bw(v3, 0xFFFFFFFFLL, 0xFFFFFFFFLL) & 0x80000000) != 0 )
  {
    dev_err(*(_QWORD *)(v2 + 24), "failed to set crypto_path bandwidth request\n");
    icc_set_bw(*(_QWORD *)(v2 + 72), 0, 0);
  }
LABEL_5:
  if ( (unsigned int)qcom_scm_pas_shutdown(*(unsigned int *)(v2 + 456)) )
  {
    if ( *(_BYTE *)(v2 + 488) != 1 )
      goto LABEL_40;
    v4 = -49;
    do
    {
      v5 = v4;
      msleep(100);
      v6 = qcom_scm_pas_shutdown(*(unsigned int *)(v2 + 456));
      if ( v6 != -22 )
        break;
      v4 = v5 + 1;
    }
    while ( v5 );
    if ( v6 )
LABEL_40:
      panic("Panicking, remoteproc %s failed to shutdown.\n", *(const char **)(a1 + 24));
  }
  v7 = *(unsigned int *)(v2 + 460);
  if ( (_DWORD)v7 && (unsigned int)qcom_scm_pas_shutdown(v7) )
    panic("Panicking, remoteproc %s dtb failed to shutdown.\n", *(const char **)(a1 + 24));
  v8 = *(_QWORD *)(v2 + 72);
  if ( v8 && (icc_set_bw(v8, 0, 0) & 0x80000000) != 0 )
  {
    dev_err(*(_QWORD *)(v2 + 24), "failed to set crypto_path bandwidth request\n");
    icc_set_bw(*(_QWORD *)(v2 + 72), 0, 0);
  }
  if ( (unsigned int)qcom_q6v5_unprepare(v2 + 24) )
    qcom_pas_handover(v2 + 24);
  if ( *(_DWORD *)(v2 + 484) )
  {
    v9 = qcom_smem_bust_hwspin_lock_by_host();
    if ( !*(_DWORD *)(v2 + 744) )
      goto LABEL_28;
  }
  else
  {
    v9 = 0;
    if ( !*(_DWORD *)(v2 + 744) )
      goto LABEL_28;
  }
  if ( (*(_BYTE *)(v2 + 752) & 1) != 0 )
    goto LABEL_28;
  v10 = *(_QWORD *)(v2 + 16);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-mss-dsm");
  if ( !compatible_node )
  {
    v19 = &unk_B627;
LABEL_38:
    printk(v19, "qcom,msm-imem-mss-dsm");
    goto LABEL_28;
  }
  if ( (of_address_to_resource(compatible_node, 0, &v20) & 0x80000000) != 0 )
  {
    v19 = &unk_AD45;
    goto LABEL_38;
  }
  v12 = ioremap_prot();
  if ( v12 )
  {
    v14 = v12;
    if ( v21 + 1 != v20 )
    {
      v16 = 0;
      v17 = 4;
      do
      {
        v18 = *(_WORD *)(v14 + v16);
        if ( v18 && *(_WORD *)(v14 + v17 - 2) )
          rproc_coredump_add_custom_segment(
            v10,
            (unsigned __int64)v18 << 16,
            (unsigned __int64)*(unsigned __int16 *)(v14 + v17 - 2) << 16,
            &adsp_segment_dump,
            0);
        v16 = v17;
        v17 += 4;
      }
      while ( v21 - v20 + 1 > v16 );
    }
    iounmap(v14);
  }
  else
  {
    printk(&unk_B272, v13);
  }
LABEL_28:
  adsp_unassign_memory_region(v2);
  ++*(_QWORD *)(v2 + 328);
  _ReadStatusReg(SP_EL0);
  return v9;
}
