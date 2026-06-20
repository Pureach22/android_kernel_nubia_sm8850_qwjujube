__int64 __fastcall audio_ssr_register(__int64 a1)
{
  if ( a1 )
    return qcom_register_ssr_notifier();
  printk(&unk_846E, "audio_ssr_register");
  return -22;
}
