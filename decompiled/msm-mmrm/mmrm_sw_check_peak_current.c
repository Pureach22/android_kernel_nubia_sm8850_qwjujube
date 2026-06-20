__int64 __fastcall mmrm_sw_check_peak_current(__int64 a1, __int64 a2, unsigned int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // x15
  int v8; // w14
  __int64 result; // x0
  int v10; // w26
  int v11; // w22
  unsigned int v13; // w8
  unsigned __int64 v14; // x20
  __int64 v15; // x9
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x10
  unsigned __int64 v18; // x12
  unsigned int v19; // w12
  const char *v21; // x2
  unsigned int v22; // w20
  __int64 v23; // x19
  int v24; // w21
  int v25; // w24
  unsigned int v26; // w9
  __int64 v27; // x8
  unsigned int v28; // w19
  __int64 v29; // x19
  unsigned int v30; // w21
  int v31; // w22
  int v32; // w24
  __int64 v33; // x8
  __int64 v34; // x9
  int v35; // w21
  unsigned __int64 v36; // x12
  unsigned int v37; // w12
  unsigned int v38; // w25
  unsigned __int64 v39; // x21
  unsigned int v40; // w8
  unsigned __int64 v41; // x27
  __int64 v42; // x21
  unsigned __int64 v43; // x22
  unsigned int v44; // w8
  __int64 v45; // x9
  __int64 v46; // x9
  unsigned int v47; // w24
  unsigned int v48; // w28
  unsigned int v49; // w9
  __int64 v50; // x8
  _QWORD *v51; // x26
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 (__fastcall *v54)(_QWORD); // x8
  __int64 v55; // x28
  int v56; // w27
  __int64 v57; // x25
  unsigned __int64 *v58; // x8
  unsigned __int64 v59; // x9
  __int64 v60; // x21
  unsigned int v61; // w25
  unsigned int v62; // w26
  __int64 v63; // x8
  __int64 v64; // x0
  unsigned int (__fastcall *v65)(_QWORD); // x8
  __int64 v66; // x19
  bool v67; // w21
  __int64 v68; // x19
  int v69; // w22
  int v70; // w24
  __int64 v71; // x0
  int v72; // w8
  unsigned __int64 v73; // x0
  __int64 v74; // x2
  __int64 v75; // x8
  int v76; // w8
  __int64 v77; // x24
  unsigned int v78; // w19
  void *v79; // x0
  int v80; // w0
  int v81; // [xsp+4h] [xbp-4Ch]
  int v82; // [xsp+4h] [xbp-4Ch]
  _QWORD v83[3]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v84; // [xsp+28h] [xbp-28h] BYREF
  __int64 v85; // [xsp+30h] [xbp-20h]
  __int64 v86; // [xsp+38h] [xbp-18h]
  __int64 v87; // [xsp+40h] [xbp-10h]
  __int64 v88; // [xsp+48h] [xbp-8h]

  v7 = &_ksymtab_mmrm_client_check_scaling_supported;
  v8 = 65538;
  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 9 )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_3;
    v21 = "mmrm_sw_check_req_level";
    goto LABEL_27;
  }
  v10 = *(_DWORD *)(a1 + 72);
  v11 = *(_DWORD *)(a2 + 160);
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
    v22 = a3;
    v23 = a2;
    v24 = a4;
    v25 = a5;
    printk(&unk_DDEB, "high", "mmrm_sw_check_req_level");
    v7 = &_ksymtab_mmrm_client_check_scaling_supported;
    a4 = v24;
    v8 = 65538;
    a5 = v25;
    a3 = v22;
    a2 = v23;
  }
  v13 = *(_DWORD *)(a1 + 76);
  LODWORD(v14) = a3;
  if ( v13 > a3 )
  {
    v15 = *(unsigned int *)(a1 + 16);
    LODWORD(v14) = a3;
    if ( (_DWORD)v15 )
    {
      v16 = *(_QWORD *)(a1 + 8);
      v17 = 0;
      do
      {
        v18 = *(_QWORD *)(v16 + 128);
        if ( v18 && v18 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v16 + 664) && *(_DWORD *)(v16 + 160) != v11 )
        {
          v19 = *(_DWORD *)(v16 + 672);
          if ( v19 == v13 )
          {
            LODWORD(v14) = *(_DWORD *)(a1 + 76);
            goto LABEL_29;
          }
          if ( v19 > a3 && v19 < v13 )
            v17 = v16;
        }
        --v15;
        v16 += 720LL;
      }
      while ( v15 );
      LODWORD(v14) = a3;
      if ( v17 )
      {
        LODWORD(v14) = a3;
        if ( v17 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( *(_DWORD *)(v17 + 672) <= a3 )
            LODWORD(v14) = a3;
          else
            LODWORD(v14) = *(_DWORD *)(v17 + 672);
        }
      }
    }
  }
