__int64 ipa_is_ready()
{
  char v0; // w19

  if ( ipa3_ctx )
  {
    mutex_lock(ipa3_ctx + 29472);
    v0 = *(_BYTE *)(ipa3_ctx + 43637);
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    v0 = 0;
  }
  return v0 & 1;
}
