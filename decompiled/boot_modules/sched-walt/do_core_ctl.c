void do_core_ctl()
{
  __int64 v0; // x27
  __int64 v1; // x28
  char *v2; // x21
  unsigned int v3; // w0
  unsigned int v4; // w22
  unsigned int v5; // w8
  unsigned int v6; // w23
  bool v7; // cc
  int v9; // w19
  bool v10; // w26
  __int64 v11; // x0
  char *v12; // x20
  char *v13; // x9
  int v14; // w10
  int v15; // w11
  unsigned int v16; // w8
  char *v17; // x9
  int v18; // w11
  char *v19; // x12
  unsigned __int64 v20; // x13
  unsigned __int64 v21; // x8
  __int64 v22; // x14
  __int64 v23; // x13
  char **v24; // x8
  char *v25; // x13
  __int64 v26; // x8
  __int64 v27; // x2
  char *v28; // x1
  unsigned __int64 v34; // x14
  int v35; // w19
  int v36; // w10
  __int64 *v37; // x15
  char *v38; // x9
  unsigned __int64 v39; // x8
  char *v40; // x11
  unsigned __int64 v41; // x12
  __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x12
  __int64 v45; // x8
  char **v46; // x8
  char *v47; // x12
  __int64 v48; // x8
  __int64 v49; // x2
  char *v50; // x1
  unsigned __int64 v53; // x13
  unsigned __int64 v56; // x13
  char *v57; // x12
  unsigned __int64 v58; // x13
  unsigned __int64 v59; // x8
  __int64 v60; // x14
  __int64 v61; // x13
  char **v62; // x8
  char *v63; // x13
  __int64 v64; // x8
  __int64 v65; // x2
  char *v66; // x1
  unsigned __int64 v69; // x14
  __int64 v70; // x8
  __int64 v71; // x20
  unsigned __int64 v72; // x22
  unsigned int v73; // w8
  unsigned __int64 v74; // x22
  unsigned int v75; // w8
  __int64 v76; // x21
  unsigned int v77; // w8
  unsigned __int64 v78; // x21
  unsigned int v79; // w8
  unsigned int v80; // [xsp+8h] [xbp-38h]
  __int64 v81; // [xsp+10h] [xbp-30h]
  __int64 v82; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int64 v83; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v84; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v85[2]; // [xsp+30h] [xbp-10h] BYREF

  v85[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v85[0] = 0;
  v82 = 0;
  v83 = 0;
  if ( num_clusters )
  {
    v0 = 0;
    v80 = 0;
    while ( 1 )
    {
      v1 = 304 * v0;
      v2 = (char *)&cluster_state + 304 * v0;
      if ( !v2 )
      {
LABEL_109:
        v70 = (unsigned int)v83;
        v71 = v80;
        goto LABEL_111;
      }
      if ( (unsigned __int64)(v1 - 1136) < 0xFFFFFFFFFFFFFB40LL )
        goto LABEL_132;
      v3 = _sw_hweight64(*((_DWORD *)v2 + 20) & (unsigned int)~(LODWORD(_cpu_partial_halt_mask[0])
                                                              | LODWORD(_cpu_halt_mask[0])));
      if ( (unsigned __int64)(v1 - 1149) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_132;
      v4 = v3;
      *((_DWORD *)v2 + 17) = v3;
      if ( (unsigned __int64)(v1 - 1081) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_132;
      if ( (v2[136] & 1) != 0 )
      {
        if ( (unsigned __int64)(v1 - 1129) < 0xFFFFFFFFFFFFFB3FLL || (v1 | 4uLL) > 0x4C0 || (v1 | 0xCuLL) > 0x4C0 )
          goto LABEL_132;
        v5 = *((_DWORD *)v2 + 1);
        if ( v5 <= *((_DWORD *)v2 + 22) )
          v5 = *((_DWORD *)v2 + 22);
        if ( v5 >= *((_DWORD *)v2 + 3) )
          v6 = *((_DWORD *)v2 + 3);
        else
          v6 = v5;
        v7 = v6 > v3;
        if ( v6 < v3 )
        {
LABEL_19:
          _CF = v3 >= v6;
          if ( v3 <= v6 )
            goto LABEL_32;
          goto LABEL_20;
        }
      }
      else
      {
        if ( (unsigned __int64)(v1 - 1145) < 0xFFFFFFFFFFFFFB3FLL )
          goto LABEL_132;
        v6 = *((_DWORD *)v2 + 18);
        v7 = v6 > v3;
        if ( v6 < v3 )
          goto LABEL_19;
      }
      if ( !v7 )
        goto LABEL_4;
      if ( (unsigned __int64)(v1 - 1136) < 0xFFFFFFFFFFFFFB40LL )
        goto LABEL_132;
      if ( !(unsigned int)_sw_hweight64(
                            *((_DWORD *)v2 + 20)
                          & ((unsigned int)cpus_part_paused_by_us | (unsigned int)cpus_paused_by_us)) )
        goto LABEL_4;
      v4 = *((_DWORD *)v2 + 17);
      _CF = v4 >= v6;
      if ( v4 <= v6 )
      {
LABEL_32:
        if ( !_CF
          && *((_DWORD *)v2 + 17)
           + (unsigned int)_try_to_resume((__int64)&cluster_state + 304 * v0, v6, 0, (__int64)&v84) != v6 )
        {
          _try_to_resume((__int64)&cluster_state + 304 * v0, v6, 1, (__int64)&v84);
          v80 = v84 & cpus_part_paused_by_us;
          v82 = (unsigned int)v84 & (unsigned int)cpus_part_paused_by_us;
        }
        goto LABEL_4;
      }
LABEL_20:
      if ( (unsigned __int64)(v1 - 1145) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_132;
      if ( (unsigned __int64)(v1 - 1141) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_132;
      v9 = *((_DWORD *)v2 + 18);
      v10 = *((_DWORD *)v2 + 19) != 0;
      v11 = raw_spin_lock_irqsave(&state_lock);
      if ( (unsigned __int64)(v1 - 1097) < 0xFFFFFFFFFFFFFB3FLL )
        goto LABEL_132;
      v12 = v2 + 120;
      v81 = v11;
      v13 = *((char **)v2 + 15);
      if ( v13 == v2 + 120 )
      {
        v14 = 0;
      }
      else
      {
        v14 = 0;
        v15 = v9 + 1;
        do
        {
          if ( !--v15 )
            break;
          v57 = *(char **)v13;
          if ( (v13[16] & 1) == 0 )
          {
            v58 = *((unsigned int *)v13 - 4);
            v59 = v58 >> 6;
            v60 = 1LL << v58;
            if ( ((1LL << v58) & *((_QWORD *)&_cpu_active_mask + (v58 >> 6))) != 0
              && (_cpu_halt_mask[v59] & v60) == 0
              && (_cpu_partial_halt_mask[v59] & v60) == 0 )
            {
              if ( v4 - v14 == v6 )
                break;
              if ( (*(v13 - 24) & 1) == 0 && (!*((_DWORD *)v2 + 19) || *(v13 - 12) == 1) )
              {
                v61 = 1LL << v58;
                _X8 = &v85[v59];
                __asm { PRFM            #0x11, [X8] }
                do
                  v69 = __ldxr(_X8);
                while ( __stxr(v69 | v61, _X8) );
                v62 = *((char ***)v13 + 1);
                if ( *v62 == v13 && (v63 = *(char **)v13, *(char **)(*(_QWORD *)v13 + 8LL) == v13) )
                {
                  *((_QWORD *)v63 + 1) = v62;
                  *v62 = v63;
                }
                else
                {
                  _list_del_entry_valid_or_report(v13);
                }
                v64 = *((_QWORD *)v13 - 1);
                ++v14;
                v65 = v64 + 120;
                *(_QWORD *)v13 = 0xDEAD000000000100LL;
                *((_QWORD *)v13 + 1) = 0xDEAD000000000122LL;
                v66 = *(char **)(v64 + 128);
                if ( v13 == (char *)(v64 + 120) || v66 == v13 || *(_QWORD *)v66 != v65 )
                {
                  _list_add_valid_or_report(v13, v66, v65);
                }
                else
                {
                  *(_QWORD *)(v64 + 128) = v13;
                  *(_QWORD *)v13 = v65;
                  *((_QWORD *)v13 + 1) = v66;
                  *(_QWORD *)v66 = v13;
                }
              }
            }
          }
          v13 = v57;
        }
        while ( v57 != v12 );
      }
      if ( (v1 | 0xCuLL) > 0x4C0 )
        goto LABEL_132;
      v16 = *((_DWORD *)v2 + 3);
      do
      {
        if ( v4 - v14 <= v16 )
          break;
        v17 = *(char **)v12;
        if ( *(char **)v12 != v12 )
        {
          v18 = *((_DWORD *)v2 + 18) + 1;
          do
          {
            if ( !--v18 )
              break;
            v19 = *(char **)v17;
            if ( (v17[16] & 1) == 0 )
            {
              v20 = *((unsigned int *)v17 - 4);
              v21 = v20 >> 6;
              v22 = 1LL << v20;
              if ( ((1LL << v20) & *((_QWORD *)&_cpu_active_mask + (v20 >> 6))) != 0
                && (_cpu_halt_mask[v21] & v22) == 0
                && (_cpu_partial_halt_mask[v21] & v22) == 0 )
              {
                if ( v4 - v14 <= *((_DWORD *)v2 + 3) )
                  break;
                if ( !v10 || *(v17 - 12) == 1 )
                {
                  v23 = 1LL << v20;
                  _X8 = &v85[v21];
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v34 = __ldxr(_X8);
                  while ( __stxr(v34 | v23, _X8) );
                  v24 = *((char ***)v17 + 1);
                  if ( *v24 == v17 && (v25 = *(char **)v17, *(char **)(*(_QWORD *)v17 + 8LL) == v17) )
                  {
                    *((_QWORD *)v25 + 1) = v24;
                    *v24 = v25;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v17);
                  }
                  v26 = *((_QWORD *)v17 - 1);
                  ++v14;
                  v27 = v26 + 120;
                  *(_QWORD *)v17 = 0xDEAD000000000100LL;
                  *((_QWORD *)v17 + 1) = 0xDEAD000000000122LL;
                  v28 = *(char **)(v26 + 128);
                  if ( v17 == (char *)(v26 + 120) || v28 == v17 || *(_QWORD *)v28 != v27 )
                  {
                    _list_add_valid_or_report(v17, v28, v27);
                  }
                  else
                  {
                    *(_QWORD *)(v26 + 128) = v17;
                    *(_QWORD *)v17 = v27;
                    *((_QWORD *)v17 + 1) = v28;
                    *(_QWORD *)v28 = v17;
                  }
                }
              }
            }
            v17 = v19;
          }
          while ( v19 != v12 );
        }
        if ( !v10 )
          break;
        v16 = *((_DWORD *)v2 + 3);
        v10 = 0;
      }
      while ( v4 - v14 > v16 );
      if ( (v1 | 8uLL) > 0x4C0 )
LABEL_132:
        __break(1u);
      v35 = *((_DWORD *)v2 + 2);
      v36 = v35 - _sw_hweight64((unsigned int)cpus_part_paused_by_us);
      v37 = &cpus_part_paused_by_us;
      if ( v36 >= 1 )
      {
        v38 = *(char **)v12;
        if ( *(char **)v12 != v12 )
        {
          while ( 1 )
          {
            v39 = *((unsigned int *)v38 - 4);
            v40 = *(char **)v38;
            if ( ((1LL << v39) & v85[0]) == 0
              || (*(__int64 *)((char *)v37 + ((v39 >> 3) & 0x1FFFFFF8)) & (1LL << v39)) != 0 )
            {
              goto LABEL_77;
            }
            v41 = v39 >> 6;
            v42 = 1LL << v39;
            _X12 = &v83 + v41;
            __asm { PRFM            #0x11, [X12] }
            do
              v53 = __ldxr(_X12);
            while ( __stxr(v53 | v42, _X12) );
            v43 = *((unsigned int *)v38 - 4);
            v44 = v43 >> 6;
            v45 = 1LL << v43;
            _X12 = &v85[v44];
            __asm { PRFM            #0x11, [X12] }
            do
              v56 = __ldxr(_X12);
            while ( __stxr(v56 & ~v45, _X12) );
            v46 = *((char ***)v38 + 1);
            if ( *v46 == v38 && (v47 = *(char **)v38, *(char **)(*(_QWORD *)v38 + 8LL) == v38) )
            {
              *((_QWORD *)v47 + 1) = v46;
              *v46 = v47;
            }
            else
            {
              _list_del_entry_valid_or_report(v38);
            }
            v48 = *((_QWORD *)v38 - 1);
            --v36;
            v49 = v48 + 120;
            *(_QWORD *)v38 = 0xDEAD000000000100LL;
            *((_QWORD *)v38 + 1) = 0xDEAD000000000122LL;
            v50 = *(char **)(v48 + 128);
            if ( v38 != (char *)(v48 + 120) && v50 != v38 && *(_QWORD *)v50 == v49 )
              break;
            _list_add_valid_or_report(v38, v50, v49);
            if ( v40 == v12 )
              goto LABEL_3;
LABEL_78:
            v38 = v40;
            if ( v36 <= 0 )
              goto LABEL_3;
          }
          *(_QWORD *)(v48 + 128) = v38;
          *(_QWORD *)v38 = v49;
          *((_QWORD *)v38 + 1) = v50;
          *(_QWORD *)v50 = v38;
LABEL_77:
          if ( v40 == v12 )
            goto LABEL_3;
          goto LABEL_78;
        }
      }
LABEL_3:
      raw_spin_unlock_irqrestore(&state_lock, v81);
LABEL_4:
      if ( ++v0 >= (unsigned __int64)(unsigned int)num_clusters )
        goto LABEL_109;
    }
  }
  v71 = 0;
  v70 = 0;
LABEL_111:
  v72 = v70 & ~cpus_part_paused_by_us;
  v83 = v72;
  v73 = __clz(__rbit64(v72));
  if ( !v72 )
    v73 = 32;
  if ( v73 < nr_cpu_ids && (walt_partial_pause_cpus(&v83, 1) & 0x80000000) == 0 )
    cpus_part_paused_by_us |= v72;
  v74 = v85[0] & ~(_DWORD)cpus_paused_by_us;
  _ZF = (v85[0] & ~(_DWORD)cpus_paused_by_us) == 0;
  v85[0] = v74;
  v75 = __clz(__rbit64(v74));
  if ( _ZF )
    v75 = 32;
  if ( v75 < nr_cpu_ids && (walt_pause_cpus((__int64)v85, 1) & 0x80000000) == 0 )
    cpus_paused_by_us |= v74;
  v76 = v71 & cpus_part_paused_by_us;
  v82 = v71 & cpus_part_paused_by_us;
  v77 = __clz(__rbit64(v71 & cpus_part_paused_by_us));
  if ( (v71 & cpus_part_paused_by_us) == 0 )
    v77 = 32;
  if ( v77 < nr_cpu_ids && (walt_partial_resume_cpus((unsigned __int64 *)&v82, 1) & 0x80000000) == 0 )
    cpus_part_paused_by_us &= v76 ^ 0xFFFFFFFFLL;
  v78 = (unsigned int)v84 & (unsigned int)cpus_paused_by_us;
  _ZF = ((unsigned int)v84 & (unsigned int)cpus_paused_by_us) == 0;
  v84 = v78;
  v79 = __clz(__rbit64(v78));
  if ( _ZF )
    v79 = 32;
  if ( v79 < nr_cpu_ids && (walt_resume_cpus((__int64)&v84, 1) & 0x80000000) == 0 )
    cpus_paused_by_us &= v78 ^ 0xFFFFFFFF;
  _ReadStatusReg(SP_EL0);
}
