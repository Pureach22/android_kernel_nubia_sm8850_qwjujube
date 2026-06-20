__int64 __fastcall hfi_enc_debugfs_misr_read(int *a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 connector; // x0
  int v7; // w21
  _QWORD *cmd_buf; // x0
  __int64 v9; // x22
  int v10; // w0
  int v11; // w4
  unsigned int v12; // w19
  __int64 result; // x0
  void *v14; // x0
  void *v15; // x0
  _DWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v15 = &unk_22DDE9;
    goto LABEL_22;
  }
  if ( *((_QWORD *)a1 + 170) )
  {
    v2 = *((_QWORD *)a1 + 622);
    if ( !v2 )
    {
LABEL_23:
      result = 4294967274LL;
      goto LABEL_24;
    }
  }
  else
  {
    printk(&unk_25A5F5, "hfi_enc_debugfs_misr_read");
    v2 = *((_QWORD *)a1 + 622);
    if ( !v2 )
      goto LABEL_23;
  }
  if ( *(_QWORD *)a1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 8);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v4 + 6440);
        if ( v5 )
          goto LABEL_8;
        v15 = &unk_279C72;
LABEL_22:
        printk(v15, "hfi_enc_debugfs_misr_read");
        goto LABEL_23;
      }
    }
    v14 = &unk_234896;
  }
  else
  {
    v14 = &unk_26FCAB;
  }
  printk(v14, "sde_encoder_get_kms");
  v5 = 0x2AE7FC00171F28LL;
LABEL_8:
  connector = sde_encoder_get_connector(*(_QWORD *)a1, a1);
  if ( !connector )
  {
    v15 = &unk_219407;
    goto LABEL_22;
  }
  v7 = *(_DWORD *)(connector + 2740);
  if ( v7 == -1 )
  {
    v15 = &unk_231479;
    goto LABEL_22;
  }
  cmd_buf = hfi_adapter_get_cmd_buf(v5 + 8);
  if ( !cmd_buf )
  {
    v15 = &unk_2426FC;
    goto LABEL_22;
  }
  *(_QWORD *)(v2 + 120) = &hfi_enc_misr_read_hfi_prop_handler;
  v16[0] = v7;
  v16[1] = 2;
  v9 = (__int64)cmd_buf;
  hfi_adapter_add_get_property((__int64)cmd_buf, -16777208, v7, 2u, (__int64)v16, 8u, v2 + 120, 6);
  sde_evtlog_log(sde_dbg_base_evtlog, "hfi_enc_debugfs_misr_read", 797, -1, a1[6], v7, -16777208, 13107, 239);
  v10 = hfi_adapter_set_cmd_buf_blocking(v9);
  v11 = a1[6];
  v12 = v10;
  sde_evtlog_log(sde_dbg_base_evtlog, "hfi_enc_debugfs_misr_read", 800, -1, v11, v7, -16777208, v10, 68);
  result = v12;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
