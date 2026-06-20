__int64 __fastcall send_multiple_add_clear_mcbc_filter_cmd_tlv(__int64 a1, unsigned __int8 a2, unsigned int *a3)
{
  int v5; // w25
  __int64 v7; // x0
  _DWORD *v8; // x22
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  int v19; // w8
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x26
  unsigned __int64 v30; // x23
  _DWORD *v31; // x27
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 result; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  v5 = 8 * *a3;
  v7 = wmi_buf_alloc_fl(a1, v5 + 20, "send_multiple_add_clear_mcbc_filter_cmd_tlv", 0x283u);
  if ( !v7 )
    return 2;
  v8 = *(_DWORD **)(v7 + 224);
  v9 = v7;
  qdf_mem_set(v8, 0x10u, 0);
  *v8 = 36110348;
  if ( *((_BYTE *)a3 + 1444) )
    v18 = 4;
  else
    v18 = 3;
  v8[1] = a2;
  v8[2] = v18;
  v19 = *a3;
  v8[3] = *a3;
  v8[4] = (8 * (v19 & 0x1FFF)) | 0x130000;
  if ( *a3
    && (v20 = qdf_trace_msg(
                0x31u,
                8u,
                "%s: multicast addr cnt: %u",
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                "send_multiple_add_clear_mcbc_filter_cmd_tlv"),
        *a3) )
  {
    v29 = 0;
    v30 = 0;
    v31 = v8 + 5;
    while ( 1 )
    {
      *v31 = *(unsigned int *)((char *)a3 + v29 + 4);
      v31[1] = *(unsigned __int16 *)((char *)a3 + v29 + 8);
      if ( v29 == 1440 )
        break;
      if ( (unsigned int *)((char *)a3 + v29) == (unsigned int *)-4LL )
      {
        v34 = 0;
        v32 = 0;
        v33 = 0;
        v35 = 0;
      }
      else
      {
        v32 = *((unsigned __int8 *)a3 + v29 + 4);
        v33 = *((unsigned __int8 *)a3 + v29 + 5);
        v34 = *((unsigned __int8 *)a3 + v29 + 6);
        v35 = *((unsigned __int8 *)a3 + v29 + 9);
      }
      v20 = qdf_trace_msg(
              0x31u,
              8u,
              "mac addr[%d]: %02x:%02x:%02x:**:**:%02x",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              (unsigned int)v30++,
              v32,
              v33,
              v34,
              v35);
      v31 += 2;
      v29 += 6;
      if ( v30 >= *a3 )
        goto LABEL_13;
    }
    __break(0x5512u);
    __asm { STGP            X19, X6, [X29,#0x20+var_20+4]! }
    return send_conf_hw_filter_cmd_tlv(v20);
  }
  else
  {
LABEL_13:
    wmi_mtrace(0x1D015u, v8[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v9,
               v5 + 20,
               0x1D015u,
               "send_multiple_add_clear_mcbc_filter_cmd_tlv",
               0x2B1u,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set_param cmd %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "send_multiple_add_clear_mcbc_filter_cmd_tlv",
        (unsigned int)result);
      wmi_buf_free();
      return 16;
    }
  }
  return result;
}
