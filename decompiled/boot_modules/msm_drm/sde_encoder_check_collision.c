__int64 __fastcall sde_encoder_check_collision(
        __int64 *a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x23
  void (__fastcall *v11)(__int64, unsigned int *); // x8
  unsigned __int64 v13; // x20
  __int64 v14; // x21
  int v15; // w6
  int v16; // w7
  unsigned int v17; // w27
  unsigned int v18; // w8
  __int64 v19; // x22
  unsigned int v21; // w19
  char v23; // [xsp+0h] [xbp-20h]
  char v24; // [xsp+0h] [xbp-20h]
  unsigned int v25; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a1;
  v25 = 0;
  if ( a1 && v8 && (v9 = a1[1]) != 0 && *(_QWORD *)(v9 + 2512) )
  {
    v10 = a1[301];
    if ( v10 )
    {
      v11 = (void (__fastcall *)(__int64, unsigned int *))a1[50];
      v13 = a1[298];
      if ( *((_DWORD *)v11 - 1) != 1659771273 )
        __break(0x8228u);
      v11(v8, &v25);
      v14 = (unsigned int)(1000 * *(_DWORD *)(v8 + 4740));
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_check_collision",
        6181,
        -1,
        v13,
        a2,
        v14,
        *(_DWORD *)(v10 + 8),
        239);
      if ( v13 >= a2 - 500000 )
      {
LABEL_18:
        v21 = 0;
      }
      else
      {
        v17 = 0;
        while ( 1 )
        {
          v18 = v17 >= *(_DWORD *)(v10 + 8)
              ? 0x3B9ACA00 / v25
              : 1000 * (0x3B9ACA00u / *(_DWORD *)(*(_QWORD *)v10 + 4LL * (int)v17));
          v19 = v18;
          sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_check_collision", 6188, -1, v18, 0, -1059143953, v16, v24);
          v13 += v19;
          if ( v13 + 500000 < a2 && v14 - 500000 + v13 > a2 )
            break;
          ++v17;
          if ( v13 >= a2 - 500000 )
            goto LABEL_18;
        }
        v21 = 1;
      }
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_check_collision", 6200, -1, v21, -1059143953, v15, v16, v24);
    }
    else
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "curr_freq_pattern is not valid\n");
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_check_collision", 6172, -1, 60333, -1059143953, a7, a8, v23);
      v21 = 0;
    }
  }
  else
  {
    printk(&unk_2382FD, "sde_encoder_check_collision");
    v21 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
