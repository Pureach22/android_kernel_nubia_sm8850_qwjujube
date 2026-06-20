unsigned __int64 __fastcall determine_memmap_size(__int64 a1)
{
  __int64 v2; // x0

  v2 = memory_block_size_bytes();
  return ((memory_block_size_bytes() * ((a1 + v2 - 2097153) / (unsigned __int64)(v2 - 0x200000))) >> 6)
       & 0x3FFFFFFFFFFFFC0LL;
}
