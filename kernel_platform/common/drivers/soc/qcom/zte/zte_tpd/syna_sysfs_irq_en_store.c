__int64 __fastcall syna_sysfs_irq_en_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x2
  __int64 (*v9)(void); // x8
  int v10; // w0
  __int64 v11; // x2
  int v12; // w20
  void *v13; // x0
  int v14; // w0
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v16 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 152LL);
  v7 = *(_QWORD *)(v6 + 624);
  if ( !(unsigned int)kstrtouint(a3, 10, &v16) )
  {
    if ( v7 == -8 || (v9 = *(__int64 (**)(void))(v7 + 64)) == nullptr )
    {
      a4 = 0;
      goto LABEL_19;
    }
    if ( (*(_BYTE *)(v6 + 1410) & 1) == 0 )
    {
      printk(unk_35C01, "syna_sysfs_irq_en_store", v8);
      goto LABEL_19;
    }
    if ( *(_DWORD *)(v6 + 1404) == 3 )
    {
      printk(unk_382A7, "syna_sysfs_irq_en_store", v8);
    }
    else if ( v16 == 1 )
    {
      /* CFI check removed */
      v14 = v9();
      if ( v14 < 0 )
      {
        v12 = v14;
        v13 = unk_33CD2;
        goto LABEL_24;
      }
    }
    else
    {
      if ( v16 )
      {
        printk(unk_32624, "syna_sysfs_irq_en_store", v16);
        v12 = -22;
        goto LABEL_18;
      }
      /* CFI check removed */
      v10 = v9();
      if ( v10 < 0 )
      {
        v12 = v10;
        v13 = unk_33001;
LABEL_24:
        printk(v13, "syna_sysfs_irq_en_store", v11);
        goto LABEL_18;
      }
    }
    v12 = a4;
LABEL_18:
    a4 = v12;
    goto LABEL_19;
  }
  a4 = -22;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return a4;
}
