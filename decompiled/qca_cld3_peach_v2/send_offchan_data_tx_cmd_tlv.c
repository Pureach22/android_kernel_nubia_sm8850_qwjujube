__int64 __fastcall send_offchan_data_tx_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v3; // x25
  unsigned int v5; // w23
  int v6; // w27
  unsigned int v7; // w21
  __int64 v8; // x0
  unsigned __int8 *v9; // x26
  __int64 v10; // x19
  int v11; // w8
  int v12; // w3
  int v13; // w4
  __int64 v14; // x9
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x8
  __int64 v25; // x9
  int v26; // w10
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2

  v3 = *(_QWORD *)(a2 + 32);
  if ( *(unsigned __int16 *)(a2 + 8) >= 0x40u )
    v5 = 64;
  else
    v5 = *(unsigned __int16 *)(a2 + 8);
  v6 = ((_BYTE)v5 + 3) & 0xFC;
  v7 = v6 + 52;
  v8 = wmi_buf_alloc_fl(a1, v6 + 52, "send_offchan_data_tx_cmd_tlv", 0x1514u);
  if ( !v8 )
    return 2;
  v9 = *(unsigned __int8 **)(v8 + 224);
  v10 = v8;
  *(_DWORD *)v9 = 42139680;
  *((_DWORD *)v9 + 1) = *(unsigned __int8 *)(a2 + 10);
  *((_DWORD *)v9 + 2) = *(unsigned __int16 *)(a2 + 14);
  v11 = *(unsigned __int16 *)(a2 + 12);
  *((_DWORD *)v9 + 9) = v6 | 0x110000;
  *((_DWORD *)v9 + 3) = v11;
  qdf_mem_copy(v9 + 40, *(const void **)(a2 + 16), v5);
  _qdf_nbuf_map_single(v3, *(_QWORD *)a2, 1u);
  v12 = *((_DWORD *)v9 + 1);
  v13 = *((_DWORD *)v9 + 3);
  v14 = 40;
  if ( (*(_BYTE *)(*(_QWORD *)a2 + 68LL) & 4) != 0 )
    v14 = 80;
  v15 = *(_QWORD *)(*(_QWORD *)a2 + v14);
  *((_DWORD *)v9 + 4) = v15;
  *((_DWORD *)v9 + 5) = BYTE4(v15) & 0x1F;
  *((_DWORD *)v9 + 6) = *(unsigned __int16 *)(a2 + 8);
  *((_DWORD *)v9 + 7) = v5;
  *((_DWORD *)v9 + 8) = *(unsigned __int8 *)(a2 + 11);
  wmi_mgmt_cmd_record(a1, 28681, v9 + 40, v12, v13);
  if ( *(_BYTE *)(a2 + 11) == 1 )
  {
    v24 = &v9[((v5 + 3) & 0xFC) + 40];
    if ( !v24 )
    {
      v36 = "%s: Populate TX send params failed";
      goto LABEL_15;
    }
    v25 = *(_QWORD *)(a2 + 40);
    v26 = *((_DWORD *)v24 + 2) >> 26;
    *(_DWORD *)v24 = 42205192;
    *((_DWORD *)v24 + 1) = v25;
    *((_DWORD *)v24 + 2) = HIDWORD(v25) & 0x3FFFFFF | ((unsigned __int8)v26 << 26);
  }
  else
  {
    v7 = v6 + 40;
  }
  qdf_mtrace(49, 100, 0x389u, *((_DWORD *)v9 + 1), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v10,
             v7,
             0x7009u,
             "send_offchan_data_tx_cmd_tlv",
             0x1541u,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35);
  if ( !(_DWORD)result )
    return result;
  v36 = "%s: Failed to offchan data Tx";
LABEL_15:
  qdf_trace_msg(0x31u, 2u, v36, v16, v17, v18, v19, v20, v21, v22, v23, "send_offchan_data_tx_cmd_tlv");
  wmi_buf_free();
  return 16;
}
