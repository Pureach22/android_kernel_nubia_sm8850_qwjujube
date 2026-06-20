__int64 __fastcall sharedmem_mmap(__int64 a1, __int64 *a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x10
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x9
  unsigned __int64 v7; // x8
  __int64 result; // x0
  unsigned int v9; // w19

  v2 = a2[10];
  if ( v2 <= 4 && (v3 = *(_QWORD *)(a1 + 24 + 72 * v2 + 32)) != 0 )
  {
    v5 = *a2;
    v4 = a2[1];
    v6 = a1 + 24 + 72 * v2;
    v7 = v4 - *a2;
    if ( v7 > v3 )
    {
      printk(&unk_6882, "sharedmem_mmap", v4);
      return 4294967274LL;
    }
    else
    {
      a2[3] = a2[3] & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
      result = remap_pfn_range(a2, v5, *(_QWORD *)(v6 + 8) >> 12, v7);
      if ( (_DWORD)result )
      {
        v9 = result;
        printk(&unk_6A51, "sharedmem_mmap", (unsigned int)result);
        return v9;
      }
    }
  }
  else
  {
    printk(&unk_6AB2, "sharedmem_mmap", 4294967274LL);
    return 4294967274LL;
  }
  return result;
}
