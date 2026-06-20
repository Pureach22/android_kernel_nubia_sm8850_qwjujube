__int64 __fastcall get_debugfs_input_client_with_min(__int64 a1, int a2, size_t a3, _QWORD *a4, signed int a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  __int64 v9; // x20
  unsigned int v11; // w4
  unsigned int v13; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int16 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  v13 = 0;
  if ( !a1 || (v6 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_2A0F5, "_get_debugfs_input_client_with_min", 122, v5, a1);
LABEL_9:
    v11 = -22;
    goto LABEL_7;
  }
  *a4 = v6;
  if ( a3 <= 9 )
  {
    v9 = v5;
    _check_object_size(&v14, a3, 0);
    if ( !inline_copy_from_user((int)&v14, a2, a3) )
    {
      *((_BYTE *)&v14 + a3) = 0;
      if ( !(unsigned int)kstrtouint(&v14, 0, &v13) )
      {
        v11 = v13;
        if ( (int)v13 >= a5 )
          goto LABEL_7;
        printk(&unk_2A141, "_get_debugfs_input_client_with_min", 139, v9, v13);
        goto LABEL_9;
      }
    }
  }
  v11 = -14;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v11;
}
