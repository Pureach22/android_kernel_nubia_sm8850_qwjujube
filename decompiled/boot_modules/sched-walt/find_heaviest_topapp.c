__int64 __fastcall find_heaviest_topapp(unsigned __int64 a1)
{
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x9
  __int64 v6; // x1
  __int64 v7; // x9
  char v8; // w10
  __int64 v9; // x9
  char v10; // w10
  __int64 v11; // x9
  char v12; // w10
  __int64 v13; // x20
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 v16; // x3
  __int64 v17; // x11
  __int64 *v18; // x23
  _DWORD *v19; // x1
  unsigned int *v20; // x12
  unsigned __int64 v21; // x12
  unsigned __int64 v22; // x11
  __int64 *v23; // x5
  __int64 v24; // x7
  __int64 *v25; // x11
  unsigned __int64 v26; // x0
  unsigned int v27; // w1
  bool v28; // cc
  int v29; // w2
  int v30; // w13
  int v31; // w6
  int v32; // w13
  int v33; // w0
  int v34; // w2
  bool v35; // nf
  int v36; // w0
  int v37; // w1
  int v38; // w13
  int v39; // w0
  int v40; // w13
  unsigned __int64 v41; // x13
  bool v42; // cf
  unsigned __int64 v43; // x13
  unsigned int v44; // w6
  __int64 v45; // x0
  __int64 v46; // x11
  __int64 v47; // x26
  unsigned int v48; // w24
  unsigned int v49; // w1
  unsigned int *v50; // x2
  unsigned __int64 v51; // x2
  __int64 *v52; // x9
  __int64 v53; // x8
  unsigned __int64 v54; // x23
  __int64 v55; // x13
  _DWORD *v56; // x8
  unsigned __int64 v57; // x2
  int v58; // w8
  bool v59; // zf
  _BOOL4 v60; // w8
  int v61; // w8
  bool v62; // w11
  int v63; // w13
  __int64 v64; // x11
  __int64 v65; // x12
  __int64 v66; // x12
  __int64 v67; // x15
  _DWORD *v68; // x8
  unsigned int v69; // w11
  int v70; // w13
  _DWORD *v71; // x8
  unsigned int v72; // w13
  _DWORD *v73; // x8
  unsigned int v74; // w13
  int v75; // w17
  __int64 v76; // x11
  bool v77; // w11
  char v78; // w8
  __int64 v79; // x13
  char v80; // w8
  bool v81; // w11
  __int64 v82; // x13
  char v83; // w8
  unsigned __int64 v84; // x15
  unsigned int v85; // w13
  __int64 v86; // x14
  int v87; // w11
  _DWORD *v88; // x8
  unsigned int v89; // w12
  __int64 v90; // x11
  int v91; // w12
  _DWORD *v92; // x8
  unsigned int v93; // w11
  unsigned __int64 v94; // x11
  __int64 v95; // x11
  int v96; // w12
  unsigned int *v97; // x8
  unsigned int v98; // w10
  unsigned __int64 v99; // x9
  unsigned __int64 v100; // x8
  _BOOL8 v101; // x0
  __int64 v102; // [xsp+0h] [xbp-40h]
  __int64 v103; // [xsp+8h] [xbp-38h]
  __int64 v104; // [xsp+10h] [xbp-30h]
  __int64 v105; // [xsp+18h] [xbp-28h]
  int v106; // [xsp+30h] [xbp-10h]
  int v107; // [xsp+34h] [xbp-Ch]
  __int64 v108; // [xsp+38h] [xbp-8h]

  if ( num_sched_clusters < 2 )
    return 0xFFFFFFFFLL;
  v3 = ((__int64 (__fastcall *)(__int64))lookup_related_thread_group)(1);
  if ( !v3
    || !(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres)
    || (v4 = v3, !(unsigned int)_sw_hweight64((unsigned int)cpus_for_pipeline))
    || sched_boost_type )
  {
    if ( have_heavy_list )
    {
      v6 = raw_spin_lock_irqsave(&heavy_lock);
      v7 = heavy_wts[0];
      if ( heavy_wts[0] )
      {
        v8 = *(_BYTE *)(heavy_wts[0] + 191);
        heavy_wts[0] = 0;
        *(_DWORD *)(v7 + 364) = -1;
        *(_BYTE *)(v7 + 191) = v8 & 0xF7;
      }
      v9 = qword_699A8;
      if ( qword_699A8 )
      {
        v10 = *(_BYTE *)(qword_699A8 + 191);
        qword_699A8 = 0;
        *(_DWORD *)(v9 + 364) = -1;
        *(_BYTE *)(v9 + 191) = v10 & 0xF7;
      }
      v11 = qword_699B0;
      if ( qword_699B0 )
      {
        v12 = *(_BYTE *)(qword_699B0 + 191);
        qword_699B0 = 0;
        *(_DWORD *)(v11 + 364) = -1;
        *(_BYTE *)(v11 + 191) = v12 & 0xF7;
      }
      have_heavy_list = 0;
      raw_spin_unlock_irqrestore(&heavy_lock, v6);
      ((void (__fastcall *)(_QWORD, __int64))pipeline_set_unisolation)(0, 1);
    }
    find_heaviest_topapp_last_rearrange_ns = a1;
    least_pipeline_demand = 0;
    return 0xFFFFFFFFLL;
  }
  if ( heavy_wts[0] )
  {
    v5 = find_heaviest_topapp_last_rearrange_ns + 1000000LL * (unsigned int)sysctl_pipeline_rearrange_delay_ms;
    if ( find_heaviest_topapp_last_rearrange_ns )
      goto LABEL_9;
  }
  else
  {
    v5 = find_heaviest_topapp_last_rearrange_ns + 250000000;
    if ( find_heaviest_topapp_last_rearrange_ns )
    {
LABEL_9:
      if ( v5 > a1 )
        return 0;
    }
  }
  find_heaviest_topapp_last_rearrange_ns = a1;
  v13 = raw_spin_lock_irqsave(v4 + 4);
  raw_spin_lock(&heavy_lock);
  v15 = heavy_wts[0];
  v14 = qword_699A8;
  v16 = qword_699B0;
  v17 = pipeline_special_task;
  v18 = sched_cluster;
  heavy_wts[0] = 0;
  qword_699A8 = 0;
  qword_699B0 = 0;
  if ( pipeline_special_task )
  {
    if ( (_UNKNOWN *)pipeline_special_task == &init_task )
      v19 = &vendor_data_pad;
    else
      v19 = (_DWORD *)(pipeline_special_task + 5184);
    v20 = v19 - 1296;
    if ( v19 == (_DWORD *)&vendor_data_pad )
      v20 = (unsigned int *)&init_task;
    v21 = v20[10];
    if ( (unsigned int)(num_sched_clusters - 1) >= 8 )
      goto LABEL_243;
    v22 = v19[8] / (unsigned int)walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(sched_cluster[num_sched_clusters - 1] + ((v21 >> 3) & 0x1FFFFFF8) + 24) >> v21) & 1) != 0 )
      v22 = (unsigned __int16)(100 * ((unsigned int)v22 % 0x46)) / 0x46u + 100LL * ((unsigned int)v22 / 0x46);
    if ( v22 >= (unsigned int)sysctl_pipeline_special_task_util_thres )
    {
      v19 = nullptr;
      v17 = 0;
    }
    else
    {
      v17 = 1;
      heavy_wts[0] = (__int64)v19;
    }
  }
  else
  {
    v19 = nullptr;
  }
  v23 = *(__int64 **)(v4 + 8);
  if ( v23 == (__int64 *)(v4 + 8) )
  {
    LOBYTE(v106) = 0;
    goto LABEL_110;
  }
  v108 = find_heaviest_topapp_top_wts;
  v104 = v15;
  v105 = v14;
  v106 = 0;
  v107 = (unsigned __int8)top_wts_bias;
  v103 = 8 * v17;
  do
  {
    v24 = (__int64)(v23 - 31);
    v25 = v23 - 679;
    if ( v23 - 31 == (__int64 *)&vendor_data_pad )
      v25 = (__int64 *)&init_task;
    if ( (unsigned int)(num_sched_clusters - 1) >= 8 )
      goto LABEL_243;
    v26 = *((_DWORD *)v23 - 54) / (unsigned int)walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(v18[num_sched_clusters - 1]
                     + (((unsigned __int64)*((unsigned int *)v25 + 10) >> 3) & 0x1FFFFFF8)
                     + 24) >> *((_DWORD *)v25 + 10))
        & 1) != 0 )
      v26 = (unsigned __int16)(100 * ((unsigned int)v26 % 0x46)) / 0x46u + 100LL * ((unsigned int)v26 / 0x46);
    if ( have_heavy_list )
      v27 = *((_DWORD *)v23 + 48);
    else
      v27 = 0;
    *((_DWORD *)v23 + 48) = 0;
    v28 = v26 > 0x31 || v27 > 3;
    v29 = *((_DWORD *)v23 + 47) - 1;
    v30 = v29 & ~(v29 >> 31);
    *((_DWORD *)v23 + 47) = v30;
    if ( v28
      || ((v31 = *((_DWORD *)v23 + 29), v29 <= 10) ? (v32 = 10) : (v32 = v29),
          v30 = v32 - 10,
          *((_DWORD *)v23 + 47) = v30,
          v31 != -1) )
    {
      v33 = v26 - least_pipeline_demand;
      v34 = *((unsigned __int8 *)v23 + 184);
      v35 = v33 < 0;
      v36 = v27 & ~(v33 >> 31);
      v37 = v35 ? 5 : 0;
      v38 = v30 + v36;
      v39 = *((_BYTE *)v23 + 184) ? v37 | 0xA : v37;
      v40 = v38 - v39;
      *((_DWORD *)v23 + 47) = v40 & ~(v40 >> 31);
      if ( !v34 || v40 >= 50 && *((_DWORD *)v23 + 29) != -1 )
      {
        if ( v40 >= 251 )
          *((_DWORD *)v23 + 47) = 250;
        if ( !pipeline_special_task || v24 != heavy_wts[0] )
        {
          v41 = v23[16];
          v42 = a1 >= v41;
          v43 = a1 - v41;
          if ( v42
            && v43 >= 0xBEBC200
            && ((unsigned int)cpus_for_pipeline & ~*((_DWORD *)v25 + 348)) == 0
            && *(v23 - 30) >= a1 - (unsigned int)(2 * sched_ravg_window) )
          {
            v44 = walt_scale_demand_divisor;
            v45 = (unsigned int)(num_sched_clusters - 1);
            v46 = v103;
            v102 = (unsigned int)pipeline_swap_util_th;
            do
            {
              if ( v46 == 24 )
                goto LABEL_244;
              v47 = *(__int64 *)((char *)heavy_wts + v46);
              if ( !v47 )
              {
                *(__int64 *)((char *)heavy_wts + v46) = v24;
                break;
              }
              v48 = *(_DWORD *)(v24 + 436);
              v49 = *(_DWORD *)(v47 + 436);
              if ( v48 < v49 )
              {
                v47 = v24;
              }
              else
              {
                if ( (_UNKNOWN *)v47 == &vendor_data_pad )
                  v50 = (unsigned int *)&init_task;
                else
                  v50 = (unsigned int *)(v47 - 5184);
                v51 = v50[10];
                if ( (unsigned int)v45 >= 8 )
                  goto LABEL_243;
                v52 = v18;
                v53 = v18[v45];
                v54 = *(_DWORD *)(v47 + 32) / v44;
                v55 = v53 + 24;
                if ( ((*(_QWORD *)(v53 + 24 + ((v51 >> 3) & 0x1FFFFFF8)) >> v51) & 1) == 0 )
                  v54 = (unsigned __int16)(70 * ((unsigned int)v54 % 0x64)) / 0x64u + 70LL * ((unsigned int)v54 / 0x64);
                v56 = (_DWORD *)(v24 - 5184);
                if ( (_UNKNOWN *)v24 == &vendor_data_pad )
                  v56 = &init_task;
                v57 = *(_DWORD *)(v24 + 32) / v44;
                if ( ((*(_QWORD *)(v55 + (((unsigned __int64)(unsigned int)v56[10] >> 3) & 0x1FFFFFF8)) >> v56[10]) & 1) == 0 )
                  v57 = (unsigned __int16)(70 * ((unsigned int)v57 % 0x64)) / 0x64u + 70LL * ((unsigned int)v57 / 0x64);
                if ( v48 != v49 )
                  goto LABEL_106;
                v58 = v107;
                if ( v46 )
                  v59 = 1;
                else
                  v59 = v108 == 0;
                if ( v59 )
                  v58 = 0;
                if ( v58 != 1 )
                  goto LABEL_105;
                if ( v24 == v108 )
                {
                  v28 = v54 > v57 + v102;
                  v54 = 0;
                  v61 = v28;
                  v106 |= v61;
LABEL_105:
                  if ( v57 <= v54 )
                    v47 = v24;
                  else
LABEL_106:
                    *(__int64 *)((char *)heavy_wts + v46) = v24;
                  v18 = v52;
                  goto LABEL_75;
                }
                if ( v47 != v108 )
                  goto LABEL_105;
                v47 = v24;
                v60 = v57 > v54;
                v18 = v52;
                v106 |= v60;
              }
LABEL_75:
              v46 += 8;
              v24 = v47;
            }
            while ( v46 != 24 );
          }
        }
      }
    }
    v23 = (__int64 *)*v23;
  }
  while ( v23 != (__int64 *)(v4 + 8) );
  v14 = v105;
  v19 = (_DWORD *)heavy_wts[0];
  v15 = v104;
