__int64 __fastcall msm_vidc_adjust_bitrate_apv(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v6; // w19
  __int64 v8; // x21

  if ( (unsigned int)(*(_DWORD *)(a1 + 604) * *(_DWORD *)(a1 + 600)) >> 14 >= 0x7E9
    && (unsigned int)msm_vidc_apv_bitrate >= 0x77359400 )
  {
    v6 = msm_vidc_apv_bitrate;
    if ( (unsigned int)msm_vidc_apv_bitrate > 0xC4B20100 )
    {
      v6 = -994967296;
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v8 = a1;
        printk(&unk_8D2FE, "high", a1 + 340, "msm_vidc_adjust_bitrate_apv", a5);
        a1 = v8;
      }
      msm_vidc_apv_bitrate = -994967296;
    }
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_7F467, "high", a1 + 340, "msm_vidc_adjust_bitrate_apv", v6);
  }
  ((void (*)(void))msm_vidc_update_cap_value)();
  return 0;
}
