__int64 __fastcall socinfo_get_partinfo_chip_id(unsigned int a1)
{
  unsigned int v1; // w9

  v1 = dword_C32C;
  if ( a1 != 1 )
    v1 = 0;
  if ( (unsigned int)socinfo_format < 0x10 || a1 > 0x10 )
    return 0;
  else
    return v1;
}
