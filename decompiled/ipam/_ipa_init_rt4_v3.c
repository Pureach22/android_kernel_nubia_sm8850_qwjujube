__int64 ipa_init_rt4_v3()
{
  __int64 v0; // x8
  __int64 v1; // x9
  __int64 v2; // x10
  unsigned int v3; // w11
  __int64 v4; // x12
  int v5; // w14
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x8
  unsigned __int16 *v10; // x12
  _QWORD *v11; // x9
  __int64 v12; // x11
  int v13; // w10
  int v14; // w12
  __int64 v15; // x13
  int v16; // w20
  int v17; // w11
  int v18; // w19
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x20
  unsigned int v24; // w19
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v36; // [xsp+10h] [xbp-A0h]
  __int64 v37; // [xsp+18h] [xbp-98h]
  int v38; // [xsp+20h] [xbp-90h]
  int v39; // [xsp+24h] [xbp-8Ch]
  __int64 v40; // [xsp+28h] [xbp-88h] BYREF
  __int64 v41; // [xsp+30h] [xbp-80h]
  __int64 v42; // [xsp+38h] [xbp-78h]
  _QWORD v43[14]; // [xsp+40h] [xbp-70h] BYREF

  v43[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v1 = ipa3_ctx + 0x8000;
  v42 = 0;
  memset(v43, 0, 104);
  v40 = 0;
  v41 = 0;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  v2 = *(_QWORD *)(ipa3_ctx + 34176);
  v3 = *(_DWORD *)(*(_QWORD *)v2 + 56LL);
  if ( v3 <= *(_DWORD *)(*(_QWORD *)v2 + 60LL) )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 29456);
    do
    {
      v5 = 1 << v3++;
      v4 |= v5;
      *(_QWORD *)(v0 + 29456) = v4;
    }
    while ( v3 <= *(_DWORD *)(*(_QWORD *)v2 + 60LL) );
  }
  if ( v0 )
  {
    v6 = *(_QWORD *)(v1 + 1384);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d v4 rt bitmap 0x%lx\n", "_ipa_init_rt4_v3", 5915, *(_QWORD *)(v0 + 29456));
      v0 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v0 + 34160);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d v4 rt bitmap 0x%lx\n", "_ipa_init_rt4_v3", 5915, *(_QWORD *)(v0 + 29456));
      v0 = ipa3_ctx;
    }
  }
  v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *, _QWORD))ipahal_rt_generate_empty_img)(
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 52LL),
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 76LL),
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 88LL),
         &v40,
         0);
  if ( v8 )
  {
    v24 = v8;
    printk(&unk_3EE2C4, "_ipa_init_rt4_v3");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d fail generate empty v4 rt img\n", "_ipa_init_rt4_v3", 5921);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d fail generate empty v4 rt img\n", "_ipa_init_rt4_v3", 5921);
    }
  }
  else
  {
    v9 = ipa3_ctx;
    v10 = (unsigned __int16 *)(ipa3_ctx + 29522);
    v11 = (_QWORD *)(ipa3_ctx + 34152);
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      v35 = 0;
      v12 = v41;
      v13 = v42;
      LODWORD(v37) = 0;
      v16 = 0;
      v14 = *v10;
      v15 = **(_QWORD **)(ipa3_ctx + 34176);
    }
    else
    {
      v12 = v41;
      v13 = v42;
      v35 = v41;
      LODWORD(v37) = v42;
      v14 = *v10;
      v15 = **(_QWORD **)(ipa3_ctx + 34176);
      v16 = *(_DWORD *)(v15 + 72) + v14;
    }
    v36 = v12;
    v17 = *(_DWORD *)(v15 + 84);
    HIDWORD(v37) = v16;
    v38 = v13;
    v18 = v17 + v14;
    v39 = v17 + v14;
    if ( ipa3_ctx )
    {
      if ( *v11 )
      {
        ipc_log_string(
          *v11,
          "ipa %s:%d putting hashable routing IPv4 rules to phys 0x%x\n",
          "_ipa_init_rt4_v3",
          5945,
          v16);
        v9 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v9 + 34160);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d putting hashable routing IPv4 rules to phys 0x%x\n",
          "_ipa_init_rt4_v3",
          5945,
          v16);
        v9 = ipa3_ctx;
      }
      if ( v9 )
      {
        v20 = *(_QWORD *)(v9 + 34152);
        if ( v20 )
        {
          ipc_log_string(
            v20,
            "ipa %s:%d putting non-hashable routing IPv4 rules to phys 0x%x\n",
            "_ipa_init_rt4_v3",
            5947,
            v18);
          v9 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v9 + 34160);
        if ( v21 )
          ipc_log_string(
            v21,
            "ipa %s:%d putting non-hashable routing IPv4 rules to phys 0x%x\n",
            "_ipa_init_rt4_v3",
            5947,
            v18);
      }
    }
    v22 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(3, &v35, 0);
    if ( v22 )
    {
      v23 = v22;
      ipa3_init_imm_cmd_desc(v43, v22);
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v43) )
      {
        printk(&unk_3CB958, "_ipa_init_rt4_v3");
        v32 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v33 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v33 )
          {
            ipc_log_string(v33, "ipa %s:%d fail to send immediate command\n", "_ipa_init_rt4_v3", 5960);
            v32 = ipa3_ctx;
          }
          v34 = *(_QWORD *)(v32 + 34160);
          if ( v34 )
            ipc_log_string(v34, "ipa %s:%d fail to send immediate command\n", "_ipa_init_rt4_v3", 5960);
        }
        v24 = -14;
      }
      else
      {
        v24 = 0;
      }
      kfree(v23);
    }
    else
    {
      printk(&unk_3B4390, "_ipa_init_rt4_v3");
      v29 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_45;
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d fail construct ip_v4_rt_init imm cmd\n", "_ipa_init_rt4_v3", 5951);
        v29 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v29 + 34160);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d fail construct ip_v4_rt_init imm cmd\n", "_ipa_init_rt4_v3", 5951);
        v24 = -1;
      }
      else
      {
LABEL_45:
        v24 = -1;
      }
    }
    ipahal_free_dma_mem(&v40);
  }
  _ReadStatusReg(SP_EL0);
  return v24;
}
