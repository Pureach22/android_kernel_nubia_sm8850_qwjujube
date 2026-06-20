__int64 __fastcall ieee80211_do_open(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 v3; // x22
  __int64 v5; // x20
  __int64 v7; // x24
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w8
  void *v12; // x9
  unsigned int v13; // w24
  __int64 result; // x0
  __int64 *v15; // x1
  __int64 *v16; // x2
  __int64 *v17; // x0
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x12
  int v25; // w9
  int v26; // w8
  __int64 v27; // x9
  __int64 v28; // x9
  unsigned int v29; // w8
  void *v30; // x9
  int *v31; // x8
  int v32; // w11
  unsigned int v33; // w21
  int v34; // w8
  _QWORD *v35; // x9
  __int64 *v36; // x8
  __int64 v37; // x10
  int v38; // w8
  int v39; // w9
  _DWORD *v40; // x8
  _BOOL4 v41; // w8
  int v42; // w11
  _BOOL4 v43; // w9
  unsigned int v44; // w8
  unsigned int v45; // w9
  unsigned int v46; // w10
  unsigned int v47; // w12
  __int64 v48; // x11
  unsigned int v49; // w9
  unsigned int v50; // w12
  unsigned int v51; // w12
  unsigned int v52; // w12
  unsigned int v53; // w10
  int v54; // w9
  void (__fastcall *v55)(__int64, __int64, __int64, __int64); // x8
  int v56; // w8
  __int64 v57; // x2
  unsigned int v58; // w8
  int v59; // w8
  int v60; // w8
  unsigned __int64 v61; // x0
  unsigned __int64 *v62; // x1
  __int64 v63; // x2
  int v64; // w8
  int v65; // w8
  unsigned __int64 v68; // x9
  unsigned __int64 v75; // x10
  unsigned int v78; // w9

  v2 = *(_DWORD *)(a1 + 4704);
  v3 = *(_QWORD *)(a1 + 32);
  v5 = *(_QWORD *)(a1 + 1600);
  v7 = a1 + 4096;
  if ( v2 <= 0xD )
  {
    if ( ((1 << v2) & 0x2321) != 0 )
    {
      __break(0x800u);
    }
    else if ( v2 == 3 )
    {
      *(_QWORD *)(a1 + 2016) = a1 + 2248;
    }
    else if ( v2 == 4 )
    {
      v15 = *(__int64 **)(a1 + 2016);
      if ( !v15 )
        return 4294967229LL;
      v16 = (__int64 *)*v15;
      v17 = (__int64 *)(a1 + 2248);
      if ( *(__int64 **)(*v15 + 8) != v15 || v17 == v15 || v16 == v17 )
      {
        _list_add_valid_or_report(v17, v15);
      }
      else
      {
        v16[1] = (__int64)v17;
        *(_QWORD *)(a1 + 2248) = v16;
        *(_QWORD *)(a1 + 2256) = v15;
        *v15 = (__int64)v17;
      }
      v18 = *(_QWORD *)(a1 + 2016);
      *(_WORD *)(a1 + 1924) = *(_WORD *)(v18 - 324);
      *(_BYTE *)(a1 + 1926) = *(_BYTE *)(v18 - 322);
      *(_BYTE *)(a1 + 1928) = *(_BYTE *)(v18 - 320);
      *(_BYTE *)(a1 + 1927) = *(_BYTE *)(v18 - 321);
      *(_BYTE *)(v7 + 1737) = *(_BYTE *)(v18 + 3585);
      *(_DWORD *)(v7 + 1738) = *(_DWORD *)(v18 + 3586);
      v19 = *(_QWORD *)(v18 + 2728);
      v20 = *(_QWORD *)(v18 + 2712);
      v21 = *(_QWORD *)(v18 + 2720);
      *(_QWORD *)(a1 + 4984) = *(_QWORD *)(v18 + 2736);
      *(_QWORD *)(a1 + 4976) = v19;
      *(_QWORD *)(a1 + 4968) = v21;
      *(_QWORD *)(a1 + 4960) = v20;
      v22 = *(_QWORD *)(v18 + 2696);
      v23 = *(_QWORD *)(v18 + 2680);
      v24 = *(_QWORD *)(v18 + 2688);
      *(_QWORD *)(a1 + 4952) = *(_QWORD *)(v18 + 2704);
      v25 = *(_DWORD *)(a1 + 1512);
      *(_QWORD *)(a1 + 4944) = v22;
      *(_QWORD *)(a1 + 4936) = v24;
      *(_QWORD *)(a1 + 4928) = v23;
      *(_DWORD *)(a1 + 1512) = v25 + *(_DWORD *)(v18 - 736);
    }
  }
  if ( !*(_DWORD *)(v5 + 1316) )
  {
    *(_BYTE *)(v5 + 1471) = 0;
    result = drv_start(v5);
    if ( (_DWORD)result )
      goto LABEL_57;
  }
  if ( !v3
    || **(_DWORD **)(v3 + 1008) | *(unsigned __int16 *)(*(_QWORD *)(v3 + 1008) + 4LL)
    || (dev_addr_mod(v3, 0, *(_QWORD *)(v5 + 72) + 48LL, 6),
        v31 = *(int **)(v3 + 1008),
        v32 = *v31,
        *(_WORD *)(v3 + 795) = *((_WORD *)v31 + 2),
        *(_DWORD *)(v3 + 791) = v32,
        (*v31 & 1) == 0)
    && *v31 | *((unsigned __int16 *)v31 + 2) )
  {
    v8 = *(_DWORD *)(a1 + 4704);
    if ( v8 != 6 )
    {
      if ( v8 == 4 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 2016) + 317LL) == 1 )
        {
          ieee80211_link_vlan_copy_chanctx(a1 + 3600);
          netif_carrier_on(v3);
          v9 = a1 - 16;
          if ( *(_DWORD *)(a1 + 4704) == 4 )
          {
            v10 = *(_QWORD *)(a1 + 2016);
            if ( !v10 )
            {
              v13 = 0;
              if ( (*(_BYTE *)(a1 + 1608) & 1) != 0 )
              {
LABEL_162:
                _X8 = (unsigned int *)(v5 + 2528);
                __asm { PRFM            #0x11, [X8] }
                do
                  v78 = __ldxr(_X8);
                while ( __stxr(v78 + 1, _X8) );
                v64 = *(_DWORD *)(v5 + 1316);
                if ( (a2 & 1) != 0 )
                {
LABEL_149:
                  v65 = v64 + 1;
                  *(_DWORD *)(v5 + 1316) = v65;
                  if ( v65 != 1 )
                  {
LABEL_150:
                    if ( v13 )
                      ieee80211_hw_config(v5, v13);
                    goto LABEL_152;
                  }
LABEL_141:
                  ieee80211_hw_conf_init(v5);
LABEL_152:
                  ieee80211_recalc_ps(v5);
                  _X8 = (unsigned __int64 *)(a1 + 1616);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v68 = __ldxr(_X8);
                  while ( __stxr(v68 | 1, _X8) );
                  return 0;
                }
LABEL_140:
                if ( v64 != 1 )
                  goto LABEL_150;
                goto LABEL_141;
              }
LABEL_148:
              v64 = *(_DWORD *)(v5 + 1316);
              if ( (a2 & 1) != 0 )
                goto LABEL_149;
              goto LABEL_140;
            }
            v9 = v10 - 2264;
          }
          if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1600) + 96LL) & 0x1000000000000LL) != 0
            && (*(_DWORD *)(v9 + 4720) & 0xFFFFFFFE) == 2 )
          {
            v11 = *(_DWORD *)(v9 + 5876);
            if ( *(_BYTE *)(a1 + 65) == 1 )
              v11 &= (unsigned __int8)(v11 & 2) >> 1;
            v12 = &ieee80211_dataif_ops;
            if ( (v11 & 1) != 0 )
              v12 = &ieee80211_dataif_8023_ops;
            v13 = 0;
            *(_QWORD *)(*(_QWORD *)(a1 + 1592) + 8LL) = v12;
LABEL_136:
            v60 = *(_DWORD *)(a1 + 4704);
            if ( v60 == 6 )
            {
              if ( (*(_BYTE *)(a1 + 2248) & 0x20) == 0 )
              {
                v61 = a1 + 2264;
                v62 = *(unsigned __int64 **)(v5 + 4640);
                v63 = v5 + 4632;
                if ( a1 + 2264 == v5 + 4632 || v62 == (unsigned __int64 *)v61 || *v62 != v63 )
                {
                  _list_add_valid_or_report(v61, v62);
                  if ( (*(_BYTE *)(a1 + 1608) & 1) != 0 )
                    goto LABEL_162;
                  goto LABEL_148;
                }
                *(_QWORD *)(a1 + 2264) = v63;
                *(_QWORD *)(a1 + 2272) = v62;
                atomic_store(v61, v62);
                *(_QWORD *)(v5 + 4640) = v61;
              }
            }
            else if ( v60 == 10 )
            {
              atomic_store(a1 - 16, (unsigned __int64 *)(v5 + 5376));
              if ( (*(_BYTE *)(a1 + 1608) & 1) != 0 )
                goto LABEL_162;
              goto LABEL_148;
            }
            if ( (*(_BYTE *)(a1 + 1608) & 1) != 0 )
              goto LABEL_162;
            goto LABEL_148;
          }
        }
        else
        {
          netif_carrier_off(v3);
        }
