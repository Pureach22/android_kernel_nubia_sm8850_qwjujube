__int64 __fastcall sde_setup_dspp_memcol_prot_v17(_QWORD *a1, _DWORD *a2)
{
  __int64 result; // x0
  __int64 *v5; // x8
  int v6; // w20
  int v7; // w1
  __int64 v8; // x9
  int v9; // w8
  unsigned int v10; // w1
  int v11; // w8
  unsigned int v12; // w2

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  result = sde_reg_read((__int64)a1, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL));
  v5 = *(__int64 **)a2;
  v6 = result;
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable memcolor prot feature\n");
    v10 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    if ( (v6 & 0xFE0100E0) != 0 )
      v11 = -29753353;
    else
      v11 = 2686743;
    v12 = v11 & v6;
    return sde_reg_write((__int64)a1, v10, v12, "ctx->cap->sblk->hsic.base");
  }
  v7 = a2[2];
  if ( v7 != 48 )
    return _drm_err("invalid size of payload len %d exp %zd\n", v7, 0x30u);
  v8 = *v5;
  if ( !*v5 )
    return result;
  v9 = ((_DWORD)v8 << 15) & 0x40000 | ((v8 & 7) << 22) | ((((unsigned int)v8 >> 4) & 1) << 17);
  if ( (v8 & 0x20) != 0 )
  {
    v9 |= 8u;
    goto LABEL_16;
  }
  if ( v9 )
  {
LABEL_16:
    v10 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    v12 = result & 0xFE29FFF7 | v9 | 0x100000;
    return sde_reg_write((__int64)a1, v10, v12, "ctx->cap->sblk->hsic.base");
  }
  return result;
}
