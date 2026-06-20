__int64 __fastcall rmnet_shs_mmap_global(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  unsigned int v3; // w19

  if ( global_shared && *(_QWORD *)global_shared )
  {
    result = remap_pfn_range(
               a2,
               *a2,
               (__int64)(((__int64)memstart_addr >> 12 << 6)
                       + ((unsigned __int64)(((__int64)(*(_QWORD *)global_shared << 8) >> 8) + 0x8000000000LL) >> 6)) >> 6,
               a2[1] - *a2,
               a2[3]);
    if ( (_DWORD)result )
    {
      v3 = result;
      printk(&unk_1552B);
      return v3;
    }
  }
  else
  {
    printk(&unk_15B6A);
    return 0;
  }
  return result;
}
