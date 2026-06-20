size_t __fastcall reg_dmav1_setup_dspp_memcol_skinv17(int *a1, _QWORD *a2)
{
  const void *v4; // x1
  __int64 v5; // x2
  unsigned int v6; // w4
  __int64 v7; // x10
  int v8; // w1
  double v10; // d0

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v4 = (const void *)a2[2];
  v5 = (unsigned int)a1[16];
  v6 = a1[374];
  if ( !v4 || (unsigned int)v5 > 4 || v6 >= 2 )
    return _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v4, v5, 5, v6);
  if ( &dspp_buf[2 * v5] == (unsigned __int64 *)-400LL )
    return _drm_err("invalid dma_buf\n");
  v7 = *a2;
  *((_DWORD *)a2 + 40) = a2[20] & 0xFF0F0FFF | 0x701000;
  if ( v7 )
  {
    v8 = *((_DWORD *)a2 + 2);
    if ( v8 == 48 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "reg_dmav1_setup_dspp_memcol_skinv17",
        3147,
        -1,
        a1[16],
        a1[374],
        a1[7],
        1,
        239);
      return _setup_dspp_memcol(a1, 5, a2);
    }
    else
    {
      return _drm_err("invalid size of payload len %d exp %zd\n", v8, 0x30u);
    }
  }
  else
  {
    v10 = _drm_dev_dbg(0, 0, 1, "disable memcolor skin feature\n");
    reg_dma_dspp_memcol_off(a1, a2, 5, v10);
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "reg_dmav1_setup_dspp_memcol_skinv17",
             3137,
             -1,
             a1[16],
             a1[374],
             a1[7],
             0,
             239);
  }
}
