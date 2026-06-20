__int64 __fastcall cam_smmu_get_region_info(int a1, int a2, _QWORD *a3)
{
  unsigned int v4; // w19
  __int64 v8; // x0
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 v11; // x10
  _QWORD *v12; // x9
  const char *v13; // x5
  __int64 v14; // x4
  __int64 result; // x0
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 v18; // x10
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x10
  const char *v23; // x5
  __int64 v24; // x2
  __int64 v25; // x4
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( !a3 )
  {
    v13 = "Invalid params";
    v14 = 2259;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_region_info",
      v14,
      v13);
    goto LABEL_16;
  }
  if ( a1 == -1 )
  {
    v13 = "Invalid handle";
    v14 = 2264;
    goto LABEL_14;
  }
  v4 = HIWORD(a1) & 0xFFF;
  if ( v4 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_region_info",
      2272,
      "Handle or index invalid. idx = %d hdl = %x",
      v4,
      a1);
    goto LABEL_16;
  }
  if ( (unsigned int)cam_smmu_get_multiregion_client_dev_idx(iommu_cb_set + 14280LL * v4, a1 >> 28, a2, &v31) )
  {
LABEL_16:
    result = 4294967274LL;
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v8 = mutex_lock(iommu_cb_set + 14280LL * v4 + 8432);
  v9 = iommu_cb_set + 14280LL * v4;
  if ( !v9 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_region_info",
      2283,
      "SMMU context bank pointer invalid");
LABEL_19:
    mutex_unlock(iommu_cb_set + 14280LL * v4 + 8432);
    goto LABEL_16;
  }
  if ( a2 <= 2 )
  {
    v10 = a3;
    if ( a2 )
    {
      if ( a2 != 1 )
      {
        if ( a2 == 2 )
        {
          if ( *(_BYTE *)(v9 + 81) )
          {
            v11 = *(_QWORD *)(v9 + 160);
            v12 = (_QWORD *)(v9 + 168);
            goto LABEL_44;
          }
          v23 = "Scratch memory not supported";
          v24 = 1;
          v25 = 2321;
LABEL_53:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            v24,
            "cam_smmu_get_region_info",
            v25,
            v23);
          mutex_unlock(iommu_cb_set + 14280LL * v4 + 8432);
          result = 4294967277LL;
          goto LABEL_17;
        }
        goto LABEL_33;
      }
      if ( !*(_BYTE *)(v9 + 83) )
      {
        v23 = "Shared mem not supported";
        v24 = 1;
        v25 = 2308;
        goto LABEL_53;
      }
      if ( v31 <= 2 )
      {
        v21 = v9 + 672LL * v31;
        v11 = *(_QWORD *)(v21 + 2232);
        v12 = (_QWORD *)(v21 + 2240);
        goto LABEL_44;
      }
    }
    else
    {
      if ( !*(_BYTE *)(v9 + 82) )
      {
        v23 = "Firmware not supported";
        v24 = 1;
        v25 = 2293;
        goto LABEL_53;
      }
      if ( v31 < 3 )
      {
        v19 = v9 + 672LL * v31;
        v11 = *(_QWORD *)(v19 + 880);
        v12 = (_QWORD *)(v19 + 888);
        goto LABEL_44;
      }
    }
    goto LABEL_54;
  }
  v10 = a3;
  if ( a2 <= 5 )
  {
    if ( a2 != 3 )
    {
      if ( a2 == 4 )
      {
        if ( *(_BYTE *)(v9 + 85) )
        {
          v11 = *(_QWORD *)(v9 + 224);
          v12 = (_QWORD *)(v9 + 232);
LABEL_44:
          *v10 = v11;
          goto LABEL_45;
        }
        v23 = "Secondary heap not supported";
        v24 = 1;
        v25 = 2346;
        goto LABEL_53;
      }
      goto LABEL_33;
    }
    if ( !*(_BYTE *)(v9 + 84) )
    {
      v23 = "IO memory not supported";
      v24 = 1;
      v25 = 2333;
      goto LABEL_53;
    }
    if ( v31 <= 2 )
    {
      v20 = v9 + 672LL * v31;
      v11 = *(_QWORD *)(v20 + 3584);
      v12 = (_QWORD *)(v20 + 3592);
      goto LABEL_44;
    }
    goto LABEL_54;
  }
  if ( a2 == 6 )
  {
    if ( !*(_BYTE *)(v9 + 86) )
    {
      v23 = "FW uncached region not supported";
      v24 = 2;
      v25 = 2358;
      goto LABEL_53;
    }
    if ( v31 > 2 )
      goto LABEL_54;
    v16 = v9 + 672LL * v31;
    v17 = 4944;
    v18 = *(_QWORD *)(v16 + 4936);
LABEL_40:
    *a3 = v18;
    v12 = (_QWORD *)(v16 + v17);
LABEL_45:
    v22 = iommu_cb_set + 14280LL * v4;
    v10[1] = *v12;
    mutex_unlock(v22 + 8432);
    result = 0;
    goto LABEL_17;
  }
  if ( a2 != 7 )
  {
LABEL_33:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_region_info",
      2386,
      "Invalid region id: %d for smmu hdl: %X",
      (unsigned int)a1);
    goto LABEL_19;
  }
  if ( !*(_BYTE *)(v9 + 88) )
  {
    v23 = "device memory region not supported";
    v24 = 2;
    v25 = 2373;
    goto LABEL_53;
  }
  if ( v31 <= 2 )
  {
    v16 = v9 + 672LL * v31;
    v17 = 6296;
    v18 = *(_QWORD *)(v16 + 6288);
    goto LABEL_40;
  }
LABEL_54:
  __break(0x5512u);
  __asm { LDTRH           W6, [X27,#0x40] }
  return cam_smmu_reserve_buf_region(v8);
}
