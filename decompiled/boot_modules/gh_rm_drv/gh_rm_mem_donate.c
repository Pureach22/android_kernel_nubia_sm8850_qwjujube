__int64 __fastcall gh_rm_mem_donate(
        unsigned __int8 a1,
        unsigned __int8 a2,
        int a3,
        __int64 a4,
        unsigned int *a5,
        unsigned __int16 *a6,
        _DWORD *a7)
{
  void *v8; // x0

  if ( *(_DWORD *)a4 != 1 )
  {
    v8 = &unk_12949;
LABEL_7:
    printk(v8, "gh_rm_mem_donate");
    return 4294967274LL;
  }
  if ( *(_BYTE *)(a4 + 6) != 7 )
  {
    v8 = &unk_121EA;
    goto LABEL_7;
  }
  return gh_rm_mem_share_lend_helper(0x51000010u, a1, a2, a3, (unsigned int *)a4, a5, a6, a7);
}