LABEL_29:
  if ( (~msm_mmrm_debug & 0x10002) != 0 )
  {
    if ( a4 )
      goto LABEL_31;
LABEL_38:
    a6 = 0;
    if ( *(_QWORD *)(a2 + 664) )
      goto LABEL_33;
LABEL_39:
    a7 = 0;
    if ( (_DWORD)v14 == *(_DWORD *)(a1 + 76) )
      goto LABEL_36;
LABEL_40:
    if ( (unsigned int)v14 <= 8 )
    {
      v33 = *(unsigned int *)(a1 + 16);
      if ( !(_DWORD)v33 )
        goto LABEL_53;
      v34 = *(_QWORD *)(a1 + 8);
      v35 = 0;
      while ( 1 )
      {
        v36 = *(_QWORD *)(v34 + 128);
        if ( v36 && v36 <= 0xFFFFFFFFFFFFF000LL && v34 != a2 && *(_QWORD *)(v34 + 664) )
        {
          v37 = *(_DWORD *)(v34 + 672);
          if ( v37 >= 9 )
            goto LABEL_52;
          v35 += *(_DWORD *)(v34 + 684) * *(_DWORD *)(v34 + 4LL * (unsigned int)v14 + 328 + 36LL * v37);
        }
        --v33;
        v34 += 720;
        if ( !v33 )
          goto LABEL_54;
      }
    }
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
    {
LABEL_3:
      result = 4294967274LL;
      goto LABEL_67;
    }
    v21 = "mmrm_sw_calculate_total_current";
LABEL_27:
    printk(&unk_D131, "err ", v21);
    result = 4294967274LL;
    goto LABEL_67;
  }
  v29 = a2;
  v30 = a3;
  v31 = a4;
  v32 = a5;
  printk(&unk_E1CD, "high", "mmrm_sw_check_req_level");
  v7 = &_ksymtab_mmrm_client_check_scaling_supported;
  v8 = 65538;
  a5 = v32;
  a3 = v30;
  a2 = v29;
  if ( !v31 )
    goto LABEL_38;
LABEL_31:
  if ( (unsigned int)v14 >= 9 )
    goto LABEL_52;
  a6 = *(_DWORD *)(a2 + 36LL * a3 + 4LL * (unsigned int)v14 + 328) * a5;
  if ( !*(_QWORD *)(a2 + 664) )
    goto LABEL_39;
LABEL_33:
  v26 = *(_DWORD *)(a2 + 672);
  if ( v26 > 8 )
    goto LABEL_52;
  v27 = *(unsigned int *)(a1 + 76);
  if ( (unsigned int)v27 > 8 )
    goto LABEL_52;
  a7 = *(_DWORD *)(a2 + 684) * *(_DWORD *)(a2 + 36LL * v26 + 4 * v27 + 328);
  if ( (_DWORD)v14 != (_DWORD)v27 )
    goto LABEL_40;
