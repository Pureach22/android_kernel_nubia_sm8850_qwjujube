__int64 __fastcall print_rd_rules(__int64 result)
{
  unsigned __int64 v1; // x9
  __int64 v2; // x19
  unsigned __int64 v3; // x24
  __int64 v4; // x25
  unsigned int *v5; // x22
  unsigned int v6; // w8
  __int64 v7; // x3
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x13
  __int64 v11; // x13
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x13
  unsigned int *v14; // x15
  unsigned int *v15; // x14
  unsigned int v16; // w10
  bool v17; // cf
  __int64 v18; // x9
  unsigned int *v19; // x12
  unsigned int *v20; // x11
  unsigned int v21; // w13
  bool v22; // cc
  unsigned __int64 v23; // x12
  unsigned int v25; // w9
  int v26; // w10
  int v27; // w10
  int v28; // w10
  unsigned int v29; // w10
  __int64 v30; // x4
  __int64 v31; // [xsp+8h] [xbp-58h]
  __int64 v32; // [xsp+10h] [xbp-50h]
  _QWORD v33[4]; // [xsp+18h] [xbp-48h] BYREF
  char s[32]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v35; // [xsp+58h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v1) = *(_DWORD *)(result + 16);
  if ( (_DWORD)v1 )
  {
    v2 = result;
    v3 = 0;
    v4 = result + 28;
    v31 = result + 124;
    v32 = result - 68;
    memset(v33, 0, sizeof(v33));
    do
    {
      v5 = (unsigned int *)(v4 + 96 * v3);
      v6 = v5[21];
      v7 = v5[2];
      if ( (v6 & 0x800) == 0 )
      {
        snprintf(s, 0x20u, "%d KHz", v7);
        if ( (v5[21] & 0x10) != 0 )
          goto LABEL_59;
        goto LABEL_3;
      }
      if ( v3 >= (unsigned int)v1 )
        v8 = (unsigned int)v1;
      else
        v8 = v3;
      if ( !v8 )
        goto LABEL_32;
      v9 = v8 + 1;
      v10 = v3 >= (unsigned int)v1 ? (unsigned int)v1 : v3;
      v8 = v9 & 0x1FFFFFFFELL;
      v11 = (v10 + 1) & 0x1FFFFFFFELL;
      do
        v11 -= 2;
      while ( v11 );
      if ( v9 == v8 )
      {
        v12 = v8 - 1;
        if ( (_DWORD)v1 == (_DWORD)v12 )
          goto LABEL_34;
      }
      else
      {
LABEL_32:
        do
        {
          v23 = v8 + 1;
          if ( v8 >= (unsigned int)v1 )
            break;
        }
        while ( v3 != v8++ );
        v12 = v23 - 1;
        if ( (_DWORD)v1 == (_DWORD)v23 - 1 )
        {
LABEL_34:
          v25 = 0;
          goto LABEL_37;
        }
      }
      v13 = v12 + 1;
      v14 = (unsigned int *)(v4 + 96 * v3);
      v15 = (unsigned int *)(v32 + 96 * v12);
      do
      {
        v16 = *v14;
        if ( !--v13 )
          break;
        v14 = v15;
        v17 = v15[1] >= v16;
        v15 -= 24;
      }
      while ( v17 );
      LODWORD(v1) = v1 - 1;
      if ( (unsigned int)v12 <= (unsigned int)v1 )
        v1 = (unsigned int)v1;
      else
        v1 = (unsigned int)v12;
      v18 = v1 - v12 + 1;
      v19 = (unsigned int *)(v31 + 96 * v12);
      v20 = (unsigned int *)(v4 + 96 * v3);
      while ( --v18 )
      {
        v21 = v20[1];
        v20 = v19;
        v22 = *v19 > v21;
        v19 += 24;
        if ( v22 )
          goto LABEL_36;
      }
      v21 = v20[1];
LABEL_36:
      v25 = v21 - v16;
LABEL_37:
      if ( v25 >= 0x27100 )
        v26 = 160000;
      else
        v26 = v25;
      if ( (v6 & 0x40000) != 0 )
        v25 = v26;
      if ( v25 >= 0x13880 )
        v27 = 80000;
      else
        v27 = v25;
      if ( (v6 & 0x10000) != 0 )
        v25 = v27;
      if ( v25 >= 0x9C40 )
        v28 = 40000;
      else
        v28 = v25;
      if ( (v6 & 0x8000) != 0 )
        v25 = v28;
      if ( v25 >= 0x4E20 )
        v29 = 20000;
      else
        v29 = v25;
      if ( (~v6 & 0x6000) != 0 )
        v30 = v25;
      else
        v30 = v29;
      snprintf(s, 0x20u, "%d KHz, %u KHz AUTO", v7, v30);
      if ( (v5[21] & 0x10) != 0 )
      {
LABEL_59:
        result = scnprintf(v33, 32, "%u s", v5[22] / 0x3E8);
        goto LABEL_4;
      }
LABEL_3:
      result = scnprintf(v33, 32, "N/A");
LABEL_4:
      v1 = *(unsigned int *)(v2 + 16);
      ++v3;
    }
    while ( v3 < v1 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
