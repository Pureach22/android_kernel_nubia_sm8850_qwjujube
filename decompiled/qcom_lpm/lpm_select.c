__int64 __fastcall lpm_select(__int64 a1, __int64 a2)
{
  char v4; // w8
  _BYTE *v5; // x19
  __int64 v6; // x27
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x22
  unsigned __int64 sleep_length; // x2
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v15; // x8
  _BYTE *v16; // x9
  unsigned int v18; // w22
  __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x10
  __int64 v22; // x9
  int v23; // w8
  unsigned int v24; // w9
  unsigned __int64 v25; // x20
  int v26; // w0
  int v27; // w28
  __int64 v28; // x25
  __int64 v29; // x8
  __int64 v30; // x8
  bool v31; // cc
  __int64 v32; // x26
  __int64 v33; // x0
  int v34; // w9
  __int64 v35; // x8
  __int64 v36; // x9
  unsigned int v37; // w0
  unsigned __int64 v38; // x16
  unsigned int v39; // w17
  __int64 v40; // x1
  __int64 v41; // x1
  __int64 v42; // x1
  __int64 v43; // x1
  __int64 v44; // x10
  unsigned __int64 v45; // x9
  __int64 v46; // x0
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x2
  __int64 v49; // x10
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x11
  unsigned int v53; // w8
  unsigned int v54; // w9
  unsigned int v55; // w23
  _BYTE *v56; // x8
  int v57; // w8
  void (__fastcall *v58)(_QWORD); // x8
  __int64 v59; // x8
  unsigned int v60; // w8
  int v61; // w8
  int v62; // w8
  int v63; // w8
  __int64 v64; // x9
  _BYTE *v65; // x8
  __int64 v66; // [xsp+8h] [xbp-28h]
  unsigned __int64 v67; // [xsp+10h] [xbp-20h]
  __int64 v68; // [xsp+18h] [xbp-18h] BYREF
  __int64 v69; // [xsp+20h] [xbp-10h]
  __int64 v70; // [xsp+28h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  v5 = &lpm_cpu_data[_ReadStatusReg(TPIDR_EL1)];
  v6 = 2000000000000LL;
  v7 = *(_QWORD *)((char *)&cpu_bit_bitmap
                 + 8 * (*(_DWORD *)(a2 + 4) & 0x3FLL)
                 - (((unsigned __int64)*(unsigned int *)(a2 + 4) >> 3) & 0x1FFFFFF8)
                 + 8);
  do
  {
    v8 = (unsigned int)(-1LL << v4) & (unsigned int)v7;
    if ( !(_DWORD)v8 )
      break;
    v9 = __clz(__rbit64(v8));
    if ( ((_cpu_active_mask >> v9) & 1) != 0 )
    {
      v10 = cpuidle_governor_latency_req((unsigned int)v9);
      if ( v10 < v6 )
        v6 = v10;
    }
    v4 = v9 + 1;
  }
  while ( v9 < 0x1F );
  v68 = 0;
  if ( !v5 || (v5[324] & 1) != 0 )
  {
    LODWORD(v11) = 0;
    goto LABEL_18;
  }
  *((_QWORD *)v5 + 8) = 0;
  v5[76] = 0;
  *((_QWORD *)v5 + 36) = ktime_get();
  sleep_length = tick_nohz_get_sleep_length(&v68);
  if ( (sleep_disabled & 1) == 0 && (prediction_disabled & 1) == 0 )
  {
    v18 = *((_DWORD *)v5 + 2);
    if ( (v18 & 0x80000000) == 0 )
    {
      v19 = *((_QWORD *)v5 + 5);
      if ( (int)v18 <= *(_DWORD *)(v19 + 1064) - 1 )
      {
        if ( v18 >= 0xB )
          goto LABEL_115;
        v20 = *(unsigned int *)(v19 + 104LL * v18 + 92);
        v21 = *(_QWORD *)(*((_QWORD *)v5 + 6) + 24LL) / 1000LL;
        v22 = *((unsigned int *)v5 + 63);
        if ( v21 <= v20 )
          LODWORD(v20) = 0;
        v23 = v21 - v20;
        if ( v5[77] == 1 )
        {
          if ( (_DWORD)v22 )
            v24 = v22 - 1;
          else
            v24 = 4;
          *((_DWORD *)v5 + 63) = v24;
          if ( v24 > 4 )
            goto LABEL_115;
          *(_DWORD *)&v5[4 * v24 + 228] += v23;
          v5[77] = 0;
        }
        else
        {
          if ( (unsigned int)v22 > 4 )
            goto LABEL_115;
          *(_DWORD *)&v5[4 * v22 + 228] = v23;
        }
        v59 = *((unsigned int *)v5 + 63);
        if ( (unsigned int)v59 <= 4 )
        {
          *(_DWORD *)&v5[4 * v59 + 208] = v18;
          v60 = *((_DWORD *)v5 + 63);
          *((_DWORD *)v5 + 78) = 0;
          if ( v60 <= 4 )
          {
            v61 = *((_DWORD *)v5 + 62);
            if ( v61 <= 4 )
              *((_DWORD *)v5 + 62) = v61 + 1;
            v62 = *((_DWORD *)v5 + 63);
            if ( (unsigned int)(v62 + 1) <= 4 )
              v63 = v62 + 1;
            else
              v63 = 0;
            *((_DWORD *)v5 + 63) = v63;
            goto LABEL_12;
          }
        }
LABEL_115:
        __break(0x5512u);
      }
    }
  }
LABEL_12:
  v13 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v13 >= 0x20 )
    goto LABEL_115;
  v69 = 0;
  v14 = _per_cpu_offset[v13];
  if ( (suspend_in_progress & 1) == 0 )
  {
    if ( ((_cpu_active_mask >> v13) & 1) == 0 )
      goto LABEL_35;
    if ( (sleep_length & 0x8000000000000000LL) != 0 || (sleep_disabled & 1) != 0 )
      goto LABEL_14;
    v25 = sleep_length;
    v26 = sched_lpm_disallowed_time();
    sleep_length = v25;
    if ( v26 )
    {
LABEL_35:
      v27 = *(_DWORD *)(a1 + 1064);
      v11 = (unsigned int)(v27 - 1);
      if ( (int)v11 >= 1 )
      {
        v28 = 0;
        do
        {
          if ( (unsigned __int64)v11 > 9 )
            goto LABEL_115;
          if ( *(_QWORD *)(a2 + 48 + (v11 << 6)) )
          {
            v29 = 1;
          }
          else
          {
            v32 = a1 + 24 + 104 * v11;
            if ( v6 / 0x3E8uLL >= *(unsigned int *)(v32 + 68) )
            {
              if ( *(_QWORD *)(v32 + 56) <= sleep_length )
              {
                if ( ((*(_QWORD *)((char *)&_cpu_active_mask
                                 + (((unsigned __int64)*(unsigned int *)(a2 + 4) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a2 + 4))
                    & 1) != 0
                  && (v5[76] & 1) == 0 )
                {
                  if ( (prediction_disabled & 1) == 0 )
                  {
                    if ( *((_DWORD *)v5 + 18) )
                    {
                      *((_DWORD *)v5 + 18) = 0;
                      v5[77] = 1;
                      *((_QWORD *)v5 + 38) = 0;
                    }
                    else if ( *(_QWORD *)(*((_QWORD *)v5 + 5) + 80LL) <= sleep_length )
                    {
                      if ( *((int *)v5 + 62) > 4 )
                      {
                        v66 = *((_QWORD *)v5 + 5);
                        v67 = sleep_length;
                        v33 = ((__int64 (__fastcall *)(_BYTE *, _BYTE *))find_deviation)(v5, v5 + 228);
                        *((_QWORD *)v5 + 8) = v33;
                        if ( v33 )
                        {
                          sleep_length = v67;
                          *((_DWORD *)v5 + 78) = 1;
                        }
                        else
                        {
                          sleep_length = v67;
                          v34 = *(_DWORD *)(v66 + 1064);
                          if ( v34 < 2 )
                            goto LABEL_79;
                          v35 = 0;
                          v36 = 104LL * (unsigned int)v34 - 104;
                          while ( 1 )
                          {
                            if ( v35 == 1040 )
                              goto LABEL_115;
                            v37 = *(_DWORD *)(v66 + 204 + v35);
                            if ( 104LL * *((unsigned int *)v5 + 52) - 104 == v35 )
                            {
                              LODWORD(v38) = *((_DWORD *)v5 + 57);
                              v39 = (unsigned int)v38 < v37;
                              if ( (unsigned int)v38 >= v37 )
                                v38 = 0;
                              else
                                v38 = (unsigned int)v38;
                            }
                            else
                            {
                              v39 = 0;
                              v38 = 0;
                            }
                            if ( 104LL * *((unsigned int *)v5 + 53) - 104 == v35 )
                            {
                              v40 = *((unsigned int *)v5 + 58);
                              if ( (unsigned int)v40 < v37 )
                              {
                                ++v39;
                                v38 += v40;
                              }
                            }
                            if ( 104LL * *((unsigned int *)v5 + 54) - 104 == v35 )
                            {
                              v41 = *((unsigned int *)v5 + 59);
                              if ( (unsigned int)v41 < v37 )
                              {
                                ++v39;
                                v38 += v41;
                              }
                            }
                            if ( 104LL * *((unsigned int *)v5 + 55) - 104 == v35 )
                            {
                              v42 = *((unsigned int *)v5 + 60);
                              if ( (unsigned int)v42 < v37 )
                              {
                                ++v39;
                                v38 += v42;
                              }
                            }
                            if ( 104LL * *((unsigned int *)v5 + 56) - 104 == v35 )
                            {
                              v43 = *((unsigned int *)v5 + 61);
                              if ( (unsigned int)v43 < v37 )
                              {
                                ++v39;
                                v38 += v43;
                              }
                            }
                            if ( v39 >= 3 )
                              break;
                            v35 += 104;
                            if ( v36 == v35 )
                              goto LABEL_79;
                          }
                          v44 = *((_QWORD *)v5 + 36);
                          v45 = v38 / v39;
                          *((_DWORD *)v5 + 78) = 2;
                          *((_QWORD *)v5 + 8) = v45;
                          *((_QWORD *)v5 + 38) = v44 / 1000 + v45;
                          if ( v38 < v39 )
                          {
LABEL_79:
                            v46 = ((__int64 (__fastcall *)(_BYTE *, _BYTE *, unsigned __int64, __int64, __int64, void *, __int64, void *))find_deviation)(
                                    v5,
                                    v5 + 256,
                                    v67,
                                    104,
                                    1,
                                    &_cpu_active_mask,
                                    2,
                                    &loc_C000);
                            sleep_length = v67;
                            *((_QWORD *)v5 + 8) = v46;
                            if ( v46 )
                              *((_DWORD *)v5 + 78) = 3;
                          }
                        }
                      }
                      else
                      {
                        *((_QWORD *)v5 + 38) = 0;
                      }
                    }
                  }
                  v5[76] = 1;
                }
                v47 = *((_QWORD *)v5 + 8);
                if ( !v47 || v47 >= *(unsigned int *)(v32 + 76) )
                  goto LABEL_86;
                v29 = 8;
              }
              else
              {
                v29 = 4;
              }
            }
            else
            {
              v29 = 2;
            }
          }
          v27 = v11;
          v30 = v29 << (8 * (unsigned __int8)v11);
          v31 = v11-- <= 1;
          v28 |= v30;
        }
        while ( !v31 );
        LODWORD(v11) = 0;
        v27 = 1;
      }
LABEL_86:
      *((_DWORD *)v5 + 2) = v11;
      v48 = sleep_length / 0x3E8;
      v49 = *((_QWORD *)v5 + 36) + 1000 * v48;
      v50 = *((_QWORD *)v5 + 8);
      *((_QWORD *)v5 + 7) = v49;
      if ( !v50 )
        goto LABEL_96;
      v51 = *((_QWORD *)v5 + 5);
      if ( (unsigned int)v11 >= *(_DWORD *)(v51 + 1064) - 1 )
        goto LABEL_96;
      v52 = *((_QWORD *)v5 + 38);
      if ( v49 > v52 )
        *((_QWORD *)v5 + 7) = v52;
      v53 = v50 + 100;
      v54 = *(_DWORD *)(v51 + 104LL * v27 + 100) - 1;
      v55 = v53 >= v54 ? v54 : v53;
      if ( (unsigned int)v48 > v55 )
      {
        if ( (unsigned int)v48 - v55 <= v54 )
        {
          v57 = v11;
        }
        else
        {
          v56 = &lpm_cpu_data[_ReadStatusReg(TPIDR_EL1)];
          *((_QWORD *)v56 + 15) = histtimer_fn;
          hrtimer_start_range_ns(v56 + 80, 1000LL * v55, 0, 3);
          v57 = *((_DWORD *)v5 + 2);
        }
      }
      else
      {
LABEL_96:
        v57 = v11;
      }
      if ( v57 == *(_DWORD *)(a1 + 1064) - 1 )
      {
        if ( cluster_gov_ops )
        {
          v58 = *(void (__fastcall **)(_QWORD))cluster_gov_ops;
          if ( *(_QWORD *)cluster_gov_ops )
          {
            if ( *((_DWORD *)v58 - 1) != 1795193624 )
              __break(0x8228u);
            v58(v5);
          }
        }
      }
      goto LABEL_15;
    }
    v64 = v69;
    v65 = &lpm_cpu_data[v14];
    *((_DWORD *)v65 + 2) = 0;
    *((_QWORD *)v65 + 37) = v64;
  }
LABEL_14:
  LODWORD(v11) = 0;
LABEL_15:
  if ( !*((_DWORD *)v5 + 2) )
  {
    v15 = *((_QWORD *)v5 + 37);
    if ( v15 )
    {
      v16 = &lpm_cpu_data[_ReadStatusReg(TPIDR_EL1)];
      *((_QWORD *)v16 + 23) = biastimer_fn;
      hrtimer_start_range_ns(v16 + 144, (unsigned int)v15, 0, 3);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
