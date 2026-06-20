__int64 __fastcall sde_connector_get_modes(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x9
  __int64 (__fastcall *v7)(__int64, __int64, __int64 *); // x8
  __int64 v8; // x1
  __int64 result; // x0
  char v10; // w9
  int v11; // w10
  unsigned int v12; // w20
  int v13; // w11
  int v14; // w8
  int v15; // w10
  __int64 v16; // x9
  __int64 v17; // x8
  unsigned int v18; // w20
  __int64 v19; // x1
  void *v20; // x0
  __int64 v21; // [xsp+0h] [xbp-50h] BYREF
  __int64 v22; // [xsp+8h] [xbp-48h]
  __int64 v23; // [xsp+10h] [xbp-40h]
  __int64 v24; // [xsp+18h] [xbp-38h]
  __int64 v25; // [xsp+20h] [xbp-30h]
  _DWORD v26[3]; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v27; // [xsp+38h] [xbp-18h]
  int v28; // [xsp+40h] [xbp-10h]
  int v29; // [xsp+44h] [xbp-Ch]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  if ( !a1 )
  {
    printk(&unk_242658, "sde_connector_get_modes");
LABEL_30:
    result = 0;
    goto LABEL_31;
  }
  if ( !*(_QWORD *)(a1 + 2904) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "missing get_modes callback\n");
    goto LABEL_30;
  }
  if ( !*(_QWORD *)a1 || (v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v20 = &unk_242658;
LABEL_33:
    printk(v20, "sde_connector_get_kms");
    printk(&unk_234896, "sde_connector_get_avail_res_info");
    goto LABEL_13;
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v20 = &unk_234896;
    goto LABEL_33;
  }
  v4 = *(_QWORD *)(a1 + 2512);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 16)) == 0 )
    v5 = *(_QWORD *)(a1 + 2272);
  sde_rm_get_resource_info((_QWORD *)(v3 + 2144), v5, (__int64)&v21);
  v6 = *(_QWORD *)(v3 + 152);
  if ( (*(_BYTE *)(v6 + 21612) & 1) != 0 && *(_DWORD *)(a1 + 2736) == 10 )
    LODWORD(v22) = *(_DWORD *)(v6 + 10392);
  LODWORD(v24) = *(_DWORD *)(v6 + 21576);
LABEL_13:
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(a1 + 2904);
  v8 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v7 - 1) != 763279165 )
    __break(0x8228u);
  result = v7(a1, v8, &v21);
  if ( !(_DWORD)result )
  {
    printk(&unk_227C39, "sde_connector_get_modes");
    goto LABEL_30;
  }
  if ( *(_BYTE *)(a1 + 4746) == 1 )
  {
    v10 = *(_BYTE *)(a1 + 4644);
    v11 = *(unsigned __int8 *)(a1 + 4660);
    v12 = result;
    v13 = *(_DWORD *)(a1 + 4640);
    v14 = *(unsigned __int8 *)(a1 + 4672);
    v26[0] = 0;
    v26[1] = v11;
    v15 = *(_DWORD *)(a1 + 4656);
    LOBYTE(v26[0]) = v10;
    v16 = *(_QWORD *)(a1 + 4648);
    v26[2] = v13;
    v27 = v16;
    v28 = v15;
    v29 = v14;
    msm_property_set_blob(a1 + 3312, a1 + 4240, v26, 28, 3);
    result = v12;
  }
  if ( *(_DWORD *)(a1 + 2736) == 10 )
  {
    v17 = *(_QWORD *)(a1 + 2512);
    v18 = result;
    if ( v17 )
      v19 = v17 + 448;
    else
      v19 = 0;
    if ( (unsigned int)msm_property_set_property(a1 + 3312, v19, 21, *(unsigned int *)(a1 + 4664)) )
      printk(&unk_257882, "sde_connector_update_colorspace");
    result = v18;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
