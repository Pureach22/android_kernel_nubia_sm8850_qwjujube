__int64 __fastcall debugfs_esd_trigger_check(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x8
  char v7; // w8
  int v8; // w20
  size_t v9; // x23
  __int64 v10; // x0
  __int64 v11; // x19
  int v12; // w20
  __int64 v13; // x20
  __int64 (__fastcall *v14)(_QWORD); // x8
  int v15; // w0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    result = -19;
    goto LABEL_11;
  }
  if ( *a4 )
  {
    result = 0;
    goto LABEL_11;
  }
  result = -22;
  if ( a3 <= 4 && a2 && a3 )
  {
    v6 = *(_QWORD *)(v4 + 264);
    if ( !v6 || *(_DWORD *)(v6 + 1968) )
    {
      result = a3;
      goto LABEL_11;
    }
    v7 = *(_BYTE *)(v6 + 1720);
    v16 = 0;
    if ( (v7 & 1) == 0 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: ESD feature is not enabled\n");
      result = -22;
      goto LABEL_11;
    }
    v8 = a2;
    v9 = a3;
    v10 = _kmalloc_cache_noprof(kthread_create_on_node, 3520, 10);
    v11 = v10;
    if ( !v10 )
    {
      result = -12;
      goto LABEL_11;
    }
    _check_object_size(v10, v9, 0);
    if ( inline_copy_from_user_7(v11, v8, v9) )
    {
      v12 = -22;
LABEL_16:
      kfree(v11);
      result = v12;
      goto LABEL_11;
    }
    *(_BYTE *)(v11 + v9) = 0;
    v12 = -22;
    if ( (unsigned int)kstrtouint(v11, 10, &v16) || v16 != 1 )
      goto LABEL_16;
    *(_DWORD *)(v4 + 1372) = 1;
    mutex_lock(v4 + 72);
    if ( (*(_BYTE *)(v4 + 1642) & 1) != 0 )
    {
      if ( *(_DWORD *)(v4 + 1372) )
      {
        v13 = *(_QWORD *)(v4 + 264);
        drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: ESD attack triggered by user\n");
        v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 2304);
        if ( *((_DWORD *)v14 - 1) != -1699580201 )
          __break(0x8228u);
        v15 = v14(v13);
        if ( v15 )
        {
          v12 = v15;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to trigger ESD attack\n");
          goto LABEL_16;
        }
      }
    }
    else
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: [%s] op not supported due to HW unavailability\n",
        *(const char **)(v4 + 32));
      LODWORD(v9) = -95;
    }
    mutex_unlock(v4 + 72);
    v12 = v9;
    goto LABEL_16;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
