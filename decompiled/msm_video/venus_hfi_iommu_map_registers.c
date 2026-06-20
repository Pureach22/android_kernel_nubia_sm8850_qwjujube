__int64 __fastcall venus_hfi_iommu_map_registers(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned __int64 device_region_info; // x0
  unsigned int v7; // w8
  __int64 v8; // x9
  unsigned int (__fastcall *v9)(__int64, __int64 *); // x9
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // [xsp+0h] [xbp-80h] BYREF
  __int64 v21; // [xsp+8h] [xbp-78h]
  __int64 v22; // [xsp+10h] [xbp-70h]
  __int64 v23; // [xsp+18h] [xbp-68h]
  __int64 v24; // [xsp+20h] [xbp-60h]
  __int64 v25; // [xsp+28h] [xbp-58h]
  __int64 v26; // [xsp+30h] [xbp-50h]
  __int64 v27; // [xsp+38h] [xbp-48h]
  __int64 v28; // [xsp+40h] [xbp-40h]
  __int64 v29; // [xsp+48h] [xbp-38h]
  __int64 v30; // [xsp+50h] [xbp-30h]
  __int64 v31; // [xsp+58h] [xbp-28h]
  __int64 v32; // [xsp+60h] [xbp-20h]
  __int64 v33; // [xsp+68h] [xbp-18h]
  __int64 v34; // [xsp+70h] [xbp-10h]
  __int64 v35; // [xsp+78h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v20 = 0;
    device_region_info = venus_hfi_get_device_region_info(a1, a2);
    if ( device_region_info )
    {
      HIDWORD(v22) = 2;
      v33 = *(_QWORD *)(device_region_info + 8);
      LODWORD(v23) = *(_DWORD *)(device_region_info + 16);
      v7 = *(_DWORD *)(device_region_info + 20);
      v28 = v7;
      if ( a1 )
      {
        v8 = *(_QWORD *)(a1 + 6568);
        if ( v8 )
        {
          v9 = *(unsigned int (__fastcall **)(__int64, __int64 *))(v8 + 96);
          if ( v9 )
          {
            if ( *((_DWORD *)v9 - 1) != 481270700 )
              __break(0x8229u);
            if ( v9(a1, &v20) )
            {
              if ( (msm_vidc_debug & 1) != 0 )
              {
                device_region_name(a2);
                printk(&unk_8D1B9, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_iommu_map_registers");
              }
              result = 4294967284LL;
              goto LABEL_20;
            }
            v7 = v28;
          }
        }
      }
      *(_DWORD *)a3 = v7;
      v11 = v33;
      v12 = v34;
      result = 0;
      *(_QWORD *)(a3 + 120) = v32;
      *(_QWORD *)(a3 + 128) = v11;
      v13 = v28;
      v14 = v29;
      *(_QWORD *)(a3 + 136) = v12;
      *(_QWORD *)(a3 + 88) = v13;
      *(_QWORD *)(a3 + 96) = v14;
      v15 = v31;
      *(_QWORD *)(a3 + 104) = v30;
      *(_QWORD *)(a3 + 112) = v15;
      v16 = v25;
      *(_QWORD *)(a3 + 56) = v24;
      *(_QWORD *)(a3 + 64) = v16;
      v17 = v27;
      *(_QWORD *)(a3 + 72) = v26;
      *(_QWORD *)(a3 + 80) = v17;
      v18 = v21;
      *(_QWORD *)(a3 + 24) = v20;
      *(_QWORD *)(a3 + 32) = v18;
      v19 = v23;
      *(_QWORD *)(a3 + 40) = v22;
      *(_QWORD *)(a3 + 48) = v19;
      goto LABEL_20;
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_94FB8, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_iommu_map_registers");
    result = 0;
  }
  else
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_83321, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_iommu_map_registers");
    result = 4294967274LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
