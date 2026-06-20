__int64 ipa_init_flt4_v3()
{
  __int64 v0; // x3
  unsigned int v1; // w0
  __int64 v2; // x8
  unsigned __int16 *v3; // x12
  _QWORD *v4; // x9
  __int64 v5; // x10
  int v6; // w11
  int v7; // w12
  __int64 v8; // x13
  int v9; // w20
  int v10; // w11
  int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x20
  unsigned int v17; // w19
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v29; // [xsp+10h] [xbp-A0h]
  __int64 v30; // [xsp+18h] [xbp-98h]
  int v31; // [xsp+20h] [xbp-90h]
  int v32; // [xsp+24h] [xbp-8Ch]
  __int64 v33; // [xsp+28h] [xbp-88h] BYREF
  __int64 v34; // [xsp+30h] [xbp-80h]
  __int64 v35; // [xsp+38h] [xbp-78h]
  _QWORD v36[14]; // [xsp+40h] [xbp-70h] BYREF

  v36[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = *(_QWORD *)(ipa3_ctx + 17488);
  v35 = 0;
  memset(v36, 0, 104);
  v33 = 0;
  v34 = 0;
  v29 = 0;
  v30 = 0;
  v28 = 0;
  v1 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64, __int64 *, _QWORD))ipahal_flt_generate_empty_img)(
         *(unsigned int *)(ipa3_ctx + 17496),
         *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 8LL),
         *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 20LL),
         v0,
         &v33,
         0);
  if ( v1 )
  {
    v17 = v1;
    printk(&unk_3E2DDC, "_ipa_init_flt4_v3");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d fail generate empty v4 flt img\n", "_ipa_init_flt4_v3", 6063);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d fail generate empty v4 flt img\n", "_ipa_init_flt4_v3", 6063);
    }
  }
  else
  {
    v2 = ipa3_ctx;
    v3 = (unsigned __int16 *)(ipa3_ctx + 29522);
    v4 = (_QWORD *)(ipa3_ctx + 34152);
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      v28 = 0;
      v5 = v34;
      v6 = v35;
      LODWORD(v30) = 0;
      v9 = 0;
      v7 = *v3;
      v8 = **(_QWORD **)(ipa3_ctx + 34176);
    }
    else
    {
      v5 = v34;
      v6 = v35;
      v28 = v34;
      LODWORD(v30) = v35;
      v7 = *v3;
      v8 = **(_QWORD **)(ipa3_ctx + 34176);
      v9 = *(_DWORD *)(v8 + 4) + v7;
    }
    HIDWORD(v30) = v9;
    v31 = v6;
    v10 = *(_DWORD *)(v8 + 16);
    v29 = v5;
    v11 = v10 + v7;
    v32 = v10 + v7;
    if ( ipa3_ctx )
    {
      if ( *v4 )
      {
        ipc_log_string(
          *v4,
          "ipa %s:%d putting hashable filtering IPv4 rules to phys 0x%x\n",
          "_ipa_init_flt4_v3",
          6087,
          v9);
        v2 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v2 + 34160);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d putting hashable filtering IPv4 rules to phys 0x%x\n",
          "_ipa_init_flt4_v3",
          6087,
          v9);
        v2 = ipa3_ctx;
      }
      if ( v2 )
      {
        v13 = *(_QWORD *)(v2 + 34152);
        if ( v13 )
        {
          ipc_log_string(
            v13,
            "ipa %s:%d putting non-hashable filtering IPv4 rules to phys 0x%x\n",
            "_ipa_init_flt4_v3",
            6089,
            v11);
          v2 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v2 + 34160);
        if ( v14 )
          ipc_log_string(
            v14,
            "ipa %s:%d putting non-hashable filtering IPv4 rules to phys 0x%x\n",
            "_ipa_init_flt4_v3",
            6089,
            v11);
      }
    }
    v15 = ((__int64 (__fastcall *)(_QWORD, __int64 *, _QWORD))ipahal_construct_imm_cmd)(0, &v28, 0);
    if ( v15 )
    {
      v16 = v15;
      ipa3_init_imm_cmd_desc(v36, v15);
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v36) )
      {
        printk(&unk_3CB958, "_ipa_init_flt4_v3");
        v25 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v26 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v26 )
          {
            ipc_log_string(v26, "ipa %s:%d fail to send immediate command\n", "_ipa_init_flt4_v3", 6102);
            v25 = ipa3_ctx;
          }
          v27 = *(_QWORD *)(v25 + 34160);
          if ( v27 )
            ipc_log_string(v27, "ipa %s:%d fail to send immediate command\n", "_ipa_init_flt4_v3", 6102);
        }
        v17 = -14;
      }
      else
      {
        v17 = 0;
      }
      kfree(v16);
    }
    else
    {
      printk(&unk_3ABE50, "_ipa_init_flt4_v3");
      v22 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_37;
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d fail construct ip_v4_flt_init imm cmd\n", "_ipa_init_flt4_v3", 6093);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d fail construct ip_v4_flt_init imm cmd\n", "_ipa_init_flt4_v3", 6093);
        v17 = -1;
      }
      else
      {
LABEL_37:
        v17 = -1;
      }
    }
    ipahal_free_dma_mem(&v33);
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
