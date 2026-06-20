__int64 __fastcall drm_dp_send_link_address(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x24
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x19
  unsigned __int64 v9; // x22
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w0
  unsigned __int64 v14; // x26
  int v15; // w22
  _QWORD *v16; // x23
  int v17; // w8
  __int64 v18; // x20
  __int64 v19; // x21
  _QWORD *v20; // x27
  char *v21; // x24
  int v22; // w8
  int v23; // w22
  unsigned int v24; // w8
  unsigned int v25; // w19
  unsigned int v31; // w9
  __int64 v32; // x8
  __int64 v33; // x1
  int v34; // w12
  _QWORD *v35; // x8
  __int64 v36; // x9
  __int64 v37; // x0
  char v38; // w13
  _BOOL4 v39; // w11
  char v40; // w8
  __int64 v41; // x19
  __int64 v42; // x1
  int v43; // w21
  char v44; // w8
  unsigned int v45; // w22
  char v46; // w27
  int v47; // w20
  __int64 v48; // x8
  __int64 v49; // x1
  _DWORD *v50; // x24
  __int64 v51; // x2
  unsigned int v52; // w0
  char v53; // w20
  unsigned int v54; // w20
  int v55; // w0
  int v56; // w8
  __int64 v57; // x1
  unsigned int v58; // w0
  __int64 v59; // x1
  unsigned int v61; // w8
  char v62; // w26
  unsigned __int64 v63; // x19
  _QWORD *v64; // x23
  __int64 v65; // x28
  _QWORD *v66; // t1
  int v67; // w4
  _QWORD *v68; // x21
  __int64 v69; // x8
  __int64 v70; // x1
  _QWORD *v71; // x8
  _QWORD *v72; // x9
  unsigned int v73; // w19
  __int64 v74; // x8
  unsigned int v75; // w21
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  __int64 v79; // x3
  __int64 v80; // x8
  __int64 v81; // x0
  unsigned __int64 v82; // x8
  __int64 v83; // x9
  int v84; // w11
  unsigned int v85; // w21
  __int64 v86; // x0
  _DWORD *v87; // x0
  _QWORD *v88; // x8
  __int64 v89; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v92; // x20
  unsigned int v93; // [xsp+3Ch] [xbp-C4h]
  _DWORD *v94; // [xsp+40h] [xbp-C0h]
  __int64 v95; // [xsp+48h] [xbp-B8h]
  __int64 v96; // [xsp+50h] [xbp-B0h]
  __int64 v97; // [xsp+58h] [xbp-A8h]
  int v98; // [xsp+60h] [xbp-A0h]
  int v99; // [xsp+64h] [xbp-9Ch]
  char s[8]; // [xsp+68h] [xbp-98h] BYREF
  __int64 v101; // [xsp+70h] [xbp-90h]
  __int64 v102; // [xsp+78h] [xbp-88h]
  __int64 v103; // [xsp+80h] [xbp-80h]
  __int64 v104; // [xsp+88h] [xbp-78h]
  __int64 v105; // [xsp+90h] [xbp-70h]
  __int64 v106; // [xsp+98h] [xbp-68h]
  __int64 v107; // [xsp+A0h] [xbp-60h]
  __int64 v108; // [xsp+A8h] [xbp-58h]
  __int64 v109; // [xsp+B0h] [xbp-50h]
  __int64 v110; // [xsp+B8h] [xbp-48h]
  __int64 v111; // [xsp+C0h] [xbp-40h]
  __int64 v112; // [xsp+C8h] [xbp-38h]
  __int64 v113; // [xsp+D0h] [xbp-30h]
  __int64 v114; // [xsp+D8h] [xbp-28h]
  _QWORD v115[4]; // [xsp+E0h] [xbp-20h] BYREF

  _X25 = a1;
  v115[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( !v4 )
  {
LABEL_180:
    result = 4294967284LL;
    goto LABEL_181;
  }
  while ( 1 )
  {
    *(_QWORD *)(v4 + 312) = a2;
    v113 = 0;
    v114 = 0;
    v111 = 0;
    v112 = 0;
    v109 = 0;
    v110 = 0;
    v107 = 0;
    v108 = 0;
    v105 = 0;
    v106 = 0;
    v103 = 0;
    v104 = 0;
    v101 = 0;
    v102 = 0;
    *(_QWORD *)s = 1;
    ((void (__fastcall *)(char *, __int64))drm_dp_encode_sideband_req)(s, v4);
    *(_BYTE *)(a2 + 72) = 1;
    drm_dp_queue_down_tx(_X25, v4);
    v5 = drm_dp_mst_wait_tx_reply(a2, v4);
    if ( (v5 & 0x80000000) != 0 )
    {
      v74 = *((_QWORD *)_X25 + 13);
      v75 = v5;
      if ( v74 )
        v76 = *(_QWORD *)(v74 + 8);
      else
        v76 = 0;
      dev_err(v76, "[drm] *ERROR* Sending link address failed with %d\n", v75);
      v73 = v75;
      goto LABEL_175;
    }
    if ( *(_BYTE *)(v4 + 346) == 1 )
    {
      v77 = *((_QWORD *)_X25 + 13);
      if ( v77 )
        v78 = *(_QWORD *)(v77 + 8);
      else
        v78 = 0;
      dev_err(v78, "[drm] *ERROR* link address NAK received\n");
      v73 = -5;
      goto LABEL_175;
    }
    v6 = *((_QWORD *)_X25 + 13);
    if ( v6 )
      v7 = *(_QWORD *)(v6 + 8);
    else
      v7 = 0;
    _drm_dev_dbg(0, v7, 2, "link address reply: %d\n", *(unsigned __int8 *)(v4 + 364));
    if ( *(_BYTE *)(v4 + 364) )
    {
      v8 = 0;
      v9 = 0;
      while ( v8 != 425 )
      {
        v11 = *((_QWORD *)_X25 + 13);
        if ( v11 )
          v12 = *(_QWORD *)(v11 + 8);
        else
          v12 = 0;
        if ( (unsigned __int64)(v8 - 403) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 402) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 401) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 397) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 401) < 0xFFFFFFFFFFFFFCFFLL
          || (unsigned __int64)(v8 - 399) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 398) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 380) < 0xFFFFFFFFFFFFFD00LL
          || (unsigned __int64)(v8 - 379) < 0xFFFFFFFFFFFFFD00LL )
        {
          goto LABEL_178;
        }
        v10 = v4 + 365;
        _drm_dev_dbg(
          0,
          v12,
          2,
          "port %d: input %d, pdt: %d, pn: %d, dpcd_rev: %02x, mcs: %d, ddps: %d, ldps %d, sdp %d/%d\n",
          v9++,
          *(unsigned __int8 *)(v10 + v8),
          *(unsigned __int8 *)(v10 + v8 + 1),
          *(unsigned __int8 *)(v10 + v8 + 2),
          *(unsigned __int8 *)(v10 + v8 + 6),
          *(unsigned __int8 *)(v10 + v8 + 3),
          *(unsigned __int8 *)(v10 + v8 + 4),
          *(unsigned __int8 *)(v10 + v8 + 5),
          *(unsigned __int8 *)(v10 + v8 + 23),
          *(unsigned __int8 *)(v10 + v8 + 24));
        v8 += 25;
        if ( v9 >= *(unsigned __int8 *)(v4 + 364) )
          goto LABEL_23;
      }
      goto LABEL_179;
    }
