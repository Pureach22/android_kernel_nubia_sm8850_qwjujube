__int64 __fastcall sub_C95C0(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w16
  int v4; // w19

  return sde_crtc_force_async_mode(a1, a2, a3, v4 & ~HIBYTE(v3));
}
