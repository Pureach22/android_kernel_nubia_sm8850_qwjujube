__int64 ipa3_get_pdev()
{
  if ( ipa3_ctx )
    return *(_QWORD *)(ipa3_ctx + 34216);
  else
    return 0;
}
