__int64 __fastcall cam_isp_config_csid_rup_aup(_DWORD *a1, char a2)
{
  unsigned __int64 v3; // x8
  __int64 v4; // x26
  _QWORD *v5; // x27
  _DWORD *v6; // x20
  _QWORD *v7; // x28
  __int64 v8; // x8
  unsigned int v9; // w7
  _BYTE *v10; // x9
  __int64 v11; // x10
  char v12; // w10
  __int64 v13; // x8
  unsigned int v14; // w7
  _BYTE *v15; // x9
  __int64 v16; // x10
  char v17; // w10
  __int64 v18; // x22
  const char *v19; // x27
  _BYTE *v20; // x2
  int v21; // w8
  __int64 v22; // x20
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 result; // x0
  _BYTE s[1088]; // [xsp+20h] [xbp-450h] BYREF
  __int64 v29; // [xsp+460h] [xbp-10h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v3 = (unsigned int)a1[2179];
  if ( (_DWORD)v3 )
  {
    v4 = 0;
    v5 = a1 + 52;
    while ( 1 )
    {
      if ( v4 == 11 )
      {
LABEL_41:
        __break(0x5512u);
LABEL_42:
        __break(1u);
      }
      v6 = &a1[3 * v4 + 2146];
      if ( !v6[2] )
      {
        v7 = (_QWORD *)*v5;
        if ( (_QWORD *)*v5 != v5 )
          break;
      }
LABEL_4:
      if ( ++v4 >= v3 )
        goto LABEL_28;
    }
    while ( 1 )
    {
      if ( *((_DWORD *)v7 + 4) )
      {
        v8 = v7[4];
        if ( !v8 )
          goto LABEL_18;
        v9 = *(_DWORD *)(*(_QWORD *)(v8 + 16) + 4LL);
        if ( v9 != *v6 )
          goto LABEL_18;
        if ( v9 > 7 )
          goto LABEL_41;
        v10 = &s[136 * v9];
        v11 = *((unsigned int *)v10 + 28);
        if ( (unsigned int)v11 > 0xB )
          goto LABEL_41;
        if ( 8 * v11 + 136 * (unsigned __int64)v9 + 16 > 0x43F )
          goto LABEL_42;
        *(_QWORD *)&v10[8 * v11 + 16] = v8;
        v12 = debug_mdl;
        ++*((_DWORD *)v10 + 28);
        if ( (v12 & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v12 & 8,
            4,
            "cam_isp_config_csid_rup_aup",
            16113,
            "Reg update for res %d hw_id %d cdm_idx %d ctx_idx: %u",
            *(_DWORD *)(v8 + 4),
            v9,
            v9,
            a1[14]);
          v13 = v7[5];
          if ( v13 )
          {
LABEL_19:
            v14 = *(_DWORD *)(*(_QWORD *)(v13 + 16) + 4LL);
            if ( v14 == *v6 )
            {
              if ( v14 > 7 )
                goto LABEL_41;
              v15 = &s[136 * v14];
              v16 = *((unsigned int *)v15 + 28);
              if ( (unsigned int)v16 > 0xB )
                goto LABEL_41;
              if ( 8 * v16 + 136 * (unsigned __int64)v14 + 16 > 0x43F )
                goto LABEL_42;
              *(_QWORD *)&v15[8 * v16 + 16] = v13;
              v17 = debug_mdl;
              ++*((_DWORD *)v15 + 28);
              if ( (v17 & 8) != 0 && !debug_priority )
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v17 & 8,
                  4,
                  "cam_isp_config_csid_rup_aup",
                  16113,
                  "Reg update for res %d hw_id %d cdm_idx %d ctx_idx: %u",
                  *(_DWORD *)(v13 + 4),
                  v14,
                  v14,
                  a1[14]);
            }
          }
        }
        else
        {
LABEL_18:
          v13 = v7[5];
          if ( v13 )
            goto LABEL_19;
        }
      }
      v7 = (_QWORD *)*v7;
      if ( v7 == v5 )
      {
        v3 = (unsigned int)a1[2179];
        goto LABEL_4;
      }
    }
  }
LABEL_28:
  v18 = 0;
  if ( (a2 & 1) != 0 )
    v19 = "Y";
  else
    v19 = "N";
  do
  {
    v20 = &s[v18];
    if ( *(_DWORD *)&s[v18 + 112] )
    {
      v21 = a1[2360];
      v22 = *((_QWORD *)v20 + 2);
      *(_QWORD *)v20 = 0;
      *((_DWORD *)v20 + 2) = 0;
      v20[128] = 1;
      *((_DWORD *)v20 + 29) = v21;
      v20[130] = a2 & 1;
      v23 = *(_QWORD *)(v22 + 16);
      v24 = *(_QWORD *)(v23 + 112);
      v25 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 88);
      if ( *((_DWORD *)v25 - 1) != -1055839300 )
        __break(0x8228u);
      result = v25(v24, 3);
      if ( (_DWORD)result )
        goto LABEL_40;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_config_csid_rup_aup",
          16140,
          "Reg update for CSID: %u, mup: %u, ctx_idx: %u, disable_aup_write: %s",
          *(_DWORD *)(*(_QWORD *)(v22 + 16) + 4LL),
          a1[2360],
          a1[14],
          v19);
    }
    v18 += 136;
  }
  while ( v18 != 1088 );
  result = 0;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
