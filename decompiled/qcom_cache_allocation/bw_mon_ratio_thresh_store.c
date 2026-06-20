__int64 __fastcall bw_mon_ratio_thresh_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  char *v6; // x0
  char *v7; // x20
  char *v8; // x0
  unsigned int v9; // w0
  char *v10; // x0
  char *v11; // x0
  char *v12; // x0
  char *v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v15 = 0;
  v16[0] = 0;
  v6 = (char *)kstrdup(a3, 3264);
  if ( !v6 )
  {
    a4 = -12;
    goto LABEL_14;
  }
  v7 = v6;
  v14 = v6;
  v8 = strsep(&v14, " ");
  if ( !v8 )
    goto LABEL_11;
  v9 = kstrtoint(v8, 10, &v15);
  if ( (v9 & 0x80000000) != 0 )
    goto LABEL_15;
  v10 = strsep(&v14, " ");
  if ( v10 )
  {
    v9 = kstrtoint(v10, 10, (char *)&v15 + 4);
    if ( (v9 & 0x80000000) != 0 )
      goto LABEL_15;
    v11 = strsep(&v14, " ");
    if ( v11 )
    {
      v9 = kstrtoint(v11, 10, v16);
      if ( (v9 & 0x80000000) != 0 )
        goto LABEL_15;
      v12 = strsep(&v14, " ");
      if ( v12 )
      {
        v9 = kstrtoint(v12, 10, (char *)v16 + 4);
        if ( (v9 & 0x80000000) == 0 )
        {
          strsep(&v14, " ");
          goto LABEL_11;
        }
LABEL_15:
        printk(&unk_AD46, "bw_mon_ratio_thresh_store", v9);
        goto LABEL_12;
      }
    }
  }
LABEL_11:
  mutex_lock(v5 + 192);
  *(_QWORD *)(*(_QWORD *)(v5 + 16) + 24LL) = (int)v15;
  *(_QWORD *)(*(_QWORD *)(v5 + 16) + 32LL) = SHIDWORD(v15);
  *(_QWORD *)(*(_QWORD *)(v5 + 16) + 64LL) = SLODWORD(v16[0]);
  *(_QWORD *)(*(_QWORD *)(v5 + 16) + 72LL) = SHIDWORD(v16[0]);
  mutex_unlock(v5 + 192);
LABEL_12:
  kfree(v7);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return a4;
}
