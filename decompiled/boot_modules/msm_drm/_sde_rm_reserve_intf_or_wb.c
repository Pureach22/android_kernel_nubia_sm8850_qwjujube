__int64 __fastcall sde_rm_reserve_intf_or_wb(__int64 a1, __int64 a2, unsigned int a3, int a4, __int64 *a5)
{
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x8
  bool v15; // w13
  bool v16; // w27
  __int64 v17; // x28
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x9
  _BOOL4 v21; // w23
  _QWORD *v22; // x8
  int v23; // w0
  _BOOL4 v25; // w27
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x9
  _BOOL4 v29; // w24
  _QWORD *v30; // x8
  int v31; // w0
  __int64 result; // x0
  void *v33; // x0
  const char *v34; // x1
  char v35; // [xsp+0h] [xbp-50h]
  __int64 *v36; // [xsp+10h] [xbp-40h]
  __int64 v37; // [xsp+18h] [xbp-38h] BYREF
  __int64 v38; // [xsp+20h] [xbp-30h]
  int v39; // [xsp+28h] [xbp-28h]
  int v40; // [xsp+2Ch] [xbp-24h]
  __int64 v41; // [xsp+30h] [xbp-20h] BYREF
  _QWORD *v42; // [xsp+38h] [xbp-18h]
  __int64 v43; // [xsp+40h] [xbp-10h]
  __int64 v44; // [xsp+48h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v37 = 0;
  v40 = a4;
  while ( (sde_rm_get_hw_locked(a1, (__int64)&v37, 1) & 1) != 0 )
  {
    v10 = v38;
    if ( *(_DWORD *)(v38 + 36) == a3 )
    {
      v11 = *(_QWORD *)(v38 + 16);
      if ( v11 && *(_DWORD *)(v11 + 20) != *(_DWORD *)(a2 + 20)
        || (v12 = *(_QWORD *)(v38 + 24)) != 0 && *(_DWORD *)(v12 + 20) != *(_DWORD *)(a2 + 20) )
      {
        v33 = &unk_21DAD5;
        v34 = "_sde_rm_reserve_intf_or_wb";
        goto LABEL_66;
      }
      *(_QWORD *)(v38 + 24) = a2;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_rm_reserve_intf_or_wb",
        2086,
        -1,
        *(_DWORD *)(v10 + 32),
        *(_DWORD *)(a2 + 20),
        a3,
        -1059143953,
        v35);
      break;
    }
  }
  if ( !v37 )
  {
    printk(&unk_27D9E2, "_sde_rm_reserve_intf_or_wb");
    result = 4294967274LL;
    goto LABEL_61;
  }
  if ( (*((_BYTE *)a5 + 76) & 1) != 0 || (v13 = *a5, (*a5 & 0x80) != 0) )
  {
    v36 = a5;
    v42 = nullptr;
    v43 = 0x600000000LL;
    v41 = 0;
    if ( (sde_rm_get_hw_locked(a1, (__int64)&v41, 1) & 1) == 0 )
      goto LABEL_35;
    v15 = a3 != 5 && a4 == 9;
    v16 = a3 != 10 && a4 == 8 || v15;
    if ( a3 != 10 && a4 == 8 )
      v17 = 48;
    else
      v17 = 56;
    while ( 1 )
    {
      v18 = v42[2];
      v19 = *(_QWORD *)(v42[5] + 32LL);
      if ( v18 && *(_DWORD *)(v18 + 20) != *(_DWORD *)(a2 + 20) )
        goto LABEL_24;
      v20 = v42[3];
      if ( v20 )
      {
        if ( *(_DWORD *)(v20 + 20) != *(_DWORD *)(a2 + 20) )
          goto LABEL_24;
      }
      if ( v16 )
      {
        v21 = (*(_QWORD *)(v19 + v17 + 8 * ((unsigned __int64)a3 >> 6)) & (1LL << a3)) != 0;
        if ( (_drm_debug & 4) != 0 )
          goto LABEL_22;
      }
      else
      {
        v21 = 0;
        if ( (_drm_debug & 4) != 0 )
LABEL_22:
          _drm_dev_dbg(
            0,
            0,
            0,
            "type %d id %d, cdm intfs %lu wbs %lu match %d\n",
            a4,
            a3,
            *(_QWORD *)(v19 + 48),
            *(_QWORD *)(v19 + 56),
            v21);
      }
      if ( v21 )
      {
        v22 = v42;
        v23 = sde_dbg_base_evtlog;
        v42[3] = a2;
        sde_evtlog_log(
          v23,
          "_sde_rm_reserve_cdm",
          2055,
          -1,
          *((_DWORD *)v22 + 8),
          *(_DWORD *)(a2 + 20),
          *((_DWORD *)v22 + 9),
          -1059143953,
          v35);
LABEL_35:
        if ( v41 )
        {
          v13 = *v36;
          break;
        }
        v33 = &unk_26CBB9;
        v34 = "_sde_rm_reserve_cdm";
LABEL_66:
        printk(v33, v34);
        result = 4294967177LL;
        goto LABEL_61;
      }
LABEL_24:
      if ( (sde_rm_get_hw_locked(a1, (__int64)&v41, 1) & 1) == 0 )
        goto LABEL_35;
    }
  }
  if ( (v13 & 0x40) == 0 )
    goto LABEL_60;
  v42 = nullptr;
  v43 = 0xE00000000LL;
  v41 = 0;
  if ( (sde_rm_get_hw_locked(a1, (__int64)&v41, 1) & 1) == 0 )
    goto LABEL_59;
  v25 = a3 != 5 && a4 == 9;
  while ( 1 )
  {
    v26 = v42[2];
    v27 = v42[5];
    if ( v26 && *(_DWORD *)(v26 + 20) != *(_DWORD *)(a2 + 20) )
      goto LABEL_48;
    v28 = v42[3];
    if ( v28 )
    {
      if ( *(_DWORD *)(v28 + 20) != *(_DWORD *)(a2 + 20) )
        goto LABEL_48;
    }
    if ( v25 )
    {
      v29 = (*(_QWORD *)(*(_QWORD *)(v27 + 32) + 8 * ((unsigned __int64)a3 >> 6) + 56) & (1LL << a3)) != 0;
      if ( (_drm_debug & 4) != 0 )
        goto LABEL_46;
    }
    else
    {
      v29 = 0;
      if ( (_drm_debug & 4) != 0 )
LABEL_46:
        _drm_dev_dbg(
          0,
          0,
          0,
          "type %d id %d, dnsc_blur wbs %lu match %d\n",
          a4,
          a3,
          *(_QWORD *)(*(_QWORD *)(v27 + 32) + 56LL),
          v29);
    }
    if ( v29 )
      break;
LABEL_48:
    if ( (sde_rm_get_hw_locked(a1, (__int64)&v41, 1) & 1) == 0 )
      goto LABEL_59;
  }
  v30 = v42;
  v31 = sde_dbg_base_evtlog;
  v42[3] = a2;
  sde_evtlog_log(
    v31,
    "_sde_rm_reserve_dnsc_blur",
    2013,
    -1,
    *((_DWORD *)v30 + 8),
    *(_DWORD *)(a2 + 20),
    *((_DWORD *)v30 + 9),
    -1059143953,
    v35);
LABEL_59:
  if ( !v41 )
  {
    v33 = &unk_21DB28;
    v34 = "_sde_rm_reserve_dnsc_blur";
    goto LABEL_66;
  }
LABEL_60:
  result = 0;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
