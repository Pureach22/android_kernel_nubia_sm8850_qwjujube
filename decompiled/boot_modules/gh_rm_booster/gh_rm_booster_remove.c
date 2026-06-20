__int64 gh_rm_booster_remove()
{
  __int64 v0; // x0

  gh_rm_unregister_notifier(rm_status + 104);
  cancel_delayed_work_sync(rm_status + 128);
  mutex_lock(&rm_booster_lock);
  v0 = rm_status;
  if ( *(_DWORD *)rm_status )
  {
    gh_resume_rm_status();
    v0 = rm_status;
  }
  kfree(v0);
  rm_status = 0;
  return mutex_unlock(&rm_booster_lock);
}
