__int64 __fastcall sde_setup_dspp_pa_vlut_v1_7(__int64 a1, const void **a2)
{
  const void *v2; // x2
  unsigned int v4; // w20
  int v5; // w3
  int v7; // w0
  _QWORD *v8; // x24
  int v9; // w21
  unsigned __int64 v10; // x25
  unsigned int v11; // w22
  bool v12; // cf
  unsigned int v13; // w2
  int v15; // w8

  if ( !a2 )
  {
    v2 = nullptr;
    v5 = 0;
    return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v2, v5, 0x408u);
  }
  v2 = *a2;
  v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 488LL);
  if ( *a2 )
  {
    v5 = *((_DWORD *)a2 + 2);
    if ( v5 != 1032 )
      return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v2, v5, 0x408u);
  }
  v7 = sde_reg_read(a1, v4);
  v8 = *a2;
  v9 = v7;
  if ( v8 )
  {
    _drm_dev_dbg(0, 0, 1, "Enable vlut feature flags %llx\n", *v8);
    v10 = 0;
    v11 = v4 + 5120;
    do
    {
      sde_reg_write(a1, v11, v8[v10 + 1] & 0x3FF | ((HIDWORD(v8[v10 + 1]) & 0x3FF) << 16), "(offset + j)");
      v12 = v10++ >= 127;
      v11 += 4;
    }
    while ( !v12 );
    sde_reg_write(a1, v4 + 564, 1u, "(base + PA_LUT_SWAP_OFF)");
    v13 = v9 | 0x180000;
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "Disable vlut feature\n");
    if ( (v9 & 0xFE0100E0) != 0 )
      v15 = -524289;
    else
      v15 = 31915807;
    v13 = v15 & v9;
  }
  return sde_reg_write(a1, v4, v13, "base");
}
