__int64 __fastcall reg_set_hal_reg_cap(
        __int64 a1,
        const void *a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  psoc_obj = reg_get_psoc_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( psoc_obj )
  {
    if ( a3 < 4u )
    {
      qdf_mem_copy((void *)(psoc_obj + 93088), a2, 16 * ((3 * a3) & 0xFFFu));
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: phy cnt:%d is more than %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "reg_set_hal_reg_cap");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_set_hal_reg_cap");
    return 16;
  }
}
