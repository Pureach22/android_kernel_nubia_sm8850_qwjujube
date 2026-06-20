void __fastcall ipareg_construct_coal_evict_lru(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = (2 * (*(_DWORD *)a2 & 0x1F)) | *a3;
  *a3 = v3;
  *a3 = v3 | *(unsigned __int8 *)(a2 + 4);
}
