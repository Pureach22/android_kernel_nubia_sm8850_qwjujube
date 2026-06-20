__int64 __fastcall send_encrypt_decrypt_send_cmd_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w22
  __int64 v13; // x0
  __int64 v14; // x23
  __int64 v15; // x19
  int v16; // w8
  int v17; // w3
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Send encrypt decrypt cmd",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_encrypt_decrypt_send_cmd_tlv");
  v12 = *(_DWORD *)(a2 + 100);
  v13 = wmi_buf_alloc_fl(a1, v12 + 112, "send_encrypt_decrypt_send_cmd_tlv", 0x2E03u);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 224);
    v15 = v13;
    *(_DWORD *)v14 = 38338664;
    *(_DWORD *)(v14 + 4) = *(_DWORD *)a2;
    *(_DWORD *)(v14 + 8) = *(unsigned __int8 *)(a2 + 4);
    *(_DWORD *)(v14 + 12) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v14 + 16) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v14 + 20) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v14 + 24) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(v14 + 28) = *(_DWORD *)(a2 + 24);
    qdf_mem_copy((void *)(v14 + 32), (const void *)(a2 + 28), *(unsigned int *)(a2 + 16));
    qdf_mem_copy((void *)(v14 + 72), (const void *)(a2 + 68), 0x20u);
    v16 = *(_DWORD *)(a2 + 100);
    *(_DWORD *)(v14 + 104) = v16;
    if ( v16 )
    {
      *(_DWORD *)(v14 + 108) = ((_WORD)v16 + 3) & 0xFFFC | 0x110000;
      qdf_mem_copy((void *)(v14 + 112), *(const void **)(a2 + 104), *(unsigned int *)(a2 + 100));
    }
    v17 = *(_DWORD *)(v14 + 4);
    *(_BYTE *)(v14 + 69) = *(_BYTE *)(a2 + 60);
    *(_BYTE *)(v14 + 68) = *(_BYTE *)(a2 + 61);
    *(_BYTE *)(v14 + 67) = *(_BYTE *)(a2 + 62);
    *(_BYTE *)(v14 + 66) = *(_BYTE *)(a2 + 63);
    *(_BYTE *)(v14 + 65) = *(_BYTE *)(a2 + 64);
    *(_BYTE *)(v14 + 64) = *(_BYTE *)(a2 + 65);
    qdf_mtrace(49, 100, 0x29Au, v17, 0);
    v26 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            v12 + 112,
            0x501Au,
            "send_encrypt_decrypt_send_cmd_tlv",
            0x2E34u,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( v26 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send ENCRYPT DECRYPT cmd: %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "send_encrypt_decrypt_send_cmd_tlv",
        v26);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v26;
}
