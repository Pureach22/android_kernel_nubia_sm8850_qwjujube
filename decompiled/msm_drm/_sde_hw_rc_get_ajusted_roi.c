__int64 __fastcall sde_hw_rc_get_ajusted_roi(int *a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  if ( a2 && a3 )
  {
    if ( a2[2] || a2[3] )
    {
      *(_QWORD *)a3 = *(_QWORD *)a2;
    }
    else
    {
      *a3 = *a2;
      a3[1] = a2[1];
      a3[2] = a1[24];
      a3[3] = a1[23];
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "_sde_hw_rc_get_ajusted_roi", 565, -1, a1[11], a1[10], a1[24], a1[23], 239);
    _drm_dev_dbg(0, 0, 0, "displayh:%u, displayv:%u, panel_w:%u, panel_h:%u\n", a1[11], a1[10], a1[24], a1[23]);
    _drm_dev_dbg(0, 0, 0, "pu_roi x:%u, y:%u, w:%u, h:%u\n", *a2, a2[1], a2[2], a2[3]);
    _drm_dev_dbg(0, 0, 0, "rc_roi x:%u, y:%u, w:%u, h:%u\n", *a3, a3[1], a3[2], a3[3]);
    return 0;
  }
  else
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
}
