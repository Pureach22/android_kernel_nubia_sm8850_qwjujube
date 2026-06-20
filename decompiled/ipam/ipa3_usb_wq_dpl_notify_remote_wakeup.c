__int64 ipa3_usb_wq_dpl_notify_remote_wakeup()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x19

  v0 = raw_spin_lock_irqsave(ipa3_usb_ctx + 524);
  v1 = ipa3_usb_ctx;
  v2 = v0;
  if ( (*(_BYTE *)(ipa3_usb_ctx + 916) & 1) == 0 )
  {
    ipa3_usb_notify_do(1u, 1u);
    v1 = ipa3_usb_ctx;
  }
  *(_BYTE *)(v1 + 916) = 1;
  return raw_spin_unlock_irqrestore(v1 + 524, v2);
}