LABEL_36:
  v28 = a6 - a7;
  while ( 2 )
  {
    if ( (v8 & ~v7[72]) == 0 )
    {
      v60 = a2;
      printk(&unk_D636, "high", "mmrm_sw_check_peak_current");
      v7 = &_ksymtab_mmrm_client_check_scaling_supported;
      a2 = v60;
      v8 = 65538;
    }
    v38 = v28 + v10;
    if ( (int)(v28 + v10) <= 0 )
    {
      *(_DWORD *)(a1 + 72) = 0;
      *(_DWORD *)(a1 + 76) = v14;
      goto LABEL_64;
    }
    if ( v38 < *(_DWORD *)(a1 + 68) )
      goto LABEL_61;
    if ( *(_DWORD *)(a2 + 136) != 1 || !msm_mmrm_enable_throttle_feature )
    {
      if ( ((v8 - 1) & ~v7[72]) == 0 )
        printk(&unk_E31E, "err ", "mmrm_sw_check_peak_current");
      mmrm_sw_dump_enabled_client_info(a1);
      result = 4294967274LL;
      goto LABEL_67;
    }
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    memset(v83, 0, sizeof(v83));
    _init_swait_queue_head(v83, "&x->wait", &init_completion___key);
    v40 = *(unsigned __int16 *)(a1 + 64);
    if ( !*(_WORD *)(a1 + 64) )
    {
      v7 = &_ksymtab_mmrm_client_check_scaling_supported;
      v8 = 65538;
      goto LABEL_61;
    }
    v82 = v10;
    v41 = 0;
    v42 = 28;
    v8 = 65538;
    v7 = &_ksymtab_mmrm_client_check_scaling_supported;
    while ( 1 )
    {
      if ( v41 == 5 )
        goto LABEL_52;
      v43 = *(_QWORD *)(a1 + 8) + 720LL * *(unsigned __int16 *)(a1 + v42);
      if ( v43 )
      {
        if ( v43 <= 0xFFFFFFFFFFFFF000LL )
          break;
      }
LABEL_73:
      ++v41;
      v42 += 8;
      if ( v41 >= v40 )
        goto LABEL_61;
    }
    v44 = *(_DWORD *)(v43 + 672);
    if ( v44 > 8 )
      goto LABEL_52;
    v45 = *(unsigned int *)(a1 + 76);
    if ( (unsigned int)v45 > 8 )
      goto LABEL_52;
    v46 = 4 * v45;
    v47 = *(_DWORD *)(v43 + v46 + 364);
    v48 = *(_DWORD *)(v43 + 328 + 36LL * v44 + v46);
    if ( (~msm_mmrm_debug & 0x10002) != 0
      || (printk(&unk_DF2B, "high", "mmrm_sw_throttle_low_priority_client"),
          v7 = &_ksymtab_mmrm_client_check_scaling_supported,
          v8 = 65538,
          (~msm_mmrm_debug & 0x10002) != 0) )
    {
      v49 = v48 - v47;
      if ( v48 <= v47 )
      {
LABEL_72:
        v40 = *(unsigned __int16 *)(a1 + 64);
        goto LABEL_73;
      }
    }
    else
    {
      printk(&unk_CABF, "high", "mmrm_sw_throttle_low_priority_client");
      v7 = &_ksymtab_mmrm_client_check_scaling_supported;
      v8 = 65538;
      v49 = v48 - v47;
      if ( v48 <= v47 )
        goto LABEL_72;
    }
    if ( v28 >= v49 )
      goto LABEL_72;
    v61 = v28 - v49;
    v62 = v49;
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
    {
      printk(&unk_DCFC, "high", "mmrm_sw_throttle_low_priority_client");
      v8 = 65538;
      if ( (~msm_mmrm_debug & 0x10002) == 0 )
        printk(&unk_D93D, "high", "mmrm_sw_throttle_low_priority_client");
    }
    LODWORD(v84) = 1;
    v63 = *(unsigned int *)(v43 + 672);
    if ( (unsigned int)v63 > 8 )
    {
LABEL_52:
      __break(0x5512u);
LABEL_53:
      v35 = 0;
LABEL_54:
      if ( (v8 & ~v7[72]) == 0 )
      {
        v68 = a2;
        v69 = a6;
        v70 = a7;
        printk(&unk_D158, "high", "mmrm_sw_calculate_total_current");
        v7 = &_ksymtab_mmrm_client_check_scaling_supported;
        a7 = v70;
        v8 = 65538;
        a6 = v69;
        a2 = v68;
      }
      v28 = 0;
      v10 = v35 + a6;
      continue;
    }
    break;
  }
  v85 = *(_QWORD *)(v43 + 8 * v63 + 184);
  v86 = *(_QWORD *)(v43 + 192);
  v87 = *(_QWORD *)(v43 + 144);
  v64 = ktime_get();
  v65 = *(unsigned int (__fastcall **)(_QWORD))(v43 + 152);
  v66 = v64;
  if ( v65 )
  {
    if ( *((_DWORD *)v65 - 1) != -1570308778 )
      __break(0x8228u);
    v67 = v65(&v84) == 0;
  }
  else
  {
    v67 = 1;
  }
  v71 = ktime_get();
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
    v77 = v71;
    printk(&unk_CD92, "high", "mmrm_sw_throttle_low_priority_client");
    v71 = v77;
    if ( v67 )
      goto LABEL_128;
    goto LABEL_147;
  }
  if ( !v67 )
  {
LABEL_147:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v79 = &unk_D24F;
      goto LABEL_153;
    }
