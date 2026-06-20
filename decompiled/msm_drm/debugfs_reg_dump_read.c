__int64 __fastcall debugfs_reg_dump_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x24
  __int64 v9; // x19
  __int64 (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x0
  int v12; // w0
  int v13; // w21
  __int64 v14; // x8
  __int64 (__fastcall *v15)(__int64, __int64, __int64); // x8
  unsigned int v16; // w21
  __int64 (__fastcall *v17)(__int64, __int64, __int64); // x8
  __int64 v18; // x0
  int v19; // w0
  int v20; // w22
  unsigned int v21; // w8
  __int64 v22; // x21
  unsigned __int64 StatusReg; // x21
  __int64 v24; // x22

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v9 )
    return -12;
  while ( 1 )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v4 + 1640);
    v11 = *(_QWORD *)(v4 + 1632);
    if ( *((_DWORD *)v10 - 1) != 1407241817 )
      __break(0x8228u);
    v12 = v10(v11, 0x100000001LL, 1);
    if ( v12 )
    {
      v13 = v12;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to enable DSI core clocks\n",
        *(const char **)(v4 + 16));
      kfree(v9);
      return v13;
    }
    v14 = *(unsigned int *)(v4 + 1608);
    if ( (unsigned int)v14 < 3 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &debugfs_reg_dump_read__alloc_tag;
    v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v9 )
      return -12;
  }
  v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v4 + 8 * v14 + 1080);
  if ( v15 )
  {
    if ( *((_DWORD *)v15 - 1) != 1314269413 )
      __break(0x8228u);
    v16 = v15(v4 + 96, v9, 4096);
  }
  else
  {
    v16 = 0;
  }
  v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v4 + 1640);
  v18 = *(_QWORD *)(v4 + 1632);
  if ( *((_DWORD *)v17 - 1) != 1407241817 )
    __break(0x8228u);
  v19 = v17(v18, 1, 1);
  if ( v19 )
  {
    v20 = v19;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to disable DSI core clocks\n",
      *(const char **)(v4 + 16));
    kfree(v9);
    return v20;
  }
  else
  {
    if ( v16 <= a3 )
      v21 = v16;
    else
      v21 = a3;
    if ( v21 >= 0x1000 )
      v22 = 4096;
    else
      v22 = v21;
    _check_object_size(v9, v22, 1);
    if ( inline_copy_to_user_4(a2, v9, v22) )
    {
      kfree(v9);
      return -14;
    }
    else
    {
      *a4 += v22;
      kfree(v9);
      return v22;
    }
  }
}
