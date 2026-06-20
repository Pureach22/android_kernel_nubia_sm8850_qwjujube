__int64 __fastcall cluster_power_cb(__int64 remaining, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x23
  __int64 v7; // x10
  __int64 v8; // x25
  int v9; // w24
  unsigned int v10; // w9
  __int64 v11; // x10
  __int64 v12; // x12
  __int64 v13; // x14
  __int64 v14; // x10
  __int64 *v15; // x13
  int v16; // w11
  __int64 v18; // x19
  char v19; // w13
  __int64 v20; // x19
  unsigned __int64 v21; // x13
  unsigned __int64 v22; // x13
  __int64 v23; // x13
  int v24; // w12
  unsigned int v25; // w9
  int v26; // w19
  int v27; // w0
  _UNKNOWN **v28; // x10
  _QWORD *v29; // x12
  _QWORD *v30; // x12
  _QWORD *v31; // x12
  __int64 v32; // x9
  int v33; // w13
  __int64 v34; // x12
  unsigned int v35; // w11
  int v36; // w10
  unsigned __int64 v37; // x13
  __int64 v38; // x12
  __int64 v39; // x22
  int v40; // w10
  unsigned __int64 v41; // kr00_8
  __int64 v42; // x13
  __int64 v43; // x9
  int v44; // w11
  unsigned __int64 v45; // x12
  unsigned __int64 v46; // x5
  unsigned __int64 v47; // x4
  bool v48; // cf
  __int64 v49; // x4
  unsigned int v50; // w2
  __int64 v51; // x4
  __int64 v52; // x4
  __int64 v53; // x4
  __int64 v54; // x4
  unsigned int v55; // w8
  __int64 v56; // x20
  __int64 v57; // x21
  __int64 (__fastcall *v58)(__int64, _QWORD, __int64, _QWORD); // x8
  __int64 v59; // x0
  __int64 v60; // t1
  __int64 v61; // x8
  unsigned int v62; // [xsp+14h] [xbp-Ch]
  __int64 v63; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(remaining - 48);
  v5 = *(unsigned int *)(v4 + 1460);
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      _ReadStatusReg(SP_EL0);
    }
    else if ( a2 == 3 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(remaining - 48) + 1312LL) )
          return 1;
        v2 = remaining;
        *(_QWORD *)(remaining + 152) = ktime_get();
        v6 = v2;
        remaining = _hrtimer_get_remaining(v2 + 56, 0);
        if ( remaining >= 1000 )
          remaining = hrtimer_try_to_cancel(v2 + 56);
        v5 = v2;
        if ( (prediction_disabled & 1) != 0 )
          goto LABEL_46;
        v8 = *(_QWORD *)(v2 - 48);
        v9 = *(_DWORD *)(v8 + 1460);
        if ( *(_DWORD *)(v2 - 192) != v9 )
          goto LABEL_46;
        v10 = *(_DWORD *)(v2 - 200);
        if ( v10 < 5 )
        {
          v11 = *(_QWORD *)(v2 + 120);
          v12 = v2 - 168;
          v13 = (unsigned __int128)(v11 * (__int128)0x20C49BA5E353F7CFLL) >> 64;
          v14 = (unsigned __int128)((*(_QWORD *)(v2 + 152) - v11) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
          v15 = (__int64 *)(v2 - 168 + 24LL * v10);
          v16 = *(unsigned __int8 *)(v2 - 195);
          v7 = (v14 >> 7) + ((unsigned __int64)v14 >> 63);
          v15[2] = (v13 >> 7) + ((unsigned __int64)v13 >> 63);
          if ( v16 != 1 )
          {
            *v15 = v7;
            goto LABEL_33;
          }
          if ( v10 )
            --v10;
          else
            v10 = 4;
          if ( v10 <= 4 )
          {
            *(_BYTE *)(v2 - 195) = 0;
            *(_QWORD *)(v12 + 24LL * v10) += v7;
LABEL_33:
            v23 = v12 + 24LL * v10;
            v24 = *(_DWORD *)(v2 - 184);
            *(_DWORD *)(v2 - 192) = 0x80000000;
            *(_DWORD *)(v23 + 8) = v9;
            *(_QWORD *)(v2 + 120) = 0;
            if ( v24 <= 4 )
              *(_DWORD *)(v2 - 184) = v24 + 1;
            if ( v10 == 4 )
              v25 = 0;
            else
              v25 = v10 + 1;
            *(_DWORD *)(v2 - 200) = v25;
            if ( (unsigned __int64)(1000 * v7) >= *(_QWORD *)(*(_QWORD *)(v8 + 1440) + ((__int64)v9 << 6) + 16) )
            {
              v26 = _sw_hweight64(_cpu_possible_mask);
              v27 = _sw_hweight64(*(unsigned int *)(v8 + 1328));
              v5 = v6;
              if ( v26 == v27 && v9 == *(_DWORD *)(v8 + 1456) - 1 )
              {
                clear_cpu_predict_history();
                v5 = v6;
                v28 = (_UNKNOWN **)cluster_dev_list;
                if ( cluster_dev_list != (_UNKNOWN *)&cluster_dev_list )
                {
                  do
                  {
                    if ( *((_BYTE *)v28 + 21) == 1 )
                    {
                      *(v28 - 32) = nullptr;
                      *(v28 - 31) = nullptr;
                      *(v28 - 43) = nullptr;
                      v29 = v28 - 41;
                      *v29 = 0;
                      v29[1] = 0;
                      v30 = v28 - 38;
                      *v30 = 0;
                      v30[1] = 0;
                      v31 = v28 - 35;
                      *v31 = 0;
                      v31[1] = 0;
                      *((_DWORD *)v28 - 84) = -1;
                      *((_DWORD *)v28 - 94) = 0;
                      *((_DWORD *)v28 - 78) = -1;
                      *((_DWORD *)v28 - 90) = 0;
                      *((_DWORD *)v28 - 72) = -1;
                      *((_WORD *)v28 - 186) = 0;
                      *((_DWORD *)v28 - 66) = -1;
                      *((_DWORD *)v28 - 60) = -1;
                      *(v28 - 29) = nullptr;
                      *((_BYTE *)v28 + 20) = 0;
                      *((_DWORD *)v28 - 91) = -1;
                    }
                    v28 = (_UNKNOWN **)*v28;
                  }
                  while ( v28 != &cluster_dev_list );
                }
              }
            }
LABEL_46:
            if ( (prediction_disabled & 1) == 0 )
            {
              v32 = *(_QWORD *)(v5 - 48);
              v33 = *(unsigned __int8 *)(v5 - 196);
              v34 = *(_QWORD *)(v5 + 152);
              v35 = *(_DWORD *)(v32 + 1460);
              *(_QWORD *)(v5 + 144) = 0x7FFFFFFFFFFFFFFFLL;
              *(_BYTE *)(v5 + 196) = 0;
              *(_QWORD *)(v5 + 160) = 0;
              if ( v33 == 1 )
              {
                *(_BYTE *)(v5 - 196) = 0;
              }
              else
              {
                v36 = *(_DWORD *)(v5 - 184);
                if ( v36 != 5 )
                  goto LABEL_63;
                v37 = *(unsigned int *)(v5 - 180);
                v38 = v34 / 1000;
                if ( v38 - *(_QWORD *)(v5 - 152) <= v37 )
                {
                  v36 = 5;
                }
                else
                {
                  v36 = 4;
                  *(_DWORD *)(v5 - 184) = 4;
                }
                if ( v38 - *(_QWORD *)(v5 - 128) > v37 )
                  *(_DWORD *)(v5 - 184) = --v36;
                if ( v38 - *(_QWORD *)(v5 - 104) > v37 )
                  *(_DWORD *)(v5 - 184) = --v36;
                if ( v38 - *(_QWORD *)(v5 - 80) > v37 )
                  *(_DWORD *)(v5 - 184) = --v36;
                if ( v38 - *(_QWORD *)(v5 - 56) > v37 )
                {
                  *(_DWORD *)(v5 - 184) = v36 - 1;
                }
                else
                {
LABEL_63:
                  if ( v36 >= 5 )
                  {
                    v40 = *(_DWORD *)(v32 + 1456);
                    if ( v35 >= v40 - 1 )
                    {
                      if ( v40 )
                      {
                        v44 = 0;
                        v45 = 0;
                        while ( 1 )
                        {
                          if ( *(_DWORD *)(v5 - 160) == v44 )
                          {
                            v46 = 1000LL * *(_QWORD *)(v5 - 168);
                            v47 = *(_QWORD *)(*(_QWORD *)(v32 + 1440) + ((__int64)v44 << 6) + 16);
                            v48 = v46 >= v47;
                            if ( v46 >= v47 )
                              v49 = 0;
                            else
                              v49 = *(_QWORD *)(v5 - 168);
                            v50 = !v48;
                            v45 += v49;
                          }
                          else
                          {
                            v50 = 0;
                          }
                          if ( *(_DWORD *)(v5 - 136) == v44 )
                          {
                            v51 = *(_QWORD *)(v5 - 144);
                            if ( (unsigned __int64)(1000 * v51) < *(_QWORD *)(*(_QWORD *)(v32 + 1440)
                                                                            + ((__int64)v44 << 6)
                                                                            + 16) )
                            {
                              ++v50;
                              v45 += v51;
                            }
                          }
                          if ( *(_DWORD *)(v5 - 112) == v44 )
                          {
                            v52 = *(_QWORD *)(v5 - 120);
                            if ( (unsigned __int64)(1000 * v52) < *(_QWORD *)(*(_QWORD *)(v32 + 1440)
                                                                            + ((__int64)v44 << 6)
                                                                            + 16) )
                            {
                              ++v50;
                              v45 += v52;
                            }
                          }
                          if ( *(_DWORD *)(v5 - 88) == v44 )
                          {
                            v53 = *(_QWORD *)(v5 - 96);
                            if ( (unsigned __int64)(1000 * v53) < *(_QWORD *)(*(_QWORD *)(v32 + 1440)
                                                                            + ((__int64)v44 << 6)
                                                                            + 16) )
                            {
                              ++v50;
                              v45 += v53;
                            }
                          }
                          if ( *(_DWORD *)(v5 - 64) == v44 )
                          {
                            v54 = *(_QWORD *)(v5 - 72);
                            if ( (unsigned __int64)(1000 * v54) < *(_QWORD *)(*(_QWORD *)(v32 + 1440)
                                                                            + ((__int64)v44 << 6)
                                                                            + 16) )
                            {
                              ++v50;
                              v45 += v54;
                            }
                          }
                          if ( v50 >= *(_DWORD *)(v5 - 176) )
                            break;
                          if ( v40 == ++v44 )
                            return 1;
                        }
                        *(_DWORD *)(v5 - 188) = v44;
                        *(_BYTE *)(v5 + 196) = 1;
                        *(_QWORD *)(v5 + 160) = v45 / v50;
                      }
                    }
                    else
                    {
                      v41 = *(_QWORD *)(v5 - 144)
                          + *(_QWORD *)(v5 - 168)
                          + *(_QWORD *)(v5 - 120)
                          + *(_QWORD *)(v5 - 96)
                          + *(_QWORD *)(v5 - 72);
                      *(_BYTE *)(v5 + 196) = 1;
                      *(_QWORD *)(v5 + 160) = v41 / 5;
                      v42 = *(_QWORD *)(v32 + 1440);
                      v43 = (unsigned int)(*(_DWORD *)(v32 + 1456) - 1);
                      if ( 1000 * (v41 / 5) <= *(_QWORD *)(v42 + (v43 << 6) + 16) )
                        *(_DWORD *)(v5 - 188) = v43;
                      else
                        *(_DWORD *)(v5 - 188) = -1;
                    }
                  }
                }
              }
            }
            return 1;
          }
        }
LABEL_98:
        __break(0x5512u);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          v62 = v7;
          v56 = remaining;
          v63 = v5;
          ++*(_DWORD *)(StatusReg + 16);
          v57 = qword_C510;
          if ( qword_C510 )
          {
            do
            {
              v58 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD))v57;
              v59 = *(_QWORD *)(v57 + 8);
              if ( *(_DWORD *)(*(_QWORD *)v57 - 4LL) != -295030581 )
                __break(0x8228u);
              remaining = v58(v59, v62, v63, (unsigned int)v2);
              v60 = *(_QWORD *)(v57 + 24);
              v57 += 24;
            }
            while ( v60 );
          }
          v61 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v61;
          if ( !v61 || (remaining = v56, !*(_QWORD *)(StatusReg + 16)) )
          {
            preempt_schedule_notrace(remaining);
            remaining = v56;
          }
        }
      }
    }
    return 1;
  }
  if ( !*(_QWORD *)(v4 + 1232) )
    return 32770;
  v7 = *(unsigned int *)(v4 + 1328);
  if ( (v7 & _cpu_online_mask) != 0 )
  {
    if ( (unsigned int)v5 >= 4 )
      goto LABEL_98;
    if ( *(_BYTE *)(remaining + v5 + 168) == 1 )
    {
      if ( *(_DWORD *)(v4 + 1312) )
      {
        v18 = remaining;
        clear_cpu_predict_history();
        *(_QWORD *)(v18 - 168) = 0;
        *(_DWORD *)(v18 - 160) = -1;
        *(_QWORD *)(v18 - 152) = 0;
        *(_QWORD *)(v18 - 144) = 0;
        *(_DWORD *)(v18 - 136) = -1;
        *(_QWORD *)(v18 - 128) = 0;
        *(_QWORD *)(v18 - 120) = 0;
        *(_DWORD *)(v18 - 112) = -1;
        *(_QWORD *)(v18 - 104) = 0;
        *(_QWORD *)(v18 - 96) = 0;
        *(_DWORD *)(v18 - 88) = -1;
        *(_QWORD *)(v18 - 80) = 0;
        *(_QWORD *)(v18 - 72) = 0;
        *(_DWORD *)(v18 - 64) = -1;
        *(_QWORD *)(v18 - 56) = 0;
        *(_DWORD *)(v18 - 200) = 0;
        *(_WORD *)(v18 - 196) = 0;
        *(_BYTE *)(v18 + 196) = 0;
        *(_QWORD *)(v18 - 188) = 0xFFFFFFFFLL;
        return 1;
      }
      v19 = 0;
      v20 = remaining - 208;
      do
      {
        v21 = v7 & (-1LL << v19);
        if ( !v21 )
          break;
        v22 = __clz(__rbit64(v21));
        if ( ((_cpu_online_mask >> v22) & 1) != 0 && (lpm_cpu_data[_per_cpu_offset[v22] + 316] & 1) != 0 )
          return 32770;
        v48 = v22 >= 0x1F;
        v19 = v22 + 1;
      }
      while ( !v48 );
      v39 = remaining;
      *(_QWORD *)(remaining + 152) = ktime_get();
      if ( !(unsigned int)cluster_power_down(v20) )
      {
        v55 = *(_DWORD *)(v39 - 188);
        if ( v55 == -1 || *(_DWORD *)(v4 + 1460) < v55 )
          return 1;
      }
    }
    return 32770;
  }
  return 1;
}
