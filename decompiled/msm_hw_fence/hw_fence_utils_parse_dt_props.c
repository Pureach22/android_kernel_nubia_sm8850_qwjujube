__int64 __fastcall hw_fence_utils_parse_dt_props(__int64 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  __int64 v4; // x8
  int v5; // w0
  unsigned int v6; // w5
  __int64 v7; // x9
  int v8; // w0
  __int64 v9; // x20
  int v10; // w8
  const char *v11; // x3
  int v12; // w0
  char v13; // w8
  unsigned int v14; // w5
  int v15; // w6
  char *v16; // x9
  bool v17; // cf
  char *v18; // x21
  const char *v19; // x3
  unsigned int v20; // w28
  unsigned __int64 v21; // x8
  char *v22; // x9
  unsigned int v23; // w10
  char v24; // w5
  int v25; // w9
  __int64 v26; // x12
  __int64 v27; // x13
  unsigned __int64 v28; // x12
  bool v29; // cc
  unsigned __int64 v30; // x12
  int v31; // w11
  __int64 v32; // x6
  unsigned int *v33; // x9
  unsigned int v34; // w11
  unsigned __int64 v35; // x10
  __int64 v36; // x12
  unsigned __int64 v37; // x5
  __int64 v38; // x7
  __int64 v39; // x8
  unsigned __int64 v40; // x11
  unsigned int v41; // w5
  unsigned int v42; // w8
  __int64 v43; // x0
  __int64 v44; // x4
  __int64 v45; // x24
  unsigned int v46; // w20
  _UNKNOWN **v47; // x25
  unsigned int v48; // w21
  int v49; // w22
  unsigned int v50; // w5
  __int64 v51; // x8
  int v52; // w9
  __int64 v53; // x4
  __int64 v54; // x8
  __int64 v55; // x10
  unsigned int v56; // w11
  __int64 v57; // x11
  int v58; // w12
  int *v59; // x13
  __int64 v60; // x14
  int v61; // w15
  int v62; // t1
  __int64 v63; // x10
  unsigned __int64 v64; // x8
  int *v65; // x9
  int v66; // t1
  __int64 v67; // x8
  __int64 v68; // x0
  int v69; // w8
  __int64 result; // x0
  __int64 v71; // x30
  unsigned int v72; // w19
  void *v73; // x0
  __int64 v74; // x2
  __int64 v75; // x30
  void *v76; // x0
  __int64 v77; // x2
  void *v78; // x0
  __int64 v79; // x2
  __int64 v80; // x30
  __int64 v81; // x21
  void *v82; // x0
  __int64 v83; // x2
  __int64 v84; // x30
  __int64 v85; // x19
  const char *v86; // x3
  __int64 v87; // [xsp+8h] [xbp-98h]
  unsigned int v88; // [xsp+14h] [xbp-8Ch] BYREF
  __int64 v89; // [xsp+18h] [xbp-88h] BYREF
  __int64 v90; // [xsp+20h] [xbp-80h]
  char s[8]; // [xsp+28h] [xbp-78h] BYREF
  __int64 v92; // [xsp+30h] [xbp-70h]
  __int64 v93; // [xsp+38h] [xbp-68h]
  _BYTE v94[13]; // [xsp+40h] [xbp-60h] BYREF
  __int64 v95; // [xsp+50h] [xbp-50h] BYREF
  __int64 v96; // [xsp+58h] [xbp-48h]
  unsigned int v97; // [xsp+60h] [xbp-40h]
  char v98[8]; // [xsp+68h] [xbp-38h] BYREF
  __int64 v99; // [xsp+70h] [xbp-30h]
  __int64 v100; // [xsp+78h] [xbp-28h]
  __int64 v101; // [xsp+80h] [xbp-20h]
  _BYTE v102[11]; // [xsp+88h] [xbp-18h] BYREF
  __int64 v103; // [xsp+98h] [xbp-8h]

  v3 = v1;
  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v88 = 0;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v4 + 744), "qcom,hw-fence-driver-id", &v88, 1, 0) & 0x80000000) == 0 )
    *((_DWORD *)a1 + 3) = v88;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 744), "soccp_controller", a1 + 4201, 1, 0) & 0x80000000) == 0
    && *((_DWORD *)a1 + 8402)
    || *((_DWORD *)a1 + 3) )
  {
    *((_BYTE *)a1 + 33520) = 1;
  }
  v5 = of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 744), "qcom,hw-fence-table-entries", &v88, 1, 0);
  v6 = v88;
  if ( v5 < 0 || !v88 )
  {
    v71 = v3;
    v72 = v5 & (v5 >> 31);
    v73 = &unk_23BDB;
    v74 = 1765;
LABEL_98:
    printk(v73, "hw_fence_utils_parse_dt_props", v74, v71, v72);
    result = v72;
    goto LABEL_115;
  }
  *((_DWORD *)a1 + 4) = v88;
  if ( v6 >= 0x1FFFFFF )
  {
    v75 = v3;
    v76 = &unk_2143E;
    v77 = 1772;
LABEL_100:
    printk(v76, "hw_fence_utils_parse_dt_props", v77, v75, v6);
    goto LABEL_114;
  }
  v7 = *a1;
  *((_DWORD *)a1 + 5) = v6 << 7;
  v8 = of_property_read_variable_u32_array(*(_QWORD *)(v7 + 744), "qcom,hw-fence-queue-entries", &v88, 1, 0);
  v6 = v88;
  if ( v8 < 0 || !v88 )
  {
    v71 = v3;
    v72 = v8 & (v8 >> 31);
    v73 = &unk_25C11;
    v74 = 1780;
    goto LABEL_98;
  }
  *((_DWORD *)a1 + 6) = v88;
  if ( v6 >= 0x3FFFFFF )
  {
    v75 = v3;
    v76 = &unk_273DC;
    v77 = 1789;
    goto LABEL_100;
  }
  v9 = 0;
  if ( *((_BYTE *)a1 + 33520) )
    v10 = 8640;
  else
    v10 = 8328;
  *((_DWORD *)a1 + 7) = 4096;
  *((_DWORD *)a1 + 8) = v10;
  v87 = v3;
  *((_DWORD *)a1 + 15) = 1;
  do
  {
    v11 = *(const char **)((char *)&hw_fence_client_types + v9);
    v93 = 0;
    memset(v94, 0, sizeof(v94));
    *(_QWORD *)s = 0;
    v92 = 0;
    v89 = 0;
    v90 = 0;
    snprintf(s, 0x25u, "qcom,hw-fence-client-type-%s", v11);
    v12 = of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 744), s, &v89, 4, 0);
    if ( v12 < 0 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
        printk(
          &unk_2823C,
          "_parse_client_queue_dt_props_indv",
          1622,
          *(_UNKNOWN **)((char *)&hw_fence_client_types + v9),
          v12 & (unsigned int)(v12 >> 31));
      v14 = *(_DWORD *)((char *)&hw_fence_client_types + v9 + 16);
      v15 = *(_DWORD *)((char *)&hw_fence_client_types + v9 + 20);
      *(_DWORD *)((char *)&hw_fence_client_types + v9 + 24) = *((_DWORD *)a1 + 6);
    }
    else
    {
      v13 = BYTE4(v90);
      v14 = v89;
      v15 = HIDWORD(v89);
      v16 = (char *)&hw_fence_client_types + v9;
      v17 = HIDWORD(v90) >= 2;
      *((_DWORD *)v16 + 6) = v90;
      *((_DWORD *)v16 + 4) = v14;
      *((_DWORD *)v16 + 5) = v15;
      if ( v17 )
      {
        v81 = v87;
        v78 = &unk_2A99D;
        v79 = 1630;
        v80 = v87;
        goto LABEL_111;
      }
      v16[48] = v13;
    }
    v18 = (char *)&hw_fence_client_types + v9;
    if ( v14 > *(_DWORD *)((char *)&hw_fence_client_types + v9 + 12) || (unsigned int)(v15 - 3) <= 0xFFFFFFFD )
    {
      v81 = v87;
      v78 = &unk_25D18;
      v79 = 1639;
      v80 = v87;
      goto LABEL_111;
    }
    v19 = *(const char **)((char *)&hw_fence_client_types + v9);
    v101 = 0;
    memset(v102, 0, sizeof(v102));
    v99 = 0;
    v100 = 0;
    *(_QWORD *)v98 = 0;
    v97 = 0;
    v95 = 0;
    v96 = 0;
    snprintf(v98, 0x2Bu, "qcom,hw-fence-client-type-%s-extra", v19);
    if ( !of_find_property(*(_QWORD *)(*a1 + 744), v98, 0) )
      goto LABEL_56;
    v20 = of_property_count_elems_of_size(*(_QWORD *)(*a1 + 744), v98, 4);
    if ( v20 - 6 <= 0xFFFFFFFA )
    {
      v81 = v87;
      v82 = &unk_27526;
      v83 = 1532;
      v84 = v87;
      goto LABEL_106;
    }
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(*a1 + 744), v98, &v95, v20, 0) & 0x80000000) != 0 )
    {
      v81 = v87;
      v82 = &unk_22147;
      v84 = v87;
      v83 = 1539;
      goto LABEL_106;
    }
    v21 = (unsigned int)v95;
    v22 = (char *)&hw_fence_client_types + v9;
    *(_DWORD *)((char *)&hw_fence_client_types + v9 + 28) = v95;
    if ( v20 <= 1 )
    {
      v23 = *((_DWORD *)v22 + 8);
LABEL_40:
      v24 = 0;
      goto LABEL_41;
    }
    v23 = HIDWORD(v95);
    *((_DWORD *)v22 + 8) = HIDWORD(v95);
    if ( v20 == 2 )
      goto LABEL_40;
    *(_DWORD *)((char *)&hw_fence_client_types + v9 + 40) = v96;
    if ( v20 < 4 )
      goto LABEL_40;
    v24 = BYTE4(v96);
    if ( HIDWORD(v96) >= 2 )
    {
      v81 = v87;
      v82 = &unk_263CE;
      v83 = 1551;
      v84 = v87;
      goto LABEL_106;
    }
    if ( HIDWORD(v96) )
      v25 = 16;
    else
      v25 = 1;
    *(_DWORD *)((char *)&hw_fence_client_types + v9 + 44) = v25;
    if ( v20 != 4 )
    {
      if ( v97 >= 2 )
      {
        v81 = v87;
        v82 = &unk_25D62;
        v83 = 1560;
        v84 = v87;
        goto LABEL_106;
      }
      *((_BYTE *)&hw_fence_client_types + v9 + 49) = 1;
    }