LABEL_110:
  if ( v19 )
  {
    v62 = v19 == (_DWORD *)find_heaviest_topapp_top_wts;
    if ( v19 != (_DWORD *)find_heaviest_topapp_top_wts )
    {
      find_heaviest_topapp_top_wts = (__int64)v19;
      v63 = 1;
      goto LABEL_113;
    }
    v70 = find_heaviest_topapp_top_wts_count;
    if ( (v106 & 1) != 0 )
    {
      --find_heaviest_topapp_top_wts_count;
      if ( v70 == 1 && (top_wts_bias & 1) != 0 )
      {
        v62 = 0;
        goto LABEL_114;
      }
    }
    else
    {
      ++find_heaviest_topapp_top_wts_count;
      if ( v70 + 1 > 4 )
      {
        v63 = 5;
LABEL_113:
        find_heaviest_topapp_top_wts_count = v63;
LABEL_114:
        top_wts_bias = v62;
      }
    }
  }
  v64 = (unsigned int)sysctl_sched_heavy_nr;
  total_util = 0;
  if ( !sysctl_sched_heavy_nr )
  {
    v67 = (unsigned int)(num_sched_clusters - 1);
    if ( v19 )
    {
      v68 = v19 - 1296;
      if ( v19 == (_DWORD *)&vendor_data_pad )
        v68 = &init_task;
      if ( (unsigned int)v67 >= 8 )
        goto LABEL_243;
      v69 = v19[8] / (unsigned int)walt_scale_demand_divisor;
      if ( ((*(_QWORD *)(v18[v67] + (((unsigned __int64)(unsigned int)v68[10] >> 3) & 0x1FFFFFF8) + 24) >> v68[10]) & 1) != 0 )
        v69 = 100 * (v69 / 0x46) + (unsigned __int16)(100 * (v69 % 0x46)) / 0x46u;
      total_util = v69;
    }
    else
    {
      v69 = 0;
    }
    if ( qword_699A8 )
    {
      v71 = (_DWORD *)(qword_699A8 - 5184);
      if ( (_UNKNOWN *)qword_699A8 == &vendor_data_pad )
        v71 = &init_task;
      if ( (unsigned int)v67 > 7 )
        goto LABEL_243;
      v72 = *(_DWORD *)(qword_699A8 + 32) / (unsigned int)walt_scale_demand_divisor;
      if ( ((*(_QWORD *)(v18[v67] + (((unsigned __int64)(unsigned int)v71[10] >> 3) & 0x1FFFFFF8) + 24) >> v71[10]) & 1) != 0 )
        v72 = 100 * (v72 / 0x46) + (unsigned __int16)(100 * (v72 % 0x46)) / 0x46u;
      v69 += v72;
      total_util = v69;
    }
    if ( qword_699B0 )
    {
      v73 = (_DWORD *)(qword_699B0 - 5184);
      if ( (_UNKNOWN *)qword_699B0 == &vendor_data_pad )
        v73 = &init_task;
      if ( (unsigned int)v67 > 7 )
        goto LABEL_243;
      v74 = *(_DWORD *)(qword_699B0 + 32) / (unsigned int)walt_scale_demand_divisor;
      if ( ((*(_QWORD *)(v18[v67] + (((unsigned __int64)(unsigned int)v73[10] >> 3) & 0x1FFFFFF8) + 24) >> v73[10]) & 1) != 0 )
        v74 = 100 * (v74 / 0x46) + (unsigned __int16)(100 * (v74 % 0x46)) / 0x46u;
      v69 += v74;
      total_util = v69;
    }
    v65 = (__int64)v19;
    if ( v69 < sysctl_sched_pipeline_util_thres )
    {
      v65 = (__int64)v19;
      qword_699B0 = 0;
    }
    goto LABEL_154;
  }
  v65 = (__int64)v19;
  if ( sysctl_sched_heavy_nr > 2 )
    goto LABEL_154;
  if ( (unsigned int)sysctl_sched_heavy_nr <= 3 )
    v66 = 3;
  else
    v66 = (unsigned int)sysctl_sched_heavy_nr;
  if ( (unsigned int)sysctl_sched_heavy_nr > 2 )
    goto LABEL_243;
  heavy_wts[sysctl_sched_heavy_nr] = 0;
  if ( (_DWORD)v64 == 2 )
    goto LABEL_125;
  if ( v64 + 1 == v66 )
  {
LABEL_243:
    __break(0x5512u);
    goto LABEL_244;
  }
  if ( (_DWORD)v64 != 1 )
  {
LABEL_244:
    __break(1u);
    JUMPOUT(0x56BF4);
  }
  heavy_wts[v64 + 1] = 0;
