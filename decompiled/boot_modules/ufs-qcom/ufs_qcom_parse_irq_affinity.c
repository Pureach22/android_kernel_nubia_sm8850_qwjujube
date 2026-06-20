__int64 __fastcall ufs_qcom_parse_irq_affinity(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x23
  __int64 v6; // x21
  __int64 result; // x0
  int v8; // w8
  int v9; // w8
  __int64 v10; // x0
  unsigned int v11; // w25
  __int64 v12; // x19
  __int64 v13; // x21
  __int64 v14; // x22
  int v15; // w20
  __int64 v16; // x8
  unsigned int v17; // w9
  __int64 v18; // x9
  unsigned __int64 v19; // x12
  unsigned __int64 v20; // x13
  __int64 v21; // x12
  unsigned __int64 v28; // x14
  _QWORD *v29; // x9
  __int64 v30; // x8
  __int64 v31; // x10
  __int64 *v32; // x9
  __int64 v33; // t1
  __int64 v34; // x22
  __int64 v35; // x27
  __int64 *v36; // x28
  __int64 v37; // x24
  int v38; // w0
  int v39; // w20
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x11
  __int64 v43; // x8
  int v44; // w9
  __int64 v45; // x12
  unsigned __int64 v46; // x14
  unsigned __int64 v47; // x13
  __int64 v48; // x15
  __int64 *v49; // x17
  __int64 v50; // t1
  __int64 v51; // x10
  _QWORD *v52; // x8
  __int64 v53; // x12
  __int64 v54; // x14
  unsigned __int64 v55; // x13
  __int64 v56; // x15
  __int64 *v57; // x17
  __int64 v58; // t1
  unsigned int v59; // w13
  int v60; // w14
  __int64 v61; // x9
  __int64 v62; // x10
  unsigned __int64 v63; // x12
  unsigned __int64 v64; // x13
  __int64 v65; // x12
  unsigned __int64 v68; // x14
  unsigned __int64 v69; // [xsp+8h] [xbp-38h]
  int variable_u32_array; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v71; // [xsp+18h] [xbp-28h] BYREF
  __int64 v72; // [xsp+20h] [xbp-20h]
  __int64 v73; // [xsp+28h] [xbp-18h]
  __int64 v74; // [xsp+30h] [xbp-10h]
  __int64 v75; // [xsp+38h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 64);
    v5 = *(_QWORD *)(a1 + 184);
    variable_u32_array = 0;
    v6 = *(_QWORD *)(v3 + 744);
    result = _sw_hweight64(_cpu_possible_mask);
    if ( *(_DWORD *)(v5 + 3192) != (_DWORD)result && *(_BYTE *)(v5 + 760) != 1 || !v6 )
    {
LABEL_94:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    of_property_read_variable_u32_array(v6, "qcom,prime-mask", &variable_u32_array, 1, 0);
    v8 = variable_u32_array;
    *(_QWORD *)(v5 + 712) = _cpu_possible_mask & variable_u32_array;
    if ( !v8 )
    {
      dev_err(v3, "Invalid group prime mask 0x%x\n", 0);
      *(_QWORD *)(v5 + 712) = 128;
    }
    variable_u32_array = 0;
    of_property_read_variable_u32_array(v6, "qcom,silver-mask", &variable_u32_array, 1, 0);
    v9 = variable_u32_array;
    *(_QWORD *)(v5 + 720) = _cpu_possible_mask & variable_u32_array;
    if ( v9 )
    {
      if ( !*(_QWORD *)(v5 + 712) )
        goto LABEL_10;
    }
    else
    {
      dev_err(v3, "Invalid group silver mask 0x%x\n", 0);
      *(_QWORD *)(v5 + 720) = 15;
      if ( !*(_QWORD *)(v5 + 712) )
      {
LABEL_10:
        v10 = *(_QWORD *)(v3 + 744);
        variable_u32_array = 0;
        result = of_find_property(v10, "qcom,esi-affinity-mask", &variable_u32_array);
        if ( result )
        {
          v11 = variable_u32_array;
          if ( variable_u32_array >> 2 < 0 )
          {
            *(_QWORD *)(v5 + 736) = 0;
          }
          else
          {
            v12 = (__int64)variable_u32_array >> 2;
            result = devm_kmalloc(*(_QWORD *)(a1 + 64), 4 * v12, 3520);
            *(_QWORD *)(v5 + 736) = result;
            if ( result )
            {
              variable_u32_array = of_property_read_variable_u32_array(
                                     v6,
                                     "qcom,esi-affinity-mask",
                                     result,
                                     0,
                                     (__int64)(int)v11 >> 2);
              if ( variable_u32_array < 0 )
              {
                result = dev_info(v3, "Not found esi-affinity-mask property values\n");
              }
              else
              {
                if ( v11 >= 4 )
                {
                  v16 = 0;
                  if ( (unsigned int)v12 <= 1 )
                    v17 = 1;
                  else
                    v17 = v12;
                  v18 = 4LL * v17;
                  do
                  {
                    v19 = *(unsigned int *)(*(_QWORD *)(v5 + 736) + v16);
                    v20 = v19 >> 6;
                    v21 = 1LL << v19;
                    _X13 = (unsigned __int64 *)(v5 + 728 + 8 * v20);
                    __asm { PRFM            #0x11, [X13] }
                    do
                      v28 = __ldxr(_X13);
                    while ( __stxr(v28 | v21, _X13) );
                    v16 += 4;
                  }
                  while ( v18 != v16 );
                }
                result = _sw_hweight64(_cpu_possible_mask);
                if ( *(_DWORD *)(v5 + 3192) != (_DWORD)result )
                {
                  if ( *(int *)(v5 + 648) < 1 )
                    goto LABEL_92;
                  v13 = 0;
                  v14 = 0;
                  while ( 1 )
                  {
                    v15 = _sw_hweight64(*(unsigned int *)(*(_QWORD *)(v5 + 640) + v13 * 8 + 24));
                    result = _sw_hweight64(*(unsigned int *)(*(_QWORD *)(v5 + 640) + v13 * 8 + 16));
                    if ( v15 != (_DWORD)result )
                      break;
                    ++v14;
                    v13 += 4;
                    if ( v14 >= *(int *)(v5 + 648) )
                      goto LABEL_92;
                  }
                  v29 = *(_QWORD **)(v5 + 640);
                  v69 = (unsigned int)(HIDWORD(v29[v13]) + 1);
                  if ( HIDWORD(v29[v13]) == -2 )
                  {
LABEL_92:
                    result = dev_info(
                               *(_QWORD *)(*(_QWORD *)(v5 + 16) + 64LL),
                               "Not a partial cpu device, any cpu could be disabled using sysfs\n");
                    goto LABEL_93;
                  }
                  v30 = *(unsigned int *)(v5 + 648);
                  v73 = 0;
                  v74 = 0;
                  v71 = 0;
                  v72 = 0;
                  if ( (int)v30 < 1 )
                  {
                    LODWORD(v31) = 0;
                  }
                  else
                  {
                    v71 = v29[3];
                    if ( (_DWORD)v30 != 1 )
                    {
                      v72 = v29[7];
                      if ( (_DWORD)v30 != 2 )
                      {
                        v73 = v29[11];
                        if ( (_DWORD)v30 != 3 )
                        {
                          v74 = v29[15];
                          if ( (_DWORD)v30 != 4 )
                            goto LABEL_98;
                        }
                      }
                    }
                    v31 = 0;
                    v32 = (_QWORD *)((char *)v29 + ((v69 >> 3) & 0x1FFFFFF8) + 16);
                    do
                    {
                      v33 = *v32;
                      v32 += 4;
                      if ( (v33 & (1LL << v69)) != 0 )
                        goto LABEL_43;
                      ++v31;
                    }
                    while ( v30 != v31 );
                    LODWORD(v31) = v30;
                  }
LABEL_43:
                  if ( (int)v31 < (int)v30 - 1 )
                  {
                    v34 = (unsigned int)(v31 + 1);
                    v35 = (int)v31;
                    v36 = &v71 + (unsigned int)v34;
                    v37 = (32 * v34) | 0x18;
                    while ( 1 )
                    {
                      v38 = _sw_hweight64(*(unsigned int *)(*(_QWORD *)(v5 + 640) + 32 * v35 + 16));
                      if ( (unsigned int)v35 > 4 )
                        break;
                      if ( (v35 & 0x1FFFFFFF00000004LL) != 0 || (unsigned __int64)(8 * v35) > 0x20 )
                        goto LABEL_98;
                      v39 = v38;
                      result = _sw_hweight64(*((unsigned int *)&v71 + 2 * v35));
                      v40 = *(int *)(v5 + 648);
                      if ( ++v35 < v40 )
                      {
                        v41 = 0;
                        v42 = v37;
                        do
                        {
                          if ( v39 != (_DWORD)result )
                          {
                            if ( (unsigned __int64)(v34 + v41) > 3 )
                              goto LABEL_97;
                            v36[v41] = *(_QWORD *)(*(_QWORD *)(v5 + 640) + v42) << ((unsigned __int8)v39
                                                                                  - (unsigned __int8)result);
                          }
                          ++v41;
                          v42 += 32;
                        }
                        while ( (int)v40 > (int)v34 + (int)v41 );
                      }
                      ++v34;
                      ++v36;
                      v37 += 32;
                      if ( v35 >= (int)v40 - 1 )
                        goto LABEL_55;
                    }
LABEL_97:
                    __break(0x5512u);
LABEL_98:
                    __break(1u);
                  }
LABEL_55:
                  if ( v11 < 4 )
                    goto LABEL_85;
                  v43 = 0;
                  v44 = 0;
                  do
                  {
                    v45 = *(_QWORD *)(v5 + 736);
                    v46 = *(unsigned int *)(v5 + 648);
                    v47 = *(unsigned int *)(v45 + 4 * v43);
                    if ( (int)v46 < 1 )
                    {
                      v46 = 0;
                    }
                    else
                    {
                      v48 = 0;
                      v49 = (__int64 *)(*(_QWORD *)(v5 + 640) + ((v47 >> 3) & 0x1FFFFFF8) + 16);
                      while ( 1 )
                      {
                        v50 = *v49;
                        v49 += 4;
                        result = v50;
                        if ( (v50 & (1LL << v47)) != 0 )
                          break;
                        if ( v46 == ++v48 )
                          goto LABEL_65;
                      }
                      v46 = (unsigned int)v48;
LABEL_65:
                      if ( v46 > 3 )
                        goto LABEL_97;
                    }
                    if ( (((unsigned __int64)*(&v71 + v46) >> v43) & 1) != 0 )
                      *(_DWORD *)(v45 + 4LL * v44++) = v47;
                    ++v43;
                  }
                  while ( v43 != v12 );
                  if ( v44 < 1 )
                  {
LABEL_85:
                    *(_QWORD *)(v5 + 728) = 0;
                    goto LABEL_93;
                  }
                  v51 = 0;
                  v52 = (_QWORD *)(v5 + 728);
                  while ( 1 )
                  {
                    v53 = *(_QWORD *)(v5 + 736);
                    v54 = *(unsigned int *)(v5 + 648);
                    v55 = *(unsigned int *)(v53 + 4 * v51);
                    if ( (int)v54 >= 1 )
                      break;
                    LODWORD(v56) = 0;
                    if ( (unsigned int)v55 >= (unsigned int)v69 )
                      goto LABEL_81;
LABEL_71:
                    if ( ++v51 == v44 )
                    {
                      v61 = 4LL * (unsigned int)v44;
                      v62 = 0;
                      *v52 = 0;
                      do
                      {
                        v63 = *(unsigned int *)(*(_QWORD *)(v5 + 736) + v62);
                        v64 = v63 >> 6;
                        v65 = 1LL << v63;
                        _X13 = &v52[v64];
                        __asm { PRFM            #0x11, [X13] }
                        do
                          v68 = __ldxr(_X13);
                        while ( __stxr(v68 | v65, _X13) );
                        v62 += 4;
                      }
                      while ( v61 != v62 );
                      goto LABEL_93;
                    }
                  }
                  v56 = 0;
                  v57 = (__int64 *)(*(_QWORD *)(v5 + 640) + ((v55 >> 3) & 0x1FFFFFF8) + 16);
                  while ( 1 )
                  {
                    v58 = *v57;
                    v57 += 4;
                    result = v58;
                    if ( (v58 & (1LL << v55)) != 0 )
                      break;
                    if ( v54 == ++v56 )
                    {
                      LODWORD(v56) = *(_DWORD *)(v5 + 648);
                      if ( (unsigned int)v55 < (unsigned int)v69 )
                        goto LABEL_71;
                      goto LABEL_81;
                    }
                  }
                  if ( (unsigned int)v55 < (unsigned int)v69 )
                    goto LABEL_71;
LABEL_81:
                  v60 = *(_DWORD *)(*(_QWORD *)(v5 + 640) + 32LL * (int)v56);
                  v59 = *(_DWORD *)(*(_QWORD *)(v5 + 640) + 32LL * (int)v56 + 4);
                  if ( (int)v59 >= v60 )
                  {
                    while ( ((*(_QWORD *)((char *)v52 + (((unsigned __int64)v59 >> 3) & 0x1FFFFFF8)) >> v59) & 1) != 0 )
                    {
                      if ( (int)--v59 < v60 )
                        goto LABEL_71;
                    }
                    *(_DWORD *)(v53 + 4 * v51) = v59;
                  }
                  goto LABEL_71;
                }
LABEL_93:
                *(_QWORD *)(v5 + 728) = (unsigned int)(*(_DWORD *)(v5 + 728) & _cpu_possible_mask);
              }
            }
          }
        }
        goto LABEL_94;
      }
    }
    *(_BYTE *)(v5 + 3137) = 1;
    goto LABEL_10;
  }
  __break(0x800u);
  return ufs_qcom_register_minidump(0, a2, a3);
}
