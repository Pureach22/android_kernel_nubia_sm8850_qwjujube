__int64 __fastcall get_pack_checksum(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned __int8 a5)
{
  int v10; // w20
  unsigned __int64 v11; // x8
  unsigned int v12; // w10

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "get_pack_checksum", 1611);
  v10 = a3 + a4 + a5;
  if ( a3 )
  {
    v11 = 0;
    do
    {
      v12 = *(_DWORD *)(a2 + v11);
      v11 += 4LL;
      v10 += bswap32(v12);
    }
    while ( v11 < a3 );
  }
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] aw9610x check_sum = 0x%x\n", "get_pack_checksum", 1620, v10);
  return (unsigned int)-v10;
}
