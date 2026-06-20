void __fastcall gsihal_write_reg_fields(unsigned int a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  void (__fastcall **v3)(_QWORD); // x10
  __int64 v4; // x20
  void (__fastcall *v5)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Input error fields=%pK\n", "gsihal_write_reg_fields", 2071, nullptr);
    __break(0x800u);
    goto LABEL_10;
  }
  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_write_reg_fields", 2077, a1);
    __break(0x800u);
    goto LABEL_10;
  }
  if ( *(_DWORD *)gsihal_ctx < 0xEu )
  {
    v2 = 32LL * a1 + 4800LL * *(unsigned int *)gsihal_ctx;
    if ( (v2 | 0x10) > 0x10680 )
      goto LABEL_14;
    v3 = (void (__fastcall **)(_QWORD))((char *)&gsihal_reg_objs + v2);
    v4 = *(unsigned int *)((char *)&gsihal_reg_objs + v2 + 16);
    if ( (_DWORD)v4 != -1 )
    {
      if ( v2 <= 0x1067F )
      {
        v5 = *v3;
        if ( *((_DWORD *)*v3 - 1) != 249786651 )
          __break(0x8228u);
        v5(a1);
        __dmb(2u);
        writel_relaxed(0, (unsigned int *)(*(_QWORD *)(gsihal_ctx + 8) + v4));
        goto LABEL_10;
      }
LABEL_14:
      __break(1u);
    }
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Write access to obsolete reg=%s\n",
      "gsihal_write_reg_fields",
      2087,
      gsireg_name_to_str[a1]);
    __break(0x800u);
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return;
  }
  __break(0x5512u);
  gsihal_read_reg_fields();
}
