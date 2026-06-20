__int64 __fastcall msm_vidc_get_platform_data_alor(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_vidc_debug & 2) != 0 )
  {
    v2 = a1;
    printk(&unk_935D1, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data_alor");
    a1 = v2;
  }
  memcpy(*(void **)(a1 + 3912), &alor_data, 0x288u);
  return 0;
}
