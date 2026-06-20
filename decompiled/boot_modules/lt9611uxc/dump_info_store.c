__int64 __fastcall dump_info_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22

  v4 = *(_QWORD *)(a1 + 152);
  if ( v4 )
  {
    print_hex_dump(&unk_B105, &unk_A8C1, 0, 16, 1, v4 + 3504, 128, 0);
    print_hex_dump(&unk_B105, &unk_A8C1, 0, 16, 1, v4 + 3632, 128, 0);
  }
  else
  {
    printk(&unk_B00B, "dump_info_store");
    return -22;
  }
  return a4;
}
