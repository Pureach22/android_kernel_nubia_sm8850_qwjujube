__int64 __fastcall sde_vbif_set_ot_limit(__int64 result, unsigned int *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned int v7; // w8
  unsigned int v8; // w8
  __int64 v9; // x21
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned __int64 v12; // x10
  __int64 v13; // x11
  int v14; // w22
  int v15; // w4
  _BOOL4 v16; // w5
  __int64 v17; // x8
  __int64 v18; // x24
  int v19; // w7
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x1
  __int64 v23; // x10
  int v24; // w22
  __int64 v25; // x11
  __int64 v26; // x7
  unsigned int v27; // w8
  unsigned int v28; // w6
  unsigned int *v29; // x11
  __int64 v30; // x10
  _DWORD *v31; // x11
  unsigned int v32; // w23
  __int64 v33; // x8
  unsigned int (__fastcall *v34)(__int64, __int64, __int64); // x8
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x8
  _DWORD *v38; // x8
  __int64 v39; // x1
  int v40; // w22
  __int64 v41; // x2
  __int64 v42; // x8
  void (__fastcall *v43)(__int64, __int64, __int64); // x8
  __int64 v44; // x1
  int v45; // w7
  __int64 v46; // x8
  _DWORD *v47; // x8
  __int64 v48; // x1
  char v49; // [xsp+0h] [xbp-20h]
  char v50; // [xsp+0h] [xbp-20h]

  if ( !result )
    return printk(&unk_26FEB0, "sde_vbif_set_ot_limit");
  v4 = *(_QWORD *)(result + 152);
  v5 = result;
  if ( (*(_QWORD *)(v4 + 22008) & 0x100000000LL) != 0 && v4 )
  {
    mutex_lock(result + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x400000000LL) != 0
      && *(_DWORD *)(v5 + 3664) == 1
      && (v7 = *(_DWORD *)(v5 + 3656), v7 <= 6)
      && ((1 << v7) & 0x64) != 0
      || (v8 = *(_DWORD *)(v5 + 3656), v8 <= 4) && ((1 << v8) & 0x1A) != 0 )
    {
      result = mutex_unlock(v5 + 3696);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(0, 0, 0, "vbif operations not permitted\n");
      return result;
    }
    result = mutex_unlock(v5 + 3696);
  }
  v9 = *(_QWORD *)(v5 + 3512);
  v10 = *(_QWORD *)(v5 + 3528);
  if ( !v9 || *(_DWORD *)(v9 + 32) != a2[6] )
  {
    v9 = *(_QWORD *)(v5 + 3520);
    if ( !v9 || *(_DWORD *)(v9 + 32) != a2[6] )
    {
      v15 = 0;
      v16 = v10 != 0;
      goto LABEL_26;
    }
  }
  if ( !v10 )
  {
    v16 = 0;
    v15 = 1;
LABEL_26:
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "invalid arguments vbif %d mdp %d\n", v15, v16);
    return result;
  }
  v11 = a2[7];
  if ( (unsigned int)(v11 - 1) > 0x12 )
    return result;
  v12 = *(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x8000000000LL;
  if ( v12 )
  {
    if ( !*(_QWORD *)(v5 + 32 * v11 + 2888) )
    {
LABEL_22:
      if ( (_drm_debug & 4) == 0 )
        return result;
      v14 = 0;
      goto LABEL_32;
    }
  }
  else
  {
    v13 = *(unsigned int *)(v10 + 28);
    if ( (unsigned int)v13 > 2 )
      goto LABEL_86;
    if ( !*(_QWORD *)(v10 + 8 * v13 + 152) )
      goto LABEL_22;
  }
  if ( (_drm_debug & 4) == 0 )
    goto LABEL_33;
  v14 = 1;
LABEL_32:
  result = _drm_dev_dbg(0, 0, 0, "split_vbif:%d type:%s supported:%d\n", v12 >> 39, sde_clk_ctrl_type_s[v11], v14);
  if ( !v14 )
    return result;
LABEL_33:
  v17 = *(unsigned int *)(v9 + 28);
  if ( (unsigned int)v17 > 2 )
    goto LABEL_86;
  if ( *(_QWORD *)(v9 + 48 + 8 * v17) )
  {
    v18 = v9 + 96;
    if ( *(_QWORD *)(v9 + 96 + 8 * v17) )
    {
      if ( (*(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x100000000000LL) == 0 )
      {
        mutex_lock(v9 + 288);
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "sde_vbif_set_ot_limit",
                   354,
                   4,
                   *(_DWORD *)(v9 + 32),
                   *a2,
                   -1059143953,
                   v19,
                   v49);
        v20 = *(unsigned int *)(v9 + 28);
        if ( (unsigned int)v20 > 2 )
          goto LABEL_86;
        v21 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 8 * v20 + 264);
        if ( v21 && (a2[5] & 1) == 0 )
        {
          v22 = *a2;
          if ( *((_DWORD *)v21 - 1) != 409794976 )
            __break(0x8228u);
          result = v21(v9, v22);
        }
        v23 = *(_QWORD *)(v9 + 40);
        if ( !v23 )
        {
          printk(&unk_25F163, "_sde_vbif_get_ot_limit");
          v32 = 234;
          goto LABEL_71;
        }
        v24 = *(_DWORD *)(v23 + 52);
        if ( !v24 || *((_BYTE *)a2 + 20) == 1 )
        {
          v24 = *(_DWORD *)(v23 + 48);
          if ( v24 )
          {
            if ( *((_BYTE *)a2 + 20) == 1 )
            {
              v25 = 64;
              goto LABEL_50;
            }
            v24 = 0;
          }
LABEL_68:
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "vbif:%d xin:%d ot_lim:%d\n", *(_DWORD *)(v9 + 32), *a2, v24);
          v32 = (unsigned __int8)v24;
          if ( !(_BYTE)v24 )
            return mutex_unlock(v9 + 288);
LABEL_71:
          trace_sde_perf_set_ot(a2[1], *a2, v32, a2[6]);
          result = sde_vbif_setup_clk_force_ctrl(v5, a2[7], 1);
          v37 = *(unsigned int *)(v9 + 28);
          if ( (unsigned int)v37 <= 2 )
          {
            v38 = *(_DWORD **)(v9 + 48 + 8 * v37);
            v39 = *a2;
            v40 = result;
            v41 = *((unsigned __int8 *)a2 + 20);
            if ( *(v38 - 1) != -1446195126 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v38)(v9, v39, v41, v32);
            v42 = *(unsigned int *)(v9 + 28);
            if ( (unsigned int)v42 <= 2 )
            {
              v43 = *(void (__fastcall **)(__int64, __int64, __int64))(v18 + 8 * v42);
              v44 = *a2;
              if ( *((_DWORD *)v43 - 1) != -1777251732 )
                __break(0x8228u);
              v43(v9, v44, 1);
              result = ((__int64 (__fastcall *)(__int64, _QWORD))sde_vbif_wait_for_xin_halt)(v9, *a2);
              if ( (_DWORD)result )
                result = sde_evtlog_log(
                           sde_dbg_base_evtlog,
                           "sde_vbif_set_ot_limit",
                           377,
                           -1,
                           *(_DWORD *)(v9 + 32),
                           *a2,
                           -1059143953,
                           v45,
                           v50);
              v46 = *(unsigned int *)(v9 + 28);
              if ( (unsigned int)v46 <= 2 )
              {
                v47 = *(_DWORD **)(v18 + 8 * v46);
                v48 = *a2;
                if ( *(v47 - 1) != -1777251732 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _QWORD))v47)(v9, v48, 0);
                if ( v40 )
                  sde_vbif_setup_clk_force_ctrl(v5, a2[7], 0);
                return mutex_unlock(v9 + 288);
              }
            }
          }
LABEL_86:
          __break(0x5512u);
          __break(1u);
          return trace_sde_perf_set_ot(result, a2, a3, a4);
        }
        v25 = 80;
