__int64 __fastcall sde_cp_crtc_init(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 blob; // x0
  unsigned __int64 v4; // x8
  __int64 result; // x0

  if ( !a1 )
    return _drm_err("invalid crtc %pK\n", nullptr);
  v1 = a1 + 4096;
  blob = drm_property_create_blob(*(_QWORD *)a1, 1032, 0);
  if ( blob <= 0xFFFFFFFFFFFFF000LL )
    v4 = blob;
  else
    v4 = 0;
  *(_QWORD *)(a1 + 7576) = v4;
  msm_property_install_blob(a1 + 2600, "dspp_caps", 4, 4);
  _mutex_init(a1 + 4664, "&sde_crtc->crtc_cp_lock", &sde_cp_crtc_init___key);
  *(_QWORD *)(a1 + 4536) = a1 + 4536;
  *(_QWORD *)(a1 + 4544) = a1 + 4536;
  *(_QWORD *)(a1 + 4552) = a1 + 4552;
  *(_QWORD *)(a1 + 4560) = a1 + 4552;
  *(_QWORD *)(a1 + 4520) = a1 + 4520;
  *(_QWORD *)(a1 + 4528) = a1 + 4520;
  *(_QWORD *)(a1 + 4568) = a1 + 4568;
  *(_QWORD *)(a1 + 4576) = a1 + 4568;
  *(_QWORD *)(a1 + 4584) = a1 + 4584;
  *(_QWORD *)(a1 + 4592) = a1 + 4584;
  _mutex_init(a1 + 7704, "&sde_crtc->ltm_buffer_lock", &sde_cp_crtc_init___key_5);
  *(_DWORD *)(a1 + 7752) = 0;
  *(_QWORD *)(a1 + 7640) = a1 + 7640;
  *(_QWORD *)(a1 + 7648) = a1 + 7640;
  *(_QWORD *)(a1 + 7656) = a1 + 7656;
  *(_QWORD *)(a1 + 7664) = a1 + 7656;
  *(_BYTE *)(v1 + 3668) = 0;
  result = sde_cp_crtc_disable(a1);
  *(_BYTE *)(v1 + 3860) = 0;
  *(_QWORD *)(a1 + 7960) = 0;
  *(_QWORD *)(a1 + 7968) = 0;
  return result;
}
