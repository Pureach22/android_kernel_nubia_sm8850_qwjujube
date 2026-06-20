__int64 __fastcall ipa3_uc_mhi_print_stats(__int64 a1, int a2)
{
  int v4; // w21
  int v5; // w21
  int v6; // w21
  int v7; // w0
  __int64 v8; // x26
  char v9; // w8
  unsigned int v10; // w27
  char v11; // w21
  int v12; // w27
  __int64 v13; // x26
  int v14; // w27
  int v15; // w27
  int v16; // w27
  int v17; // w27
  int v18; // w27
  int v19; // w27
  int v20; // w27
  int v21; // w27
  int v22; // w27
  int v23; // w27
  int v24; // w27
  int v25; // w27
  int v26; // w27
  int v27; // w27
  int v28; // w27
  int v29; // w27
  int v30; // w27
  int v31; // w27
  int v32; // w27
  int v33; // w0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0

  if ( *(_QWORD *)(ipa3_uc_mhi_ctx + 32) )
  {
    v4 = scnprintf(a1, a2, "Common Stats:\n");
    v5 = scnprintf(a1 + v4, a2 - v4, "numULDLSync=0x%x\n", **(_DWORD **)(ipa3_uc_mhi_ctx + 32)) + v4;
    v6 = scnprintf(a1 + v5, a2 - v5, "numULTimerExpired=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + 4LL))
       + v5;
    v7 = scnprintf(a1 + v6, a2 - v6, "numChEvCtxWpRead=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + 8LL));
    v8 = 0;
    v9 = 1;
    v10 = v7 + v6;
    do
    {
      v11 = v9;
      v12 = scnprintf(a1 + (int)v10, (int)(a2 - v10), "Channel %d Stats:\n", v8) + v10;
      v13 = 80 * v8;
      v14 = scnprintf(
              a1 + v12,
              a2 - v12,
              "doorbellInt=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 16))
          + v12;
      v15 = scnprintf(
              a1 + v14,
              a2 - v14,
              "reProccesed=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 20))
          + v14;
      v16 = scnprintf(
              a1 + v15,
              a2 - v15,
              "bamFifoFull=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 24))
          + v15;
      v17 = scnprintf(
              a1 + v16,
              a2 - v16,
              "bamFifoEmpty=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 28))
          + v16;
      v18 = scnprintf(
              a1 + v17,
              a2 - v17,
              "bamFifoUsageHigh=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 32))
          + v17;
      v19 = scnprintf(
              a1 + v18,
              a2 - v18,
              "bamFifoUsageLow=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 36))
          + v18;
      v20 = scnprintf(a1 + v19, a2 - v19, "bamInt=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 40))
          + v19;
      v21 = scnprintf(a1 + v20, a2 - v20, "ringFull=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 44))
          + v20;
      v22 = scnprintf(a1 + v21, a2 - v21, "ringEmpty=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 48))
          + v21;
      v23 = scnprintf(
              a1 + v22,
              a2 - v22,
              "ringUsageHigh=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 52))
          + v22;
      v24 = scnprintf(
              a1 + v23,
              a2 - v23,
              "ringUsageLow=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 56))
          + v23;
      v25 = scnprintf(
              a1 + v24,
              a2 - v24,
              "delayedMsi=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 60))
          + v24;
      v26 = scnprintf(
              a1 + v25,
              a2 - v25,
              "immediateMsi=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 64))
          + v25;
      v27 = scnprintf(
              a1 + v26,
              a2 - v26,
              "thresholdMsi=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 68))
          + v26;
      v28 = scnprintf(
              a1 + v27,
              a2 - v27,
              "numSuspend=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 72))
          + v27;
      v29 = scnprintf(a1 + v28, a2 - v28, "numResume=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 76))
          + v28;
      v30 = scnprintf(a1 + v29, a2 - v29, "num_OOB=0x%x\n", *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 80))
          + v29;
      v31 = scnprintf(
              a1 + v30,
              a2 - v30,
              "num_OOB_timer_expiry=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 84))
          + v30;
      v32 = scnprintf(
              a1 + v31,
              a2 - v31,
              "num_OOB_moderation_timer_start=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 88))
          + v31;
      v33 = scnprintf(
              a1 + v32,
              a2 - v32,
              "num_db_mode_evt=0x%x\n",
              *(_DWORD *)(*(_QWORD *)(ipa3_uc_mhi_ctx + 32) + v13 + 92));
      v9 = 0;
      v8 = 1;
      v10 = v33 + v32;
    }
    while ( (v11 & 1) != 0 );
  }
  else
  {
    printk(&unk_3D046E, "ipa3_uc_mhi_print_stats");
    v35 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v36 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d MHI uc stats is not valid\n", "ipa3_uc_mhi_print_stats", 921);
        v35 = ipa3_ctx;
      }
      v37 = *(_QWORD *)(v35 + 34160);
      if ( v37 )
        ipc_log_string(v37, "ipa %s:%d MHI uc stats is not valid\n", "ipa3_uc_mhi_print_stats", 921);
    }
    return 0;
  }
  return v10;
}
