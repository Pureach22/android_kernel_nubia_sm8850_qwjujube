__int64 __fastcall smem_read_ready(__int64 a1, __int64 a2)
{
  int v2; // w1
  _UNKNOWN **v3; // x19
  unsigned __int64 v4; // x0
  int v5; // w9
  void (__fastcall *v6)(_QWORD); // x11
  unsigned int *v7; // x8
  unsigned int v8; // w8
  unsigned int v9; // w10
  bool v10; // cf
  int v11; // w10
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 16);
  v3 = &smem_client_channel_list_head;
  v13[0] = 0;
  do
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &smem_client_channel_list_head )
    {
      v3 = &smem_client_channel_list_head;
      goto LABEL_7;
    }
  }
  while ( *((_DWORD *)v3 + 4) != v2 );
  if ( !v3 )
    goto LABEL_16;
LABEL_7:
  if ( *((_DWORD *)v3 + 4) != v2 )
  {
LABEL_16:
    printk(&unk_74DF);
    goto LABEL_15;
  }
  if ( ((_BYTE)v3[4] & 1) != 0 )
  {
    v4 = qcom_smem_get(1, 655, v13);
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_73B6);
    }
    else
    {
      v5 = *((_DWORD *)v3 + 6);
      v6 = (void (__fastcall *)(_QWORD))v3[8];
      v7 = (unsigned int *)(v4 + *((unsigned int *)v3 + 5));
      v9 = *v7;
      v8 = v7[1];
      v10 = v9 >= v8;
      v11 = v9 + v5;
      if ( !v10 )
        v5 = 0;
      if ( *((_DWORD *)v6 - 1) != 1311034697 )
        __break(0x822Bu);
      v6(v11 - v8 - v5);
    }
  }
  else
  {
    printk(&unk_7591);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return 1;
}
