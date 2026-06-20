__int64 __fastcall add_sbs_chlist_to_pcl(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int *a5,
        char a6,
        unsigned int *a7,
        unsigned __int8 a8,
        unsigned int *a9,
        unsigned __int8 a10,
        int a11,
        _BYTE *a12,
        _BYTE *a13)
{
  __int64 result; // x0
  unsigned int sbs_cut_off_freq; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w22
  __int64 comp_private_obj; // x0
  char *v34; // x25
  int v35; // w8
  __int64 v36; // x10
  int v37; // w23
  const char *v38; // x2
  char *v39; // x25
  int v40; // w8
  __int64 v41; // x10
  int v42; // w25
  int v43; // w8
  int v44; // w8
  int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w10
  __int64 v55; // x8
  unsigned int v56; // w11
  unsigned int v57; // w10
  __int64 v58; // x8
  unsigned int v59; // w11
  unsigned int v60; // w10
  __int64 v61; // x8
  unsigned int v62; // w11
  unsigned int v63; // w10
  __int64 v64; // x8
  unsigned int v65; // w11
  int v66; // w8
  unsigned int v67; // w11
  __int64 v68; // x9
  unsigned int v69; // w12
  unsigned int v70; // w11
  __int64 v71; // x9
  unsigned int v72; // w12
  _BYTE *v73; // [xsp+0h] [xbp-30h]
  char v74; // [xsp+1Ch] [xbp-14h]
  __int64 v75; // [xsp+28h] [xbp-8h]

  result = policy_mgr_is_hw_sbs_capable(a1);
  if ( (result & 1) != 0 )
  {
    sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(a1);
    if ( sbs_cut_off_freq )
    {
      v31 = sbs_cut_off_freq;
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
      if ( comp_private_obj )
      {
        v75 = comp_private_obj;
        v74 = a6;
        if ( a11 == 5 )
        {
          qdf_mutex_acquire(comp_private_obj + 56);
          if ( BYTE4(qword_81C458) != 1 )
          {
            v36 = v75;
LABEL_48:
            v37 = 0;
            goto LABEL_49;
          }
          v34 = (char *)&pm_conc_connection_list + 4;
          if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
          {
            v35 = HIDWORD(pm_conc_connection_list);
            if ( HIDWORD(pm_conc_connection_list) < v31 )
              goto LABEL_8;
          }
          if ( BYTE4(qword_81C47C) == 1 )
          {
            v34 = (char *)&qword_81C464 + 4;
            if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) )
            {
              v35 = HIDWORD(qword_81C464);
              if ( HIDWORD(qword_81C464) < v31 )
                goto LABEL_8;
            }
            if ( BYTE4(qword_81C4A0) == 1 )
            {
              v34 = (char *)&qword_81C488 + 4;
              if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)) )
              {
                v35 = HIDWORD(qword_81C488);
                if ( HIDWORD(qword_81C488) < v31 )
                  goto LABEL_8;
              }
              if ( BYTE4(qword_81C4C4) == 1 )
              {
                v34 = (char *)&qword_81C4AC + 4;
                if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
                  || (v35 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) >= v31) )
                {
                  if ( BYTE4(qword_81C4E8) == 1 )
                  {
                    v34 = (char *)&qword_81C4D0 + 4;
                    v37 = 0;
                    if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) )
                    {
                      v36 = v75;
                      goto LABEL_49;
                    }
                    v35 = HIDWORD(qword_81C4D0);
                    v36 = v75;
                    if ( HIDWORD(qword_81C4D0) >= v31 )
                      goto LABEL_49;
                    goto LABEL_9;
                  }
                  goto LABEL_47;
                }
LABEL_8:
                v36 = v75;
LABEL_9:
                *(_DWORD *)(a2 + 4LL * *a5) = v35;
                v37 = *(_DWORD *)v34;
                *(_BYTE *)(a3 + (*a5)++) = -1;
                *a13 = 1;
