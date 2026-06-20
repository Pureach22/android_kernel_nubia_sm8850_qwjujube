__int64 __fastcall smem_mailbox_stop(int a1)
{
  _UNKNOWN **v1; // x19
  unsigned __int64 v2; // x0
  __int64 v3; // x8
  unsigned __int64 v4; // x8
  int v5; // w2
  __int64 result; // x0
  unsigned __int64 v7; // x20
  unsigned __int64 v8; // x20
  int v9; // [xsp+8h] [xbp-18h] BYREF
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = &smem_client_channel_list_head;
  v11[0] = 0;
  do
  {
    v1 = (_UNKNOWN **)*v1;
    if ( v1 == &smem_client_channel_list_head )
    {
      v1 = &smem_client_channel_list_head;
      goto LABEL_7;
    }
  }
  while ( *((_DWORD *)v1 + 4) != a1 );
  if ( !v1 )
    goto LABEL_16;
LABEL_7:
  if ( *((_DWORD *)v1 + 4) != a1 )
  {
LABEL_16:
    printk(&unk_74DF);
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( ((_BYTE)v1[4] & 1) != 0 )
  {
    v2 = qcom_smem_get(1, 655, v11);
    if ( v2 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_73B6);
      result = 4294967284LL;
    }
    else
    {
      v3 = *((unsigned int *)v1 + 5);
      v10 = *(_DWORD *)(v2 + v3);
      if ( v10 != *(_DWORD *)(v2 + v3 + 4) )
      {
        v7 = v2;
        printk(&unk_7374);
        _memcpy_toio(v7 + *((unsigned int *)v1 + 5) + 4, &v10, 4);
        v3 = *((unsigned int *)v1 + 5);
        v2 = v7;
      }
      v4 = v2 + v3 + *((unsigned int *)v1 + 6);
      v5 = *(_DWORD *)(v4 + 8);
      v9 = *(_DWORD *)(v4 + 12);
      if ( v5 != v9 )
      {
        v8 = v2;
        printk(&unk_71CE);
        _memcpy_toio(v8 + *((unsigned int *)v1 + 5) + *((unsigned int *)v1 + 6) + 8, &v9, 4);
      }
      result = 1;
      *((_BYTE *)v1 + 32) = 0;
    }
  }
  else
  {
    printk(&unk_70FA);
    result = 0xFFFFFFFFLL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
