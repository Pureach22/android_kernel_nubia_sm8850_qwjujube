__int64 __fastcall sde_core_perf_crtc_update_llcc(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x27
  int v4; // w8
  int v5; // w6
  int v6; // w7
  int v7; // w6
  int v8; // w7
  int v9; // w6
  int v10; // w7
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x8
  int v14; // w22
  __int64 v15; // x8
  __int64 *v16; // x24
  int v17; // w26
  __int64 v18; // x9
  int v19; // w6
  _BOOL4 v20; // w26
  __int64 v21; // x8
  int v22; // w6
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x22
  int slice_id; // w24
  const char *v26; // x4
  __int64 result; // x0
  void *v28; // x0
  void *v29; // x0
  __int64 v30; // [xsp+8h] [xbp-18h]
  int v31; // [xsp+10h] [xbp-10h]
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v30 = 0;
  if ( !a1 )
  {
    v29 = &unk_25E167;
LABEL_82:
    result = printk(v29, "sde_core_perf_crtc_update_llcc");
    goto LABEL_83;
  }
  if ( !*a1 || (v2 = *(_QWORD *)(*a1 + 56)) == 0 )
  {
    v28 = &unk_231B33;
LABEL_80:
    printk(v28, "_sde_crtc_get_kms");
    goto LABEL_81;
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v28 = &unk_234896;
    goto LABEL_80;
  }
  if ( !*(_QWORD *)(v3 + 152) )
  {
LABEL_81:
    v29 = &unk_234896;
    goto LABEL_82;
  }
  mutex_lock(&sde_core_perf_lock);
  v4 = *(_DWORD *)(v3 + 2112);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 2) != 0 )
      goto LABEL_10;
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "system cache[%d] is disabled from debugfs\n", 0);
    *((_BYTE *)a1 + 7560) = 0;
    v4 = *(_DWORD *)(v3 + 2112);
    if ( (v4 & 2) != 0 )
    {
LABEL_10:
      if ( (v4 & 4) == 0 )
        goto LABEL_11;
      goto LABEL_19;
    }
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "system cache[%d] is disabled from debugfs\n", 1);
  *((_BYTE *)a1 + 7561) = 0;
  if ( (*(_DWORD *)(v3 + 2112) & 4) == 0 )
  {
LABEL_11:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "system cache[%d] is disabled from debugfs\n", 2);
    *((_BYTE *)a1 + 7562) = 0;
    if ( (*((_BYTE *)a1 + 172) & 1) == 0 )
      goto LABEL_14;
    goto LABEL_20;
  }
LABEL_19:
  if ( (*((_BYTE *)a1 + 172) & 1) == 0 )
  {
LABEL_14:
    v30 = 0x100000001LL;
    goto LABEL_32;
  }
LABEL_20:
  v5 = *((unsigned __int8 *)a1 + 7560);
  v6 = *((unsigned __int8 *)a1 + 7472);
  if ( v5 != v6 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "crtc=%d llcc=%d new=%d old=%d", *((_DWORD *)a1 + 28), 0, v5, v6);
      LOBYTE(v5) = *((_BYTE *)a1 + 7560);
    }
    *((_BYTE *)a1 + 7472) = v5;
    LODWORD(v30) = 1;
  }
  v7 = *((unsigned __int8 *)a1 + 7561);
  v8 = *((unsigned __int8 *)a1 + 7473);
  if ( v7 != v8 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "crtc=%d llcc=%d new=%d old=%d", *((_DWORD *)a1 + 28), 1, v7, v8);
      LOBYTE(v7) = *((_BYTE *)a1 + 7561);
    }
    *((_BYTE *)a1 + 7473) = v7;
    HIDWORD(v30) = 1;
  }
  v9 = *((unsigned __int8 *)a1 + 7562);
  v10 = *((unsigned __int8 *)a1 + 7474);
  if ( v9 == v10 )
    goto LABEL_33;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "crtc=%d llcc=%d new=%d old=%d", *((_DWORD *)a1 + 28), 2, v9, v10);
    LOBYTE(v9) = *((_BYTE *)a1 + 7562);
  }
  *((_BYTE *)a1 + 7474) = v9;
