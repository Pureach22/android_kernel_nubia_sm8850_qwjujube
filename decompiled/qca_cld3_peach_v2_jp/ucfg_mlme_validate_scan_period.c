bool __fastcall ucfg_mlme_validate_scan_period(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  if ( a10 >= 0xEA61 )
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Roam scan period value %d msec is out of range (Min: %d msec Max: %d msec)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "ucfg_mlme_validate_scan_period",
      a10,
      0,
      60000);
  return a10 < 0xEA61;
}
