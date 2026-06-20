__int64 __fastcall hfi_kick_off_v1(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  int v5; // w1
  __int64 v6; // x8
  int *v7; // x0
  int v8; // w2
  __int64 v9; // x10
  unsigned int v10; // w0
  unsigned int v11; // w4
  unsigned int v12; // w19
  long double v13; // q0
  int v14; // w10
  unsigned int v15; // w11
  unsigned int v16; // w10
  unsigned int v17; // w10
  unsigned int v18; // w10
  char *v19; // x21
  unsigned int v20; // w20
  __int64 v21; // x8
  int *v22; // x0
  int v23; // w1
  __int64 v24; // x9
  unsigned int v25; // w0
  __int64 v26; // x1
  unsigned int v27; // w10
  unsigned int v28; // w10
  __int64 src; // [xsp+8h] [xbp-18h] BYREF
  int v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (*)(void))validate_kick_off_v1)();
  if ( (_DWORD)result )
    goto LABEL_10;
  v30 = 0;
  src = 0;
  if ( !a1 || a2 >= 2 )
  {
    _drm_err("invalid params cfg - %p, dpu idx %d\n", (const void *)a1, a2);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v5 = *(_DWORD *)(a1 + 56);
  if ( (v5 & 0xF0FFFu) - 196865 <= 0xFD )
  {
    v6 = *(_QWORD *)(a1 + 16);
    v7 = *(int **)(a1 + 48);
    v8 = *(_DWORD *)(a1 + 60);
    v9 = *(_QWORD *)(v6 + 24);
    LODWORD(v6) = *(_DWORD *)(v6 + 20);
    LODWORD(src) = *(_DWORD *)(a1 + 64);
    HIDWORD(src) = v9;
    v30 = v6;
    v10 = hfi_util_u32_prop_helper_add_prop_by_obj(v7, v5, v8, 2, &src, 0xCu);
    v11 = *(_DWORD *)(a1 + 56);
    if ( !v10 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "successfully added SSPP feature: 0x%x flag %u iova %x len %x\n",
        v11,
        *(_DWORD *)(a1 + 64),
        HIDWORD(src),
        v30);
      result = 0;
      goto LABEL_10;
    }
    v12 = v10;
    _drm_err("error adding hfi property: %d error: %d\n", v11, v10);
    goto LABEL_7;
  }
  if ( (v5 & 0xF0FFFu) - 131329 > 0xFD )
  {
    _drm_err("unsupported prop_id %d\n", v5);
    goto LABEL_9;
  }
  *(double *)&v13 = _drm_dev_dbg(
                      0,
                      0,
                      0,
                      "DSPP feature 0x%x flag %u dspp_idx %d start_idx %d num_mixers %d\n",
                      v5,
                      *(_DWORD *)(a1 + 64),
                      *(_DWORD *)(a1 + 76),
                      *(_DWORD *)(a1 + 72),
                      *(_DWORD *)(a1 + 68));
  v14 = *(_DWORD *)(a1 + 64);
  if ( (v14 & 2) != 0 )
  {
    v21 = *(_QWORD *)(a1 + 16);
    v22 = *(int **)(a1 + 48);
    v23 = *(_DWORD *)(a1 + 56);
    v24 = *(_QWORD *)(v21 + 24);
    LODWORD(v21) = *(_DWORD *)(v21 + 20);
    LODWORD(src) = *(_DWORD *)(a1 + 64);
    HIDWORD(src) = v24;
    v30 = v21;
    v25 = hfi_util_u32_prop_helper_add_prop(v22, v23, 2, &src, 0xCu);
    if ( !v25 )
    {
      _drm_dev_dbg(0, 0, 0, "broadcast feature: added to prop_helper\n");
      result = 0;
      goto LABEL_10;
    }
    v26 = *(unsigned int *)(a1 + 56);
    v12 = v25;
    _drm_err("Failed to add hfi prop %d ret %d\n", v26, v25);
LABEL_7:
    result = v12;
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = *(_DWORD *)(a1 + 76);
  if ( v15 != *(_DWORD *)(a1 + 72) + *(_DWORD *)(a1 + 68) - 1 )
  {
    if ( v15 <= 4 )
    {
      if ( 12LL * v15 + 60 * (unsigned __int64)a2 > 0x77 )
        goto LABEL_38;
      hfi_cfg_cached[15 * a2 + 3 * v15] = v14;
      v27 = *(_DWORD *)(a1 + 76);
      if ( v27 <= 4 )
      {
        if ( 12LL * v27 + 60 * (unsigned __int64)a2 > 0x73 )
          goto LABEL_38;
        hfi_cfg_cached[15 * a2 + 1 + 3 * v27] = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 24LL);
        v28 = *(_DWORD *)(a1 + 76);
        if ( v28 <= 4 )
        {
          if ( 12LL * v28 + 60 * (unsigned __int64)a2 <= 0x6F )
          {
            hfi_cfg_cached[15 * a2 + 2 + 3 * v28] = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 20LL);
            _drm_dev_dbg(0, 0, 0, "non-broadcast feature: copied to hfi_cfg_cached[%d]\n", a2);
            result = 0;
            goto LABEL_10;
          }
          goto LABEL_38;
        }
      }
    }
LABEL_37:
    __break(0x5512u);
    goto LABEL_38;
  }
  if ( v15 > 4 )
    goto LABEL_37;
  if ( 12LL * v15 + 60 * (unsigned __int64)a2 > 0x77 )
    goto LABEL_38;
  hfi_cfg_cached[15 * a2 + 3 * v15] = v14;
  v16 = *(_DWORD *)(a1 + 76);
  if ( v16 > 4 )
    goto LABEL_37;
  if ( 12LL * v16 + 60 * (unsigned __int64)a2 > 0x73 )
    goto LABEL_38;
  hfi_cfg_cached[15 * a2 + 1 + 3 * v16] = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 24LL);
  v17 = *(_DWORD *)(a1 + 76);
  if ( v17 > 4 )
    goto LABEL_37;
  if ( 12LL * v17 + 60 * (unsigned __int64)a2 <= 0x6F )
  {
    hfi_cfg_cached[15 * a2 + 2 + 3 * v17] = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 20LL);
    v18 = *(_DWORD *)(a1 + 72);
    if ( v18 <= 5 )
    {
      v19 = (char *)&hfi_cfg_cached[15 * a2];
      v20 = hfi_util_u32_prop_helper_add_prop(
              *(int **)(a1 + 48),
              *(_DWORD *)(a1 + 56),
              2,
              &v19[12 * v18],
              (unsigned int)(12 * *(_DWORD *)(a1 + 68)));
      if ( v20 )
        _drm_err("Failed to add hfi prop %d ret %d\n", *(_DWORD *)(a1 + 56), v20);
      else
        _drm_dev_dbg(0, 0, 0, "non-broadcast feature: submitted to prop_helper\n");
      *((_DWORD *)v19 + 14) = 0;
      result = v20;
      *((_QWORD *)v19 + 5) = 0;
      *((_QWORD *)v19 + 6) = 0;
      *((_QWORD *)v19 + 3) = 0;
      *((_QWORD *)v19 + 4) = 0;
      *((_QWORD *)v19 + 1) = 0;
      *((_QWORD *)v19 + 2) = 0;
      *(_QWORD *)v19 = 0;
      goto LABEL_10;
    }
    goto LABEL_37;
  }
LABEL_38:
  __break(1u);
  return reset_v1(v13);
}
