__int64 __fastcall qmi_handle_init(unsigned __int64 *a1, __int64 a2, unsigned __int64 *a3, unsigned __int64 a4)
{
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x11
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  int v18; // w20
  unsigned int v19; // w20
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _mutex_init(a1 + 31, "&qmi->txn_lock", &qmi_handle_init___key);
  _mutex_init(a1 + 1, "&qmi->sock_lock", &qmi_handle_init___key_6);
  a1[30] = 0;
  a1[28] = 0x1000000400000000LL;
  a1[29] = 0;
  a1[16] = (unsigned __int64)(a1 + 16);
  a1[17] = (unsigned __int64)(a1 + 16);
  a1[18] = (unsigned __int64)(a1 + 18);
  a1[19] = (unsigned __int64)(a1 + 18);
  a1[20] = (unsigned __int64)(a1 + 20);
  a1[21] = (unsigned __int64)(a1 + 20);
  a1[9] = 0xFFFFFFFE00000LL;
  a1[10] = (unsigned __int64)(a1 + 10);
  a1[11] = (unsigned __int64)(a1 + 10);
  a1[12] = (unsigned __int64)qmi_data_ready_work;
  a1[37] = a4;
  if ( a3 )
  {
    v8 = a3[1];
    a1[22] = *a3;
    a1[23] = v8;
    v9 = a3[5];
    v10 = a3[2];
    v11 = a3[3];
    a1[26] = a3[4];
    a1[27] = v9;
    a1[24] = v10;
    a1[25] = v11;
  }
  if ( (unsigned __int64)(a2 + 7) <= 0x14 )
    v12 = 20;
  else
    v12 = a2 + 7;
  a1[15] = v12;
  v13 = _kmalloc_noprof(v12, 3520);
  a1[14] = v13;
  if ( !v13 )
  {
    v19 = -12;
    goto LABEL_22;
  }
  v14 = alloc_workqueue("qmi_msg_handler", 131074, 1);
  a1[13] = v14;
  if ( v14 )
  {
    v21[0] = 0;
    LODWORD(v15) = sock_create_kern(&init_net, 42, 2, 42, v21);
    if ( (v15 & 0x80000000) != 0 )
    {
      v15 = (int)v15;
    }
    else
    {
      v18 = kernel_getsockname(v21[0], a1 + 7);
      v15 = v21[0];
      if ( v18 < 0 )
      {
        sock_release(v21[0]);
        v15 = v18;
      }
      else
      {
        (*(_QWORD **)((char *)&_ksymtab_qmi_decode_message + v21[0]))[81] = a1;
        (*(_QWORD **)((char *)&_ksymtab_qmi_decode_message + v15))[33] = qmi_data_ready;
        (*(_QWORD **)((char *)&_ksymtab_qmi_decode_message + v15))[87] = qmi_data_ready;
      }
    }
    *a1 = v15;
    if ( v15 < 0xFFFFFFFFFFFFF001LL )
    {
      v19 = 0;
      goto LABEL_22;
    }
    if ( v15 == -97 )
    {
      v19 = -517;
    }
    else
    {
      printk(&unk_820A, v16, v17);
      v19 = *(_DWORD *)a1;
    }
    destroy_workqueue(a1[13]);
  }
  else
  {
    v19 = -12;
  }
  kfree(a1[14]);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v19;
}
