__int64 __fastcall msm_vidc_error_state(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x4
  const char *v8; // x4

  if ( (mutex_is_locked(a1 + 16) & 1) != 0 )
  {
    if ( a2 == 5 )
      return msm_vidc_stop_streaming(a1, a3);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      if ( a2 <= 8 )
        v8 = event_name_arr[a2];
      else
        v8 = "UNKNOWN EVENT";
      printk(&unk_84523, "err ", a1 + 340, "msm_vidc_error_state", v8);
    }
  }
  else
  {
    __break(0x800u);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_839CB, "err ", a1 + 340, "msm_vidc_error_state", v6);
  }
  return 4294967274LL;
}
