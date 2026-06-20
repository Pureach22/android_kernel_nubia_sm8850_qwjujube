__int64 __fastcall ipa_add_interrupt_handler(unsigned int a1, __int64 a2, char a3, __int64 a4)
{
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x0
  char *v15; // x8
  int reg_n; // w0
  __int64 v17; // x8
  int v18; // w21
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w20
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w8
  unsigned int i; // w19
  __int64 v27; // x0
  int v28; // w8
  unsigned int v29; // w21
  int ep_bit; // w20
  unsigned int ep_reg_idx; // w0
  unsigned int v32; // w20
  unsigned int v33; // w19
  int v34; // w8
  int ep_mapping; // w0
  __int64 v36; // x8
  int v37; // w24
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 result; // x0
  int v46; // w19
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  int v50; // w19
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  _QWORD v56[2]; // [xsp+0h] [xbp-10h]

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = ipa3_ctx;
  v56[0] = 0;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d interrupt_enum(%d)\n", "ipa_add_interrupt_handler", 446, a1);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d interrupt_enum(%d)\n", "ipa_add_interrupt_handler", 446, a1);
  }
  if ( a1 >= 0x1D )
  {
    printk(&unk_3FE110, "ipa_add_interrupt_handler");
    v53 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v54 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d invalid interrupt number %d\n", "ipa_add_interrupt_handler", 449, a1);
        v53 = ipa3_ctx;
      }
      v55 = *(_QWORD *)(v53 + 34160);
      if ( v55 )
        ipc_log_string(v55, "ipa %s:%d invalid interrupt number %d\n", "ipa_add_interrupt_handler", 449, a1);
    }
    result = 4294967274LL;
    goto LABEL_96;
  }
  v11 = ipa3_ctx;
  v12 = ipa3_irq_mapping[a1];
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d ipa_interrupt_to_cb irq_num(%d)\n", "ipa_add_interrupt_handler", 459, v12);
      v11 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v11 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d ipa_interrupt_to_cb irq_num(%d)\n", "ipa_add_interrupt_handler", 459, v12);
  }
  if ( ((32LL * (unsigned int)v12) | 0x18uLL) > 0x400
    || (v15 = (char *)&ipa_interrupt_to_cb + 32 * v12,
        v15[24] = a3 & 1,
        *(_QWORD *)v15 = a2,
        ((32 * v12) | 0x10uLL) > 0x400)
    || (*((_QWORD *)v15 + 2) = a4, ((32 * v12) | 8uLL) > 0x400) )
  {
    __break(1u);
LABEL_104:
    __break(0x5512u);
  }
  *((_DWORD *)v15 + 2) = a1;
  reg_n = ipahal_read_reg_n(2, (unsigned int)ipa_ee);
  v17 = ipa3_ctx;
  v18 = reg_n;
  if ( ipa3_ctx )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d read IPA_IRQ_EN_EE_n register. reg = %d\n", "ipa_add_interrupt_handler", 467, v18);
      v17 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v17 + 34160);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d read IPA_IRQ_EN_EE_n register. reg = %d\n", "ipa_add_interrupt_handler", 467, v18);
      v17 = ipa3_ctx;
    }
  }
  v21 = 1 << v12;
  if ( *(_BYTE *)(v17 + 43308) == 1 )
  {
    ipa3_uc_rg10_write_reg(2, (unsigned int)ipa_ee, v18 | (unsigned int)v21);
    v22 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_28;
  }
  else
  {
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
      2,
      0,
      (unsigned int)ipa_ee,
      v18 | (unsigned int)v21);
    v22 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_28;
  }
  v23 = *(_QWORD *)(v22 + 34152);
  if ( v23 )
  {
    ipc_log_string(
      v23,
      "ipa %s:%d wrote IPA_IRQ_EN_EE_n register. reg = %d\n",
      "ipa_add_interrupt_handler",
      474,
      v18 | v21);
    v22 = ipa3_ctx;
  }
  v24 = *(_QWORD *)(v22 + 34160);
  if ( v24 )
    ipc_log_string(
      v24,
      "ipa %s:%d wrote IPA_IRQ_EN_EE_n register. reg = %d\n",
      "ipa_add_interrupt_handler",
      474,
      v18 | v21);
