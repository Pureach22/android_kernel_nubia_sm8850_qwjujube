__int64 __fastcall gen8_snapshot_mvc_regs(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v6; // x24
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  unsigned int v9; // w9
  __int64 v10; // x8
  unsigned int v11; // w28
  unsigned int v12; // w13
  __int64 v13; // x27
  int v14; // w9
  __int64 v15; // x25
  unsigned int v16; // w9
  __int64 v17; // x20
  unsigned int v18; // w25
  __int64 v19; // x8
  unsigned int v20; // w26
  int v21; // w9
  __int64 v22; // x27
  unsigned int *v23; // x21
  unsigned int v24; // w8
  unsigned int v26; // w22
  __int64 v27; // x9
  unsigned __int64 v28; // x10
  unsigned int v29; // w9
  unsigned int v30; // w10
  unsigned int v31; // w11
  unsigned int v32; // w8
  int v33; // w9
  unsigned int v34; // w10
  char v35; // w11
  __int64 result; // x0
  unsigned int *v37; // x26
  unsigned int v38; // w8
  unsigned int v40; // w23
  __int64 v41; // x9
  unsigned __int64 v42; // x10
  unsigned int v43; // w20
  unsigned int v44; // w9
  unsigned int v45; // w10
  unsigned int v46; // w12
  unsigned __int64 v47; // x11
  unsigned int v48; // w9
  unsigned __int64 *v49; // x8
  unsigned __int64 v50; // x10
  unsigned int *v51; // x11
  __int64 v52; // x9
  __int64 v53; // x10
  _QWORD *v54; // x8
  __int64 v55; // x10
  __int64 v56; // x9
  unsigned int *v57; // x11
  __int64 v58; // x13
  __int64 v59; // x12
  unsigned int v60; // t1
  __int64 v61; // x9
  int v62; // w9
  unsigned int v63; // w10
  char v64; // w11
  unsigned int *v67; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int64 v68; // [xsp+20h] [xbp-20h]
  unsigned __int64 v69; // [xsp+28h] [xbp-18h]
  __int64 v70; // [xsp+30h] [xbp-10h]
  __int64 v71; // [xsp+38h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a1 + 24612);
  v69 = 0;
  v70 = 0;
  v67 = nullptr;
  v68 = 0;
  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 )
    goto LABEL_18;
  v7 = *(_QWORD *)(a1 + 88);
  if ( v7 )
  {
    v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 16);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v8(a1 + 56) & 1) != 0 )
        goto LABEL_18;
    }
  }
  if ( *(_BYTE *)(a1 + 11305) != 1
    || !gen8_capturescript
    || (unsigned __int64)gen8_capturescript > 0xFFFFFFFFFFFFF000LL
    || !gen8_crashdump_registers
    || (unsigned __int64)gen8_crashdump_registers > 0xFFFFFFFFFFFFF000LL
    || (gen8_crashdump_timedout & 1) != 0 )
  {
LABEL_18:
    if ( a4 )
    {
      v16 = __clz(v6);
      v17 = a1;
      v18 = 32 - v16;
      v19 = 0;
      v20 = 0;
      if ( v16 != 31 && v16 != 32 )
        v21 = 32 - v16;
      else
        v21 = 1;
      v22 = (unsigned int)(v21 - 1);
      do
      {
        v23 = (unsigned int *)(a3 + 40 * v19);
        v24 = v23[1];
        if ( v24 == 1 && (v6 & 1) == 0 )
        {
          v27 = 0;
          while ( v22 != v27 )
          {
            v28 = v6 >> v27;
            v26 = ++v27;
            if ( (v28 & 2) != 0 )
              goto LABEL_32;
          }
        }
        else
        {
          v26 = 0;
LABEL_32:
          if ( v26 < v18 )
          {
LABEL_33:
            v29 = v23[2];
            v30 = v23[3];
            v31 = *v23;
            if ( v24 == 1 )
              v32 = v26;
            else
              v32 = 0;
            v67 = v23;
            v69 = __PAIR64__(v30, v29);
            v68 = __PAIR64__(v32, v31);
            kgsl_snapshot_add_section(v17, 5379, a2, gen8_legacy_snapshot_mvc, &v67);
            v24 = v23[1];
            if ( v24 == 1 )
            {
              v33 = 0;
              v34 = v26;
              while ( 1 )
              {
                v35 = v26 + v33;
                if ( (int)v18 <= (int)(v26 + v33 + 1) )
                  break;
                ++v33;
                if ( ((v6 >> v35) & 2) != 0 )
                {
                  v26 += v33;
                  if ( v18 > v34 + v33 )
                    goto LABEL_33;
                  break;
                }
              }
            }
          }
        }
        v19 = ++v20;
      }
      while ( v20 < a4 );
    }
  }
  else if ( a4 )
  {
    v9 = __clz(v6);
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
      v37 = (unsigned int *)(a3 + 40 * v10);
      v38 = v37[1];
      v37[8] = v13;
      if ( v38 == 1 && (v6 & 1) == 0 )
      {
        v41 = 0;
        while ( v15 != v41 )
        {
          v42 = v6 >> v41;
          v40 = ++v41;
          if ( (v42 & 2) != 0 )
          {
            if ( v40 >= v11 )
              break;
            goto LABEL_56;
          }
        }
      }
      else
      {
        v40 = 0;
        if ( v11 )
        {
LABEL_56:
          v43 = v12;
LABEL_57:
          v44 = v37[2];
          v45 = v37[3];
          v46 = *v37;
          v70 = v13;
          v47 = (unsigned __int64)(v44 & 0xF) << 12;
          v69 = __PAIR64__(v45, v44);
          if ( v38 == 1 )
            v48 = v40;
          else
            v48 = 0;
          v68 = __PAIR64__(v48, v46);
          v49 = *(unsigned __int64 **)(gen8_capturescript + 8);
          v67 = v37;
          v50 = v47 & 0xFFFFFFFFFFF8F0CFLL
              | ((unsigned __int64)(v40 & 7) << 16)
              | ((unsigned __int64)(v46 & 0xF) << 8)
              | (16LL * (v45 & 3))
              | 0x800000;
          v51 = *((unsigned int **)v37 + 2);
          *v49 = v50;
          v49[1] = 0x81E00000200001LL;
          v52 = *((_QWORD *)v37 + 3);
          if ( v52 )
          {
            v53 = *(unsigned int *)(v52 + 4);
            v49[2] = *(unsigned int *)(v52 + 8);
            v49[3] = (v53 << 44) | 0x200001;
            v54 = v49 + 4;
          }
          else
          {
            v54 = v49 + 2;
          }
          v55 = *v51;
          if ( (_DWORD)v55 != -1 )
          {
            v56 = gen8_crashdump_registers;
            v57 = v51 + 2;
            do
            {
              v58 = *(_QWORD *)(v56 + 24) + v13;
              v59 = *(v57 - 1) - (unsigned int)v55 + 1;
              v13 += 4LL * (unsigned int)v59;
              *v54 = v58;
              v54[1] = v59 | (v55 << 44);
              v54 += 2;
              v60 = *v57;
              v57 += 2;
              v55 = v60;
            }
            while ( v60 != -1 );
          }
          gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + (unsigned int)v13;
          *(_DWORD *)gen8_cd_reg_end = -1431655766;
          v61 = *(_QWORD *)(gen8_crashdump_registers + 24);
          v54[3] = 0;
          *v54 = v61 + (unsigned int)v13;
          v54[1] = 0x84500000000001LL;
          v54[2] = 0;
          if ( (gen8_do_crashdump(a1) & 1) == 0 )
          {
            result = 0;
            goto LABEL_43;
          }
          kgsl_snapshot_add_section(a1, 5379, a2, gen8_snapshot_mvc, &v67);
          v38 = v37[1];
          if ( v38 == 1 )
          {
            v62 = 0;
            v63 = v40;
            v12 = v43;
            while ( 1 )
            {
              v64 = v40 + v62;
              if ( (int)v11 <= (int)(v40 + v62 + 1) )
                break;
              ++v62;
              if ( ((v6 >> v64) & 2) != 0 )
              {
                v40 += v62;
                if ( v11 > v63 + v62 )
                  goto LABEL_57;
                break;
              }
            }
          }
          else
          {
            v12 = v43;
          }
        }
      }
      result = 1;
      v10 = ++v12;
      if ( v12 >= a4 )
        goto LABEL_43;
    }
  }
  result = 1;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
