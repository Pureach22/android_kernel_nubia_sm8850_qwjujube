__int64 __fastcall smart_freq_update_reason_common(__int64 result, unsigned int a2, unsigned int a3)
{
  __int64 v4; // x8
  __int64 v6; // x21
  char v7; // w24
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x1
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x1
  char v12; // w2
  unsigned __int64 v13; // x2
  unsigned __int64 v14; // x2
  bool v15; // cc
  __int64 v16; // x25
  _QWORD *v17; // x2
  _BYTE *v18; // x6
  char *v19; // x30
  int *v20; // x8
  int v21; // w9
  int v22; // w4
  int v23; // w10
  int v24; // w10
  bool v25; // zf
  int v26; // w11
  int v28; // w11
  char v29; // w11
  bool v30; // zf
  char v31; // w11
  bool v32; // zf
  char v33; // w11
  bool v34; // zf
  unsigned int v36; // w9
  char v37; // w10
  unsigned __int64 v38; // x10
  unsigned __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x10
  char *v42; // x11
  unsigned __int64 v43; // x9
  __int64 v44; // x12
  __int64 v45; // x22
  int v46; // w11
  __int64 v47; // x15
  int v48; // w14
  int *v49; // x16
  __int64 v50; // x14
  __int64 v51; // x1
  __int64 v52; // x8
  __int64 v53; // x8
  _DWORD **v54; // x22
  unsigned int v55; // w26
  unsigned int v56; // w23
  _DWORD *v57; // x27
  __int64 v58; // x24
  _QWORD *v59; // x21
  _BYTE *v60; // x19
  char *v61; // x20
  __int64 v62; // x1
  __int64 v63; // [xsp+10h] [xbp-10h]
  char v64; // [xsp+1Ch] [xbp-4h]

  if ( smart_freq_init_done == 1 )
  {
    v4 = cluster_head;
    v6 = result;
    if ( (__int64 *)cluster_head == &cluster_head )
    {
      v7 = 0;
    }
    else
    {
      v7 = 0;
      do
      {
        v8 = *(unsigned int *)(v4 + 16);
        if ( !*(_DWORD *)(v4 + 16) )
        {
LABEL_133:
          __break(0x5512u);
          JUMPOUT(0x5B1B4);
        }
        v9 = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + __clz(__rbit64(v8))));
        v10 = v9 % *(unsigned int *)(v4 + 32) * *(_QWORD *)(*(_QWORD *)(v4 + 472) + 32LL) / *(unsigned int *)(v4 + 32)
            + v9 / *(unsigned int *)(v4 + 32) * *(_QWORD *)(*(_QWORD *)(v4 + 472) + 32LL);
        v11 = (unsigned __int16)(90 * (v10 % 0x64)) / 0x64u + 90 * (v10 / 0x64);
        v12 = 0;
        while ( 1 )
        {
          v13 = (-1LL << v12) & v8;
          if ( !v13 )
          {
LABEL_4:
            result = 0;
            *(_QWORD *)(v4 + 464) = 0;
            goto LABEL_5;
          }
          v14 = __clz(__rbit64(v13));
          if ( *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v14) + 560] >= v11 )
            break;
          v15 = v14 > 0x1E;
          v12 = v14 + 1;
          if ( v15 )
            goto LABEL_4;
        }
        result = *(_QWORD *)(v4 + 464);
        if ( result )
          result = (unsigned __int64)(v6 - result) > 0x11E1A2FF;
        else
          *(_QWORD *)(v4 + 464) = v6;