LABEL_135:
        v13 = 0;
        goto LABEL_136;
      }
      if ( (a2 & 1) == 0 )
        goto LABEL_117;
      ieee80211_del_virtual_monitor(v5);
      ieee80211_set_sdata_offload_flags(a1 - 16);
      result = drv_add_interface(v5, a1 - 16);
      if ( !(_DWORD)result )
      {
        v8 = *(_DWORD *)(a1 + 4704);
        v27 = a1 - 16;
        if ( v8 == 4 )
        {
          v28 = *(_QWORD *)(a1 + 2016);
          if ( !v28 )
          {
            v8 = 4;
            goto LABEL_94;
          }
          v27 = v28 - 2264;
        }
        if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1600) + 96LL) & 0x1000000000000LL) != 0
          && (*(_DWORD *)(v27 + 4720) & 0xFFFFFFFE) == 2 )
        {
          v29 = *(_DWORD *)(v27 + 5876);
          if ( *(_BYTE *)(a1 + 65) == 1 )
            v29 = *(_DWORD *)(v27 + 5876) & ((*(_DWORD *)(v27 + 5876) & 2u) >> 1);
          v30 = &ieee80211_dataif_ops;
          if ( (v29 & 1) != 0 )
            v30 = &ieee80211_dataif_8023_ops;
          *(_QWORD *)(*(_QWORD *)(a1 + 1592) + 8LL) = v30;
          v8 = *(_DWORD *)(a1 + 4704);
        }
