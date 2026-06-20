__int64 __fastcall gen8_snapshot_shader(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  unsigned __int64 v5; // x27
  __int64 v6; // x8
  __int64 (__fastcall *v7)(_QWORD); // x8
  unsigned __int64 v8; // x3
  unsigned __int64 v9; // x8
  int v10; // w23
  unsigned int v11; // w5
  int v12; // w9
  unsigned __int64 v13; // x15
  unsigned __int64 v14; // x8
  unsigned int v15; // w22
  int v16; // w11
  unsigned int v17; // w9
  unsigned int v18; // w26
  int v19; // w9
  __int64 v20; // x28
  _DWORD *v21; // x24
  int v22; // w9
  unsigned int v24; // w23
  __int64 v25; // x8
  unsigned __int64 v26; // x10
  unsigned int v27; // w8
  unsigned int v28; // w10
  unsigned int v29; // w9
  unsigned int v30; // w27
  unsigned int i; // w25
  int v32; // w8
  int v33; // w11
  unsigned int v34; // w12
  char v35; // w13
  char v36; // w10
  _DWORD *v38; // x28
  unsigned __int64 *v39; // x8
  int v40; // w12
  unsigned int v42; // w10
  __int64 v43; // x9
  unsigned __int64 v44; // x11
  unsigned int v45; // w11
  unsigned int v46; // w9
  unsigned int v47; // w13
  unsigned __int64 v48; // x16
  unsigned int v49; // w13
  __int64 v50; // x11
  unsigned __int64 v51; // x14
  unsigned __int64 v52; // x1
  __int64 v53; // x17
  int v54; // w14
  char v55; // w15
  __int64 v56; // x10
  char v57; // w0
  int v58; // w8
  unsigned int v59; // w24
  __int64 v60; // x9
  unsigned __int64 v61; // x10
  unsigned int v62; // w9
  unsigned int v63; // w23
  unsigned int v64; // w10
  unsigned int v65; // w8
  unsigned int v66; // w27
  unsigned int j; // w25
  int v68; // w8
  int v69; // w11
  unsigned int v70; // w12
  char v71; // w13
  char v72; // [xsp+4h] [xbp-5Ch]
  int v73; // [xsp+8h] [xbp-58h]
  unsigned int v74; // [xsp+Ch] [xbp-54h]
  unsigned __int64 v75; // [xsp+10h] [xbp-50h]
  __int64 v76; // [xsp+18h] [xbp-48h]
  __int64 v77; // [xsp+20h] [xbp-40h]
  int v78; // [xsp+20h] [xbp-40h]
  unsigned __int64 v79; // [xsp+28h] [xbp-38h]
  _DWORD *v80; // [xsp+30h] [xbp-30h] BYREF
  __int64 v81; // [xsp+38h] [xbp-28h]
  __int64 v82; // [xsp+40h] [xbp-20h]
  __int64 v83; // [xsp+48h] [xbp-18h]
  __int64 v84; // [xsp+50h] [xbp-10h]
  __int64 v85; // [xsp+58h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v4 = *(_QWORD *)(gen8_snapshot_block_list + 128);
  v5 = *(_QWORD *)(gen8_snapshot_block_list + 136);
  v79 = *(unsigned int *)(a1 + 24612);
  v80 = nullptr;
  v75 = v5;
  v76 = v4;
  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 )
    goto LABEL_18;
  v6 = *(_QWORD *)(a1 + 88);
  if ( v6 )
  {
    v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 16);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v7(a1 + 56) & 1) != 0 )
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
    if ( v5 )
    {
      v13 = v79;
      v14 = 0;
      v15 = 0;
      v16 = 0;
      v17 = __clz(v79);
      v18 = 32 - v17;
      if ( v17 != 31 && v17 != 32 )
        v19 = 32 - v17;
      else
        v19 = 1;
      v20 = (unsigned int)(v19 - 1);
      do
      {
        v78 = v16;
        v21 = (_DWORD *)(v4 + 40 * v14);
        v22 = v21[6];
        if ( v22 == 1 && (v13 & 1) == 0 )
        {
          v25 = 0;
          while ( v20 != v25 )
          {
            v26 = v13 >> v25;
            v24 = ++v25;
            if ( (v26 & 2) != 0 )
              goto LABEL_32;
          }
        }
        else
        {
          v24 = 0;
LABEL_32:
          if ( v24 < v18 )
          {
            v27 = v21[2];
            v28 = v27;
LABEL_34:
            if ( v28 )
            {
              v29 = v21[7];
              v30 = 0;
              do
              {
                if ( v29 )
                {
                  for ( i = 0; i < v29; ++i )
                  {
                    v80 = v21;
                    LODWORD(v81) = v30;
                    v32 = v21[3];
                    LODWORD(v83) = i;
                    HIDWORD(v81) = v32;
                    LODWORD(v82) = v24;
                    v84 = v15;
                    v15 += 4 * v21[1];
                    kgsl_snapshot_add_section(a1, 4611, a2, gen8_legacy_snapshot_shader, &v80);
                    v29 = v21[7];
                  }
                  v27 = v21[2];
                  v13 = v79;
                }
                ++v30;
              }
              while ( v30 < v27 );
              v5 = v75;
              v4 = v76;
              v28 = v27;
              v22 = v21[6];
            }
            if ( v22 == 1 )
            {
              v33 = 0;
              v34 = v24;
              while ( 1 )
              {
                v35 = v24 + v33;
                if ( (int)v18 <= (int)(v24 + v33 + 1) )
                  break;
                ++v33;
                if ( ((v13 >> v35) & 2) != 0 )
                {
                  v24 += v33;
                  if ( v18 > v34 + v33 )
                    goto LABEL_34;
                  break;
                }
              }
            }
          }
        }
        v14 = (unsigned int)(v78 + 1);
        v16 = v78 + 1;
      }
      while ( v5 > v14 );
    }
  }
  else if ( v5 )
  {
    v8 = v79;
    v9 = 0;
    v10 = 0;
    v11 = 32 - __clz(v79);
    v74 = v11;
    if ( v11 <= 1 )
      v12 = 1;
    else
      v12 = v11;
    v77 = (unsigned int)(v12 - 1);
    while ( 1 )
    {
      v38 = (_DWORD *)(v4 + 40 * v9);
      v39 = *(unsigned __int64 **)(gen8_capturescript + 8);
      v40 = v38[6];
      if ( v40 == 1 && (v8 & 1) == 0 )
        break;
      v42 = 0;
      if ( !v11 )
        goto LABEL_76;
LABEL_61:
      v45 = v38[2];
      v46 = 0;
      v47 = v45;
LABEL_62:
      if ( v47 )
      {
        LODWORD(v48) = v38[7];
        v49 = 0;
        do
        {
          if ( (_DWORD)v48 )
          {
            v50 = 0;
            v51 = 0;
            do
            {
              v52 = ((unsigned __int64)(v42 & 0x1F) << 21) | v49 & 0xF | v50 & 0x7C000000;
              ++v51;
              v50 += 0x4000000;
              *v39 = v52
                   | ((v38[5] & 7LL) << 18)
                   | ((v38[4] & 3LL) << 16)
                   | ((unsigned __int64)(unsigned __int8)*v38 << 8)
                   | (16LL * (v38[3] & 0xF));
              v39[1] = 0xAE6D00000200001LL;
              v53 = (unsigned int)v38[1] | 0xC00000000000000LL;
              v39[2] = *(_QWORD *)(gen8_crashdump_registers + 24) + v46;
              v39[3] = v53;
              v39 += 4;
              v48 = (unsigned int)v38[7];
              v46 += 4 * v38[1];
            }
            while ( v51 < v48 );
            v45 = v38[2];
          }
          ++v49;
        }
        while ( v49 < v45 );
        v40 = v38[6];
        v47 = v45;
      }
      if ( v40 == 1 )
      {
        v54 = 0;
        while ( 1 )
        {
          v55 = v42 + v54;
          if ( (int)v11 <= (int)(v42 + v54 + 1) )
            break;
          ++v54;
          if ( ((v8 >> v55) & 2) != 0 )
          {
            v42 += v54;
            if ( v11 > v42 )
              goto LABEL_62;
            break;
          }
        }
      }
LABEL_77:
      gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + v46;
      *(_DWORD *)gen8_cd_reg_end = -1431655766;
      v56 = *(_QWORD *)(gen8_crashdump_registers + 24);
      v39[3] = 0;
      *v39 = v56 + v46;
      v39[1] = 0x84500000000001LL;
      v39[2] = 0;
      v57 = gen8_do_crashdump(a1);
      if ( (v57 & 1) == 0 )
      {
        v36 = 0;
        goto LABEL_49;
      }
      v58 = v38[6];
      v59 = 0;
      v72 = v57;
      v73 = v10;
      if ( v58 == 1 )
      {
        v8 = v79;
        v11 = v74;
        if ( (v79 & 1) == 0 )
        {
          v60 = 0;
          while ( v77 != v60 )
          {
            v61 = v79 >> v60;
            v59 = ++v60;
            if ( (v61 & 2) != 0 )
              goto LABEL_83;
          }
          goto LABEL_50;
        }
LABEL_83:
        if ( v59 < v74 )
        {
LABEL_86:
          v62 = v38[2];
          v63 = 0;
          v64 = v62;
LABEL_87:
          if ( v64 )
          {
            v65 = v38[7];
            v66 = 0;
            do
            {
              if ( v65 )
              {
                for ( j = 0; j < v65; ++j )
                {
                  v80 = v38;
                  LODWORD(v81) = v66;
                  v68 = v38[3];
                  LODWORD(v83) = j;
                  HIDWORD(v81) = v68;
                  LODWORD(v82) = v59;
                  v84 = v63;
                  v63 += 4 * v38[1];
                  kgsl_snapshot_add_section(a1, 4611, a2, gen8_snapshot_shader_memory, &v80);
                  v65 = v38[7];
                }
                v62 = v38[2];
                v8 = v79;
                v11 = v74;
              }
              ++v66;
            }
            while ( v66 < v62 );
            v5 = v75;
            v4 = v76;
            v64 = v62;
            v58 = v38[6];
          }
          if ( v58 == 1 )
          {
            v69 = 0;
            v70 = v59;
            while ( 1 )
            {
              v71 = v59 + v69;
              if ( (int)v11 <= (int)(v59 + v69 + 1) )
                break;
              ++v69;
              if ( ((v8 >> v71) & 2) != 0 )
              {
                v59 += v69;
                if ( v11 > v70 + v69 )
                  goto LABEL_87;
                break;
              }
            }
          }
        }
      }
      else
      {
        v8 = v79;
        v11 = v74;
        if ( v74 )
          goto LABEL_86;
      }
LABEL_50:
      v36 = v72;
      v9 = (unsigned int)(v73 + 1);
      v10 = v73 + 1;
      if ( v5 <= v9 )
        goto LABEL_49;
    }
    v43 = 0;
    while ( v77 != v43 )
    {
      v44 = v8 >> v43;
      v42 = ++v43;
      if ( (v44 & 2) != 0 )
      {
        if ( v42 >= v11 )
          break;
        goto LABEL_61;
      }
    }
LABEL_76:
    v46 = 0;
    goto LABEL_77;
  }
  v36 = 1;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v36 & 1;
}
