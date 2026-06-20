__int64 __fastcall tp_self_test_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v6; // x22
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x23
  int (__fastcall *v12)(__int64, __int64); // x8
  __int64 v13; // x22
  __int64 v14; // x19
  __int64 v15; // x0

  if ( *a4 )
    return 0;
  v6 = tpd_cdev;
  v10 = _kmalloc_cache_noprof(init_timer_key, 3520, 4096);
  if ( !v10 )
  {
    printk(&unk_33404, v8, v9);
    return -12;
  }
  if ( *a4 )
    return 0;
  v12 = *(int (__fastcall **)(__int64, __int64))(v6 + 3552);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != 1693605810 )
      __break(0x8228u);
    v13 = v12(v6, v10);
  }
  else
  {
    v13 = 0;
  }
  simple_read_from_buffer(a2, a3, a4, v10, v13);
  kfree(v10);
  v14 = tpd_cdev;
  v15 = *(_QWORD *)(tpd_cdev + 2720);
  if ( v15 )
  {
    if ( *(_QWORD *)(v15 + 8) )
    {
      vfree(*(_QWORD *)(v15 + 8));
      *(_QWORD *)(*(_QWORD *)(v14 + 2720) + 8LL) = 0;
      **(_QWORD **)(v14 + 2720) = 0;
      v15 = *(_QWORD *)(v14 + 2720);
    }
    kfree(v15);
    *(_QWORD *)(v14 + 2720) = 0;
  }
  *(_DWORD *)(v14 + 1096) = 0;
  return v13;
}
