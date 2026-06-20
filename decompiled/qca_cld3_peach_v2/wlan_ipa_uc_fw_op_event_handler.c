__int64 __fastcall wlan_ipa_uc_fw_op_event_handler(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  const char *v11; // x3
  __int64 result; // x0
  __int16 v13; // w8
  __int64 v14; // x19
  __int64 v15; // x21
  __int64 v16; // x23
  __int64 v17; // x0
  char v18; // w8
  __int64 v19; // x23
  __int64 v20; // x23
  __int64 v21; // x1
  __int64 v22; // x0
  __int16 v23; // w8
  __int64 v24; // x23

  if ( (qdf_is_recovering() & 1) != 0 )
  {
    v10 = "%s: in recovering";
    v11 = "wlan_ipa_uc_fw_op_event_handler";
    return qdf_trace_msg(0x61u, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, v11);
  }
  v13 = *(_WORD *)(a1 + 80);
  v14 = *(_QWORD *)(a1 + 64);
  if ( (v13 & 1) == 0 )
  {
    v15 = *(_QWORD *)(a1 + 48);
    *(_QWORD *)(a1 + 48) = 0;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: posted msg %d",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "__wlan_ipa_uc_fw_op_event_handler",
      *(unsigned __int16 *)(v15 + 2));
    return wlan_ipa_uc_op_cb(v15, v14);
  }
  if ( (v13 & 2) != 0 )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: filter delete notification",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "__wlan_ipa_uc_fw_op_event_handler");
    v20 = wlan_fw_event_msg_list_dequeue(a1);
    result = qdf_event_set(v14 + 7472, v21);
    if ( v20 )
    {
      while ( 1 )
      {
        v22 = _qdf_mem_malloc(0x20u, "__wlan_ipa_uc_fw_op_event_handler", 6351);
        if ( !v22 )
          break;
        *(_DWORD *)(v22 + 24) = *(_DWORD *)(v20 + 20);
        *(_WORD *)(v22 + 2) = *(_WORD *)(v20 + 16);
        v23 = *(_WORD *)(v20 + 24);
        v24 = v22;
        *(_WORD *)(v22 + 6) = v23;
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: posted msg %d",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          "__wlan_ipa_uc_fw_op_event_handler");
        wlan_ipa_uc_op_cb(v24, v14);
        result = wlan_fw_event_msg_list_dequeue(a1);
        v20 = result;
        if ( !result )
          return result;
      }
      goto LABEL_17;
    }
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: dequeuing msg from list",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "__wlan_ipa_uc_fw_op_event_handler");
    result = wlan_fw_event_msg_list_dequeue(a1);
    if ( result )
    {
      v16 = result;
      while ( 1 )
      {
        v17 = _qdf_mem_malloc(0x20u, "__wlan_ipa_uc_fw_op_event_handler", 6372);
        if ( !v17 )
          break;
        *(_WORD *)(v17 + 2) = *(_WORD *)(v16 + 16);
        *(_QWORD *)(v17 + 16) = *(_QWORD *)(v16 + 8);
        v18 = *(_BYTE *)v16;
        v19 = v17;
        *(_BYTE *)(v17 + 8) = v18;
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: posted msg %d",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          "__wlan_ipa_uc_fw_op_event_handler");
        wlan_ipa_uc_op_cb(v19, v14);
        result = wlan_fw_event_msg_list_dequeue(a1);
        v16 = result;
        if ( !result )
          return result;
      }
LABEL_17:
      v10 = "%s: Message memory allocation failed";
      v11 = "__wlan_ipa_uc_fw_op_event_handler";
      return qdf_trace_msg(0x61u, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, v11);
    }
  }
  return result;
}
