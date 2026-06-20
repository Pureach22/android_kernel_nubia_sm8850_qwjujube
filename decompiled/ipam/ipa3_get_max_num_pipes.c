__int64 ipa3_get_max_num_pipes()
{
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
    return 31;
  else
    return 36;
}
