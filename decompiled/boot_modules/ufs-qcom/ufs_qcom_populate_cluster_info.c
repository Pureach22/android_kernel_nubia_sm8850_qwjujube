__int64 __fastcall ufs_qcom_populate_cluster_info(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  _QWORD *v3; // x22
  int v4; // w9
  char v5; // w14
  int v6; // w12
  bool v7; // cc
  bool v8; // zf
  unsigned __int64 v9; // x14
  unsigned __int64 v10; // x14
  unsigned int v11; // w15
  int v12; // w12
  int v13; // w8
  char *v14; // x9
  unsigned int v15; // w10
  unsigned __int64 v16; // x20
  __int64 v17; // x0
  unsigned int v18; // w8
  __int64 v19; // x8
  int v20; // w9
  int v21; // w8
  unsigned int v22; // w8
  __int64 v23; // x8
  int v24; // w9
  int v25; // w8
  unsigned int v26; // w8
  __int64 v27; // x8
  int v28; // w9
  int v29; // w8
  unsigned int v30; // w8
  __int64 v31; // x8
  int v32; // w9
  int v33; // w8
  __int64 v34; // x8
  __int64 result; // x0
  __int64 v36; // x1
  __int64 v37; // x8
  __int64 v38; // x9
  unsigned int v39; // w11
  __int64 v40; // x10
  unsigned __int64 StatusReg; // x23
  __int64 v42; // x24
  unsigned int v43; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-18h]
  __int64 v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v42 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ufs_qcom_populate_cluster_info__alloc_tag;
    v16 = 32LL * *(int *)(v2 + 648);
    v17 = _kmalloc_noprof(v16, 3520);
    *(_QWORD *)(StatusReg + 80) = v42;
    if ( v17 )
      goto LABEL_22;
LABEL_60:
    *(_BYTE *)(v2 + 760) = 0;
    result = dev_err(*(_QWORD *)(v1 + 64), "allocating memory for cpufreq info failed\n");
    goto LABEL_55;
  }
  v2 = *(_QWORD *)(a1 + 184);
  v4 = _cpu_possible_mask;
  v1 = a1;
  v5 = 0;
  *(_BYTE *)(v2 + 760) = 1;
  v6 = -1;
  v3 = &cpu_topology;
  v44 = -1;
  v45 = -1;
  do
  {
    v9 = (unsigned int)(-1LL << v5) & v4;
    v8 = (_DWORD)v9 == 0;
    v10 = __clz(__rbit64(v9));
    if ( v8 )
      v10 = 32;
    if ( (unsigned int)v10 >= 0x20 )
      break;
    v11 = *((_DWORD *)&cpu_topology + 12 * (unsigned int)v10 + 2);
    if ( v11 != v6 )
    {
      if ( v11 > 3 )
        goto LABEL_57;
      v12 = *(_DWORD *)(v2 + 648);
      *((_DWORD *)&v44 + v11) = v10;
      *(_DWORD *)(v2 + 648) = v12 + 1;
      v6 = v11;
    }
    v7 = v10 > 0x1E;
    v5 = v10 + 1;
  }
  while ( !v7 );
  v13 = *(_DWORD *)(v2 + 648);
  if ( v13 >= 1 )
  {
    v14 = (char *)&cpu_topology + 48 * (unsigned int)v44;
    if ( v13 == 1 )
    {
      if ( (unsigned int)v44 > 0x1F )
        goto LABEL_57;
      *(_QWORD *)(v2 + 744) = *((_QWORD *)v14 + 4);
    }
    else
    {
      if ( (unsigned int)v44 >= 0x20 )
        goto LABEL_57;
      v15 = HIDWORD(v44);
      v7 = HIDWORD(v44) > 0x1F;
      *(_QWORD *)(v2 + 752) = *((_QWORD *)v14 + 4);
      if ( v7 )
        goto LABEL_57;
      *(_QWORD *)(v2 + 744) |= *((_QWORD *)&cpu_topology + 6 * v15 + 4);
      if ( (unsigned int)v13 >= 3 )
      {
        if ( (unsigned int)v45 > 0x1F )
          goto LABEL_57;
        *(_QWORD *)(v2 + 744) |= *((_QWORD *)&cpu_topology + 6 * (unsigned int)v45 + 4);
        if ( v13 != 3 )
        {
          if ( HIDWORD(v45) > 0x1F )
            goto LABEL_57;
          *(_QWORD *)(v2 + 744) |= *((_QWORD *)&cpu_topology + 6 * HIDWORD(v45) + 4);
          if ( (unsigned int)v13 >= 5 )
            goto LABEL_57;
        }
      }
    }
  }
  v16 = 32LL * *(int *)(v2 + 648);
  v17 = _kmalloc_noprof(v16, 3520);
  if ( !v17 )
    goto LABEL_60;
