__int64 __fastcall ipa3_force_cfg_ep_holb(unsigned int a1, _DWORD *a2)
{
  unsigned int v4; // w9
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a2 || *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3F1C1D, "ipa3_force_cfg_ep_holb");
    v8 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_50;
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d bad parm.\n", "ipa3_force_cfg_ep_holb", 9898);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d bad parm.\n", "ipa3_force_cfg_ep_holb", 9898);
      result = 4294967274LL;
    }
    else
    {
LABEL_50:
      result = 4294967274LL;
    }
    goto LABEL_21;
  }
  if ( (a1 & 0x80000000) != 0 )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
  }
  else if ( a1 >= 0x24 )
  {
    __break(0x5512u);
    JUMPOUT(0x30FF4B0);
  }
  ipa3_inc_client_enable_clks();
  if ( !*((_WORD *)a2 + 6) )
    goto LABEL_10;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
  {
    *((_WORD *)a2 + 6) = 0;
    ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
    {
      if ( (unsigned int)ipa3_process_timer_cfg(1000 * *a2, (_BYTE *)a2 + 14, (unsigned __int8 *)a2 + 15) )
      {
        v23 = printk(&unk_3EFDA2, "ipa3_force_cfg_ep_holb");
        v24 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v25 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v25 )
          {
            ipc_log_string(v25, "ipa %s:%d failed to process HOLB timer tmr=%u\n", "ipa3_force_cfg_ep_holb", 9925, *a2);
            v24 = ipa3_ctx;
          }
          v23 = *(_QWORD *)(v24 + 34160);
          if ( v23 )
            v23 = ipc_log_string(
                    v23,
                    "ipa %s:%d failed to process HOLB timer tmr=%u\n",
                    "ipa3_force_cfg_ep_holb",
                    9925,
                    *a2);
        }
        ((void (__fastcall *)(__int64))ipa_assert)(v23);
        result = 0xFFFFFFFFLL;
        goto LABEL_21;
      }
    }
  }
  ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(53, a1, a2);
  *((_WORD *)a2 + 6) = 1;
  ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
LABEL_10:
    ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
  if ( (a1 & 0x80000000) != 0 || (v4 = *(_DWORD *)(ipa3_ctx + 34308), v4 <= a1) )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    v4 = *(_DWORD *)(ipa3_ctx + 34308);
    if ( (a1 & 0x80000000) != 0 )
      goto LABEL_44;
  }
  else if ( (a1 & 0x80000000) != 0 )
  {
LABEL_44:
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    goto LABEL_15;
  }
  if ( v4 <= a1 )
    goto LABEL_44;
LABEL_15:
  ipa3_dec_client_disable_clks();
  v5 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_20:
    result = 0;
    goto LABEL_21;
  }
  v6 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v6 )
  {
    ipc_log_string(
      v6,
      "ipa %s:%d cfg holb %u ep=%d tmr=%d\n",
      "ipa3_force_cfg_ep_holb",
      9946,
      *((unsigned __int16 *)a2 + 6),
      a1,
      *a2);
    v5 = ipa3_ctx;
  }
  result = *(_QWORD *)(v5 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d cfg holb %u ep=%d tmr=%d\n",
      "ipa3_force_cfg_ep_holb",
      9946,
      *((unsigned __int16 *)a2 + 6),
      a1,
      *a2);
    goto LABEL_20;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
