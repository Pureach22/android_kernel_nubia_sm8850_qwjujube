__int64 __fastcall wlan_dp_spm_flow_retire(__int64 a1, char a2)
{
  __int64 context; // x19
  __int64 i; // x25
  __int64 v6; // x8
  __int64 v7; // x23
  __int64 v8; // x26
  __int64 v9; // x0
  unsigned __int64 v10; // x24
  unsigned __int64 v11; // x28
  __int64 v12; // x22
  __int64 v13; // x1
  unsigned __int64 v14; // x0
  int v15; // w8
  unsigned int v16; // w28
  __int64 v17; // x8
  __int64 v18; // x22
  __int64 v19; // x9
  __int64 v20; // x24
  char v21; // w8
  __int64 v22; // x8
  _QWORD *v23; // x9
  int v24; // w9
  unsigned __int64 v26; // x9
  __int64 *v27; // x11
  unsigned int v28; // w9
  __int64 v29; // x11
  unsigned int v30; // w12
  __int64 v31; // x13
  unsigned __int16 v32; // w0
  __int16 v33; // w0
  __int16 v34; // w0
  __int16 v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 v49; // x9
  __int64 result; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x21
  unsigned __int16 v60; // [xsp+Ch] [xbp-124h]
  unsigned __int16 v61; // [xsp+Ch] [xbp-124h]
  unsigned __int16 v62; // [xsp+Ch] [xbp-124h]
  __int64 v63; // [xsp+10h] [xbp-120h]
  unsigned int v64; // [xsp+1Ch] [xbp-114h]
  _QWORD v65[34]; // [xsp+20h] [xbp-110h] BYREF

  v65[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = dp_get_context();
  qdf_spinlock_acquire(context + 2984);
  for ( i = 0; i != 64; ++i )
  {
    v6 = *(_QWORD *)(a1 + 8 * i);
    if ( v6 )
    {
      v7 = v6 - 16;
      if ( v6 != 16 )
      {
        while ( 1 )
        {
          v8 = *(_QWORD *)(v7 + 16);
          v9 = dp_get_context();
          v10 = *(_QWORD *)(v7 + 136);
          v11 = *(_QWORD *)(v7 + 144);
          v12 = v9;
          v14 = sched_clock(v9, v13);
          if ( !*(_BYTE *)(v7 + 51) && v14 >= v11 && v14 >= v10 )
          {
            v15 = *(unsigned __int8 *)(v7 + 163);
            _ZF = *(_BYTE *)(v7 + 162) || v15 == 2;
            if ( !_ZF || v14 - v11 >= *(_QWORD *)(v7 + 176) )
            {
              v26 = v14 - *(_QWORD *)(v7 + 144);
              if ( v26 >= 0x3B9ACA00 )
                break;
            }
          }
          if ( (a2 & 1) != 0 )
          {
            v15 = *(unsigned __int8 *)(v7 + 163);
            v16 = 0;
            goto LABEL_8;
          }
LABEL_16:
          if ( v8 )
          {
            v7 = v8 - 16;
            if ( v8 != 16 )
              continue;
          }
          goto LABEL_2;
        }
        if ( v14 - *(_QWORD *)(v7 + 136) < 0x12A05F201LL || *(_QWORD *)(v7 + 152) >= 0xAu )
        {
          if ( v26 <= 0x4A817C7FFLL
            && (v27 = *(__int64 **)(v12 + 1480), v28 = *((unsigned __int16 *)v27 + 16), *((_WORD *)v27 + 16)) )
          {
            v29 = *v27;
            v30 = 0;
            while ( 1 )
            {
              v31 = v29 + 336LL * (unsigned __int8)v30;
              if ( *(_BYTE *)(v31 + 40) )
              {
                if ( *(_QWORD *)(v31 + 136) == *(_DWORD *)(v7 + 168) )
                  break;
              }
              ++v30;
              v16 = 1;
              if ( v30 >= v28 )
                goto LABEL_8;
            }
            v16 = v31 == 0;
            if ( v31 && (a2 & 1) == 0 )
              goto LABEL_16;
          }
          else
          {
            v16 = 1;
          }
        }
        else
        {
          v16 = 2;
        }
LABEL_8:
        if ( v15 == 2 )
        {
          v17 = *(_QWORD *)(context + 2936);
          if ( v17 )
          {
            v18 = *(unsigned __int8 *)(v7 + 160);
            v19 = *(_QWORD *)(v17 + 6424) + (v18 << 7);
            v20 = v19 + 8;
            v21 = *(_BYTE *)(v17 + 148);
            memset(v65, 0, 256);
            if ( (v21 & 8) != 0 )
            {
              v64 = *(_DWORD *)(v19 + 100);
              v63 = *(_QWORD *)(v19 + 80);
              scnprintf(v65, 256, "0x%x", *(_DWORD *)(v19 + 28));
              v60 = v32;
              scnprintf((char *)v65 + v32, 256 - v32, " 0x%x", *(_DWORD *)(v20 + 36));
              v61 = v33 + v60;
              scnprintf((char *)v65 + v61, 256 - v61, " %u", *(unsigned __int16 *)(v20 + 52));
              v62 = v34 + v61;
              scnprintf((char *)v65 + v62, 256 - v62, " %u", *(unsigned __int16 *)(v20 + 54));
              v36 = scnprintf(
                      (char *)v65 + (unsigned __int16)(v35 + v62),
                      256 - (unsigned __int16)(v35 + v62),
                      " %u",
                      *(unsigned __int8 *)(v20 + 56));
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: STC: c_state: [%u], c_flags: [%lu], Remove TX flow [%u] reason:[%u], tuple: %s",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "wlan_dp_stc_tx_flow_retire_ind",
                v64,
                v63,
                (unsigned int)v18,
                v16,
                v65);
              if ( *(_DWORD *)(v20 + 92) )
              {
LABEL_12:
                if ( (*(_QWORD *)(v20 + 72) & 1) != 0 )
                {
                  _X8 = (unsigned __int64 *)(v20 + 80);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v49 = __ldxr(_X8);
                  while ( __stxr(v49 | 1, _X8) );
                }
              }
            }
            else if ( *(_DWORD *)(v19 + 100) )
            {
              goto LABEL_12;
            }
          }
        }
        v22 = *(_QWORD *)(v7 + 16);
        v23 = *(_QWORD **)(v7 + 24);
        *v23 = v22;
        if ( v22 )
          *(_QWORD *)(v22 + 8) = v23;
        *(_QWORD *)(v7 + 24) = 0xDEAD000000000122LL;
        call_rcu(v7 + 32, dp_spm_add_flow_to_freelist);
        v24 = *(_DWORD *)(a1 + 520) + 1;
        --*(_DWORD *)(a1 + 516);
        *(_DWORD *)(a1 + 520) = v24;
        goto LABEL_16;
      }
    }
LABEL_2:
    ;
  }
  result = qdf_spinlock_release(context + 2984);
  v59 = jiffies;
  if ( wlan_dp_spm_flow_retire___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: post retire count: %u",
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               "wlan_dp_spm_flow_retire",
               *(unsigned int *)(context + 2976));
    wlan_dp_spm_flow_retire___last_ticks = v59;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
