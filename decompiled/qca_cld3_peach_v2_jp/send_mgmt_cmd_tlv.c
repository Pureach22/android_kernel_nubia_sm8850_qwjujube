__int64 __fastcall send_mgmt_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned int v5; // w24
  __int64 v6; // x27
  unsigned int v7; // w23
  __int64 v8; // x0
  unsigned __int8 *v9; // x26
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  int v20; // w3
  int v21; // w4
  __int64 v22; // x9
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 *v32; // x24
  __int64 v33; // x8
  int v34; // w9
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2

  v3 = *(_QWORD *)(a2 + 32);
  if ( *(unsigned __int16 *)(a2 + 8) >= 0x40u )
    v5 = 64;
  else
    v5 = *(unsigned __int16 *)(a2 + 8);
  v6 = (unsigned __int8)(v5 + 3) & 0xFC;
  v7 = v6 + 72;
  v8 = wmi_buf_alloc_fl(a1, (int)v6 + 72, "send_mgmt_cmd_tlv", 0x149Cu);
  if ( !v8 )
    return 2;
  v9 = *(unsigned __int8 **)(v8 + 224);
  v10 = v8;
  *(_DWORD *)v9 = 27656232;
  *((_DWORD *)v9 + 1) = *(unsigned __int8 *)(a2 + 10);
  *((_DWORD *)v9 + 2) = *(unsigned __int16 *)(a2 + 14);
  *((_DWORD *)v9 + 3) = *(unsigned __int16 *)(a2 + 12);
  *((_DWORD *)v9 + 10) = *(char *)(a2 + 56);
  *((_DWORD *)v9 + 11) = v6 | 0x110000;
  qdf_mem_copy(v9 + 48, *(const void **)(a2 + 16), v5);
  if ( !(unsigned int)_qdf_nbuf_map_single(v3, *(_QWORD *)a2, 1u) )
  {
    v20 = *((_DWORD *)v9 + 1);
    v21 = *((_DWORD *)v9 + 3);
    v22 = 40;
    if ( (*(_BYTE *)(*(_QWORD *)a2 + 68LL) & 4) != 0 )
      v22 = 80;
    v23 = *(_QWORD *)(*(_QWORD *)a2 + v22);
    *((_DWORD *)v9 + 4) = v23;
    *((_DWORD *)v9 + 5) = BYTE4(v23) & 0x1F;
    *((_DWORD *)v9 + 6) = *(unsigned __int16 *)(a2 + 8);
    *((_DWORD *)v9 + 7) = v5;
    *((_DWORD *)v9 + 8) = *(unsigned __int8 *)(a2 + 48);
    *((_DWORD *)v9 + 9) = *(_DWORD *)(a2 + 52);
    wmi_mgmt_cmd_record(a1, 28680, v9 + 48, v20, v21);
    v32 = &v9[v6 + 48];
    if ( *(_BYTE *)(a2 + 48) == 1 )
    {
      if ( !v32 )
      {
        v43 = "%s: Populate TX send params failed";
LABEL_19:
        qdf_trace_msg(0x31u, 2u, v43, v24, v25, v26, v27, v28, v29, v30, v31, "send_mgmt_cmd_tlv");
        _qdf_nbuf_unmap_single(v3, *(_QWORD *)a2, 1);
        goto LABEL_20;
      }
      v33 = *(_QWORD *)(a2 + 40);
      v34 = *((_DWORD *)v32 + 2) >> 26;
      *(_DWORD *)v32 = 42205192;
      *((_DWORD *)v32 + 1) = v33;
      *((_DWORD *)v32 + 2) = HIDWORD(v33) & 0x3FFFFFF | ((unsigned __int8)v34 << 26);
      if ( !*(_BYTE *)(a2 + 57) )
        goto LABEL_13;
    }
    else
    {
      *(_DWORD *)v32 = 42205192;
      if ( !*(_BYTE *)(a2 + 57) )
      {
LABEL_13:
        v7 = v6 + 60;
LABEL_16:
        qdf_mtrace(49, 100, 0x388u, *((_DWORD *)v9 + 1), 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v10,
                   v7,
                   0x7008u,
                   "send_mgmt_cmd_tlv",
                   0x14EDu,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42);
        if ( !(_DWORD)result )
          return result;
        v43 = "%s: Failed to send mgmt Tx";
        goto LABEL_19;
      }
    }
    qdf_trace_msg(0x31u, 8u, "%s: Set mlo mgmt tid", v24, v25, v26, v27, v28, v29, v30, v31, "send_mgmt_cmd_tlv");
    *((_DWORD *)v32 + 5) = -1;
    *(_QWORD *)(v32 + 12) = 0x3C6000400120008LL;
    goto LABEL_16;
  }
  qdf_trace_msg(0x31u, 2u, "%s: wmi buf map failed", v11, v12, v13, v14, v15, v16, v17, v18, "send_mgmt_cmd_tlv");
LABEL_20:
  wmi_buf_free();
  return 16;
}
