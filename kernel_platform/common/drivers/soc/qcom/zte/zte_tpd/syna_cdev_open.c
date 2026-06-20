__int64 syna_cdev_open(void)
{
  unsigned int *v0; // x20
  __int64 v1; // x2
  int v2; // w8
  unsigned int *v3; // x19
  unsigned int **v4; // x21
  __int64 v5 = 0; // x2
  __int64 v9; // x0
  unsigned int v10; // w8

  v0 = *(unsigned int **)(g_cdev_data + 168);
  mutex_lock(&qword_316A0);
  v1 = v0[225];
  if ( (_DWORD)v1 )
  {
    printk(unk_366C2, "syna_cdev_open", v1);
    v2 = v0[225] + 1;
  }
  else
  {
    v2 = 1;
  }
  v0[225] = v2;
  qword_31700 = 0;
  LODWORD(qword_31708) = 0;
  LODWORD(qword_31710) = *(_DWORD *)(*(_QWORD *)v0 + 60LL);
  HIDWORD(qword_31708) = *(_DWORD *)(*(_QWORD *)v0 + 56LL);
  *(_BYTE *)(*(_QWORD *)v0 + 890LL) = 0;
  *((_BYTE *)v0 + 1412) = 0;
  mutex_lock(&qword_316D0);
  v3 = *((unsigned int **)v0 + 159);
  v4 = (unsigned int **)(v0 + 318);
  if ( v3 != v0 + 318 )
  {
    do
    {
      list_del((struct list_head *)v3);
      v9 = *((_QWORD *)v3 + 2);
      *(_QWORD *)v3 = 0xDEAD000000000100LL;
      *((_QWORD *)v3 + 1) = 0xDEAD000000000122LL;
      kfree(v9);
      kfree(v3);
      v10 = v0[316];
      if ( v10 )
        v0[316] = v10 - 1;
      v3 = *v4;
    }
    while ( *v4 != (unsigned int *)v4 );
  }
  mutex_unlock(&qword_316D0);
  syna_tcm_clear_data_duplicator(*(_QWORD *)v0);
  mutex_unlock(&qword_316A0);
  printk(unk_34E37, "syna_cdev_open", v5);
  return 0;
}
