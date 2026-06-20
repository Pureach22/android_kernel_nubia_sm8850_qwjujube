__int64 __fastcall sde_rm_reserve_dsc(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x27
  int v5; // w8
  __int64 v6; // x9
  __int64 v8; // x22
  __int64 v9; // x8
  bool v13; // w23
  __int64 *v14; // x25
  __int64 v15; // x10
  bool is_dsi_display; // w0
  _QWORD *v17; // x8
  _QWORD *v18; // x9
  int v19; // w10
  __int64 v20; // x12
  __int64 v21; // x10
  __int64 v22; // x10
  _QWORD *v23; // x9
  int v24; // w10
  __int64 v25; // x12
  unsigned int v26; // w28
  unsigned int v27; // w26
  int v28; // w6
  __int64 v29; // x8
  int v30; // w8
  signed int v31; // w24
  int v32; // w6
  int v33; // w9
  int v34; // w10
  unsigned int v35; // w24
  signed int v36; // w25
  int v37; // w8
  __int64 v38; // x22
  unsigned __int64 v39; // x21
  __int64 v40; // x8
  __int64 result; // x0
  int v42; // [xsp+0h] [xbp-120h]
  unsigned int v43; // [xsp+4h] [xbp-11Ch]
  __int64 v44; // [xsp+8h] [xbp-118h] BYREF
  __int64 v45; // [xsp+10h] [xbp-110h]
  __int64 v46; // [xsp+18h] [xbp-108h]
  __int64 v47; // [xsp+20h] [xbp-100h] BYREF
  __int64 v48; // [xsp+28h] [xbp-F8h]
  __int64 v49; // [xsp+30h] [xbp-F0h]
  __int64 v50; // [xsp+38h] [xbp-E8h] BYREF
  __int64 v51; // [xsp+40h] [xbp-E0h]
  __int64 v52; // [xsp+48h] [xbp-D8h]
  _QWORD v53[12]; // [xsp+50h] [xbp-D0h] BYREF
  _QWORD v54[14]; // [xsp+B0h] [xbp-70h] BYREF

  v54[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 104);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v5 = *(_DWORD *)(v4 + 4);
  memset(v54, 0, 96);
  memset(v53, 0, sizeof(v53));
  if ( v5 != 1 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "compression blk dsc not required\n");
    goto LABEL_98;
  }
  v6 = *(_QWORD *)(a3 + 8);
  v8 = *(unsigned int *)(v6 + 8);
  if ( !(_DWORD)v8 || v4 == -24 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid topoplogy params: %d, %d\n", (unsigned int)v8, v4 != -24);
    goto LABEL_98;
  }
  v9 = *a1;
  v13 = 0;
  v14 = *(__int64 **)(*a1 + 816LL);
  v15 = *a1 + 816LL;
  v47 = 0;
  v48 = 0;
  v49 = 0xA00000000LL;
  if ( v14 != (__int64 *)v15 )
  {
    do
    {
      if ( *((_DWORD *)v14 + 4) == *(_DWORD *)(a2 + 20) )
      {
        is_dsi_display = sde_encoder_is_dsi_display((_BOOL8)(v14 - 1));
        v9 = *a1;
        v13 = is_dsi_display;
      }
      v14 = (__int64 *)*v14;
    }
    while ( v14 != (__int64 *)(v9 + 816) );
    v6 = *(_QWORD *)(a3 + 8);
  }
  if ( *(_DWORD *)(v6 + 8) == 1 )
  {
    v50 = 0;
    v51 = 0;
    v52 = 0xA00000000LL;
    if ( (sde_rm_get_hw_locked((__int64)a1, (__int64)&v50, 1) & 1) != 0 )
    {
      while ( 1 )
      {
        v21 = *(_QWORD *)(v51 + 16);
        if ( !v21 || *(_DWORD *)(v21 + 20) == *(_DWORD *)(a2 + 20) )
        {
          v22 = *(_QWORD *)(v51 + 24);
          if ( (!v22 || *(_DWORD *)(v22 + 20) == *(_DWORD *)(a2 + 20))
            && !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v51 + 40) + 40LL) + 48LL) )
          {
            break;
          }
        }
        if ( (sde_rm_get_hw_locked((__int64)a1, (__int64)&v50, 1) & 1) == 0 )
          goto LABEL_16;
      }
      v43 = *(_DWORD *)(v51 + 36);
      v17 = a1 + 17;
      if ( v13 )
        goto LABEL_17;
LABEL_34:
      v23 = (_QWORD *)a1[18];
      if ( v23 == v17 )
        goto LABEL_43;
      v24 = 0;
      while ( 1 )
      {
        v25 = v23[3];
        if ( v25 && *(_DWORD *)(v25 + 16) == *(_DWORD *)(a2 + 16) )
        {
          if ( (unsigned __int64)(8LL * v24) > 0x60 || v24 == 12 )
          {
LABEL_42:
            __break(1u);
            goto LABEL_43;
          }
          v53[v24++] = v23;
        }
        v23 = (_QWORD *)v23[1];
        if ( v23 == v17 )
          goto LABEL_43;
      }
    }
  }
LABEL_16:
  v43 = 0;
  v17 = a1 + 17;
  if ( !v13 )
    goto LABEL_34;
