__int64 __fastcall zs_compact(__int64 a1)
{
  unsigned int v7; // w10
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v12; // x9
  __int64 v13; // x13
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x9
  _QWORD *v16; // x22
  unsigned int v17; // w9
  _QWORD *v18; // x9
  _QWORD *v19; // x8
  unsigned __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // x8
  _QWORD *v23; // x9
  unsigned int *v24; // x23
  _QWORD *v25; // x8
  unsigned __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x8
  unsigned __int64 v29; // x8
  __int64 v30; // x24
  int v31; // w26
  int v32; // w8
  unsigned int v33; // w9
  int v34; // w10
  __int64 v35; // x12
  __int64 *v36; // x2
  __int64 v37; // x8
  unsigned __int64 v38; // x23
  unsigned __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x9
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x28
  unsigned __int64 v44; // x26
  unsigned __int64 v45; // x16
  int v46; // w23
  int v47; // w24
  unsigned __int64 v48; // x11
  unsigned __int64 v49; // x12
  unsigned __int64 v50; // x19
  int v51; // w27
  unsigned __int64 v52; // x22
  __int64 v53; // x8
  __int64 v54; // x8
  int v55; // w8
  unsigned __int64 v56; // x11
  __int64 v57; // x8
  int v58; // w8
  unsigned __int64 v59; // x22
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 *v62; // x19
  int v63; // w8
  unsigned int v64; // w8
  int v65; // w9
  unsigned int v66; // w9
  __int64 v67; // x8
  int v68; // w8
  __int64 *v69; // x1
  __int64 v70; // x2
  int v71; // w8
  int v72; // w9
  __int64 v73; // x8
  int v74; // w8
  int v75; // w8
  _QWORD *v76; // x0
  _QWORD *v77; // x1
  _QWORD *v78; // x2
  int v79; // w8
  int v80; // w9
  unsigned int v81; // w9
  __int64 v82; // x8
  int v83; // w8
  _QWORD *v84; // x0
  _QWORD *v85; // x1
  _QWORD *v86; // x2
  unsigned __int64 v89; // x9
  _QWORD **v90; // [xsp+0h] [xbp-F0h]
  _QWORD **v91; // [xsp+8h] [xbp-E8h]
  _QWORD **v92; // [xsp+10h] [xbp-E0h]
  _QWORD **v93; // [xsp+18h] [xbp-D8h]
  _QWORD **v94; // [xsp+20h] [xbp-D0h]
  __int64 v95; // [xsp+28h] [xbp-C8h]
  __int64 v96; // [xsp+30h] [xbp-C0h]
  _QWORD **v97; // [xsp+38h] [xbp-B8h]
  _QWORD **v98; // [xsp+40h] [xbp-B0h]
  _QWORD **v99; // [xsp+48h] [xbp-A8h]
  _QWORD **v100; // [xsp+50h] [xbp-A0h]
  __int64 v101; // [xsp+58h] [xbp-98h]
  _QWORD **v102; // [xsp+60h] [xbp-90h]
  __int64 v103; // [xsp+68h] [xbp-88h]
  __int64 *v104; // [xsp+70h] [xbp-80h]
  __int64 v105; // [xsp+78h] [xbp-78h]
  __int64 v106; // [xsp+80h] [xbp-70h]
  __int64 v107; // [xsp+88h] [xbp-68h]
  __int64 v108; // [xsp+90h] [xbp-60h]
  __int64 v109; // [xsp+98h] [xbp-58h]
  unsigned int *v110; // [xsp+A0h] [xbp-50h]
  _QWORD *v111; // [xsp+A8h] [xbp-48h]
  __int64 v112; // [xsp+B0h] [xbp-40h]
  unsigned __int64 v113; // [xsp+B8h] [xbp-38h]
  int v114; // [xsp+C4h] [xbp-2Ch]
  __int64 v115; // [xsp+C8h] [xbp-28h]
  unsigned __int64 v116; // [xsp+D0h] [xbp-20h]
  unsigned __int64 v117; // [xsp+D8h] [xbp-18h]
  __int64 v118; // [xsp+E0h] [xbp-10h]

  _X9 = (unsigned int *)(a1 + 2128);
  __asm { PRFM            #0x11, [X9] }
  do
    v7 = __ldxr(_X9);
  while ( __stlxr(1u, _X9) );
  __dmb(0xBu);
  if ( v7 )
    return 0;
  v9 = a1;
  result = 0;
  v103 = v9 + 8;
  v10 = 254;
  StatusReg = _ReadStatusReg(SP_EL0);
  v109 = v9;
  while ( 1 )
  {
    v12 = v10;
    if ( v10 != *(_DWORD *)(*(_QWORD *)(v103 + 8 * v10) + 212LL) )
      goto LABEL_8;
    v95 = v10;
    v96 = result;
    v107 = *(_QWORD *)(v103 + 8 * v10);
    raw_write_lock(v9 + 2120);
    result = raw_spin_lock(v107);
    v13 = v107;
    v14 = *(_QWORD *)(v107 + 312);
    v15 = *(_QWORD *)(v107 + 320);
    if ( v14 <= v15 )
    {
      v101 = 0;
      goto LABEL_7;
    }
    v16 = nullptr;
    v97 = (_QWORD **)(v107 + 152);
    v93 = (_QWORD **)(v107 + 136);
    v91 = (_QWORD **)(v107 + 120);
    v90 = (_QWORD **)(v107 + 104);
    v92 = (_QWORD **)(v107 + 88);
    v94 = (_QWORD **)(v107 + 72);
    v98 = (_QWORD **)(v107 + 56);
    v99 = (_QWORD **)(v107 + 168);
    v100 = (_QWORD **)(v107 + 40);
    v101 = 0;
    v102 = (_QWORD **)(v107 + 24);
    v106 = v107 + 216;
    v105 = v107 + 8;
LABEL_15:
    if ( (v14 - v15) / *(int *)(v13 + 204) * *(int *)(v13 + 208) )
      break;
LABEL_161:
    if ( v16 )
      goto LABEL_162;
LABEL_7:
    raw_spin_unlock(v13);
    raw_write_unlock(v9 + 2120);
    v12 = v95;
    result = v101 + v96;
LABEL_8:
    v10 = v12 - 1;
    if ( !v12 )
      goto LABEL_182;
  }
  if ( v16 )
    goto LABEL_42;
  v18 = *v99;
  if ( *v99 == v99 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
  {
    v18 = *v97;
    if ( *v97 == v97 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
    {
      v18 = *v93;
      if ( *v93 == v93 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
      {
        v18 = *v91;
        if ( *v91 == v91 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
        {
          v18 = *v90;
          if ( *v90 == v90 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
          {
            v18 = *v92;
            if ( *v92 == v92 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
            {
              v18 = *v94;
              if ( *v94 == v94 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
              {
                v18 = *v98;
                if ( *v98 == v98 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
                {
                  v18 = *v100;
                  if ( *v100 == v100 || (v16 = v18 - 3, v18 == &_ksymtab_zs_destroy_pool) )
                  {
                    v18 = *v102;
                    if ( *v102 == v102 )
                      goto LABEL_7;
                    v16 = v18 - 3;
                    if ( v18 == &_ksymtab_zs_destroy_pool )
                      goto LABEL_7;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v19 = (_QWORD *)v18[1];
  v20 = *((unsigned int *)v18 - 6);
  if ( (_QWORD *)*v19 == v18 && (v21 = *v18, *(_QWORD **)(*v18 + 8LL) == v18) )
  {
    *(_QWORD *)(v21 + 8) = v19;
    *v19 = v21;
  }
  else
  {
    result = _list_del_entry_valid_or_report(v18);
  }
  v22 = (v20 >> 1) & 0xF;
  *v18 = v18;
  v18[1] = v18;
  if ( (unsigned int)v22 >= 0xE )
    goto LABEL_177;
  --*(_QWORD *)(v106 + 8 * v22);
LABEL_42:
  v23 = *v102;
  if ( *v102 == v102 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
  {
    v23 = *v100;
    if ( *v100 == v100 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
    {
      v23 = *v98;
      if ( *v98 == v98 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
      {
        v23 = *v94;
        if ( *v94 == v94 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
        {
          v23 = *v92;
          if ( *v92 == v92 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
          {
            v23 = *v90;
            if ( *v90 == v90 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
            {
              v23 = *v91;
              if ( *v91 == v91 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
              {
                v23 = *v93;
                if ( *v93 == v93 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
                {
                  v23 = *v97;
                  if ( *v97 == v97 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
                  {
                    v23 = *v99;
                    if ( *v99 == v99 || (v24 = (unsigned int *)(v23 - 3), v23 == &_ksymtab_zs_destroy_pool) )
                    {
LABEL_162:
                      v79 = *((_DWORD *)v16 + 1);
                      if ( v79 )
                      {
                        v80 = *(_DWORD *)(v13 + 204);
                        if ( v79 != v80 )
                        {
                          v83 = 100 * v79 / v80 / 10;
                          v81 = v83 + 1;
                          if ( (unsigned int)(v83 + 1) >= 0xE )
                            goto LABEL_177;
                          ++*(_QWORD *)(v106 + 8LL * v81);
                          if ( v83 == 12 )
                            goto LABEL_177;
                          v82 = (unsigned int)(v83 + 1);
                          goto LABEL_170;
                        }
                        v81 = 11;
                      }
                      else
                      {
                        v81 = 0;
                      }
                      v82 = v81;
                      ++*(_QWORD *)(v106 + 8LL * v81);
LABEL_170:
                      v84 = v16 + 3;
                      v85 = (_QWORD *)(v105 + 16 * v82);
                      v86 = (_QWORD *)*v85;
                      if ( *(_QWORD **)(*v85 + 8LL) != v85 || v84 == v85 || v86 == v84 )
                      {
                        _list_add_valid_or_report(v84);
                      }
                      else
                      {
                        v86[1] = v84;
                        v16[3] = v86;
                        v16[4] = v85;
                        *v85 = v84;
                      }
                      *(_DWORD *)v16 = (*(_DWORD *)v16 & 0xFFFFFFE1) + 2 * v81;
                      goto LABEL_7;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v25 = (_QWORD *)v23[1];
  v26 = *((unsigned int *)v23 - 6);
  if ( (_QWORD *)*v25 == v23 && (v27 = *v23, *(_QWORD **)(*v23 + 8LL) == v23) )
  {
    *(_QWORD *)(v27 + 8) = v25;
    *v25 = v27;
  }
  else
  {
    result = _list_del_entry_valid_or_report(v23);
  }
  v28 = (v26 >> 1) & 0xF;
  *v23 = v23;
  v23[1] = v23;
  if ( (unsigned int)v28 < 0xE )
  {
    --*(_QWORD *)(v106 + 8 * v28);
    result = raw_write_lock(v24 + 12);
    v29 = ((unsigned __int64)*v24 >> 5) & 0x1FF;
    if ( (unsigned int)v29 < 0xFF )
    {
      v30 = *((_QWORD *)v24 + 2);
      v110 = v24;
      v111 = v16;
      v118 = *(_QWORD *)(v103 + 8 * v29);
LABEL_68:
      v31 = 0;
      v112 = v30;
      v108 = ((v30 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL;
      v104 = (__int64 *)(v30 + 32);
LABEL_69:
      ++*(_DWORD *)(StatusReg + 16);
      ++*(_DWORD *)(StatusReg + 3220);
      v32 = *(_DWORD *)(v118 + 200);
      v33 = *(unsigned __int16 *)(v30 + 48) + v32 * v31;
      if ( v33 > 0xFFF )
      {
LABEL_77:
        v36 = nullptr;
        goto LABEL_78;
      }
      v34 = **(_DWORD **)(v30 + 40);
      if ( (v34 & 0x3FC000) != 0x160000 )
        goto LABEL_180;
      while ( 1 )
      {
        if ( (v34 & 1) != 0 )
        {
          v35 = *v104;
          if ( (*v104 & 1) != 0 )
          {
LABEL_76:
            v36 = (__int64 *)(v35 & 0xFFFFFFFFFFFFFFFELL);
LABEL_78:
            --*(_DWORD *)(StatusReg + 3220);
            v37 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v37;
            if ( v37 && *(_QWORD *)(StatusReg + 16) )
            {
              if ( v36 )
                goto LABEL_81;
LABEL_126:
              v63 = **(_DWORD **)(v30 + 40);
              if ( (v63 & 0x3FC000) != 0x160000 )
                goto LABEL_181;
              if ( (v63 & 1) != 0 )
                goto LABEL_129;
              v30 = *(_QWORD *)(v30 + 32);
              if ( !v30 )
                goto LABEL_129;
              goto LABEL_68;
            }
            v62 = v36;
            result = preempt_schedule(result);
            v36 = v62;
            if ( !v62 )
              goto LABEL_126;
LABEL_81:
            v38 = *v36;
            v114 = v31;
            v39 = obj_malloc(v9, (unsigned int *)v16, v36);
            v40 = memstart_addr;
            v41 = *(int *)(v118 + 200);
            v113 = v38;
            ++*(_DWORD *)(StatusReg + 16);
            v42 = 0xFFFFFFFEC0000000LL - (v40 >> 12 << 6);
            v43 = ((_WORD)v41 * (_WORD)v38) & 0xFFF;
            v44 = ((_DWORD)v41 * (_DWORD)v39) & 0xFFF;
            v45 = v42 + (v38 >> 24 << 6);
            ++*(_DWORD *)(StatusReg + 3220);
            if ( v43 + v41 <= 0x1000 )
              v46 = v41;
            else
              v46 = 4096 - v43;
            if ( v44 + v41 <= 0x1000 )
              v47 = v41;
            else
              v47 = 4096 - v44;
            ++*(_DWORD *)(StatusReg + 16);
            v117 = v45;
            v48 = v42 + (v39 >> 24 << 6);
            ++*(_DWORD *)(StatusReg + 3220);
            v49 = ((v45 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
            LODWORD(v9) = 0;
            v50 = ((v48 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
LABEL_88:
            v115 = ((v48 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL;
            v116 = v48;
            while ( 1 )
            {
              v51 = v46 >= v47 ? v47 : v46;
              v52 = v49;
              result = (__int64)memcpy((void *)(v50 + v44), (const void *)(v49 + v43), v51);
              v9 = (unsigned int)(v51 + v9);
              if ( (_DWORD)v9 == *(_DWORD *)(v118 + 200) )
                break;
              v43 += v51;
              if ( v43 < 0x1000 )
              {
                v46 -= v51;
                v49 = v52;
              }
              else
              {
                --*(_DWORD *)(StatusReg + 3220);
                v53 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v53;
                if ( !v53 || !*(_QWORD *)(StatusReg + 16) )
                  result = preempt_schedule(result);
                --*(_DWORD *)(StatusReg + 3220);
                v54 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v54;
                if ( !v54 || !*(_QWORD *)(StatusReg + 16) )
                  result = preempt_schedule(result);
                v55 = **(_DWORD **)(v117 + 40);
                if ( (v55 & 0x3FC000) != 0x160000 )
                  goto LABEL_178;
                if ( (v55 & 1) != 0 )
                  v56 = 0;
                else
                  v56 = *(_QWORD *)(v117 + 32);
                ++*(_DWORD *)(StatusReg + 16);
                ++*(_DWORD *)(StatusReg + 3220);
                ++*(_DWORD *)(StatusReg + 16);
                v117 = v56;
                ++*(_DWORD *)(StatusReg + 3220);
                v49 = ((v56 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
                v43 = 0;
                v50 = v115 | 0xFF00000000000000LL;
                v46 = *(_DWORD *)(v118 + 200) - v9;
              }
              v44 += v51;
              v47 -= v51;
              if ( v44 >= 0x1000 )
              {
                --*(_DWORD *)(StatusReg + 3220);
                v57 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v57;
                if ( !v57 || !*(_QWORD *)(StatusReg + 16) )
                {
                  v59 = v49;
                  result = preempt_schedule(result);
                  v49 = v59;
                }
                v58 = **(_DWORD **)(v116 + 40);
                if ( (v58 & 0x3FC000) == 0x160000 )
                {
                  if ( (v58 & 1) != 0 )
                    v48 = 0;
                  else
                    v48 = *(_QWORD *)(v116 + 32);
                  ++*(_DWORD *)(StatusReg + 16);
                  ++*(_DWORD *)(StatusReg + 3220);
                  v44 = 0;
                  v50 = ((v48 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
                  v47 = *(_DWORD *)(v118 + 200) - v9;
                  goto LABEL_88;
                }
                goto LABEL_179;
              }
            }
            --*(_DWORD *)(StatusReg + 3220);
            v60 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v60;
            if ( !v60 || !*(_QWORD *)(StatusReg + 16) )
              result = preempt_schedule(result);
            --*(_DWORD *)(StatusReg + 3220);
            v61 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v61;
            v9 = v109;
            v24 = v110;
            v16 = v111;
            v30 = v112;
            if ( !v61 || !*(_QWORD *)(StatusReg + 16) )
              preempt_schedule(result);
            result = obj_free(*(unsigned int *)(v118 + 200), v113);
            if ( *((_DWORD *)v111 + 1) != *(_DWORD *)(v118 + 204) )
            {
              v31 = v114 + 1;
              if ( v110[1] )
                goto LABEL_69;
            }
LABEL_129:
            result = raw_write_unlock(v24 + 12);
            v64 = v24[1];
            if ( v64 )
            {
              v13 = v107;
              v65 = *(_DWORD *)(v107 + 204);
              if ( v64 == v65 )
              {
                v66 = 11;
                goto LABEL_133;
              }
              v68 = (int)(100 * v64) / v65 / 10;
              v66 = v68 + 1;
              if ( (unsigned int)(v68 + 1) >= 0xE )
                break;
              ++*(_QWORD *)(v106 + 8LL * v66);
              if ( v68 == 12 )
                break;
              v67 = (unsigned int)(v68 + 1);
            }
            else
            {
              v13 = v107;
              v66 = 0;
LABEL_133:
              v67 = v66;
              ++*(_QWORD *)(v106 + 8LL * v66);
            }
            result = (__int64)(v24 + 6);
            v69 = (__int64 *)(v105 + 16 * v67);
            v70 = *v69;
            if ( *(__int64 **)(*v69 + 8) != v69 || (__int64 *)result == v69 || v70 == result )
            {
              result = _list_add_valid_or_report(result);
            }
            else
            {
              *(_QWORD *)(v70 + 8) = result;
              *((_QWORD *)v24 + 3) = v70;
              *((_QWORD *)v24 + 4) = v69;
              *v69 = result;
            }
            *v24 = (*v24 & 0xFFFFFFE1) + 2 * v66;
            if ( v66 )
            {
              v71 = *((_DWORD *)v16 + 1);
              if ( v71 )
                goto LABEL_143;
LABEL_146:
              if ( *(_DWORD *)(v9 + 2124) )
              {
                v17 = 0;
LABEL_148:
                v73 = v17;
                ++*(_QWORD *)(v106 + 8LL * v17);
LABEL_154:
                v76 = v16 + 3;
                v77 = (_QWORD *)(v105 + 16 * v73);
                v78 = (_QWORD *)*v77;
                if ( *(_QWORD **)(*v77 + 8LL) != v77 || v76 == v77 || v78 == v76 )
                {
                  _list_add_valid_or_report(v76);
                }
                else
                {
                  v78[1] = v76;
                  v16[3] = v78;
                  v16[4] = v77;
                  *v77 = v76;
                }
                *(_DWORD *)v16 = (*(_DWORD *)v16 & 0xFFFFFFE1) + 2 * v17;
                raw_spin_unlock(v13);
                raw_write_unlock(v9 + 2120);
                raw_write_lock(v9 + 2120);
                result = raw_spin_lock(v107);
                v13 = v107;
                v16 = nullptr;
              }
            }
            else
            {
              result = ((__int64 (__fastcall *)(__int64, __int64, unsigned int *))free_zspage)(v9, v13, v24);
              v13 = v107;
              v101 += *(int *)(v107 + 208);
              v71 = *((_DWORD *)v16 + 1);
              if ( !v71 )
                goto LABEL_146;
LABEL_143:
              v72 = *(_DWORD *)(v13 + 204);
              if ( v71 == v72 )
              {
                v17 = 11;
                goto LABEL_148;
              }
              v74 = 100 * v71 / v72;
              if ( (unsigned int)(v74 - 100) < 0xA || *(_DWORD *)(v9 + 2124) )
              {
                v75 = v74 / 10;
                v17 = v75 + 1;
                if ( (unsigned int)(v75 + 1) >= 0xE )
                  break;
                ++*(_QWORD *)(v106 + 8LL * v17);
                if ( v75 == 12 )
                  break;
                v73 = (unsigned int)(v75 + 1);
                goto LABEL_154;
              }
            }
            v14 = *(_QWORD *)(v13 + 312);
            v15 = *(_QWORD *)(v13 + 320);
            if ( v14 <= v15 )
              goto LABEL_161;
            goto LABEL_15;
          }
        }
        else
        {
          v35 = *(_QWORD *)((v108 | 0xFF00000000000000LL) + v33);
          if ( (v35 & 1) != 0 )
            goto LABEL_76;
        }
        v33 += v32;
        ++v31;
        if ( v33 >= 0x1000 )
          goto LABEL_77;
      }
    }
  }
LABEL_177:
  __break(0x5512u);
LABEL_178:
  __break(0x800u);
LABEL_179:
  __break(0x800u);
LABEL_180:
  __break(0x800u);
LABEL_181:
  __break(0x800u);
LABEL_182:
  _X8 = (unsigned __int64 *)(v9 + 2072);
  __asm { PRFM            #0x11, [X8] }
  do
    v89 = __ldxr(_X8);
  while ( __stxr(v89 + result, _X8) );
  *(_DWORD *)(v9 + 2128) = 0;
  return result;
}
