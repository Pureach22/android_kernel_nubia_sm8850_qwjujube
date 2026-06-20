__int64 __fastcall reg_process_txpb_event(
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
  __int64 psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  void (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x0

  psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_obj )
  {
    v20 = *(void (__fastcall **)(__int64, __int64))(psoc_obj + 93976);
    if ( v20 )
    {
      v21 = *(_QWORD *)(psoc_obj + 93984);
      if ( *((_DWORD *)v20 - 1) != 1468230183 )
        __break(0x8228u);
      v20(v21, a2);
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: TPB: soc_reg->txpb_cbk.cbk NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_process_txpb_event");
    }
    return 0;
  }
  else
  {
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
      "reg_process_txpb_event");
    return 16;
  }
}
