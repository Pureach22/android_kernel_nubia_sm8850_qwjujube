__int64 cds_shutdown_notifier_call()
{
  __int64 v0; // x1
  __int64 *v1; // x22
  __int64 v2; // x0
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0

  v0 = raw_spin_lock_irqsave(&ssr_protect_lock);
  v1 = (__int64 *)shutdown_notifier_head;
  for ( notifier_state = 1; v1 != &shutdown_notifier_head; v0 = v4 )
  {
    raw_spin_unlock_irqrestore(&ssr_protect_lock, v0);
    v3 = (void (__fastcall *)(_QWORD))v1[2];
    v2 = v1[3];
    if ( *((_DWORD *)v3 - 1) != 251140989 )
      __break(0x8228u);
    v3(v2);
    v4 = raw_spin_lock_irqsave(&ssr_protect_lock);
    v1 = (__int64 *)*v1;
  }
  notifier_state = 0;
  return raw_spin_unlock_irqrestore(&ssr_protect_lock, v0);
}
