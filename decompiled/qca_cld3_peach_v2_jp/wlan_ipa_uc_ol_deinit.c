__int64 __fastcall wlan_ipa_uc_ol_deinit(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // x8
  void (*v29)(void); // x8
  __int64 v30; // x21
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x8
  void (*v42)(void); // x8
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 (*v45)(void); // x8
  unsigned int v46; // w20
  int v47; // w2
  int v48; // w3
  int v49; // w4
  int v50; // w5
  int v51; // w6
  int v52; // w7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x0
  int v62; // w3
  int v63; // w4
  int v64; // w5
  int v65; // w6
  int v66; // w7
  __int64 v67; // x8
  __int64 (*v68)(void); // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w3
  int v78; // w4
  int v79; // w5
  int v80; // w6
  int v81; // w7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  int v90; // w3
  int v91; // w4
  int v92; // w5
  int v93; // w6
  int v94; // w7
  char v96[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v97; // [xsp+8h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x61u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_uc_ol_deinit");
  if ( (**(_BYTE **)(a1 + 1464) & 0x20) == 0 )
  {
    v18 = 0;
    goto LABEL_49;
  }
  wlan_ipa_uc_disable_pipes(a1, 1, v10, v11, v12, v13, v14, v15, v16, v17);
  v27 = *(_QWORD *)(a1 + 1456);
  if ( v27 && *(_QWORD *)v27 && (v28 = *(_QWORD *)(*(_QWORD *)v27 + 152LL)) != 0 )
  {
    v29 = *(void (**)(void))(v28 + 48);
    if ( v29 )
    {
      if ( *((_DWORD *)v29 - 1) != -251540498 )
        __break(0x8228u);
      v29();
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v19, v20, v21, v22, v23, v24, v25, v26, "cdp_ipa_deregister_op_cb");
  }
  v30 = 0;
  v31 = a1 + 1552;
  *(_DWORD *)(a1 + 7452) = 1;
  do
  {
    cancel_work_sync(v31);
    _qdf_mem_free(*(_QWORD *)(v31 + 48));
    *(_QWORD *)(v31 + 48) = 0;
    if ( (unsigned int)(v30 - 13) <= 1 )
    {
      _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v31 + 72) + 8LL));
      _qdf_mem_free(*(_QWORD *)(v31 + 72));
    }
    ++v30;
    v31 += 88;
  }
  while ( v30 != 16 );
  v40 = *(_QWORD *)(a1 + 1456);
  if ( v40 && *(_QWORD *)v40 && (v41 = *(_QWORD *)(*(_QWORD *)v40 + 152LL)) != 0 )
  {
    v42 = *(void (**)(void))(v41 + 16);
    if ( v42 )
    {
      if ( *((_DWORD *)v42 - 1) != 261447488 )
        __break(0x8228u);
      v42();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "cdp_ipa_iounmap_doorbell_vaddr");
  }
  if ( *(_BYTE *)(a1 + 6984) != 1 )
    goto LABEL_42;
  v43 = *(_QWORD *)(a1 + 1456);
  if ( v43 && *(_QWORD *)v43 && (v44 = *(_QWORD *)(*(_QWORD *)v43 + 152LL)) != 0 )
  {
    v45 = *(__int64 (**)(void))(v44 + 192);
    if ( !v45 )
      goto LABEL_31;
    if ( *((_DWORD *)v45 - 1) != -1922697876 )
      __break(0x8228u);
    v46 = v45();
    if ( !v46 )
    {
LABEL_31:
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: TX buffers unmapped from IPA",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_ipa_uc_ol_deinit");
      wlan_ipa_log_message(
        (int)"wlan_ipa_uc_ol_deinit",
        (int)"TX buffers unmapped from IPA",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v96[0]);
      v61 = *(_QWORD *)(a1 + 1456);
      if ( !v61 )
        goto LABEL_43;
      goto LABEL_35;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "cdp_ipa_tx_buf_smmu_unmapping");
    v46 = 16;
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Failure to unmap IPA Tx buffers (status=%d)",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wlan_ipa_uc_ol_deinit",
    v46);
  wlan_ipa_log_message(
    (int)"wlan_ipa_uc_ol_deinit",
    (int)"Failure to unmap IPA Tx buffers (status=%d)",
    v46,
    v62,
    v63,
    v64,
    v65,
    v66,
    v96[0]);
  v61 = *(_QWORD *)(a1 + 1456);
  if ( v61 )
  {
LABEL_35:
    if ( !*(_QWORD *)v61 )
      goto LABEL_43;
    v67 = *(_QWORD *)(*(_QWORD *)v61 + 152LL);
    if ( !v67 )
      goto LABEL_43;
    v68 = *(__int64 (**)(void))(v67 + 128);
    if ( v68 )
    {
      if ( *((_DWORD *)v68 - 1) != -1401535946 )
        __break(0x8228u);
      v18 = v68();
      if ( !v18 )
        goto LABEL_45;
      goto LABEL_44;
    }
LABEL_42:
    v18 = 0;
    goto LABEL_45;
  }
LABEL_43:
  qdf_trace_msg(0x45u, 1u, "%s invalid instance", v53, v54, v55, v56, v57, v58, v59, v60, "cdp_ipa_cleanup");
  v18 = 16;
LABEL_44:
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Failure to cleanup IPA pipes (status=%d)",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "wlan_ipa_uc_ol_deinit",
    v18);
  wlan_ipa_log_message(
    (int)"wlan_ipa_uc_ol_deinit",
    (int)"Failure to cleanup IPA pipes (status=%d)",
    v18,
    v77,
    v78,
    v79,
    v80,
    v81,
    v96[0]);
LABEL_45:
  qdf_mutex_acquire(a1 + 7224);
  *(_QWORD *)v96 = 0;
  while ( !(unsigned int)qdf_list_remove_front((_DWORD *)(a1 + 4016), v96) )
    _qdf_mem_free(*(__int64 *)v96);
  qdf_mutex_release(a1 + 7224);
  qdf_trace_msg(0x61u, 8u, "%s: exit: ret=%d", v82, v83, v84, v85, v86, v87, v88, v89, "wlan_ipa_uc_ol_deinit", v18);
  wlan_ipa_log_message((int)"wlan_ipa_uc_ol_deinit", (int)"exit: ret=%d", v18, v90, v91, v92, v93, v94, v96[0]);
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v18;
}
