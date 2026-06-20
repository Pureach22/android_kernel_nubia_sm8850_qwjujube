__int64 __fastcall cam_ife_hw_mgr_find_affected_ctx(__int64 a1, unsigned int a2, _DWORD *a3, char a4)
{
  __int64 v5; // x23
  __int64 v6; // x0
  unsigned int v7; // w26
  unsigned int v8; // w8
  int v9; // w9
  _BOOL4 v10; // w24
  unsigned __int64 v11; // x8
  unsigned int v12; // w9
  _DWORD *v13; // x10
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  __int64 v19; // x10
  __int64 v20; // x10
  __int64 v21; // x10
  __int64 v22; // x10
  __int64 v23; // x10
  __int64 v24; // x10
  unsigned __int64 v25; // x8
  __int64 v26; // x8
  _DWORD *v27; // x24
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 result; // x0
  _DWORD *v31; // [xsp+0h] [xbp-60h]
  __int64 v34; // [xsp+18h] [xbp-48h]
  __int64 v35; // [xsp+20h] [xbp-40h]
  __int64 v36; // [xsp+28h] [xbp-38h]
  __int64 v37; // [xsp+30h] [xbp-30h]
  _QWORD v38[5]; // [xsp+38h] [xbp-28h] BYREF

  v38[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( a3 )
  {
    a3[26] = 0;
    if ( a2 >= 8 )
      goto LABEL_128;
    v5 = qword_394A78;
    *((_DWORD *)&v34 + a2) = 1;
    if ( (__int64 *)v5 != &qword_394A78 )
    {
      v31 = a3 + 10;
      do
      {
        v7 = *(_DWORD *)(v5 + 8716);
        memset(v38, 0, 32);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_is_ctx_affected",
            17101,
            "Enter:max_idx = %d, ctx_idx: %u",
            v7,
            *(_DWORD *)(v5 + 56));
          if ( v7 > 7 )
          {
LABEL_5:
            if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_is_ctx_affected__rs, "cam_ife_hw_mgr_is_ctx_affected") )
              v6 = 3;
            else
              v6 = 2;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              v6,
              8,
              1,
              "cam_ife_hw_mgr_is_ctx_affected",
              17105,
              "invalid parameter = %d, ctx_idx: %u",
              v7,
              *(_DWORD *)(v5 + 56));
            goto LABEL_9;
          }
        }
        else if ( v7 > 7 )
        {
          goto LABEL_5;
        }
        if ( !v7 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_is_ctx_affected",
              17125,
              "Exit, ctx_idx: %u",
              *(_DWORD *)(v5 + 56));
          goto LABEL_9;
        }
        v8 = *(_DWORD *)(v5 + 8584);
        if ( v8 > 7 )
          goto LABEL_127;
        v9 = *((_DWORD *)&v34 + v8);
        v10 = v9 != 0;
        if ( v9 )
        {
          v11 = 0;
          if ( v7 == 1 )
            goto LABEL_54;
        }
        else
        {
          LODWORD(v38[0]) = *(_DWORD *)(v5 + 8584);
          v11 = 1;
          if ( v7 == 1 )
            goto LABEL_54;
        }
        v12 = *(_DWORD *)(v5 + 8596);
        if ( v12 > 7 )
          goto LABEL_127;
        if ( *((_DWORD *)&v34 + v12) )
        {
          v10 = 1;
          if ( v7 == 2 )
            goto LABEL_54;
        }
        else
        {
          v13 = (_DWORD *)((unsigned __int64)v38 | (4 * v11++));
          *v13 = v12;
          if ( v7 == 2 )
            goto LABEL_54;
        }
        v14 = *(_DWORD *)(v5 + 8608);
        if ( v14 > 7 )
          goto LABEL_127;
        if ( *((_DWORD *)&v34 + v14) )
        {
          v10 = 1;
          if ( v7 == 3 )
            goto LABEL_54;
        }
        else
        {
          if ( v11 > 7 )
            goto LABEL_128;
          *((_DWORD *)v38 + v11++) = v14;
          if ( v7 == 3 )
            goto LABEL_54;
        }
        v15 = *(_DWORD *)(v5 + 8620);
        if ( v15 > 7 )
          goto LABEL_127;
        if ( *((_DWORD *)&v34 + v15) )
        {
          v10 = 1;
          if ( v7 == 4 )
            goto LABEL_54;
        }
        else
        {
          if ( v11 > 7 )
            goto LABEL_128;
          *((_DWORD *)v38 + v11++) = v15;
          if ( v7 == 4 )
            goto LABEL_54;
        }
        v16 = *(_DWORD *)(v5 + 8632);
        if ( v16 > 7 )
          goto LABEL_127;
        if ( *((_DWORD *)&v34 + v16) )
        {
          v10 = 1;
          if ( v7 == 5 )
            goto LABEL_54;
        }
        else
        {
          if ( v11 > 7 )
            goto LABEL_128;
          *((_DWORD *)v38 + v11++) = v16;
          if ( v7 == 5 )
            goto LABEL_54;
        }
        v17 = *(_DWORD *)(v5 + 8644);
        if ( v17 > 7 )
          goto LABEL_127;
        if ( *((_DWORD *)&v34 + v17) )
        {
          v10 = 1;
          if ( v7 == 6 )
            goto LABEL_54;
        }
        else
        {
          if ( v11 > 7 )
            goto LABEL_128;
          *((_DWORD *)v38 + v11++) = v17;
          if ( v7 == 6 )
            goto LABEL_54;
        }
        v18 = *(_DWORD *)(v5 + 8656);
        if ( v18 > 7 )
          goto LABEL_127;
        if ( !*((_DWORD *)&v34 + v18) )
        {
          if ( v11 > 7 )
            goto LABEL_128;
          *((_DWORD *)v38 + v11++) = v18;
          if ( !v10 )
            goto LABEL_78;
          goto LABEL_55;
        }
        v10 = 1;