LABEL_17:
  v18 = (_QWORD *)*v17;
  if ( (_QWORD *)*v17 != v17 )
  {
    v19 = 0;
    do
    {
      v20 = v18[3];
      if ( v20 && *(_DWORD *)(v20 + 16) == *(_DWORD *)(a2 + 16) )
      {
        if ( (unsigned __int64)(8LL * v19) > 0x60 || v19 == 12 )
          goto LABEL_42;
        v53[v19++] = v18;
      }
      v18 = (_QWORD *)*v18;
    }
    while ( v18 != v17 );
  }
LABEL_43:
  v26 = 0;
  v27 = 0;
  v42 = v8 - 2;
  while ( (sde_rm_get_hw_locked((__int64)a1, (__int64)&v47, v13) & 1) != 0 )
  {
    v30 = *(_DWORD *)(v48 + 36);
    if ( v13 )
      v31 = v27;
    else
      v31 = v8 + ~v27;
    if ( ((v26 >> v30) & 1) != 0 )
      goto LABEL_49;
    if ( a4 )
    {
      if ( v30 != *(unsigned __int8 *)(a4 + v31) )
        goto LABEL_49;
    }
    else if ( ((*(_BYTE *)(v4 + 152) & 1) != 0 || *(_BYTE *)(v4 + 153) == 1)
           && (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v48 + 40) + 40LL) + 32LL) & 0x10) == 0 )
    {
      goto LABEL_49;
    }
    if ( v27 >= 0xC )
      goto LABEL_101;
    if ( (sde_rm_check_dsc(a2, v48, 0, v53[v27], (unsigned int)v8, v43) & 1) != 0 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        if ( a4 )
          v32 = *(unsigned __int8 *)(a4 + v31);
        else
          v32 = -1;
        _drm_dev_dbg(0, 0, 0, "blk id = %d, _dsc_ids[%d] = %d\n", *(_DWORD *)(v48 + 36), v27, v32);
      }
      if ( v27 )
      {
        v33 = *(_DWORD *)(v48 + 36);
        v34 = *(_DWORD *)(v54[v27 - 1] + 36LL) - v33;
        if ( v34 < 0 )
          v34 = v33 - *(_DWORD *)(v54[v27 - 1] + 36LL);
        if ( v34 == 1 )
          v35 = v27;
        else
          v35 = 0;
        if ( v34 != 1 )
          v26 = 0;
      }
      else
      {
        v33 = *(_DWORD *)(v48 + 36);
        v35 = 0;
      }
      v27 = v35 + 1;
      v54[v35] = v48;
      if ( v35 + 1 == (_DWORD)v8 )
        goto LABEL_94;
      v44 = 0;
      v45 = 0;
      v26 |= 1 << v33;
      v46 = 0xA00000000LL;
      if ( (sde_rm_get_hw_locked((__int64)a1, (__int64)&v44, v13) & 1) != 0 )
      {
        if ( v13 )
          v36 = v35 + 1;
        else
          v36 = v42 - v35;
        while ( 1 )
        {
          v37 = *(_DWORD *)(v45 + 36);
          if ( ((v26 >> v37) & 1) == 0 && (!a4 || v37 == *(unsigned __int8 *)(a4 + v36)) )
          {
            if ( v35 == 11 )
              goto LABEL_101;
            if ( (sde_rm_check_dsc(a2, v45, v48, v53[v27], (unsigned int)v8, 0) & 1) != 0 )
              break;
          }
          if ( (sde_rm_get_hw_locked((__int64)a1, (__int64)&v44, v13) & 1) == 0 )
            goto LABEL_47;
        }
        if ( (_drm_debug & 4) != 0 )
        {
          if ( a4 )
            v28 = *(unsigned __int8 *)(a4 + v36);
          else
            v28 = -1;
          _drm_dev_dbg(0, 0, 0, "blk id = %d, _dsc_ids[%d] = %d\n", *(_DWORD *)(v45 + 36), v27, v28);
        }
        v29 = v45;
        v54[v27] = v45;
        v27 = v35 + 2;
        v26 |= 1 << *(_DWORD *)(v29 + 36);
      }
LABEL_47:
      if ( !v44 )
      {
        --v27;
        v26 &= ~(1 << *(_DWORD *)(v48 + 36));
      }
    }
LABEL_49:
    if ( v27 == (_DWORD)v8 )
      goto LABEL_93;
  }
  if ( v27 == (_DWORD)v8 )
  {
LABEL_93:
    if ( (int)v8 >= 1 )
    {
LABEL_94:
      v38 = 8 * v8;
      v39 = 0;
      while ( v39 != 96 )
      {
        v40 = v54[v39 / 8];
        if ( v40 )
        {
          *(_QWORD *)(v40 + 24) = a2;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_rm_reserve_dsc",
            1886,
            -1,
            *(_DWORD *)(v40 + 32),
            *(_DWORD *)(a2 + 20),
            *(_DWORD *)(v40 + 36),
            -1059143953,
            v42);
          v39 += 8LL;
          if ( v38 != v39 )
            continue;
        }
        goto LABEL_98;
      }
LABEL_101:
      __break(0x5512u);
    }
LABEL_98:
    result = 0;
  }
  else
  {
    printk(&unk_27A4D8, "_sde_rm_reserve_dsc");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
