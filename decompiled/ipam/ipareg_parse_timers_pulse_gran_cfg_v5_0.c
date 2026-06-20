void __fastcall ipareg_parse_timers_pulse_gran_cfg_v5_0(__int64 a1, int *a2, unsigned int a3)
{
  ipareg_parse_timers_pulse_gran_cfg(a1, a2, a3);
  a2[3] = (a3 >> 9) & 7;
}
