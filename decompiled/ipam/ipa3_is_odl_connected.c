__int64 ipa3_is_odl_connected()
{
  return (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 7) & 1;
}
