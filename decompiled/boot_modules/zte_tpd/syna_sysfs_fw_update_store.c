__int64 __fastcall syna_sysfs_fw_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x2
  void (__fastcall *v9)(_QWORD); // x8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v11 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 152LL);
  if ( (*(_BYTE *)(v6 + 1410) & 1) != 0 )
  {
    if ( (unsigned int)kstrtouint(a3, 10, &v11) )
    {
      a4 = -22;
    }
    else
    {
      v7 = syna_dev_do_reflash((__int64 *)v6, 1);
      if ( v7 < 0 )
      {
        LODWORD(a4) = v7;
        printk(&unk_3240E, "syna_sysfs_fw_update_store", v8);
      }
      else if ( *(_BYTE *)(*(_QWORD *)v6 + 9LL) == 1 )
      {
        v9 = *(void (__fastcall **)(_QWORD))(v6 + 1720);
        if ( *((_DWORD *)v9 - 1) != -1373616356 )
          __break(0x8228u);
        v9(v6);
      }
      a4 = (int)a4;
    }
  }
  else
  {
    printk(&unk_35C01, "syna_sysfs_fw_update_store", a3);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
