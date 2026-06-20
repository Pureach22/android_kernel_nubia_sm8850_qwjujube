void *__fastcall sme_qos_cleanup_ctrl_blk_for_handoff(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w20
  __int64 v10; // x19
  __int64 v11; // x19
  void *result; // x0

  v9 = a1;
  v10 = qword_91F2D8;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: invoked on session %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sme_qos_cleanup_ctrl_blk_for_handoff",
    a1);
  v11 = v10 + 3040LL * v9;
  qdf_mem_set((void *)(v11 + 16), 0x98u, 0);
  qdf_mem_set((void *)(v11 + 168), 0x98u, 0);
  *(_WORD *)(v11 + 4) = 0;
  *(_DWORD *)(v11 + 320) = 0;
  *(_DWORD *)(v11 + 12) = 2;
  qdf_mem_set((void *)(v11 + 744), 0x98u, 0);
  qdf_mem_set((void *)(v11 + 896), 0x98u, 0);
  *(_WORD *)(v11 + 732) = 0;
  *(_DWORD *)(v11 + 1048) = 0;
  *(_DWORD *)(v11 + 740) = 2;
  qdf_mem_set((void *)(v11 + 1472), 0x98u, 0);
  qdf_mem_set((void *)(v11 + 1624), 0x98u, 0);
  *(_WORD *)(v11 + 1460) = 0;
  *(_DWORD *)(v11 + 1776) = 0;
  *(_DWORD *)(v11 + 1468) = 2;
  qdf_mem_set((void *)(v11 + 2200), 0x98u, 0);
  result = qdf_mem_set((void *)(v11 + 2352), 0x98u, 0);
  *(_WORD *)(v11 + 2188) = 0;
  *(_DWORD *)(v11 + 2504) = 0;
  *(_DWORD *)(v11 + 2196) = 2;
  return result;
}
