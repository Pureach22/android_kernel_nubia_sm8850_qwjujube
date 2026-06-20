__int64 __fastcall kgsl_memdesc_sg_dma(__int64 a1, unsigned __int64 a2, int a3)
{
  __int64 v5; // x22
  __int64 v7; // x0
  __int64 result; // x0
  unsigned int v9; // w19
  unsigned __int64 *v10; // x8
  unsigned __int64 v11; // x10

  v5 = memstart_addr;
  v7 = _kmalloc_cache_noprof(raw_read_lock, 3264, 16);
  *(_QWORD *)(a1 + 56) = v7;
  if ( !v7 )
    return 4294967284LL;
  result = sg_alloc_table(v7, 1, 3264);
  if ( (_DWORD)result )
  {
    v9 = result;
    kfree(*(_QWORD *)(a1 + 56));
    *(_QWORD *)(a1 + 56) = 0;
    return v9;
  }
  else
  {
    v10 = **(unsigned __int64 ***)(a1 + 56);
    v11 = *v10;
    *((_DWORD *)v10 + 2) = 0;
    *((_DWORD *)v10 + 3) = a3;
    *v10 = v11 & 3 | (((a2 >> 6) & 0x3FFFFFFFFFFFFC0LL) - (v5 >> 12 << 6) - 0x140000000LL);
  }
  return result;
}
