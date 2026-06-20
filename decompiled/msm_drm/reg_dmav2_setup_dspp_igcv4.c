_WORD *__fastcall reg_dmav2_setup_dspp_igcv4(int *a1, _QWORD *a2)
{
  __int64 v3; // x2
  unsigned int v4; // w4
  _DWORD *v5; // x20
  int v6; // w8
  _WORD *result; // x0
  __int64 v9; // x8
  _WORD *v10; // x9
  _WORD *v11; // x11
  __int16 v12; // w10
  int v13; // w8
  __int16 v14; // w9
  int v15; // w9
  __int16 v16; // w9
  int v17; // w9
  _WORD *v18; // x20
  __int16 v19; // w8

  if ( !a1 || !a2 )
    return (_WORD *)_drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
  v3 = (unsigned int)a1[16];
  v4 = a1[374];
  if ( !a2[2] || (unsigned int)v3 > 4 || v4 >= 2 )
    return (_WORD *)_drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v3, 2, v4);
  if ( &dspp_buf[2 * v3] == (unsigned __int64 *)-160LL )
    return (_WORD *)_drm_err("invalid dma_buf\n");
  v5 = (_DWORD *)*a2;
  if ( *a2 )
  {
    v6 = *((_DWORD *)a2 + 2);
    if ( v6 == 4632 )
    {
      result = (_WORD *)_kvmalloc_node_noprof(1548, 0, 3520, 0xFFFFFFFFLL);
      if ( result )
      {
        v9 = 2;
        v10 = v5;
        do
        {
          v11 = &result[v9];
          v9 += 3;
          *(v11 - 2) = 16 * v10[1028];
          *(v11 - 1) = 16 * v10[4];
          v12 = v10[516];
          v10 += 2;
          *v11 = 16 * v12;
        }
        while ( v9 != 770 );
        v13 = v5[773];
        v14 = 16 * v13;
        if ( !v13 )
          v14 = -16;
        result[768] = v14;
        v15 = v5[771];
        if ( v15 )
          v16 = 16 * v15;
        else
          v16 = -16;
        result[769] = v16;
        v17 = v5[772];
        v18 = result;
        if ( v17 )
          v19 = 16 * v17;
        else
          v19 = -16;
        result[770] = v19;
        reg_dmav2_setup_dspp_igc_common(a1, a2, 1548, result, 0);
        return (_WORD *)kvfree(v18);
      }
    }
    else
    {
      return (_WORD *)_drm_err("invalid size of payload len %d exp %zd\n", v6, 0x1218u);
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav2_setup_dspp_igcv4", 6097, -1, a1[16], a1[374], a1[7], 0, 239);
    return (_WORD *)dspp_igcv4_off(a1, a2);
  }
  return result;
}