LABEL_50:
        if ( (*(_BYTE *)(v23 + 32) & 2) != 0 && *((_BYTE *)a2 + 21) == 1 )
        {
          v26 = a2[3];
          v27 = a2[4];
          v28 = a2[2];
          v29 = (unsigned int *)(v23 + v25);
          v30 = *v29;
          if ( (_DWORD)v30 )
          {
            v31 = (_DWORD *)(*((_QWORD *)v29 + 1) + 8LL);
            while ( v28 * (unsigned __int64)v27 * v26 > *((_QWORD *)v31 - 1) )
            {
              --v30;
              v31 += 4;
              if ( !v30 )
                goto LABEL_60;
            }
            v24 = *v31;
          }
LABEL_60:
          if ( (_drm_debug & 4) != 0 )
            result = _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "vbif:%d xin:%d w:%d h:%d fps:%d pps:%llu ot:%u\n",
                       *(_DWORD *)(v9 + 32),
                       *a2,
                       v28,
                       v26,
                       v27,
                       v28 * (unsigned __int64)v27 * v26,
                       v24);
        }
        v33 = *(unsigned int *)(v9 + 28);
        if ( (unsigned int)v33 >= 3 )
          goto LABEL_86;
        v34 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(v9 + 8 * v33 + 72);
        if ( v34 )
        {
          v35 = *a2;
          v36 = *((unsigned __int8 *)a2 + 20);
          if ( *((_DWORD *)v34 - 1) != -717269202 )
            __break(0x8228u);
          if ( v34(v9, v35, v36) == v24 )
            v24 = 0;
        }
        goto LABEL_68;
      }
    }
  }
  return result;
}
