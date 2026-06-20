__int64 __fastcall rpmh_regulator_req(__int64 result, unsigned int *a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  __int64 v6; // x19
  int v7; // w8
  __int64 v8; // x25
  __int64 v9; // x8
  unsigned __int64 v10; // x21
  __int64 v11; // x22
  bool v12; // w27
  __int64 v13; // x8
  int v14; // w8
  unsigned __int64 v15; // x21
  char v16; // w8
  __int64 i; // x20
  const char *v18; // x3
  __int64 v19; // x8
  int v20; // w0
  __int64 v21; // x23
  const char *v22; // x3
  int v23; // w0
  __int64 v24; // [xsp+0h] [xbp-150h]
  unsigned int v25; // [xsp+14h] [xbp-13Ch]
  __int64 v26; // [xsp+18h] [xbp-138h]
  char v27; // [xsp+20h] [xbp-130h]
  unsigned __int64 v28; // [xsp+28h] [xbp-128h]
  char **v29; // [xsp+30h] [xbp-120h]
  _QWORD v31[34]; // [xsp+40h] [xbp-110h] BYREF

  v31[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(result + 336);
  v7 = *(_DWORD *)(v6 + 72);
  memset(v31, 0, 256);
  if ( v7 > 1 )
  {
    if ( v7 != 2 )
    {
      if ( v7 != 3 )
        goto LABEL_43;
      v8 = 1;
      v28 = 8;
      v29 = &rpmh_regulator_pbs_param_names;
      v26 = a3;
      v27 = 1;
LABEL_11:
      if ( a5 > 2 )
        goto LABEL_54;
      v10 = a4;
      LODWORD(v11) = scnprintf(
                       v31,
                       256,
                       "%s (%s), addr=0x%05X: s=%s; sent: ",
                       *(const char **)(v6 + 8),
                       *(const char **)(result + 8),
                       *(_DWORD *)(v6 + 16),
                       rpmh_regulator_state_names[a5]);
      v25 = a4;
      v12 = (a4 & 1) == 0;
      v24 = v6 + 80;
      if ( (a4 & 1) != 0 )
      {
        if ( (unsigned int)v11 > 0x100 )
          goto LABEL_53;
        v11 = (unsigned int)scnprintf(
                              (char *)v31 + (unsigned int)v11,
                              256LL - (unsigned int)v11,
                              "%s%s=%u",
                              (const char *)&unk_8F54,
                              *v29,
                              *a2)
            + (unsigned int)v11;
        if ( *(_DWORD *)(v6 + 72) == 1 )
        {
          if ( (unsigned int)v11 > 0x100 )
            goto LABEL_53;
          v13 = *a2;
          if ( (unsigned int)v13 > 0x1F )
            goto LABEL_53;
          LODWORD(v11) = scnprintf((char *)v31 + v11, 256 - v11, " (vlvl=%u)", *(_DWORD *)(v24 + 4 * v13)) + v11;
        }
      }
      if ( (v27 & 1) == 0 )
      {
        for ( i = 1; i != v8; ++i )
        {
          if ( ((v10 >> i) & 1) != 0 )
          {
            if ( (unsigned int)v11 > 0x100 )
              goto LABEL_53;
            if ( v28 <= 8 * i )
              goto LABEL_54;
            if ( v12 )
              v18 = (const char *)&unk_8F54;
            else
              v18 = ", ";
            v12 = 0;
            LODWORD(v11) = scnprintf(
                             (char *)v31 + (unsigned int)v11,
                             256LL - (unsigned int)v11,
                             "%s%s=%u",
                             v18,
                             v29[i],
                             a2[i])
                         + v11;
          }
        }
      }
      v14 = *(_DWORD *)(v26 + 16);
      v15 = v14 & ~v25;
      if ( (v14 & ~v25) == 0 )
      {
        v15 = 0;
        v16 = 1;
        if ( (v27 & 1) == 0 )
          goto LABEL_44;
        goto LABEL_42;
      }
      if ( (unsigned int)v11 <= 0x100 )
      {
        v11 = (unsigned int)scnprintf((char *)v31 + (unsigned int)v11, 256LL - (unsigned int)v11, "; prev: ")
            + (unsigned int)v11;
        if ( (v15 & 1) == 0 )
        {
          v16 = 1;
          if ( (v27 & 1) != 0 )
            goto LABEL_42;
LABEL_44:
          v21 = 1;
          while ( 1 )
          {
            if ( ((v15 >> v21) & 1) != 0 )
            {
              if ( (unsigned int)v11 > 0x100 )
                goto LABEL_53;
              if ( v28 <= 8 * v21 )
                goto LABEL_54;
              if ( (v16 & 1) != 0 )
                v22 = (const char *)&unk_8F54;
              else
                v22 = ", ";
              v23 = scnprintf(
                      (char *)v31 + (unsigned int)v11,
                      256LL - (unsigned int)v11,
                      "%s%s=%u",
                      v22,
                      v29[v21],
                      a2[v21]);
              v16 = 0;
              LODWORD(v11) = v23 + v11;
            }
            if ( ++v21 == v8 )
              goto LABEL_42;
          }
        }
        if ( (unsigned int)v11 <= 0x100 )
        {
          v11 = (unsigned int)scnprintf((char *)v31 + v11, 256 - v11, "%s%s=%u", (const char *)&unk_8F54, *v29, *a2)
              + (unsigned int)v11;
          if ( *(_DWORD *)(v6 + 72) == 1 )
          {
            if ( (unsigned int)v11 <= 0x100 )
            {
              v19 = *a2;
              if ( (unsigned int)v19 <= 0x1F )
              {
                v20 = scnprintf((char *)v31 + v11, 256 - v11, " (vlvl=%u)", *(_DWORD *)(v24 + 4 * v19));
                v16 = 0;
                LODWORD(v11) = v20 + v11;
                if ( (v27 & 1) == 0 )
                  goto LABEL_44;
                goto LABEL_42;
              }
            }
            goto LABEL_53;
          }
          v16 = 0;
          if ( (v27 & 1) == 0 )
            goto LABEL_44;
LABEL_42:
          result = ipc_log_string(rpmh_reg_ipc_log, "%s\n", (const char *)v31);
          goto LABEL_43;
        }
      }
LABEL_53:
      __break(0x5512u);
LABEL_54:
      __break(1u);
    }
    v8 = 2;
    v29 = (char **)&rpmh_regulator_xob_param_names;
    v9 = 16;
    v26 = a3;
    v27 = 0;
LABEL_10:
    v28 = v9;
    goto LABEL_11;
  }
  if ( !v7 )
  {
    v26 = a3;
    v27 = 0;
    v29 = rpmh_regulator_vrm_param_names;
    v8 = 4;
    v9 = 32;
    goto LABEL_10;
  }
  if ( v7 == 1 )
  {
    v8 = 1;
    v26 = a3;
    v27 = 1;
    v28 = 8;
    v29 = &rpmh_regulator_arc_param_names;
    goto LABEL_11;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
