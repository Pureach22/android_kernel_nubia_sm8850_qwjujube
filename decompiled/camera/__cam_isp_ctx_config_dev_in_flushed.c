__int64 __fastcall _cam_isp_ctx_config_dev_in_flushed(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v5; // x0
  char v6; // w8
  __int64 v7; // x6
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  int v10; // w9
  int v11; // w10
  int v12; // w6
  int v13; // w7
  unsigned int v14; // w19
  const char *v15; // x6
  _DWORD v16[2]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v17; // [xsp+18h] [xbp-38h]
  int v18; // [xsp+20h] [xbp-30h]
  int v19; // [xsp+24h] [xbp-2Ch]
  __int64 v20; // [xsp+28h] [xbp-28h]
  __int64 v21; // [xsp+30h] [xbp-20h]
  __int64 v22; // [xsp+38h] [xbp-18h]
  __int64 v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256) + 45056LL;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 256) + 45740LL) & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_config_dev_in_flushed",
      9248,
      "HW is not acquired, reject packet, ctx_id %u link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    result = 4294967274LL;
    goto LABEL_11;
  }
  result = _cam_isp_ctx_config_dev_in_top_state(a1, a2);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(v2 + 685) & 1) != 0 )
    {
      v5 = a1;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        if ( *(_BYTE *)(v2 + 682) )
          v15 = "Y";
        else
          v15 = "N";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_config_dev_in_flushed",
          9267,
          "vfps_ctx:%s resume_hw_in_flushed:%d ctx:%u link: 0x%x",
          v15,
          *(unsigned __int8 *)(v2 + 683),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        v5 = a1;
      }
      if ( *(_BYTE *)(v2 + 682) == 1 )
      {
        if ( *(_BYTE *)(v2 + 683) != 1 )
        {
          result = 0;
          goto LABEL_11;
        }
        v6 = *(_BYTE *)(v2 + 697);
        *(_BYTE *)(v2 + 683) = 0;
        if ( (v6 & 1) == 0 )
          goto LABEL_26;
LABEL_20:
        v8 = *(_QWORD *)(v5 + 216);
        if ( v8 )
        {
          v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 40);
          if ( v9 )
          {
            v11 = *(_DWORD *)(v5 + 60);
            v10 = *(_DWORD *)(v5 + 64);
            v22 = 0;
            v23 = 0;
            v20 = 0;
            v21 = 0;
            v16[0] = v10;
            v16[1] = v11;
            v17 = 0;
            v19 = 0;
            v18 = 2;
            if ( *((_DWORD *)v9 - 1) != 1498387893 )
              __break(0x8228u);
            result = v9(v16);
            if ( (_DWORD)result )
            {
              v12 = *(_DWORD *)(a1 + 32);
              v13 = *(_DWORD *)(a1 + 64);
              v14 = result;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_config_dev_in_flushed",
                9296,
                "Failed at notifying for synced resume on ctx: %u link: 0x%x",
                v12,
                v13);
              result = v14;
            }
            goto LABEL_11;
          }
        }
LABEL_26:
        result = _cam_isp_ctx_issue_resume_util(v5);
        goto LABEL_11;
      }
      if ( *(_BYTE *)(v2 + 697) != 1 || (v7 = *(unsigned int *)(v2 + 644), (unsigned int)v7 > 1) )
      {
        if ( !*(_BYTE *)(v2 + 697) )
          goto LABEL_26;
        goto LABEL_20;
      }
      result = 0;
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_11;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _DWORD, _DWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_config_dev_in_flushed",
        9280,
        "Received %u number of INIT packets, expecting %u to resume on ctx: %u link: 0x%x",
        v7,
        2,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_config_dev_in_flushed",
        9260,
        "Received update pckt in flushed state, skip start, ctx %u link: 0x%x",
        *(unsigned int *)(a1 + 32),
        *(unsigned int *)(a1 + 64));
    }
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
