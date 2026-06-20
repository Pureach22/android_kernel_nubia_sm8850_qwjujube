const char *__fastcall sde_get_sde_format_ext(int a1, __int64 a2)
{
  const char *v3; // x8
  unsigned int v4; // w9
  unsigned __int64 v5; // x10
  unsigned __int64 v6; // x11
  unsigned int v7; // w13
  const char *v8; // x20
  const char *v9; // x8
  unsigned int v10; // w6
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a1;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "plane format modifier 0x%llX\n", a2);
  if ( a2 > 0x5000000000000FFLL )
  {
    if ( a2 == 0x500000000000100LL )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "found cac fmt: %4.4s DRM_FORMAT_MOD_QCOM_CAC_B\n", (const char *)&v12);
      v3 = "AB24";
LABEL_47:
      v4 = 2;
      v5 = 96;
    }
    else
    {
      if ( a2 != 0x500000000000201LL )
      {
LABEL_63:
        printk(&unk_23CC23, "sde_get_sde_format_ext");
        goto LABEL_61;
      }
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_LOSSY_2_1\n", (const char *)&v12);
      v3 = "AB24";
LABEL_43:
      v4 = 1;
      v5 = 48;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 0x500000000000001LL:
      case 0x500000000000009LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s  DRM_FORMAT_MOD_QCOM_COMPRESSED\n", (const char *)&v12);
        v3 = "BG16";
        v4 = 7;
        v5 = 336;
        break;
      case 0x500000000000002LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_DX\n", (const char *)&v12);
        v3 = (const char *)&sde_format_map_yuv10bit;
        goto LABEL_47;
      case 0x500000000000003LL:
      case 0x50000000000000BLL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_COMPRESSED/DX\n", (const char *)&v12);
        v3 = (const char *)&sde_format_map_yuv10bit_ubwc;
        goto LABEL_47;
      case 0x500000000000004LL:
      case 0x500000000000005LL:
      case 0x500000000000006LL:
      case 0x50000000000000CLL:
      case 0x50000000000000DLL:
      case 0x500000000000011LL:
      case 0x500000000000012LL:
      case 0x500000000000013LL:
      case 0x500000000000014LL:
      case 0x500000000000015LL:
      case 0x500000000000016LL:
      case 0x500000000000017LL:
      case 0x500000000000018LL:
      case 0x500000000000019LL:
      case 0x50000000000001ALL:
      case 0x50000000000001BLL:
      case 0x50000000000001CLL:
      case 0x50000000000001DLL:
      case 0x50000000000001ELL:
      case 0x50000000000001FLL:
      case 0x500000000000020LL:
      case 0x500000000000022LL:
      case 0x500000000000023LL:
      case 0x500000000000024LL:
      case 0x500000000000025LL:
      case 0x500000000000026LL:
      case 0x500000000000027LL:
      case 0x500000000000028LL:
      case 0x500000000000029LL:
      case 0x50000000000002ALL:
      case 0x50000000000002BLL:
      case 0x50000000000002CLL:
      case 0x50000000000002DLL:
      case 0x50000000000002ELL:
      case 0x50000000000002FLL:
      case 0x500000000000030LL:
      case 0x500000000000031LL:
      case 0x500000000000032LL:
      case 0x500000000000033LL:
      case 0x500000000000034LL:
      case 0x500000000000035LL:
      case 0x500000000000036LL:
      case 0x500000000000037LL:
      case 0x500000000000038LL:
      case 0x500000000000039LL:
      case 0x50000000000003ALL:
      case 0x50000000000003BLL:
      case 0x50000000000003CLL:
      case 0x50000000000003DLL:
      case 0x50000000000003ELL:
      case 0x50000000000003FLL:
      case 0x500000000000041LL:
      case 0x500000000000042LL:
      case 0x500000000000043LL:
      case 0x500000000000044LL:
      case 0x500000000000045LL:
      case 0x500000000000046LL:
      case 0x500000000000047LL:
      case 0x500000000000048LL:
      case 0x500000000000049LL:
      case 0x50000000000004ALL:
      case 0x50000000000004BLL:
      case 0x50000000000004CLL:
      case 0x50000000000004DLL:
      case 0x50000000000004ELL:
      case 0x50000000000004FLL:
      case 0x500000000000050LL:
      case 0x500000000000051LL:
      case 0x500000000000052LL:
      case 0x500000000000053LL:
      case 0x500000000000054LL:
      case 0x500000000000055LL:
      case 0x500000000000056LL:
      case 0x500000000000057LL:
      case 0x500000000000058LL:
      case 0x500000000000059LL:
      case 0x50000000000005ALL:
      case 0x50000000000005BLL:
      case 0x50000000000005CLL:
      case 0x50000000000005DLL:
      case 0x50000000000005ELL:
      case 0x50000000000005FLL:
      case 0x500000000000060LL:
      case 0x500000000000061LL:
      case 0x500000000000062LL:
      case 0x500000000000063LL:
      case 0x500000000000064LL:
      case 0x500000000000065LL:
      case 0x500000000000066LL:
      case 0x500000000000067LL:
      case 0x500000000000068LL:
      case 0x500000000000069LL:
      case 0x50000000000006ALL:
      case 0x50000000000006BLL:
      case 0x50000000000006CLL:
      case 0x50000000000006DLL:
      case 0x50000000000006ELL:
      case 0x50000000000006FLL:
      case 0x500000000000070LL:
      case 0x500000000000071LL:
      case 0x500000000000072LL:
      case 0x500000000000073LL:
      case 0x500000000000074LL:
      case 0x500000000000075LL:
      case 0x500000000000076LL:
      case 0x500000000000077LL:
      case 0x500000000000078LL:
      case 0x500000000000079LL:
      case 0x50000000000007ALL:
      case 0x50000000000007BLL:
      case 0x50000000000007CLL:
      case 0x50000000000007DLL:
      case 0x50000000000007ELL:
      case 0x50000000000007FLL:
        goto LABEL_63;
      case 0x500000000000007LL:
      case 0x50000000000000FLL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_COMPRESSED/DX/TIGHT\n", (const char *)&v12);
        v3 = (const char *)&sde_format_map_tp10_ubwc;
        goto LABEL_43;
      case 0x500000000000008LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_TILE\n", (const char *)&v12);
        v3 = "BG16";
        v4 = 13;
        v5 = 624;
        break;
      case 0x50000000000000ALL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_TILE/DX\n", (const char *)&v12);
        v3 = (const char *)&sde_format_map_p010_tile;
        goto LABEL_43;
      case 0x50000000000000ELL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_TILE/DX/TIGHT\n", (const char *)&v12);
        v3 = (const char *)&sde_format_map_tp10_tile;
        goto LABEL_43;
      case 0x500000000000010LL:
        v3 = "AR4H";
        goto LABEL_47;
      case 0x500000000000021LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found fmt: %4.4s DRM_FORMAT_MOD_QCOM_LOSSY_8_5\n", (const char *)&v12);
        v3 = "AB24";
        goto LABEL_43;
      case 0x500000000000040LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found cac fmt: %4.4s DRM_FORMAT_MOD_QCOM_CAC_R\n", (const char *)&v12);
        v3 = "AB24";
        goto LABEL_47;
      case 0x500000000000080LL:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found cac fmt: %4.4s DRM_FORMAT_MOD_QCOM_CAC_G\n", (const char *)&v12);
        v3 = "AB24";
        goto LABEL_47;
      default:
        if ( a2 )
          goto LABEL_63;
        v3 = "AR24";
        v4 = 49;
        v5 = 2352;
        break;
    }
  }
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    if ( v5 <= v6 )
      goto LABEL_64;
    if ( v12 == *(_DWORD *)&v3[v6] )
      break;
    ++v7;
    v6 += 48LL;
    if ( v4 <= v7 )
      goto LABEL_60;
  }
  v8 = &v3[v6];
  if ( !&v3[v6] )
  {
LABEL_60:
    printk(&unk_26D954, "sde_get_sde_format_ext");
LABEL_61:
    v8 = nullptr;
    goto LABEL_62;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v5 < v6 + 28 )
LABEL_64:
      __break(1u);
    v9 = &v3[v6];
    if ( *((_DWORD *)v9 + 7) == 2 )
      v10 = ((unsigned int)*((_QWORD *)v9 + 4) >> 2) & 1;
    else
      v10 = 0;
    _drm_dev_dbg(0, 0, 0, "fmt %4.4s mod 0x%llX ubwc %d yuv %d\n", (const char *)&v12, a2, v10, *((_QWORD *)v9 + 4) & 1);
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return v8;
}
