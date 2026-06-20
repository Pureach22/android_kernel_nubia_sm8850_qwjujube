char *__fastcall ipa_pad_to_32(char *result)
{
  char *v1; // x19
  size_t v2; // x20

  if ( result )
  {
    if ( ((unsigned __int8)result & 7u) - 1 <= 2 )
    {
      v1 = result;
      v2 = 4 - ((unsigned __int8)result & 7u);
      memset(result, 0, v2);
      return &v1[v2];
    }
  }
  else
  {
    _warn_printk("%s: NULL address\n", "ipa_pad_to_32");
    __break(0x800u);
    return nullptr;
  }
  return result;
}
