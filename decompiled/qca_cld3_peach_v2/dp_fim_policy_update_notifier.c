__int64 __fastcall dp_fim_policy_update_notifier(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 v12; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  __int64 v33; // x20
  unsigned int multiplier; // w0

  if ( !a1 || !a3 )
  {
    v31 = "%s: notifier called with invalid data";
LABEL_12:
    qdf_trace_msg(0x45u, 2u, v31, a4, a5, a6, a7, a8, a9, a10, a11, "dp_fim_policy_update_notifier");
    return 4294967274LL;
  }
  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 )
  {
    v31 = "%s: dp_intf is null";
    goto LABEL_12;
  }
  v12 = *(_QWORD *)(v11 + 3720);
  if ( !v12 )
  {
    v31 = "%s: fim_ctx is null";
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: policy notifier called state:%lu id:%llu prio:%hhu",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_fim_policy_update_notifier",
    a2,
    *(_QWORD *)(a3 + 48),
    *(unsigned __int8 *)(a3 + 56));
  switch ( a2 )
  {
    case 3LL:
      dp_fim_hash_table_delete_node(v12, (_DWORD *)a3, a3, 2);
      ++*(_DWORD *)(v12 + 2112);
      break;
    case 2LL:
      dp_fim_hash_table_delete_node(v12, (_DWORD *)a3, a3, 2);
      ++*(_DWORD *)(v12 + 2108);
      break;
    case 1LL:
      dp_fim_hash_table_delete_node(v12, (_DWORD *)a3, a3, 4);
      ++*(_DWORD *)(v12 + 2104);
      break;
    default:
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: not supported state:%lu",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "dp_fim_policy_update_notifier",
        a2);
      break;
  }
  if ( *(_DWORD *)(v12 + 2104) == *(_DWORD *)(v12 + 2108) )
  {
    *(_BYTE *)v12 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Disable FIM for dp_intf:%02x:%02x:%02x:**:**:%02x",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_fim_policy_update_notifier",
      *(unsigned __int8 *)(v11 + 20),
      *(unsigned __int8 *)(v11 + 21),
      *(unsigned __int8 *)(v11 + 22),
      *(unsigned __int8 *)(v11 + 25));
  }
  else
  {
    *(_BYTE *)v12 = 1;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Enable FIM for dp_intf:%02x:%02x:%02x:**:**:%02x",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_fim_policy_update_notifier",
      *(unsigned __int8 *)(v11 + 20),
      *(unsigned __int8 *)(v11 + 21),
      *(unsigned __int8 *)(v11 + 22),
      *(unsigned __int8 *)(v11 + 25));
    v33 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    mod_timer(v12 + 2136, v33 + 30000LL * multiplier);
  }
  return 0;
}
