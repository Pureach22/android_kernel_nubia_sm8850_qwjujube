__int64 __fastcall msm_vidc_adjust_dec_operating_rate(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 308) == 1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_89856, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_adjust_dec_operating_rate");
    return 4294967274LL;
  }
  else
  {
    ((void (*)(void))msm_vidc_update_cap_value)();
    return 0;
  }
}
