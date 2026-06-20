__int64 __fastcall wma_crash_on_fw_timeout(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( (cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9) & 8) != 0
    || cds_is_fw_down(v10, v11, v12, v13, v14, v15, v16, v17) )
  {
    return 0;
  }
  else
  {
    return ((cds_get_driver_state(v18, v19, v20, v21, v22, v23, v24, v25) & 4) == 0) & a1;
  }
}
