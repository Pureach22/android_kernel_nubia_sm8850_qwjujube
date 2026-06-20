__int64 __fastcall gen8_gmu_snapshot(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x24
  unsigned __int64 v6; // x25
  unsigned int *v7; // x22
  __int64 v8; // x26
  __int64 v9; // x27
  int v10; // w8
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned int v13; // w10
  __int64 v14; // x9
  unsigned int v15; // w22
  unsigned int v16; // w23
  int v17; // w10
  __int64 v18; // x26
  _DWORD *v19; // x27
  unsigned int v21; // w28
  __int64 v22; // x9
  unsigned __int64 v23; // x10
  unsigned int v24; // w8
  int v25; // w8
  unsigned int v26; // w9
  char v27; // w10
  __int64 result; // x0
  _DWORD *v29; // [xsp+0h] [xbp-40h] BYREF
  __int64 v30; // [xsp+8h] [xbp-38h]
  __int64 v31; // [xsp+10h] [xbp-30h]
  __int64 v32; // [xsp+18h] [xbp-28h]
  __int64 v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h] BYREF
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  gen8_snapshot_external_core_regs();
  v4 = (_QWORD *)to_gen8_gmu(a1);
  v5 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 192LL);
  v6 = *(unsigned int *)(a1 + 24612);
  v32 = 0;
  v33 = 0;
  v7 = (unsigned int *)v5[15];
  v30 = 0;
  v31 = 0;
  v29 = nullptr;
  kgsl_snapshot_add_section(a1, 5889, a2, gen8_gmu_snapshot_itcm, v4);
  adreno_snapshot_gmu_versions(a1, a2);
  v8 = a1 + 1560;
  v9 = 32;
  v35 = 0;
  do
  {
    if ( *(_QWORD *)(v8 + 40) )
    {
      v11 = v4[6];
      v34 = v8;
      if ( v8 == v11 )
      {
        v10 = 1;
      }
      else if ( v8 == v4[2] )
      {
        v10 = 2;
      }
      else if ( v8 == v4[3] || v8 == v4[4] )
      {
        v10 = 8;
      }
      else if ( v8 == *(_QWORD *)(a1 + 8664) )
      {
        v10 = 9;
      }
      else if ( v8 == *(_QWORD *)(a1 + 8672) )
      {
        v10 = 10;
      }
      else
      {
        v10 = 5;
      }
      LODWORD(v35) = v10;
      kgsl_snapshot_add_section(a1, 5889, a2, adreno_snapshot_gmu_mem, &v34);
    }
    --v9;
    v8 += 208;
  }
  while ( v9 );
  kgsl_snapshot_add_section(a1, 514, a2, gen8_snapshot_rscc_registers, v5[13]);
  if ( (kgsl_regmap_valid_offset(a1 + 13200, *v7) & 1) != 0 )
  {
    kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, v7);
  }
  else if ( (gen8_gmu_device_snapshot___already_done & 1) == 0 )
  {
    gen8_gmu_device_snapshot___already_done = 1;
    _warn_printk("cx_misc registers are not defined in device tree");
    __break(0x800u);
  }
  kgsl_snapshot_add_section(a1, 5889, a2, gen8_gmu_snapshot_dtcm, v4);
  kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, v5[10]);
  if ( gen8_gmu_rpmh_pwr_state_is_active(a1) && gen8_gmu_gx_is_on(a1) )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    v12 = v5[12];
    if ( v12 )
    {
      v13 = __clz(v6);
      v14 = 0;
      v15 = 32 - v13;
      v16 = 0;
      if ( v13 != 31 && v13 != 32 )
        v17 = 32 - v13;
      else
        v17 = 1;
      v18 = (unsigned int)(v17 - 1);
      do
      {
        v19 = (_DWORD *)(v5[11] + 32 * v14);
        if ( *v19 == 1 && (v6 & 1) == 0 )
        {
          v22 = 0;
          while ( v18 != v22 )
          {
            v23 = v6 >> v22;
            v21 = ++v22;
            if ( (v23 & 2) != 0 )
              goto LABEL_38;
          }
        }
        else
        {
          v21 = 0;
LABEL_38:
          if ( v21 < v15 )
          {
LABEL_39:
            v29 = v19;
            if ( *v19 == 1 )
              v24 = v21;
            else
              v24 = 0;
            HIDWORD(v30) = v24;
            kgsl_snapshot_add_section(a1, 5379, a2, gen8_legacy_snapshot_registers, &v29);
            if ( *v19 == 1 )
            {
              v25 = 0;
              v26 = v21;
              while ( 1 )
              {
                v27 = v21 + v25;
                if ( (int)v15 <= (int)(v21 + v25 + 1) )
                  break;
                ++v25;
                if ( ((v6 >> v27) & 2) != 0 )
                {
                  v21 += v25;
                  if ( v15 > v26 + v25 )
                    goto LABEL_39;
                  break;
                }
              }
            }
            v12 = v5[12];
          }
        }
        v14 = ++v16;
      }
      while ( v12 > v16 );
    }
  }
  gen8_snapshot(a1, a2);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  result = gmu_core_regwrite(a1, 129427, 32774);
  _ReadStatusReg(SP_EL0);
  return result;
}