LABEL_41:
    if ( (v21 & 3) != 0 || (v23 & 3) != 0 || (((_BYTE)v23 + (_BYTE)v21) & 7) != 0 )
    {
      v81 = v87;
      v82 = &unk_27567;
      v83 = 1570;
      v84 = v87;
LABEL_106:
      v85 = v84;
      printk(v82, "_parse_client_queue_dt_props_extra", v83, v84, *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
      goto LABEL_107;
    }
    v26 = -56;
    if ( *((_BYTE *)a1 + 33520) )
      v26 = -192;
    v27 = 4294967271LL;
    if ( *((_BYTE *)a1 + 33520) )
      v27 = 4294967231LL;
    v28 = v27 + v26 * *((unsigned int *)v18 + 5);
    v29 = v28 > v21;
    v30 = v28 - v21;
    if ( !v29 )
    {
      v81 = v87;
      v82 = &unk_27B23;
      v83 = 1578;
      v84 = v87;
      goto LABEL_106;
    }
    if ( v30 <= v23 )
    {
      v81 = v87;
      v85 = v87;
      printk(
        &unk_275BF,
        "_parse_client_queue_dt_props_extra",
        1586,
        v87,
        *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
      goto LABEL_107;
    }
    v31 = 16 * *(_DWORD *)((char *)&hw_fence_client_types + v9 + 24);
    if ( (v24 & 1) != 0 )
      v31 = *(_DWORD *)((char *)&hw_fence_client_types + v9 + 24);
    if ( *(_DWORD *)((char *)&hw_fence_client_types + v9 + 40) >= (unsigned int)~v31 )
    {
      v81 = v87;
      v85 = v87;
      printk(
        &unk_2219B,
        "_parse_client_queue_dt_props_extra",
        1596,
        v87,
        *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
LABEL_107:
      printk(
        &unk_24BB9,
        "_parse_client_queue_dt_props_indv",
        1646,
        v85,
        *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
      goto LABEL_112;
    }
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      printk(
        &unk_2A4D3,
        "_parse_client_queue_dt_props_extra",
        1603,
        *(_UNKNOWN **)((char *)&hw_fence_client_types + v9),
        (unsigned int)v21);
LABEL_56:
    v32 = *(unsigned int *)((char *)&hw_fence_client_types + v9 + 24);
    if ( (_DWORD)v32 )
    {
      if ( (unsigned int)v32 >= 0x3FFFFFF )
      {
        v81 = v87;
        v78 = &unk_299A5;
        v79 = 1658;
        v80 = v87;
        goto LABEL_111;
      }
      v33 = (unsigned int *)((char *)&hw_fence_client_types + v9);
      v34 = 192;
      v35 = *((unsigned int *)v18 + 5);
      v36 = 24;
      v37 = v32 << 6;
      if ( *((_BYTE *)a1 + 33520) )
        v36 = 64;
      else
        v34 = 56;
      v39 = v33[7];
      v38 = v33[8];
      v40 = v36 + v34 * (unsigned __int64)(unsigned int)v35;
      if ( (4294963200LL - (v39 + v38) - v40) / v35 <= v37 )
      {
        v81 = v87;
        v85 = v87;
        printk(
          &unk_22995,
          "_parse_client_queue_dt_props_indv",
          1667,
          v87,
          *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
        goto LABEL_112;
      }
      v41 = (v39 + v35 * v37 + v38 + v40 + 4095) & 0xFFFFF000;
      v33[9] = v41;
      if ( v41 > 0x100000 )
      {
        v81 = v87;
        v78 = &unk_256D0;
        v79 = 1677;
        v80 = v87;
LABEL_111:
        v85 = v80;
        printk(v78, "_parse_client_queue_dt_props_indv", v79, v80, *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
LABEL_112:
        printk(
          &unk_2B5CB,
          "_parse_client_queue_dt_props",
          1702,
          v85,
          *(_UNKNOWN **)((char *)&hw_fence_client_types + v9));
LABEL_113:
        printk(&unk_25C6A, "hw_fence_utils_parse_dt_props", 1810, v81, v44);
LABEL_114:
        result = 4294967274LL;
        goto LABEL_115;
      }
    }
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      printk(
        &unk_20574,
        "_parse_client_queue_dt_props_indv",
        1684,
        *(_UNKNOWN **)((char *)&hw_fence_client_types + v9),
        *((unsigned int *)v18 + 4));
    v42 = *((_DWORD *)a1 + 15) + *((_DWORD *)v18 + 4);
    *((_DWORD *)a1 + 15) = v42;
    if ( *((_DWORD *)v18 + 5) == 2 )
      *((_DWORD *)a1 + 14) = v42 - 1;
    v9 += 56;
  }
  while ( v9 != 1456 );
  a1[6] = (__int64)&hw_fence_client_types;
  v43 = _kmalloc_noprof(16LL * v42, 3520);
  v81 = v87;
  a1[5] = v43;
  if ( !v43 )
    goto LABEL_113;
  v45 = 0;
  v46 = (*((_DWORD *)a1 + 8) + (*((_DWORD *)a1 + 14) << 6) + *((_DWORD *)a1 + 5) + 4095) & 0xFFFFF000;
  while ( 2 )
  {
    v47 = &hw_fence_client_types + 7 * v45;
    if ( *((_DWORD *)v47 + 4) )
    {
      v48 = 0;
      v49 = -1;
      do
      {
        v52 = *((_DWORD *)v47 + 2);
        v53 = v52 + v48;
        if ( v52 + v48 )
        {
          v54 = a1[6];
          v55 = (unsigned int)(v53 - 1) >> 6;
          v56 = (v53 - 1) & 0x3F;
          if ( v56 >= *(_DWORD *)(v54 + 56LL * (unsigned int)v55 + 16) )
          {
            v50 = 1665;
          }
          else
          {
            v50 = v56 + 1;
            if ( (unsigned int)v53 >= 0x41 )
            {
              if ( (unsigned int)v53 >= 0x81 )
              {
                v58 = 0;
                v59 = (int *)(v54 + 72);
                v57 = v55 & 0x3FFFFFE;
                v60 = ((unsigned int)(v52 + v49) >> 6) & 0x3FFFFFE;
                do
                {
                  v61 = *(v59 - 14);
                  v62 = *v59;
                  v59 += 28;
                  v60 -= 2;
                  v50 += v61;
                  v58 += v62;
                }
                while ( v60 );
                v50 += v58;
                if ( v57 == v55 )
                  goto LABEL_73;
              }
              else
              {
                v57 = 0;
              }
              v63 = v54 + 56LL * (unsigned int)v57;
              v64 = ((unsigned __int64)(unsigned int)(v52 + v49) >> 6) - v57;
              v65 = (int *)(v63 + 16);
              do
              {
                v66 = *v65;
                v65 += 14;
                --v64;
                v50 += v66;
              }
              while ( v64 );
            }
          }
        }
        else
        {
          v50 = 0;
        }
LABEL_73:
        v51 = a1[5] + 16LL * v50;
        *(_QWORD *)v51 = v47;
        *(_DWORD *)(v51 + 8) = v46;
        *(_DWORD *)(v51 + 12) = 0;
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
          printk(&unk_28D76, "_parse_client_queue_dt_props", 1737, *v47, v53);
        ++v48;
        ++v49;
        v46 += *((_DWORD *)v47 + 9);
      }
      while ( v48 < *((_DWORD *)v47 + 4) );
    }
    if ( ++v45 != 26 )
      continue;
    break;
  }
  v67 = *((unsigned int *)a1 + 15);
  *((_DWORD *)a1 + 115) = v46;
  v68 = _kmalloc_noprof(8 * v67, 3520);
  a1[91] = v68;
  if ( !v68 )
  {
    result = 4294967284LL;
    goto LABEL_115;
  }
  v69 = msm_hw_fence_debug_level;
  if ( (~msm_hw_fence_debug_level & 0x10008) != 0
    || (printk(&unk_2A437, "hw_fence_utils_parse_dt_props", 1823, *((unsigned int *)a1 + 4), *((unsigned int *)a1 + 5)),
        v69 = msm_hw_fence_debug_level,
        (~msm_hw_fence_debug_level & 0x10008) != 0) )
  {
    if ( (~v69 & 0x10008) == 0 )
      goto LABEL_119;
LABEL_91:
    if ( (~v69 & 0x10008) == 0 )
      goto LABEL_120;
    goto LABEL_92;
  }
  printk(&unk_2504D, "hw_fence_utils_parse_dt_props", 1825, *((unsigned int *)a1 + 7), *((unsigned int *)a1 + 8));
  v69 = msm_hw_fence_debug_level;
  if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
    goto LABEL_91;
LABEL_119:
  printk(&unk_20CDA, "hw_fence_utils_parse_dt_props", 1827, *((unsigned int *)a1 + 15), *((unsigned int *)a1 + 14));
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
  {
LABEL_120:
    if ( *((_BYTE *)a1 + 33520) )
      v86 = "true";
    else
      v86 = "false";
    printk(&unk_25CB0, "hw_fence_utils_parse_dt_props", 1829, v86, *((unsigned int *)a1 + 3));
  }
LABEL_92:
  result = 0;
LABEL_115:
  _ReadStatusReg(SP_EL0);
  return result;
}
