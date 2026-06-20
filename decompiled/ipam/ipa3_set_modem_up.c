__int64 __fastcall ipa3_set_modem_up(char a1)
{
  __int64 v2; // x0

  mutex_lock(ipa3_ctx + 52440);
  v2 = ipa3_ctx + 52440;
  *(_BYTE *)(ipa3_ctx + 51096) = a1;
  return mutex_unlock(v2);
}
