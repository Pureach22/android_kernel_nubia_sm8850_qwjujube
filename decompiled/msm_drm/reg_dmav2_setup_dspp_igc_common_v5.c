unsigned __int64 __fastcall reg_dmav2_setup_dspp_igc_common_v5(int *a1, _QWORD *a2, int a3)
{
  __int64 v4; // x8
  unsigned int v5; // w4
  _DWORD *v6; // x23
  int v7; // w8
  __int64 v8; // x24
  unsigned __int64 v11; // x21
  unsigned __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  unsigned __int64 i; // x22
  unsigned __int64 v18; // x8
  __int64 v19; // x9
  unsigned __int64 v20; // x10
  _DWORD *v21; // x11
  int v22; // w12
  int v23; // w9
  int v24; // w8
  int v25; // w8
  _DWORD *v26; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x10
  int v29; // w11
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  unsigned __int64 StatusReg; // x26
  __int64 v36; // x27

  if ( !a1 || !a2 )
    return _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
  v4 = (unsigned int)a1[16];
  v5 = a1[374];
  if ( !a2[2] || (unsigned int)v4 > 4 || v5 >= 2 )
    return _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v4, 2, v5);
  if ( &dspp_buf[2 * v4] == (unsigned __int64 *)-160LL )
    return _drm_err("invalid dma_buf\n");
  v6 = (_DWORD *)*a2;
  if ( *a2 )
  {
    v7 = *((_DWORD *)a2 + 2);
    if ( v7 == 4632 )
    {
      v8 = *(_QWORD *)v6;
      if ( (*(_QWORD *)v6 & 2LL) != 0 )
        v11 = 2316;
      else
        v11 = 1548;
      result = _kvmalloc_node_noprof(v11, 0, 3520, 0xFFFFFFFFLL);
      for ( i = result; result; *(_QWORD *)(StatusReg + 80) = v36 )
      {
        v18 = 0;
        v19 = 0;
        v20 = i + 4;
        v21 = v6;
        while ( v11 >= v18 )
        {
          if ( v11 + v19 < 2 )
            break;
          *(_WORD *)(i + v18) = v21[514];
          if ( v11 < v18 + 2 )
            break;
          if ( v11 + v19 - 2 < 2 )
            break;
          *(_WORD *)(v20 + v18 - 2) = v21[2];
          if ( v11 < v18 + 4 || v11 + v19 - 4 < 2 )
            break;
          v22 = v21[258];
          v19 -= 6;
          ++v21;
          *(_WORD *)(v20 + v18) = v22;
          v18 += 6LL;
          if ( v18 == 1536 )
          {
            if ( (v11 & 0xFFE) != 0x600 )
            {
              v23 = v6[773];
              if ( !v23 )
                LOWORD(v23) = -1;
              *(_WORD *)(i + 1536) = v23;
              if ( (v11 & 0xFFE) != 0x602 )
              {
                v24 = v6[771];
                if ( !v24 )
                  LOWORD(v24) = -1;
                *(_WORD *)(i + 1538) = v24;
                if ( (v11 & 0xFFE) != 0x604 )
                {
                  v25 = v6[772];
                  if ( !v25 )
                    LOWORD(v25) = -1;
                  *(_WORD *)(i + 1540) = v25;
                  if ( (v8 & 2) == 0 )
                  {
LABEL_39:
                    reg_dmav2_setup_dspp_igc_common((__int64)a1, (__int64)a2, v11, (int *)i, a3, v13, v14, v15, v16);
                    return kvfree(i);
                  }
                  v26 = v6 + 774;
                  v27 = v11 - 1546;
                  v28 = 1546;
                  while ( v11 >= v28 - 4 )
                  {
                    if ( v27 + 4 < 2 )
                      break;
                    *(_WORD *)(i + v28 - 4) = v26[256];
                    if ( v11 < v28 - 2 )
                      break;
                    if ( v27 >= 0xFFFFFFFFFFFFFFFELL )
                      break;
                    *(_WORD *)(i + v28 - 2) = *v26;
                    if ( v11 < v28 || v27 < 2 )
                      break;
                    v29 = v26[128];
                    v27 -= 6LL;
                    ++v26;
                    *(_WORD *)(i + v28) = v29;
                    v28 += 6LL;
                    if ( v28 == 2314 )
                      goto LABEL_39;
                  }
                }
              }
            }
            break;
          }
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v36 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &reg_dmav2_setup_dspp_igc_common_v5__alloc_tag;
        result = _kvmalloc_node_noprof(v11, 0, 3520, 0xFFFFFFFFLL);
        i = result;
      }
    }
    else
    {
      return _drm_err("invalid size of payload len %d exp %zd\n", v7, 0x1218u);
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav2_setup_dspp_igc_common_v5", 6151, -1, a1[16], a1[374], a1[7], 0, 239);
    return dspp_igcv4_off((__int64)a1, (__int64)a2, v31, v32, v33, v34);
  }
  return result;
}
