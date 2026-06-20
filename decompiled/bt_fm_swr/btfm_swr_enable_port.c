__int64 __fastcall btfm_swr_enable_port(char a1, char a2, int a3, char a4)
{
  char v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w19
  void *v7; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-1Ch] BYREF
  int v10; // [xsp+8h] [xbp-18h] BYREF
  char v11[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v12[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = a1 - 1;
  if ( a2 == 2 )
    v4 = 3;
  else
    v4 = 1;
  v12[0] = a2;
  v11[0] = v4;
  v10 = a3;
  v9[0] = a4;
  printk(&unk_75CB, "btfm_swr_enable_port");
  v5 = swr_connect_port(*(_QWORD *)(pbtfmswr + 8), v13, 1, v11, &v10, v12, v9);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    v7 = &unk_7845;
  }
  else
  {
    printk(&unk_76CE, "btfm_swr_enable_port");
    v6 = swr_slvdev_datapath_control(
           *(_QWORD *)(pbtfmswr + 8),
           *(unsigned __int8 *)(*(_QWORD *)(pbtfmswr + 8) + 64LL),
           1);
    if ( (v6 & 0x80000000) != 0 )
    {
      printk(&unk_7011, "btfm_swr_enable_port");
    }
    else if ( !v6 )
    {
      ++btfm_num_ports_open;
    }
    v7 = &unk_7055;
  }
  printk(v7, "btfm_swr_enable_port");
  _ReadStatusReg(SP_EL0);
  return v6;
}
