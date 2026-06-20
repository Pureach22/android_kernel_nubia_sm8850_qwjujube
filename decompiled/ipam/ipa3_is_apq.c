bool ipa3_is_apq()
{
  return *(_DWORD *)(ipa3_ctx + 32256) == 2;
}
