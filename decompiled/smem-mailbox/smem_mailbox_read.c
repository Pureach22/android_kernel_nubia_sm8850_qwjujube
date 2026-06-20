__int64 __fastcall smem_mailbox_read(int a1, __int64 *a2, unsigned __int16 *a3, __int64 a4)
{
  _UNKNOWN **v7; // x19
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x22
  int *v10; // x8
  int v11; // w3
  __int64 v12; // x1
  unsigned __int64 v13; // x0
  int v14; // w9
  unsigned int *v15; // x8
  unsigned int v16; // w8
  unsigned int v17; // w10
  bool v18; // cf
  int v19; // w10
  __int64 result; // x0
  int v21; // [xsp+8h] [xbp-18h] BYREF
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = &smem_client_channel_list_head;
  v23[0] = 0;
  do
  {
    v7 = (_UNKNOWN **)*v7;
    if ( v7 == &smem_client_channel_list_head )
    {
      v7 = &smem_client_channel_list_head;
      goto LABEL_7;
    }
  }
  while ( *((_DWORD *)v7 + 4) != a1 );
  if ( !v7 )
    goto LABEL_22;
LABEL_7:
  if ( *((_DWORD *)v7 + 4) != a1 )
  {
LABEL_22:
    printk(&unk_73D6);
    result = 4294967274LL;
    goto LABEL_21;
  }
  if ( ((_BYTE)v7[4] & 1) != 0 )
  {
    v8 = qcom_smem_get(1, 655, v23);
    if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_73B6);
      result = 4294967284LL;
    }
    else
    {
      v9 = v8;
      v10 = (int *)(v8 + *((unsigned int *)v7 + 5));
      v11 = *v10;
      v22 = v10[1];
      if ( v11 == v22 )
      {
        printk(&unk_72A5);
        result = 4294967254LL;
      }
      else
      {
        do
        {
          v21 = 0;
          if ( (read_item((__int64)v7, (__int64)&v21, 4u) & 1) == 0 )
            break;
          if ( (_WORD)v21 )
          {
            if ( (unsigned __int16)v21 != 1 )
            {
              printk(&unk_7125);
              result = 4294967254LL;
              goto LABEL_21;
            }
            *a3 = HIWORD(v21) - 4;
            v12 = _kmalloc_noprof(*a3, 3264);
            *a2 = v12;
            if ( (read_item((__int64)v7, v12, *a3) & 1) != 0 )
            {
              v13 = v9 + *((unsigned int *)v7 + 5);
              v22 = *(_DWORD *)(v13 + 4) - (*a3 & 3) + 4;
              _memcpy_toio(v13 + 4, &v22, 4);
            }
            break;
          }
        }
        while ( (read_item((__int64)v7, a4, 8u) & 1) != 0 );
        v14 = *((_DWORD *)v7 + 6);
        v15 = (unsigned int *)(v9 + *((unsigned int *)v7 + 5));
        v17 = *v15;
        v16 = v15[1];
        v18 = v17 >= v16;
        v19 = v17 + v14;
        if ( !v18 )
          v14 = 0;
        result = v19 - v16 - v14;
      }
    }
  }
  else
  {
    printk(&unk_70FA);
    result = 0xFFFFFFFFLL;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
