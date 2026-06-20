__int64 __fastcall sde_setup_dspp_pa_hsic_v17(_QWORD *a1, _DWORD *a2)
{
  __int64 *v3; // x8
  int v4; // w1
  __int64 v5; // x9
  int v6; // w25
  int v7; // w24
  int v8; // w23
  int v10; // w22
  unsigned int v11; // w20
  int v12; // w21
  int v13; // w8
  int v14; // w8
  unsigned int v15; // w2
  unsigned int v16; // w20
  int v17; // w21
  unsigned int v18; // w2
  int v19; // w8
  unsigned int v20; // w20
  int v21; // w21
  unsigned int v22; // w2
  int v23; // w8
  unsigned int v24; // w20
  int v25; // w21
  unsigned int v26; // w2
  int v27; // w8

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v3 = *(__int64 **)a2;
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable pa hsic feature\n");
    v6 = 0;
    v7 = 0;
    v8 = 0;
    goto LABEL_12;
  }
  v4 = a2[2];
  if ( v4 != 24 )
    return _drm_err("invalid size of payload len %d exp %zd\n", v4, 0x18u);
  v5 = *v3;
  if ( (*v3 & 1) != 0 )
  {
    v6 = *((_DWORD *)v3 + 2);
    if ( (v5 & 2) != 0 )
    {
LABEL_7:
      v7 = *((_DWORD *)v3 + 3);
      if ( (v5 & 4) != 0 )
        goto LABEL_8;
      goto LABEL_16;
    }
  }
  else
  {
    v6 = 0;
    if ( (v5 & 2) != 0 )
      goto LABEL_7;
  }
  v7 = 0;
  if ( (v5 & 4) != 0 )
  {
LABEL_8:
    v8 = *((_DWORD *)v3 + 4);
    if ( (v5 & 8) != 0 )
      goto LABEL_17;
    goto LABEL_12;
  }
LABEL_16:
  v8 = 0;
  if ( (v5 & 8) != 0 )
  {
LABEL_17:
    v10 = *((_DWORD *)v3 + 5);
    goto LABEL_18;
  }
LABEL_12:
  v10 = 0;
LABEL_18:
  v11 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
  v12 = sde_reg_read((__int64)a1, v11);
  sde_reg_write((__int64)a1, v11 + 28, v6 & 0xFFF, "base + offset");
  if ( (v12 & 0xFC0100E0) != 0 )
    v13 = -33554433;
  else
    v13 = -34603009;
  v14 = v13 & v12;
  if ( v6 )
    v15 = v12 | 0x2100000;
  else
    v15 = v14;
  sde_reg_write((__int64)a1, v11, v15, "base");
  v16 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
  v17 = sde_reg_read((__int64)a1, v16);
  sde_reg_write((__int64)a1, v16 + 32, (unsigned __int16)v7, "base + offset");
  if ( v7 )
  {
    v18 = v17 | 0x4100000;
  }
  else
  {
    if ( (v17 & 0xFA0100E0) != 0 )
      v19 = -67108865;
    else
      v19 = -68157441;
    v18 = v19 & v17;
  }
  sde_reg_write((__int64)a1, v16, v18, "base");
  v20 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
  v21 = sde_reg_read((__int64)a1, v20);
  sde_reg_write((__int64)a1, v20 + 36, (unsigned __int8)v8, "base + offset");
  if ( v8 )
  {
    v22 = v21 | 0x8100000;
  }
  else
  {
    if ( (v21 & 0xF60100E0) != 0 )
      v23 = -134217729;
    else
      v23 = -135266305;
    v22 = v23 & v21;
  }
  sde_reg_write((__int64)a1, v20, v22, "base");
  v24 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
  v25 = sde_reg_read((__int64)a1, v24);
  sde_reg_write((__int64)a1, v24 + 40, (unsigned __int8)v10, "base + offset");
  if ( v10 )
  {
    v26 = v25 | 0x10100000;
  }
  else
  {
    if ( (v25 & 0xEE0100E0) != 0 )
      v27 = -268435457;
    else
      v27 = -269484033;
    v26 = v27 & v25;
  }
  return sde_reg_write((__int64)a1, v24, v26, "base");
}
