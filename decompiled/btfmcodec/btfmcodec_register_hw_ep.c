__int64 __fastcall btfmcodec_register_hw_ep(__int64 *a1)
{
  __int64 btfmcodec; // x19
  void *v3; // x0
  _QWORD *v4; // x0
  unsigned int v5; // w20
  __int64 v7; // x9
  _QWORD *v8; // x22
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x9

  btfmcodec = btfm_get_btfmcodec();
  mutex_lock(btfmcodec + 1040);
  if ( !btfmcodec )
  {
    v3 = &unk_C74B;
LABEL_9:
    printk(v3, "btfmcodec_register_hw_ep");
    v5 = -1;
    goto LABEL_10;
  }
  if ( !*((_DWORD *)a1 + 24) )
  {
    v3 = &unk_D6C3;
    goto LABEL_9;
  }
  if ( *(_QWORD *)(btfmcodec + 984) )
  {
    v3 = &unk_CF03;
    goto LABEL_9;
  }
  v4 = (_QWORD *)_kmalloc_cache_noprof(cdev_init, 3520, 112);
  if ( v4 )
  {
    *(_QWORD *)(btfmcodec + 984) = v4;
    v7 = a1[11];
    v8 = v4;
    v4[10] = a1[10];
    v4[11] = v7;
    v9 = a1[13];
    v4[12] = a1[12];
    v4[13] = v9;
    v10 = a1[7];
    v4[6] = a1[6];
    v4[7] = v10;
    v11 = a1[9];
    v4[8] = a1[8];
    v4[9] = v11;
    v12 = a1[3];
    v4[2] = a1[2];
    v4[3] = v12;
    v13 = a1[5];
    v4[4] = a1[4];
    v4[5] = v13;
    v14 = *a1;
    v4[1] = a1[1];
    *v4 = v14;
    printk(&unk_BFC8, "btfmcodec_register_hw_ep");
    printk(&unk_C298, "btfmcodec_register_hw_ep");
    printk(&unk_C7FA, "btfmcodec_register_hw_ep");
    printk(&unk_CBAE, "btfmcodec_register_hw_ep");
    v5 = btfm_register_codec(v8);
  }
  else
  {
    printk(&unk_C9A9, "btfmcodec_register_hw_ep");
    v5 = -12;
  }
LABEL_10:
  mutex_unlock(btfmcodec + 1040);
  return v5;
}
