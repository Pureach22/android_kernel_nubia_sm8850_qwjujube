__int64 __fastcall sde_encoder_delay_kickoff_processing(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x23
  __int64 v3; // x25
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x21
  int v7; // w19
  __int64 (__fastcall *v8)(_QWORD); // x9
  __int64 v9; // x20
  unsigned int v10; // w3
  unsigned int v11; // w8
  __int64 v12; // x19
  void *v13; // x0
  unsigned int v14; // w26
  int v15; // w9
  unsigned int v16; // w20
  _BOOL4 v17; // w28
  _BOOL4 v18; // w8
  int v19; // w4
  unsigned __int64 v20; // x22
  __int64 v21; // x27
  __int64 v22; // x23
  unsigned __int64 v23; // x24
  unsigned __int64 v24; // x9
  int v25; // w0
  int v26; // w4
  int v27; // w4
  __int64 v28; // x25
  signed __int64 v29; // kr00_8
  __int64 v30; // x24
  int v31; // w2
  int v32; // w5
  int v33; // w6
  int v34; // w7
  char v35; // [xsp+0h] [xbp-90h]
  char s[8]; // [xsp+48h] [xbp-48h] BYREF
  __int64 v37; // [xsp+50h] [xbp-40h]
  __int64 v38; // [xsp+58h] [xbp-38h]
  __int64 v39; // [xsp+60h] [xbp-30h]
  __int64 v40; // [xsp+68h] [xbp-28h]
  __int64 v41; // [xsp+70h] [xbp-20h]
  __int64 v42; // [xsp+78h] [xbp-18h]
  __int64 v43; // [xsp+80h] [xbp-10h]
  __int64 v44; // [xsp+88h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  *(_QWORD *)s = 0;
  v37 = 0;
  if ( !result || !*(_QWORD *)result )
  {
    v12 = result;
    v13 = &unk_26FCAB;
    goto LABEL_24;
  }
  v1 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    v12 = result;
    v13 = &unk_234896;
LABEL_24:
    printk(v13, "sde_encoder_get_kms");
    result = v12;
    v2 = 0;
    v3 = *(_QWORD *)(v12 + 328);
    if ( !v3 )
      goto LABEL_81;
    goto LABEL_6;
  }
  v3 = *(_QWORD *)(result + 328);
  if ( !v3 )
    goto LABEL_81;
LABEL_6:
  if ( !v2 )
    goto LABEL_81;
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
    goto LABEL_81;
  v5 = *(_QWORD *)(v4 + 2512);
  if ( !v5 )
    goto LABEL_81;
  v6 = *(_QWORD *)(v5 + 1664);
  if ( !v6 )
    goto LABEL_81;
  v7 = *(_DWORD *)(v5 + 1536);
  if ( !v7 && (*(_BYTE *)(result + 751) & 1) == 0 && *(_BYTE *)(result + 749) != 1 )
  {
    if ( result )
      goto LABEL_27;
LABEL_62:
    v30 = result;
    printk(&unk_26FCAB, "sde_encoder_get_fps");
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    result = v30;
    v17 = 0;
    v14 = 0;
    v16 = 0;
    v18 = 0;
    goto LABEL_32;
  }
  if ( !result )
  {
    printk(&unk_246014, "_sde_encoder_get_qsync_fps_callback");
    result = 0;
    goto LABEL_62;
  }
  v8 = *(__int64 (__fastcall **)(_QWORD))(v4 + 3184);
  if ( v8 )
  {
    v9 = result;
    if ( *((_DWORD *)v8 - 1) != 1917458973 )
      __break(0x8229u);
    v10 = v8(v5);
    if ( (v10 & 0x80000000) != 0 )
    {
      printk(&unk_26211F, "_sde_encoder_get_qsync_fps_callback");
      v11 = 10;
    }
    else if ( v10 )
    {
      v11 = v10;
    }
    else
    {
      v11 = 10;
    }
    result = v9;
    goto LABEL_28;
  }
LABEL_27:
  v11 = 10;
