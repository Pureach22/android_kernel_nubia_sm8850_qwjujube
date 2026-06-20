__int64 __fastcall tgt_reg_process_txpb_event_handler(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
    return reg_process_txpb_event(a1, a2, v12, v13, v14, v15, v16, v17, v18, v19);
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: psoc reg component is NULL",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "tgt_reg_process_txpb_event_handler");
  return 16;
}
