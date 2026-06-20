void __fastcall gsihal_write_reg_nk(unsigned int a1, int a2, int a3, unsigned int a4)
{
  __int64 v4; // x10
  char *v5; // x12
  int v6; // w11
  int v7; // w9
  int v8; // w10

  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_write_reg_nk", 2041, a1);
    __break(0x800u);
    return;
  }
  if ( *(_DWORD *)gsihal_ctx >= 0xEu )
    goto LABEL_12;
  v4 = 32LL * a1 + 4800LL * *(unsigned int *)gsihal_ctx;
  if ( (v4 | 0x10uLL) > 0x10680 )
    goto LABEL_11;
  v5 = (char *)&gsihal_reg_objs + v4;
  v6 = *(_DWORD *)((char *)&gsihal_reg_objs + v4 + 16);
  if ( v6 == -1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Write access to obsolete reg=%s\n",
      "gsihal_write_reg_nk",
      2051,
      gsireg_name_to_str[a1]);
    __break(0x800u);
    return;
  }
  if ( (v4 | 0x18uLL) > 0x10680 || (v4 | 0x14uLL) > 0x10680 )
  {
LABEL_11:
    __break(1u);
LABEL_12:
    __break(0x5512u);
    ((void (*)(void))writel_relaxed)();
    return;
  }
  v8 = *((_DWORD *)v5 + 5);
  v7 = *((_DWORD *)v5 + 6);
  __dmb(2u);
  writel_relaxed(a4, *(_QWORD *)(gsihal_ctx + 8) + (unsigned int)(v6 + v7 * a3 + v8 * a2));
}
