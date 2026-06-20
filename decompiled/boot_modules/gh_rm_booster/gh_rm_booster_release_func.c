__int64 gh_rm_booster_release_func()
{
  __int64 v0; // x0

  v0 = mutex_lock(&rm_booster_lock);
  if ( rm_status && *(_DWORD *)rm_status )
  {
    gh_resume_rm_status(v0);
    *(_DWORD *)rm_status = 0;
  }
  return mutex_unlock(&rm_booster_lock);
}