LABEL_49:
                result = qdf_mutex_release(v36 + 56);
                if ( a8 )
                {
                  v54 = *a5;
                  v55 = a8;
                  do
                  {
                    if ( v54 >= a4 )
                      break;
                    v56 = *a7;
                    if ( *a7 > v31 )
                      return result;
                    if ( v37 != v56 )
                    {
                      *(_DWORD *)(a2 + 4LL * v54) = v56;
                      *(_BYTE *)(a3 + *a5) = -21;
                      v54 = *a5 + 1;
                      *a5 = v54;
                    }
                    --v55;
                    ++a7;
                  }
                  while ( v55 );
                }
                if ( a10 && (v74 & 1) == 0 )
                {
                  v57 = *a5;
                  v58 = a10;
                  do
                  {
                    if ( v57 >= a4 )
                      break;
                    v59 = *a9;
                    if ( *a9 > v31 )
                      return result;
                    if ( v37 != v59 )
                    {
                      *(_DWORD *)(a2 + 4LL * v57) = v59;
                      *(_BYTE *)(a3 + *a5) = -21;
                      v57 = *a5 + 1;
                      *a5 = v57;
                    }
                    --v58;
                    ++a9;
                  }
                  while ( v58 );
                }
                return qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "%s: new pcl index %d",
                         v46,
                         v47,
                         v48,
                         v49,
                         v50,
                         v51,
                         v52,
                         v53,
                         "add_sbs_chlist_to_pcl",
                         *a5,
                         v73);
              }
            }
          }
LABEL_47:
          v36 = v75;
          goto LABEL_48;
        }
        v73 = a12;
        result = qdf_mutex_acquire(comp_private_obj + 56);
        if ( (a11 & 0xFFFFFFFE) != 6 )
        {
          if ( a11 == 9 )
          {
            if ( BYTE4(qword_81C458) )
            {
              if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
                && (v44 = HIDWORD(pm_conc_connection_list), HIDWORD(pm_conc_connection_list) > v31)
                || BYTE4(qword_81C47C) == 1
                && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464))
                 && (v44 = HIDWORD(qword_81C464), HIDWORD(qword_81C464) > v31)
                 || BYTE4(qword_81C4A0) == 1
                 && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488))
                  && (v44 = HIDWORD(qword_81C488), HIDWORD(qword_81C488) > v31)
                  || BYTE4(qword_81C4C4) == 1
                  && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
                   && (v44 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) > v31)
                   || BYTE4(qword_81C4E8) == 1
                   && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0))
                   && (v44 = HIDWORD(qword_81C4D0), HIDWORD(qword_81C4D0) > v31)))) )
              {
                *(_DWORD *)(a2 + 4LL * *a5) = v44;
                *(_BYTE *)(a3 + (*a5)++) = -1;
                *a12 = 1;
              }
            }
          }
          else if ( a11 == 8 )
          {
            if ( BYTE4(qword_81C458) )
            {
              if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
                && (v43 = HIDWORD(pm_conc_connection_list), HIDWORD(pm_conc_connection_list) < v31)
                || BYTE4(qword_81C47C) == 1
                && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464))
                 && (v43 = HIDWORD(qword_81C464), HIDWORD(qword_81C464) < v31)
                 || BYTE4(qword_81C4A0) == 1
                 && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488))
                  && (v43 = HIDWORD(qword_81C488), HIDWORD(qword_81C488) < v31)
                  || BYTE4(qword_81C4C4) == 1
                  && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
                   && (v43 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) < v31)
                   || BYTE4(qword_81C4E8) == 1
                   && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0))
                   && (v43 = HIDWORD(qword_81C4D0), HIDWORD(qword_81C4D0) < v31)))) )
              {
                *(_DWORD *)(a2 + 4LL * *a5) = v43;
                *(_BYTE *)(a3 + (*a5)++) = -1;
                *a13 = 1;
              }
            }
          }
          else
          {
            if ( BYTE4(qword_81C458) )
            {
              result = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
              if ( (result & 1) == 0 )
              {
                v45 = HIDWORD(pm_conc_connection_list);
                if ( HIDWORD(pm_conc_connection_list) < v31 )
                  goto LABEL_46;
              }
              if ( BYTE4(qword_81C47C) == 1 )
              {
                result = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464));
                if ( (result & 1) == 0 )
                {
                  v45 = HIDWORD(qword_81C464);
                  if ( HIDWORD(qword_81C464) < v31 )
                    goto LABEL_46;
                }
                if ( BYTE4(qword_81C4A0) == 1 )
                {
                  if ( (result = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)), (result & 1) == 0)
                    && (v45 = HIDWORD(qword_81C488), HIDWORD(qword_81C488) < v31)
                    || BYTE4(qword_81C4C4) == 1
                    && ((result = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC)), (result & 1) == 0)
                     && (v45 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) < v31)
                     || BYTE4(qword_81C4E8) == 1
                     && (result = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)), (result & 1) == 0)
                     && (v45 = HIDWORD(qword_81C4D0), HIDWORD(qword_81C4D0) < v31)) )
                  {
LABEL_46:
                    *(_DWORD *)(a2 + 4LL * *a5) = v45;
                    *(_BYTE *)(a3 + (*a5)++) = -1;
                    *a13 = 1;
                  }
                }
              }
            }
            if ( a8 )
            {
              v67 = *a5;
              v68 = a8;
              do
              {
                if ( v67 >= a4 )
                  break;
                v69 = *a7;
                if ( *a7 >= v31
                  && ((qword_81C458 & 0x100000000LL) == 0
                   || HIDWORD(pm_conc_connection_list) != v69
                   && (BYTE4(qword_81C47C) != 1
                    || HIDWORD(qword_81C464) != v69
                    && (BYTE4(qword_81C4A0) != 1
                     || HIDWORD(qword_81C488) != v69
                     && (BYTE4(qword_81C4C4) != 1
                      || HIDWORD(qword_81C4AC) != v69 && (BYTE4(qword_81C4E8) != 1 || HIDWORD(qword_81C4D0) != v69))))) )
                {
                  *(_DWORD *)(a2 + 4LL * v67) = v69;
                  *(_BYTE *)(a3 + *a5) = -21;
                  v67 = *a5 + 1;
                  *a5 = v67;
                }
                --v68;
                ++a7;
              }
              while ( v68 );
            }
            if ( a10 && (a6 & 1) == 0 )
            {
              v70 = *a5;
              v71 = a10;
              do
              {
                if ( v70 >= a4 )
                  break;
                v72 = *a9;
                if ( *a9 < v31 )
                  return result;
                if ( (qword_81C458 & 0x100000000LL) == 0
                  || HIDWORD(pm_conc_connection_list) != v72
                  && (BYTE4(qword_81C47C) != 1
                   || HIDWORD(qword_81C464) != v72
                   && (BYTE4(qword_81C4A0) != 1
                    || HIDWORD(qword_81C488) != v72
                    && (BYTE4(qword_81C4C4) != 1
                     || HIDWORD(qword_81C4AC) != v72 && (BYTE4(qword_81C4E8) != 1 || HIDWORD(qword_81C4D0) != v72)))) )
                {
                  *(_DWORD *)(a2 + 4LL * v70) = v72;
                  *(_BYTE *)(a3 + *a5) = -21;
                  v70 = *a5 + 1;
                  *a5 = v70;
                }
                --v71;
                ++a9;
              }
              while ( v71 );
            }
          }
