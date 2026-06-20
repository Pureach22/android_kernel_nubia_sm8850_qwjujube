__int64 __fastcall synx_global_map_core_id(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( a1 < 8 )
    return dword_2BF00[a1];
  if ( (synx_debug & 1) != 0 )
    printk(&unk_27EB9, &unk_29207, "synx_global_map_core_id", 231, a5, a6);
  return 9;
}
