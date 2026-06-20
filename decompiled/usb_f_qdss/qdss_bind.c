__int64 __fastcall qdss_bind(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  unsigned int v5; // w0
  __int64 v6; // x1
  __int64 result; // x0
  const char *v8; // x21
  _QWORD *v9; // x0
  const char *v10; // x21
  _QWORD *v11; // x0
  _QWORD *v12; // x0
  const char *v13; // x20
  int v14; // w9
  _UNKNOWN **v15; // x1
  _UNKNOWN **v16; // x2
  _UNKNOWN **v17; // x3
  __int64 v18; // x1
  unsigned int v19; // w19
  _QWORD *v20; // x8
  _QWORD *v21; // x8
  _QWORD *v22; // x20
  const char *v23; // x21

  v4 = **(_QWORD **)(a1 + 48);
  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "qdss_bind", *(const char **)(a2 + 296));
  v5 = usb_interface_id(a1, a2);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_31;
  *(_BYTE *)(a2 + 275) = v5;
  byte_1AA = v5;
  if ( !qdss_string_defs )
  {
    result = usb_string_id(*(_QWORD *)(a1 + 48));
    if ( (result & 0x80000000) != 0 )
      return result;
    qdss_string_defs = result;
    byte_1B0 = result;
  }
  if ( *(_BYTE *)(a2 + 280) != 1 )
    goto LABEL_10;
  v5 = usb_interface_id(a1, a2);
  if ( (v5 & 0x80000000) != 0 )
  {
LABEL_31:
    v19 = v5;
    printk(&unk_83C5, v6);
    return v19;
  }
  *(_BYTE *)(a2 + 274) = v5;
  byte_1B3 = v5;
  if ( !byte_188 )
  {
    result = usb_string_id(*(_QWORD *)(a1 + 48));
    if ( (result & 0x80000000) != 0 )
      return result;
    byte_188 = result;
    byte_1B9 = result;
  }
LABEL_10:
  v8 = *(const char **)(a2 + 296);
  if ( !strcmp(v8, "qdss_mdm") || !strcmp(v8, "qdss_sw") )
    byte_1BC = 0;
  v9 = (_QWORD *)usb_ep_autoconfig(v4, &qdss_fs_data_desc);
  if ( !v9 )
    goto LABEL_32;
  *(_QWORD *)(a2 + 240) = v9;
  *v9 = a2;
  v10 = *(const char **)(a2 + 296);
  if ( strcmp(v10, "qdss_mdm") && strcmp(v10, "qdss_sw") )
  {
    if ( (msm_ep_set_mode(*(_QWORD *)(a2 + 240), *(unsigned int *)(a2 + 336)) & 0x80000000) != 0 )
      goto LABEL_33;
    msm_ep_update_ops(*(_QWORD *)(a2 + 240));
  }
  if ( *(_BYTE *)(a2 + 280) == 1 )
  {
    v11 = (_QWORD *)usb_ep_autoconfig(v4, &qdss_fs_ctrl_in_desc);
    if ( v11 )
    {
      *(_QWORD *)(a2 + 232) = v11;
      *v11 = a2;
      v12 = (_QWORD *)usb_ep_autoconfig(v4, &qdss_fs_ctrl_out_desc);
      if ( v12 )
      {
        *(_QWORD *)(a2 + 224) = v12;
        *v12 = a2;
        goto LABEL_22;
      }
    }
LABEL_32:
    printk(&unk_80D9, "qdss_bind");
    goto LABEL_33;
  }
LABEL_22:
  v13 = *(const char **)(a2 + 296);
  if ( !strcmp(v13, "qdss_mdm") || !strcmp(v13, "qdss_sw") || !(unsigned int)alloc_hw_req(*(_QWORD *)(a2 + 240)) )
  {
    v14 = *(unsigned __int8 *)(a2 + 280);
    byte_1DD = byte_1C2;
    byte_1E6 = byte_1C2;
    if ( v14 == 1 )
    {
      v15 = &qdss_fs_desc;
      v16 = &qdss_hs_desc;
      byte_1EF = byte_1CB;
      byte_1F8 = byte_1CB;
      v17 = &qdss_ss_desc;
      byte_201 = byte_1D4;
      byte_20A = byte_1D4;
    }
    else
    {
      v15 = &qdss_fs_data_only_desc;
      v16 = &qdss_hs_data_only_desc;
      v17 = &qdss_ss_data_only_desc;
    }
    result = usb_assign_descriptors(a2, v15, v16, v17, v17);
    if ( !(_DWORD)result )
      return result;
    v18 = *(_QWORD *)(a2 + 288);
    if ( v18 )
    {
      usb_ep_free_request(*(_QWORD *)(a2 + 240), v18);
      *(_QWORD *)(a2 + 288) = 0;
    }
  }
  else
  {
    printk(&unk_80FC, "qdss_bind");
  }
LABEL_33:
  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "clear_eps", *(const char **)(a2 + 296));
  v20 = *(_QWORD **)(a2 + 232);
  if ( v20 )
    *v20 = 0;
  v21 = *(_QWORD **)(a2 + 224);
  if ( v21 )
    *v21 = 0;
  v22 = *(_QWORD **)(a2 + 240);
  if ( v22 )
  {
    v23 = *(const char **)(a2 + 296);
    if ( strcmp(v23, "qdss_mdm") )
    {
      if ( strcmp(v23, "qdss_sw") )
      {
        msm_ep_clear_ops(v22);
        msm_ep_set_mode(*(_QWORD *)(a2 + 240), 0);
        v22 = *(_QWORD **)(a2 + 240);
      }
    }
    *v22 = 0;
  }
  return 4294967201LL;
}