LABEL_125:
  v65 = heavy_wts[0];
LABEL_154:
  v75 = sysctl_single_thread_pipeline;
  if ( !v15 )
    goto LABEL_171;
  if ( !v65 )
  {
    v76 = qword_699A8;
    if ( !qword_699A8 )
      goto LABEL_167;
    if ( sysctl_single_thread_pipeline )
    {
      if ( (_DWORD *)v15 != v19 )
        goto LABEL_167;
      if ( v14 )
      {
        v77 = v14 == (_QWORD)v19;
        goto LABEL_176;
      }
      if ( !v16 )
        goto LABEL_209;
      v81 = v16 == (_QWORD)v19;
      v82 = qword_699A8;
      if ( qword_699A8 )
        goto LABEL_192;
      goto LABEL_197;
    }
LABEL_166:
    if ( v15 == v76 )
      goto LABEL_171;
    goto LABEL_167;
  }
  if ( !sysctl_single_thread_pipeline )
  {
    if ( v15 == v65 )
      goto LABEL_171;
    v76 = qword_699A8;
    if ( !qword_699A8 )
      goto LABEL_167;
    goto LABEL_166;
  }
  if ( (_DWORD *)v15 == v19 )
    goto LABEL_171;
LABEL_167:
  if ( !qword_699B0 )
    goto LABEL_170;
  if ( sysctl_single_thread_pipeline )
  {
    if ( (_DWORD *)v15 == v19 )
      goto LABEL_171;
    goto LABEL_170;
  }
  if ( v15 != qword_699B0 )
  {
LABEL_170:
    v78 = *(_BYTE *)(v15 + 191);
    *(_DWORD *)(v15 + 364) = -1;
    *(_BYTE *)(v15 + 191) = v78 & 0xF7;
  }