LABEL_28:
  v14 = *(_DWORD *)(result + 3944);
  v15 = *(_DWORD *)(result + 648);
  if ( v11 >= v14 )
    v16 = *(_DWORD *)(result + 3944);
  else
    v16 = v11;
  v17 = v15 == 2;
  v18 = v15 == 1;
LABEL_32:
  if ( (*(_QWORD *)(*(_QWORD *)(v2 + 152) + 22008LL) & 0x2000000000LL) == 0 || !v7 || !v17 )
  {
    v20 = *(unsigned int *)(result + 4812);
    if ( !*(_DWORD *)(result + 4812) )
      v18 = 0;
    if ( v18 )
    {
      if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 328) + 424LL) + 40LL) + 32LL) & 0x100000) != 0 )
        goto LABEL_81;
      v21 = result;
      v22 = ktime_get(result);
    }
    else
    {
      v21 = result;
      v22 = ktime_get(result);
      if ( !(_DWORD)v20 )
      {
        v23 = v6 - 3000000;
LABEL_48:
        v24 = v23 - v22;
        if ( (__int64)v23 <= v22 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            if ( v21 )
            {
              v27 = *(_DWORD *)(v21 + 24);
              v28 = v21;
            }
            else
            {
              v28 = 0;
              v27 = -1;
            }
            _drm_dev_dbg(0, 0, 0, "enc:%d, ept elapsed; ept:%llu, ept_ts:%llu, current_ts:%llu\n", v27, v6, v23, v22);
            v21 = v28;
          }
          v25 = sde_dbg_base_evtlog;
          if ( v21 )
            v26 = *(_DWORD *)(v21 + 24);
          else
            v26 = -1;
          v31 = 6942;
          v32 = v7;
          v33 = v20;
          v35 = v14;
        }
        else
        {
          if ( (unsigned int)v20 | v7 || v23 >= *(_QWORD *)(v3 + 864) + ((unsigned __int64)v14 + 999999999) / v14 )
          {
            v29 = v24 + 999;
            if ( (unsigned __int64)((__int64)(v24 + 999) / 1000) < 0x989681 )
            {
              snprintf(s, 0x40u, "schedule_timeout_%llu", v6);
              _ReadStatusReg(SP_EL0);
              trace_tracing_mark_write();
              usleep_range_state(v29 / 1000 - 1000, v29 / 1000, 2);
              trace_tracing_mark_write();
              v25 = sde_dbg_base_evtlog;
              if ( v21 )
                v26 = *(_DWORD *)(v21 + 24);
              else
                v26 = -1;
              v31 = 6974;
              v35 = v14;
            }
            else
            {
              if ( (unsigned int)__ratelimit(
                                   &sde_encoder_delay_kickoff_processing__rs,
                                   "_sde_encoder_delay_kickoff_processing") )
                printk(&unk_256E6A, "_sde_encoder_delay_kickoff_processing");
              v25 = sde_dbg_base_evtlog;
              if ( v21 )
                v26 = *(_DWORD *)(v21 + 24);
              else
                v26 = -1;
              v35 = v14;
              v31 = 6964;
            }
            v32 = v7;
            v33 = v20;
            v34 = v16;
            goto LABEL_80;
          }
          v25 = sde_dbg_base_evtlog;
          if ( v21 )
            v26 = *(_DWORD *)(v21 + 24);
          else
            v26 = -1;
          v32 = 0;
          v33 = 0;
          v35 = v14;
          v31 = 6951;
        }
        v34 = v16;
LABEL_80:
        result = sde_evtlog_log(v25, "_sde_encoder_delay_kickoff_processing", v31, -1, v26, v32, v33, v34, v35);
        goto LABEL_81;
      }
    }
    v23 = v6 - (v20 + 999999999) / v20 + 1000000;
    goto LABEL_48;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( result )
      v19 = *(_DWORD *)(result + 24);
    else
      v19 = -1;
    result = _drm_dev_dbg(0, 0, 0, "enc:%d, ept:%llu not applicable for cmd mode with qsync enabled", v19, v6);
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
