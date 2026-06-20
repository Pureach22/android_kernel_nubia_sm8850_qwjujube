__int64 __fastcall debugfs_misr_setup(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  const char *v8; // x20
  size_t v9; // x22
  bool v10; // zf
  char v11; // w9
  __int64 v12; // x8
  __int64 (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w0
  int v15; // w21
  __int64 v16; // x19
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x24
  __int64 (__fastcall *v21)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v22; // [xsp+0h] [xbp-10h] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    result = -19;
    goto LABEL_33;
  }
  if ( *a4 )
  {
    result = 0;
    goto LABEL_33;
  }
  v22 = 0;
  v8 = (const char *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 256);
  if ( !v8 )
  {
LABEL_32:
    result = -12;
    goto LABEL_33;
  }
  while ( 1 )
  {
    if ( a3 >= 0xFF )
      v9 = 255;
    else
      v9 = a3;
    _check_object_size(v8, v9, 0);
    if ( inline_copy_from_user_7((__int64)v8, a2, v9) || (v8[v9] = 0, sscanf(v8, "%u %u", (char *)&v22 + 4, &v22) != 2) )
    {
      v16 = -22;
      goto LABEL_22;
    }
    v10 = HIDWORD(v22) == 0;
    *(_DWORD *)(v4 + 1348) = v22;
    v11 = !v10;
    *(_BYTE *)(v4 + 1344) = v11;
    mutex_lock(v4 + 72);
    if ( (*(_BYTE *)(v4 + 1642) & 1) == 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: [%s] op not supported due to HW unavailability\n",
        *(const char **)(v4 + 32));
      v15 = -95;
      goto LABEL_30;
    }
    v12 = *(unsigned int *)(*(_QWORD *)(v4 + 168) + 1608LL);
    if ( (unsigned int)v12 < 3 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    v21 = drm_dp_dpcd_read;
    *(_QWORD *)(StatusReg + 80) = &debugfs_misr_setup__alloc_tag;
    v8 = (const char *)_kmalloc_cache_noprof(v21, 3520, 256);
    *(_QWORD *)(StatusReg + 80) = v20;
    if ( !v8 )
      goto LABEL_32;
  }
  v13 = *(__int64 (__fastcall **)(_QWORD))(v4 + 8 * v12 + 1872);
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != 2041732229 )
      __break(0x8228u);
    v14 = v13(v4);
    if ( v14 )
    {
      v15 = v14;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to enable MISR through hfi, rc=%d\n",
        *(_QWORD *)(v4 + 32),
        v14);
      goto LABEL_30;
    }
LABEL_29:
    v15 = a3;
    goto LABEL_30;
  }
  v17 = dsi_display_clk_ctrl(*(_QWORD *)(v4 + 1320), 1, 1);
  if ( v17 )
  {
    v15 = v17;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI core clocks, rc=%d\n",
      *(_QWORD *)(v4 + 32),
      v17);
    goto LABEL_30;
  }
  dsi_display_setup_misr(v4);
  v18 = dsi_display_clk_ctrl(*(_QWORD *)(v4 + 1320), 1, 0);
  if ( !v18 )
    goto LABEL_29;
  v15 = v18;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI core clocks, rc=%d\n",
    *(_QWORD *)(v4 + 32),
    v18);
LABEL_30:
  mutex_unlock(v4 + 72);
  v16 = v15;
LABEL_22:
  kfree(v8);
  result = v16;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
