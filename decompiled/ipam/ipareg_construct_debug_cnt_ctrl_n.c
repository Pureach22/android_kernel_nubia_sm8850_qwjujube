void __fastcall ipareg_construct_debug_cnt_ctrl_n(unsigned int a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w20
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w9
  int v9; // w8
  int v10; // w8
  unsigned __int8 *v11; // x22
  __int64 v13; // x0
  int v14; // w20
  __int64 v15; // x21
  const char *v16; // x0
  __int64 v17; // x0
  int v18; // w20
  __int64 v19; // x21
  const char *v20; // x0
  int *v21; // x19
  unsigned __int8 *v22; // x20
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  *a3 |= *a2;
  v3 = *((_DWORD *)a2 + 1);
  if ( v3 > 1 )
  {
    if ( v3 == 2 )
    {
      v4 = 32;
      goto LABEL_14;
    }
    if ( v3 != 3 )
    {
      if ( v3 == 4 )
      {
        v4 = 80;
LABEL_14:
        v5 = *a3 | v4;
        *a3 = v5;
        v6 = v5 | (a2[8] << 8);
        *a3 = v6;
        v7 = ((a2[9] & 0x1F) << 12) | v6;
        *a3 = v7;
        v8 = *((unsigned __int16 *)a2 + 6) << 20;
        if ( *(_DWORD *)ipahal_ctx > 0xBu )
        {
          v10 = v8 & 0x1FF00000 | v7;
        }
        else
        {
          v9 = v8 & 0xFF00000 | v7;
          *a3 = v9;
          v10 = v9 | (a2[10] << 28);
        }
        *a3 = v10;
        return;
      }
      goto LABEL_19;
    }
    if ( (a2[10] & 1) != 0 )
    {
      v4 = 64;
      goto LABEL_14;
    }
    v21 = a3;
    v22 = a2;
    printk(&unk_3C2D15, "ipareg_construct_debug_cnt_ctrl_n");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d No FLT global rules\n", "ipareg_construct_debug_cnt_ctrl_n", 1834);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d No FLT global rules\n", "ipareg_construct_debug_cnt_ctrl_n", 1834);
    }
    __break(0x800u);
    v4 = 64;
LABEL_34:
    a2 = v22;
    a3 = v21;
    goto LABEL_14;
  }
  if ( !v3 )
  {
    if ( (a2[10] & 1) != 0 )
    {
      v4 = 0;
      goto LABEL_14;
    }
    v21 = a3;
    v22 = a2;
    printk(&unk_3C2D15, "ipareg_construct_debug_cnt_ctrl_n");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(v23, "ipahal %s:%d No FLT global rules\n", "ipareg_construct_debug_cnt_ctrl_n", 1821);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v24, "ipahal %s:%d No FLT global rules\n", "ipareg_construct_debug_cnt_ctrl_n", 1821);
    }
    v4 = 0;
    __break(0x800u);
    goto LABEL_34;
  }
  if ( v3 == 1 )
  {
    v4 = 16;
    goto LABEL_14;
  }
LABEL_19:
  v11 = a2;
  ipahal_reg_name_str(a1);
  printk(&unk_3F120B, "ipareg_construct_debug_cnt_ctrl_n");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    v14 = *((_DWORD *)v11 + 1);
    v15 = v13;
    v16 = ipahal_reg_name_str(a1);
    ipc_log_string(
      v15,
      "ipahal %s:%d Invalid dbg_cnt_ctrl type (%d) for %s\n",
      "ipareg_construct_debug_cnt_ctrl_n",
      1843,
      v14,
      v16);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v17 = ipa3_get_ipc_logbuf_low();
    v18 = *((_DWORD *)v11 + 1);
    v19 = v17;
    v20 = ipahal_reg_name_str(a1);
    ipc_log_string(
      v19,
      "ipahal %s:%d Invalid dbg_cnt_ctrl type (%d) for %s\n",
      "ipareg_construct_debug_cnt_ctrl_n",
      1843,
      v18,
      v20);
  }
  __break(0x800u);
}
