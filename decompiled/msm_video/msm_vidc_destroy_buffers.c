__int64 __fastcall msm_vidc_destroy_buffers(__int64 *a1)
{
  __int64 *v1; // x23
  __int64 *v2; // x28
  __int64 v3; // x20
  __int64 v5; // x27
  __int64 *v6; // x24
  __int64 v7; // x4
  __int64 *v8; // kr00_8
  __int64 *v9; // x1
  __int64 *v10; // x24
  __int64 v11; // x8
  const char *v12; // x3
  __int64 v13; // x21
  __int64 *v14; // x25
  __int64 v15; // x9
  void (__fastcall *v16)(__int64, __int64); // x9
  __int64 v17; // x1
  __int64 v18; // x9
  void (__fastcall *v19)(_QWORD); // x9
  __int64 v20; // x8
  void (__fastcall *v21)(__int64 *, __int64); // x8
  __int64 v22; // x1
  __int64 **v23; // x8
  __int64 *v24; // x9
  __int64 i; // x21
  __int64 v26; // x4
  __int64 *v27; // kr08_8
  __int64 v28; // x25
  __int64 *v29; // x27
  __int64 v30; // x9
  void (__fastcall *v31)(__int64, __int64); // x9
  __int64 v32; // x1
  __int64 v33; // x9
  void (__fastcall *v34)(_QWORD); // x9
  __int64 v35; // x8
  void (__fastcall *v36)(__int64 *, __int64); // x8
  __int64 v37; // x1
  __int64 **v38; // x8
  __int64 *v39; // x9
  __int64 *v40; // x1
  __int64 *v41; // x27
  __int64 **v42; // x8
  __int64 *v43; // x9
  __int64 *v44; // x9
  __int64 *v45; // x28
  __int64 *v46; // x1
  __int64 *v47; // x27
  __int64 **v48; // x8
  __int64 *v49; // x9
  __int64 *v50; // x9
  __int64 *v51; // x28
  __int64 *v52; // x1
  __int64 *v53; // x27
  __int64 **v54; // x8
  __int64 *v55; // x9
  __int64 *v56; // x9
  __int64 *v57; // x28
  __int64 *v58; // x1
  __int64 *v59; // x25
  __int64 **v60; // x8
  __int64 *v61; // x9
  __int64 *v62; // x9
  __int64 *v63; // x27
  __int64 **v64; // x1
  __int64 *v65; // x4
  __int64 v66; // x8
  __int64 *v67; // x27
  __int64 v68; // x8
  void (__fastcall *v69)(_QWORD); // x8
  __int64 *v70; // x0
  __int64 *v71; // x25
  __int64 **v72; // x8
  __int64 *v73; // x9
  __int64 *v74; // x9
  __int64 v75; // x8
  __int64 *v76; // x28
  const char *v77; // x4
  __int64 *v78; // x0
  __int64 *v79; // x25
  __int64 **v80; // x8
  __int64 *v81; // x9
  __int64 *v82; // x9
  __int64 v83; // x8
  __int64 *v84; // x28
  const char *v85; // x4
  __int64 **v86; // x0
  _QWORD *v87; // x27
  __int64 **v88; // x8
  __int64 *v89; // x22
  __int64 **v90; // x9
  __int64 **v91; // x0
  __int64 **v92; // x8
  __int64 *v93; // x22
  __int64 **v94; // x9
  _QWORD *v95; // x1
  int v96; // w21
  _QWORD *v97; // x25
  __int64 v98; // x8
  void (__fastcall *v99)(_QWORD); // x8
  _QWORD *v100; // x1
  _QWORD *v101; // x25
  int v102; // w21
  _QWORD *v103; // x27
  __int64 v104; // x8
  void (__fastcall *v105)(_QWORD); // x8
  _QWORD *v106; // x1
  int v107; // w21
  _QWORD *v108; // x27
  __int64 v109; // x8
  void (__fastcall *v110)(_QWORD); // x8
  _QWORD *v111; // x1
  int v112; // w21
  _QWORD *v113; // x27
  __int64 v114; // x8
  void (__fastcall *v115)(_QWORD); // x8
  __int64 *v117; // [xsp+30h] [xbp-80h]
  _QWORD *v118; // [xsp+38h] [xbp-78h]
  __int64 *v119; // [xsp+40h] [xbp-70h]
  __int64 *v120; // [xsp+48h] [xbp-68h]
  __int64 *v121; // [xsp+50h] [xbp-60h]
  __int64 *v122; // [xsp+58h] [xbp-58h]
  __int64 *v123; // [xsp+60h] [xbp-50h]
  __int64 *v124; // [xsp+68h] [xbp-48h]
  __int64 *v125; // [xsp+70h] [xbp-40h]
  __int64 *v126; // [xsp+78h] [xbp-38h]
  __int64 *v127; // [xsp+80h] [xbp-30h]
  __int64 *v128; // [xsp+88h] [xbp-28h]
  __int64 *v129; // [xsp+90h] [xbp-20h]
  __int64 *v130; // [xsp+98h] [xbp-18h]
  __int64 *v131; // [xsp+A0h] [xbp-10h]

  v3 = a1[40];
  v5 = 0;
  v118 = a1 + 4728;
  v129 = a1 + 373;
  v130 = a1 + 378;
  v127 = a1 + 363;
  v128 = a1 + 368;
  v125 = a1 + 353;
  v126 = a1 + 358;
  v123 = a1 + 343;
  v124 = a1 + 348;
  v117 = a1 + 323;
  v6 = a1 + 313;
  v121 = a1 + 333;
  v122 = a1 + 338;
  v119 = a1 + 328;
  v120 = a1 + 318;
  v131 = a1 + 313;
  do
  {
    v7 = msm_vidc_destroy_buffers_internal_buf_types[v5];
    v8 = v1;
    v1 = v6;
    switch ( (int)v7 )
    {
      case 1:
        goto LABEL_30;
      case 2:
        v1 = v120;
        if ( !v120 )
          break;
        goto LABEL_31;
      case 3:
        v1 = v119;
        if ( !v119 )
          break;
        goto LABEL_31;
      case 4:
        v1 = v121;
        if ( !v121 )
          break;
        goto LABEL_31;
      case 5:
        v1 = v117;
        if ( !v117 )
          break;
        goto LABEL_31;
      case 6:
        break;
      case 7:
        v1 = v122;
        if ( !v122 )
          break;
        goto LABEL_31;
      case 8:
        v1 = v123;
        if ( !v123 )
          break;
        goto LABEL_31;
      case 9:
        v1 = v124;
        if ( !v124 )
          break;
        goto LABEL_31;
      case 10:
        v1 = v125;
        if ( !v125 )
          break;
        goto LABEL_31;
      case 11:
        v1 = v126;
LABEL_30:
        if ( v1 )
          goto LABEL_31;
        break;
      case 12:
        v1 = v127;
        if ( !v127 )
          break;
        goto LABEL_31;
      case 13:
        v1 = v128;
        if ( !v128 )
          break;
        goto LABEL_31;
      case 14:
        v1 = v129;
        if ( !v129 )
          break;
        goto LABEL_31;
      case 15:
        v1 = v130;
        if ( !v130 )
          break;
LABEL_31:
        v9 = (__int64 *)*v1;
        if ( (__int64 *)*v1 != v1 )
        {
          do
          {
            v2 = (__int64 *)*v9;
            if ( a1 && (msm_vidc_debug & 2) != 0 )
            {
              v11 = *((unsigned int *)v9 + 6);
              v12 = "UNKNOWN BUF";
              if ( (unsigned int)v11 <= 0xF )
                v12 = buf_type_name_arr[v11];
              v10 = v9;
              printk(&unk_8C0C3, "high", (char *)a1 + 340, v12, *((unsigned int *)v9 + 8));
              v9 = v10;
              v6 = v131;
            }
            ((void (__fastcall *)(__int64 *, __int64 *))msm_vidc_destroy_internal_buffer)(a1, v9);
            v9 = v2;
          }
          while ( v2 != v1 );
        }
        break;
      default:
        v1 = v8;
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_9780D, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v7);
        break;
    }
    ++v5;
  }
  while ( v5 != 9 );
  v13 = *v117;
  if ( (__int64 *)*v117 != v117 )
  {
    do
    {
      v14 = *(__int64 **)v13;
      print_vidc_buffer(1, (__int64)"err ", (__int64)"destroying ro buf", (__int64)a1, v13);
      if ( *(_QWORD *)(v13 + 104) )
      {
        if ( !*(_QWORD *)(v13 + 96) )
          goto LABEL_294;
        if ( !v3 )
          goto LABEL_294;
        v15 = *(_QWORD *)(v3 + 6568);
        if ( !v15 )
          goto LABEL_294;
        v16 = *(void (__fastcall **)(__int64, __int64))(v15 + 48);
        if ( !v16 )
          goto LABEL_294;
        v17 = *(_QWORD *)(v13 + 104);
        if ( *((_DWORD *)v16 - 1) != -792689463 )
          __break(0x8229u);
        v16(v3, v17);
        if ( *(_QWORD *)(v13 + 104) )
        {
LABEL_294:
          if ( *(_QWORD *)(v13 + 88) )
          {
            if ( v3 )
            {
              v18 = *(_QWORD *)(v3 + 6568);
              if ( v18 )
              {
                v19 = *(void (__fastcall **)(_QWORD))(v18 + 32);
                if ( v19 )
                {
                  if ( *((_DWORD *)v19 - 1) != 248590048 )
                    __break(0x8229u);
                  v19(v3);
                }
              }
            }
          }
        }
      }
      if ( (*(_BYTE *)(v13 + 112) & 1) != 0 )
      {
        if ( v3 )
        {
          v20 = *(_QWORD *)(v3 + 6568);
          if ( v20 )
          {
            v21 = *(void (__fastcall **)(__int64 *, __int64))(v20 + 8);
            if ( v21 )
            {
              v22 = *(_QWORD *)(v13 + 88);
              if ( *((_DWORD *)v21 - 1) != 381883841 )
                __break(0x8228u);
              v21(a1, v22);
            }
          }
        }
      }
      v23 = *(__int64 ***)(v13 + 8);
      if ( *v23 == (__int64 *)v13 && (v24 = *(__int64 **)v13, *(_QWORD *)(*(_QWORD *)v13 + 8LL) == v13) )
      {
        v24[1] = (__int64)v23;
        *v23 = v24;
      }
      else
      {
        _list_del_entry_valid_or_report(v13);
      }
      *(_QWORD *)v13 = v13;
      *(_QWORD *)(v13 + 8) = v13;
      msm_vidc_pool_free(a1);
      v13 = (__int64)v14;
    }
    while ( v14 != v117 );
  }
  for ( i = 0; i != 4; ++i )
  {
    v26 = msm_vidc_destroy_buffers_ext_buf_types[i];
    v27 = v2;
    v2 = v117;
    switch ( (int)v26 )
    {
      case 1:
        v2 = v131;
        if ( v131 )
          goto LABEL_100;
        continue;
      case 2:
        v2 = v120;
        if ( v120 )
          goto LABEL_100;
        continue;
      case 3:
        v2 = v119;
        if ( v119 )
          goto LABEL_100;
        continue;
      case 4:
        v2 = v121;
        if ( v121 )
          goto LABEL_100;
        continue;
      case 5:
        goto LABEL_99;
      case 6:
        continue;
      case 7:
        v2 = v122;
        if ( !v122 )
          continue;
        goto LABEL_100;
      case 8:
        v2 = v123;
        if ( !v123 )
          continue;
        goto LABEL_100;
      case 9:
        v2 = v124;
        if ( !v124 )
          continue;
        goto LABEL_100;
      case 10:
        v2 = v125;
        if ( !v125 )
          continue;
        goto LABEL_100;
      case 11:
        v2 = v126;
LABEL_99:
        if ( v2 )
          goto LABEL_100;
        continue;
      case 12:
        v2 = v127;
        if ( !v127 )
          continue;
        goto LABEL_100;
      case 13:
        v2 = v128;
        if ( !v128 )
          continue;
        goto LABEL_100;
      case 14:
        v2 = v129;
        if ( !v129 )
          continue;
        goto LABEL_100;
      case 15:
        v2 = v130;
        if ( !v130 )
          continue;
LABEL_100:
        v28 = *v2;
        if ( (__int64 *)*v2 != v2 )
        {
          do
          {
            v29 = *(__int64 **)v28;
            if ( *(_QWORD *)(v28 + 104) )
            {
              if ( !*(_QWORD *)(v28 + 96) )
                goto LABEL_295;
              if ( !v3 )
                goto LABEL_295;
              v30 = *(_QWORD *)(v3 + 6568);
              if ( !v30 )
                goto LABEL_295;
              v31 = *(void (__fastcall **)(__int64, __int64))(v30 + 48);
              if ( !v31 )
                goto LABEL_295;
              v32 = *(_QWORD *)(v28 + 104);
              if ( *((_DWORD *)v31 - 1) != -792689463 )
                __break(0x8229u);
              v31(v3, v32);
              if ( *(_QWORD *)(v28 + 104) )
              {
LABEL_295:
                if ( *(_QWORD *)(v28 + 88) )
                {
                  if ( v3 )
                  {
                    v33 = *(_QWORD *)(v3 + 6568);
                    if ( v33 )
                    {
                      v34 = *(void (__fastcall **)(_QWORD))(v33 + 32);
                      if ( v34 )
                      {
                        if ( *((_DWORD *)v34 - 1) != 248590048 )
                          __break(0x8229u);
                        v34(v3);
                      }
                    }
                  }
                }
              }
            }
            if ( (*(_BYTE *)(v28 + 112) & 1) != 0 )
            {
              print_vidc_buffer(1, (__int64)"err ", (__int64)"destroying: put dmabuf", (__int64)a1, v28);
              if ( v3 )
              {
                v35 = *(_QWORD *)(v3 + 6568);
                if ( v35 )
                {
                  v36 = *(void (__fastcall **)(__int64 *, __int64))(v35 + 8);
                  if ( v36 )
                  {
                    v37 = *(_QWORD *)(v28 + 88);
                    if ( *((_DWORD *)v36 - 1) != 381883841 )
                      __break(0x8228u);
                    v36(a1, v37);
                  }
                }
              }
            }
            v38 = *(__int64 ***)(v28 + 8);
            if ( *v38 == (__int64 *)v28 && (v39 = *(__int64 **)v28, *(_QWORD *)(*(_QWORD *)v28 + 8LL) == v28) )
            {
              v39[1] = (__int64)v38;
              *v38 = v39;
            }
            else
            {
              _list_del_entry_valid_or_report(v28);
            }
            *(_QWORD *)v28 = v28;
            *(_QWORD *)(v28 + 8) = v28;
            msm_vidc_pool_free(a1);
            v28 = (__int64)v29;
          }
          while ( v29 != v2 );
        }
        break;
      default:
        v2 = v27;
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_9780D, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v26);
        break;
    }
  }
  v40 = (__int64 *)a1[401];
  if ( v40 != a1 + 401 )
  {
    do
    {
      v41 = (__int64 *)*v40;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v45 = v40;
        printk(&unk_8E529, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v40[2]);
        v40 = v45;
      }
      v42 = (__int64 **)v40[1];
      if ( *v42 == v40 && (v43 = (__int64 *)*v40, *(__int64 **)(*v40 + 8) == v40) )
      {
        v43[1] = (__int64)v42;
        *v42 = v43;
      }
      else
      {
        _list_del_entry_valid_or_report(v40);
        v40 = v44;
      }
      *v40 = 0xDEAD000000000100LL;
      v40[1] = 0xDEAD000000000122LL;
      msm_vidc_pool_free(a1);
      v40 = v41;
    }
    while ( v41 != a1 + 401 );
  }
  v46 = (__int64 *)a1[405];
  if ( v46 != a1 + 405 )
  {
    do
    {
      v47 = (__int64 *)*v46;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v51 = v46;
        printk(&unk_97A2B, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v46[2]);
        v46 = v51;
      }
      v48 = (__int64 **)v46[1];
      if ( *v48 == v46 && (v49 = (__int64 *)*v46, *(__int64 **)(*v46 + 8) == v46) )
      {
        v49[1] = (__int64)v48;
        *v48 = v49;
      }
      else
      {
        _list_del_entry_valid_or_report(v46);
        v46 = v50;
      }
      *v46 = 0xDEAD000000000100LL;
      v46[1] = 0xDEAD000000000122LL;
      msm_vidc_pool_free(a1);
      v46 = v47;
    }
    while ( v47 != a1 + 405 );
  }
  v52 = (__int64 *)a1[501];
  if ( v52 != a1 + 501 )
  {
    do
    {
      v53 = (__int64 *)*v52;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v57 = v52;
        printk(&unk_93CAC, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v52[2]);
        v52 = v57;
      }
      v54 = (__int64 **)v52[1];
      if ( *v54 == v52 && (v55 = (__int64 *)*v52, *(__int64 **)(*v52 + 8) == v52) )
      {
        v55[1] = (__int64)v54;
        *v54 = v55;
      }
      else
      {
        _list_del_entry_valid_or_report(v52);
        v52 = v56;
      }
      *v52 = 0xDEAD000000000100LL;
      v52[1] = 0xDEAD000000000122LL;
      msm_vidc_pool_free(a1);
      v52 = v53;
    }
    while ( v53 != a1 + 501 );
  }
  v58 = (__int64 *)a1[511];
  if ( v58 != a1 + 511 )
  {
    do
    {
      v59 = (__int64 *)*v58;
      if ( v58
        && *((_DWORD *)v58 + 8)
        && *((_DWORD *)v58 + 9)
        && *((_DWORD *)v58 + 10)
        && a1
        && *((_DWORD *)v58 + 11)
        && (msm_vidc_debug & 1) != 0 )
      {
        v63 = v58;
        printk(&unk_8E756, "err ", (char *)a1 + 340, *((unsigned int *)v58 + 4), v58[3]);
        v58 = v63;
      }
      v60 = (__int64 **)v58[1];
      if ( *v60 == v58 && (v61 = (__int64 *)*v58, *(__int64 **)(*v58 + 8) == v58) )
      {
        v61[1] = (__int64)v60;
        *v60 = v61;
      }
      else
      {
        _list_del_entry_valid_or_report(v58);
        v58 = v62;
      }
      *v58 = 0xDEAD000000000100LL;
      v58[1] = 0xDEAD000000000122LL;
      msm_vidc_pool_free(a1);
      v58 = v59;
    }
    while ( v59 != a1 + 511 );
  }
  v64 = (__int64 **)a1[499];
  if ( v64 != (__int64 **)(a1 + 499) )
  {
    do
    {
      v65 = v64[2];
      if ( v65 && (v66 = v65[1]) != 0 && *(_QWORD *)(v66 + 40) )
      {
        v67 = *v64;
        if ( !a1 )
          goto LABEL_187;
      }
      else
      {
        v67 = *v64;
        if ( !a1 )
          goto LABEL_187;
      }
      if ( (msm_vidc_debug & 1) == 0 )
      {
LABEL_187:
        if ( v3 )
          goto LABEL_188;
        goto LABEL_179;
      }
      printk(&unk_8E564, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v65);
      if ( v3 )
      {
LABEL_188:
        v68 = *(_QWORD *)(v3 + 6568);
        if ( v68 )
        {
          v69 = *(void (__fastcall **)(_QWORD))(v68 + 16);
          if ( v69 )
          {
            if ( *((_DWORD *)v69 - 1) != -598128984 )
              __break(0x8228u);
            v69(a1);
          }
        }
      }
LABEL_179:
      v64 = (__int64 **)v67;
    }
    while ( v67 != a1 + 499 );
  }
  v70 = (__int64 *)a1[507];
  if ( v70 != a1 + 507 )
  {
    do
    {
      v71 = (__int64 *)*v70;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v75 = *((unsigned int *)v70 + 4);
        v76 = v70;
        v77 = "UNKNOWN CAP";
        if ( (unsigned int)v75 <= 0xC5 )
          v77 = cap_name_arr[v75];
        printk(&unk_82ADC, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v77);
        v70 = v76;
      }
      v72 = (__int64 **)v70[1];
      if ( *v72 == v70 && (v73 = (__int64 *)*v70, *(__int64 **)(*v70 + 8) == v70) )
      {
        v73[1] = (__int64)v72;
        *v72 = v73;
      }
      else
      {
        _list_del_entry_valid_or_report(v70);
        v70 = v74;
      }
      *v70 = 0xDEAD000000000100LL;
      v70[1] = 0xDEAD000000000122LL;
      vfree(v70);
      v70 = v71;
    }
    while ( v71 != a1 + 507 );
  }
  v78 = (__int64 *)a1[505];
  if ( v78 != a1 + 505 )
  {
    do
    {
      v79 = (__int64 *)*v78;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v83 = *((unsigned int *)v78 + 4);
        v84 = v78;
        v85 = "UNKNOWN CAP";
        if ( (unsigned int)v83 <= 0xC5 )
          v85 = cap_name_arr[v83];
        printk(&unk_89B3D, "err ", (char *)a1 + 340, "msm_vidc_destroy_buffers", v85);
        v78 = v84;
      }
      v80 = (__int64 **)v78[1];
      if ( *v80 == v78 && (v81 = (__int64 *)*v78, *(__int64 **)(*v78 + 8) == v78) )
      {
        v81[1] = (__int64)v80;
        *v80 = v81;
      }
      else
      {
        _list_del_entry_valid_or_report(v78);
        v78 = v82;
      }
      *v78 = 0xDEAD000000000100LL;
      v78[1] = 0xDEAD000000000122LL;
      vfree(v78);
      v78 = v79;
    }
    while ( v79 != a1 + 505 );
  }
  v86 = (__int64 **)a1[503];
  v87 = v118;
  if ( v86 != (__int64 **)(a1 + 503) )
  {
    do
    {
      v89 = *v86;
      v88 = (__int64 **)v86[1];
      if ( *v88 == (__int64 *)v86 && (__int64 **)v89[1] == v86 )
      {
        v89[1] = (__int64)v88;
        *v88 = v89;
      }
      else
      {
        _list_del_entry_valid_or_report(v86);
        v86 = v90;
      }
      *v86 = (__int64 *)0xDEAD000000000100LL;
      v86[1] = (__int64 *)0xDEAD000000000122LL;
      vfree(v86);
      v86 = (__int64 **)v89;
    }
    while ( v89 != a1 + 503 );
  }
  v91 = (__int64 **)a1[497];
  if ( v91 != (__int64 **)(a1 + 497) )
  {
    do
    {
      v93 = *v91;
      v92 = (__int64 **)v91[1];
      if ( *v92 == (__int64 *)v91 && (__int64 **)v93[1] == v91 )
      {
        v93[1] = (__int64)v92;
        *v92 = v93;
      }
      else
      {
        _list_del_entry_valid_or_report(v91);
        v91 = v94;
      }
      *v91 = (__int64 *)0xDEAD000000000100LL;
      v91[1] = (__int64 *)0xDEAD000000000122LL;
      vfree(v91);
      v91 = (__int64 **)v93;
    }
    while ( v93 != a1 + 497 );
  }
  v95 = (_QWORD *)*v118;
  if ( (_QWORD *)*v118 != v118 )
  {
    v96 = 0;
    do
    {
      v97 = (_QWORD *)*v95;
      if ( a1 && v95 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_915A6, "err ", (char *)a1 + 340, "release", v95 + 2);
        v87 = v118;
        if ( v3 )
        {
LABEL_240:
          v98 = *(_QWORD *)(v3 + 6584);
          if ( v98 )
          {
            v99 = *(void (__fastcall **)(_QWORD))(v98 + 56);
            if ( v99 )
            {
              if ( *((_DWORD *)v99 - 1) != -1185588215 )
                __break(0x8228u);
              v99(a1);
            }
          }
        }
      }
      else if ( v3 )
      {
        goto LABEL_240;
      }
      ++v96;
      v95 = v97;
    }
    while ( v97 != v87 );
  }
  v101 = v87 + 22;
  v100 = (_QWORD *)v87[22];
  if ( v100 != v87 + 22 )
  {
    v102 = 0;
    do
    {
      v103 = (_QWORD *)*v100;
      if ( a1 && v100 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_915A6, "err ", (char *)a1 + 340, "destroy", v100 + 2);
        if ( v3 )
        {
LABEL_254:
          v104 = *(_QWORD *)(v3 + 6584);
          if ( v104 )
          {
            v105 = *(void (__fastcall **)(_QWORD))(v104 + 48);
            if ( v105 )
            {
              if ( *((_DWORD *)v105 - 1) != -1185588215 )
                __break(0x8228u);
              v105(a1);
            }
          }
        }
      }
      else if ( v3 )
      {
        goto LABEL_254;
      }
      ++v102;
      v100 = v103;
    }
    while ( v103 != v101 );
  }
  v106 = (_QWORD *)v118[44];
  if ( v106 != v118 + 44 )
  {
    v107 = 0;
    do
    {
      v108 = (_QWORD *)*v106;
      if ( a1 && v106 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_915A6, "err ", (char *)a1 + 340, "release", v106 + 2);
        if ( v3 )
        {
LABEL_268:
          v109 = *(_QWORD *)(v3 + 6584);
          if ( v109 )
          {
            v110 = *(void (__fastcall **)(_QWORD))(v109 + 56);
            if ( v110 )
            {
              if ( *((_DWORD *)v110 - 1) != -1185588215 )
                __break(0x8228u);
              v110(a1);
            }
          }
        }
      }
      else if ( v3 )
      {
        goto LABEL_268;
      }
      ++v107;
      v106 = v108;
    }
    while ( v108 != v118 + 44 );
  }
  v111 = (_QWORD *)v118[66];
  if ( v111 != v118 + 66 )
  {
    v112 = 0;
    do
    {
      v113 = (_QWORD *)*v111;
      if ( a1 && v111 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_915A6, "err ", (char *)a1 + 340, "destroy", v111 + 2);
        if ( v3 )
        {
LABEL_282:
          v114 = *(_QWORD *)(v3 + 6584);
          if ( v114 )
          {
            v115 = *(void (__fastcall **)(_QWORD))(v114 + 48);
            if ( v115 )
            {
              if ( *((_DWORD *)v115 - 1) != -1185588215 )
                __break(0x8228u);
              v115(a1);
            }
          }
        }
      }
      else if ( v3 )
      {
        goto LABEL_282;
      }
      ++v112;
      v111 = v113;
    }
    while ( v113 != v118 + 66 );
  }
  return msm_vidc_pools_deinit(a1);
}
