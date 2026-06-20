__int64 __fastcall gsihal_reg_init(unsigned int a1)
{
  char *v1; // x24
  char *v2; // x27
  __int64 v3; // x19
  __int64 v4; // x22
  __int64 v5; // x26
  __int64 v6; // x28
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x8
  bool v10; // zf
  bool v12; // zf
  char *v13; // x20
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-30h]

  _ReadStatusReg(SP_EL0);
  if ( a1 - 14 <= 0xFFFFFFF2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid GSI HW type (%d)\n", "gsihal_reg_init", 2450, a1);
    result = 4294967274LL;
  }
  else
  {
    if ( a1 >= 2 )
    {
      v1 = (char *)&gsihal_reg_objs;
      v2 = (char *)&unk_3410;
      v3 = 1;
      v4 = 9600;
      v15 = a1;
      do
      {
        v5 = 0;
        v6 = 0;
        ++v3;
        do
        {
          if ( (unsigned __int64)(v4 + v6) >> 7 >= 0x20D )
            _fortify_panic(22, 0, 32);
          if ( *(_QWORD *)&v2[v6] )
            v10 = 0;
          else
            v10 = *(_QWORD *)&v2[v6 + 8] == 0;
          v12 = v10 && *(_QWORD *)&v2[v6 + 16] == 0 && *(_QWORD *)&v2[v6 + 24] == 0;
          v13 = &v1[v6 + (_QWORD)&unk_2580];
          if ( v12 )
          {
            v7 = *(_QWORD *)&v1[v6 + 4808];
            v8 = *(_QWORD *)&v1[v6 + 4816];
            v9 = *(_QWORD *)&v1[v6 + 4824];
            *(_QWORD *)v13 = *(_QWORD *)&v1[v6 + 4800];
            *((_QWORD *)v13 + 1) = v7;
            *((_QWORD *)v13 + 2) = v8;
            *((_QWORD *)v13 + 3) = v9;
            goto LABEL_7;
          }
          if ( v6 == 3744 || *(_DWORD *)&v1[v6 + 9616] )
          {
            if ( *(_QWORD *)v13 )
              goto LABEL_22;
          }
          else
          {
            dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d reg=%s with zero offset gsi_ver=%d\n",
              "gsihal_reg_init",
              2470,
              gsireg_name_to_str[v5],
              v3);
            __break(0x800u);
            if ( *(_QWORD *)v13 )
              goto LABEL_22;
          }
          dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d reg=%s with NULL construct func gsi_ver=%d\n",
            "gsihal_reg_init",
            2476,
            gsireg_name_to_str[v5],
            v3);
          __break(0x800u);
LABEL_22:
          if ( !*(_QWORD *)&v1[v6 + 9608] )
          {
            dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d reg=%s with NULL parse func gsi_ver=%d\n",
              "gsihal_reg_init",
              2482,
              gsireg_name_to_str[v5],
              v3);
            __break(0x800u);
          }
LABEL_7:
          ++v5;
          v6 += 32;
        }
        while ( v5 != 150 );
        v2 += 4800;
        v1 += 4800;
        v4 += 4800;
      }
      while ( v3 != v15 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
