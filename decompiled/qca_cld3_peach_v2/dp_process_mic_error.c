__int64 __fastcall dp_process_mic_error(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x30
  __int64 v11; // x8
  __int64 v12; // x21
  const char *v13; // x2
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v18; // x21
  __int64 vdev_by_user; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w4
  __int64 v29; // x20
  void (__fastcall *v30)(__int64, __int64); // x8
  __int64 v31; // x0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( !a1 )
  {
    v13 = "%s: Interface is NULL";
LABEL_8:
    qdf_trace_msg(0x45u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "is_dp_intf_valid");
    goto LABEL_9;
  }
  v11 = a1[7];
  if ( !v11 )
  {
    v13 = "%s: DP interface net_device is null";
    goto LABEL_8;
  }
  if ( (*(_BYTE *)(v11 + 176) & 1) != 0 )
  {
    v18 = *a1;
    vdev_by_user = _dp_objmgr_get_vdev_by_user(a1[458], 97, "__dp_process_mic_error");
    if ( !vdev_by_user )
      goto LABEL_9;
    v28 = *((_DWORD *)a1 + 7);
    v29 = vdev_by_user;
    if ( (v28 | 2) == 2 )
    {
      if ( wlan_cm_is_vdev_active(vdev_by_user, v20, v21, v22, v23, v24, v25, v26, v27) )
        goto LABEL_23;
      v28 = *((_DWORD *)a1 + 7);
    }
    if ( (v28 | 2) != 3 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid interface type:%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "__dp_process_mic_error");
LABEL_27:
      wlan_objmgr_vdev_release_ref(v29, 0x61u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
      goto LABEL_9;
    }
LABEL_23:
    v30 = *(void (__fastcall **)(__int64, __int64))(v18 + 664);
    v31 = a1[432];
    if ( *((_DWORD *)v30 - 1) != -1466984463 )
      __break(0x8228u);
    v30(v31, v29);
    goto LABEL_27;
  }
  v12 = jiffies;
  if ( is_dp_intf_valid___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: DP interface '%s' is not up %ps",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "is_dp_intf_valid",
      v11 + 296,
      v9);
    is_dp_intf_valid___last_ticks = v12;
  }
LABEL_9:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 433);
    v15 = a1[432];
    if ( !v15 )
      goto LABEL_14;
    goto LABEL_13;
  }
  raw_spin_lock_bh(a1 + 433);
  a1[434] |= 1uLL;
  v15 = a1[432];
  if ( v15 )
  {
LABEL_13:
    _qdf_mem_free(v15);
    a1[432] = 0;
  }
LABEL_14:
  if ( *((_DWORD *)a1 + 862) == 2 )
    *((_DWORD *)a1 + 862) = 1;
  v16 = a1[434];
  if ( (v16 & 1) == 0 )
    return raw_spin_unlock(a1 + 433);
  a1[434] = v16 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 433);
}
