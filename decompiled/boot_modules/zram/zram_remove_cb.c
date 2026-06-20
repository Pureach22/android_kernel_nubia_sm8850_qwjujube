__int64 __fastcall zram_remove_cb(__int64 a1, __int64 a2)
{
  if ( (unsigned int)zram_remove(a2) )
    __break(0x800u);
  return 0;
}
