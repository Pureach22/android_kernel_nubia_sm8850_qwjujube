__int64 __fastcall btpower_set_grant_state(int a1)
{
  __int64 v2; // x0

  mutex_lock(pwr_data + 224);
  v2 = pwr_data + 224;
  *(_DWORD *)(pwr_data + 280) = a1;
  return mutex_unlock(v2);
}
