__int64 __fastcall populate_dot11f_capabilities(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int capability_info; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int16 v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  capability_info = lim_get_capability_info(a1, &v24, a3, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( capability_info )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to retrieve the Capabilities bitfield from CFG status: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "populate_dot11f_capabilities",
      capability_info);
  }
  else
  {
    if ( (a4 & 1) != 0 )
      lim_update_cu_flag();
    *a2 = v24;
  }
  _ReadStatusReg(SP_EL0);
  return capability_info;
}