LABEL_171:
  if ( !v14 )
    goto LABEL_186;
  v77 = v14 == (_QWORD)v19;
  if ( !v65 )
    goto LABEL_176;
  if ( !v75 )
  {
    if ( v14 == v65 )
      goto LABEL_186;
    v79 = qword_699A8;
    if ( qword_699A8 )
      goto LABEL_181;
LABEL_182:
    if ( qword_699B0 )
    {
      if ( v75 )
      {
LABEL_184:
        if ( v77 )
          goto LABEL_186;
        goto LABEL_185;
      }
      if ( v14 == qword_699B0 )
        goto LABEL_186;
    }
LABEL_185:
    v80 = *(_BYTE *)(v14 + 191);
    *(_DWORD *)(v14 + 364) = -1;
    *(_BYTE *)(v14 + 191) = v80 & 0xF7;
    goto LABEL_186;
  }
  if ( (_DWORD *)v14 == v19 )
    goto LABEL_186;
  v77 = 0;
LABEL_176:
  v79 = qword_699A8;
  if ( !qword_699A8 )
    goto LABEL_182;
  if ( v75 )
    goto LABEL_184;
LABEL_181:
  if ( v14 != v79 )
    goto LABEL_182;
LABEL_186:
  if ( !v16 )
    goto LABEL_209;
  v81 = v16 == (_QWORD)v19;
  if ( !v65 )
    goto LABEL_191;
  if ( !v75 )
  {
    if ( v16 == v65 )
      goto LABEL_209;
    v82 = qword_699A8;
    if ( qword_699A8 )
      goto LABEL_196;
    goto LABEL_197;
  }
  if ( (_DWORD *)v16 == v19 )
    goto LABEL_209;
  v81 = 0;
