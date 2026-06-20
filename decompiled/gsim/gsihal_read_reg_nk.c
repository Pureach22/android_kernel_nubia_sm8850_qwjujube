__int64 __fastcall gsihal_read_reg_nk(unsigned int a1, int a2, int a3)
{
  __int64 v3; // x10
  int v4; // w12

  if ( !gsihal_ctx )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d gsihal_ctx mpt initialized", "gsihal_read_reg_nk", 2008);
    return 0xFFFFFFFFLL;
  }
  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_read_reg_nk", 2013, a1);
    __break(0x800u);
    return 4294967274LL;
  }
  if ( *(_DWORD *)gsihal_ctx >= 0xEu )
    goto LABEL_14;
  v3 = 32LL * a1 + 4800LL * *(unsigned int *)gsihal_ctx;
  if ( (v3 | 0x10uLL) > 0x10680 )
    goto LABEL_13;
  v4 = *(_DWORD *)((char *)&gsihal_reg_objs + v3 + 16);
  if ( v4 == -1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Read access to obsolete reg=%s\n",
      "gsihal_read_reg_nk",
      2023,
      gsireg_name_to_str[a1]);
    __break(0x800u);
    return 0xFFFFFFFFLL;
  }
  if ( (v3 | 0x18uLL) > 0x10680 || (v3 | 0x14uLL) > 0x10680 )
  {
LABEL_13:
    __break(1u);
LABEL_14:
    __break(0x5512u);
    return ((__int64 (*)(void))readl_relaxed_0)();
  }
  return readl_relaxed_0(
           *(_QWORD *)(gsihal_ctx + 8)
         + (unsigned int)(v4
                        + *(_DWORD *)((char *)&gsihal_reg_objs + v3 + 24) * a3
                        + *(_DWORD *)((char *)&gsihal_reg_objs + v3 + 20) * a2));
}
