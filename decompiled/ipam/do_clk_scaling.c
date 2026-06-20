__int64 __fastcall do_clk_scaling(__int64 a1)
{
  __int64 v1; // x23
  __int64 v2; // x22
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x1
  __int64 v6; // x0
  __int64 v7; // x9
  unsigned __int64 v8; // x8
  __int64 v9; // x11
  _DWORD *v10; // x16
  __int64 v11; // x15
  int v12; // w16
  __int64 v13; // x9
  int v14; // w19
  unsigned __int64 v15; // x10
  int v16; // w15
  unsigned __int64 v17; // x17
  int v18; // w13
  int v19; // w16
  int v20; // w0
  unsigned __int64 v21; // x15
  int v22; // w17
  unsigned __int64 v23; // x0
  int v24; // w14
  int v25; // w16
  unsigned __int64 v26; // x0
  bool v27; // cc
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  int v32; // w8
  __int64 v33; // x9
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x10
  int v38; // w20
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 result; // x0
  __int64 v42; // x0
  int v43; // w11
  int *v44; // x13
  int v45; // w12
  __int64 v46; // x14
  int v47; // w15
  int v48; // w16
  int *v49; // x9
  __int64 v50; // x8
  int v51; // t1
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w20
  __int64 v56; // x24
  __int64 v57; // x0
  __int64 ipc_logbuf; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int16 v62; // [xsp+4h] [xbp-9Ch]
  char v63; // [xsp+6h] [xbp-9Ah]
  _QWORD v64[19]; // [xsp+8h] [xbp-98h] BYREF

  v64[18] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(ipa3_ctx + 45120) )
  {
    v2 = ipa_pm_ctx;
    v3 = mutex_lock(ipa_pm_ctx + 1152);
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(v3);
    if ( ipc_logbuf_low )
    {
      v6 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_logbuf_low = ipc_log_string(v6, "ipa_pm %s:%d clock scaling started\n", "do_clk_scaling", 370);
    }
    v7 = ipa_pm_ctx;
    v8 = 0;
    v9 = 8;
    memset(v64, 0, 144);
    v63 = 0;
    v62 = 0;
    do
    {
      v10 = *(_DWORD **)(v7 + v9);
      if ( v10 && (unsigned int)(v10[20] - 3) <= 3 )
      {
        v11 = (int)v10[22];
        if ( (_DWORD)v11 )
        {
          if ( (unsigned int)v11 > 2 )
            goto LABEL_106;
          if ( (*((_BYTE *)&v62 + v11) & 1) == 0 )
          {
            if ( v8 > 0x23 )
              goto LABEL_106;
            v12 = *(_DWORD *)(v7 + 1204 + 4 * v11);
            *((_BYTE *)&v62 + v11) = 1;
            *((_DWORD *)v64 + v8++) = v12;
          }
        }
        else
        {
          if ( v8 > 0x23 )
            goto LABEL_106;
          *((_DWORD *)v64 + v8++) = v10[24];
        }
      }
      v9 += 8;
    }
    while ( v9 != 288 );
    if ( (int)v8 >= 2 )
    {
      v13 = 4 * v8;
      v14 = 0;
      v15 = v8 - 2;
      while ( v8 - 1 <= 0x23 )
      {
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19 = v8 - 1;
        do
        {
          if ( v17 > 0x8F )
            goto LABEL_100;
          v20 = *(_DWORD *)((char *)v64 + v17);
          v17 += 4LL;
          if ( v20 > v18 )
          {
            v18 = v20;
            v19 = v16;
          }
          ++v16;
        }
        while ( v13 != v17 );
        if ( v19 == 36 )
          break;
        if ( (unsigned __int64)(4LL * v19) > 0x90 )
          break;
        *((_DWORD *)v64 + v19) = *((_DWORD *)v64 + v8 - 1);
        if ( (unsigned __int64)(unsigned int)(v8 - 1) - 37 < 0xFFFFFFFFFFFFFFDCLL )
          break;
        v21 = v8 - 2;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v13 -= 4;
        v25 = v8 - 2;
        do
        {
          if ( v23 > 0x8F )
            goto LABEL_100;
          v5 = *(unsigned int *)((char *)v64 + v23);
          v23 += 4LL;
          if ( (int)v5 > v24 )
          {
            v24 = v5;
            v25 = v22;
          }
          ++v22;
        }
        while ( v13 != v23 );
        if ( (_DWORD)v8 == 38 )
          break;
        if ( 4 * v21 > 0x90 )
          break;
        if ( v25 == 36 )
          break;
        if ( (unsigned __int64)(4LL * v25) > 0x90 )
          break;
        if ( 4 * v21 > 0x8F )
          break;
        v26 = 4LL * v25;
        if ( v26 > 0x90 )
          break;
        *((_DWORD *)v64 + v25) = *((_DWORD *)v64 + v21);
        if ( v15 > 0x23 )
          goto LABEL_106;
        v27 = v8 > 2;
        v14 += v24;
        --v8;
        *((_DWORD *)v64 + v21) = v18 - v24;
        if ( !v27 )
        {
          v28 = ipa3_get_ipc_logbuf_low(v26);
          if ( v28 )
            goto LABEL_40;
          goto LABEL_41;
        }
      }
LABEL_100:
      __break(1u);
      goto LABEL_101;
    }
    v14 = 0;
    v28 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    if ( v28 )
    {
LABEL_40:
      v29 = ipa3_get_ipc_logbuf_low(v28);
      ipc_log_string(v29, "ipa_pm %s:%d Aggregated throughput: %d\n", "calculate_throughput", 278, v14);
    }
LABEL_41:
    v1 = ipa_pm_ctx;
    v30 = ipa_pm_ctx + 584;
    *(_DWORD *)(ipa_pm_ctx + 1200) = v14;
    v31 = raw_spin_lock_irqsave(v30);
    v32 = *(_DWORD *)(v1 + 1116);
    v5 = v31;
    if ( v32 >= 1 )
    {
      if ( *(_DWORD *)(v1 + 652)
        || (*(_DWORD *)(v1 + 656) & ~*(_DWORD *)(v1 + 1104)) != 0
        || (*(_DWORD *)(v1 + 660) & ~*(_DWORD *)(v1 + 1108)) != 0 )
      {
        if ( v32 == 1 )
          goto LABEL_66;
        if ( *(_DWORD *)(v1 + 748)
          || (*(_DWORD *)(v1 + 752) & ~*(_DWORD *)(v1 + 1104)) != 0
          || (*(_DWORD *)(v1 + 756) & ~*(_DWORD *)(v1 + 1108)) != 0 )
        {
          if ( v32 == 2 )
            goto LABEL_66;
          if ( *(_DWORD *)(v1 + 844)
            || (*(_DWORD *)(v1 + 848) & ~*(_DWORD *)(v1 + 1104)) != 0
            || (*(_DWORD *)(v1 + 852) & ~*(_DWORD *)(v1 + 1108)) != 0 )
          {
            if ( v32 == 3 )
              goto LABEL_66;
            if ( *(_DWORD *)(v1 + 940)
              || (*(_DWORD *)(v1 + 944) & ~*(_DWORD *)(v1 + 1104)) != 0
              || (*(_DWORD *)(v1 + 948) & ~*(_DWORD *)(v1 + 1108)) != 0 )
            {
              if ( v32 == 4 )
                goto LABEL_66;
              if ( *(_DWORD *)(v1 + 1036)
                || (*(_DWORD *)(v1 + 1040) & ~*(_DWORD *)(v1 + 1104)) != 0
                || (*(_DWORD *)(v1 + 1044) & ~*(_DWORD *)(v1 + 1108)) != 0 )
              {
                if ( v32 != 5 )
                {
                  if ( !*(_DWORD *)(v1 + 1132)
                    && (*(_DWORD *)(v1 + 1136) & ~*(_DWORD *)(v1 + 1104)) == 0
                    && (*(_DWORD *)(v1 + 1140) & ~*(_DWORD *)(v1 + 1108)) == 0 )
                  {
LABEL_101:
                    v56 = v1 + 1068;
                    v55 = 5;
                    goto LABEL_102;
                  }
                  if ( v32 != 6 )
LABEL_106:
                    __break(0x5512u);
                }
                goto LABEL_66;
              }
              v56 = v1 + 972;
              v55 = 4;
            }
            else
            {
              v56 = v1 + 876;
              v55 = 3;
            }
          }
          else
          {
            v56 = v1 + 780;
            v55 = 2;
          }
        }
        else
        {
          v56 = v1 + 684;
          v55 = 1;
        }
      }
      else
      {
        v55 = 0;
        v56 = v1 + 588;
      }
LABEL_102:
      v57 = raw_spin_unlock_irqrestore(ipa_pm_ctx + 584, v5);
      *(_QWORD *)(v1 + 1144) = v56 + 76;
      ipc_logbuf = ipa3_get_ipc_logbuf(v57);
      if ( ipc_logbuf )
      {
        v59 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(v59, "ipa_pm %s:%d Exception %d set\n", "set_current_threshold", 343, v55);
      }
      v60 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v60 )
      {
        v61 = ipa3_get_ipc_logbuf_low(v60);
        ipc_log_string(v61, "ipa_pm %s:%d Exception %d set\n", "set_current_threshold", 343, v55);
      }
LABEL_67:
      v34 = mutex_unlock(ipa_pm_ctx + 1152);
      v35 = *(unsigned int *)(v2 + 1112);
      if ( (int)v35 < 1 )
      {
        v38 = 1;
      }
      else
      {
        v36 = *(_QWORD *)(v2 + 1144);
        if ( (_DWORD)v35 == 1 )
        {
          v37 = 0;
          v38 = 1;
        }
        else
        {
          v37 = v35 & 0x7FFFFFFE;
          v43 = 0;
          v44 = (int *)(v36 + 4);
          v45 = 1;
          v46 = v37;
          do
          {
            v47 = *(v44 - 1);
            v48 = *v44;
            v44 += 2;
            if ( v14 >= v47 )
              ++v45;
            if ( v14 >= v48 )
              ++v43;
            v46 -= 2;
          }
          while ( v46 );
          v38 = v43 + v45;
          if ( v37 == v35 )
            goto LABEL_88;
        }
        v49 = (int *)(v36 + 4 * v37);
        v50 = v35 - v37;
        do
        {
          v51 = *v49++;
          if ( v14 >= v51 )
            ++v38;
          --v50;
        }
        while ( v50 );
      }
LABEL_88:
      v52 = ipa3_get_ipc_logbuf_low(v34);
      if ( v52 )
      {
        v53 = ipa3_get_ipc_logbuf_low(v52);
        v52 = ipc_log_string(
                v53,
                "ipa_pm %s:%d old idx was at %d\n",
                "do_clk_scaling",
                382,
                *(_DWORD *)(ipa_pm_ctx + 1120));
      }
      if ( *(_DWORD *)(ipa_pm_ctx + 1120) != v38 )
      {
        *(_DWORD *)(ipa_pm_ctx + 1120) = v38;
        v52 = ipa3_set_clock_plan_from_pm(v38);
      }
      result = ipa3_get_ipc_logbuf_low(v52);
      if ( result )
      {
        v54 = ipa3_get_ipc_logbuf_low(result);
        result = ipc_log_string(
                   v54,
                   "ipa_pm %s:%d new idx is at %d\n",
                   "do_clk_scaling",
                   390,
                   *(_DWORD *)(ipa_pm_ctx + 1120));
      }
      goto LABEL_94;
    }
LABEL_66:
    v33 = ipa_pm_ctx;
    *(_QWORD *)(v1 + 1144) = v1 + 1124;
    raw_spin_unlock_irqrestore(v33 + 584, v31);
    goto LABEL_67;
  }
  v39 = ipa3_get_ipc_logbuf(a1);
  if ( v39 )
  {
    v40 = ipa3_get_ipc_logbuf(v39);
    v39 = ipc_log_string(v40, "ipa_pm %s:%d IPA clock is gated\n", "do_clk_scaling", 363);
  }
  result = ipa3_get_ipc_logbuf_low(v39);
  if ( result )
  {
    v42 = ipa3_get_ipc_logbuf_low(result);
    result = ipc_log_string(v42, "ipa_pm %s:%d IPA clock is gated\n", "do_clk_scaling", 363);
  }
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return result;
}
