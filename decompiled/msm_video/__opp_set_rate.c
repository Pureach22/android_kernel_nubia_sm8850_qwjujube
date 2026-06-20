__int64 __fastcall _opp_set_rate(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned int v5; // w19
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v6[0] = a2;
  if ( (unsigned __int64)dev_pm_opp_find_freq_ceil(v3 + 16, v6) < 0xFFFFFFFFFFFFF001LL
    || (unsigned __int64)dev_pm_opp_find_freq_floor(*a1 + 16, v6) < 0xFFFFFFFFFFFFF001LL )
  {
    dev_pm_opp_put();
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8DC7E, "high", 0xFFFFFFFFLL, "codec", "__opp_set_rate");
    result = dev_pm_opp_set_rate(*a1 + 16, v6[0]);
    if ( (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    {
      v5 = result;
      printk(&unk_86D68, "err ", 0xFFFFFFFFLL, "codec", "__opp_set_rate");
      result = v5;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D04D, "err ", 0xFFFFFFFFLL, "codec", "__opp_set_rate");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
