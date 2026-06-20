__int64 __fastcall dspp_ltm(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  unsigned int v3; // w10
  __int64 (__fastcall *v4)(__int64, _DWORD *, char, __int64); // x12
  __int64 (__fastcall *v5)(); // x11
  __int64 (__fastcall *v6)(__int64); // x10
  void *v7; // x9
  int v8; // w9
  size_t (__fastcall *v9)(int *, _QWORD *, double, double, double, double); // x9
  char v10; // w8

  if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 392LL) - 0x10000) <= 4 )
  {
    v1 = result;
    result = ((__int64 (__fastcall *)(__int64, __int64))reg_dmav1_init_ltm_op_v6)(1, result);
    if ( (_DWORD)result )
      goto LABEL_16;
    result = ((__int64 (__fastcall *)(__int64, __int64))reg_dmav1_init_ltm_op_v6)(2, v1);
    if ( (_DWORD)result )
      goto LABEL_16;
    result = ((__int64 (__fastcall *)(__int64, __int64))reg_dmav1_init_ltm_op_v6)(3, v1);
    if ( (_DWORD)result )
      goto LABEL_16;
    v2 = *(_QWORD *)(v1 + 72);
    v3 = *(_DWORD *)(*(_QWORD *)(v2 + 48) + 392LL) - 65538;
    if ( v3 > 2 )
    {
      v6 = sde_ltm_clear_merge_mode;
      v4 = sde_setup_dspp_ltm_hist_ctrlv1;
      v5 = (__int64 (__fastcall *)())reg_dmav1_setup_ltm_vlutv1;
    }
    else
    {
      v4 = sde_setup_dspp_ltm_hist_ctrlv1_2;
      v5 = off_28B9F8[v3];
      v6 = sde_ltm_clear_merge_modev1_2;
    }
    *(_QWORD *)(v1 + 640) = v5;
    *(_QWORD *)(v1 + 664) = v4;
    *(_QWORD *)(v1 + 760) = v6;
    if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 48) + 392LL) - 65539) > 1 )
    {
      v7 = reg_dmav1_setup_ltm_roiv1;
    }
    else
    {
      *(_QWORD *)(v1 + 568) = sde_validate_ltm_roiv1_3;
      v7 = reg_dmav1_setup_ltm_roiv1_3;
    }
    *(_QWORD *)(v1 + 616) = v7;
    v8 = *(_DWORD *)(*(_QWORD *)(v2 + 48) + 392LL);
    *(_QWORD *)(v1 + 712) = sde_setup_dspp_ltm_threshv1;
    *(_QWORD *)(v1 + 688) = sde_setup_dspp_ltm_hist_bufferv1;
    v9 = v8 == 65540
       ? reg_dmav1_setup_ltm_initv1_4
       : (size_t (__fastcall *)(int *, _QWORD *, double, double, double, double))reg_dmav1_setup_ltm_initv1;
    *(_QWORD *)(v1 + 592) = v9;
    *(_QWORD *)(v1 + 736) = sde_ltm_read_intr_status;
    if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 48) + 392LL) - 65537) >= 4 )
LABEL_16:
      v10 = 0;
    else
      v10 = 1;
    *(_BYTE *)(v1 + 81) = v10;
  }
  return result;
}
