__int64 __fastcall profile_assignments_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x21
  unsigned __int64 v6; // x22
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x27
  unsigned __int64 v9; // x8
  size_t v10; // x2
  char *v11; // x1
  __int64 *v12; // x23
  unsigned __int64 v13; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  int v23; // w24
  int v24; // w0
  __int64 v25; // x8
  unsigned __int64 v26; // x25
  int v27; // w8
  int v28; // w14
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x12
  int v33; // w0
  unsigned int v34; // w28
  __int64 *v35; // x8
  __int64 *v36; // x23
  __int64 name; // x0
  __int64 *v38; // x8
  const char *v39; // x28
  __int64 v40; // x0
  __int64 *v41; // x1
  unsigned int v42; // w9
  size_t v43; // x0
  unsigned __int64 v44; // x2
  __int64 *v45; // x9
  __int64 *v46; // x0
  int v47; // w8
  __int64 **v48; // x8
  __int64 v49; // x9
  unsigned __int64 v50; // x23
  __int64 v51; // x25
  int v53; // [xsp+8h] [xbp-38h]
  int v54; // [xsp+Ch] [xbp-34h]
  int v55; // [xsp+10h] [xbp-30h]
  int v56; // [xsp+10h] [xbp-30h]
  unsigned int groupid; // [xsp+14h] [xbp-2Ch]
  __int64 v58; // [xsp+18h] [xbp-28h]
  unsigned int v59; // [xsp+18h] [xbp-28h]
  __int64 v60; // [xsp+18h] [xbp-28h]
  __int64 *v61; // [xsp+20h] [xbp-20h]
  int v62; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v63[2]; // [xsp+30h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int64)(a3 - 4096) < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = -22;
    goto LABEL_102;
  }
  v4 = *(_QWORD *)(a1 + 32);
  v3 = a3;
  v62 = 0;
  v6 = a3 + 1;
  v7 = _kmalloc_noprof(a3 + 1, 3264);
  if ( !v7 )
  {
LABEL_101:
    v3 = -12;
    goto LABEL_102;
  }
  while ( 1 )
  {
    _check_object_size(v7, v3, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v9 = a2 & (a2 << 8 >> 8);
    v10 = v3;
    if ( 0x8000000000LL - v3 >= v9 )
    {
      v12 = (__int64 *)(v4 + 19680);
      v13 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v13);
LABEL_14:
      v10 = _arch_copy_from_user(v7, a2 & 0xFF7FFFFFFFFFFFFFLL, v3);
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v22 - 4096);
      _WriteStatusReg(TTBR1_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      if ( !v10 )
        break;
    }
    if ( v6 >= v3 - v10 )
      v11 = (char *)(v6 - (v3 - v10));
    else
      v11 = nullptr;
    if ( (unsigned __int64)v11 >= v10 )
    {
      memset((void *)(v7 + v3 - v10), 0, v10);
      v3 = -14;
      goto LABEL_22;
    }
LABEL_100:
    _fortify_panic(15, v11, v10);
    v6 = v3 + 1;
    v50 = _ReadStatusReg(SP_EL0);
    v51 = *(_QWORD *)(v50 + 80);
    *(_QWORD *)(v50 + 80) = &profile_assignments_write__alloc_tag;
    v7 = _kmalloc_noprof(v3 + 1, 3264);
    *(_QWORD *)(v50 + 80) = v51;
    if ( !v7 )
      goto LABEL_101;
  }
  rt_mutex_lock(v4 + 11088);
  if ( (*(_BYTE *)(v4 + 19728) & 1) != 0 )
  {
    v3 = -22;
    goto LABEL_21;
  }
  v23 = adreno_active_count_get(v4);
  if ( v23 )
    goto LABEL_20;
  v24 = gmu_core_dev_oob_set(v4);
  if ( v24 )
  {
    v23 = v24;
    adreno_active_count_put(v4);
LABEL_20:
    v3 = v23;
    goto LABEL_21;
  }
  if ( !(unsigned int)adreno_wait_idle(v4) )
  {
    adreno_profile_process_results(v4);
    v25 = *(_QWORD *)(v4 + 19704);
    if ( v25 )
    {
      *(_QWORD *)(v4 + 19712) = v25;
      *(_QWORD *)(v4 + 19720) = v25;
    }
    v26 = 0;
    a2 = v7;
    *(_BYTE *)(v7 + v3) = 0;
    while ( 1 )
    {
      v62 = -22;
      if ( (v26 & 0x8000000000000000LL) != 0 || v6 <= v26 )
        break;
      while ( 1 )
      {
        v27 = *(unsigned __int8 *)a2;
        if ( v27 != 32 )
          break;
        if ( (++v26 & 0x8000000000000000LL) == 0LL )
        {
          ++a2;
          if ( v6 > v26 )
            continue;
        }
        goto LABEL_99;
      }
      if ( v27 == 45 )
      {
        ++v26;
        v11 = (char *)(a2 + 1);
        v28 = 1;
      }
      else
      {
        v28 = 0;
        v11 = (char *)a2;
      }
      if ( (v26 & 0x8000000000000000LL) != 0 || v6 <= v26 )
        break;
      v29 = 0;
      while ( 1 )
      {
        v30 = (unsigned __int8)v11[v29];
        if ( !v11[v29] )
          goto LABEL_25;
        if ( (_DWORD)v30 == 58 )
          break;
        if ( v6 > v26 + v29 )
        {
          v11[v29++] = 32 * (*((_BYTE *)&ctype + v30) & 1) + v30;
          if ( (__int64)(v29 + v26) >= 0 && v6 > v29 + v26 )
            continue;
        }
        goto LABEL_99;
      }
      if ( !v29 )
        goto LABEL_25;
      if ( v6 <= v26 + v29 )
        break;
      v11[v29] = 0;
      if ( (__int64)(v26 + v29 + 1) < 0 || v6 <= v26 + v29 + 1 )
        break;
      v31 = 0;
      while ( ((unsigned __int8)v11[v29 + 1 + v31] | 0x20) != 0x20 )
      {
        v32 = v26 + v29 + v31 + 2;
        if ( v32 >= 0 )
        {
          ++v31;
          if ( v6 > v32 )
            continue;
        }
        goto LABEL_99;
      }
      if ( !v31 )
        goto LABEL_25;
      v55 = v28;
      v58 = (__int64)&v11[v29 + 1];
      if ( v11[v29 + 1 + v31] )
      {
        if ( v6 <= v26 + v29 + v31 + 1 )
          break;
        v26 += v29 + v31 + 2;
        a2 = (__int64)&v11[v29 + 2 + v31];
        v11[v29 + 1 + v31] = 0;
      }
      else
      {
        v6 = 0;
        v26 = 0;
        a2 = 0;
      }
      groupid = adreno_perfcounter_get_groupid(v4, v11);
      if ( (groupid & 0x80000000) != 0 )
        goto LABEL_25;
      v33 = kstrtouint(v58, 10, &v62);
      v59 = v62;
      if ( v62 < 0 )
        goto LABEL_25;
      v34 = groupid;
      v54 = v33;
      v61 = v12;
      if ( v55 )
      {
        v35 = v12;
        v36 = (__int64 *)*v12;
        while ( v36 != v35 )
        {
          v47 = *((_DWORD *)v36 + 11);
          v46 = v36;
          v36 = (__int64 *)*v36;
          if ( v47 == v34 && *((_DWORD *)v46 + 12) == v59 )
          {
            v48 = (__int64 **)v46[1];
            if ( *v48 == v46 && (__int64 *)v36[1] == v46 )
            {
              v36[1] = (__int64)v48;
              *v48 = v36;
            }
            else
            {
              _list_del_entry_valid_or_report(v46);
              v46 = v45;
            }
            *v46 = 0xDEAD000000000100LL;
            v46[1] = 0xDEAD000000000122LL;
            --*(_DWORD *)(v4 + 19696);
            kfree(v46);
            v34 = groupid;
            adreno_perfcounter_put(v4, groupid, v59, 1);
          }
          v35 = v61;
        }
      }
      else
      {
        v63[0] = 0;
        name = adreno_perfcounter_get_name(v4, groupid);
        if ( name )
        {
          v38 = (__int64 *)*v12;
          v39 = (const char *)name;
          while ( v38 != v12 )
          {
            if ( *((_DWORD *)v38 + 11) == groupid && *((_DWORD *)v38 + 12) == v59 )
              goto LABEL_95;
            v38 = (__int64 *)*v38;
          }
          if ( !(unsigned int)adreno_perfcounter_get(v4, groupid, v59, (_DWORD *)v63 + 1, v63, 0) )
          {
            v56 = HIDWORD(v63[0]);
            v53 = v63[0];
            v40 = _kmalloc_cache_noprof(raw_read_unlock, 3264, 64);
            if ( v40 )
            {
              v41 = *(__int64 **)(v4 + 19688);
              if ( (__int64 *)v40 == v12 || v41 == (__int64 *)v40 || (__int64 *)*v41 != v12 )
              {
                _list_add_valid_or_report(v40, v41);
                v40 = v49;
              }
              else
              {
                *(_QWORD *)(v4 + 19688) = v40;
                *(_QWORD *)v40 = v12;
                *(_QWORD *)(v40 + 8) = v41;
                *v41 = v40;
              }
              v42 = v59;
              v60 = v40;
              *(_DWORD *)(v40 + 44) = groupid;
              *(_DWORD *)(v40 + 48) = v42;
              *(_DWORD *)(v40 + 52) = v56;
              *(_DWORD *)(v40 + 56) = v53;
              v43 = strnlen(v39, 0x19u);
              if ( v43 == -1 )
              {
                _fortify_panic(2, -1, 0);
LABEL_104:
                _fortify_panic(7, 25, v44);
                goto LABEL_14;
              }
              if ( v43 == 25 )
                v44 = 25;
              else
                v44 = v43 + 1;
              if ( v44 >= 0x1A )
                goto LABEL_104;
              sized_strscpy(v60 + 16, v39);
              ++*(_DWORD *)(v4 + 19696);
            }
            else
            {
              adreno_perfcounter_put(v4, groupid, v59, 1);
            }
          }
        }
      }
LABEL_95:
      if ( !v54 )
      {
        v12 = v61;
        if ( a2 )
          continue;
      }
      goto LABEL_25;
    }
LABEL_99:
    __break(1u);
    goto LABEL_100;
  }
  v3 = -110;
LABEL_25:
  gmu_core_dev_oob_clear(v4);
  adreno_active_count_put(v4);
LABEL_21:
  rt_mutex_unlock(v4 + 11088);
LABEL_22:
  kfree(v7);
LABEL_102:
  _ReadStatusReg(SP_EL0);
  return v3;
}
