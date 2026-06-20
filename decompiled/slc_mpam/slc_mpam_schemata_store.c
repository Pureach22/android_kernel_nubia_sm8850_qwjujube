__int64 __fastcall slc_mpam_schemata_store(__int64 a1, char *a2, __int64 a3)
{
  __int64 v5; // x0
  int v6; // w9
  int v7; // w10
  char *v8; // x0
  const char *v9; // x23
  unsigned int v10; // w0
  int v12; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-28h] BYREF
  char *i; // [xsp+10h] [xbp-20h] BYREF
  int v15; // [xsp+1Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = a2;
  v15 = 0;
  v13 = 0;
  v12 = 0;
  v5 = qcom_msc_lookup(2);
  if ( v5 )
  {
    v7 = *(_DWORD *)(a1 + 136);
    v6 = *(_DWORD *)(a1 + 140);
    LODWORD(v13) = *(_DWORD *)(v5 + 12);
    HIWORD(v13) = v6;
    WORD2(v13) = v7;
  }
  for ( i = strsep(stringp, ","); i; i = strsep(stringp, ",") )
  {
    v8 = strsep(&i, "=");
    if ( v8 )
    {
      v9 = v8;
      if ( i )
      {
        if ( (kstrtouint(i, 0, &v15) & 0x80000000) != 0 )
        {
          printk(&unk_7625, v9);
          a3 = -22;
          goto LABEL_13;
        }
        if ( !strcmp("gear", v9) )
          v12 = v15;
      }
    }
  }
  v10 = msc_system_set_partition(2, &v13, &v12);
  if ( v10 )
  {
    printk(&unk_7452, v10);
    a3 = -16;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return a3;
}
