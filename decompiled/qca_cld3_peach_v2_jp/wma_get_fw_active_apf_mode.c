__int64 __fastcall wma_get_fw_active_apf_mode(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19

  if ( a1 >= 3 )
  {
    v9 = 2;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid Active APF Mode %d; Using 'disabled'",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_get_fw_active_apf_mode",
      a1);
  }
  else
  {
    return dword_A17E48[a1];
  }
  return v9;
}
