__int64 __fastcall zte_misc_common_callback_set(__int64 a1, const char **a2)
{
  const char *v3; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x22
  unsigned int v7; // w20
  const char *v8; // x21
  size_t v9; // x0
  size_t v10; // x2
  size_t v11; // x21
  size_t v12; // x0
  char *v13; // x8
  char *v14; // x1
  size_t v16; // x2
  char string[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v18; // [xsp+10h] [xbp-40h]
  __int64 v19; // [xsp+18h] [xbp-38h]
  __int64 v20; // [xsp+20h] [xbp-30h]
  __int64 v21; // [xsp+28h] [xbp-28h]
  __int64 v22; // [xsp+30h] [xbp-20h]
  __int64 v23; // [xsp+38h] [xbp-18h]
  __int64 v24; // [xsp+40h] [xbp-10h]
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  *(_QWORD *)string = 0;
  v18 = 0;
  if ( sscanf(v3, "%s", string) == 1 )
  {
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      v8 = (&node_ops_list)[v6];
      v9 = strnlen(string, 0x40u);
      v10 = v9;
      if ( v9 >= 0x41 )
        goto LABEL_18;
      if ( v9 == 64 )
        goto LABEL_17;
      if ( !strncmp(v8, string, v9) )
      {
        v11 = strlen(v8);
        v12 = strnlen(string, 0x40u);
        if ( v12 >= 0x41 )
        {
          v16 = v12 + 1;
          goto LABEL_20;
        }
        if ( v12 == 64 )
        {
LABEL_17:
          _fortify_panic(4, 64, 65);
LABEL_18:
          v16 = v10 + 1;
LABEL_20:
          _fortify_panic(2, 64, v16);
        }
        if ( v11 == v12 )
        {
          v13 = (&node_ops_list)[v6 + 1];
          if ( v13 )
          {
            v14 = (&node_ops_list)[v6 + 4];
            if ( *((_DWORD *)v13 - 1) != 1291426251 )
              __break(0x8228u);
            v7 = ((__int64 (__fastcall *)(__int64, char *))v13)(a1, v14);
            if ( (v7 & 0x80000000) != 0 )
              goto LABEL_16;
          }
        }
      }
      v6 += 5;
      if ( v6 == 180 )
        goto LABEL_16;
    }
  }
  printk(&unk_7C12, v4, v5);
  v7 = -22;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v7;
}
