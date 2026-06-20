__int64 __fastcall ipa3_nat_mdfy_pdn(unsigned __int8 *a1)
{
  __int64 v2; // x22
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  signed int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  int v22; // w10
  unsigned int v23; // w8
  unsigned int v24; // w11
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int modify_pdn_cmd; // w0
  __int64 v33; // x0
  __int64 v34; // x20
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // [xsp+0h] [xbp-A0h] BYREF
  _QWORD v54[13]; // [xsp+8h] [xbp-98h] BYREF
  unsigned __int64 v55; // [xsp+70h] [xbp-30h] BYREF
  int v56; // [xsp+78h] [xbp-28h]
  _QWORD v57[4]; // [xsp+80h] [xbp-20h] BYREF

  v57[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  memset(v57, 0, 24);
  v56 = 0;
  v55 = 0;
  v53 = 0;
  memset(v54, 0, sizeof(v54));
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    v4 = ipa3_ctx;
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d In\n", "ipa3_nat_mdfy_pdn", 1717);
      v4 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v4 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d In\n", "ipa3_nat_mdfy_pdn", 1717);
  }
  v6 = mutex_lock(v2 + 29544);
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_mdfy_pdn__rs, "ipa3_nat_mdfy_pdn") )
    {
      printk(&unk_3EC6AF, "ipa3_nat_mdfy_pdn");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_9;
    }
    else
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_9:
        v8 = *(_QWORD *)(v7 + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d IPA HW does not support multi PDN\n", "ipa3_nat_mdfy_pdn", 1722);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d IPA HW does not support multi PDN\n", "ipa3_nat_mdfy_pdn", 1722);
      }
    }
