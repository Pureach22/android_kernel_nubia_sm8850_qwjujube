void __fastcall gsihal_write_reg_nk_fields(unsigned int a1, int a2, int a3, __int64 a4)
{
  unsigned __int64 v4; // x9
  char *v5; // x8
  int v6; // w11
  int v7; // w9
  int v8; // w10
  _DWORD *v9; // x8
  __int64 v10; // x20
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( a4 )
  {
    if ( a1 >= 0x96 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Invalid register reg=%u\n", "gsihal_write_reg_nk_fields", 2257, a1);
      __break(0x800u);
    }
    else
    {
      if ( *(_DWORD *)gsihal_ctx >= 0xEu )
      {
        __break(0x5512u);
        JUMPOUT(0x280E8);
      }
      v4 = 32LL * a1 + 4800LL * *(unsigned int *)gsihal_ctx;
      if ( (v4 | 0x10) > 0x10680 )
        goto LABEL_16;
      v5 = (char *)&gsihal_reg_objs + v4;
      v6 = *(_DWORD *)((char *)&gsihal_reg_objs + v4 + 16);
      if ( v6 == -1 )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d Write access to obsolete reg=%s\n",
          "gsihal_write_reg_nk_fields",
          2267,
          gsireg_name_to_str[a1]);
        __break(0x800u);
        goto LABEL_12;
      }
      if ( (v4 | 0x14) > 0x10680 || (v4 | 0x18) > 0x10680 || v4 > 0x1067F )
LABEL_16:
        __break(1u);
      v7 = *((_DWORD *)v5 + 5);
      v8 = *((_DWORD *)v5 + 6);
      v9 = *(_DWORD **)v5;
      v10 = (unsigned int)(v6 + v7 * a2 + v8 * a3);
      if ( *(v9 - 1) != 249786651 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, __int64, unsigned int *))v9)(a1, a4, &v11);
      __dmb(2u);
      writel_relaxed(v11, (unsigned int *)(*(_QWORD *)(gsihal_ctx + 8) + v10));
    }
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Input error fields=%pK\n", "gsihal_write_reg_nk_fields", 2251, nullptr);
    __break(0x800u);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
}