LABEL_22:
  if ( *(int *)(v2 + 648) < 1 )
    goto LABEL_50;
  if ( !v16 )
LABEL_58:
    __break(1u);
  v18 = v44;
  v7 = (unsigned int)v44 > 0x1F;
  *(_DWORD *)v17 = v44;
  if ( v7 )
    goto LABEL_57;
  v19 = v3[6 * v18 + 4];
  *(_QWORD *)(v17 + 24) = v19;
  v20 = 63 - __clz((unsigned int)v19);
  if ( (_DWORD)v19 )
    v21 = v20;
  else
    v21 = 32;
  *(_DWORD *)(v17 + 4) = v21;
  if ( *(int *)(v2 + 648) < 2 )
    goto LABEL_50;
  if ( v16 == 32 )
    goto LABEL_58;
  v22 = HIDWORD(v44);
  v7 = HIDWORD(v44) > 0x1F;
  *(_DWORD *)(v17 + 32) = HIDWORD(v44);
  if ( v7 )
    goto LABEL_57;
  if ( v16 < 0x38 )
    goto LABEL_58;
  v23 = v3[6 * v22 + 4];
  *(_QWORD *)(v17 + 56) = v23;
  v24 = 63 - __clz((unsigned int)v23);
  if ( (_DWORD)v23 )
    v25 = v24;
  else
    v25 = 32;
  *(_DWORD *)(v17 + 36) = v25;
  if ( *(int *)(v2 + 648) < 3 )
    goto LABEL_50;
  if ( v16 < 0x41 )
    goto LABEL_58;
  v26 = v45;
  v7 = (unsigned int)v45 > 0x1F;
  *(_DWORD *)(v17 + 64) = v45;
  if ( v7 )
  {
LABEL_57:
    __break(0x5512u);
    goto LABEL_58;
  }
  if ( v16 < 0x58 )
    goto LABEL_58;
  v27 = v3[6 * v26 + 4];
  *(_QWORD *)(v17 + 88) = v27;
  v28 = 63 - __clz((unsigned int)v27);
  if ( (_DWORD)v27 )
    v29 = v28;
  else
    v29 = 32;
  *(_DWORD *)(v17 + 68) = v29;
  if ( *(int *)(v2 + 648) >= 4 )
  {
    if ( v16 < 0x61 )
      goto LABEL_58;
    v30 = HIDWORD(v45);
    v7 = HIDWORD(v45) > 0x1F;
    *(_DWORD *)(v17 + 96) = HIDWORD(v45);
    if ( !v7 )
    {
      if ( v16 < 0x78 )
        goto LABEL_58;
      v31 = v3[6 * v30 + 4];
      *(_QWORD *)(v17 + 120) = v31;
      v32 = 63 - __clz((unsigned int)v31);
      if ( (_DWORD)v31 )
        v33 = v32;
      else
        v33 = 32;
      *(_DWORD *)(v17 + 100) = v33;
      if ( *(int *)(v2 + 648) <= 4 )
        goto LABEL_50;
    }
    goto LABEL_57;
  }
LABEL_50:
  v34 = *(_QWORD *)(v2 + 16);
  *(_QWORD *)(v2 + 640) = v17;
  result = *(_QWORD *)(*(_QWORD *)(v34 + 64) + 744LL);
  if ( result )
  {
    v43 = 0;
    result = of_get_property(result, "qcom,cluster-mask", &v43);
    if ( result )
    {
      if ( v43 >= 4 )
      {
        v37 = 0;
        v38 = v43 & 0xFFFFFFFC;
        do
        {
          v39 = *(_DWORD *)(result + v37);
          v40 = *(_QWORD *)(v2 + 640) + 8 * v37;
          v37 += 4;
          *(_QWORD *)(v40 + 16) = bswap32(v39);
        }
        while ( v38 != v37 );
      }
    }
    else
    {
      result = printk(&unk_1A0B5, v36);
      *(_BYTE *)(v2 + 760) = 0;
    }
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
