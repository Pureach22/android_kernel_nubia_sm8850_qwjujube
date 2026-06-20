void memlat_update_work()
{
  __int64 v0; // x8
  __int64 v1; // x21
  unsigned int v2; // w1
  int v3; // w6
  unsigned int v4; // w19
  unsigned int v5; // w2
  __int64 v6; // x22
  __int64 v7; // x3
  unsigned __int64 v8; // x1
  char v9; // w4
  unsigned int v10; // w5
  unsigned int v11; // w2
  unsigned int v12; // w19
  unsigned __int64 v14; // x4
  unsigned __int64 v15; // x4
  _DWORD *v16; // x23
  _DWORD *v17; // x19
  unsigned int v18; // w24
  unsigned int v19; // w19
  unsigned int v20; // w24
  unsigned int v21; // w25
  int v22; // w26
  unsigned int v23; // w27
  __int64 v24; // x1
  __int64 v25; // x1
  unsigned int v26; // w4
  __int64 v27; // x4
  unsigned int v28; // w4
  unsigned int v29; // w1
  unsigned __int64 v30; // x6
  unsigned __int64 v31; // x2
  unsigned __int64 v32; // x1
  unsigned int v33; // w0
  unsigned int v34; // w23
  int v35; // w8
  unsigned int v36; // w0
  int v37; // w8
  __int64 v42; // x24
  unsigned int v43; // w19
  __int64 v44; // x21
  unsigned int v45; // w25
  unsigned int v46; // w8
  unsigned int v47; // w0
  int v48; // w8
  unsigned int v49; // w9
  _QWORD *v50; // x8
  __int64 i; // x21
  int updated; // w0
  __int64 **v53; // x23
  unsigned int v54; // w8
  __int64 v55; // x3
  char v56; // w9
  __int64 v57; // x0
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-90h]
  __int64 v59; // [xsp+8h] [xbp-88h] BYREF
  int v60; // [xsp+10h] [xbp-80h]
  _QWORD v61[2]; // [xsp+18h] [xbp-78h]
  int v62; // [xsp+28h] [xbp-68h]
  __int64 v63; // [xsp+30h] [xbp-60h]
  __int64 v64; // [xsp+38h] [xbp-58h]
  int v65; // [xsp+40h] [xbp-50h]
  __int64 v66; // [xsp+48h] [xbp-48h] BYREF
  __int64 v67; // [xsp+50h] [xbp-40h]
  __int64 v68; // [xsp+58h] [xbp-38h]
  __int64 v69; // [xsp+60h] [xbp-30h]
  __int64 v70; // [xsp+68h] [xbp-28h]
  __int64 v71; // [xsp+70h] [xbp-20h]
  __int64 v72; // [xsp+78h] [xbp-18h]
  int v73; // [xsp+80h] [xbp-10h]
  __int64 v74; // [xsp+88h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  v61[0] = 0;
  v61[1] = 0;
  if ( *(_BYTE *)(memlat_data + 306) != 1 )
    goto LABEL_111;
  v0 = 0;
  v60 = 0;
  _ReadStatusReg(SP_EL0);
  v59 = 0;
  while ( 2 )
  {
    v1 = *(_QWORD *)(memlat_data + 8 * v0 + 248);
    if ( !v1 )
      goto LABEL_3;
    v2 = *(_DWORD *)(v1 + 108);
    if ( !v2 )
      goto LABEL_54;
    v3 = 0;
    while ( 2 )
    {
      v6 = *(_QWORD *)(v1 + 96) + 240LL * v3;
      if ( !v6 || (*(_BYTE *)(v6 + 16) & 1) == 0 )
        goto LABEL_11;
      v7 = *(unsigned int *)(*(_QWORD *)(v6 + 8) + 16LL);
      if ( (unsigned int)v7 >= 5 )
      {
        v4 = *(_DWORD *)(v6 + 84);
        goto LABEL_8;
      }
      v8 = *(unsigned int *)(v6 + 24);
      v9 = 0;
      v10 = 0;
      v11 = __clz(__rbit64(v8));
      if ( !*(_DWORD *)(v6 + 24) )
        v11 = 32;
      do
      {
        v14 = (-1LL << v9) & v8;
        if ( !v14 )
          break;
        v15 = __clz(__rbit64(v14));
        v16 = *(_DWORD **)((char *)&sampling_stats + _per_cpu_offset[v15]);
        if ( (*(_BYTE *)(v6 + 184) & 1) != 0
          || (v17 = &v16[v7], v18 = v17[155], v19 = v17[150], v18 >= *(_DWORD *)(v6 + 68))
          && v19 <= *(_DWORD *)(v6 + 72) )
        {
          v12 = v16[147];
LABEL_19:
          if ( v10 < v12 )
            v11 = v15;
          if ( v10 <= v12 )
            v10 = v12;
          goto LABEL_23;
        }
        v20 = *(_DWORD *)(v6 + 44);
        v21 = v20 - v19;
        if ( v20 >= v19 )
        {
          v22 = *(_DWORD *)(v6 + 56);
          v12 = v16[147];
          if ( v22 )
          {
            if ( v12 > *(_DWORD *)(v6 + 64) )
            {
              v23 = *(_DWORD *)(v6 + 60);
              if ( v12 < v23 && (v16[148] >= *(_DWORD *)(v6 + 48) || v16[149] >= *(_DWORD *)(v6 + 52)) )
              {
                v12 += v12 * v21 * v22 / (100 * v20);
                if ( v23 < v12 )
                  v12 = *(_DWORD *)(v6 + 60);
              }
            }
          }
          goto LABEL_19;
        }
LABEL_23:
        _CF = v15 >= 0x1F;
        v9 = v15 + 1;
      }
      while ( !_CF );
      v24 = *(_QWORD *)(v6 + 32);
      if ( v24 )
      {
        v25 = v24 - 4;
        do
        {
          v26 = *(_DWORD *)(v25 + 4);
          v25 += 8;
        }
        while ( v26 && v26 < v10 );
        if ( v26 )
          v27 = 0;
        else
          v27 = -8;
        v28 = *(_DWORD *)(v25 + v27);
      }
      else
      {
        v28 = 0;
      }
      v29 = *(_DWORD *)(v6 + 76);
      v4 = *(_DWORD *)(v6 + 80);
      if ( v28 <= v29 )
        v28 = *(_DWORD *)(v6 + 76);
      if ( v28 < v4 )
        v4 = v28;
      if ( (v10 || *(_DWORD *)(v6 + 84) != v29) && v11 > 0x1F )
        __break(0x5512u);
      *(_DWORD *)(v6 + 84) = v4;
      v2 = *(_DWORD *)(v1 + 108);
LABEL_8:
      v5 = *((_DWORD *)v61 + v0);
      if ( v4 > v5 )
        v5 = v4;
      *((_DWORD *)v61 + v0) = v5;
LABEL_11:
      if ( ++v3 < v2 )
        continue;
      break;
    }
LABEL_54:
    v30 = *(unsigned int *)(v1 + 40);
    if ( *(_QWORD *)(v1 + 40) || *(_DWORD *)(v1 + 48) || *(_DWORD *)(v1 + 36) )
    {
      v31 = *((unsigned int *)v61 + v0);
      v32 = *(unsigned int *)(v1 + 48);
      if ( v31 < v32
        || (v32 = *(unsigned int *)(v1 + 44), v31 < v32)
        || (LODWORD(v32) = *(_DWORD *)(v1 + 40), v31 < v30) )
      {
        LODWORD(v30) = v32;
        *((_DWORD *)v61 + v0) = v32;
      }
      *(_DWORD *)(v1 + 36) = v30;
    }
LABEL_3:
    if ( ++v0 != 5 )
      continue;
    break;
  }
  v33 = _sw_hweight64(_cpu_possible_mask);
  if ( v33 <= 8 )
    v34 = 8;
  else
    v34 = v33;
  v65 = 0;
  v35 = *(unsigned __int8 *)(memlat_data + 304);
  v63 = 0;
  v64 = 0;
  if ( v35 == 1 )
  {
    v73 = 0;
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v66 = 0;
    v36 = _sw_hweight64(_cpu_possible_mask);
    v37 = v36 <= 8 ? 8 : v36;
    if ( v37 + 1 >= v34 )
    {
      StatusReg = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      raw_spin_lock(memlat_data + 296);
      v42 = 0;
      v43 = 0;
      do
      {
        v44 = *(_QWORD *)(memlat_data + 8 * v42 + 248);
        if ( v44 && *(_BYTE *)(v44 + 52) == 1 )
        {
          v45 = 0;
          *(_DWORD *)(*(_QWORD *)(v44 + 64) + 4LL * (int)v34) = *((_DWORD *)v61 + v42);
          v46 = _cpu_possible_mask;
          while ( 1 )
          {
            v47 = _sw_hweight64(v46);
            v48 = v47 <= 8 ? 8 : v47;
            if ( v45 >= v48 + 1 )
              break;
            v49 = *(_DWORD *)(*(_QWORD *)(v44 + 64) + 4LL * (int)v45);
            v46 = _cpu_possible_mask;
            ++v45;
            if ( v49 <= *((_DWORD *)&v63 + v42) )
              v49 = *((_DWORD *)&v63 + v42);
            *((_DWORD *)&v63 + v42) = v49;
          }
          if ( *((_DWORD *)&v63 + v42) != *(_DWORD *)(v44 + 56) )
            v43 |= 1LL << v42;
        }
        ++v42;
      }
      while ( v42 != 5 );
      if ( v43 )
      {
        raw_spin_lock(memlat_data + 300);
        v50 = (_QWORD *)memlat_data;
        if ( (v43 & 1) == 0 )
        {
          if ( (v43 & 2) == 0 )
            goto LABEL_87;
LABEL_113:
          *(_DWORD *)(v50[32] + 56LL) = HIDWORD(v63);
          if ( (v43 & 4) != 0 )
            goto LABEL_114;
LABEL_88:
          if ( (v43 & 8) == 0 )
            goto LABEL_89;
LABEL_115:
          *(_DWORD *)(v50[34] + 56LL) = HIDWORD(v64);
          if ( (v43 & 0x10) == 0 )
            goto LABEL_91;
LABEL_90:
          *(_DWORD *)(v50[35] + 56LL) = v65;
          goto LABEL_91;
        }
        *(_DWORD *)(*(_QWORD *)(memlat_data + 248) + 56LL) = v63;
        if ( (v43 & 2) != 0 )
          goto LABEL_113;
LABEL_87:
        if ( (v43 & 4) == 0 )
          goto LABEL_88;
LABEL_114:
        *(_DWORD *)(v50[33] + 56LL) = v64;
        if ( (v43 & 8) != 0 )
          goto LABEL_115;
LABEL_89:
        if ( (v43 & 0x10) != 0 )
          goto LABEL_90;
LABEL_91:
        raw_spin_unlock(v50 + 37);
        if ( (v43 & 1) == 0 )
        {
          if ( (v43 & 2) == 0 )
            goto LABEL_93;
LABEL_118:
          HIDWORD(v68) = 1;
          HIDWORD(v67) = HIDWORD(v63);
          if ( (v43 & 4) != 0 )
            goto LABEL_119;
LABEL_94:
          if ( (v43 & 8) == 0 )
            goto LABEL_95;
LABEL_120:
          HIDWORD(v71) = 3;
          HIDWORD(v70) = HIDWORD(v64);
          if ( (v43 & 0x10) == 0 )
            goto LABEL_97;
LABEL_96:
          v73 = 4;
          LODWORD(v72) = v65;
          goto LABEL_97;
        }
        LODWORD(v67) = 0;
        LODWORD(v66) = v63;
        if ( (v43 & 2) != 0 )
          goto LABEL_118;
LABEL_93:
        if ( (v43 & 4) == 0 )
          goto LABEL_94;
LABEL_119:
        LODWORD(v70) = 2;
        LODWORD(v69) = v64;
        if ( (v43 & 8) != 0 )
          goto LABEL_120;
LABEL_95:
        if ( (v43 & 0x10) != 0 )
          goto LABEL_96;
LABEL_97:
        if ( (qcom_dcvs_update_votes("memlat_fp", &v66, v43, 1) & 0x80000000) != 0 )
          printk(&unk_C606);
        raw_spin_unlock(memlat_data + 300);
        _WriteStatusReg(DAIF, StatusReg);
      }
      else
      {
        raw_spin_unlock(memlat_data + 296);
        _WriteStatusReg(DAIF, StatusReg);
      }
    }
  }
  for ( i = 0; i != 5; ++i )
  {
    v53 = *(__int64 ***)(memlat_data + 8 * i + 248);
    if ( v53 )
    {
      v54 = *((_DWORD *)v61 + i);
      if ( *((_DWORD *)v53 + 8) != v54 )
      {
        v55 = *((unsigned int *)v53 + 5);
        if ( (_DWORD)v55 != 3 )
        {
          v56 = *((_BYTE *)v53 + 52);
          *((_DWORD *)v53 + 8) = v54;
          if ( (v56 & 1) == 0 )
          {
            v59 = v54;
            v60 = i;
            v57 = (*v53)[14];
            if ( !v57 )
              v57 = **v53;
            updated = qcom_dcvs_update_votes(v57, &v59, 1, v55);
            if ( updated < 0 )
              dev_err(*v53, "qcom dcvs err: %d\n", updated);
          }
        }
      }
    }
  }
LABEL_111:
  _ReadStatusReg(SP_EL0);
}
