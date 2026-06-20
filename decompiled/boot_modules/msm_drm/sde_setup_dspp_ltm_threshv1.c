__int64 __fastcall sde_setup_dspp_ltm_threshv1(_QWORD *a1, _DWORD **a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x2
  __int64 v4; // x1

  v2 = a1;
  if ( !a1 || !a2 )
    return _drm_err("invalid parameters ctx %pK cfg %pK\n", a1, a2);
  if ( *a2 )
  {
    v3 = **a2 & 0x3FF;
    v4 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 96);
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "Disable LTM noise thresh feature\n");
    a1 = v2;
    v3 = 0;
    v4 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2[9] + 48LL) + 380LL) + 96);
  }
  return sde_reg_write(a1, v4, v3, "ctx->cap->sblk->ltm.base + 0x60");
}