LABEL_148:
    v76 = -22;
    goto LABEL_149;
  }
LABEL_128:
  if ( (unsigned __int64)(v71 - v66) <= 0x5F5E100 || (~msm_mmrm_debug & 0x10001) != 0 )
  {
    if ( *(_BYTE *)(v43 + 676) )
      goto LABEL_131;
LABEL_155:
    v80 = clk_set_rate(*(_QWORD *)(v43 + 128), *(_QWORD *)(v43 + 192));
    v72 = msm_mmrm_debug;
    if ( v80 )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
      {
        v79 = &unk_E1F1;
LABEL_153:
        printk(v79, "err ", "mmrm_sw_throttle_low_priority_client");
      }
      goto LABEL_148;
    }
  }
  else
  {
    printk(&unk_DAB6, "err ", "mmrm_sw_throttle_low_priority_client");
    if ( !*(_BYTE *)(v43 + 676) )
      goto LABEL_155;
LABEL_131:
    v72 = msm_mmrm_debug;
  }
  if ( (~v72 & 0x10002) == 0 )
    printk(&unk_C7DA, "high", "mmrm_sw_throttle_low_priority_client");
  v73 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 32);
  v7 = &_ksymtab_mmrm_client_check_scaling_supported;
  v8 = 65538;
  if ( !v73 || v73 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_D9F4, "err ", "mmrm_sw_throttle_low_priority_client");
    v76 = -12;
LABEL_149:
    v78 = v76;
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_CF79, "err ", "mmrm_sw_check_peak_current");
    mmrm_sw_dump_enabled_client_info(a1);
    result = v78;
    goto LABEL_67;
  }
  *(_DWORD *)(v73 + 16) = v41;
  *(_DWORD *)(v73 + 20) = v62;
  v74 = a1 + 80;
  a2 = *(_QWORD *)(a1 + 88);
  *(_DWORD *)(v73 + 24) = *(_DWORD *)(v43 + 672);
  if ( v73 == a1 + 80 || a2 == v73 || *(_QWORD *)a2 != v74 )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)(a1 + 88) = v73;
    *(_QWORD *)v73 = v74;
    *(_QWORD *)(v73 + 8) = a2;
    *(_QWORD *)a2 = v73;
  }
  v75 = *(_QWORD *)(v43 + 192);
  *(_DWORD *)(v43 + 672) = 1;
  *(_QWORD *)(v43 + 664) = v75;
  v38 = v61 + v82;
  *(_BYTE *)(v43 + 676) = 0;
