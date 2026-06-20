__int64 __fastcall wcd9378_tx_path_get(__int64 a1, __int64 a2)
{
  char *v3; // x0
  char *v4; // x19
  char *v5; // x0
  char *v6; // x0
  unsigned int v7; // w20
  char *v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (char *)kstrndup(a1, 9, 3264);
  v9[0] = v3;
  if ( v3 )
  {
    v4 = v3;
    v5 = strsep(v9, " ");
    if ( v5 )
    {
      v6 = strpbrk(v5, "0123");
      if ( v6 )
      {
        v7 = kstrtouint(v6, 10, a2);
        if ( (v7 & 0x80000000) != 0 )
          printk(&unk_13B34, "wcd9378_tx_path_get");
      }
      else
      {
        printk(&unk_13232, "wcd9378_tx_path_get");
        v7 = -22;
      }
    }
    else
    {
      printk(&unk_13E09, "wcd9378_tx_path_get");
      v7 = -22;
    }
    kfree(v4);
  }
  else
  {
    v7 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
