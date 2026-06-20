__int64 __fastcall clear_index(__int64 a1, unsigned int a2)
{
  if ( a1 )
    return ipclite_global_test_and_clear_bit(a2 & 0x1F, a1 + 4LL * (a2 >> 5));
  else
    return printk(&unk_B037, "ipclite_test", "clear_index");
}
