__int64 __fastcall smem_mailbox_write(int a1, char a2, const void *a3, unsigned __int16 a4)
{
  char v7; // w19
  _UNKNOWN **v8; // x27
  unsigned __int64 v9; // x25
  unsigned __int64 v10; // x0
  int v11; // w28
  unsigned __int64 v12; // x21
  __int64 v13; // x24
  unsigned __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w8
  unsigned int v17; // w2
  void *v18; // x0
  __int64 v19; // x26
  unsigned __int64 StatusReg; // x9
  int v21; // w11
  int v22; // w25
  __int64 v23; // x22
  __int64 v24; // x23
  unsigned int v25; // w8
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 v28; // x0
  __int64 v29; // x9
  __int64 v30; // x8
  unsigned int v31; // w10
  bool v32; // cf
  int v33; // w8
  __int64 result; // x0
  void *v35; // x0
  unsigned __int64 v36; // [xsp+8h] [xbp-28h]
  __int64 v37; // [xsp+10h] [xbp-20h]
  unsigned int v38; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+20h] [xbp-10h] BYREF

  v7 = a1;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = &smem_client_channel_list_head;
  v39[0] = 0;
  do
  {
    v8 = (_UNKNOWN **)*v8;
    if ( v8 == &smem_client_channel_list_head )
    {
      v8 = &smem_client_channel_list_head;
      goto LABEL_7;
    }
  }
  while ( *((_DWORD *)v8 + 4) != a1 );
  if ( !v8 )
    goto LABEL_28;
LABEL_7:
  if ( *((_DWORD *)v8 + 4) != a1 )
  {
LABEL_28:
    printk(&unk_73D6);
    result = 4294967274LL;
    goto LABEL_27;
  }
  if ( ((_BYTE)v8[4] & 1) == 0 )
  {
    printk(&unk_70FA);
    result = 0xFFFFFFFFLL;
    goto LABEL_27;
  }
  v9 = a4;
  if ( (unsigned __int64)*((unsigned int *)v8 + 7) - 4 < a4 )
  {
    printk(&unk_721C);
    result = 4294967268LL;
    goto LABEL_27;
  }
  v10 = qcom_smem_get(1, 655, v39);
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    v35 = &unk_73B6;
LABEL_37:
    printk(v35);
    result = 4294967284LL;
    goto LABEL_27;
  }
  v11 = a4;
  v12 = v10;
  v13 = (unsigned int)a4 + 16;
  v14 = v10 + *((unsigned int *)v8 + 5) + *((unsigned int *)v8 + 6);
  v15 = *(_DWORD *)(v14 + 8);
  v38 = v15;
  v16 = *(_DWORD *)(v14 + 12);
  v17 = v16 - v15;
  if ( v16 >= v15 )
  {
    if ( v16 != v15 && v17 < (unsigned int)a4 + 12 )
    {
      v18 = &unk_7549;
      goto LABEL_34;
    }
  }
  else if ( v17 + *((_DWORD *)v8 + 7) < (unsigned int)a4 + 12 )
  {
    v18 = &unk_7409;
LABEL_34:
    printk(v18);
    result = 4294967268LL;
    goto LABEL_27;
  }
  v19 = _kmalloc_noprof((unsigned int)a4 + 16, 3264);
  if ( !v19 )
  {
LABEL_36:
    v35 = &unk_7450;
    goto LABEL_37;
  }
  while ( 1 )
  {
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    *(_DWORD *)v19 = 786432;
    *(_QWORD *)(v19 + 4) = StatusReg;
    *(_WORD *)(v19 + 12) = 1;
    *(_WORD *)(v19 + 14) = a4 + 4;
    if ( v13 - 16 >= v9 )
      break;
    _fortify_panic(17, v13 - 16, a4);
    v36 = _ReadStatusReg(SP_EL0);
    v37 = *(_QWORD *)(v36 + 80);
    *(_QWORD *)(v36 + 80) = &smem_mailbox_write__alloc_tag;
    v19 = _kmalloc_noprof((unsigned int)a4 + 16, 3264);
    *(_QWORD *)(v36 + 80) = v37;
    if ( !v19 )
      goto LABEL_36;
  }
  memcpy((void *)(v19 + 16), a3, a4);
  v21 = *((_DWORD *)v8 + 7);
  v22 = -a4 & 3;
  v23 = v38 + (unsigned int)v13 - v21;
  v24 = v12 + *((unsigned int *)v8 + 5) + *((unsigned int *)v8 + 6) + 16;
  if ( (int)(v38 + v13 - v21) < 0 )
  {
    _memcpy_toio(v24 + v38, v19, (unsigned int)(v11 + 16));
    v25 = v22 + v13 + v38;
  }
  else
  {
    _memcpy_toio(v24 + v38, v19, (int)(v21 - v38));
    _memcpy_toio(v24, v19 + (unsigned int)v13 - v23, v23);
    v25 = v23 + v22;
  }
  v26 = *((unsigned int *)v8 + 5);
  v27 = *((unsigned int *)v8 + 6);
  v38 = v25;
  _memcpy_toio(v12 + v26 + v27 + 8, &v38, 4);
  if ( (a2 & 1) != 0 )
  {
    v28 = *(_QWORD *)mailbox;
    if ( *(_QWORD *)mailbox )
    {
      *(_DWORD *)(mailbox + 8) ^= 1 << v7;
      qcom_smem_state_update_bits(v28, 255);
    }
    else
    {
      printk(&unk_7269);
    }
  }
  v29 = *((unsigned int *)v8 + 6);
  v30 = v12 + *((unsigned int *)v8 + 5) + v29;
  v31 = *(_DWORD *)(v30 + 8);
  LODWORD(v30) = *(_DWORD *)(v30 + 12);
  v32 = (unsigned int)v30 >= v31;
  v33 = v30 - v31;
  if ( v33 != 0 && v32 )
    LODWORD(v29) = 0;
  result = (unsigned int)(v33 + v29);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
