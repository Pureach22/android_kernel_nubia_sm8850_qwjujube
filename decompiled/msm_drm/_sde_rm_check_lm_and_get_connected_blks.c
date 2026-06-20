__int64 __fastcall sde_rm_check_lm_and_get_connected_blks(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        __int64 a4,
        __int64 *a5,
        __int64 *a6,
        _QWORD *a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 v15; // x19
  int v16; // w27
  unsigned __int64 v17; // x11
  __int16 v18; // w13
  __int16 v19; // w25
  int v20; // w4
  int v21; // w5
  int v22; // w6
  int v23; // w7
  __int16 v24; // w26
  unsigned __int64 v25; // x19
  unsigned __int64 v26; // x4
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x10
  bool v30; // w11
  int v31; // w9
  __int64 v32; // x5
  const char *v33; // x3
  __int64 v34; // x8
  int v35; // w6
  int v36; // w9
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x1
  __int64 v40; // x1
  char v41; // w0
  __int64 v43; // [xsp+18h] [xbp-38h]
  __int64 v44; // [xsp+20h] [xbp-30h]
  __int64 v46; // [xsp+30h] [xbp-20h] BYREF
  __int64 v47; // [xsp+38h] [xbp-18h]
  __int64 v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(*(_QWORD *)(a4 + 40) + 40LL);
  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  v16 = *((_DWORD *)a3 + 21);
  v17 = *(_QWORD *)(v15 + 32);
  v18 = v17;
  v19 = v17;
  if ( (_drm_debug & 4) != 0 )
  {
    v43 = v15;
    v44 = a8;
    v20 = *(_DWORD *)(v15 + 16);
    v21 = *(_DWORD *)(v15 + 56);
    v23 = *(_DWORD *)(v15 + 60);
    v22 = *(_DWORD *)(v15 + 64);
    v24 = v17;
    v25 = *(_QWORD *)(v15 + 32);
    _drm_dev_dbg(0, 0, 0, "check lm %d: dspp %d ds %d pp %d features %ld disp type %d\n", v20, v21, v22, v23, v17, v16);
    v17 = v25;
    v15 = v43;
    a8 = v44;
    v18 = v24;
  }
  if ( a8 )
  {
    v26 = *(unsigned int *)(v15 + 16);
    v27 = *(_QWORD *)(*(_QWORD *)(a8 + 40) + 40LL);
    if ( ((*(_QWORD *)(v27 + ((v26 >> 3) & 0x1FFFFFF8) + 80) >> v26) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "lm %d not peer of lm %d\n", v26, *(unsigned int *)(v27 + 16));
      goto LABEL_83;
    }
  }
  if ( (v17 & 0x60) == 0 )
  {
    v34 = *a3;
    v35 = *(_DWORD *)(v15 + 56);
    v36 = *(_DWORD *)(v15 + 64);
    if ( (~*(_DWORD *)a3 & 0xCLL) != 0 )
    {
      if ( (v34 & 4) != 0 )
      {
        if ( v35 == 5 )
          goto LABEL_41;
LABEL_32:
        if ( (v34 & 0x10) != 0 && (v17 & 0x80) == 0 || (v34 & 0x20) != 0 && (v17 & 0x100) == 0 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "fail: cwb/dcwb supported lm not allocated\n");
          goto LABEL_83;
        }
        if ( (v34 & 0x20) == 0 && (v17 & 0x100) != 0 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "fail: dcwb supported dummy lm incorrectly allocated\n");
          goto LABEL_83;
        }
        if ( a9 )
        {
          if ( (v34 & 0x20) != 0 && (v17 & 0x100) != 0 )
          {
            v37 = *(unsigned int *)(v15 + 16);
            v38 = __clz(__rbit32(a9)) + 1;
            if ( (((unsigned int)v37 ^ (unsigned int)v38) & 1) != 0 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "fail: dcwb:%d trying to match lm:%d\n", v37, v38);
              goto LABEL_83;
            }
          }
        }
        if ( (v34 & 0x100) != 0 && (v19 & 0x4000) == 0 )
          goto LABEL_17;
        if ( (v34 & 0x200) != 0 && (v18 & 0x8000) == 0 )
          goto LABEL_26;
        goto LABEL_55;
      }
      if ( (v34 & 8) == 0 )
        goto LABEL_32;
    }
    else if ( v35 == 5 )
    {
LABEL_41:
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "fail:lm(%d)req_dspp(%d)dspp(%d)req_ds(%d)ds(%d)\n",
          *(_DWORD *)(v15 + 16),
          ((unsigned int)v34 >> 2) & 1,
          v35,
          ((unsigned int)v34 >> 3) & 1,
          v36);
      goto LABEL_83;
    }
    if ( v36 == 5 )
      goto LABEL_41;
    goto LABEL_32;
  }
  v28 = *a3;
  if ( (*a3 & 0x200) == 0 )
  {
    v29 = (v17 >> 6) & 1;
    v30 = v16 != 1 && (v17 & 0x20) != 0;
    v31 = v16 == 2 ? 0 : v29;
    if ( v30 || v31 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "display preference is not met. display_type: %d lm_features: %lx\n",
          *((_DWORD *)a3 + 21),
          *(_QWORD *)(v15 + 32));
      goto LABEL_83;
    }
  }
  if ( (v28 & 0x100) != 0 && (v19 & 0x4000) == 0 )
  {
LABEL_17:
    if ( (_drm_debug & 4) != 0 )
    {
      v32 = *(unsigned int *)(v15 + 16);
      v33 = "cac primary preference is not met,cac_prim_pref: %d lm_id: %d\n";
LABEL_28:
      _drm_dev_dbg(0, 0, 0, v33, 0, v32);
      goto LABEL_83;
    }
    goto LABEL_83;
  }
  if ( (v28 & 0x200) != 0 && (v18 & 0x8000) == 0 )
  {
LABEL_26:
    if ( (_drm_debug & 4) != 0 )
    {
      v32 = *(unsigned int *)(v15 + 16);
      v33 = "cac loopback preference is not met,cac_lb_pref: %d lm_id: %d\n";
      goto LABEL_28;
    }
LABEL_83:
    v41 = 0;
    goto LABEL_84;
  }
