__int64 __fastcall btfm_swr_disable_port(char a1, char a2, char a3)
{
  char v3; // w8
  unsigned int v4; // w19
  _BYTE v6[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v7[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 2 )
    v3 = 3;
  else
    v3 = 1;
  v7[0] = v3;
  v6[0] = a3;
  v8[0] = a1 - 1;
  printk(&unk_7074, "btfm_swr_disable_port");
  if ( (swr_disconnect_port(*(_QWORD *)(pbtfmswr + 8), v8, 1, v7, v6) & 0x80000000) != 0 )
    printk(&unk_7123, "btfm_swr_disable_port");
  printk(&unk_76CE, "btfm_swr_disable_port");
  v4 = swr_slvdev_datapath_control(*(_QWORD *)(pbtfmswr + 8), *(unsigned __int8 *)(*(_QWORD *)(pbtfmswr + 8) + 64LL), 0);
  if ( (v4 & 0x80000000) != 0 )
    printk(&unk_7011, "btfm_swr_disable_port");
  if ( btfm_num_ports_open >= 1 )
    --btfm_num_ports_open;
  printk(&unk_7055, "btfm_swr_disable_port");
  _ReadStatusReg(SP_EL0);
  return v4;
}
