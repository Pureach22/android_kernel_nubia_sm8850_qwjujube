_BYTE *__fastcall ipa_write_8(char a1, _BYTE *a2)
{
  if ( a2 )
  {
    *a2 = a1;
    return a2 + 1;
  }
  else
  {
    _warn_printk("%s: NULL address\n", "ipa_write_8");
    __break(0x800u);
    return nullptr;
  }
}
