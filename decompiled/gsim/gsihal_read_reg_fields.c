__int64 __fastcall gsihal_read_reg_fields(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w9
  __int64 v4; // x9
  unsigned int v6; // w0
  unsigned int v7; // w8
  unsigned int v8; // w21
  _DWORD *v9; // x8

  if ( !a2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Input error fields\n", "gsihal_read_reg_fields", 2105);
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_read_reg_fields", 2111, a1);
    __break(0x800u);
    return (unsigned int)-22;
  }
  v3 = *(_DWORD *)gsihal_ctx;
  if ( *(_DWORD *)gsihal_ctx >= 0xEu )
    goto LABEL_15;
  if ( ((32LL * a1 + 4800LL * v3) | 0x10uLL) > 0x10680 )
  {
LABEL_16:
    __break(1u);
    JUMPOUT(0x1A15FFC);
  }
  v4 = *((unsigned int *)&gsihal_reg_objs + 1200 * v3 + 8 * a1 + 4);
  if ( (_DWORD)v4 == -1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Read access to obsolete reg=%s\n",
      "gsihal_read_reg_fields",
      2121,
      gsireg_name_to_str[a1]);
    __break(0x800u);
    return (unsigned int)-1;
  }
  v6 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(gsihal_ctx + 8) + v4));
  v7 = *(_DWORD *)gsihal_ctx;
  if ( *(_DWORD *)gsihal_ctx > 0xDu )
  {
LABEL_15:
    __break(0x5512u);
    goto LABEL_16;
  }
  if ( ((32LL * a1 + 4800LL * v7) | 8uLL) > 0x10680 )
    goto LABEL_16;
  v8 = v6;
  v9 = *((_DWORD **)&gsihal_reg_objs + 600 * v7 + 4 * a1 + 1);
  if ( *(v9 - 1) != -320198565 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, _QWORD))v9)(a1, a2, v6);
  return v8;
}
