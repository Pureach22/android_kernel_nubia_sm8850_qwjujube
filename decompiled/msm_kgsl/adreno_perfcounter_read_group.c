__int64 __fastcall adreno_perfcounter_read_group(_QWORD *a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 v3; // x28
  __int64 result; // x0
  unsigned int v7; // w24
  __int64 v8; // x19
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x27
  unsigned __int64 v11; // x8
  size_t v12; // x2
  unsigned __int64 v13; // x1
  unsigned int v14; // w22
  unsigned __int64 v15; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  unsigned int v25; // w0
  unsigned __int64 v26; // x14
  __int64 v27; // x25
  int v28; // w8
  __int64 v29; // x15
  unsigned __int64 v30; // x24
  unsigned __int64 v31; // x22
  unsigned int *v32; // x26
  unsigned __int64 v33; // x9
  __int64 v34; // x11
  __int64 v35; // x10
  int *v36; // x11
  unsigned __int64 v37; // x23
  __int64 v38; // x27
  int v39; // t1
  __int64 v40; // x10
  __int64 (__fastcall *v42)(_QWORD); // x8
  __int64 v43; // x0
  __int64 v44; // x10
  __int64 (__fastcall *v45)(_QWORD); // x9
  int v46; // w22
  __int64 v47; // x0
  int v48; // w22
  __int64 v49; // x8
  __int64 (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x8
  unsigned int v54; // w23
  unsigned __int64 v55; // x22
  __int64 v56; // x25
  unsigned int v57; // w2
  __int64 v58; // [xsp+0h] [xbp-30h]
  __int64 v59; // [xsp+8h] [xbp-28h]
  int v60; // [xsp+14h] [xbp-1Ch]
  __int64 v61; // [xsp+18h] [xbp-18h]
  unsigned __int64 v62; // [xsp+20h] [xbp-10h]
  unsigned __int64 v63; // [xsp+28h] [xbp-8h]

  v3 = *(_QWORD *)(a1[1783] + 48LL);
  if ( !v3 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a2 && a3 - 101 >= 0xFFFFFF9C )
  {
    v7 = a3;
    v63 = 16 * a3;
    v8 = _kmalloc_noprof(v63, 3264);
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = 16 * v7;
        _check_object_size(v8, v9, 0);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v11 = a2 & ((__int64)(a2 << 8) >> 8);
        v12 = 16 * v7;
        if ( 0x8000000000LL - v9 >= v11 )
        {
          v15 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v21 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v21);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v15);
          v12 = _arch_copy_from_user(v8, a2 & 0xFF7FFFFFFFFFFFFFLL, 16 * v7);
          v22 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v24 - 4096);
          _WriteStatusReg(TTBR1_EL1, v24);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v22);
          if ( !v12 )
            break;
        }
        if ( v63 >= v9 - v12 )
          v13 = v63 - (v9 - v12);
        else
          v13 = 0;
        if ( v13 >= v12 )
        {
          memset((void *)(v8 + v9 - v12), 0, v12);
          v14 = -14;
          goto LABEL_20;
        }
