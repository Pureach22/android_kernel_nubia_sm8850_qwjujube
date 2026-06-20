_DWORD *__fastcall ipa_write_32(int a1, _DWORD *a2)
{
  if ( a2 )
  {
    *a2 = a1;
    return a2 + 1;
  }
  else
  {
    printk(&unk_3E8A9D, "ipa_write_32");
    return nullptr;
  }
}
