__int64 __fastcall send_setup_install_key_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  int v8; // w9
  int v9; // w8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  unsigned int v19; // w20

  v4 = (*((unsigned __int16 *)a2 + 1) + 3) & 0x1FFFC;
  v5 = wmi_buf_alloc_fl(a1, v4 + 108, "send_setup_install_key_cmd_tlv", 0x1980u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 6291556;
  v6[1] = *a2;
  v6[4] = *((_DWORD *)a2 + 1);
  if ( *((_DWORD *)a2 + 2) )
  {
    v6[24] = 1;
    v6[25] = *((_DWORD *)a2 + 2);
  }
  v8 = v6[5];
  v6[2] = *((_DWORD *)a2 + 3);
  v6[3] = *((unsigned __int16 *)a2 + 8);
  v6[5] = v8 | *((_DWORD *)a2 + 5);
  v6[6] = *((_DWORD *)a2 + 6);
  v9 = *((_DWORD *)a2 + 7);
  if ( v9 && *((_DWORD *)a2 + 8) )
  {
    v6[22] = v9;
    v6[23] = *((_DWORD *)a2 + 8);
  }
  qdf_mem_copy(v6 + 17, a2 + 72, 0x10u);
  qdf_mem_copy(v6 + 13, a2 + 56, 0x10u);
  v6[26] = (*((_WORD *)a2 + 1) + 3) & 0xFFFC | 0x110000;
  qdf_mem_copy(v6 + 27, a2 + 88, *((unsigned __int16 *)a2 + 1));
  qdf_mem_copy(v6 + 7, a2 + 48, 8u);
  v6[21] = *((unsigned __int16 *)a2 + 1);
  qdf_mem_copy(v6 + 11, a2 + 40, 8u);
  qdf_mtrace(49, 100, 0x289u, v6[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             v4 + 108,
             0x5009u,
             "send_setup_install_key_cmd_tlv",
             0x19B4u,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_mem_set(*(void **)(v7 + 224), (unsigned int)(v4 + 108), 0);
    wmi_buf_free();
    return v19;
  }
  return result;
}
