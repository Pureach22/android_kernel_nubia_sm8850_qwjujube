__int64 gf_remove()
{
  __int64 *v0; // x8
  __int64 v1; // x10
  __int64 v2; // x8
  unsigned __int64 v10; // x10

  printk(&unk_8964);
  wakeup_source_remove(&fp_wakelock);
  if ( qword_83A0 )
    input_unregister_device();
  input_free_device();
  mutex_lock(&device_list_lock);
  v0 = (__int64 *)qword_8380;
  if ( *(__int64 **)qword_8380 == &qword_8378 && (v1 = qword_8378, *(__int64 **)(qword_8378 + 8) == &qword_8378) )
  {
    *(_QWORD *)(qword_8378 + 8) = qword_8380;
    *v0 = v1;
  }
  else
  {
    _list_del_entry_valid_or_report(&qword_8378);
  }
  qword_8378 = 0xDEAD000000000100LL;
  qword_8380 = 0xDEAD000000000122LL;
  device_destroy(gf_class, (unsigned int)gf);
  v2 = 1LL << gf;
  _X9 = (unsigned __int64 *)&minors[((unsigned __int64)(unsigned int)gf >> 6) & 0x3FFF];
  __asm { PRFM            #0x11, [X9] }
  do
    v10 = __ldxr(_X9);
  while ( __stxr(v10 & ~v2, _X9) );
  if ( qword_8408 )
  {
    panel_event_notifier_unregister(cookie);
    cancel_delayed_work_sync(&qword_8410);
    destroy_workqueue(qword_8408);
  }
  return mutex_unlock(&device_list_lock);
}