LABEL_94:
        if ( *(_BYTE *)(v7 + 1736) == 1 && v8 <= 9 )
        {
          if ( v8 == 2 )
          {
            v46 = 8;
            goto LABEL_103;
          }
          if ( v8 == 3 )
          {
            v46 = 9;
LABEL_103:
            v47 = *(unsigned __int8 *)(v7 + 1738);
            if ( v47 != 255 )
            {
              v48 = *(_QWORD *)(a1 + 1600);
              v49 = *(unsigned __int16 *)(v48 + 128);
              if ( v49 > v47 )
              {
                v50 = *(unsigned __int8 *)(v7 + 1739);
                if ( v50 != 255 && v49 > v50 )
                {
                  v51 = *(unsigned __int8 *)(v7 + 1740);
                  if ( v51 != 255 && v49 > v51 )
                  {
                    v52 = *(unsigned __int8 *)(v7 + 1741);
                    if ( v52 != 255 && v49 > v52 )
                    {
                      if ( v46 > 9 || ((1 << v46) & 0x288) == 0 || (*(_QWORD *)(v48 + 96) & 0x40000) == 0 )
                        goto LABEL_114;
                      v53 = *(unsigned __int8 *)(v7 + 1737);
                      if ( v53 != 255 && v49 > v53 )
                      {
LABEL_117:
                        if ( v8 == 1 )
                        {
                          ++*(_DWORD *)(v5 + 1348);
                        }
                        else if ( v8 == 3 )
                        {
                          v54 = *(_DWORD *)(v5 + 1348) + 1;
                          ++*(_DWORD *)(v5 + 1344);
                          *(_DWORD *)(v5 + 1348) = v54;
                          ieee80211_configure_filter(v5);
                        }
LABEL_121:
                        if ( *(_BYTE *)(v7 + 1768) == 1 )
                        {
                          v55 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v5 + 464) + 136LL);
                          if ( v55 )
                          {
                            if ( *((_DWORD *)v55 - 1) != 1677116977 )
                              __break(0x8228u);
                            v55(v5, a1 + 4704, 256, 256);
                          }
                        }
                        v56 = *(_DWORD *)(a1 + 4704);
                        v57 = 0;
                        if ( v56 != 10 && v56 != 12 )
                          v57 = ieee80211_reset_erp_info(a1 - 16);
                        ieee80211_link_info_change_notify(a1 - 16, a1 + 3600, v57);
                        v58 = *(_DWORD *)(a1 + 4704);
                        if ( v58 <= 0xC )
                        {
                          v59 = 1 << v58;
                          if ( (v59 & 0x88E) != 0 )
                          {
                            netif_carrier_off(v3);
LABEL_134:
                            ieee80211_set_wmm_default(a1 + 3600, 1, *(_DWORD *)(a1 + 4704) != 2);
                            goto LABEL_135;
                          }
                          if ( (v59 & 0x1400) != 0 )
                            goto LABEL_134;
                        }
                        __break(0x800u);
                        goto LABEL_134;
                      }
                    }
                  }
                }
              }
            }
            __break(0x800u);
            drv_remove_interface(v5, a1 - 16);
            result = 4294967274LL;
            if ( *(_DWORD *)(v5 + 1316) )
              goto LABEL_57;
            goto LABEL_51;
          }
        }
        else
        {
          if ( v8 == 10 )
          {
LABEL_114:
            *(_BYTE *)(v7 + 1737) = -1;
            goto LABEL_117;
          }
          if ( v8 == 12 )
            goto LABEL_121;
        }
        v46 = v8;
        goto LABEL_103;
      }
