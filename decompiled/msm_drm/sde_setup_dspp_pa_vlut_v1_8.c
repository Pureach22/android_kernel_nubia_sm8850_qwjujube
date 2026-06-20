__int64 __fastcall sde_setup_dspp_pa_vlut_v1_8(__int64 a1, _QWORD **a2)
{
  __int64 v2; // d14
  _QWORD *v3; // x21
  int v5; // w3
  _QWORD *v6; // x20
  __int64 v7; // x8
  int v8; // w24
  unsigned int v9; // w22
  unsigned __int64 v10; // x25
  bool v11; // cf
  __int64 result; // x0
  __int64 v13; // x15
  __int64 v14; // d3
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v17; // x1

  if ( !a1 )
    return _drm_err("invalid input parameter NULL ctx\n");
  if ( !a2 )
  {
    v3 = nullptr;
    v5 = 0;
    return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v3, v5, 0x408u);
  }
  v3 = *a2;
  if ( *a2 )
  {
    v5 = *((_DWORD *)a2 + 2);
    if ( v5 != 1032 )
      return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v3, v5, 0x408u);
  }
  v6 = a2[2];
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v8 = *(_DWORD *)(v7 + 308);
  if ( v3 )
  {
    v9 = *(_DWORD *)(v7 + 488);
    _drm_dev_dbg(0, 0, 1, "Enable vlut feature flags %llx\n", *v3);
    v10 = 0;
    do
    {
      sde_reg_write(a1, v9, v3[v10 + 1] & 0x3FF | ((HIDWORD(v3[v10 + 1]) & 0x3FF) << 16), "(vlut_base + j)");
      v11 = v10++ >= 127;
      v9 += 4;
    }
    while ( !v11 );
    sde_reg_write(a1, v8 + 76, 1u, "ctrl_off");
    result = sde_reg_write(a1, v8 + 24, 1u, "swap_off");
    if ( !v6 )
      return result;
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "Disable vlut feature\n");
    result = sde_reg_write(a1, v8 + 76, 0, "ctrl_off");
    if ( !v6 )
      return result;
  }
  v15 = *((unsigned int *)v6 + 7);
  if ( (unsigned int)v15 > 2 )
  {
    __break(0x5512u);
    *(_QWORD *)(v13 - 24) = v2;
    *(_QWORD *)(v13 - 16) = v14;
    return sde_setup_dspp_gc_v1_7(result);
  }
  else
  {
    v16 = (_DWORD *)v6[v15 + 140];
    if ( v16 )
    {
      v17 = *(unsigned int *)(a1 + 64);
      if ( *(v16 - 1) != -365933170 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v16)(v6, v17, 1);
    }
  }
  return result;
}
