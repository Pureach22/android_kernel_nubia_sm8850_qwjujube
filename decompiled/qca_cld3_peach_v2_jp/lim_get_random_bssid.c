void *__fastcall lim_get_random_bssid(__int64 a1, void *a2)
{
  int system_ticks; // w0
  void *result; // x0
  _DWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  system_ticks = qdf_mc_timer_get_system_ticks();
  v5[0] = system_ticks | (system_ticks << 15);
  v5[1] = v5[0] >> 1;
  result = qdf_mem_copy(a2, v5, 6u);
  _ReadStatusReg(SP_EL0);
  return result;
}