LABEL_28:
  if ( a1 != 13 )
    goto LABEL_95;
  v25 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( v25 < 0xB )
    goto LABEL_95;
  if ( v25 <= 0x14 )
  {
    v32 = 0;
    v33 = -1;
    do
    {
      if ( v32 == 84
        || v32 == 114
        || v32 == 74
        || v32 == 122
        || (v34 = v32 & 0xFD, v34 == 56)
        || v34 == 52
        || v32 == 50
        || v32 == 85
        || v32 == 115
        || v34 == 77
        || v32 == 75
        || v32 == 61
        || v34 == 57
        || v32 == 53
        || (v32 & 0xFB) == 0x33 )
      {
        ep_mapping = ipa_get_ep_mapping(v32);
        v36 = ipa3_ctx;
        v37 = ep_mapping;
        if ( ipa3_ctx )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v38 )
          {
            ipc_log_string(
              v38,
              "ipa %s:%d modem ep_idx(%d) client_idx = %d\n",
              "ipa_add_interrupt_handler",
              509,
              v37,
              v32);
            v36 = ipa3_ctx;
          }
          v39 = *(_QWORD *)(v36 + 34160);
          if ( v39 )
            ipc_log_string(
              v39,
              "ipa %s:%d modem ep_idx(%d) client_idx = %d\n",
              "ipa_add_interrupt_handler",
              509,
              v37,
              v32);
        }
        if ( v37 == -1 )
        {
          v40 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v41 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v41 )
            {
              ipc_log_string(v41, "ipa %s:%d Invalid IPA client\n", "ipa_add_interrupt_handler", 511);
              v40 = ipa3_ctx;
            }
            v42 = *(_QWORD *)(v40 + 34160);
            if ( v42 )
              ipc_log_string(v42, "ipa %s:%d Invalid IPA client\n", "ipa_add_interrupt_handler", 511);
          }
        }
        else
        {
          v33 &= ~(1 << v37);
        }
      }
      ++v32;
    }
    while ( v32 != 134 );
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(5, 0, (unsigned int)ipa_ee, v33);
    v43 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_95;
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n reg = %d\n", "ipa_add_interrupt_handler", 518, v33);
      v43 = ipa3_ctx;
    }
    result = *(_QWORD *)(v43 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n reg = %d\n",
        "ipa_add_interrupt_handler",
        518,
        v33);
LABEL_95:
      result = 0;
    }
  }
  else
  {
    for ( i = 0; i != 134; ++i )
    {
      v27 = ipa_get_ep_mapping(i);
      if ( i != 84 && i != 114 && i != 74 && i != 122 )
      {
        v28 = i & 0xFD;
        if ( v28 != 56
          && v28 != 52
          && i != 50
          && i != 85
          && i != 115
          && v28 != 77
          && i != 75
          && i != 61
          && v28 != 57
          && v28 != 53
          && i != 51
          && (_DWORD)v27 != -1 )
        {
          v29 = v27;
          ep_bit = ipahal_get_ep_bit(v27);
          ep_reg_idx = ipahal_get_ep_reg_idx(v29);
          if ( ep_reg_idx > 1 )
            goto LABEL_104;
          *((_DWORD *)v56 + ep_reg_idx) |= ep_bit;
        }
      }
    }
    v46 = v56[0];
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
      137,
      0,
      (unsigned int)ipa_ee,
      LODWORD(v56[0]));
    v47 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v48 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v48 )
      {
        ipc_log_string(
          v48,
          "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n_REG_k m = %u pipe_bmsk[i] = %d\n",
          "ipa_add_interrupt_handler",
          497,
          0,
          v46);
        v47 = ipa3_ctx;
      }
      v49 = *(_QWORD *)(v47 + 34160);
      if ( v49 )
        ipc_log_string(
          v49,
          "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n_REG_k m = %u pipe_bmsk[i] = %d\n",
          "ipa_add_interrupt_handler",
          497,
          0,
          v46);
    }
    v50 = HIDWORD(v56[0]);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ipahal_write_reg_mn)(
      137,
      1,
      (unsigned int)ipa_ee,
      HIDWORD(v56[0]));
    v51 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_95;
    v52 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v52 )
    {
      ipc_log_string(
        v52,
        "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n_REG_k m = %u pipe_bmsk[i] = %d\n",
        "ipa_add_interrupt_handler",
        497,
        1,
        v50);
      v51 = ipa3_ctx;
    }
    result = *(_QWORD *)(v51 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d wrote IPA_SUSPEND_IRQ_EN_EE_n_REG_k m = %u pipe_bmsk[i] = %d\n",
        "ipa_add_interrupt_handler",
        497,
        1,
        v50);
      goto LABEL_95;
    }
  }
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return result;
}