LABEL_27:
    v17 = -1;
    goto LABEL_28;
  }
  if ( !*(_QWORD *)(v2 + 29840) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_mdfy_pdn__rs_75, "ipa3_nat_mdfy_pdn") )
    {
      printk(&unk_3CFE70, "ipa3_nat_mdfy_pdn");
      v14 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_27;
    }
    else
    {
      v14 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_27;
    }
    v15 = *(_QWORD *)(v14 + 34152);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d Attempt to modify a PDN entry before the PDN table memory allocation\n",
        "ipa3_nat_mdfy_pdn",
        1729);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(
        v16,
        "ipa %s:%d Attempt to modify a PDN entry before the PDN table memory allocation\n",
        "ipa3_nat_mdfy_pdn",
        1729);
    goto LABEL_27;
  }
  v10 = *a1;
  if ( (int)(ipa3_get_max_pdn(v6) - 1) < v10 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_mdfy_pdn__rs_78, "ipa3_nat_mdfy_pdn") )
    {
      printk(&unk_3E1226, "ipa3_nat_mdfy_pdn");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_27;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_27;
    }
    v12 = *(_QWORD *)(v11 + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d pdn index out of range %d\n", "ipa3_nat_mdfy_pdn", 1735, *a1);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d pdn index out of range %d\n", "ipa3_nat_mdfy_pdn", 1735, *a1);
    goto LABEL_27;
  }
  v22 = *(_DWORD *)(ipa3_ctx + 32240);
  v24 = *((_DWORD *)a1 + 1);
  v23 = *((_DWORD *)a1 + 2);
  v56 = *((_DWORD *)a1 + 3);
  v55 = __PAIR64__(v23, v24);
  if ( v22 == 15 )
    HIDWORD(v55) = v23 | 0x40000000;
  v25 = ipahal_nat_entry_size(2, &v53);
  if ( v25 )
  {
    v17 = v25;
    printk(&unk_3A9ECC, "ipa3_nat_mdfy_pdn");
    v38 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v39 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v39 )
      {
        ipc_log_string(v39, "ipa %s:%d Failed to retrieve pdn entry size\n", "ipa3_nat_mdfy_pdn", 1762);
        v38 = ipa3_ctx;
      }
      v40 = *(_QWORD *)(v38 + 34160);
      if ( v40 )
        ipc_log_string(v40, "ipa %s:%d Failed to retrieve pdn entry size\n", "ipa3_nat_mdfy_pdn", 1762);
    }
  }
  else
  {
    v26 = ipahal_nat_construct_entry(2, &v55);
    if ( v26 )
    {
      v17 = v26;
      printk(&unk_3CFE43, "ipa3_nat_mdfy_pdn");
      v41 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v42 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v42 )
        {
          ipc_log_string(v42, "ipa %s:%d Fail to construct NAT pdn entry\n", "ipa3_nat_mdfy_pdn", 1772);
          v41 = ipa3_ctx;
        }
        v43 = *(_QWORD *)(v41 + 34160);
        if ( v43 )
          ipc_log_string(v43, "ipa %s:%d Fail to construct NAT pdn entry\n", "ipa3_nat_mdfy_pdn", 1772);
      }
    }
    else
    {
      v27 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(
            v28,
            "ipa %s:%d Modify PDN in index: %d Public ip address:%pI4h\n",
            "ipa3_nat_mdfy_pdn",
            1778,
            *a1,
            &v55);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
        {
          ipc_log_string(
            v29,
            "ipa %s:%d Modify PDN in index: %d Public ip address:%pI4h\n",
            "ipa3_nat_mdfy_pdn",
            1778,
            *a1,
            &v55);
          v27 = ipa3_ctx;
        }
        if ( v27 )
        {
          v30 = *(_QWORD *)(v27 + 34152);
          if ( v30 )
          {
            ipc_log_string(
              v30,
              "ipa %s:%d Modify PDN dst metadata: 0x%x src metadata: 0x%x\n",
              "ipa3_nat_mdfy_pdn",
              1782,
              v56,
              HIDWORD(v55));
            v27 = ipa3_ctx;
          }
          v31 = *(_QWORD *)(v27 + 34160);
          if ( v31 )
            ipc_log_string(
              v31,
              "ipa %s:%d Modify PDN dst metadata: 0x%x src metadata: 0x%x\n",
              "ipa3_nat_mdfy_pdn",
              1782,
              v56,
              HIDWORD(v55));
        }
      }
      modify_pdn_cmd = ipa3_nat_create_modify_pdn_cmd(v57, 0);
      if ( modify_pdn_cmd )
      {
        v17 = modify_pdn_cmd;
        printk(&unk_3E689A, "ipa3_nat_mdfy_pdn");
        v44 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v45 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v45 )
          {
            ipc_log_string(v45, "ipa %s:%d  Fail to create modify pdn command\n", "ipa3_nat_mdfy_pdn", 1790);
            v44 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v44 + 34160);
          if ( v46 )
            ipc_log_string(v46, "ipa %s:%d  Fail to create modify pdn command\n", "ipa3_nat_mdfy_pdn", 1790);
        }
      }
      else
      {
        v33 = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD))ipahal_construct_imm_cmd)(11, v57, 0);
        if ( v33 )
        {
          v34 = v33;
          ipa3_init_imm_cmd_desc(v54, v33);
          v35 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v36 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v36 )
            {
              ipc_log_string(v36, "ipa %s:%d sending PDN table copy cmd\n", "ipa3_nat_mdfy_pdn", 1806);
              v35 = ipa3_ctx;
            }
            v37 = *(_QWORD *)(v35 + 34160);
            if ( v37 )
              ipc_log_string(v37, "ipa %s:%d sending PDN table copy cmd\n", "ipa3_nat_mdfy_pdn", 1806);
          }
          v17 = ((__int64 (__fastcall *)(__int64, _QWORD *))ipa3_send_cmd)(1, v54);
          if ( v17 )
          {
            printk(&unk_3B2734, "ipa3_nat_mdfy_pdn");
            v50 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v51 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v51 )
              {
                ipc_log_string(
                  v51,
                  "ipa %s:%d Fail to send PDN table copy immediate command\n",
                  "ipa3_nat_mdfy_pdn",
                  1811);
                v50 = ipa3_ctx;
              }
              v52 = *(_QWORD *)(v50 + 34160);
              if ( v52 )
                ipc_log_string(
                  v52,
                  "ipa %s:%d Fail to send PDN table copy immediate command\n",
                  "ipa3_nat_mdfy_pdn",
                  1811);
            }
          }
          kfree(v34);
        }
        else
        {
          printk(&unk_3AFDBE, "ipa3_nat_mdfy_pdn");
          v47 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_88;
          v48 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v48 )
          {
            ipc_log_string(
              v48,
              "ipa %s:%d fail construct dma_shared_mem cmd: for pdn table\n",
              "ipa3_nat_mdfy_pdn",
              1799);
            v47 = ipa3_ctx;
          }
          v49 = *(_QWORD *)(v47 + 34160);
          if ( v49 )
          {
            ipc_log_string(
              v49,
              "ipa %s:%d fail construct dma_shared_mem cmd: for pdn table\n",
              "ipa3_nat_mdfy_pdn",
              1799);
            v17 = -12;
          }
          else
          {
LABEL_88:
            v17 = -12;
          }
        }
      }
    }
  }
LABEL_28:
  mutex_unlock(v2 + 29544);
  v18 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d Out\n", "ipa3_nat_mdfy_pdn", 1818);
      v18 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v18 + 34160);
    if ( v20 )
      ipc_log_string(v20, "ipa %s:%d Out\n", "ipa3_nat_mdfy_pdn", 1818);
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
