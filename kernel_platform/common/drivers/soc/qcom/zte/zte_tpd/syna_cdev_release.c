__int64 syna_cdev_release(void)
{
  __int64 *v0; // x21
  __int64 v1; // x2
  __int64 *v2; // x20
  __int64 **v3; // x22
  __int64 v4; // x2
  __int64 v5; // x8
  __int64 v9; // x0
  int v10; // w8

  v0 = *(__int64 **)(g_cdev_data + 168);
  v1 = *((unsigned int *)v0 + 225);
  if ( (int)v1 > 0 )
  {
    mutex_lock(&qword_316A0);
    --*((_DWORD *)v0 + 225);
    mutex_lock(&qword_316D0);
    v2 = (__int64 *)v0[159];
    v3 = (__int64 **)(v0 + 159);
    if ( v2 != v0 + 159 )
    {
      do
      {
        list_del((struct list_head *)v2);
        v9 = v2[2];
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v9);
        kfree(v2);
        v10 = *((_DWORD *)v0 + 316);
        if ( v10 )
          *((_DWORD *)v0 + 316) = v10 - 1;
        v2 = *v3;
      }
      while ( *v3 != (__int64 *)v3 );
    }
    mutex_unlock(&qword_316D0);
    syna_tcm_clear_data_duplicator(*v0);
    mutex_unlock(&qword_316A0);
    qword_31700 = 0;
    LODWORD(qword_31708) = 0;
    printk(unk_377F8, "syna_cdev_release", v4);
    v5 = *v0;
    if ( *(_DWORD *)(*v0 + 56) != HIDWORD(qword_31708) )
    {
      *(_DWORD *)(v5 + 56) = HIDWORD(qword_31708);
      v5 = *v0;
    }
    if ( *(_DWORD *)(v5 + 60) != (_DWORD)qword_31710 )
      *(_DWORD *)(v5 + 60) = qword_31710;
  }
  else
  {
    printk(unk_34E53, "syna_cdev_release", v1);
  }
  return 0;
}
