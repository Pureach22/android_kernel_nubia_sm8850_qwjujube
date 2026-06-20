__int64 __fastcall sde_rm_reserve_ctls(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  unsigned int v6; // w8
  unsigned int v12; // w24
  __int64 v13; // x9
  __int64 v14; // x27
  __int64 v15; // x9
  int v16; // w4
  int v17; // w4
  int v18; // w5
  char v19; // w9
  __int64 v20; // x8
  int v21; // w6
  __int64 i; // x22
  __int64 v23; // x8
  int v24; // w0
  __int64 result; // x0
  char v26; // [xsp+0h] [xbp-A0h]
  __int64 v27; // [xsp+8h] [xbp-98h] BYREF
  __int64 v28; // [xsp+10h] [xbp-90h]
  __int64 v29; // [xsp+18h] [xbp-88h]
  __int64 v30; // [xsp+20h] [xbp-80h] BYREF
  __int64 v31; // [xsp+28h] [xbp-78h]
  __int64 v32; // [xsp+30h] [xbp-70h]
  __int64 v33; // [xsp+38h] [xbp-68h]
  __int64 v34; // [xsp+40h] [xbp-60h]
  __int64 v35; // [xsp+48h] [xbp-58h]
  __int64 v36; // [xsp+50h] [xbp-50h]
  __int64 v37; // [xsp+58h] [xbp-48h]
  __int64 v38; // [xsp+60h] [xbp-40h]
  __int64 v39; // [xsp+68h] [xbp-38h]
  __int64 v40; // [xsp+70h] [xbp-30h]
  __int64 v41; // [xsp+78h] [xbp-28h]
  __int64 v42; // [xsp+80h] [xbp-20h]
  __int64 v43; // [xsp+88h] [xbp-18h]
  __int64 v44; // [xsp+90h] [xbp-10h]
  __int64 v45; // [xsp+98h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a4 + 16);
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  if ( !v5 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid number of ctl: %d\n", 0);
LABEL_43:
    result = 0;
    goto LABEL_45;
  }
  v6 = *(_DWORD *)(a2 + 20);
  v12 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v27 = 0;
  v28 = 0;
  v29 = v6 | 0x500000000LL;
  v31 = 0;
  v32 = 0x500000000LL;
  v30 = 0;
  while ( (sde_rm_get_hw_locked(a1, (__int64)&v30, 1) & 1) != 0 )
  {
    v13 = *(_QWORD *)(v31 + 16);
    v14 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v31 + 40) + 72LL) + 32LL);
    if ( !v13 || *(_DWORD *)(v13 + 20) == *(_DWORD *)(a2 + 20) )
    {
      v15 = *(_QWORD *)(v31 + 24);
      if ( !v15 || *(_DWORD *)(v15 + 20) == *(_DWORD *)(a2 + 20) )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "ctl %d caps 0x%lX\n", *(_DWORD *)(v31 + 36), v14);
        if ( a5 || (v14 & 8) != 0 )
        {
          if ( a5 )
            goto LABEL_21;
          v16 = *(_DWORD *)(a3 + 84);
          if ( v16 == 1 || (*(_BYTE *)(a3 + 1) & 2) != 0 )
            goto LABEL_21;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "display pref not met. display_type: %d primary_pref: %d\n",
              v16,
              (unsigned __int64)(v14 & 8) >> 3);
        }
        else if ( (((unsigned int)v14 >> 1) & 1) == *(_BYTE *)(a4 + 20) && (*(_DWORD *)a4 != 10 || (v14 & 4) != 0) )
        {
LABEL_21:
          if ( (sde_rm_get_hw_locked(a1, (__int64)&v27, 1) & 1) != 0
            && (v17 = *(_DWORD *)(v28 + 36), v18 = *(_DWORD *)(v31 + 36), v17 != v18) )
          {
            sde_evtlog_log(sde_dbg_base_evtlog, "_sde_rm_reserve_ctls", 1609, -1, v17, v18, 13107, -1059143953, v26);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "ctl in use:%d avoiding new:%d\n", *(_DWORD *)(v28 + 36), *(_DWORD *)(v31 + 36));
          }
          else
          {
            if ( v12 >= 0xC )
              __break(0x5512u);
            v19 = _drm_debug;
            v20 = v31;
            *(&v33 + v12) = v31;
            if ( (v19 & 4) != 0 )
            {
              if ( a5 )
                v21 = *(unsigned __int8 *)(a5 + v12);
              else
                v21 = -1;
              _drm_dev_dbg(0, 0, 0, "blk id = %d, _ctl_ids[%d] = %d\n", *(_DWORD *)(v20 + 36), v12, v21);
            }
            if ( !a5 || *(_DWORD *)(*(&v33 + v12) + 36) == *(unsigned __int8 *)(a5 + v12) )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "ctl %d match\n", *(_DWORD *)(v31 + 36));
              if ( ++v12 == *(_DWORD *)(a4 + 16) )
                break;
            }
          }
        }
      }
    }
  }
  if ( v12 == *(_DWORD *)(a4 + 16) )
  {
    for ( i = 0; i != 12; ++i )
    {
      if ( i >= *(int *)(a4 + 16) )
        break;
      v23 = *(&v33 + i);
      v24 = sde_dbg_base_evtlog;
      *(_QWORD *)(v23 + 24) = a2;
      sde_evtlog_log(
        v24,
        "_sde_rm_reserve_ctls",
        1634,
        -1,
        *(_DWORD *)(v23 + 32),
        *(_DWORD *)(a2 + 20),
        *(_DWORD *)(v23 + 36),
        -1059143953,
        v26);
    }
    goto LABEL_43;
  }
  result = 4294967177LL;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