LABEL_32:
  v31 = 1;
LABEL_33:
  v11 = 0;
  v12 = v3 + 2094;
  do
  {
    if ( !*((_DWORD *)&v30 + v11) )
      goto LABEL_35;
    v13 = a1[251];
    if ( v13 )
      v14 = 2 * (*(_QWORD *)(v13 + 472) != 0);
    else
      v14 = 0;
    if ( ((*(_QWORD *)(*(_QWORD *)(v3 + 1976) + 21696LL) >> v11) & 1) != 0 )
    {
      v15 = *a1;
      v16 = *(__int64 **)(*a1 + 864);
      if ( v16 == (__int64 *)(*a1 + 864) )
      {
        v20 = 0;
      }
      else
      {
        v17 = 0;
        do
        {
          if ( v16 != &qword_10 && *((_BYTE *)v16 + 156) )
          {
            if ( *(_DWORD *)(v3 + 2088) != 2 || *(_BYTE *)(v3 + 2092) != 1 )
              goto LABEL_51;
            v18 = v16[249];
            if ( v18 )
              LODWORD(v18) = 2 * (*(_QWORD *)(v18 + 472) != 0);
            if ( (_DWORD)v18 == v14 )
            {
LABEL_51:
              v19 = *((unsigned __int8 *)v16 + v11 + 7456);
              v17 |= v19;
              if ( (_drm_debug & 4) != 0 )
              {
                _drm_dev_dbg(0, 0, 0, "crtc=%d type:%d llcc:%u active:0x%x\n", *((_DWORD *)v16 + 24), v11, v19, v17);
                v15 = *a1;
              }
            }
          }
          v16 = (__int64 *)*v16;
        }
        while ( v16 != (__int64 *)(v15 + 864) );
        v20 = v17 != 0;
      }
      v21 = *(_QWORD *)(v3 + 136);
      if ( !v21 || !*(_QWORD *)(v21 + 8) )
      {
        printk(&unk_25EA5D, "_sde_core_perf_activate_llcc");
LABEL_74:
        printk(&unk_23523E, "_sde_core_perf_activate_llcc");
        goto LABEL_35;
      }
      v22 = *(unsigned __int8 *)(v12 + v11);
      if ( v20 )
      {
        if ( (v22 & 1) != 0 )
          goto LABEL_71;
      }
      else if ( (v22 & 1) == 0 )
      {
LABEL_71:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "skip llcc type:%d request:%d state:%d\n", v11, v20, v22);
        goto LABEL_35;
      }
      v23 = llcc_slice_getd(*(unsigned int *)(*(_QWORD *)(v3 + 152) + 24 * v11 + 21632));
      if ( !v23 || (v24 = v23, v23 >= 0xFFFFFFFFFFFFF001LL) )
      {
        printk(&unk_22E387, "_sde_core_perf_activate_llcc");
        goto LABEL_74;
      }
      slice_id = llcc_get_slice_id(v23);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_core_perf_activate_llcc",
        468,
        -1,
        v20,
        v11,
        *(unsigned __int8 *)(v12 + v11),
        slice_id,
        239);
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v20 )
          v26 = (const char *)&unk_229BD3;
        else
          v26 = "de";
        _drm_dev_dbg(
          0,
          0,
          0,
          "%sactivate the llcc type:%d state:%d scid:%d\n",
          v26,
          v11,
          *(unsigned __int8 *)(v12 + v11),
          slice_id);
      }
      if ( v20 )
      {
        llcc_slice_activate(v24);
        *(_BYTE *)(v12 + v11) = 1;
      }
      else
      {
        llcc_slice_deactivate(v24);
        *(_BYTE *)(v12 + v11) = 0;
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "system cache %d is not enabled!. Won't use\n", v11);
    }
LABEL_35:
    ++v11;
  }
  while ( v11 != 3 );
  result = mutex_unlock(&sde_core_perf_lock);
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