LABEL_184:
          qdf_mutex_release(v75 + 56);
          return qdf_trace_msg(
                   0x4Fu,
                   8u,
                   "%s: new pcl index %d",
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   v53,
                   "add_sbs_chlist_to_pcl",
                   *a5,
                   v73);
        }
        if ( BYTE4(qword_81C458) )
        {
          v39 = (char *)&pm_conc_connection_list + 4;
          if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
          {
            v40 = HIDWORD(pm_conc_connection_list);
            if ( HIDWORD(pm_conc_connection_list) > v31 )
              goto LABEL_17;
          }
          if ( BYTE4(qword_81C47C) == 1 )
          {
            v39 = (char *)&qword_81C464 + 4;
            if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) )
            {
              v40 = HIDWORD(qword_81C464);
              if ( HIDWORD(qword_81C464) > v31 )
                goto LABEL_17;
            }
            if ( BYTE4(qword_81C4A0) != 1 )
              goto LABEL_77;
            v39 = (char *)&qword_81C488 + 4;
            if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)) )
            {
              v40 = HIDWORD(qword_81C488);
              if ( HIDWORD(qword_81C488) > v31 )
                goto LABEL_17;
            }
            if ( BYTE4(qword_81C4C4) != 1 )
              goto LABEL_77;
            v39 = (char *)&qword_81C4AC + 4;
            if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC)) )
            {
              v40 = HIDWORD(qword_81C4AC);
              if ( HIDWORD(qword_81C4AC) > v31 )
              {
LABEL_17:
                v41 = v75;
                goto LABEL_18;
              }
            }
            if ( BYTE4(qword_81C4E8) == 1 )
            {
              v42 = 0;
              if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) )
              {
                v41 = v75;
                goto LABEL_78;
              }
              v41 = v75;
              v40 = HIDWORD(qword_81C4D0);
              if ( HIDWORD(qword_81C4D0) <= v31 )
              {
LABEL_78:
                result = qdf_mutex_release(v41 + 56);
                if ( a8 )
                {
                  v60 = *a5;
                  v61 = a8;
                  do
                  {
                    if ( v60 >= a4 )
                      break;
                    v62 = *a7;
                    if ( *a7 >= v31 && v42 != v62 )
                    {
                      *(_DWORD *)(a2 + 4LL * v60) = v62;
                      *(_BYTE *)(a3 + *a5) = -21;
                      v60 = *a5 + 1;
                      *a5 = v60;
                    }
                    --v61;
                    ++a7;
                  }
                  while ( v61 );
                }
                if ( a10 && (v74 & 1) == 0 )
                {
                  v63 = *a5;
                  v64 = a10;
                  do
                  {
                    if ( v63 >= a4 )
                      break;
                    v65 = *a9;
                    if ( *a9 < v31 )
                      return result;
                    if ( v42 != v65 )
                    {
                      *(_DWORD *)(a2 + 4LL * v63) = v65;
                      *(_BYTE *)(a3 + *a5) = -21;
                      v63 = *a5 + 1;
                      *a5 = v63;
                    }
                    --v64;
                    ++a9;
                  }
                  while ( v64 );
                }
                if ( a11 != 7 )
                  return qdf_trace_msg(
                           0x4Fu,
                           8u,
                           "%s: new pcl index %d",
                           v46,
                           v47,
                           v48,
                           v49,
                           v50,
                           v51,
                           v52,
                           v53,
                           "add_sbs_chlist_to_pcl",
                           *a5,
                           v73);
                qdf_mutex_acquire(v75 + 56);
                if ( BYTE4(qword_81C458) == 1 )
                {
                  if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
                    && (v66 = HIDWORD(pm_conc_connection_list), HIDWORD(pm_conc_connection_list) < v31)
                    || BYTE4(qword_81C47C) == 1
                    && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464))
                     && (v66 = HIDWORD(qword_81C464), HIDWORD(qword_81C464) < v31)
                     || BYTE4(qword_81C4A0) == 1
                     && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488))
                      && (v66 = HIDWORD(qword_81C488), HIDWORD(qword_81C488) < v31)
                      || BYTE4(qword_81C4C4) == 1
                      && (!wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
                       && (v66 = HIDWORD(qword_81C4AC), HIDWORD(qword_81C4AC) < v31)
                       || BYTE4(qword_81C4E8) == 1
                       && !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0))
                       && (v66 = HIDWORD(qword_81C4D0), HIDWORD(qword_81C4D0) < v31)))) )
                  {
                    *(_DWORD *)(a2 + 4LL * *a5) = v66;
                    *(_BYTE *)(a3 + (*a5)++) = -41;
                  }
                }
                goto LABEL_184;
              }
              v39 = (char *)&qword_81C4D0 + 4;
LABEL_18:
              *(_DWORD *)(a2 + 4LL * *a5) = v40;
              v42 = *(_DWORD *)v39;
              *(_BYTE *)(a3 + (*a5)++) = -1;
              *a12 = 1;
              goto LABEL_78;
            }
          }
        }
LABEL_77:
        v41 = v75;
        v42 = 0;
        goto LABEL_78;
      }
      v38 = "%s: Invalid Context";
    }
    else
    {
      v38 = "%s: Invalid cut off freq";
    }
    return qdf_trace_msg(0x4Fu, 2u, v38, v23, v24, v25, v26, v27, v28, v29, v30, "add_sbs_chlist_to_pcl");
  }
  return result;
}
