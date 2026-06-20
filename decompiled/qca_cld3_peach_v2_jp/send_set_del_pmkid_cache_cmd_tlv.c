__int64 __fastcall send_set_del_pmkid_cache_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w20
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  int v8; // w1
  __int64 result; // x0
  size_t v10; // x2
  size_t v11; // x2
  size_t v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20

  if ( !a2 )
    return 4;
  if ( a2[148] )
    v4 = 16;
  else
    v4 = 168;
  v5 = wmi_buf_alloc_fl(a1, v4, "send_set_del_pmkid_cache_cmd_tlv", 0x68Eu);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 43843596;
  v8 = *a2;
  v6[2] = v8;
  if ( a2[148] == 1 )
  {
    v6[1] = 1;
    v6[3] = 0;
  }
  else
  {
    v6[5] = 43909264;
    *(_QWORD *)(v6 + 3) = 0x12009400000001LL;
    v10 = *((unsigned int *)a2 + 1);
    v6[6] = v10;
    qdf_mem_copy(v6 + 7, a2 + 8, v10);
    v11 = *((unsigned int *)a2 + 18);
    v6[23] = v11;
    qdf_mem_copy(v6 + 24, a2 + 76, v11);
    qdf_mem_copy(v6 + 28, a2 + 92, 8u);
    v12 = a2[100];
    v6[30] = v12;
    qdf_mem_copy(v6 + 31, a2 + 101, v12);
    v8 = v6[2];
    v6[39] = *((_DWORD *)a2 + 34);
    v6[40] = *((_DWORD *)a2 + 35);
    v6[41] = *((_DWORD *)a2 + 36);
  }
  wmi_mtrace(0x402Eu, v8, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             v4,
             0x402Eu,
             "send_set_del_pmkid_cache_cmd_tlv",
             0x6BEu,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20);
  if ( (_DWORD)result )
  {
    v29 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send set del pmkid cache command %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "send_set_del_pmkid_cache_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return v29;
  }
  return result;
}