LABEL_68:
        _fortify_panic(15, v13, v12);
        v55 = _ReadStatusReg(SP_EL0);
        v56 = *(_QWORD *)(v55 + 80);
        v7 = v57;
        *(_QWORD *)(v55 + 80) = &adreno_perfcounter_read_group__alloc_tag;
        v63 = 16 * v57;
        v8 = _kmalloc_noprof(v63, 3264);
        *(_QWORD *)(v55 + 80) = v56;
        if ( !v8 )
          return 4294967284LL;
      }
      rt_mutex_lock(a1 + 1386);
      v14 = adreno_active_count_get((__int64)a1);
      if ( !v14 )
      {
        v25 = gmu_core_dev_oob_set(a1, 1);
        if ( !v25 )
        {
          v26 = v63;
          v58 = 16 * v7;
          v27 = 0;
          v28 = 0;
          v29 = v7;
          v61 = v7;
          v59 = v8;
          while ( 1 )
          {
            v30 = (16 * v27) | 8;
            if ( v26 < v30
              || (v31 = 16 * v27, v32 = (unsigned int *)(v8 + 16 * v27), *((_QWORD *)v32 + 1) = 0, v26 <= 16 * v27) )
            {
LABEL_67:
              __break(1u);
              goto LABEL_68;
            }
            v33 = *v32;
            if ( v33 >= *(unsigned int *)(v3 + 8) )
              break;
            v34 = *(_QWORD *)v3 + 56LL * (unsigned int)v33;
            v35 = *(unsigned int *)(v34 + 8);
            if ( !(_DWORD)v35 )
              goto LABEL_24;
            if ( v26 < (v31 | 4) )
              goto LABEL_67;
            v36 = *(int **)v34;
            v37 = StatusReg;
            v38 = 0;
            while ( 1 )
            {
              v39 = *v36;
              v36 += 12;
              if ( v39 == v32[1] )
                break;
              if ( v35 == ++v38 )
              {
                StatusReg = v37;
                goto LABEL_24;
              }
            }
            v40 = a1[1783];
            if ( *(_QWORD *)(*(_QWORD *)(v40 + 40) + 304LL) )
            {
              v60 = v28;
              v62 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              ++*(_DWORD *)(v37 + 16);
              v42 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1[1783] + 40LL) + 304LL);
              if ( *((_DWORD *)v42 - 1) != -1780529452 )
                __break(0x8228u);
              v43 = v42(a1);
              if ( (v43 & 1) == 0 )
              {
                StatusReg = v37;
                v53 = *(_QWORD *)(v37 + 16) - 1LL;
                *(_DWORD *)(v37 + 16) = v53;
                if ( !v53 || !*(_QWORD *)(v37 + 16) )
                  preempt_schedule(v43);
                _WriteStatusReg(DAIF, v62);
                v8 = v59;
                if ( (unsigned int)__ratelimit(&adreno_perfcounter_read_group__rs, "adreno_perfcounter_read_group") )
                  dev_err(*a1, "Timed out waiting to acquire CP semaphore: status=0x%08x\n", 0);
                v28 = -11;
                goto LABEL_23;
              }
              v26 = v63;
              if ( v63 <= v31 )
                goto LABEL_67;
              v33 = *v32;
              v40 = a1[1783];
              v28 = v60;
              v8 = v59;
            }
            else
            {
              v62 = 0;
            }
            v44 = *(_QWORD *)(v40 + 48);
            if ( v44
              && *(unsigned int *)(v44 + 8) > v33
              && (v13 = *(_QWORD *)v44 + 56LL * (unsigned int)v33, *(_DWORD *)(v13 + 8) > (unsigned int)v38) )
            {
              v45 = *(__int64 (__fastcall **)(_QWORD))(v13 + 40);
              v46 = v28;
              if ( *((_DWORD *)v45 - 1) != -1490883378 )
                __break(0x8229u);
              v47 = v45(a1);
              v26 = v63;
              v28 = v46;
            }
            else
            {
              v47 = 0;
            }
            if ( v26 < v30 )
              goto LABEL_67;
            v48 = v28;
            v49 = a1[1783];
            *((_QWORD *)v32 + 1) = v47;
            StatusReg = v37;
            v50 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v49 + 40) + 312LL);
            if ( v50 )
            {
              if ( *((_DWORD *)v50 - 1) != 994519391 )
                __break(0x8228u);
              v51 = v50(a1);
              v52 = *(_QWORD *)(v37 + 16) - 1LL;
              *(_DWORD *)(v37 + 16) = v52;
              if ( !v52 || !*(_QWORD *)(v37 + 16) )
                preempt_schedule(v51);
              _WriteStatusReg(DAIF, v62);
              v28 = v48;
LABEL_23:
              v26 = v63;
              v29 = v61;
              goto LABEL_24;
            }
            v29 = v61;
            v28 = v48;
LABEL_24:
            if ( ++v27 == v29 )
              goto LABEL_63;
          }
          v28 = -22;
LABEL_63:
          v54 = v28;
          gmu_core_dev_oob_clear(a1, 1);
          adreno_active_count_put((__int64)a1);
          rt_mutex_unlock(a1 + 1386);
          v14 = v54;
          if ( !v54 )
          {
            _check_object_size(v8, v58, 1);
            if ( inline_copy_to_user_0(a2, v8, v58) )
              v14 = -14;
            else
              v14 = 0;
          }
          goto LABEL_20;
        }
        v14 = v25;
        adreno_active_count_put((__int64)a1);
      }
      rt_mutex_unlock(a1 + 1386);
LABEL_20:
      kfree(v8);
      return v14;
    }
    return 4294967284LL;
  }
  return result;
}
