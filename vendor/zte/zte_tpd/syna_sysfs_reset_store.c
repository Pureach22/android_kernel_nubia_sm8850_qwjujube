__int64 __fastcall syna_sysfs_reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _DWORD *v6; // x20
  __int64 v7; // x21
  __int64 v8; // x2
  __int64 v10; // x0
  void (__fastcall *v11)(_QWORD); // x8
  int v12; // w0
  __int64 v13; // x2
  int v14; // w20
  _BYTE v16[4]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v17 = 0;
  v16[0] = 0;
  v6 = *(_DWORD **)(*(_QWORD *)(v5 + 24) + 152LL);
  v7 = *((_QWORD *)v6 + 78);
  if ( !(unsigned int)kstrtouint(a3, 10, &v17) )
  {
    if ( (*((_BYTE *)v6 + 1410) & 1) == 0 )
    {
      printk(unk_35C01, "syna_sysfs_reset_store", v8);
      goto LABEL_18;
    }
    if ( v6[351] == 3 || v17 == 2 )
    {
      v10 = *((_QWORD *)v6 + 78);
      v11 = *(void (__fastcall **)(_QWORD))(v10 + 392);
      if ( !v11 )
      {
        printk(unk_3A417, "syna_sysfs_reset_store", v17);
        v14 = 0;
        goto LABEL_17;
      }
      /* CFI check removed */
      v11(v10);
      if ( (*(_BYTE *)(v7 + 188) & 1) == 0 )
        syna_tcm_get_event_data(*(_QWORD *)v6, v16, 0);
    }
    else
    {
      if ( v17 != 1 )
      {
        printk(unk_337D6, "syna_sysfs_reset_store", v17);
        v14 = -22;
        goto LABEL_17;
      }
      v12 = syna_tcm_reset(*(_QWORD *)v6, *(unsigned int *)(*(_QWORD *)v6 + 524LL), 0LL);
      if ( v12 < 0 )
      {
        v14 = v12;
        printk(unk_39948, "syna_sysfs_reset_store", v13);
        goto LABEL_17;
      }
    }
    v14 = a4;
LABEL_17:
    a4 = v14;
    goto LABEL_18;
  }
  a4 = -22;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return a4;
}
