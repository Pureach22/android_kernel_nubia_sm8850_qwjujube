__int64 __fastcall dp_fim_free_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  v9 = a1 - 16;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: FIM: reclaim node for policy_id:%llx metadata:%x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_fim_free_cb",
    *(_QWORD *)(a1 + 88),
    *(unsigned int *)(a1 + 72));
  return _qdf_mem_free(v9);
}
