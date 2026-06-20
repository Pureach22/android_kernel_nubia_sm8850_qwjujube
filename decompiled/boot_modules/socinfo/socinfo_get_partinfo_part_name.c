void *__fastcall socinfo_get_partinfo_part_name(unsigned int a1)
{
  void *v1; // x9

  v1 = &unk_C334;
  if ( a1 != 1 )
    v1 = nullptr;
  if ( (unsigned int)socinfo_format < 0x10 || a1 > 0x10 )
    return nullptr;
  else
    return v1;
}
