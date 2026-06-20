__int64 __fastcall gen8_snapshot_dbgahb_regs(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  unsigned int v9; // w9
  unsigned __int64 v10; // x8
  unsigned int v11; // w28
  int v12; // w11
  __int64 v13; // x27
  int v14; // w9
  __int64 v15; // x21
  __int64 v16; // x25
  unsigned int v17; // w8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x10
  int v20; // w8
  __int64 v21; // x26
  unsigned int v22; // w22
  __int64 v23; // x10
  unsigned __int64 v24; // x11
  int *v25; // x9
  unsigned int v26; // w10
  int v27; // w11
  unsigned int v28; // w8
  unsigned __int64 v29; // x12
  int v30; // w10
  unsigned __int64 *v31; // x10
  _QWORD *v32; // x8
  int v33; // w11
  int *v34; // x9
  __int64 v35; // x10
  __int64 v36; // x12
  __int64 v37; // x13
  __int64 v38; // x11
  int v39; // t1
  int v40; // w9
  unsigned int v41; // w10
  char v42; // w11
  __int64 result; // x0
  unsigned int v44; // w9
  unsigned __int64 v45; // x8
  unsigned int v46; // w25
  int v47; // w11
  int v48; // w9
  __int64 v49; // x27
  _DWORD *v50; // x22
  unsigned int v51; // w8
  unsigned int v52; // w9
  unsigned int v53; // w23
  unsigned int v54; // w10
  int v55; // w8
  unsigned int v56; // w28
  unsigned int v57; // w26
  __int64 v58; // x10
  unsigned __int64 v59; // x11
  unsigned int v60; // w8
  unsigned int v61; // w9
  int v62; // w9
  unsigned int v63; // w10
  char v64; // w11
  int v65; // [xsp+4h] [xbp-5Ch]
  __int64 v66; // [xsp+10h] [xbp-50h]
  unsigned __int64 v67; // [xsp+18h] [xbp-48h]
  unsigned int v68; // [xsp+24h] [xbp-3Ch]
  int v69; // [xsp+24h] [xbp-3Ch]
  _DWORD *v70; // [xsp+28h] [xbp-38h] BYREF
  __int64 v71; // [xsp+30h] [xbp-30h]
  unsigned __int64 v72; // [xsp+38h] [xbp-28h]
  unsigned __int64 v73; // [xsp+40h] [xbp-20h]
  __int64 v74; // [xsp+48h] [xbp-18h]
  __int64 v75; // [xsp+50h] [xbp-10h]
  __int64 v76; // [xsp+58h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 24612);
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v6 = *(_QWORD *)(gen8_snapshot_block_list + 176);
  v5 = *(_QWORD *)(gen8_snapshot_block_list + 184);
  v70 = nullptr;
  v71 = 0;
  v66 = v6;
  v67 = v5;
  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 )
    goto LABEL_48;
  v7 = *(_QWORD *)(a1 + 88);
  if ( v7 )
  {
    v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 16);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v8(a1 + 56) & 1) != 0 )
        goto LABEL_48;
    }
  }
  if ( *(_BYTE *)(a1 + 11305) != 1
    || !gen8_capturescript
    || (unsigned __int64)gen8_capturescript > 0xFFFFFFFFFFFFF000LL
    || !gen8_crashdump_registers
    || (unsigned __int64)gen8_crashdump_registers > 0xFFFFFFFFFFFFF000LL
    || (gen8_crashdump_timedout & 1) != 0 )
  {
LABEL_48:
    if ( v67 )
    {
      v44 = __clz(v4);
      v45 = 0;
      v46 = 32 - v44;
      v47 = 0;
      if ( v44 != 31 && v44 != 32 )
        v48 = 32 - v44;
      else
        v48 = 1;
      v49 = (unsigned int)(v48 - 1);
      do
      {
        v69 = v47;
        v50 = (_DWORD *)(v66 + 48 * v45);
        v51 = v50[2];
        if ( v51 )
        {
          v52 = v50[3];
          v53 = 0;
          v54 = v52;
          do
          {
            if ( v54 )
            {
              v55 = v50[1];
              v56 = 0;
              do
              {
                v57 = 0;
                if ( v55 != 1 || (v4 & 1) != 0 )
                {
LABEL_67:
                  if ( v57 < v46 )
                  {
LABEL_68:
                    v70 = v50;
                    if ( v55 == 1 )
                      v60 = v57;
                    else
                      v60 = 0;
                    HIDWORD(v73) = v50[7];
                    v61 = v50[5];
                    LODWORD(v73) = v56;
                    HIDWORD(v71) = v60;
                    v72 = __PAIR64__(v53, v61);
                    HIDWORD(v74) = v50[4];
                    LODWORD(v71) = *v50;
                    LODWORD(v74) = v50[6];
                    kgsl_snapshot_add_section(a1, 5379, a2, gen8_legacy_snapshot_cluster_dbgahb, &v70);
                    v55 = v50[1];
                    if ( v55 == 1 )
                    {
                      v62 = 0;
                      v63 = v57;
                      while ( 1 )
                      {
                        v64 = v57 + v62;
                        if ( (int)v46 <= (int)(v57 + v62 + 1) )
                          break;
                        ++v62;
                        if ( ((v4 >> v64) & 2) != 0 )
                        {
                          v57 += v62;
                          if ( v46 > v63 + v62 )
                            goto LABEL_68;
                          break;
                        }
                      }
                    }
                    v52 = v50[3];
                  }
                }
                else
                {
                  v58 = 0;
                  while ( v49 != v58 )
                  {
                    v59 = v4 >> v58;
                    v57 = ++v58;
                    if ( (v59 & 2) != 0 )
                      goto LABEL_67;
                  }
                }
                ++v56;
              }
              while ( v56 < v52 );
              v51 = v50[2];
              v54 = v52;
            }
            ++v53;
          }
          while ( v53 < v51 );
        }
        v45 = (unsigned int)(v69 + 1);
        v47 = v69 + 1;
      }
      while ( v67 > v45 );
    }
  }
  else if ( v67 )
  {
    v9 = __clz(v4);
    v10 = 0;
    v11 = 32 - v9;
    v12 = 0;
    v13 = 0;
    if ( v9 != 31 && v9 != 32 )
      v14 = 32 - v9;
    else
      v14 = 1;
    v15 = (unsigned int)(v14 - 1);
    while ( 1 )
    {
      v16 = v66 + 48 * v10;
      v65 = v12;
      v17 = *(_DWORD *)(v16 + 8);
      *(_DWORD *)(v16 + 44) = v13;
      if ( v17 )
      {
        v18 = *(unsigned int *)(v16 + 12);
        v68 = 0;
        v19 = v18;
        do
        {
          if ( v19 )
          {
            v20 = *(_DWORD *)(v16 + 4);
            v21 = 0;
            while ( 1 )
            {
              v22 = 0;
              if ( v20 != 1 || (v4 & 1) != 0 )
              {
LABEL_31:
                if ( v22 < v11 )
                {
LABEL_32:
                  v25 = *(int **)(v16 + 32);
                  v70 = (_DWORD *)v16;
                  v26 = *(_DWORD *)(v16 + 28);
                  v27 = *(_DWORD *)(v16 + 20);
                  HIDWORD(v72) = v68;
                  v73 = __PAIR64__(v26, v21);
                  if ( v20 == 1 )
                    v28 = v22;
                  else
                    v28 = 0;
                  HIDWORD(v71) = v28;
                  LODWORD(v72) = v27;
                  HIDWORD(v74) = *(_DWORD *)(v16 + 16);
                  v29 = v68 & 0xF
                      | (unsigned __int64)(unsigned __int8)(16 * (v21 & 0xF))
                      | ((unsigned __int64)(v22 & 0x1F) << 21)
                      | ((unsigned __int64)(v26 & 7) << 18)
                      | ((unsigned __int64)(v27 & 3) << 16)
                      | ((unsigned __int64)BYTE4(v74) << 8);
                  LODWORD(v71) = *(_DWORD *)v16;
                  v30 = *(_DWORD *)(v16 + 24);
                  v75 = v13;
                  LODWORD(v74) = v30;
                  v31 = *(unsigned __int64 **)(gen8_capturescript + 8);
                  *v31 = v29;
                  v31[1] = 0xAE6D00000200001LL;
                  v32 = v31 + 2;
                  v33 = *v25;
                  if ( *v25 != -1 )
                  {
                    v34 = v25 + 2;
                    v35 = gen8_crashdump_registers;
                    do
                    {
                      v36 = (unsigned int)(v33 - *(_DWORD *)(v16 + 40) + 49152);
                      v37 = (unsigned int)(*(v34 - 1) - v33 + 1);
                      v38 = *(_QWORD *)(v35 + 24) + v13;
                      v13 += 4LL * (unsigned int)v37;
                      *v32 = v38;
                      v32[1] = v37 | (v36 << 44);
                      v32 += 2;
                      v39 = *v34;
                      v34 += 2;
                      v33 = v39;
                    }
                    while ( v39 != -1 );
                    v31 = v32 - 2;
                  }
                  gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + (unsigned int)v13;
                  *(_DWORD *)gen8_cd_reg_end = -1431655766;
                  *v32 = *(_QWORD *)(gen8_crashdump_registers + 24) + (unsigned int)v13;
                  v31[5] = 0;
                  v31[3] = 0x84500000000001LL;
                  v31[4] = 0;
                  if ( (gen8_do_crashdump(a1) & 1) == 0 )
                  {
                    result = 0;
                    goto LABEL_78;
                  }
                  kgsl_snapshot_add_section(a1, 5379, a2, gen8_snapshot_cluster_dbgahb, &v70);
                  v20 = *(_DWORD *)(v16 + 4);
                  if ( v20 == 1 )
                  {
                    v40 = 0;
                    v41 = v22;
                    while ( 1 )
                    {
                      v42 = v22 + v40;
                      if ( (int)v11 <= (int)(v22 + v40 + 1) )
                        break;
                      ++v40;
                      if ( ((v4 >> v42) & 2) != 0 )
                      {
                        v22 += v40;
                        if ( v11 > v41 + v40 )
                          goto LABEL_32;
                        break;
                      }
                    }
                  }
                  v18 = *(unsigned int *)(v16 + 12);
                }
              }
              else
              {
                v23 = 0;
                while ( v15 != v23 )
                {
                  v24 = v4 >> v23;
                  v22 = ++v23;
                  if ( (v24 & 2) != 0 )
                    goto LABEL_31;
                }
              }
              if ( ++v21 >= v18 )
              {
                v17 = *(_DWORD *)(v16 + 8);
                v19 = v18;
                break;
              }
            }
          }
          ++v68;
        }
        while ( v68 < v17 );
      }
      result = 1;
      v10 = (unsigned int)(v65 + 1);
      v12 = v65 + 1;
      if ( v67 <= v10 )
        goto LABEL_78;
    }
  }
  result = 1;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
