__int64 __fastcall sde_crtc_vm_release_notify(__int64 *a1)
{
  __int64 result; // x0
  int v2; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 1;
  result = sde_crtc_event_notify(a1, -2147483634, &v2, 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