LABEL_191:
  v82 = qword_699A8;
  if ( !qword_699A8 )
  {
LABEL_197:
    if ( !qword_699B0 )
    {
LABEL_208:
      v83 = *(_BYTE *)(v16 + 191);
      *(_DWORD *)(v16 + 364) = -1;
      *(_BYTE *)(v16 + 191) = v83 & 0xF7;
      goto LABEL_209;
    }
    if ( !v75 )
    {
      if ( v16 == qword_699B0 )
        goto LABEL_209;
      goto LABEL_208;
    }
LABEL_199:
    if ( v81 )
      goto LABEL_209;
    goto LABEL_208;
  }
LABEL_192:
  if ( v75 )
    goto LABEL_199;
LABEL_196:
  if ( v16 != v82 )
    goto LABEL_197;
LABEL_209:
  LODWORD(v84) = 0x7FFFFFFF;
  v85 = walt_scale_demand_divisor;
  least_pipeline_demand = 0x7FFFFFFF;
  v86 = (unsigned int)(num_sched_clusters - 1);
  if ( v65 )
  {
    v87 = *(_DWORD *)(v65 + 436) + 3;
    *(_BYTE *)(v65 + 191) |= 8u;
    if ( (_UNKNOWN *)v65 == &vendor_data_pad )
      v88 = &init_task;
    else
      v88 = (_DWORD *)(v65 - 5184);
    *(_DWORD *)(v65 + 436) = v87;
    v89 = *(_DWORD *)(v65 + 32);
    if ( (unsigned int)v86 < 8 )
    {
      v84 = v89 / v85;
      if ( ((*(_QWORD *)(v18[v86] + (((unsigned __int64)(unsigned int)v88[10] >> 3) & 0x1FFFFFF8) + 24) >> v88[10]) & 1) != 0 )
        v84 = (unsigned __int16)(100 * ((unsigned int)v84 % 0x46)) / 0x46u + 100LL * ((unsigned int)v84 / 0x46);
      if ( v84 >> 31 )
        LODWORD(v84) = 0x7FFFFFFF;
      else
        least_pipeline_demand = v84;
      goto LABEL_219;
    }
    goto LABEL_243;
  }
