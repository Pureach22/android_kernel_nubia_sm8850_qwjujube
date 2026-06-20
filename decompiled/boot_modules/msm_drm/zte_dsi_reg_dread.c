__int64 __fastcall zte_dsi_reg_dread(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x8
  __int64 v7; // x8
  int cmd_set; // w21
  int v10; // w2
  char v11; // w11
  _BYTE *v12; // x9
  char v13; // w4
  __int64 v14; // x23
  __int64 v15; // x0
  unsigned __int64 v16; // x9
  _QWORD v17[40]; // [xsp+0h] [xbp-140h] BYREF

  v17[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v17, 0, 0x138u);
  while ( 1 )
  {
    v6 = *(_QWORD *)(a1 + 1424);
    if ( v6 )
    {
      if ( *(_QWORD *)(v6 + 184) && (*(_BYTE *)(a1 + 1973) & 1) != 0 )
        break;
    }
    msleep_interruptible(1000);
  }
  mutex_lock(a1 + 1040);
  v7 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1424) + 184LL) + 2216LL);
  if ( !v7 )
  {
    cmd_set = 0;
    goto LABEL_8;
  }
  v10 = *(unsigned __int8 *)(a2 + 70);
  v17[3] = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1424) + 184LL) + 2216LL);
  v11 = *(_BYTE *)(a2 + 69);
  LODWORD(v17[6]) = v10;
  HIDWORD(v17[1]) = a3 & 1;
  LODWORD(v17[2]) = 1;
  LOBYTE(v17[0]) = 1;
  v12 = *(_BYTE **)(v7 + 16);
  *v12 = v11;
  if ( *(_DWORD *)a2 == 5 )
    v13 = 20;
  else
    v13 = 6;
  *(_BYTE *)(v7 + 1) = v13;
  printk(&unk_25907F, (unsigned __int8)*v12);
  cmd_set = dsi_panel_read_cmd_set(a1, (__int64)v17);
  if ( cmd_set < 1 )
  {
    printk(&unk_2609AB, "zte_dsi_reg_dread");
    cmd_set = -5;
    goto LABEL_8;
  }
  if ( !LODWORD(v17[6]) )
  {
LABEL_8:
    mutex_unlock(a1 + 1040);
    _ReadStatusReg(SP_EL0);
    return cmd_set;
  }
  v14 = 0;
  while ( 1 )
  {
    v15 = printk(&unk_27F8EE, "zte_dsi_reg_dread");
    if ( v14 == 64 )
      break;
    v16 = LODWORD(v17[6]);
    *(_BYTE *)(a2 + 5 + v14) = *((_BYTE *)&v17[7] + v14);
    if ( ++v14 >= v16 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return sysfs_show_read(v15);
}
