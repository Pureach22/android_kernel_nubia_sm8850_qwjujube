_QWORD *cam_smmu_page_fault_work()
{
  _QWORD *v0; // x19
  _QWORD *v1; // x8
  __int64 v2; // x9
  unsigned __int64 v3; // x6
  unsigned int v4; // w20
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 *v7; // x25
  __int64 *v8; // x23
  __int64 v9; // x27
  const char *v10; // x13
  unsigned __int64 v11; // x7
  unsigned __int64 v12; // x9
  __int64 v13; // x11
  bool v14; // cc
  const char *v16; // x26
  _QWORD *result; // x0
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x8
  int v20; // w21
  bool v22; // w22
  __int64 v23; // x8
  __int64 v24; // x9
  int v25; // w10
  __int64 v26; // x10
  char v27; // w9
  __int64 v28; // x22
  __int64 v29; // x23
  __int64 v30; // x25
  __int64 v31; // x8
  void (__fastcall *v32)(_QWORD); // x8
  _QWORD *v33; // x0
  unsigned __int64 v34; // [xsp+30h] [xbp-50h]
  __int64 v35; // [xsp+38h] [xbp-48h] BYREF
  __int64 v36; // [xsp+40h] [xbp-40h]
  __int64 v37; // [xsp+48h] [xbp-38h]
  __int64 v38; // [xsp+50h] [xbp-30h]
  __int64 v39; // [xsp+58h] [xbp-28h]
  __int64 v40; // [xsp+60h] [xbp-20h]
  __int64 v41; // [xsp+68h] [xbp-18h]
  __int64 v42; // [xsp+70h] [xbp-10h]
  __int64 v43; // [xsp+78h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  mutex_lock(&unk_394088);
  v0 = (_QWORD *)qword_3940B8;
  if ( (__int64 *)qword_3940B8 == &qword_3940B8 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_page_fault_work",
      692,
      "Payload list empty");
    result = (_QWORD *)mutex_unlock(&unk_394088);
    goto LABEL_50;
  }
  v1 = *(_QWORD **)(qword_3940B8 + 8);
  if ( *v1 == qword_3940B8 && (v2 = *(_QWORD *)qword_3940B8, *(_QWORD *)(*(_QWORD *)qword_3940B8 + 8LL) == qword_3940B8) )
  {
    *(_QWORD *)(v2 + 8) = v1;
    *v1 = v2;
  }
  else
  {
    _list_del_entry_valid_or_report(qword_3940B8);
  }
  *v0 = 0xDEAD000000000100LL;
  v0[1] = 0xDEAD000000000122LL;
  mutex_unlock(&unk_394088);
  cam_check_iommu_faults(*(v0 - 5), (__int64)&v35);
  v3 = *(v0 - 3);
  v4 = *((_DWORD *)v0 - 12);
  if ( v3 )
  {
    v5 = iommu_cb_set;
    v6 = iommu_cb_set + 14280LL * (int)v4;
    v7 = *(__int64 **)(v6 + 8400);
    if ( v7 != (__int64 *)(v6 + 8400) )
    {
      v8 = nullptr;
      v9 = 0;
      v10 = "approx va %lx not in range: %lx-%lx fd = %0x i_ino %lu";
      while ( 1 )
      {
        v11 = *(v7 - 1);
        v12 = v7[4] + v11;
        if ( v11 <= v3 && v12 > v3 )
          break;
        v13 = v11 - v3;
        if ( v11 <= v3 )
          v13 = v3 + ~v12;
        if ( v9 )
          v14 = v13 < v9;
        else
          v14 = 1;
        if ( v14 )
        {
          v9 = v13;
          v8 = v7 - 7;
        }
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          v16 = v10;
          v34 = v3;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_find_closest_mapping",
            873,
            v10);
          v3 = v34;
          v5 = iommu_cb_set;
          v10 = v16;
        }
        v7 = (__int64 *)*v7;
        if ( v7 == (__int64 *)(v5 + 14280LL * (int)v4 + 8400) )
          goto LABEL_26;
      }
      v18 = v3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        3,
        "cam_smmu_find_closest_mapping",
        858,
        "Found va 0x%lx in:0x%lx-0x%lx, fd %d i_ino %lu cb:%s",
        v3,
        v11,
        v12,
        *((_DWORD *)v7 + 4),
        v7[3],
        *(const char **)(v5 + 14280LL * (int)v4 + 32));
      v3 = v18;
      v8 = v7 - 7;
LABEL_26:
      if ( v8 )
      {
        v19 = v8[6];
        v20 = *((_DWORD *)v8 + 18);
        v22 = v19 <= v3 && v8[11] + v19 > v3;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          64,
          3,
          "cam_smmu_find_closest_mapping",
          890,
          "Faulting addr 0x%lx closest map fd %d i_ino %lu %llu-%llu 0x%lx-0x%lx buf=%pK");
        if ( v20 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            3,
            "cam_smmu_page_fault_work",
            712,
            "closest buf 0x%x idx %d",
            v20,
            v4);
        goto LABEL_38;
      }
      v5 = iommu_cb_set;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_find_closest_mapping",
      894,
      "Cannot find vaddr:%lx in SMMU %s virt address",
      v3,
      *(const char **)(v5 + 14280LL * (int)v4 + 32));
  }
  v20 = 0;
  v22 = 0;
LABEL_38:
  v35 = *(v0 - 5);
  v36 = *(v0 - 4);
  v37 = *(v0 - 3);
  v23 = iommu_cb_set;
  v24 = iommu_cb_set + 14280LL * (int)v4;
  v25 = *((_DWORD *)v0 - 4);
  LODWORD(v40) = v20;
  LODWORD(v38) = v25;
  LOBYTE(v25) = *(_BYTE *)(v24 + 80);
  BYTE1(v42) = v22;
  WORD1(v42) = 0;
  LOBYTE(v42) = v25;
  LODWORD(v26) = *(_DWORD *)(v24 + 8584);
  if ( (int)v26 >= 1 )
  {
    v27 = 0;
    v28 = 14280LL * (int)v4 + 8488;
    v29 = -6;
    do
    {
      if ( !v29 )
        __break(0x5512u);
      v30 = v29 + 7;
      if ( *(_QWORD *)(v23 + v28) )
      {
        v31 = v23 + v28;
        BYTE2(v42) = v30 == (unsigned int)v26;
        v39 = *(_QWORD *)(v31 + 48);
        v32 = *(void (__fastcall **)(_QWORD))v31;
        if ( *((_DWORD *)v32 - 1) != 91190575 )
          __break(0x8228u);
        v32(&v35);
        v23 = iommu_cb_set;
        v27 = BYTE3(v42);
      }
      v26 = *(int *)(v23 + 14280LL * (int)v4 + 8584);
      if ( v30 >= v26 )
        break;
      ++v29;
      v28 += 8;
    }
    while ( (v27 & 1) == 0 );
  }
  ((void (__fastcall *)(_QWORD))cam_smmu_dump_cb_info)(v4);
  v33 = v0 - 6;
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v33, 0);
  else
    result = (_QWORD *)kvfree(v33);
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
