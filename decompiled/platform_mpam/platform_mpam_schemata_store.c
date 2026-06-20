__int64 __fastcall platform_mpam_schemata_store(__int64 a1, char *a2, __int64 a3)
{
  int v5; // w8
  int v6; // w9
  char *v7; // x0
  const char *v8; // x28
  int v9; // w8
  unsigned int v10; // w0
  _DWORD v12[2]; // [xsp+Ch] [xbp-34h] BYREF
  int v13; // [xsp+14h] [xbp-2Ch]
  __int64 v14; // [xsp+18h] [xbp-28h]
  char *i; // [xsp+20h] [xbp-20h] BYREF
  int v16; // [xsp+2Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+30h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 136);
  v6 = *(_DWORD *)(a1 + 140);
  stringp[0] = a2;
  v16 = 0;
  v12[1] = v6;
  v13 = 0;
  v12[0] = v5;
  v14 = 0;
  for ( i = strsep(stringp, ","); i; i = strsep(stringp, ",") )
  {
    v7 = strsep(&i, "=");
    if ( !v7 )
      continue;
    v8 = v7;
    if ( !i )
      continue;
    if ( (kstrtoint(i, 0, &v16) & 0x80000000) != 0 )
    {
      printk(&unk_6EBD, v8);
    }
    else
    {
      if ( !strcmp("gear", v8) )
      {
        v13 = v16;
        v10 = qcom_mpam_set_platform_bw_ctrl(v12);
        if ( v10 )
          printk(&unk_6F90, v10);
        else
          **(_DWORD **)(a1 + 152) = v13;
        continue;
      }
      if ( strcmp("limit_ratio", v8) )
      {
        if ( strcmp("limit_mbps", v8) )
          continue;
        v9 = *(_DWORD *)(*(_QWORD *)(a1 + 160) + 8LL);
        if ( !v9 || !((v9 / 100 + v16 - 1) / (v9 / 100)) )
          continue;
LABEL_17:
        qcom_mpam_set_bw_limit_rpmsg();
        continue;
      }
      if ( v16 )
        goto LABEL_17;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
