__int64 __fastcall syna_mmap(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v2; // x3

  v2 = a2[1] - *a2;
  if ( v2 > 0x32000 )
  {
    printk(&unk_3990A, "syna_mmap", (unsigned int)v2);
    return 4294967274LL;
  }
  else if ( (unsigned int)remap_pfn_range(
                            a2,
                            *a2,
                            (__int64)(((__int64)memstart_addr >> 12 << 6)
                                    + ((unsigned __int64)(((__int64)((a2[10] << 20)
                                                                   + (*(_QWORD *)(*(_QWORD *)(a1 + 32) + 1120LL) << 8)) >> 8)
                                                        + 0x8000000000LL) >> 6)) >> 6) )
  {
    return 4294967285LL;
  }
  else
  {
    return 0;
  }
}
