__int64 __fastcall get_tearcheck_cfg(__int64 a1, unsigned int *a2, int *a3, int *a4)
{
  __int64 v8; // x22
  __int64 v9; // x25
  __int64 result; // x0
  __int64 (__fastcall *v11)(_QWORD); // x9
  __int64 v12; // x0
  int v13; // w26
  int v14; // w24
  unsigned int v15; // w27
  _DWORD *v16; // x8
  unsigned int v17; // w28
  int v18; // w27
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x28
  __int64 v22; // x8
  __int64 v23; // x12
  unsigned int v24; // w9
  __int64 v25; // x10
  __int64 v26; // x13
  __int64 v27; // x8
  int v28; // w10
  int v29; // w8
  unsigned int v30; // w27
  __int64 v31; // x9
  unsigned int v32; // w10
  int v33; // w9
  int v34; // w8
  int v35; // w8
  __int64 v36; // x22
  int v37; // w4
  int v38; // w4
  int v39; // w4
  int v40; // w4
  unsigned int v41; // w22
  __int64 v42; // [xsp+48h] [xbp-68h]
  __int64 v43; // [xsp+50h] [xbp-60h]
  __int64 v44; // [xsp+50h] [xbp-60h]
  int v45; // [xsp+5Ch] [xbp-54h]
  __int64 v46; // [xsp+60h] [xbp-50h]
  __int64 v47; // [xsp+68h] [xbp-48h]
  unsigned int v48; // [xsp+74h] [xbp-3Ch]
  __int64 v49; // [xsp+78h] [xbp-38h]
  int v50; // [xsp+84h] [xbp-2Ch]
  unsigned int v51; // [xsp+88h] [xbp-28h]
  unsigned int v52; // [xsp+8Ch] [xbp-24h] BYREF
  __int64 v53; // [xsp+90h] [xbp-20h] BYREF
  _QWORD v54[3]; // [xsp+98h] [xbp-18h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)a1;
  v8 = *(_QWORD *)(a1 + 8);
  v53 = 0;
  v54[0] = 0;
  v52 = 0;
  result = sde_encoder_get_disp_op(v9);
  *a4 = 0;
  *a3 = 0;
  *a2 = 0;
  if ( !v8 || !*(_QWORD *)(v8 + 2512) || !*(_QWORD *)(a1 + 512) )
    goto LABEL_72;
  if ( (unsigned int)result < 3 )
  {
    v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 424) + 8LL * (unsigned int)result + 1232);
    if ( !v11 )
      goto LABEL_10;
    v12 = *(_QWORD *)(a1 + 424);
    if ( *((_DWORD *)v11 - 1) != 823427813 )
      __break(0x8229u);
    if ( (v11(v12) & 1) != 0 )
      v13 = -16;
    else
