__int64 __fastcall scm_update_6ghz_channel_list(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BYTE *v10; // x19
  __int64 v11; // x21
  __int64 v12; // x22
  unsigned int v13; // w8
  bool v14; // cc
  int v15; // w8
  __int64 v17; // x20
  unsigned __int64 v18; // x24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w23
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x9
  unsigned __int64 v38; // x8
  unsigned __int8 v39; // w22
  unsigned __int64 v40; // x23
  __int64 v41; // x27
  __int64 v42; // x10
  __int64 v43; // x8
  unsigned __int64 v44; // x23
  unsigned __int8 v45; // w25
  int *v46; // x28
  int v47; // w22
  __int64 v48; // x10
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x22
  __int64 comp_private_obj; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _DWORD *v62; // x26
  _DWORD *v63; // x25
  _BYTE *v64; // x8
  int v65; // w10
  __int64 v66; // x28
  unsigned int v67; // w25
  __int64 chan_meta; // x0
  __int64 v69; // x1
  int v70; // w5
  __int64 v71; // x23
  __int64 v72; // x25
  __int64 v73; // x28
  __int64 v74; // x9
  __int64 v75; // x10
  unsigned __int8 v76; // w8
  unsigned int v77; // w12
  _BYTE *v78; // x20
  unsigned __int64 v79; // x20
  unsigned int v80; // w22
  _DWORD *v81; // x8
  __int64 v82; // [xsp+0h] [xbp-4F0h]
  unsigned __int8 v83[4]; // [xsp+Ch] [xbp-4E4h] BYREF
  _QWORD v84[2]; // [xsp+10h] [xbp-4E0h] BYREF
  _BYTE s[1212]; // [xsp+24h] [xbp-4CCh] BYREF
  __int64 v86; // [xsp+4E0h] [xbp-10h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (_BYTE *)(result + 120);
  v11 = *(_QWORD *)result;
  v12 = *(_QWORD *)(*(_QWORD *)result + 216LL);
  if ( v12 )
  {
    v13 = *(_DWORD *)(v11 + 16);
    v14 = v13 > 7;
    v15 = (1 << v13) & 0x8E;
    if ( v14 || v15 == 0 )
    {
      v17 = result;
      v18 = *(_QWORD *)(v12 + 80);
      if ( (wlan_reg_is_6ghz_band_set(*(_QWORD *)(*(_QWORD *)result + 216LL), a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
      {
        v28 = *(_DWORD *)(a2 + 1740);
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: 6g scan mode %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "scm_update_6ghz_channel_list",
          v28);
        LODWORD(v37) = (unsigned __int8)*v10;
        if ( v28 )
        {
          if ( (unsigned int)v37 >= 0xB && *(_DWORD *)(v17 + 28) != 3 )
          {
            scm_add_rnr_info(v12, v17);
            LODWORD(v37) = *(unsigned __int8 *)(v17 + 120);
          }
          if ( (unsigned int)v37 >= 0x66 )
            LODWORD(v38) = 102;
          else
            LODWORD(v38) = v37;
          *v10 = v38;
          if ( (v28 == 1 || v28 == 4) && (*(_BYTE *)(v18 + 23) & 1) == 0 && *(_DWORD *)(v17 + 28) != 3 )
            goto LABEL_32;
          v39 = v38;
        }
        else
        {
          if ( (unsigned int)v37 >= 0x66 )
            LODWORD(v38) = 102;
          else
            LODWORD(v38) = (unsigned __int8)*v10;
          *v10 = v38;
          if ( !(_DWORD)v37 )
            goto LABEL_41;
          v40 = 0;
          v39 = 0;
          v41 = v17 + 124;
          do
          {
            if ( v40 == 102 )
              goto LABEL_31;
            if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)v41) )
            {
              LODWORD(v38) = v39;
              if ( v39 > 0x66u )
                goto LABEL_31;
              LODWORD(v37) = *(_DWORD *)(v41 + 8);
              v42 = *(_QWORD *)v41;
              v43 = v17 + 124 + 12LL * v39++;
              *(_DWORD *)(v43 + 8) = v37;
              *(_QWORD *)v43 = v42;
            }
            v38 = (unsigned __int8)*v10;
            ++v40;
            v41 += 12;
          }
          while ( v40 < v38 );
        }
        while ( 1 )
        {
LABEL_43:
          v83[0] = v39;
          if ( (unsigned int)v38 >= 0xB && (*(_BYTE *)(v18 + 23) & 1) != 0 && *(_DWORD *)(v17 + 28) != 3 )
          {
            scm_add_channel_flags(v11, (__int64)v10, v83, (*(_BYTE *)(v17 + 96) & 8) != 0, 0);
            v39 = v83[0];
          }
          v50 = *(_QWORD *)v17;
          *(_BYTE *)(v17 + 120) = v39;
          v84[0] = 0;
          v84[1] = 0;
          v51 = *(_QWORD *)(v50 + 216);
          if ( !v51 || (v52 = *(_QWORD *)(v51 + 80)) == 0 )
          {
            result = qdf_trace_msg(
                       0x15u,
                       2u,
                       "%s: Psoc is NULL",
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       "scm_sort_6ghz_channel_list",
                       v82);
            goto LABEL_6;
          }
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v51 + 80), 3u);
          if ( !comp_private_obj )
          {
            result = qdf_trace_msg(
                       0x15u,
                       2u,
                       "%s: %s:%u, Failed to get scan object",
                       v54,
                       v55,
                       v56,
                       v57,
                       v58,
                       v59,
                       v60,
                       v61,
                       "wlan_psoc_get_scan_obj_fl",
                       "scm_sort_6ghz_channel_list",
                       70);
            goto LABEL_6;
          }
          if ( !*v10 )
            break;
          v82 = comp_private_obj;
          memset(s, 0, sizeof(s));
          v62 = (_DWORD *)(v17 + 124);
          v18 = 0;
          v11 = 0;
          v17 = 12;
          v63 = v62;
          while ( v18 != 102 )
          {
            if ( wlan_reg_is_6ghz_chan_freq(*v63) )
            {
              if ( (unsigned int)v11 > 0x65 )
                break;
              v64 = &s[12 * (unsigned int)v11];
              v37 = *(_QWORD *)v63;
              v65 = v63[2];
              v11 = (unsigned int)(v11 + 1);
              *(_QWORD *)v64 = *(_QWORD *)v63;
              *((_DWORD *)v64 + 2) = v65;
            }
            v38 = (unsigned __int8)*v10;
            ++v18;
            v63 += 3;
            if ( v18 >= v38 )
            {
              result = qdf_trace_msg(
                         0x15u,
                         8u,
                         "%s: Total 6 GHz channels %d",
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         "scm_sort_6ghz_channel_list",
                         (unsigned int)v11);
              if ( (unsigned int)v11 < 2 )
                goto LABEL_6;
              result = _qdf_mem_malloc(16LL * (unsigned int)v11, "scm_sort_6ghz_channel_list", 85);
              if ( !result )
                goto LABEL_6;
              v10 = (_BYTE *)result;
              qdf_mutex_acquire(v82 + 23920);
              LODWORD(v38) = 3 * v11;
              v66 = 0;
              v17 = 0;
              v18 = 12LL * (unsigned int)v11;
              while ( v66 != 1212 )
              {
                v67 = *(_DWORD *)&s[v66];
                chan_meta = scm_get_chan_meta(v52, v67);
                if ( chan_meta )
                {
                  v70 = 5 * *(_DWORD *)(chan_meta + 4) + 10 * *(_DWORD *)(chan_meta + 8);
                  v38 = (unsigned __int64)&v10[16 * (unsigned __int8)v17];
                  *(_DWORD *)v38 = v67;
                  *(_DWORD *)(v38 + 4) = v70;
                  if ( (unsigned __int64)(v66 - 1208) < 0xFFFFFFFFFFFFFB44LL
                    || (*(_DWORD *)(v38 + 8) = *(_DWORD *)&s[v66 + 4],
                        (unsigned __int64)(v66 - 1204) < 0xFFFFFFFFFFFFFB44LL) )
                  {
                    __break(1u);
                    return scm_add_rnr_info(chan_meta, v69);
                  }
                  v17 = (unsigned int)(v17 + 1);
                  LODWORD(v37) = *(_DWORD *)&s[v66 + 8];
                  *(_DWORD *)(v38 + 12) = v37;
                  LODWORD(v38) = v70 | *(_DWORD *)(chan_meta + 4);
                  if ( (_DWORD)v38 )
                    qdf_trace_msg(
                      0x15u,
                      8u,
                      "%s: Freq %d weight %d bcn_cnt %d",
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      "scm_sort_6ghz_channel_list",
                      v67);
                }
                v66 += 12;
                if ( v18 == v66 )
                {
                  qdf_mutex_release(v82 + 23920);
                  v71 = 0;
                  v72 = 1;
                  v73 = 20;
                  do
                  {
                    v74 = v73;
                    v75 = v72;
                    v76 = v71;
                    do
                    {
                      v77 = *(_DWORD *)&v10[v74];
                      v74 += 16;
                      if ( v77 > *(_DWORD *)&v10[16 * v76 + 4] )
                        v76 = v75;
                      ++v75;
                    }
                    while ( (unsigned int)v11 != v75 );
                    if ( v71 != v76 )
                    {
                      v78 = &v10[16 * v76];
                      qdf_mem_copy(v84, v78, 0x10u);
                      qdf_mem_copy(v78, &v10[16 * v71], 0x10u);
                      qdf_mem_copy(&v10[16 * v71], v84, 0x10u);
                    }
                    ++v71;
                    ++v72;
                    v73 += 16;
                  }
                  while ( v71 != (_DWORD)v11 - 1 );
                  v79 = 0;
                  v80 = 0;
                  do
                  {
                    if ( wlan_reg_is_6ghz_chan_freq(*v62) )
                    {
                      v81 = &v10[16 * v80++];
                      *v62 = *v81;
                      v62[2] = v81[3];
                      v62[1] = v81[2];
                    }
                    if ( v79 > 0x64 )
                      break;
                    ++v79;
                    v62 += 3;
                  }
                  while ( v80 < (unsigned int)v11 );
                  result = _qdf_mem_free((__int64)v10);
                  goto LABEL_6;
                }
              }
              break;
            }
          }
LABEL_31:
          while ( 1 )
          {
            __break(0x5512u);
LABEL_32:
            if ( !(_DWORD)v37 )
              break;
            v44 = 0;
            v45 = 0;
            v46 = (int *)(v17 + 124);
            while ( v44 != 102 )
            {
              v47 = *v46;
              if ( !wlan_reg_is_6ghz_chan_freq(*v46)
                || wlan_reg_is_6ghz_chan_freq(v47)
                && (wlan_reg_is_6ghz_psc_chan_freq(v47, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0 )
              {
                LODWORD(v38) = v45;
                if ( v45 > 0x66u )
                  goto LABEL_31;
                LODWORD(v37) = v46[2];
                v48 = *(_QWORD *)v46;
                v49 = v17 + 124 + 12LL * v45++;
                *(_DWORD *)(v49 + 8) = v37;
                *(_QWORD *)v49 = v48;
              }
              v38 = (unsigned __int8)*v10;
              ++v44;
              v46 += 3;
              if ( v44 >= v38 )
              {
                v39 = v45;
                goto LABEL_43;
              }
            }
          }
LABEL_41:
          v39 = 0;
        }
        result = qdf_trace_msg(
                   0x15u,
                   8u,
                   "%s: Total 6 GHz channels %d",
                   v54,
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   "scm_sort_6ghz_channel_list",
                   0);
      }
      else
      {
        result = qdf_trace_msg(
                   0x15u,
                   8u,
                   "%s: 6 GHz band disabled.",
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   "scm_update_6ghz_channel_list");
      }
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
