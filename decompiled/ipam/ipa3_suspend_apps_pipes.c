__int64 __fastcall ipa3_suspend_apps_pipes(unsigned __int8 a1)
{
  _BYTE *v2; // x8
  _BYTE *v3; // x8
  unsigned int v4; // w20
  _BYTE *v5; // x8
  _BYTE *v6; // x8
  int v7; // w0
  _BYTE *v8; // x8
  char v9; // w21
  unsigned int v10; // w20
  unsigned int v11; // w9
  unsigned int ep_mapping; // w0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int reg_n; // w0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  char v24; // w20
  _QWORD v26[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v27; // [xsp+18h] [xbp-18h] BYREF
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  if ( (a1 & 1) != 0 )
  {
    v2 = (_BYTE *)ipa3_ctx;
    if ( (*(_BYTE *)ipa3_ctx & 1) == 0 )
    {
      if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
      {
        BYTE2(v26[0]) = 0;
        LOWORD(v26[0]) = 0;
        ipahal_read_reg_n_fields(163, 0, v26);
        BYTE2(v26[0]) = 1;
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
        v2 = (_BYTE *)ipa3_ctx;
      }
      *v2 = 1;
    }
    ipa3_force_close_coal(1, 1);
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64))ipa_suspend_resume_pipe)(95, 1) == -11 )
    {
      v3 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)ipa3_ctx == 1 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
        {
          BYTE2(v26[0]) = 0;
          LOWORD(v26[0]) = 0;
          ipahal_read_reg_n_fields(163, 0, v26);
          BYTE2(v26[0]) = 0;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
          v3 = (_BYTE *)ipa3_ctx;
        }
        *v3 = 0;
      }
      goto LABEL_14;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64))ipa_suspend_resume_pipe)(35, 1) == -11 )
    {
      v5 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)ipa3_ctx == 1 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
        {
          BYTE2(v26[0]) = 0;
          LOWORD(v26[0]) = 0;
          ipahal_read_reg_n_fields(163, 0, v26);
          BYTE2(v26[0]) = 0;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
          v5 = (_BYTE *)ipa3_ctx;
        }
        *v5 = 0;
        v4 = -11;
        goto LABEL_101;
      }
      goto LABEL_22;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64))ipa_suspend_resume_pipe)(127, 1) == -11 )
    {
      v6 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)ipa3_ctx == 1 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
        {
          BYTE2(v26[0]) = 0;
          LOWORD(v26[0]) = 0;
          ipahal_read_reg_n_fields(163, 0, v26);
          BYTE2(v26[0]) = 0;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
          v6 = (_BYTE *)ipa3_ctx;
        }
        *v6 = 0;
        v4 = -11;
        goto LABEL_100;
      }
      goto LABEL_30;
    }
    v7 = ((__int64 (__fastcall *)(__int64, __int64))ipa_suspend_resume_pipe)(33, 1);
    v8 = (_BYTE *)ipa3_ctx;
    if ( v7 == -11 )
    {
      if ( *(_BYTE *)ipa3_ctx )
      {
        if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
        {
          BYTE2(v26[0]) = 0;
          LOWORD(v26[0]) = 0;
          ipahal_read_reg_n_fields(163, 0, v26);
          BYTE2(v26[0]) = 0;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
          v8 = (_BYTE *)ipa3_ctx;
        }
        *v8 = 0;
        v4 = -11;
        goto LABEL_99;
      }
      goto LABEL_38;
    }
    if ( *(_BYTE *)ipa3_ctx )
    {
      if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
      {
        BYTE2(v26[0]) = 0;
        LOWORD(v26[0]) = 0;
        ipahal_read_reg_n_fields(163, 0, v26);
        BYTE2(v26[0]) = 0;
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(163, 0, v26);
        v8 = (_BYTE *)ipa3_ctx;
      }
      *v8 = 0;
    }
    goto LABEL_44;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(95, 0) != -11 )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(35, 0) == -11 )
    {
LABEL_22:
      v4 = -11;
LABEL_101:
      ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(95, (a1 & 1) == 0);
      ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(35, (a1 & 1) == 0);
      goto LABEL_102;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(127, 0) == -11 )
    {
LABEL_30:
      v4 = -11;
LABEL_100:
      ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(127, (a1 & 1) == 0);
      goto LABEL_101;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(33, 0) == -11 )
    {
LABEL_38:
      v4 = -11;
LABEL_99:
      ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(33, (a1 & 1) == 0);
      goto LABEL_100;
    }
