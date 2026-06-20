__int64 __fastcall cds_shutdown_notifier_register(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 *v5; // x19
  __int64 v6; // x9
  __int64 **v8; // x1

  v4 = _qdf_mem_malloc(0x20u, "cds_shutdown_notifier_register", 842);
  if ( !v4 )
    return 2;
  v5 = (__int64 *)v4;
  v6 = raw_spin_lock_irqsave(&ssr_protect_lock);
  if ( notifier_state == 1 )
  {
    raw_spin_unlock_irqrestore(&ssr_protect_lock, v6);
    _qdf_mem_free((__int64)v5);
    return 4294967274LL;
  }
  else
  {
    v5[2] = a1;
    v5[3] = a2;
    v8 = (__int64 **)qword_81CC88;
    if ( v5 == &shutdown_notifier_head
      || (__int64 *)qword_81CC88 == v5
      || *(__int64 **)qword_81CC88 != &shutdown_notifier_head )
    {
      _list_add_valid_or_report(v5, qword_81CC88);
    }
    else
    {
      qword_81CC88 = (__int64)v5;
      *v5 = (__int64)&shutdown_notifier_head;
      v5[1] = (__int64)v8;
      *v8 = v5;
    }
    raw_spin_unlock_irqrestore(&ssr_protect_lock, v6);
    return 0;
  }
}