LABEL_219:
  v90 = qword_699A8;
  if ( qword_699A8 )
  {
    v91 = *(_DWORD *)(qword_699A8 + 436) + 3;
    *(_BYTE *)(qword_699A8 + 191) |= 8u;
    if ( (_UNKNOWN *)v90 == &vendor_data_pad )
      v92 = &init_task;
    else
      v92 = (_DWORD *)(v90 - 5184);
    *(_DWORD *)(v90 + 436) = v91;
    v93 = *(_DWORD *)(v90 + 32);
    if ( (unsigned int)v86 > 7 )
      goto LABEL_243;
    v94 = v93 / v85;
    if ( ((*(_QWORD *)(v18[v86] + (((unsigned __int64)(unsigned int)v92[10] >> 3) & 0x1FFFFFF8) + 24) >> v92[10]) & 1) != 0 )
      v94 = (unsigned __int16)(100 * ((unsigned int)v94 % 0x46)) / 0x46u + 100LL * ((unsigned int)v94 / 0x46);
    if ( v94 <= (unsigned int)v84 )
    {
      LODWORD(v84) = v94;
      least_pipeline_demand = v94;
    }
  }
  v95 = qword_699B0;
  if ( qword_699B0 )
  {
    v96 = *(_DWORD *)(qword_699B0 + 436) + 3;
    *(_BYTE *)(qword_699B0 + 191) |= 8u;
    if ( (_UNKNOWN *)v95 == &vendor_data_pad )
      v97 = (unsigned int *)&init_task;
    else
      v97 = (unsigned int *)(v95 - 5184);
    v98 = *(_DWORD *)(v95 + 32);
    *(_DWORD *)(v95 + 436) = v96;
    v99 = v97[10];
    if ( (unsigned int)v86 > 7 )
      goto LABEL_243;
    v100 = v98 / v85;
    if ( ((*(_QWORD *)(v18[v86] + ((v99 >> 3) & 0x1FFFFFF8) + 24) >> v99) & 1) != 0 )
      v100 = (unsigned __int16)(100 * ((unsigned int)v100 % 0x46)) / 0x46u + 100LL * ((unsigned int)v100 / 0x46);
    if ( v100 <= (unsigned int)v84 )
      least_pipeline_demand = v100;
    v101 = 1;
  }
  else
  {
    v101 = v75 != 0;
  }
  ((void (__fastcall *)(_BOOL8, __int64))pipeline_set_unisolation)(v101, 1);
  raw_spin_unlock(&heavy_lock);
  raw_spin_unlock_irqrestore(v4 + 4, v13);
  return 1;
}
