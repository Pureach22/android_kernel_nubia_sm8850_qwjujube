__int64 __fastcall ulog_cat_set(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v6; // w8
  unsigned int v7; // w0
  __int64 v8; // x2
  unsigned int v9; // w20
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 8432) == 1 )
  {
    printk(&unk_6CB3, "ulog_cat_set", a3);
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( *(_QWORD *)(a1 + 8416) != a2 )
  {
    v12 = a2;
    v13 = 0;
    v10 = 0x10000800ALL;
    v11 = 0;
    v6 = *(_DWORD *)(a1 + 8424);
    LODWORD(v11) = 25;
    LODWORD(v13) = v6;
    mutex_lock(a1 + 40);
    *(_DWORD *)(a1 + 88) = 0;
    v7 = pmic_glink_write(*(_QWORD *)(a1 + 8), &v10, 32);
    if ( v7 )
    {
      v9 = v7;
    }
    else
    {
      if ( (unsigned int)wait_for_completion_timeout(a1 + 88, 250) )
      {
        mutex_unlock(a1 + 40);
        result = 0;
        *(_QWORD *)(a1 + 8416) = a2;
        goto LABEL_7;
      }
      printk(&unk_6EE0, "chg_ulog_write", v8);
      v9 = -110;
    }
    mutex_unlock(a1 + 40);
    printk(&unk_6F6A, "ulog_cat_set", v9);
    result = v9;
    goto LABEL_7;
  }
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
