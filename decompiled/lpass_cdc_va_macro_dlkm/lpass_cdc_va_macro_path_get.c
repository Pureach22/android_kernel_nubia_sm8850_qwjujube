__int64 __fastcall lpass_cdc_va_macro_path_get(__int64 a1, __int64 a2)
{
  char *v3; // x0
  char *v4; // x19
  char *v5; // x0
  char *v6; // x0
  unsigned int v7; // w20
  char *v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (char *)kstrndup(a1, 10, 3264);
  v9[0] = v3;
  if ( v3 )
  {
    v4 = v3;
    v5 = strsep(v9, " ");
    if ( v5 )
    {
      v6 = strpbrk(v5, "01234567");
      if ( v6 )
      {
        v7 = kstrtouint(v6, 10, a2);
        if ( (v7 & 0x80000000) != 0
          && (unsigned int)__ratelimit(&lpass_cdc_va_macro_path_get__rs_223, "lpass_cdc_va_macro_path_get") )
        {
          printk(&unk_11E2B, "lpass_cdc_va_macro_path_get");
        }
        goto LABEL_13;
      }
      if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_path_get__rs_221, "lpass_cdc_va_macro_path_get") )
        printk(&unk_120F8, "lpass_cdc_va_macro_path_get");
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_path_get__rs, "lpass_cdc_va_macro_path_get") )
    {
      printk(&unk_12036, "lpass_cdc_va_macro_path_get");
    }
    v7 = -22;
LABEL_13:
    kfree(v4);
    goto LABEL_14;
  }
  v7 = -22;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v7;
}
