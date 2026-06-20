unsigned __int64 __fastcall hdd_sysfs_modify_acl_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 v25; // x22
  int v26; // w0
  int v28; // w0
  int v29; // w21
  __int64 v30; // x20
  __int64 v31; // x20
  char *v32; // x0
  char *v33; // x0
  char *v34; // x0
  char *v35; // x0
  char *v36; // x0
  char *v37; // x0
  char *v38; // x0
  char *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 *v48; // [xsp+10h] [xbp-70h] BYREF
  __int64 v49; // [xsp+18h] [xbp-68h] BYREF
  char *stringp; // [xsp+20h] [xbp-60h] BYREF
  int v51; // [xsp+28h] [xbp-58h] BYREF
  _WORD v52[2]; // [xsp+2Ch] [xbp-54h] BYREF
  _QWORD v53[8]; // [xsp+30h] [xbp-50h] BYREF
  char v54; // [xsp+70h] [xbp-10h]
  __int64 v55; // [xsp+78h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v48, (__int64)"hdd_sysfs_modify_acl_store");
  if ( !v7 )
  {
    v54 = 0;
    memset(v53, 0, sizeof(v53));
    v52[0] = 0;
    v51 = 0;
    v49 = 0;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_modify_acl_store",
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15) )
    {
LABEL_4:
      a4 = -22;
      goto LABEL_5;
    }
    v25 = *(_QWORD *)(a1 + 1336);
    v26 = _wlan_hdd_validate_context(
            v25,
            (__int64)"__hdd_sysfs_modify_acl_store",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v26 )
    {
      a4 = v26;
    }
    else
    {
      if ( !wlan_hdd_validate_modules_state(v25, v16, v17, v18, v19, v20, v21, v22, v23) )
        goto LABEL_4;
      if ( *(_DWORD *)(a1 + 1352) != 1 )
      {
        v31 = jiffies;
        if ( _hdd_sysfs_modify_acl_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Command only allowed in sap mode",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__hdd_sysfs_modify_acl_store");
          _hdd_sysfs_modify_acl_store___last_ticks = v31;
        }
        goto LABEL_4;
      }
      v28 = hdd_sysfs_validate_and_copy_buf((__int64)v53, 65, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( v28 )
      {
        v29 = v28;
        v30 = jiffies;
        if ( _hdd_sysfs_modify_acl_store___last_ticks_5 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__hdd_sysfs_modify_acl_store");
          _hdd_sysfs_modify_acl_store___last_ticks_5 = v30;
        }
        a4 = v29;
        if ( (v29 & 0x8000000000000000LL) == 0 )
          goto LABEL_10;
        goto LABEL_5;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: modify_acl: count %zu buf_local:(%s) net_devname %s",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__hdd_sysfs_modify_acl_store",
        a4,
        v53,
        a1 - 1080);
      stringp = (char *)v53;
      v32 = strsep(&stringp, " ");
      if ( !v32 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v32, 0, &v51) )
        goto LABEL_4;
      v33 = strsep(&stringp, " ");
      if ( !v33 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v33, 0, (char *)&v51 + 1) )
        goto LABEL_4;
      v34 = strsep(&stringp, " ");
      if ( !v34 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v34, 0, (char *)&v51 + 2) )
        goto LABEL_4;
      v35 = strsep(&stringp, " ");
      if ( !v35 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v35, 0, (char *)&v51 + 3) )
        goto LABEL_4;
      v36 = strsep(&stringp, " ");
      if ( !v36 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v36, 0, v52) )
        goto LABEL_4;
      v37 = strsep(&stringp, " ");
      if ( !v37 )
        goto LABEL_4;
      if ( (unsigned int)kstrtou8(v37, 0, (char *)v52 + 1) )
        goto LABEL_4;
      v38 = strsep(&stringp, " ");
      if ( !v38 )
        goto LABEL_4;
      if ( (unsigned int)kstrtouint(v38, 0, (char *)&v49 + 4) )
        goto LABEL_4;
      v39 = strsep(&stringp, " ");
      if ( !v39 || (unsigned int)kstrtouint(v39, 0, &v49) )
        goto LABEL_4;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Modify ACL mac:%02x:%02x:%02x:**:**:%02x type: %d cmd: %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__hdd_sysfs_modify_acl_store",
        (unsigned __int8)v51,
        BYTE1(v51),
        BYTE2(v51),
        HIBYTE(v52[0]),
        HIDWORD(v49),
        v49);
      if ( (unsigned int)wlansap_modify_acl(
                           *(_QWORD *)(*(_QWORD *)(a1 + 54144) + 272LL),
                           (unsigned __int8 *)&v51,
                           HIDWORD(v49),
                           v49,
                           v40,
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Modify ACL failed",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "__hdd_sysfs_modify_acl_store");
        a4 = -5;
        goto LABEL_5;
      }
    }
    if ( (a4 & 0x8000000000000000LL) == 0 )
    {
LABEL_10:
      _osif_vdev_sync_op_stop((__int64)v48, (__int64)"hdd_sysfs_modify_acl_store");
      goto LABEL_11;
    }
LABEL_5:
    v24 = jiffies;
    if ( hdd_sysfs_modify_acl_store___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: errno_size %zd",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_sysfs_modify_acl_store",
        a4);
      hdd_sysfs_modify_acl_store___last_ticks = v24;
    }
    goto LABEL_10;
  }
  a4 = v7;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return a4;
}
