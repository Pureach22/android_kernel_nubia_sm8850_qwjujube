__int64 __fastcall hdcp2_app_process_msg_qseecom(__int64 a1, int a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x20
  __int64 v5; // x8
  size_t v6; // x2
  unsigned int v7; // w0
  unsigned int v8; // w2
  size_t v10; // x21

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v4 = *(_DWORD **)(v2 + 8);
  *v4 = 4099;
  v5 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 16) = a2;
  if ( !v5 )
  {
    printk(&unk_CB90);
    return (unsigned int)-22;
  }
  v4[2] = a2;
  v4[1] = *(_DWORD *)(a1 + 40);
  v6 = *(unsigned int *)(a1 + 16);
  if ( (unsigned int)v6 >= 0x217 && (hdcp2_app_process_msg_qseecom___already_done & 1) == 0 )
  {
    hdcp2_app_process_msg_qseecom___already_done = 1;
    v10 = v6;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v6,
      "field \"req_buf->msg\" at ../vendor/qcom/opensource/securemsm-kernel/hdcp/hdcp_qseecom.c:1151",
      0x216u);
    v6 = v10;
    __break(0x800u);
  }
  memcpy(v4 + 3, *(const void **)(a1 + 96), v6);
  v7 = qseecom_send_command(*(_QWORD *)(a1 + 56), v4, 576, v4 + 144, 192);
  v8 = v7;
  if ( (v7 & 0x80000000) != 0 || v4[144] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( !v7 )
  {
    if ( v4[148] == 1 )
      *(_BYTE *)(a1 + 4) = 1;
    memcpy(*(void **)(a1 + 104), v4 + 150, (unsigned int)v4[149]);
    v8 = 0;
    *(_DWORD *)(a1 + 32) = v4[149];
    *(_DWORD *)a1 = v4[147];
  }
  return v8;
}
