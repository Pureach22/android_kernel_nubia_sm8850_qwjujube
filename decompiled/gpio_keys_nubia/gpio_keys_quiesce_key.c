__int64 __fastcall gpio_keys_quiesce_key(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 16) )
    return cancel_delayed_work_sync(a1 + 80);
  else
    return timer_delete_sync(a1 + 32);
}