LABEL_44:
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(83, a1 & 1) == -11 )
    {
      v9 = a1 ^ 1;
      v4 = -11;
LABEL_98:
      ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(83, v9 & 1);
      goto LABEL_99;
    }
    if ( *(unsigned __int8 *)(ipa3_ctx + 32244) < 0x18uLL )
    {
      if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4316] == 1 )
      {
        v10 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4336];
        if ( (v10 & 0x80000000) == 0 )
        {
          v11 = *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u ? 31 : 36;
          if ( v10 < v11 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 480LL * v10 + 168) )
            {
              v27 = 0;
              LODWORD(v28) = 0;
              HIDWORD(v28) = (a1 & 1) == 0;
              ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(52, v10, &v27);
              if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
              {
                if ( WORD2(v28) )
                  ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(52, v10, &v27);
              }
            }
          }
        }
      }
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(105, a1 & 1) == -11 )
      {
        v4 = -11;
LABEL_97:
        v9 = a1 ^ 1;
        ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(105, (a1 ^ 1) & 1);
        goto LABEL_98;
      }
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(121, a1 & 1) == -11 )
        goto LABEL_95;
      if ( (a1 & 1) == 0 )
        goto LABEL_84;
      memset(v26, 0, 15);
      ep_mapping = ipa_get_ep_mapping(95);
      if ( ep_mapping == -1 )
        goto LABEL_84;
      if ( ep_mapping <= 0x23 )
      {
        if ( *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 168) )
        {
          ipahal_read_reg_n_fields(17, 0, v26);
          if ( BYTE6(v26[1]) )
          {
            v13 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v14 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v14 )
              {
                ipc_log_string(
                  v14,
                  "ipa %s:%d COAL frame is open 0x%x\n",
                  "ipa3_suspend_apps_pipes",
                  12907,
                  BYTE6(v26[1]));
                v13 = ipa3_ctx;
              }
              v15 = *(_QWORD *)(v13 + 34160);
              if ( v15 )
                ipc_log_string(
                  v15,
                  "ipa %s:%d COAL frame is open 0x%x\n",
                  "ipa3_suspend_apps_pipes",
                  12907,
                  BYTE6(v26[1]));
            }
LABEL_95:
            v4 = -11;
LABEL_96:
            ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(121, (a1 & 1) == 0);
            goto LABEL_97;
          }
          usleep_range_state(1000, 2000, 2);
          v16 = *(unsigned int *)(ipa3_ctx + 43304);
          if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
          {
            reg_n = ipahal_read_reg_n(4, (unsigned int)v16);
            if ( reg_n )
            {
              v21 = ipa3_ctx;
              v4 = reg_n;
              if ( ipa3_ctx )
              {
                v22 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v22 )
                {
                  ipc_log_string(v22, "ipa %s:%d suspend irq is pending 0x%x\n", "ipa3_suspend_apps_pipes", 12929, v4);
                  v21 = ipa3_ctx;
                }
                v23 = *(_QWORD *)(v21 + 34160);
                if ( v23 )
                  ipc_log_string(v23, "ipa %s:%d suspend irq is pending 0x%x\n", "ipa3_suspend_apps_pipes", 12929, v4);
              }
              goto LABEL_97;
            }
          }
          else
          {
            v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipahal_read_reg_mn)(135, 0, v16);
            if ( v4
              || (v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))ipahal_read_reg_mn)(
                         135,
                         1,
                         *(unsigned int *)(ipa3_ctx + 43304))) != 0 )
            {
              v17 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v18 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v18 )
                {
                  ipc_log_string(v18, "ipa %s:%d suspend irq is pending 0x%x\n", "ipa3_suspend_apps_pipes", 12921, v4);
                  v17 = ipa3_ctx;
                }
                v19 = *(_QWORD *)(v17 + 34160);
                if ( v19 )
                  ipc_log_string(v19, "ipa %s:%d suspend irq is pending 0x%x\n", "ipa3_suspend_apps_pipes", 12921, v4);
              }
              goto LABEL_96;
            }
          }
        }
LABEL_84:
        if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(32, a1 & 1) == -11 )
        {
          v24 = a1 ^ 1;
        }
        else
        {
          if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(104, a1 & 1) == -11 )
          {
            v24 = a1 ^ 1;
          }
          else
          {
            if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(120, a1 & 1) == -11 )
            {
              v24 = a1 ^ 1;
            }
            else
            {
              if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(34, a1 & 1) != -11 )
              {
                v4 = 0;
                goto LABEL_102;
              }
              v24 = a1 ^ 1;
              ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(34, (a1 ^ 1) & 1);
            }
            ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(120, v24 & 1);
          }
          ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(104, v24 & 1);
        }
        ((void (__fastcall *)(__int64, _QWORD))ipa_suspend_resume_pipe)(32, v24 & 1);
        goto LABEL_95;
      }
    }
    __break(0x5512u);
    JUMPOUT(0x12D538);
  }
LABEL_14:
  ((void (__fastcall *)(__int64, bool))ipa_suspend_resume_pipe)(95, (a1 & 1) == 0);
  v4 = -11;
LABEL_102:
  _ReadStatusReg(SP_EL0);
  return v4;
}
