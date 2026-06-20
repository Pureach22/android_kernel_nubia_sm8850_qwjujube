_WORD *__fastcall ipa_write_16(__int16 a1, _WORD *a2)
{
  if ( a2 )
  {
    *a2 = a1;
    return a2 + 1;
  }
  else
  {
    printk(&unk_3E8A9D, "ipa_write_16");
    return nullptr;
  }
}
