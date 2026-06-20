__int64 __fastcall cam_icp_mgr_hfi_init(__int64 a1)
{
  unsigned int *v2; // x21
  int v3; // w9
  __int64 v4; // x7
  __int64 v5; // x10
  int v6; // w8
  __int64 v7; // x1
  int v8; // w9
  __int64 v9; // x7
  __int64 v10; // x10
  int v11; // w9
  __int64 v12; // x7
  __int64 v13; // x10
  int v14; // w9
  __int64 v15; // x7
  __int64 v16; // x10
  int v17; // w9
  __int64 v18; // x7
  __int64 v19; // x10
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x7
  unsigned int v30; // w9
  __int64 v31; // x10
  __int64 v32; // x8
  __int64 v33; // x10
  unsigned int v34; // w20
  int v35; // w25
  __int64 v36; // x26
  unsigned int hfi_device_ops; // w0
  const char *v38; // x5
  __int64 v39; // x6
  __int64 v40; // x4
  unsigned int v41; // w6
  unsigned int v42; // w7
  __int64 v43; // x8
  __int64 v45; // [xsp+20h] [xbp-130h] BYREF
  _QWORD v46[37]; // [xsp+28h] [xbp-128h] BYREF

  v46[36] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int **)(a1 + 80);
  memset(&v46[2], 0, 0x110u);
  v45 = 0;
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hfi_init",
      5501,
      "[%s] ICP device interface is invalid",
      (const char *)(a1 + 112));
    v34 = -22;
    goto LABEL_38;
  }
  v3 = *(_DWORD *)(a1 + 176);
  v4 = *(_QWORD *)(a1 + 168);
  v5 = *(_QWORD *)(a1 + 192);
  v6 = debug_priority;
  LODWORD(v46[2]) = v3;
  v7 = debug_mdl & 0x100;
  v46[0] = v5;
  v46[1] = v4;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4721,
      "[%s] qtbl kva = %llx IOVA = %x length = %lld\n",
      (const char *)(a1 + 112),
      v4,
      v3,
      v5);
    v6 = debug_priority;
    v7 = debug_mdl & 0x100;
  }
  v8 = *(_DWORD *)(a1 + 216);
  v9 = *(_QWORD *)(a1 + 208);
  v10 = *(_QWORD *)(a1 + 232);
  LODWORD(v46[5]) = v8;
  v46[3] = v10;
  v46[4] = v9;
  if ( v7 && !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4727,
      "[%s] cmd_q kva = %llx IOVA = %x length = %lld\n",
      (const char *)(a1 + 112),
      v9,
      v8,
      v10);
    v6 = debug_priority;
    v7 = debug_mdl & 0x100;
  }
  v11 = *(_DWORD *)(a1 + 256);
  v12 = *(_QWORD *)(a1 + 248);
  v13 = *(_QWORD *)(a1 + 272);
  LODWORD(v46[8]) = v11;
  v46[6] = v13;
  v46[7] = v12;
  if ( v7 && !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4733,
      "[%s] msg_q kva = %llx IOVA = %x length = %lld\n",
      (const char *)(a1 + 112),
      v12,
      v11,
      v13);
    v6 = debug_priority;
    v7 = debug_mdl & 0x100;
  }
  v14 = *(_DWORD *)(a1 + 296);
  v15 = *(_QWORD *)(a1 + 288);
  v16 = *(_QWORD *)(a1 + 312);
  LODWORD(v46[11]) = v14;
  v46[9] = v16;
  v46[10] = v15;
  if ( v7 && !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4739,
      "[%s] dbg_q kva = %llx IOVA = %x length = %lld\n",
      (const char *)(a1 + 112),
      v15,
      v14,
      v16);
    v6 = debug_priority;
    v7 = debug_mdl & 0x100;
  }
  v17 = *(_DWORD *)(a1 + 456);
  v18 = *(_QWORD *)(a1 + 448);
  v19 = *(_QWORD *)(a1 + 472);
  LODWORD(v46[14]) = v17;
  v46[12] = v19;
  v46[13] = v18;
  if ( v7 && !v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4746,
      "[%s] sfr kva = %llx IOVA = %x length = %lld\n",
      (const char *)(a1 + 112),
      v18,
      v17,
      v19);
  v20 = *(_QWORD *)(a1 + 328);
  v21 = *(_QWORD *)(a1 + 352);
  LODWORD(v46[17]) = *(_DWORD *)(a1 + 336);
  v22 = *(_QWORD *)(a1 + 728);
  v46[15] = v21;
  v46[16] = v20;
  v23 = *(_QWORD *)(a1 + 736);
  LOBYTE(v21) = *(_BYTE *)(a1 + 44235);
  LODWORD(v46[20]) = v22;
  LODWORD(v22) = *(_DWORD *)(a1 + 416);
  v46[18] = v23;
  v24 = *(_QWORD *)(a1 + 432);
  LODWORD(v46[23]) = v22;
  v46[21] = v24;
  if ( ((v21 & 1) != 0 || *(_BYTE *)(a1 + 44236) == 1)
    && (v25 = *(unsigned int *)(a1 + 920),
        v26 = *(_QWORD *)(a1 + 928),
        LODWORD(v46[35]) = *(_DWORD *)(a1 + 920),
        v46[33] = v26,
        (debug_mdl & 0x100) != 0)
    && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4763,
      "device memory [iova = 0x%llx len = 0x%llx]",
      v25,
      v26);
    v27 = *(_QWORD *)(a1 + 808);
    if ( !v27 )
      goto LABEL_26;
  }
  else
  {
    v27 = *(_QWORD *)(a1 + 808);
    if ( !v27 )
      goto LABEL_26;
  }
  v28 = *(_QWORD *)(a1 + 816);
  if ( v28 )
  {
    v29 = *(_QWORD *)(a1 + 792);
    v30 = v28 + v27;
    v31 = *(_QWORD *)(a1 + 800);
    LODWORD(v46[29]) = v30;
    v32 = v27 - v29;
    LODWORD(v46[26]) = v29;
    v46[24] = v32;
    v33 = v31 + v29 - v30;
    v46[27] = v33;
    goto LABEL_27;
  }
