__int64 __fastcall tgt_reg_process_master_chan_list_ext(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  psoc_obj = reg_get_psoc_obj(*a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_obj )
  {
    if ( *(_BYTE *)(psoc_obj + 91095) == 1 )
      return reg_process_master_chan_list_ext(a1);
    else
      return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "tgt_reg_process_master_chan_list_ext");
    return 16;
  }
}
