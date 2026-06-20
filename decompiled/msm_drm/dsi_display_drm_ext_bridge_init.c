__int64 __fastcall dsi_display_drm_ext_bridge_init(__int64 a1, __int64 *a2, __int64 *a3)
{
  unsigned __int64 v3; // x22
  __int64 *v5; // x20
  __int64 v6; // x25
  __int64 *v8; // x10
  __int64 v9; // x8
  __int64 *v10; // x23
  __int64 *v11; // x26
  unsigned __int64 v12; // x27
  __int64 v13; // x24
  _QWORD *v14; // x28
  unsigned __int64 bridge; // x0
  _QWORD *v16; // x8
  int v17; // w0
  __int64 *v18; // x9
  __int64 *v19; // x10
  __int64 v20; // x8
  __int64 **v21; // x8
  __int64 *v22; // x11
  __int64 v23; // x8
  __int64 v24; // x9
  _QWORD *v25; // x8
  const char *v26; // x3
  int v27; // w19

  LODWORD(v3) = -22;
  if ( !a1 )
    return (unsigned int)v3;
  if ( !a2 )
    return (unsigned int)v3;
  v5 = a3;
  if ( !a3 )
    return (unsigned int)v3;
  v6 = *a2;
  v8 = (__int64 *)a2[11];
  v9 = *(_QWORD *)(a1 + 264);
  v10 = v8 - 15;
  if ( v8 == a2 + 11 )
    v11 = nullptr;
  else
    v11 = v8 - 15;
  if ( v9 && *(_BYTE *)(v9 + 1274) != 1 )
    goto LABEL_59;
  if ( !v11 )
  {
    LODWORD(v3) = -22;
    return (unsigned int)v3;
  }
  if ( !*(_DWORD *)(a1 + 816) )
  {
LABEL_59:
    LODWORD(v3) = 0;
    return (unsigned int)v3;
  }
  v12 = 0;
  v13 = a1 + 288;
  while ( v12 != 3 )
  {
    v14 = (_QWORD *)(v13 + 264 * v12);
    if ( v14[2] )
      goto LABEL_59;
    bridge = of_drm_find_bridge(v14[1]);
    v3 = bridge;
    if ( !bridge || bridge >= 0xFFFFFFFFFFFFF001LL )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to find ext bridge\n");
      return (unsigned int)v3;
    }
    if ( *(_DWORD *)(a1 + 816) >= 2u )
    {
      memcpy(v14 + 4, *(const void **)(bridge + 168), 0xE8u);
      v16 = *(_QWORD **)(v3 + 168);
      if ( v16[3] )
      {
        v14[7] = dsi_display_drm_ext_bridge_mode_fixup;
        v16 = *(_QWORD **)(v3 + 168);
      }
      if ( v16[2] )
      {
        v14[6] = dsi_display_drm_ext_bridge_mode_valid;
        v16 = *(_QWORD **)(v3 + 168);
      }
      if ( v16[6] )
      {
        v14[10] = dsi_display_drm_ext_bridge_mode_set;
        v16 = *(_QWORD **)(v3 + 168);
      }
      v14[3] = v16;
      *(_QWORD *)(v3 + 168) = v14 + 4;
      v5 = a3;
    }
    v17 = drm_bridge_attach(a2, v3, v10, 1);
    if ( v17 )
    {
      v26 = *(const char **)(a1 + 32);
      v27 = v17;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] ext brige attach failed, %d\n", v26, v17);
      LODWORD(v3) = v27;
      return (unsigned int)v3;
    }
    *v14 = a1;
    v14[2] = v3;
    raw_spin_lock_irq(v6 + 728);
    v18 = *(__int64 **)(v6 + 760);
    v19 = v18 - 4;
    if ( v18 == (__int64 *)&dword_20 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get external connector\n");
LABEL_58:
      raw_spin_unlock_irq(v6 + 728);
      goto LABEL_59;
    }
    v20 = *(v18 - 4) + 816;
    do
      v20 = *(_QWORD *)v20;
    while ( v20 != *(v18 - 4) + 816 && ((*((_DWORD *)v18 + 558) >> *(_DWORD *)(v20 + 60)) & 1) == 0 );
    if ( v20 == 8 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get encoder\n");
      goto LABEL_58;
    }
    if ( v19 != v5 && *(_DWORD *)(v20 + 16) == *(_DWORD *)(v11[14] + 24) )
    {
      v21 = (__int64 **)v18[1];
      if ( *v21 == v18 && (v22 = (__int64 *)*v18, *(__int64 **)(*v18 + 8) == v18) )
      {
        v22[1] = (__int64)v21;
        *v21 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v6 + 760));
      }
      *v18 = (__int64)v18;
      v18[1] = (__int64)v18;
      *(_QWORD *)(a1 + 24) = v19;
    }
    raw_spin_unlock_irq(v6 + 728);
    v23 = *(_QWORD *)(a1 + 24);
    if ( v23
      && (v24 = *(_QWORD *)(v23 + 416)) != 0
      && (v25 = *(_QWORD **)(v23 + 2088)) != nullptr
      && *(_DWORD *)(a1 + 816) < 2u )
    {
      if ( *(_QWORD *)(v24 + 16) )
      {
        v5[361] = (__int64)dsi_display_drm_ext_detect;
        v25 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 2088LL);
      }
      if ( *v25 )
      {
        v5[363] = (__int64)dsi_display_drm_ext_get_modes;
        v25 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 2088LL);
      }
      if ( v25[2] )
      {
        v5[365] = (__int64)dsi_display_drm_ext_mode_valid;
        v25 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 2088LL);
      }
      if ( v25[6] )
        v5[388] = (__int64)dsi_display_drm_ext_atomic_check;
      v5[368] = (__int64)dsi_display_ext_get_info;
      v5[369] = (__int64)dsi_display_ext_get_mode_info;
      *(_QWORD *)(a1 + 1272) = dsi_host_ext_ops;
    }
    else
    {
      *(_QWORD *)(a1 + 24) = 0;
    }
    ++v12;
    v10 = (__int64 *)v3;
    LODWORD(v3) = 0;
    if ( v12 >= *(unsigned int *)(a1 + 816) )
      return (unsigned int)v3;
  }
  __break(0x5512u);
  return dsi_display_drm_ext_bridge_mode_fixup();
}
