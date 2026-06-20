__int64 __fastcall mhi_unregister_controller(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x21
  __int64 v4; // x22
  __int64 v5; // x20
  unsigned int i; // w23
  __int64 v7; // x8
  unsigned int v8; // w8
  unsigned int v9; // w20
  _QWORD *v10; // x22

  v1 = *(_DWORD *)(a1 + 212);
  v2 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(a1 + 176);
  if ( v1 )
  {
    v5 = *(_QWORD *)(a1 + 248);
    for ( i = 0; i < v1; ++i )
    {
      if ( (*(_BYTE *)(v5 + 258) & 1) == 0 )
      {
        free_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v5 + 24)), v5);
        v1 = *(_DWORD *)(a1 + 212);
      }
      v5 += 264;
    }
  }
  free_irq(**(unsigned int **)(a1 + 200), a1);
  mhi_misc_unregister_controller(a1);
  mhi_misc_sysfs_destroy(a1);
  if ( *(_BYTE *)(a1 + 612) == 1 )
  {
    v7 = *(_QWORD *)(a1 + 152);
    *(_BYTE *)(a1 + 612) = 0;
    if ( v7 )
      mhi_free_bhie_table(a1, (_QWORD *)(a1 + 152));
    if ( *(_QWORD *)(a1 + 160) )
      mhi_free_bhie_table(a1, (_QWORD *)(a1 + 160));
  }
  if ( *(_QWORD *)(a1 + 592) )
    sysfs_remove_file_ns(v2 + 40, &dev_attr_trigger_edl, 0);
  destroy_workqueue(*(_QWORD *)(a1 + 448));
  kfree(*(_QWORD *)(a1 + 256));
  kfree(*(_QWORD *)(a1 + 248));
  v8 = *(_DWORD *)(a1 + 208);
  if ( v8 )
  {
    v9 = 0;
    v10 = (_QWORD *)(v4 + 272);
    do
    {
      if ( *v10 )
      {
        put_device(*v10 + 40LL);
        v8 = *(_DWORD *)(a1 + 208);
      }
      ++v9;
      v10 += 50;
    }
    while ( v9 < v8 );
  }
  vfree(*(_QWORD *)(a1 + 176));
  device_del(v2 + 40);
  put_device(v2 + 40);
  return ida_free(&mhi_controller_ida, *(unsigned int *)(a1 + 608));
}