LABEL_54:
        if ( !v10 )
          goto LABEL_78;
LABEL_55:
        if ( v11 )
        {
          if ( v11 > 8 )
            goto LABEL_128;
          if ( ((v11 - 1) & 0x3FFFFFFFFFFFFFF8LL) != 0
            || (v19 = *((unsigned int *)v38 + v11 - 1), (unsigned int)v19 > 7) )
          {
LABEL_127:
            __break(1u);
LABEL_128:
            __break(0x5512u);
          }
          v10 = 1;
          *((_DWORD *)&v34 + v19) = 1;
          if ( v11 != 1 )
          {
            if ( ((v11 - 2) & 0x3FFFFFFFFFFFFFF8LL) != 0 )
              goto LABEL_127;
            v20 = *((unsigned int *)&v38[-1] + v11);
            if ( (unsigned int)v20 > 7 )
              goto LABEL_127;
            *((_DWORD *)&v34 + v20) = 1;
            if ( v11 != 2 )
            {
              if ( ((v11 - 3) & 0x3FFFFFFFFFFFFFF8LL) != 0 )
                goto LABEL_127;
              v21 = *((unsigned int *)&v38[-1] + v11 - 1);
              if ( (unsigned int)v21 > 7 )
                goto LABEL_127;
              *((_DWORD *)&v34 + v21) = 1;
              if ( v11 != 3 )
              {
                if ( ((v11 - 4) & 0x3FFFFFFFFFFFFFF8LL) != 0 )
                  goto LABEL_127;
                v22 = *((unsigned int *)&v38[-2] + v11);
                if ( (unsigned int)v22 > 7 )
                  goto LABEL_127;
                *((_DWORD *)&v34 + v22) = 1;
                if ( v11 != 4 )
                {
                  if ( ((v11 - 5) & 0x3FFFFFFFFFFFFFF8LL) != 0 )
                    goto LABEL_127;
                  v23 = *((unsigned int *)&v38[-2] + v11 - 1);
                  if ( (unsigned int)v23 > 7 )
                    goto LABEL_127;
                  *((_DWORD *)&v34 + v23) = 1;
                  if ( v11 != 5 )
                  {
                    if ( ((v11 - 6) & 0x3FFFFFFFFFFFFFF8LL) != 0 )
                      goto LABEL_127;
                    v24 = *((unsigned int *)&v38[-3] + v11);
                    if ( (unsigned int)v24 > 7 )
                      goto LABEL_127;
                    *((_DWORD *)&v34 + v24) = 1;
                    if ( v11 != 6 )
                    {
                      v25 = v11 - 7;
                      if ( (v25 & 0x3FFFFFFFFFFFFFF8LL) != 0 )
                        goto LABEL_127;
                      v26 = *((unsigned int *)v38 + v25);
                      if ( (unsigned int)v26 > 7 )
                        goto LABEL_127;
                      *((_DWORD *)&v34 + v26) = 1;
                    }
                  }
                }
              }
            }
          }
        }
LABEL_78:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_is_ctx_affected",
            17125,
            "Exit, ctx_idx: %u",
            *(_DWORD *)(v5 + 56));
          if ( !v10 )
            goto LABEL_9;
        }
        else if ( !v10 )
        {
          goto LABEL_9;
        }
        if ( (a4 & 1) != 0 || !*(_DWORD *)(v5 + 8844) )
        {
          *(_DWORD *)(v5 + 8844) = 1;
          v27 = *(_DWORD **)(v5 + 24);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_find_affected_ctx",
              17178,
              "Add affected ctx %u to list",
              *(_DWORD *)(v5 + 56));
          v28 = (unsigned int)a3[26];
          if ( (unsigned int)v28 <= 7 )
          {
            a3[26] = v28 + 1;
            *(_QWORD *)&v31[2 * v28] = v5;
          }
          if ( !v27 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_ife_hw_mgr_find_affected_ctx",
              17194,
              "Error call back is not set, ctx_idx: %u",
              *(_DWORD *)(v5 + 56));
            result = 0;
            goto LABEL_125;
          }
          v29 = *(_QWORD *)(v5 + 32);
          if ( *(v27 - 1) != 414296116 )
            __break(0x8238u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v27)(v29, 0, a1);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_hw_mgr_find_affected_ctx",
            17169,
            "CTX:%u already error reported",
            *(_DWORD *)(v5 + 56));
        }
LABEL_9:
        v5 = *(_QWORD *)v5;
      }
      while ( (__int64 *)v5 != &qword_394A78 );
    }
    a3[1] = v34;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        0);
    a3[2] = HIDWORD(v34);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        1);
    a3[3] = v35;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        2);
    a3[4] = HIDWORD(v35);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        3);
    a3[5] = v36;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        4);
    a3[6] = HIDWORD(v36);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        5);
    a3[7] = v37;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        6);
    result = 0;
    a3[8] = HIDWORD(v37);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_find_affected_ctx",
        17203,
        "Vfe core %d is affected (%d)",
        7);
      result = 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_find_affected_ctx",
      17149,
      "recovery_data parameter is NULL");
    result = 4294967274LL;
  }
LABEL_125:
  _ReadStatusReg(SP_EL0);
  return result;
}
