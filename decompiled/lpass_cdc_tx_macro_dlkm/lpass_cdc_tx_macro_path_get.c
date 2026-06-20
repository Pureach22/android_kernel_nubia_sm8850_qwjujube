__int64 __fastcall lpass_cdc_tx_macro_path_get(__int64 a1, __int64 a2)
{
  char *v3; // x0
  char *v4; // x19
  char *v5; // x0
  char *v6; // x0
  unsigned int v7; // w20
  __int64 v8; // x2
  char *v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (char *)kstrndup(a1, 10, 3264);
  v10[0] = v3;
  if ( v3 )
  {
    v4 = v3;
    v5 = strsep(v10, " ");
    if ( v5 )
    {
      v6 = strpbrk(v5, "01234567");
      if ( v6 )
      {
        v7 = kstrtouint(v6, 10, a2);
        if ( (v7 & 0x80000000) != 0
          && (unsigned int)__ratelimit(&lpass_cdc_tx_macro_path_get__rs_257, "lpass_cdc_tx_macro_path_get") )
        {
          printk(&unk_15728, "lpass_cdc_tx_macro_path_get", v4);
        }
        goto LABEL_13;
      }
      if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_path_get__rs_255, "lpass_cdc_tx_macro_path_get") )
        printk(&unk_15415, "lpass_cdc_tx_macro_path_get", v8);
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_path_get__rs, "lpass_cdc_tx_macro_path_get") )
    {
      printk(&unk_15842, "lpass_cdc_tx_macro_path_get", v10[0]);
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