LABEL_55:
  if ( (sde_rm_is_blk_available(a1, a4, a2, a3) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "lm %d already reserved\n", *(_DWORD *)(v15 + 16));
    goto LABEL_83;
  }
  if ( *(_DWORD *)(v15 + 56) != 5 )
  {
    v46 = 0;
    v47 = 0;
    v48 = 0x300000000LL;
    while ( (sde_rm_get_hw_locked(a1, (__int64)&v46, 1) & 1) != 0 )
    {
      v39 = v47;
      if ( *(_DWORD *)(v47 + 36) == *(_DWORD *)(v15 + 56) )
      {
        *a5 = v47;
        goto LABEL_64;
      }
    }
    v39 = *a5;
LABEL_64:
    if ( !v39 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "lm %d failed to retrieve dspp %d\n",
          *(unsigned int *)(a4 + 36),
          *(unsigned int *)(v15 + 56));
      goto LABEL_83;
    }
    if ( (sde_rm_is_blk_available(a1, v39, a2, a3) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "lm %d dspp %d already reserved\n",
          *(unsigned int *)(a4 + 36),
          *(unsigned int *)(*a5 + 36));
      goto LABEL_83;
    }
  }
  if ( *(_DWORD *)(v15 + 64) != 5 )
  {
    v46 = 0;
    v47 = 0;
    v48 = 0x400000000LL;
    while ( (sde_rm_get_hw_locked(a1, (__int64)&v46, 1) & 1) != 0 )
    {
      v40 = v47;
      if ( *(_DWORD *)(v47 + 36) == *(_DWORD *)(v15 + 64) )
      {
        *a6 = v47;
        goto LABEL_74;
      }
    }
    v40 = *a6;
LABEL_74:
    if ( !v40 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "lm %d failed to retrieve ds %d\n",
          *(unsigned int *)(a4 + 36),
          *(unsigned int *)(v15 + 64));
      goto LABEL_83;
    }
    if ( (sde_rm_is_blk_available(a1, v40, a2, a3) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "lm %d ds %d already reserved\n", *(unsigned int *)(a4 + 36), *(unsigned int *)(*a6 + 36));
      goto LABEL_83;
    }
  }
  v41 = sde_rm_reserve_pp(a1, a2, a3, v15, a4, a5, a6, a7);
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return v41 & 1;
}