LABEL_10:
      v13 = 65520;
    v14 = *(unsigned __int16 *)(a1 + 534);
    v15 = *(unsigned __int16 *)(a1 + 540);
    result = drm_mode_vrefresh(a1 + 520);
    if ( *(_DWORD *)(v8 + 4676) == 1 )
    {
      v16 = *(_DWORD **)(a1 + 400);
      if ( v16 )
      {
        v17 = v15;
        v18 = result;
        v19 = *(_QWORD *)a1;
        v20 = *(_QWORD *)(v8 + 2512);
        if ( *(v16 - 1) != 1659771273 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, unsigned int *, __int64, _QWORD))v16)(v19, &v52, v20, 0);
        LODWORD(result) = v18;
        v15 = v17;
      }
      if ( v52 && (_DWORD)result && v15 )
      {
        if ( v52 < (unsigned int)result )
        {
          v51 = result;
          v21 = 0x3B9ACA00 / (unsigned int)result;
          v49 = 0x3B9ACA00 / v52;
          sde_encoder_helper_get_jitter_bounds_ns(v52, *(_DWORD *)(v9 + 3956), *(_DWORD *)(v9 + 3960), v54, &v53);
          v22 = v54[0];
          if ( !v54[0] || !v53 )
          {
            v22 = v49;
            v53 = v49;
            v54[0] = v49;
          }
          v23 = v22 - v21;
          v50 = v15;
          if ( v15 == 1 )
            v24 = 0;
          else
            v24 = v21;
          if ( v15 == 1 )
            v25 = v21;
          else
            v25 = 0;
          v26 = v25 + v24 / v15;
          if ( v26 == 1 )
            v27 = 0;
          else
            v27 = v22 - v21;
          if ( v26 == 1 )
            v28 = v23;
          else
            v28 = 0;
          v29 = v28 + v27 / v26;
          if ( (v29 & 0xFFFFFFFC) - 2 <= 4 )
            v30 = v29 & 0xFFFFFFFC;
          else
            v30 = (v29 & 0xFFFFFFFC) - 2;
          if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 152LL) + 22008LL) & 0x2000000000LL) != 0
            && (v31 = *(_QWORD *)(v8 + 2512), v13 = v13 - v14 - v29, v31) )
          {
            v32 = *(_DWORD *)(v31 + 1696);
            if ( v32 )
            {
              if ( v51 >= v32 )
              {
                v33 = 0x3B9ACA00 / v32 - v21;
                v46 = 0x3B9ACA00 / v32;
                if ( v26 == 1 )
                  v34 = 0;
                else
                  v34 = 0x3B9ACA00 / v32 - v21;
                v47 = 0x3B9ACA00 / v32 - v21;
                if ( v26 != 1 )
                  v33 = 0;
                v35 = v33 + v34 / (int)v26;
                v14 += v35;
                v45 = v35;
                goto LABEL_51;
              }
              v42 = v23;
              v44 = v26;
              v41 = *(_DWORD *)(v31 + 1696);
              printk(&unk_27A327, "_get_tearcheck_cfg");
              v23 = v42;
              v26 = v44;
              v32 = v41;
            }
          }
          else
          {
            v32 = 0;
          }
          v45 = 0;
          v46 = 0;
          v47 = 0;
LABEL_51:
          if ( (_drm_debug & 4) != 0 )
          {
            v36 = v23;
            v48 = v32;
            v43 = v26;
            v37 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
            _drm_dev_dbg(
              0,
              0,
              0,
              "enc%d intf%d qsync mode:%u min_fps:%u ts:%llu jitter_ns:%llu/%llu jitter:%u/%u\n",
              v37,
              *(_DWORD *)(a1 + 672) - 1,
              1,
              v52,
              v49,
              v54[0],
              v53,
              *(_DWORD *)(v9 + 3956),
              *(_DWORD *)(v9 + 3960));
            if ( (_drm_debug & 4) != 0 )
            {
              v38 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d intf%d default fps:%u ts:%llu yres:%u line_time:%llu extra_time:%llu\n",
                v38,
                *(_DWORD *)(a1 + 672) - 1,
                v51,
                v21,
                v50,
                v43,
                v36);
              if ( (_drm_debug & 4) != 0 )
              {
                v39 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "enc%d intf%d ept_fps:%d ts:%llu ept_extra_time:%llu ept_threshold_lines:%u\n",
                  v39,
                  *(_DWORD *)(a1 + 672) - 1,
                  v48,
                  v46,
                  v47,
                  v45);
                if ( (_drm_debug & 4) != 0 )
                {
                  if ( *(_QWORD *)a1 )
                    v40 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
                  else
                    v40 = -1;
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "enc%d intf%d threshold_lines:%u cfg_height:%u start_pos:%u\n",
                    v40,
                    *(_DWORD *)(a1 + 672) - 1,
                    v30,
                    v13,
                    v14);
                }
              }
            }
          }
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "_get_tearcheck_cfg",
                     1462,
                     -1,
                     1,
                     v52,
                     v51,
                     *(_DWORD *)(v9 + 3956),
                     *(_DWORD *)(v9 + 3960));
          goto LABEL_71;
        }
        result = printk(&unk_2571B7, "_get_tearcheck_cfg");
        v30 = 4;
      }
      else
      {
        result = printk(&unk_23BC3E, "_get_tearcheck_cfg");
        v30 = 4;
      }
    }
    else
    {
      v30 = 4;
    }
LABEL_71:
    *a2 = v30;
    *a3 = v13;
    *a4 = v14;
LABEL_72:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return sde_encoder_phys_cmd_is_scheduler_idle(result);
}
