_QWORD *__fastcall ipa_write_64(__int64 a1, _QWORD *a2)
{
  if ( a2 )
  {
    *a2 = a1;
    return a2 + 1;
  }
  else
  {
    printk(&unk_3E8A9D, "ipa_write_64");
    return nullptr;
  }
}
