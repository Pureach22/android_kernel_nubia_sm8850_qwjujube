__int64 __fastcall msm_vidc_init_core_caps(__int64 a1)
{
  __int64 v1; // x10
  unsigned int *v2; // x8
  int v3; // w11
  __int64 v4; // x9
  int v5; // w10
  bool v6; // vf
  int v7; // w11
  int v8; // w12
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x13
  __int64 v12; // x13
  __int64 v13; // x14
  unsigned int v14; // w8
  int v15; // w10
  unsigned int *v16; // x9
  __int64 v17; // x10
  __int64 v18; // x11
  unsigned int v19; // t1

  v1 = *(_QWORD *)(a1 + 3912);
  v2 = *(unsigned int **)(v1 + 208);
  if ( !v2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_84E75, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_core_caps");
    return (unsigned int)-22;
  }
  v3 = *(_DWORD *)(v1 + 216);
  v4 = *(_QWORD *)(v1 + 224);
  v5 = *(_DWORD *)(v1 + 232);
  v6 = __OFSUB__(v3, 1);
  v7 = v3 - 1;
  if ( v7 < 0 == v6 )
  {
    if ( (unsigned int)v7 >= 0x31 )
      v8 = 49;
    else
      v8 = v7;
    v9 = a1 + 3944;
    v10 = (unsigned int)(v8 + 1);
    do
    {
      v11 = *v2;
      if ( (unsigned int)v11 >= 0x33 )
        goto LABEL_22;
      *(_DWORD *)(v9 + 16 * v11) = v11;
      v12 = *v2;
      if ( (unsigned int)v12 > 0x32 )
        goto LABEL_22;
      v13 = v2[1];
      --v10;
      v2 += 2;
      *(_QWORD *)(v9 + 16 * v12 + 8) = v13;
    }
    while ( v10 );
  }
  v14 = 0;
  if ( !v4 )
    return v14;
  v6 = __OFSUB__(v5, 1);
  v15 = v5 - 1;
  if ( v15 < 0 != v6 )
    return v14;
  v16 = (unsigned int *)(v4 + 4);
  if ( (unsigned int)v15 >= 0x31 )
    v15 = 49;
  v2 = (unsigned int *)(a1 + 3944);
  v17 = (unsigned int)(v15 + 1);
  while ( 1 )
  {
    v18 = *(v16 - 1);
    if ( (unsigned int)v18 > 0x32 )
      break;
    v19 = *v16;
    v16 += 2;
    --v17;
    *(_QWORD *)&v2[4 * v18 + 2] = v19;
    if ( !v17 )
      return 0;
  }
LABEL_22:
  __break(0x5512u);
  __arm_mte_increment_tag(v2 + 180, 3u);
  return msm_vidc_init_instance_caps(a1);
}
