__int64 __fastcall gsihal_read_reg_nk_fields(unsigned int a1, int a2, int a3, __int64 a4)
{
  __int64 v5; // x9
  int v6; // w11
  unsigned int v8; // w0
  unsigned int v9; // w8
  unsigned int v10; // w21
  _DWORD *v11; // x8

  if ( !a4 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Input error fields\n", "gsihal_read_reg_nk_fields", 2213);
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_read_reg_nk_fields", 2219, a1);
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( *(_DWORD *)gsihal_ctx >= 0xEu )
    goto LABEL_18;
  v5 = 32LL * a1 + 4800LL * *(unsigned int *)gsihal_ctx;
  if ( (v5 | 0x10uLL) > 0x10680 )
    goto LABEL_17;
  v6 = *(_DWORD *)((char *)&gsihal_reg_objs + v5 + 16);
  if ( v6 == -1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Read access to obsolete reg=%s\n",
      "gsihal_read_reg_nk_fields",
      2229,
      gsireg_name_to_str[a1]);
    __break(0x800u);
    return (unsigned int)-1;
  }
  if ( (v5 | 0x14uLL) > 0x10680 || (v5 | 0x18uLL) > 0x10680 )
    goto LABEL_17;
  v8 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(gsihal_ctx + 8)
                                      + (unsigned int)(v6
                                                     + *(_DWORD *)((char *)&gsihal_reg_objs + v5 + 20) * a2
                                                     + *(_DWORD *)((char *)&gsihal_reg_objs + v5 + 24) * a3)));
  v9 = *(_DWORD *)gsihal_ctx;
  if ( *(_DWORD *)gsihal_ctx > 0xDu )
  {
LABEL_18:
    __break(0x5512u);
    JUMPOUT(0x427E2C4);
  }
  if ( ((32LL * a1 + 4800LL * v9) | 8uLL) > 0x10680 )
  {
LABEL_17:
    __break(1u);
    goto LABEL_18;
  }
  v10 = v8;
  v11 = *((_DWORD **)&gsihal_reg_objs + 600 * v9 + 4 * a1 + 1);
  if ( *(v11 - 1) != -320198565 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, _QWORD))v11)(a1, a4, v8);
  return v10;
}
