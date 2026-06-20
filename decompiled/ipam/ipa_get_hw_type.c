__int64 ipa_get_hw_type()
{
  if ( ipa3_ctx )
    return *(unsigned int *)(ipa3_ctx + 32240);
  else
    return 0;
}
