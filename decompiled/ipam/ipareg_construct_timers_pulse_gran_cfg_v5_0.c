__int64 __fastcall ipareg_construct_timers_pulse_gran_cfg_v5_0(__int64 a1, unsigned int *a2, _DWORD *a3)
{
  __int64 result; // x0

  *a3 |= (unsigned __int8)ipareg_timers_pulse_gran_code(*a2);
  *a3 |= 8 * (ipareg_timers_pulse_gran_code(a2[1]) & 0x1F);
  *a3 |= (unsigned __int8)ipareg_timers_pulse_gran_code(a2[2]) << 6;
  result = ipareg_timers_pulse_gran_code(a2[3]);
  *a3 |= (unsigned __int8)result << 9;
  return result;
}
