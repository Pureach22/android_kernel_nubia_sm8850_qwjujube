__int64 __fastcall sub_CF7FC(double a1, double a2, double a3)
{
  __int64 v3; // x14
  __int64 v4; // d24

  *(double *)(v3 - 40) = a3;
  *(_QWORD *)(v3 - 32) = v4;
  return sde_crtc_get_vblank_timestamp();
}
