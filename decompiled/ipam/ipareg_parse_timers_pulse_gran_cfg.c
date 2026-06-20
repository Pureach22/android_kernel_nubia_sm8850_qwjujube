void __fastcall ipareg_parse_timers_pulse_gran_cfg(__int64 a1, int *a2, unsigned int a3)
{
  *a2 = a3 & 7;
  a2[1] = (a3 >> 3) & 7;
  a2[2] = (a3 >> 6) & 7;
}
