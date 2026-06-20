unsigned __int64 __fastcall set_memblk_bitmap_online(unsigned __int64 a1)
{
  __int64 v1; // x10
  __int64 i; // x20
  unsigned __int64 v3; // x12
  __int64 v4; // x8
  unsigned __int64 v5; // x22
  unsigned __int64 result; // x0
  int v7; // w8
  int v8; // w10

  if ( num_segments < 1 )
    return printk(&unk_A1EB);
  v1 = 0;
  for ( i = 24; ; i += 32 )
  {
    v3 = *(_QWORD *)(segment_infos + i - 24);
    if ( v3 <= a1 && *(_QWORD *)(segment_infos + i - 16) + v3 > a1 )
      break;
    if ( num_segments == ++v1 )
      return printk(&unk_A1EB);
  }
  if ( (v1 & 0x80000000) != 0 )
    return printk(&unk_A1EB);
  v4 = *(_QWORD *)(segment_infos + i - 24);
  if ( *(_QWORD *)(segment_infos + i - 16) + v4 < a1 )
    return printk(&unk_A1EB);
  v5 = a1 - v4;
  result = memory_block_size_bytes(a1);
  if ( (unsigned int)(v5 / result) == 31 )
    return printk(&unk_A1EB);
  v7 = 1 << (v5 / result);
  v8 = *(_DWORD *)(segment_infos + i);
  if ( (v8 & v7) != 0 )
    return printk(&unk_9CCE);
  *(_DWORD *)(segment_infos + i) = v8 | v7;
  return result;
}
