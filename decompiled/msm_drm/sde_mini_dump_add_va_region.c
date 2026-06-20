__int64 __fastcall sde_mini_dump_add_va_region(const char *a1, int a2, __int64 a3)
{
  size_t v6; // x0
  unsigned __int64 v7; // x2
  __int64 result; // x0
  __int64 v9; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v10[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+28h] [xbp-18h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  memset(v10, 0, sizeof(v10));
  v9 = 0;
  v6 = strnlen(a1, 0x20u);
  if ( v6 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_10;
  }
  if ( v6 == 32 )
    v7 = 32;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x21 )
LABEL_10:
    _fortify_panic(7, 32, v7);
  sized_strscpy(v10, a1);
  v9 = a3;
  LODWORD(v11) = a2;
  result = qcom_va_md_add_region(&v9);
  if ( (result & 0x80000000) != 0 )
    result = printk(&unk_25B661, "sde_mini_dump_add_va_region");
  _ReadStatusReg(SP_EL0);
  return result;
}
