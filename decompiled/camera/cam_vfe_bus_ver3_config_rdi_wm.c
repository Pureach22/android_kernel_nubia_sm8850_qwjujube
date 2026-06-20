__int64 __fastcall cam_vfe_bus_ver3_config_rdi_wm(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  _DWORD *v3; // x8
  _DWORD *v4; // x9
  _DWORD *v5; // x10
  int v6; // w20
  __int64 *v7; // x22
  int packer_fmt; // w8
  int v9; // w8
  unsigned int v10; // w9
  unsigned int v11; // w9
  int v12; // w9
  unsigned int v14; // w9
  int v15; // w8
  unsigned int v16; // w10
  unsigned int v17; // w9
  char v18; // w11
  int v19; // w13
  int v20; // w10
  int v21; // w8

  v1 = *a1;
  v2 = *((unsigned int *)a1 + 28);
  v3 = *(_DWORD **)(*a1 + 80);
  *((_DWORD *)a1 + 6) = 0;
  if ( (_DWORD)v2 )
  {
    if ( (_DWORD)v2 != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_vfe_bus_ver3_config_rdi_wm",
        922,
        "No index mode %d is supported for VFE: %u  WM: %u",
        v2,
        *(_DWORD *)(v1 + 8),
        *((_DWORD *)a1 + 30));
      return 0;
    }
    a1[2] = 0xFFFF;
    *((_DWORD *)a1 + 8) = 0xFFFF;
    v4 = *(_DWORD **)(v1 + 80);
    v5 = v4 + 26;
  }
  else
  {
    v5 = v3 + 25;
    v4 = v3;
  }
  v6 = *((_DWORD *)a1 + 7);
  *((_DWORD *)a1 + 11) = (1 << v4[28]) | (*v5 << v4[24]);
  switch ( v6 )
  {
    case 1:
      if ( (_DWORD)v2 )
        return 0;
      v14 = 3 * *((_DWORD *)a1 + 4);
      goto LABEL_56;
    case 2:
    case 34:
      if ( (_DWORD)v2 )
        return 0;
      v11 = *((_DWORD *)a1 + 4);
      goto LABEL_57;
    case 3:
      if ( *((_BYTE *)a1 + 162) == 1 )
      {
        if ( !(_DWORD)v2 )
          *((_DWORD *)a1 + 4) = (*((_DWORD *)a1 + 4) + 7) & 0xFFFFFFF8;
        v12 = 12;
        goto LABEL_38;
      }
      if ( (_DWORD)v2 )
        return 0;
      v14 = 5 * *((_DWORD *)a1 + 4);
      goto LABEL_56;
    case 4:
      if ( *((_BYTE *)a1 + 162) == 1 )
      {
        if ( !(_DWORD)v2 )
          *((_DWORD *)a1 + 4) = (*((_DWORD *)a1 + 4) + 7) & 0xFFFFFFF8;
        v12 = 13;
        goto LABEL_38;
      }
      if ( (_DWORD)v2 )
        return 0;
      v11 = (unsigned int)(3 * *((_DWORD *)a1 + 4)) >> 1;
      goto LABEL_57;
    case 5:
      if ( *((_BYTE *)a1 + 162) == 1 )
      {
        if ( !(_DWORD)v2 )
          *((_DWORD *)a1 + 4) = (*((_DWORD *)a1 + 4) + 7) & 0xFFFFFFF8;
        v12 = 14;
        goto LABEL_38;
      }
      if ( (_DWORD)v2 )
        return 0;
      v14 = 7 * *((_DWORD *)a1 + 4);
LABEL_56:
      v11 = v14 >> 2;
      goto LABEL_57;
    case 6:
      if ( (_DWORD)v2 )
        return 0;
      v11 = 2 * *((_DWORD *)a1 + 4);
      goto LABEL_57;
    case 7:
      if ( *((_BYTE *)a1 + 162) == 1 )
      {
        if ( !(_DWORD)v2 )
          *((_DWORD *)a1 + 4) = (*((_DWORD *)a1 + 4) + 7) & 0xFFFFFFF8;
        v12 = 15;
LABEL_38:
        *((_DWORD *)a1 + 6) = v12;
      }
      else if ( !(_DWORD)v2 )
      {
        v11 = (unsigned int)(5 * *((_DWORD *)a1 + 4)) >> 1;
LABEL_57:
        v17 = (v11 + 15) >> 4;
LABEL_58:
        *((_DWORD *)a1 + 4) = v17;
      }
      return 0;
    case 12:
      v18 = v3[24];
      v19 = *((_DWORD *)a1 + 4);
      v20 = v3[v2 + 25];
      v21 = 1 << v3[28];
      *((_DWORD *)a1 + 8) = v19;
      v15 = v21 | (v20 << v18);
      v16 = (unsigned int)(v19 + 15) >> 4;
      goto LABEL_46;
    case 14:
    case 15:
    case 16:
    case 17:
    case 49:
      if ( *((_BYTE *)a1 + 162) != 1 )
      {
        if ( !(_DWORD)v2 )
        {
          v10 = (unsigned int)(2 * *((_DWORD *)a1 + 4) + 15) >> 4;
          v9 = 0;
          goto LABEL_48;
        }
        v9 = 0;
LABEL_12:
        if ( v6 != 49 )
          return 0;
        goto LABEL_49;
      }
      v7 = a1;
      packer_fmt = cam_vfe_bus_ver3_get_packer_fmt(v6, *((_DWORD *)a1 + 30));
      *((_DWORD *)v7 + 6) = packer_fmt;
      a1 = v7;
      v9 = (1 << *(_DWORD *)(v1 + 34716)) | packer_fmt;
      *((_DWORD *)v7 + 6) = v9;
      if ( (_DWORD)v2 )
        goto LABEL_12;
      v10 = (*((_DWORD *)v7 + 4) + 7) & 0xFFFFFFF8;
LABEL_48:
      *((_DWORD *)a1 + 4) = v10;
      if ( v6 != 49 )
        return 0;
LABEL_49:
      *((_DWORD *)a1 + 6) = v9 | (1 << *(_DWORD *)(v1 + 34716));
      return 0;
    case 18:
      if ( (_DWORD)v2 )
        return 0;
      v11 = 4 * *((_DWORD *)a1 + 4);
      goto LABEL_57;
    case 19:
      *((_DWORD *)a1 + 4) = (unsigned int)(8 * *((_DWORD *)a1 + 4) + 15) >> 4;
      *((_DWORD *)a1 + 11) = (1 << v3[28]) | (v3[25] << v3[24]);
      return 0;
    case 20:
      if ( (_DWORD)v2 )
        return 0;
      v17 = a1[2] & 0xFFFFFFF;
      goto LABEL_58;
    case 50:
      if ( (_DWORD)v2 )
        return 0;
      v15 = (1 << v3[28]) | (v3[25] << v3[24]);
      v16 = (((unsigned int)(5 * *((_DWORD *)a1 + 4)) >> 2) + 15) >> 4;
LABEL_46:
      *((_DWORD *)a1 + 11) = v15;
      *((_DWORD *)a1 + 4) = v16;
      return 0;
    default:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_config_rdi_wm",
        1033,
        "VFE:%u Unsupported RDI format %d",
        *(_DWORD *)(v1 + 8),
        v6);
      return 4294967274LL;
  }
}