LABEL_61:
  *(_DWORD *)(a1 + 72) = v38;
  *(_DWORD *)(a1 + 76) = v14;
  v39 = *(_QWORD *)(a1 + 80);
  if ( v39 != a1 + 80 )
  {
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    v81 = v8 - 1;
    while ( 2 )
    {
      v14 = *(_QWORD *)v39;
      if ( v39
        && v39 <= 0xFFFFFFFFFFFFF000LL
        && (unsigned int)(*(_DWORD *)(v39 + 20) + *(_DWORD *)(a1 + 72)) <= *(_DWORD *)(a1 + 68) )
      {
        if ( (v8 & ~v7[72]) == 0 )
        {
          printk(&unk_CCDB, "high", "mmrm_reinstate_throttled_client");
          v7 = &_ksymtab_mmrm_client_check_scaling_supported;
          v8 = 65538;
        }
        v50 = *(unsigned int *)(v39 + 16);
        if ( (unsigned int)v50 >= 5 )
          goto LABEL_52;
        v51 = (_QWORD *)(*(_QWORD *)(a1 + 8) + 720LL * *(unsigned __int16 *)(a1 + 24 + 8 * v50 + 4));
        if ( v51 )
        {
          if ( (unsigned __int64)v51 <= 0xFFFFFFFFFFFFF000LL )
          {
            if ( (v8 & ~v7[72]) == 0 )
              printk(&unk_D740, "high", "mmrm_reinstate_throttled_client");
            LODWORD(v84) = 1;
            v52 = *(unsigned int *)(v39 + 24);
            v85 = v51[24];
            if ( (unsigned int)v52 > 8 )
              goto LABEL_52;
            v86 = v51[v52 + 23];
            v87 = v51[18];
            v53 = ktime_get();
            v54 = (__int64 (__fastcall *)(_QWORD))v51[19];
            if ( v54 )
            {
              v55 = v53;
              if ( *((_DWORD *)v54 - 1) != -1570308778 )
                __break(0x8228u);
              v56 = v54(&v84);
              v57 = ktime_get();
              if ( (~msm_mmrm_debug & 0x10002) != 0 )
              {
                if ( v56 )
                {
LABEL_108:
                  if ( (v81 & ~msm_mmrm_debug) == 0 )
                    printk(&unk_E03A, "err ", "mmrm_reinstate_throttled_client");
                }
              }
              else
              {
                printk(&unk_D782, "high", "mmrm_reinstate_throttled_client");
                if ( v56 )
                  goto LABEL_108;
              }
              if ( (unsigned __int64)(v57 - v55) > 0x5F5E100 && (v81 & ~msm_mmrm_debug) == 0 )
                printk(&unk_C2F7, "err ", "mmrm_reinstate_throttled_client");
            }
            v58 = *(unsigned __int64 **)(v39 + 8);
            if ( *v58 == v39 && (v59 = *(_QWORD *)v39, *(_QWORD *)(*(_QWORD *)v39 + 8LL) == v39) )
            {
              *(_QWORD *)(v59 + 8) = v58;
              *v58 = v59;
            }
            else
            {
              _list_del_entry_valid_or_report(v39);
            }
            *(_QWORD *)v39 = 0xDEAD000000000100LL;
            *(_QWORD *)(v39 + 8) = 0xDEAD000000000122LL;
            kfree(v39);
            v7 = &_ksymtab_mmrm_client_check_scaling_supported;
            v8 = 65538;
          }
        }
      }
      v39 = v14;
      if ( v14 == a1 + 80 )
        break;
      continue;
    }
  }
LABEL_64:
  if ( (v8 & ~v7[72]) == 0 )
    printk(&unk_C7A4, "high", "mmrm_sw_check_peak_current");
  result = 0;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
