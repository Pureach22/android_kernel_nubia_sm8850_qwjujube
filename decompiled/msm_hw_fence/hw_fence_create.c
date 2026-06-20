__int64 __fastcall hw_fence_create(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 *a6)
{
  __int64 v6; // x30
  unsigned int v7; // w24
  __int64 v10; // x25
  __int64 v12; // x4
  __int64 range; // x8
  __int64 result; // x0
  unsigned int v15; // w19

  v7 = *(_DWORD *)a2;
  v10 = v6;
  range = hw_fence_lookup_and_create_range(a1, *(_DWORD *)a2, a3, a4, a5, 0, a6, 0, *(_DWORD *)(a1 + 80), 0);
  result = 0;
  if ( range )
  {
    if ( (*(_BYTE *)(a1 + 736) & 1) != 0 )
      goto LABEL_3;
LABEL_8:
    printk(&unk_2030A, "hw_fence_create", 1705, v10, v12);
    hw_fence_destroy_refcount(a1, *a6, 0x80000000);
    hw_fence_destroy_with_hash(a1, a2, *a6);
    return 4294967285LL;
  }
  printk(&unk_21107, "hw_fence_create", 1696, v10, v7);
  result = 4294967274LL;
  if ( (*(_BYTE *)(a1 + 736) & 1) == 0 )
    goto LABEL_8;
LABEL_3:
  if ( *(_BYTE *)(a2 + 180) == 1 )
  {
    result = hw_fence_destroy_refcount(a1, *a6, 0x80000000);
    if ( (_DWORD)result )
    {
      v15 = result;
      printk(&unk_266A0, "hw_fence_create", 1715, v10, v7);
      return v15;
    }
  }
  return result;
}
