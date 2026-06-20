long double __fastcall ipareg_construct_endp_init_hdr_ext_n_v4_5(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w9
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  __int64 v10; // x9
  int v11; // w8
  __int64 ipc_logbuf; // x0
  long double result; // q0
  __int64 ipc_logbuf_low; // x0

  v3 = ((*(_DWORD *)a2 & 0xF) << 10) | *a3;
  v4 = *(unsigned __int8 *)(a2 + 17);
  *a3 = v3;
  v5 = (16 * (*(_DWORD *)(a2 + 4) & 0x3F)) | v3;
  *a3 = v5;
  v6 = v5 | (8 * *(unsigned __int8 *)(a2 + 8));
  *a3 = v6;
  v7 = (4 * (*(_DWORD *)(a2 + 12) & 1)) | v6;
  *a3 = v7;
  v8 = v7 | (v4 | (2 * *(unsigned __int8 *)(a2 + 16))) ^ 1;
  *a3 = v8;
  v9 = v8 | (*(_DWORD *)(a2 + 4) << 10) & 0x30000;
  *a3 = v9;
  v10 = *(_QWORD *)(a2 + 24);
  if ( v10 )
  {
    v11 = (*(_DWORD *)(v10 + 20) << 12) & 0xC0000 | v9;
    *a3 = v11;
    *a3 = (*(_DWORD *)(*(_QWORD *)(a2 + 24) + 12LL) << 14) & 0x300000 | v11;
  }
  else
  {
    printk(&unk_3F4382, "ipareg_construct_endp_init_hdr_ext_n_v4_5");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d No header info, skipping it.\n",
        "ipareg_construct_endp_init_hdr_ext_n_v4_5",
        2582);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(
               ipc_logbuf_low,
               "ipahal %s:%d No header info, skipping it.\n",
               "ipareg_construct_endp_init_hdr_ext_n_v4_5",
               2582);
    }
  }
  return result;
}
