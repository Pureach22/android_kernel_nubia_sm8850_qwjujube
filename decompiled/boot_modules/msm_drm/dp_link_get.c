__int64 __fastcall dp_link_get(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x0
  char v7; // w8
  __int64 ipc_log_context; // x0

  if ( !a1 || !a2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_link_get");
    return -22;
  }
  v6 = devm_kmalloc(a1, 256, 3520);
  if ( !v6 )
    return -22;
  *(_QWORD *)(v6 + 8) = a1;
  *(_QWORD *)(v6 + 16) = a2;
  *(_BYTE *)(v6 + 151) = 3;
  if ( a3 <= 0x10020002 )
    v7 = 2;
  else
    v7 = 3;
  *(_BYTE *)(v6 + 150) = v7;
  *(_QWORD *)(v6 + 168) = dp_link_get_test_bits_depth;
  *(_QWORD *)(v6 + 176) = dp_link_process_request;
  *(_QWORD *)(v6 + 184) = dp_link_get_colorimetry_config;
  *(_QWORD *)(v6 + 192) = dp_link_adjust_levels;
  *(_QWORD *)(v6 + 200) = dp_link_send_psm_request;
  *(_QWORD *)(v6 + 208) = dp_link_send_test_response;
  *(_QWORD *)(v6 + 216) = dp_link_psm_config;
  *(_QWORD *)(v6 + 224) = dp_link_send_edid_checksum;
  return v6 + 24;
}
