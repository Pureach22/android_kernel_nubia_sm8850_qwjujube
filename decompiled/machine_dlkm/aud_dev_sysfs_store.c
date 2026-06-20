__int64 __fastcall aud_dev_sysfs_store(__int64 a1, int a2, char *s, unsigned __int64 a4)
{
  __int64 v4; // x19
  __int64 v6; // x2
  void *v8; // x0
  __int64 v9; // [xsp+0h] [xbp-10h] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( a4 >= 0xB )
  {
    printk(&unk_13CD3, "aud_dev_sysfs_store", s);
    v4 = -22;
    goto LABEL_5;
  }
  v4 = a4;
  sscanf(s, "%d %d", (char *)&v9 + 4, &v9);
  v6 = HIDWORD(v9);
  if ( HIDWORD(v9) >= *(_DWORD *)(a1 + 144) )
  {
    v8 = &unk_1324F;
LABEL_9:
    printk(v8, "aud_dev_sysfs_store", v6);
    v4 = -22;
    goto LABEL_5;
  }
  if ( (unsigned int)v9 >= 2 )
  {
    v8 = &unk_133D8;
    v6 = (unsigned int)v9;
    goto LABEL_9;
  }
  *(_BYTE *)(*(_QWORD *)(a1 - 8) + HIDWORD(v9)) = v9;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v4;
}