LABEL_5:
        v4 = *(_QWORD *)v4;
        v7 |= result;
      }
      while ( (__int64 *)v4 != &cluster_head );
    }
    v16 = cluster_head;
    if ( (__int64 *)cluster_head != &cluster_head )
    {
      result = (__int64)&unk_1000;
      v17 = &_per_cpu_offset;
      v18 = walt_rq;
      v19 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      _ReadStatusReg(SP_EL0);
      v64 = v7;
      v63 = v6;
      while ( 1 )
      {
        v20 = *(int **)(v16 + 472);
        v21 = *v20;
        if ( (*v20 & 1) == 0 )
          break;
        v22 = 1;
        if ( v21 != 1 )
          goto LABEL_23;
LABEL_108:
        v40 = *(unsigned int *)(v16 + 24);
        if ( (unsigned int)v40 >= 4 )
          goto LABEL_133;
        v41 = 0;
        v42 = (char *)&freq_cap + 4 * v40;
        v43 = *((_QWORD *)v20 + 4);
        v44 = 8;
        v45 = *((unsigned int *)v42 + 4);
        v46 = v20[1];
        do
        {
          v47 = 1LL << v41;
          v48 = v46 & (1LL << v41);
          if ( (v22 & (unsigned int)(1LL << v41)) != 0 )
          {
            v49 = &v20[2 * v41];
            v46 |= v47;
          }
          else
          {
            if ( !v48 )
              goto LABEL_114;
            v49 = &v20[2 * v41];
            v50 = *((_QWORD *)v49 + 26);
            if ( !v50 )
            {
              *((_QWORD *)v49 + 26) = v6;
              v48 = 1;
              goto LABEL_114;
            }
            if ( (unsigned __int64)(v6 - v50) < *(_QWORD *)&v20[v44 + 2] )
            {
              v48 = 1;
              goto LABEL_114;
            }
            v48 = 0;
            v46 &= ~(_DWORD)v47;
          }
          *((_QWORD *)v49 + 26) = 0;
          v20[1] = v46;
LABEL_114:
          if ( v48 | v22 & (unsigned int)(1LL << v41) && v43 <= *(_QWORD *)&v20[v44] )
            v43 = *(_QWORD *)&v20[v44];
          ++v41;
          v44 += 4;
        }
        while ( v41 != 11 );
        v51 = *(unsigned int *)(v16 + 24);
        if ( v43 == v45 )
          goto LABEL_19;
        v52 = *(unsigned int *)(v16 + 24);
        if ( (unsigned int)v52 > 3 )
          goto LABEL_133;
        *((_DWORD *)&freq_cap + v52 + 4) = v43;
        if ( !*(_DWORD *)(v16 + 16) )
          goto LABEL_133;
        v53 = *(unsigned int *)((char *)&runqueues + v17[__clz(__rbit64(*(unsigned int *)(v16 + 16)))] + 3632);
        if ( (unsigned int)v53 >= 0x20 )
          goto LABEL_133;
        v54 = *(_DWORD ***)((char *)&waltgov_cb_data + v17[v53]);
        if ( v54 )
        {
          v55 = a2;
          v56 = a3;
          v57 = *v54;
          v58 = result;
          v59 = v17;
          v60 = v18;
          v61 = v19;
          v62 = walt_sched_clock(result, v51);
          if ( *(v57 - 1) != 1756229429 )
            __break(0x823Bu);
          ((void (__fastcall *)(_DWORD **, __int64, __int64))v57)(v54, v62, 512);
          v17 = v59;
          result = v58;
          v6 = v63;
          v7 = v64;
          v19 = v61;
          v18 = v60;
          a3 = v56;
          a2 = v55;
        }
LABEL_19:
        v16 = *(_QWORD *)v16;
        if ( (__int64 *)v16 == &cluster_head )
          return result;
      }
      v22 = 0;
LABEL_23:
      if ( (v21 & 2) != 0 )
      {
        v23 = *((_DWORD *)v19 + 857);
        if ( v23 == 4 )
        {
          v22 |= 2u;
        }
        else if ( v23 == 1 )
        {
          v22 |= 2u;
        }
      }
      v24 = v22 | 0x10;
      if ( trailblazer_boost_state_ns )
        v25 = (v21 & 0x10) == 0;
      else
        v25 = 1;
      if ( v25 )
        v24 = v22;
      if ( (prev_is_sbt & 1) != 0 )
        v26 = v24 | 0x20;
      else
        v26 = v24;
      if ( (v21 & 0x20) != 0 )
        v24 = v26;
      if ( (v21 & 8) != 0 && big_task_cnt <= a2 && a3 < 0x64 )
        v24 |= 8u;
      v28 = v24 | 4;
      if ( (v7 & 1) == 0 )
        v28 = v24;
      if ( (v21 & 4) != 0 )
        v24 = v28;
      if ( (v21 & 0x40) != 0 )
      {
        if ( *((_DWORD *)v19 + 857) )
        {
          v29 = 0;
        }
        else if ( pipeline_nr )
        {
          v29 = 1;
        }
        else
        {
          if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
            v30 = have_heavy_list == 0;
          else
            v30 = 1;
          v29 = !v30;
        }
        if ( ((unsigned __int8)v29 & ((unsigned int)sched_ravg_window > 0xF423FF)) != 0 )
          v24 |= 0x40u;
        if ( (v21 & 0x80) == 0 )
        {
LABEL_50:
          if ( (v21 & 0x100) == 0 )
          {
LABEL_90:
            if ( *(_DWORD *)(result + 1324) == -1 || (v21 & 0x200) == 0 )
              v22 = v24;
            else
              v22 = v24 | 0x200;
            if ( (v21 & 0x400) != 0 )
            {
              v36 = *(_DWORD *)(v16 + 24);
              if ( v36 >= 4 )
                goto LABEL_133;
              if ( (default_freq_config[104 * v36] & 0x400) != 0 )
              {
                v37 = 0;
                do
                {
                  v38 = *(unsigned int *)(v16 + 16) & (unsigned __int64)(-1LL << v37);
                  if ( !v38 )
                    break;
                  v39 = __clz(__rbit64(v38));
                  if ( *(_QWORD *)&v18[v17[v39] + 656] )
                  {
                    v22 |= 0x400u;
                    goto LABEL_108;
                  }
                  v15 = v39 > 0x1E;
                  v37 = v39 + 1;
                }
                while ( !v15 );
              }
            }
            if ( !(v22 | v20[1]) )
              goto LABEL_19;
            goto LABEL_108;
          }
LABEL_78:
          if ( *((_DWORD *)v19 + 857) )
          {
            v33 = 0;
          }
          else if ( pipeline_nr )
          {
            v33 = 1;
          }
          else
          {
            if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
              v34 = have_heavy_list == 0;
            else
              v34 = 1;
            v33 = !v34;
          }
          if ( ((unsigned __int8)v33 & (sched_ravg_window == 8000000)) != 0 )
            v24 |= 0x100u;
          goto LABEL_90;
        }
      }
      else if ( (v21 & 0x80) == 0 )
      {
        goto LABEL_50;
      }
      if ( *((_DWORD *)v19 + 857) )
      {
        v31 = 0;
      }
      else if ( pipeline_nr )
      {
        v31 = 1;
      }
      else
      {
        if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
          v32 = have_heavy_list == 0;
        else
          v32 = 1;
        v31 = !v32;
      }
      if ( ((unsigned __int8)v31 & (sched_ravg_window == 12000000)) != 0 )
        v24 |= 0x80u;
      if ( (v21 & 0x100) == 0 )
        goto LABEL_90;
      goto LABEL_78;
    }
  }
  return result;
}
