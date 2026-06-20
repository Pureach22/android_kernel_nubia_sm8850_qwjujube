__int64 __fastcall tz_get_target_freq(_QWORD *a1, _QWORD *a2)
{
  __int64 v2; // x25
  _DWORD *v4; // x8
  __int64 v5; // x0
  unsigned int v7; // w0
  __int64 *v8; // x26
  __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned int *v11; // x8
  unsigned int v12; // w22
  unsigned __int64 v13; // x9
  unsigned int *v14; // x11
  __int64 v15; // x23
  __int64 v16; // x24
  unsigned int v17; // w21
  __int64 v19; // x9
  int v20; // w8
  __int64 v21; // x9
  int v22; // w22
  int updated; // w0
  __int64 v24; // x8
  __int64 v25; // x9

  v2 = a1[148];
  if ( !v2 )
    return 0;
  v4 = *(_DWORD **)(a1[122] + 24LL);
  if ( !v4 )
  {
    v17 = -22;
LABEL_30:
    printk(&unk_6E44);
    return v17;
  }
  v5 = a1[20];
  if ( *(v4 - 1) != -517377599 )
    __break(0x8228u);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD *))v4)(v5, a1 + 144);
  if ( v7 )
  {
    v17 = v7;
    goto LABEL_30;
  }
  *a2 = a1[146];
  v8 = (__int64 *)(v2 + 24);
  v9 = *(unsigned int *)(v2 + 152);
  *(_QWORD *)(v2 + 24) += a1[144];
  v10 = a1[145] * v9 / 0x64uLL;
  if ( v10 >= a1[144] )
    v10 = a1[144];
  a1[145] = v10;
  *(_QWORD *)(v2 + 32) += v10;
  v11 = (unsigned int *)a1[147];
  if ( v11 )
    v12 = *v11;
  else
    v12 = 0;
  raw_spin_lock(&sample_lock);
  v13 = a1[146] * a1[145];
  v14 = *(unsigned int **)(a1[122] + 48LL);
  acc_total += a1[144];
  acc_relative_busy += v13 / *v14;
  raw_spin_unlock(&sample_lock);
  if ( !a1[144] )
    return 0;
  v15 = *v8;
  if ( *v8 < 5000 )
    return 0;
  v16 = *(_QWORD *)(v2 + 32);
  if ( (unsigned int)v16 < 0x3E8 )
    return 0;
  v19 = a1[122];
  v20 = *(_DWORD *)(v19 + 56);
  if ( !v20 )
  {
LABEL_20:
    v17 = -22;
LABEL_32:
    printk(&unk_6D00);
    return v17;
  }
  v21 = *(_QWORD *)(v19 + 48);
  v17 = 0;
  while ( *(_QWORD *)(v21 + 8LL * (int)v17) != a1[146] )
  {
    if ( v20 == ++v17 )
      goto LABEL_20;
  }
  if ( (v17 & 0x80000000) != 0 )
    goto LABEL_32;
  if ( v16 < 50001 || (*(_BYTE *)(v2 + 149) & 1) != 0 )
  {
    __dmb(2u);
    if ( (*(_BYTE *)(v2 + 148) & 1) != 0 )
    {
      if ( (*(_BYTE *)(v2 + 150) & 1) != 0 )
        updated = qcom_scm_dcvs_update_ca_v2(v17, v15, v16, v12);
      else
        updated = qcom_scm_dcvs_update_v2(v17, v15, v16);
      v22 = updated;
    }
    else
    {
      raw_spin_lock(&tz_lock);
      v22 = qcom_scm_dcvs_update(v17, v15, v16);
      raw_spin_unlock(&tz_lock);
    }
  }
  else
  {
    v22 = -v17;
  }
  *v8 = 0;
  *(_QWORD *)(v2 + 32) = 0;
  v24 = a1[122];
  if ( v22 )
  {
    LODWORD(v25) = (v22 + v17) & ~((int)(v22 + v17) >> 31);
    if ( (int)v25 >= *(_DWORD *)(v24 + 56) - 1 )
      LODWORD(v25) = *(_DWORD *)(v24 + 56) - 1;
    v25 = (int)v25;
  }
  else
  {
    v25 = (int)v17;
  }
  v17 = 0;
  *a2 = *(_QWORD *)(*(_QWORD *)(v24 + 48) + 8 * v25);
  return v17;
}
