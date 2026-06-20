__int64 __fastcall sde_lock_dspp_hist_v1_7(_QWORD *a1, _DWORD *a2)
{
  if ( a1 && a2 )
    return sde_reg_write((__int64)a1, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 308LL) + 4, *a2 & 1, "offset_ctl");
  else
    return _drm_err("invalid parameters ctx %pK cfg %pK", a1, a2);
}
