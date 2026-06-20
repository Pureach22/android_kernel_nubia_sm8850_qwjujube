__int64 __fastcall zte_misc_get_node_val(char *s)
{
  size_t v2; // x20
  __int64 v3; // x22
  const char *v4; // x21
  __int64 v5; // x1
  __int64 v6; // x2
  size_t v7; // x21
  char *v8; // x8
  char *v9; // x1
  __int64 result; // x0
  void *v11; // x0
  unsigned int v12; // [xsp+4h] [xbp-4Ch] BYREF
  char sa[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v14; // [xsp+10h] [xbp-40h]
  __int64 v15; // [xsp+18h] [xbp-38h]
  __int64 v16; // [xsp+20h] [xbp-30h]
  __int64 v17; // [xsp+28h] [xbp-28h]
  __int64 v18; // [xsp+30h] [xbp-20h]
  __int64 v19; // [xsp+38h] [xbp-18h]
  __int64 v20; // [xsp+40h] [xbp-10h]
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  if ( s && *s )
  {
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    *(_QWORD *)sa = 0;
    v14 = 0;
    v2 = strlen(s);
    v3 = 0;
    while ( 1 )
    {
      v4 = (&node_ops_list)[v3];
      if ( !strncmp(v4, s, v2) )
      {
        v7 = strlen(v4);
        if ( v7 == strlen(s) )
        {
          v8 = (&node_ops_list)[v3 + 2];
          if ( v8 )
            break;
        }
      }
      v3 += 5;
      if ( v3 == 180 )
      {
        v11 = &unk_7D7F;
LABEL_14:
        printk(v11, v5, v6);
        goto LABEL_15;
      }
    }
    v9 = (&node_ops_list)[v3 + 4];
    if ( *((_DWORD *)v8 - 1) != 697349865 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(char *, char *))v8)(sa, v9) & 0x80000000) == 0 )
    {
      if ( sscanf(sa, "%d", &v12) == 1 )
      {
        result = v12;
        goto LABEL_16;
      }
      v11 = &unk_7F17;
      goto LABEL_14;
    }
  }
LABEL_15:
  result = 4294967274LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