LABEL_23:
    v13 = drm_dp_check_mstb_guid((_QWORD *)a2, (_QWORD *)(v4 + 348));
    if ( v13 )
      break;
    if ( !*(_BYTE *)(v4 + 364) )
    {
      v62 = 0;
      v63 = 0;
      goto LABEL_130;
    }
    v14 = 0;
    v95 = v4;
    v96 = v4 + 365;
    v15 = 0;
    v16 = (_QWORD *)(a2 + 40);
    v98 = 0;
    v94 = _X25;
    while ( 2 )
    {
      if ( v14 != 16 )
      {
        v18 = 25 * v14;
        v19 = *(_QWORD *)(a2 + 64);
        v20 = (_QWORD *)(a2 + 40);
        v97 = *((_QWORD *)_X25 + 13);
        v21 = (char *)(v96 + 25 * v14);
        v22 = (unsigned __int8)v21[2];
        v23 = v15 | (1LL << v22);
        do
        {
          v20 = (_QWORD *)*v20;
          if ( v20 == v16 )
            goto LABEL_57;
        }
        while ( *((unsigned __int8 *)v20 - 16) != v22 );
        _X25 = v20 - 3;
        v24 = *((_DWORD *)v20 - 6);
        if ( v24 )
        {
          do
          {
            __asm { PRFM            #0x11, [X25] }
            do
              v31 = __ldxr(_X25);
            while ( v31 == v24 && __stxr(v24 + 1, _X25) );
            v25 = v24;
            if ( v31 == v24 )
              break;
            v25 = 0;
            v24 = v31;
          }
          while ( v31 );
        }
        else
        {
          v25 = 0;
        }
        if ( (((v25 + 1) | v25) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(v20 - 3, 0);
          if ( !v25 )
            goto LABEL_57;
        }
        else if ( !v25 )
        {
          goto LABEL_57;
        }
        v32 = *(_QWORD *)(v20[201] + 104LL);
        if ( v32 )
          v33 = *(_QWORD *)(v32 + 8);
        else
          v33 = 0;
        _drm_dev_dbg(0, v33, 1, "port %p (%d)\n", v20 - 3, *_X25);
        if ( v20 == &_ksymtab_drm_atomic_get_new_mst_topology_state )
          goto LABEL_57;
        if ( (*((_BYTE *)v20 - 15) & 1) != 0 )
        {
          if ( !*v21 )
          {
            v34 = 0;
LABEL_116:
            v38 = 0;
            goto LABEL_59;
          }
        }
        else if ( *v21 && v20[200] )
        {
          mutex_lock(v19 + 800);
          --*(_DWORD *)(v20[199] + 36LL);
          v35 = (_QWORD *)v20[1];
          if ( (_QWORD *)*v35 == v20 && (v36 = *v20, *(_QWORD **)(*v20 + 8LL) == v20) )
          {
            *(_QWORD *)(v36 + 8) = v35;
            *v35 = v36;
          }
          else
          {
            _list_del_entry_valid_or_report(v20);
          }
          *v20 = 0xDEAD000000000100LL;
          v20[1] = 0xDEAD000000000122LL;
          mutex_unlock(v19 + 800);
          drm_dp_mst_topology_put_port(v20 - 3);
          drm_dp_mst_topology_put_port(v20 - 3);
LABEL_57:
          v37 = drm_dp_mst_add_port(v97, v19, a2, (unsigned __int8)v21[2]);
          if ( !v37 )
          {
            v4 = v95;
            v73 = -12;
            goto LABEL_175;
          }
          _X25 = (_DWORD *)v37;
          v34 = 0;
          v38 = 1;
LABEL_59:
          v39 = 1;
          goto LABEL_60;
        }
        if ( v20[200] )
        {
          drm_modeset_lock(v19 + 16, 0);
          if ( (unsigned __int64)(v18 - 399) < 0xFFFFFFFFFFFFFD00LL )
            goto LABEL_178;
          v34 = *((unsigned __int8 *)v20 - 13);
          if ( v34 != (unsigned __int8)v21[4] )
            goto LABEL_116;
          if ( *((_BYTE *)v20 - 13) )
          {
            if ( (unsigned __int64)(v18 - 398) < 0xFFFFFFFFFFFFFD00LL )
              goto LABEL_178;
            if ( *((unsigned __int8 *)v20 - 11) != (unsigned __int8)v21[5] )
              goto LABEL_116;
            if ( (unsigned __int64)(v18 - 397) < 0xFFFFFFFFFFFFFD00LL )
              goto LABEL_178;
            if ( *((unsigned __int8 *)v20 - 10) != (unsigned __int8)v21[6]
              || *((unsigned __int8 *)v20 - 14) != (unsigned __int8)v21[3]
              || *((unsigned __int8 *)v20 - 12) != (unsigned __int8)v21[1] )
            {
              goto LABEL_116;
            }
            if ( (unsigned __int64)(v18 - 379) < 0xFFFFFFFFFFFFFD00LL )
              goto LABEL_178;
            v38 = 0;
            v39 = *((unsigned __int8 *)v20 - 8) != (unsigned __int8)v21[24];
            goto LABEL_60;
          }
        }
        else
        {
          v34 = 0;
        }
        v38 = 0;
        v39 = 0;
LABEL_60:
        v40 = *v21;
        v41 = v19;
        *((_BYTE *)_X25 + 9) = *v21;
        if ( (v40 & 1) != 0 )
          v42 = 0;
        else
          v42 = (unsigned __int8)v21[1];
        if ( (unsigned __int64)(v18 - 399) >= 0xFFFFFFFFFFFFFD00LL )
        {
          v43 = v23;
          v44 = v21[4];
          v45 = (unsigned __int8)v21[3];
          *((_BYTE *)_X25 + 11) = v44;
          if ( (unsigned __int64)(v18 - 398) >= 0xFFFFFFFFFFFFFD00LL )
          {
            *((_BYTE *)_X25 + 13) = v21[5];
            if ( (unsigned __int64)(v18 - 397) >= 0xFFFFFFFFFFFFFD00LL )
            {
              *((_BYTE *)_X25 + 14) = v21[6];
              if ( (unsigned __int64)(v18 - 380) >= 0xFFFFFFFFFFFFFD00LL )
              {
                *((_BYTE *)_X25 + 15) = v21[23];
                if ( (unsigned __int64)(v18 - 379) >= 0xFFFFFFFFFFFFFD00LL )
                {
                  v99 = v39;
                  *((_BYTE *)_X25 + 16) = v21[24];
                  if ( (v38 & 1) != 0 )
                  {
                    v93 = v42;
                    v46 = v38;
                    v47 = v34;
                    mutex_lock(v41 + 800);
                    if ( !*_X25 )
                      __break(0x800u);
                    __asm { PRFM            #0x11, [X25] }
                    do
                      v61 = __ldxr(_X25);
                    while ( __stxr(v61 + 1, _X25) );
                    if ( v61 )
                    {
                      if ( (((v61 + 1) | v61) & 0x80000000) != 0 )
                      {
                        v59 = 1;
                        goto LABEL_127;
                      }
                    }
                    else
                    {
                      v59 = 2;
LABEL_127:
                      refcount_warn_saturate(_X25, v59);
                    }
                    v48 = *(_QWORD *)(*((_QWORD *)_X25 + 204) + 104LL);
                    if ( v48 )
                      v49 = *(_QWORD *)(v48 + 8);
                    else
                      v49 = 0;
                    v50 = _X25 + 6;
                    _drm_dev_dbg(0, v49, 1, "port %p (%d)\n", _X25, *_X25);
                    v51 = *v16;
                    if ( *(_QWORD **)(*v16 + 8LL) != v16 || v50 == (_DWORD *)v16 || (_DWORD *)v51 == v50 )
                    {
                      _list_add_valid_or_report(_X25 + 6);
                    }
                    else
                    {
                      *(_QWORD *)(v51 + 8) = v50;
                      *((_QWORD *)_X25 + 3) = v51;
                      *((_QWORD *)_X25 + 4) = v16;
                      *v16 = v50;
                    }
                    ++*(_DWORD *)(a2 + 36);
                    mutex_unlock(v41 + 800);
                    if ( v47 == *((unsigned __int8 *)_X25 + 11) )
                    {
                      v52 = drm_dp_port_set_pdt(_X25, v93, v45);
                      v53 = v52 == 1;
                      if ( (v52 & 0x80000000) == 0 )
                      {
                        v4 = v95;
                        v15 = v43;
                        goto LABEL_96;
                      }
LABEL_165:
                      v4 = v95;
                      v85 = v52;
                      if ( v97 )
                        v86 = *(_QWORD *)(v97 + 8);
                      else
                        v86 = 0;
                      dev_err(v86, "[drm] *ERROR* Failed to change PDT on port %p: %d\n", _X25, v85);
                      mutex_lock(v41 + 800);
                      v87 = _X25 + 6;
                      --*(_DWORD *)(*((_QWORD *)_X25 + 202) + 36LL);
                      v88 = *((_QWORD **)_X25 + 4);
                      if ( (_DWORD *)*v88 == _X25 + 6
                        && (v89 = *(_QWORD *)v87, *(_DWORD **)(*(_QWORD *)v87 + 8LL) == v87) )
                      {
                        *(_QWORD *)(v89 + 8) = v88;
                        *v88 = v89;
                      }
                      else
                      {
                        _list_del_entry_valid_or_report(v87);
                      }
                      *((_QWORD *)_X25 + 3) = 0xDEAD000000000100LL;
                      *((_QWORD *)_X25 + 4) = 0xDEAD000000000122LL;
                      mutex_unlock(v41 + 800);
                      drm_dp_mst_topology_put_port(_X25);
                      if ( *((_QWORD *)_X25 + 203) )
                        drm_modeset_unlock(v41 + 16);
                      v58 = v85;
LABEL_174:
                      v73 = v58;
                      drm_dp_mst_topology_put_port(_X25);
LABEL_175:
                      *(_BYTE *)(a2 + 72) = 0;
                      goto LABEL_176;
                    }
                    v42 = v93;
                    if ( *((_BYTE *)_X25 + 11) )
                    {
LABEL_86:
                      if ( (*((_BYTE *)_X25 + 9) & 1) != 0 )
                        goto LABEL_87;
                      v54 = v42;
                      v55 = drm_dp_send_enum_path_resources(v41, a2, _X25);
                      v56 = v99;
                      v42 = v54;
                      if ( v55 == 1 )
                        v56 = 1;
                      v99 = v56;
LABEL_91:
                      v52 = drm_dp_port_set_pdt(_X25, v42, v45);
                      v53 = v52 == 1;
                      if ( (v52 & 0x80000000) != 0 )
                        goto LABEL_165;
                      v4 = v95;
                      if ( (v46 & 1) != 0 )
                      {
                        v15 = v43;
                      }
                      else
                      {
                        v15 = v43;
                        if ( *((_BYTE *)_X25 + 12) == 2 )
                          v53 = (v52 == 1) | *((_BYTE *)_X25 + 10);
                      }
LABEL_96:
                      if ( *((_QWORD *)_X25 + 203) )
                      {
                        drm_modeset_unlock(v41 + 16);
                      }
                      else if ( (*((_BYTE *)_X25 + 9) & 1) == 0 )
                      {
                        drm_dp_mst_port_add_connector(a2, _X25);
                      }
                      if ( (v53 & 1) != 0 )
                      {
                        v57 = *((_QWORD *)_X25 + 5);
                        if ( v57 )
                        {
                          v58 = drm_dp_send_link_address(v41, v57);
                          if ( v58 == 1 )
                          {
                            drm_dp_mst_topology_put_port(_X25);
                            v17 = 1;
LABEL_28:
                            v98 = v17;
                            ++v14;
                            _X25 = v94;
                            if ( v14 < *(unsigned __int8 *)(v4 + 364) )
                              continue;
                            v63 = v15;
                            v62 = v17;
LABEL_130:
                            mutex_lock(_X25 + 200);
                            v66 = *(_QWORD **)(a2 + 40);
                            v65 = a2 + 40;
                            v64 = v66;
                            if ( v66 != (_QWORD *)v65 )
                            {
                              do
                              {
                                v67 = *((unsigned __int8 *)v64 - 16);
                                v68 = (_QWORD *)*v64;
                                if ( ((v63 >> v67) & 1) == 0 )
                                {
                                  v69 = *((_QWORD *)_X25 + 13);
                                  if ( v69 )
                                    v70 = *(_QWORD *)(v69 + 8);
                                  else
                                    v70 = 0;
                                  _drm_dev_dbg(0, v70, 2, "port %d was not in link address, removing\n", v67);
                                  v71 = (_QWORD *)v64[1];
                                  if ( (_QWORD *)*v71 == v64 && (v72 = (_QWORD *)*v64, *(_QWORD **)(*v64 + 8LL) == v64) )
                                  {
                                    v72[1] = v71;
                                    *v71 = v72;
                                  }
                                  else
                                  {
                                    _list_del_entry_valid_or_report(v64);
                                  }
                                  *v64 = 0xDEAD000000000100LL;
                                  v64[1] = 0xDEAD000000000122LL;
                                  drm_dp_mst_topology_put_port(v64 - 3);
                                  v62 = 1;
                                }
                                v64 = v68;
                              }
                              while ( v68 != (_QWORD *)v65 );
                            }
                            mutex_unlock(_X25 + 200);
                            v73 = v62 & 1;
                            goto LABEL_176;
                          }
                          if ( (v58 & 0x80000000) != 0 )
                            goto LABEL_174;
                        }
                      }
                      drm_dp_mst_topology_put_port(_X25);
                      v17 = v99 | v98;
                      goto LABEL_28;
                    }
                  }
                  else
                  {
                    v46 = v38;
                    if ( (v44 & 1) != 0 )
                      goto LABEL_86;
                  }
LABEL_87:
                  *((_WORD *)_X25 + 9) = 0;
                  goto LABEL_91;
                }
              }
            }
          }
        }
LABEL_178:
        __break(1u);
      }
      break;
    }
LABEL_179:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v92 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &drm_dp_send_link_address__alloc_tag;
    v4 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
    *(_QWORD *)(StatusReg + 80) = v92;
    if ( !v4 )
      goto LABEL_180;
  }
  v79 = *(unsigned __int8 *)(a2 + 32);
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  *(_QWORD *)s = 0;
  v101 = 0;
  v115[0] = 0;
  v115[1] = 0;
  if ( v79 )
  {
    v82 = 0;
    v83 = a2 + 24;
    do
    {
      if ( (v82 & 1) != 0 )
      {
        if ( v82 >= 0x10 )
          goto LABEL_179;
        v84 = *(unsigned __int8 *)(v83 + (v82 >> 1)) >> 4;
      }
      else
      {
        if ( v82 > 0xF )
          goto LABEL_179;
        LOBYTE(v84) = *(_BYTE *)(v83 + (v82 >> 1)) & 0x10;
      }
      *((_BYTE *)v115 + v82++) = v84;
    }
    while ( v79 != v82 );
  }
  v73 = v13;
  snprintf(s, 0x40u, "%*phC", v79, v115);
  v80 = *((_QWORD *)_X25 + 13);
  if ( v80 )
    v81 = *(_QWORD *)(v80 + 8);
  else
    v81 = 0;
  dev_err(v81, "[drm] *ERROR* GUID check on %s failed: %d\n", s, v73);
  if ( (v73 & 0x80000000) != 0 )
    goto LABEL_175;
  v73 = 0;
LABEL_176:
  kfree(v4);
  result = v73;
LABEL_181:
  _ReadStatusReg(SP_EL0);
  return result;
}
