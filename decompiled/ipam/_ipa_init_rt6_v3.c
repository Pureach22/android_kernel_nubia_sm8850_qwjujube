__int64 ipa_init_rt6_v3()
{
  __int64 v0; // x8
  __int64 *v1; // x9
  __int64 v2; // x10
  unsigned int v3; // w9
  int v4; // w12
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w0
  __int64 v8; // x8
  unsigned __int16 *v9; // x12
  _QWORD *v10; // x9
  __int64 v11; // x11
  int v12; // w10
  int v13; // w12
  __int64 v14; // x13
  int v15; // w20
  int v16; // w11
  int v17; // w19
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x20
  unsigned int v23; // w19
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v35; // [xsp+10h] [xbp-A0h]
  __int64 v36; // [xsp+18h] [xbp-98h]
  __int64 v37; // [xsp+20h] [xbp-90h]
  __int64 v38; // [xsp+28h] [xbp-88h] BYREF
  __int64 v39; // [xsp+30h] [xbp-80h]
  __int64 v40; // [xsp+38h] [xbp-78h]
  _QWORD v41[14]; // [xsp+40h] [xbp-70h] BYREF

  v41[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v1 = *(__int64 **)(ipa3_ctx + 34176);
  v40 = 0;
  memset(v41, 0, 104);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v2 = *v1;
  v3 = *(_DWORD *)(*v1 + 100);
  if ( v3 <= *(_DWORD *)(v2 + 104) )
  {
    do
    {
      v4 = 1 << v3++;
      *(_QWORD *)(v0 + 29464) |= v4;
      v0 = ipa3_ctx;
    }
    while ( v3 <= *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 104LL) );
  }
  if ( v0 )
  {
    v5 = *(_QWORD *)(v0 + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d v6 rt bitmap 0x%lx\n", "_ipa_init_rt6_v3", 5989, *(_QWORD *)(v0 + 29464));
      v0 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v0 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d v6 rt bitmap 0x%lx\n", "_ipa_init_rt6_v3", 5989, *(_QWORD *)(v0 + 29464));
      v0 = ipa3_ctx;
    }
  }
  v7 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *, _QWORD))ipahal_rt_generate_empty_img)(
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 96LL),
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 120LL),
         *(unsigned int *)(**(_QWORD **)(v0 + 34176) + 132LL),
         &v38,
         0);
  if ( v7 )
  {
    v23 = v7;
    printk(&unk_3DA8F2, "_ipa_init_rt6_v3");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d fail generate empty v6 rt img\n", "_ipa_init_rt6_v3", 5995);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d fail generate empty v6 rt img\n", "_ipa_init_rt6_v3", 5995);
    }
  }
  else
  {
    v8 = ipa3_ctx;
    v9 = (unsigned __int16 *)(ipa3_ctx + 29522);
    v10 = (_QWORD *)(ipa3_ctx + 34152);
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      v34 = 0;
      v11 = v39;
      v12 = v40;
      LODWORD(v36) = 0;
      v15 = 0;
      v13 = *v9;
      v14 = **(_QWORD **)(ipa3_ctx + 34176);
    }
    else
    {
      v11 = v39;
      v12 = v40;
      v34 = v39;
      LODWORD(v36) = v40;
      v13 = *v9;
      v14 = **(_QWORD **)(ipa3_ctx + 34176);
      v15 = *(_DWORD *)(v14 + 116) + v13;
    }
    v35 = v11;
    v16 = *(_DWORD *)(v14 + 128);
    HIDWORD(v36) = v15;
    LODWORD(v37) = v12;
    v17 = v16 + v13;
    HIDWORD(v37) = v16 + v13;
    if ( ipa3_ctx )
    {
      if ( *v10 )
      {
        ipc_log_string(
          *v10,
          "ipa %s:%d putting hashable routing IPv6 rules to phys 0x%x\n",
          "_ipa_init_rt6_v3",
          6019,
          v15);
        v8 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v8 + 34160);
      if ( v18 )
      {
        ipc_log_string(
          v18,
          "ipa %s:%d putting hashable routing IPv6 rules to phys 0x%x\n",
          "_ipa_init_rt6_v3",
          6019,
          v15);
        v8 = ipa3_ctx;
      }
      if ( v8 )
      {
        v19 = *(_QWORD *)(v8 + 34152);
        if ( v19 )
        {
          ipc_log_string(
            v19,
            "ipa %s:%d putting non-hashable routing IPv6 rules to phys 0x%x\n",
            "_ipa_init_rt6_v3",
            6021,
            v17);
          v8 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v8 + 34160);
        if ( v20 )
          ipc_log_string(
            v20,
            "ipa %s:%d putting non-hashable routing IPv6 rules to phys 0x%x\n",
            "_ipa_init_rt6_v3",
            6021,
            v17);
      }
    }
    v21 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(4, &v34, 0);
    if ( v21 )
    {
      v22 = v21;
      ipa3_init_imm_cmd_desc(v41, v21);
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v41) )
      {
        printk(&unk_3CB958, "_ipa_init_rt6_v3");
        v31 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v32 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v32 )
          {
            ipc_log_string(v32, "ipa %s:%d fail to send immediate command\n", "_ipa_init_rt6_v3", 6034);
            v31 = ipa3_ctx;
          }
          v33 = *(_QWORD *)(v31 + 34160);
          if ( v33 )
            ipc_log_string(v33, "ipa %s:%d fail to send immediate command\n", "_ipa_init_rt6_v3", 6034);
        }
        v23 = -14;
      }
      else
      {
        v23 = 0;
      }
      kfree(v22);
    }
    else
    {
      printk(&unk_3DDA1B, "_ipa_init_rt6_v3");
      v28 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_44;
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d fail construct ip_v6_rt_init imm cmd\n", "_ipa_init_rt6_v3", 6025);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d fail construct ip_v6_rt_init imm cmd\n", "_ipa_init_rt6_v3", 6025);
        v23 = -1;
      }
      else
      {
LABEL_44:
        v23 = -1;
      }
    }
    ipahal_free_dma_mem(&v38);
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