LABEL_26:
  LODWORD(v29) = *(_DWORD *)(a1 + 792);
  v32 = *(_QWORD *)(a1 + 800);
  v33 = 0;
  v30 = 0;
  LODWORD(v46[29]) = 0;
  LODWORD(v46[26]) = v29;
  v46[24] = v32;
  v46[27] = 0;
LABEL_27:
  v35 = *(_DWORD *)(a1 + 856);
  v36 = *(_QWORD *)(a1 + 864);
  LODWORD(v46[32]) = v35;
  v46[30] = v36;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_populate_hfi_mem_info",
      4801,
      "[%s] IO region1 IOVA = %X length = %lld, IO region2 IOVA = %X length = %lld",
      (const char *)(a1 + 112),
      v29,
      v32,
      v30,
      v33);
  hfi_device_ops = cam_icp_get_hfi_device_ops(*v2, &v45);
  if ( hfi_device_ops )
  {
    v34 = hfi_device_ops;
    v38 = "[%s] Fail to get HFI device ops rc: %d";
    v39 = a1 + 112;
    v40 = 5509;
LABEL_37:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hfi_init",
      v40,
      v38,
      v39,
      v34);
    goto LABEL_38;
  }
  if ( *(_BYTE *)(a1 + 44235) == 1 )
  {
    v41 = *(_DWORD *)(a1 + 536);
    v42 = *(_DWORD *)(a1 + 496);
    if ( v41 >= v42 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hfi_init",
        5520,
        "global sync memory [start: 0x%x] expected to be at the start of FW uncached [uncached_generic start: 0x%x]",
        v41,
        v42);
      v34 = -22;
      goto LABEL_38;
    }
    v43 = *(_QWORD *)(a1 + 552);
    LODWORD(v46[32]) = v35 + v43;
    v46[30] = v36 - v43;
  }
  v34 = cam_hfi_init(*(unsigned int *)(a1 + 156), v46, v45, *((_QWORD *)v2 + 14), 0);
  if ( v34 )
  {
    v38 = "[%s] Failed to init HFI rc=%d";
    v39 = a1 + 112;
    v40 = 5538;
    goto LABEL_37;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_hfi_init",
      5543,
      "[%s] hw mgr succeed hfi init with hfi handle: %d",
      (const char *)(a1 + 112),
      *(_DWORD *)(a1 + 156));
    v34 = 0;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v34;
}
