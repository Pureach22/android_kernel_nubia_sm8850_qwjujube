__int64 __fastcall hfi_enc_debugfs_misr_setup(_QWORD *a1)
{
  __int64 v2; // x21
  __int64 connector; // x0
  int v4; // w20
  _QWORD *cmd_buf; // x0
  int v6; // w8
  int v7; // w9
  __int64 v8; // x21
  unsigned int v9; // w0
  int v10; // w0
  int v11; // w4
  unsigned int v12; // w19
  __int64 result; // x0
  void *v14; // x0
  void *v15; // x0
  _DWORD v16[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1[170] )
    printk(&unk_25A5F5, "hfi_enc_debugfs_misr_setup");
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*a1 + 56LL) + 8LL) + 6440LL);
  if ( !v2 )
  {
    v14 = &unk_279C72;
LABEL_16:
    printk(v14, "hfi_enc_debugfs_misr_setup");
    result = 4294967274LL;
    goto LABEL_20;
  }
  connector = sde_encoder_get_connector(*a1, a1);
  if ( !connector )
  {
    v14 = &unk_219407;
    goto LABEL_16;
  }
  v4 = *(_DWORD *)(connector + 2740);
  if ( v4 == -1 )
  {
    v14 = &unk_231479;
    goto LABEL_16;
  }
  cmd_buf = hfi_adapter_get_cmd_buf(v2 + 8);
  if ( !cmd_buf )
  {
    v14 = &unk_2426FC;
    goto LABEL_16;
  }
  v6 = *((_DWORD *)a1 + 200);
  v7 = *((_DWORD *)a1 + 203);
  v16[0] = v4;
  v16[1] = v6;
  v8 = (__int64)cmd_buf;
  v16[2] = v7;
  v16[3] = 2;
  v9 = hfi_adapter_add_set_property((__int64)cmd_buf, -16777209, v4, 2u, (__int64)v16, 0x10u, 0);
  if ( v9 )
  {
    v12 = v9;
    v15 = &unk_2314A6;
LABEL_19:
    printk(v15, "hfi_enc_debugfs_misr_setup");
    result = v12;
    goto LABEL_20;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s misr_setup: sending cmd buf\n", "hfi_enc_debugfs_misr_setup");
  v10 = hfi_adapter_set_cmd_buf(v8);
  v11 = *((_DWORD *)a1 + 6);
  v12 = v10;
  sde_evtlog_log(sde_dbg_base_evtlog, "hfi_enc_debugfs_misr_setup", 681, -1, v11, v4, -16777209, v10, 51);
  if ( v12 )
  {
    v15 = &unk_25E1BA;
    goto LABEL_19;
  }
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
