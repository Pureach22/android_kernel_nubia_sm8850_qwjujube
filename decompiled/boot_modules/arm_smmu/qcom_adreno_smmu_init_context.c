__int64 __fastcall qcom_adreno_smmu_init_context(__int64 *a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v6; // x19
  __int64 v7; // x9
  __int64 v8; // x10
  unsigned int v9; // w9
  __int64 v10; // x10
  __int16 v11; // t1
  int v12; // w12
  unsigned int v13; // w11
  _QWORD *v15; // x21

  v3 = *a1;
  v6 = *(_QWORD *)(*(_QWORD *)*a1 + 744LL);
  *((_BYTE *)a1 + 68) = 1;
  v7 = *(_QWORD *)(a3 + 824);
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 56);
    v9 = *(_DWORD *)(v8 + 12);
    if ( !v9 )
      return 0;
  }
  else
  {
    v8 = 0;
    v9 = 38140;
  }
  v11 = *(_WORD *)(v8 + 16);
  v10 = v8 + 16;
  if ( (v11 & 0xFFFE) == 0 )
    goto LABEL_12;
  v12 = 1;
  do
  {
    v13 = v12;
    if ( v9 == v12 )
      break;
    ++v12;
  }
  while ( (*(_DWORD *)(v10 + 4LL * (int)v13) & 0xFFFE) != 0 );
  if ( v13 < v9 )
  {
LABEL_12:
    if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)v3 + 744LL), "qcom,msm8996-smmu-v2")
      && !*((_DWORD *)a1 + 18)
      && *((_DWORD *)a1 + 16) == 1 )
    {
      a2[1] |= 0x20uLL;
    }
    v15 = *(_QWORD **)(a3 + 152);
    *v15 = a1;
    v15[1] = qcom_adreno_smmu_get_ttbr1_cfg;
    v15[2] = qcom_adreno_smmu_set_ttbr0_cfg;
    v15[3] = qcom_adreno_smmu_get_fault_info;
    memcpy(v15 + 6, a2, 0x98u);
    if ( of_match_node(&qcom_smmu_impl_of_match, v6) )
    {
      v15[4] = qcom_adreno_smmu_set_stall;
      v15[5] = qcom_adreno_smmu_resume_translation;
    }
  }
  return 0;
}
