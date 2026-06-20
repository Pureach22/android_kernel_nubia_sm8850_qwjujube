__int64 __fastcall slc_mpam_monitor_schemata_store(__int64 a1, char *a2, __int64 a3)
{
  __int64 v5; // x0
  int v6; // w9
  int v7; // w10
  char *v8; // x0
  char *v9; // x25
  int v10; // w9
  int v11; // w8
  int v12; // w9
  int v13; // w8
  int v14; // w8
  __int64 v16; // [xsp+0h] [xbp-30h] BYREF
  __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  char *v18; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v19[4]; // [xsp+1Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = a2;
  v19[0] = 0;
  v16 = 0;
  v17 = 0;
  v5 = qcom_msc_lookup(2);
  if ( v5 )
  {
    v7 = *(_DWORD *)(a1 + 136);
    v6 = *(_DWORD *)(a1 + 140);
    LODWORD(v17) = *(_DWORD *)(v5 + 12);
    HIWORD(v17) = v6;
    WORD2(v17) = v7;
  }
  v18 = strsep(stringp, ",");
  if ( v18 )
  {
    while ( 1 )
    {
      v8 = strsep(&v18, "=");
      if ( !v8 )
        goto LABEL_6;
      v9 = v8;
      if ( !v18 )
        goto LABEL_6;
      if ( (kstrtobool(v18, v19) & 0x80000000) != 0 )
      {
        printk(&unk_7625, v9);
        a3 = -22;
        goto LABEL_50;
      }
      if ( strcmp("cap", v9) )
        break;
      if ( *(_BYTE *)(a1 + 144) != 1 )
        break;
      v10 = v19[0];
      if ( *(unsigned __int8 *)(a1 + 145) == v19[0] )
        break;
      LODWORD(v16) = 0;
LABEL_39:
      HIDWORD(v16) = v10;
      if ( (unsigned int)msc_system_mon_config(2, &v17, &v16) )
      {
        printk(&unk_764F, v9);
        a3 = -16;
        goto LABEL_50;
      }
      if ( (int)v16 > 1 )
      {
        if ( (_DWORD)v16 == 2 )
        {
          *(_BYTE *)(a1 + 149) = v19[0];
        }
        else if ( (_DWORD)v16 == 3 )
        {
          *(_BYTE *)(a1 + 151) = v19[0];
        }
      }
      else if ( (_DWORD)v16 )
      {
        if ( (_DWORD)v16 == 1 )
          *(_BYTE *)(a1 + 147) = v19[0];
      }
      else
      {
        *(_BYTE *)(a1 + 145) = v19[0];
      }
LABEL_6:
      v18 = strsep(stringp, ",");
      if ( !v18 )
        goto LABEL_50;
    }
    if ( !strcmp("miss", v9) && *(_BYTE *)(a1 + 146) == 1 )
    {
      v10 = v19[0];
      if ( *(unsigned __int8 *)(a1 + 147) != v19[0] )
      {
        v14 = 1;
        goto LABEL_38;
      }
    }
    v11 = (unsigned __int8)*v9;
    if ( v11 == 102 )
    {
      v12 = (unsigned __int8)v9[1];
      if ( v12 == 101 )
      {
        if ( !v9[2] )
          goto LABEL_23;
      }
      else if ( 101 == v12 )
      {
        goto LABEL_23;
      }
    }
    else if ( 102 == v11 )
    {
LABEL_23:
      if ( *(_BYTE *)(a1 + 148) != 1 )
        goto LABEL_25;
      v10 = v19[0];
      if ( *(unsigned __int8 *)(a1 + 149) == v19[0] )
        goto LABEL_25;
      v14 = 2;
LABEL_38:
      LODWORD(v16) = v14;
      goto LABEL_39;
    }
LABEL_25:
    if ( v11 == 98 )
    {
      v13 = (unsigned __int8)v9[1];
      if ( v13 == 101 )
      {
        if ( v9[2] )
          goto LABEL_6;
      }
      else if ( 101 != v13 )
      {
        goto LABEL_6;
      }
    }
    else if ( 98 != v11 )
    {
      goto LABEL_6;
    }
    if ( *(_BYTE *)(a1 + 150) != 1 )
      goto LABEL_6;
    v10 = v19[0];
    if ( *(unsigned __int8 *)(a1 + 151) == v19[0] )
      goto LABEL_6;
    v14 = 3;
    goto LABEL_38;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return a3;
}
