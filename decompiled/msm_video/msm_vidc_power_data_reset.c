__int64 __fastcall msm_vidc_power_data_reset(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( a1 && (msm_vidc_debug & 0xA) != 0 )
    printk(&unk_85D29, "high", a1 + 340, "msm_vidc_power_data_reset", a5);
  msm_vidc_dcvs_data_reset((unsigned int *)a1);
  *(_DWORD *)(a1 + 1916) = 0;
  *(_QWORD *)(a1 + 1996) = 0x7FFFFFFF00000000LL;
  *(_QWORD *)(a1 + 2004) = 0x100000001LL;
  return msm_vidc_scale_power(a1, 1);
}
