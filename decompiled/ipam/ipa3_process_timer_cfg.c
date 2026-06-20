__int64 __fastcall ipa3_process_timer_cfg(unsigned int a1, _BYTE *a2, unsigned __int8 *a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w24
  unsigned int v10; // w23
  unsigned int v11; // w0
  __int64 v12; // x8
  unsigned int v13; // w22
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w4
  unsigned int v17; // w4
  unsigned int v18; // w4
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // [xsp+8h] [xbp-18h] BYREF
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v42 = 0;
  v43 = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d time in usec=%u\n", "ipa3_process_timer_cfg", 9547, a1);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d time in usec=%u\n", "ipa3_process_timer_cfg", 9547, a1);
      v6 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v6 + 32240) <= 0x10u )
  {
    printk(&unk_3D0965, "ipa3_process_timer_cfg");
    v32 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v33 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v33 )
      {
        ipc_log_string(
          v33,
          "ipa %s:%d Invalid IPA version %d\n",
          "ipa3_process_timer_cfg",
          9550,
          *(_DWORD *)(ipa3_ctx + 32240));
        v32 = ipa3_ctx;
      }
      v34 = v32 + 32240;
      v35 = *(_QWORD *)(v34 + 1920);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d Invalid IPA version %d\n", "ipa3_process_timer_cfg", 9550, *(_DWORD *)v34);
    }
    goto LABEL_62;
  }
  if ( !a1 )
  {
    result = 0;
    *a2 = 0;
    *a3 = 0;
    goto LABEL_36;
  }
  ipahal_read_reg_n_fields(101, 0, &v42);
  v9 = ipa3_time_gran_usec_step((unsigned int)v42);
  v10 = ipa3_time_gran_usec_step(HIDWORD(v42));
  v11 = ipa3_time_gran_usec_step((unsigned int)v43);
  v12 = ipa3_ctx;
  v13 = v11;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d gran0 usec step=%u  gran1 usec step=%u gran2 usec step=%u\n",
        "ipa3_process_timer_cfg",
        9568,
        v9,
        v10,
        v13);
      v12 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v12 + 34160);
    if ( v15 )
      ipc_log_string(
        v15,
        "ipa %s:%d gran0 usec step=%u  gran1 usec step=%u gran2 usec step=%u\n",
        "ipa3_process_timer_cfg",
        9568,
        v9,
        v10,
        v13);
  }
  v16 = a1 / v9;
  if ( !(a1 % v9) )
  {
    if ( v16 <= 0x1F )
    {
      *a2 = 0;
      *a3 = v16;
      v22 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_35;
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d Matched: generator=0, units=%u\n", "ipa3_process_timer_cfg", 9576, v16);
        v22 = ipa3_ctx;
      }
      result = *(_QWORD *)(v22 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Matched: generator=0, units=%u\n", "ipa3_process_timer_cfg", 9576, *a3);
        goto LABEL_35;
      }
      goto LABEL_36;
    }
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d gran0 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9579);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d gran0 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9579);
    }
  }
  v17 = a1 / v10;
  if ( !(a1 % v10) )
  {
    if ( v17 <= 0x1F )
    {
      *a2 = 1;
      *a3 = v17;
      v24 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_35;
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Matched: generator=1, units=%u\n", "ipa3_process_timer_cfg", 9588, v17);
        v24 = ipa3_ctx;
      }
      result = *(_QWORD *)(v24 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Matched: generator=1, units=%u\n", "ipa3_process_timer_cfg", 9588, *a3);
        goto LABEL_35;
      }
      goto LABEL_36;
    }
    v29 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d gran1 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9591);
        v29 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v29 + 34160);
      if ( v31 )
        ipc_log_string(v31, "ipa %s:%d gran1 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9591);
    }
  }
  v18 = a1 / v13;
  if ( a1 % v13 )
  {
LABEL_57:
    printk(&unk_3F004B, "ipa3_process_timer_cfg");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(
          v40,
          "ipa %s:%d Cannot match requested time to configured granularities\n",
          "ipa3_process_timer_cfg",
          9606);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(
          v41,
          "ipa %s:%d Cannot match requested time to configured granularities\n",
          "ipa3_process_timer_cfg",
          9606);
    }
LABEL_62:
    result = 0xFFFFFFFFLL;
    goto LABEL_36;
  }
  if ( v18 > 0x1F )
  {
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d gran2 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9603);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d gran2 cannot be used due to range limit\n", "ipa3_process_timer_cfg", 9603);
    }
    goto LABEL_57;
  }
  *a2 = 2;
  *a3 = v18;
  v19 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_35:
    result = 0;
    goto LABEL_36;
  }
  v20 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d Matched: generator=2, units=%u\n", "ipa3_process_timer_cfg", 9600, v18);
    v19 = ipa3_ctx;
  }
  result = *(_QWORD *)(v19 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Matched: generator=2, units=%u\n", "ipa3_process_timer_cfg", 9600, *a3);
    goto LABEL_35;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
