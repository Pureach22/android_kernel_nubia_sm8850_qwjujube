__int64 __fastcall dspp_hist_install_property(__int64 a1)
{
  int v1; // w1

  v1 = HIWORD(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 8LL) + 152LL) + 8216LL)
                        + 320LL));
  if ( v1 != 1 )
    return _drm_err("version %d not supported\n", v1);
  sde_cp_crtc_install_enum_property(a1, 11, &sde_hist_modes, 2, "SDE_DSPP_HIST_CTRL_V1");
  return sde_cp_crtc_install_range_property(a1, "SDE_DSPP_HIST_IRQ_V1", 12, 0, 0xFFFF, 0);
}