LABEL_56:
      if ( *(_DWORD *)(v5 + 1316) )
        goto LABEL_57;
      goto LABEL_51;
    }
    v26 = *(_DWORD *)(a1 + 2248);
    if ( (v26 & 0x20) != 0 )
    {
      v13 = 0;
      ++*(_DWORD *)(v5 + 1324);
      goto LABEL_136;
    }
    if ( (v26 & 0x40) != 0 )
    {
      result = drv_add_interface(v5, a1 - 16);
      if ( (_DWORD)result )
        goto LABEL_56;
    }
    else if ( !*(_DWORD *)(v5 + 1320) && !*(_DWORD *)(v5 + 1316) )
    {
      result = ieee80211_add_virtual_monitor(v5);
      if ( (_DWORD)result )
        goto LABEL_56;
    }
    v38 = *(_DWORD *)(v5 + 1320);
    *(_DWORD *)(v5 + 1320) = v38 + 1;
    if ( v38 )
    {
      v13 = 0;
    }
    else
    {
      v13 = 8;
      *(_DWORD *)v5 |= 1u;
    }
    v39 = *(_DWORD *)(a1 + 2248);
    v40 = *(_DWORD **)(a1 + 1600);
    if ( (v39 & 2) != 0 )
    {
      ++v40[332];
      if ( (v39 & 4) == 0 )
      {
LABEL_69:
        if ( (v39 & 8) == 0 )
          goto LABEL_70;
        goto LABEL_76;
      }
    }
    else if ( (v39 & 4) == 0 )
    {
      goto LABEL_69;
    }
    ++v40[333];
    if ( (v39 & 8) == 0 )
    {
LABEL_70:
      if ( (v39 & 0x10) == 0 )
        goto LABEL_72;
      goto LABEL_71;
    }
LABEL_76:
    v42 = v40[336] + 1;
    ++v40[334];
    v40[336] = v42;
    if ( (v39 & 0x10) == 0 )
    {
LABEL_72:
      ieee80211_configure_filter(v5);
      ieee80211_recalc_offload(v5);
      v41 = *(_QWORD *)(v5 + 4984) != v5 + 4984 || *(_DWORD *)(v5 + 1320) != 0;
      if ( *(_QWORD *)(*(_QWORD *)(v5 + 464) + 472LL) )
      {
        v43 = 0;
        if ( (*(_QWORD *)(v5 + 4696) & 1) != 0 )
          goto LABEL_84;
      }
      else
      {
        v43 = *(_QWORD *)(v5 + 5264) != v5 + 5264;
        if ( (*(_QWORD *)(v5 + 4696) & 1) != 0 )
          goto LABEL_84;
      }
      if ( ((v43 || v41) | (*(_QWORD *)(v5 + 4696) >> 2) & 1) != 1 )
      {
        if ( (*(_BYTE *)v5 & 4) == 0 )
        {
          ieee80211_flush_queues(v5, 0, 0);
          v44 = *(_DWORD *)v5 | 4;
          goto LABEL_90;
        }
LABEL_91:
        netif_carrier_on(v3);
        goto LABEL_136;
      }
LABEL_84:
      if ( (*(_DWORD *)v5 & 4) != 0 )
      {
        v44 = *(_DWORD *)v5 & 0xFFFFFFFB;
LABEL_90:
        *(_DWORD *)v5 = v44;
        ieee80211_hw_config(v5, 256);
        goto LABEL_91;
      }
      goto LABEL_91;
    }
LABEL_71:
    ++v40[335];
    goto LABEL_72;
  }
  result = 4294967197LL;
  if ( !*(_DWORD *)(v5 + 1316) )
  {
LABEL_51:
    v33 = result;
    drv_stop(v5);
    result = v33;
  }
LABEL_57:
  v34 = *(_DWORD *)(a1 + 4704);
  *(_QWORD *)(a1 + 2016) = 0;
  if ( v34 == 4 )
  {
    v35 = *(_QWORD **)(a1 + 2256);
    v36 = (__int64 *)(a1 + 2248);
    if ( *v35 == a1 + 2248 && (v37 = *v36, *(__int64 **)(*v36 + 8) == v36) )
    {
      *(_QWORD *)(v37 + 8) = v35;
      *v35 = v37;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 2248);
      result = v45;
    }
    *(_QWORD *)(a1 + 2248) = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 2256) = 0xDEAD000000000122LL;
  }
  _X8 = (unsigned __int64 *)(a1 + 1616);
  __asm { PRFM            #0x11, [X8] }
  do
    v75 = __ldxr(_X8);
  while ( __stxr(v75 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  return result;
}
