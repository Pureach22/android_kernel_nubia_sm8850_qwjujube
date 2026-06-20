__int64 __fastcall perfmon_info_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x24
  __int64 v5; // x19
  __int64 v6; // x19
  __int64 v7; // x19
  __int64 v8; // x19
  __int64 v9; // x19
  __int64 v10; // x19
  __int64 v11; // x19
  __int64 v12; // x19
  __int64 v13; // x19
  __int64 v14; // x19
  __int64 v15; // x19
  size_t v16; // x0
  __int64 v17; // x21
  unsigned __int64 v18; // x25
  unsigned __int8 *v19; // x8
  __int64 v20; // x9
  __int64 v21; // x24
  unsigned int v22; // w28
  bool v23; // cf
  char **v24; // x8
  __int64 v25; // x21
  __int64 i; // x19
  const char *v27; // x22
  size_t v28; // x0
  size_t v29; // x23
  size_t v30; // x0
  const char *v31; // x1
  size_t v32; // x2
  __int64 v33; // x22
  __int64 v34; // x19
  int v35; // w0
  size_t v37; // x2
  __int64 v38; // [xsp+8h] [xbp-58h]
  char string[8]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v40; // [xsp+18h] [xbp-48h]
  __int64 v41; // [xsp+20h] [xbp-40h]
  __int64 v42; // [xsp+28h] [xbp-38h]
  __int64 v43; // [xsp+30h] [xbp-30h]
  __int64 v44; // [xsp+38h] [xbp-28h]
  __int64 v45; // [xsp+40h] [xbp-20h]
  _WORD v46[7]; // [xsp+48h] [xbp-18h] BYREF
  __int64 v47; // [xsp+58h] [xbp-8h]

  v3 = a3;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v5 = (int)scnprintf(
              a3,
              4096,
              "\nSLC Version: %u.%u.%u ",
              **(unsigned __int8 **)(v4 + 112),
              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 1LL),
              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 2LL));
  v6 = v5
     + (int)scnprintf(
              v3 + v5,
              4096 - v5,
              "No. of Memory Controller: %u ",
              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 6LL) >> 6);
  v7 = v6 + (int)scnprintf(v3 + v6, 4096 - v6, "No. of Channels: %u.\n", *(_BYTE *)(*(_QWORD *)(v4 + 112) + 6LL) & 0x3F);
  v8 = v7
     + (int)scnprintf(
              v3 + v7,
              4096 - v7,
              "Max no. of counters supported: %u ",
              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 5LL));
  v9 = v8
     + (int)scnprintf(
              v3 + v8,
              4096 - v8,
              "Max no. of filters supported: %u\n\n",
              *(unsigned __int8 *)(*(_QWORD *)(v4 + 112) + 4LL));
  v10 = v9 + (int)scnprintf(v3 + v9, 4096 - v9, "SLC port filter support:\n");
  v11 = v10 + (int)scnprintf(v3 + v10, 4096 - v10, "|--------+---------------------");
  v12 = v11 + (int)scnprintf(v3 + v11, 4096 - v11, "----------------------------|\n");
  v13 = v12 + (int)scnprintf(v3 + v12, 4096 - v12, "| PORT\t | FILTER SUPPORT      ");
  v14 = v13 + (int)scnprintf(v3 + v13, 4096 - v13, "                            |\n");
  v15 = v14 + (int)scnprintf(v3 + v14, 4096 - v14, "|--------+---------------------");
  v16 = scnprintf(v3 + v15, 4096 - v15, "----------------------------|\n");
  v17 = v15 + (int)v16;
  if ( *(_BYTE *)(v4 + 217) )
  {
    v18 = 0;
    v38 = v4;
    do
    {
      v45 = 0;
      memset(v46, 0, sizeof(v46));
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      *(_QWORD *)string = 0;
      v40 = 0;
      if ( v18 >= 7 )
        goto LABEL_25;
      v19 = *(unsigned __int8 **)(v4 + 112);
      v20 = *(_QWORD *)(v4 + 120);
      v21 = v3;
      v22 = *(unsigned __int8 *)(v20 + v18 + 12);
      v23 = *v19 >= 6u;
      v24 = ports_v6;
      if ( !v23 )
        v24 = ports_v5;
      v25 = v17 + (int)scnprintf(v3 + v17, 4096 - v17, "| %s\t |", v24[v18]);
      for ( i = 0; i != 6; ++i )
      {
        if ( ((v22 >> i) & 1) != 0 )
        {
          v27 = filters[i];
          v28 = strnlen(string, 0x46u);
          v29 = v28;
          if ( v28 >= 0x47 )
          {
            v37 = v28 + 1;
            goto LABEL_24;
          }
          if ( v28 != 70 )
          {
            v30 = strlen(v27);
            v31 = v27;
            if ( v30 + v29 >= 0x46 )
              v32 = 69 - v29;
            else
              v32 = v30;
            if ( v30 + v29 >= 0x46 )
              v33 = 69;
            else
              v33 = v30 + v29;
            memcpy(&string[v29], v31, v32);
            string[v33] = 0;
          }
        }
      }
      v16 = strnlen(string, 0x46u);
      if ( v16 >= 0x47 )
      {
        while ( 1 )
        {
          v37 = v16 + 1;
LABEL_24:
          v16 = _fortify_panic(2, 70, v37);
LABEL_25:
          __break(0x5512u);
        }
      }
      v3 = v21;
      if ( v16 != 70 )
        string[v16] = 0;
      v16 = scnprintf(v21 + v25, 4096 - v25, "%-48s |\n", string);
      v4 = v38;
      ++v18;
      v17 = v25 + (int)v16;
    }
    while ( v18 < *(unsigned __int8 *)(v38 + 217) );
  }
  v34 = v17 + (int)scnprintf(v3 + v17, 4096 - v17, "|--------+---------------------");
  v35 = scnprintf(v3 + v34, 4096 - v34, "----------------------------|\n");
  _ReadStatusReg(SP_EL0);
  return v34 + v35;
}
