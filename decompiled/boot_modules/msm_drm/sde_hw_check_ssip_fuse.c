__int64 __fastcall sde_hw_check_ssip_fuse(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0
  int v6; // w0
  int v7; // w8
  char v8; // w8
  char v9; // w20
  int v10; // w21
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( !a1 || (v2 = *(_QWORD *)(a1 + 8)) == 0 )
  {
    printk(&unk_243912, "sde_hw_check_ssip_fuse");
    result = 4294967274LL;
    goto LABEL_12;
  }
  v3 = a2 + 0x4000;
  if ( *(_BYTE *)(a2 + 20120) == 1 )
    goto LABEL_4;
  v6 = sde_hw_parse_fuse_configuration(v2 - 16, "ssip_config", &v11);
  if ( v6 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "failed to read ssip config for ss_config %d\n", v6);
    goto LABEL_10;
  }
  v7 = HIWORD(*(_DWORD *)a2);
  if ( v7 == 49152 )
  {
    v8 = 1;
  }
  else
  {
    if ( v7 != 53248 )
    {
LABEL_10:
      result = 0;
      *(_BYTE *)(v3 + 3728) = 0;
      goto LABEL_12;
    }
    v8 = 2;
  }
  v9 = v11;
  v10 = (unsigned __int8)v11 >> v8;
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2281BF, v10 & 1);
  else
    printk(&unk_250B53, "sde_hw_check_ssip_fuse");
  if ( (v10 & 1) != 0 )
  {
    if ( (v9 & 1) == 0 )
      goto LABEL_10;
  }
  else if ( (v9 & 1) != 0 )
  {
    goto LABEL_10;
  }
LABEL_4:
  result = 0;
  *(_BYTE *)(v3 + 3728) = 1;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
