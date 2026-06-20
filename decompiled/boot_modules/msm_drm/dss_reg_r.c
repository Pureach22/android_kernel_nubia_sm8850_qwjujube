__int64 __fastcall dss_reg_r(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x8
  void *v5; // x0

  if ( !a1 || (v3 = *(_QWORD *)(a1 + 8)) == 0 )
  {
    v5 = &unk_22ECB8;
LABEL_8:
    printk(v5, v2);
    return 4294967274LL;
  }
  if ( *(_DWORD *)a1 < a2 )
  {
    v5 = &unk_269701;
    goto LABEL_8;
  }
  return readl_relaxed_7((unsigned int *)(v3 + a2));
}
