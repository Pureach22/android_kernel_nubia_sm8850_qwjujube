__int64 __fastcall get_sub_channels(
        __int64 a1,
        _DWORD *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        __int64 a6,
        unsigned int *a7,
        unsigned int *a8,
        unsigned __int8 a9,
        unsigned int *a10,
        unsigned __int8 a11)
{
  unsigned int v12; // w20
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w8
  __int64 v29; // x26
  __int64 v30; // x0
  bool v31; // zf
  unsigned int *v32; // x8
  unsigned __int8 v33; // w8
  unsigned int *v34; // x8
  unsigned __int8 v35; // w8
  __int64 i; // x22
  __int64 v37; // x10
  char *v38; // x25
  unsigned __int64 v39; // x8
  unsigned int v40; // w9
  __int64 v41; // x11
  unsigned __int64 v42; // x10
  bool v43; // cf
  __int64 j; // x22
  __int64 v45; // x10
  char *v46; // x25
  unsigned __int64 v47; // x8
  unsigned int v48; // w9
  __int64 v49; // x11
  unsigned __int64 v50; // x10
  __int64 result; // x0
  __int64 v52; // x25
  unsigned int v53; // w8
  int v54; // w20
  int v55; // w7
  unsigned int v56; // w26
  unsigned int v57; // w27
  unsigned int *v58; // x22
  __int64 v59; // x28
  __int64 v60; // x8
  int v61; // w10
  unsigned int *v62; // x22
  __int64 v63; // x28
  __int64 v64; // x8
  int v65; // w10
  unsigned __int64 v66; // x9
  unsigned int v67; // w10
  __int64 k; // x11
  unsigned int v69; // w1
  unsigned __int64 v70; // x2
  unsigned int v71; // w3
  unsigned __int64 v72; // x2
  int v73; // w3
  __int64 m; // x11
  unsigned int v75; // w1
  unsigned __int64 v76; // x2
  unsigned int v77; // w3
  unsigned __int64 v78; // x2
  int v79; // w3
  unsigned __int8 v80; // [xsp+Ch] [xbp-34h]
  unsigned __int8 v81; // [xsp+10h] [xbp-30h]
  __int64 v82; // [xsp+18h] [xbp-28h]
  unsigned int *v83; // [xsp+20h] [xbp-20h]
  unsigned int *v84; // [xsp+28h] [xbp-18h]
  _DWORD *v85; // [xsp+30h] [xbp-10h]

  v12 = *a5;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v28 = *(_DWORD *)(comp_private_obj + 2236);
    v29 = comp_private_obj;
    v30 = comp_private_obj + 56;
    v31 = v28 == 1;
    v85 = a2;
    if ( v28 == 1 )
      v32 = a10;
    else
      v32 = a8;
    v82 = a6;
    v84 = v32;
    if ( v31 )
      v33 = a11;
    else
      v33 = a9;
    v80 = v33;
    if ( v31 )
      v34 = a8;
    else
      v34 = a10;
    v83 = v34;
    if ( v31 )
      v35 = a9;
    else
      v35 = a11;
    v81 = v35;
    *a5 = 0;
    qdf_mutex_acquire(v30);
    for ( i = 0; i != 5; ++i )
    {
      v38 = (char *)&pm_conc_connection_list + 36 * i;
      if ( v38[28] != 1 )
        break;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v38 + 1)) )
      {
        v39 = *a5;
        if ( (unsigned int)v39 < v12 )
        {
          v40 = *((_DWORD *)v38 + 1);
          if ( (_DWORD)v39 )
          {
            if ( *a4 == v40 )
              continue;
            v41 = 1;
            do
            {
              v42 = v41;
              if ( v39 == v41 )
                break;
              v31 = a4[v41++] == v40;
            }
            while ( !v31 );
            v43 = v42 >= v39;
            v37 = *a5;
            if ( !v43 )
              continue;
          }
          else
          {
            v37 = 0;
          }
          *a5 = v39 + 1;
          a4[v37] = v40;
        }
      }
    }
    for ( j = 0; j != 5; ++j )
    {
      v46 = (char *)&pm_conc_connection_list + 36 * j;
      if ( v46[28] != 1 )
        break;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v46 + 1)) )
      {
        v47 = *a5;
        if ( (unsigned int)v47 < v12 )
        {
          v48 = *((_DWORD *)v46 + 1);
          if ( (_DWORD)v47 )
          {
            if ( *a4 == v48 )
              continue;
            v49 = 1;
            do
            {
              v50 = v49;
              if ( v47 == v49 )
                break;
              v31 = a4[v49++] == v48;
            }
            while ( !v31 );
            v43 = v50 >= v47;
            v45 = *a5;
            if ( !v43 )
              continue;
          }
          else
          {
            v45 = 0;
          }
          *a5 = v47 + 1;
          a4[v45] = v48;
        }
      }
    }
    qdf_mutex_release(v29 + 56);
    result = policy_mgr_is_hw_sbs_capable(a1);
    if ( (result & 1) != 0
      && (*a5 == 1 || *a5 == 2 && (result = policy_mgr_are_sbs_chan(a1, *a4, a4[1]), (result & 1) == 0)) )
    {
      v56 = *a4;
      v57 = *a3;
      v52 = v82;
      *a3 = 0;
      v54 = v80;
      if ( v80 )
      {
        v58 = v84;
        v59 = v80;
        while ( 1 )
        {
          v53 = *a3;
          if ( *a3 >= v57 )
            break;
          result = policy_mgr_are_sbs_chan(a1, v56, *v58);
          if ( (result & 1) != 0 )
          {
            v60 = *a3;
            v61 = *v58;
            *a3 = v60 + 1;
            v85[v60] = v61;
          }
          --v59;
          ++v58;
          if ( !v59 )
            goto LABEL_56;
        }
      }
      else
      {
LABEL_56:
        if ( v81 )
        {
          v62 = v83;
          v63 = v81;
          while ( 1 )
          {
            v53 = *a3;
            if ( *a3 >= v57 )
              break;
            result = policy_mgr_are_sbs_chan(a1, v56, *v62);
            if ( (result & 1) != 0 )
            {
              v64 = *a3;
              v65 = *v62;
              *a3 = v64 + 1;
              v85[v64] = v65;
            }
            --v63;
            ++v62;
            if ( !v63 )
              goto LABEL_62;
          }
        }
        else
        {
LABEL_62:
          v53 = *a3;
        }
      }
      v55 = v81;
    }
    else
    {
      v52 = v82;
      v53 = 0;
      *a3 = 0;
      v54 = v80;
      v55 = v81;
    }
    v66 = *a5;
    v67 = *a7;
    *a7 = 0;
    if ( v54 )
    {
      for ( k = 0; k != v54; ++k )
      {
        result = *a7;
        if ( (unsigned int)result >= v67 )
          return result;
        v69 = v84[k];
        if ( (_DWORD)v66 )
        {
          if ( *a4 == v69 )
            continue;
          v70 = 0;
          while ( v66 - 1 != v70 )
          {
            v71 = a4[++v70];
            if ( v71 == v69 )
            {
              if ( v70 < v66 )
                goto LABEL_67;
              break;
            }
          }
        }
        if ( v53 )
        {
          if ( *v85 == v69 )
            continue;
          v72 = 0;
          while ( v53 - 1LL != v72 )
          {
            v73 = v85[++v72];
            if ( v73 == v69 )
            {
              if ( v72 >= v53 )
                break;
              goto LABEL_67;
            }
          }
        }
        *a7 = result + 1;
        *(_DWORD *)(v52 + 4 * result) = v69;
LABEL_67:
        ;
      }
    }
    if ( v55 )
    {
      for ( m = 0; m != v55; ++m )
      {
        result = *a7;
        if ( (unsigned int)result >= v67 )
          return result;
        v75 = v83[m];
        if ( (_DWORD)v66 )
        {
          if ( *a4 == v75 )
            continue;
          v76 = 0;
          while ( v66 - 1 != v76 )
          {
            v77 = a4[++v76];
            if ( v77 == v75 )
            {
              if ( v76 < v66 )
                goto LABEL_85;
              break;
            }
          }
        }
        if ( v53 )
        {
          if ( *v85 == v75 )
            continue;
          v78 = 0;
          while ( v53 - 1LL != v78 )
          {
            v79 = v85[++v78];
            if ( v79 == v75 )
            {
              if ( v78 >= v53 )
                break;
              goto LABEL_85;
            }
          }
        }
        *a7 = result + 1;
        *(_DWORD *)(v52 + 4 * result) = v75;
LABEL_85:
        ;
      }
    }
  }
  else
  {
    result = qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v20, v21, v22, v23, v24, v25, v26, v27, "get_sub_channels");
    *a5 = 0;
    *a3 = 0;
    *a7 = 0;
  }
  return result;
}
