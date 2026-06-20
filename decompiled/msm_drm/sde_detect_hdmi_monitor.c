__int64 __fastcall sde_detect_hdmi_monitor(_QWORD *a1)
{
  return drm_detect_hdmi_monitor(*a1) & 1;
}
