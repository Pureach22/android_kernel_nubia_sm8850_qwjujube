void adspsleepmon_lpm_adsp_panic_overall()
{
  __int64 v0; // x0

  if ( byte_A634 == 1 )
  {
    v0 = printk(&unk_A430);
    sleepmon_send_ssr_command(v0);
  }
}
