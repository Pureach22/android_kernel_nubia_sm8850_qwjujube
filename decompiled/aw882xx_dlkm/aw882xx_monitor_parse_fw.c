__int64 __fastcall aw882xx_monitor_parse_fw(_DWORD *a1, _DWORD *a2, __int64 a3)
{
  __int64 *v3; // x8
  __int64 v4; // x1
  void *v5; // x0
  const char *v6; // x2
  int v8; // w4
  int v9; // w8
  int v10; // w9
  int v11; // w10
  int v12; // w12
  unsigned __int8 *v13; // x13
  int v14; // w14
  int v15; // w15
  int v16; // t1
  int v17; // w9
  int v18; // w3
  _DWORD *v19; // x19
  _DWORD *v20; // x19
  __int64 *v21; // x8
  __int64 v22; // x1
  void *v23; // x0
  __int64 *v24; // x8
  __int64 v25; // x1
  _DWORD *v26; // x19
  __int64 *v27; // x8
  __int64 v28; // x1
  void *v29; // x0
  _DWORD *v30; // x19
  __int64 *v31; // x8
  __int64 v32; // x1
  void *v33; // x0
  __int64 *v34; // x8
  __int64 v35; // x1
  __int64 *v36; // x8
  __int64 *v37; // x8
  __int64 *v38; // x8
  __int64 *v39; // x8
  __int64 *v40; // x8
  __int64 *v41; // x8
  __int64 *v42; // x8
  __int64 *v43; // x8
  __int64 *v44; // x8
  __int64 *v45; // x8
  __int64 *v46; // x8
  __int64 *v47; // x8
  __int64 **v48; // x21
  _DWORD *v49; // x20
  __int64 *v50; // x9
  __int64 v51; // x8
  __int64 v53; // x1
  __int64 v54; // x1
  __int64 v55; // x1
  __int64 v56; // x1
  __int64 v57; // x1
  __int64 v58; // x1
  __int64 v59; // x0
  __int64 v60; // x1
  __int64 v61; // x1
  __int64 v62; // x1
  __int64 v63; // x0
  _DWORD *v64; // x8
  __int64 v65; // x1
  const char *v66; // x2
  __int64 *v67; // x9
  __int64 v68; // x8
  __int64 v70; // x1
  __int64 v71; // x1
  __int64 v72; // x1
  __int64 v73; // x1
  __int64 v74; // x1
  __int64 v75; // x1
  __int64 v76; // x1
  __int64 v77; // x0
  __int64 v78; // x1
  __int64 v79; // x1
  __int64 v80; // x1
  __int64 v81; // x0
  __int64 *v82; // x9
  __int64 v83; // x8
  __int64 v85; // x1
  __int64 v86; // x1
  __int64 v87; // x1
  __int64 v88; // x1
  __int64 v89; // x1
  __int64 v90; // x1
  __int64 v91; // x0
  __int64 v92; // x1
  __int64 v93; // x1
  __int64 v94; // x1
  __int64 v95; // x0
  __int64 v96; // x1

  if ( !a1 || !a2 )
  {
    printk(&unk_27D0C, a2, a3);
    return 4294967274LL;
  }
  if ( (unsigned int)a3 < 0x54 )
  {
    v3 = *((__int64 **)a1 - 70);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    v5 = &unk_25F50;
    v6 = "aw_monitor_param_check_sum";
LABEL_7:
    printk(v5, v4, v6);
    return 4294967284LL;
  }
  if ( (unsigned int)(a3 + 0x7FFFFFFF) < 0x80000005 )
  {
    v8 = 0;
    v9 = 4;
    do
    {
LABEL_16:
      v17 = *((unsigned __int8 *)a2 + v9++);
      v8 += v17;
    }
    while ( (_DWORD)a3 != v9 );
    goto LABEL_17;
  }
  v10 = 0;
  v11 = 0;
  v12 = (a3 - 4) & 0xFFFFFFFE;
  v13 = (unsigned __int8 *)a2 + 5;
  v9 = v12 + 4;
  v14 = v12;
  do
  {
    v15 = *(v13 - 1);
    v16 = *v13;
    v13 += 2;
    v14 -= 2;
    v10 += v15;
    v11 += v16;
  }
  while ( v14 );
  v8 = v11 + v10;
  if ( (_DWORD)a3 - 4 != v12 )
    goto LABEL_16;
LABEL_17:
  if ( *a2 == v8 )
  {
    v18 = a2[1];
    v19 = a1 - 168;
    switch ( v18 )
    {
      case 66048:
        if ( a2[13] <= (unsigned int)a3 )
        {
          if ( a2[17] <= (unsigned int)a3 )
          {
            if ( a2[12] * a2[11] <= (unsigned int)a3 )
            {
              if ( a2[16] * a2[15] <= (unsigned int)a3 )
              {
                v48 = (__int64 **)(a1 - 140);
                v49 = a1;
                v67 = *((__int64 **)a1 - 70);
                a1[27] = a2[9] & 1;
                a1[28] = a2[7];
                a1[29] = a2[8];
                a1[35] = (a2[9] >> 2) & 1;
                a1[30] = (a2[9] >> 1) & 1;
                a1[36] = (a2[9] >> 3) & 1;
                a1[37] = (a2[9] >> 4) & 1;
                a1[31] = (a2[9] >> 5) & 1;
                a1[32] = a2[10];
                a1[33] = (a2[9] >> 6) & 1;
                a1[34] = a2[14];
                a1[38] = (a2[9] >> 7) & 1;
                a1[39] = (a2[9] >> 8) & 1;
                a1[40] = (a2[9] >> 9) & 1;
                v68 = v67[14];
                if ( !v68 )
                  v68 = *v67;
                printk(&unk_28F21, v68, "aw_monitor_parse_hdr_v_0_1_2");
                v70 = (*v48)[14];
                if ( !v70 )
                  v70 = **v48;
                printk(&unk_23612, v70, "aw_monitor_parse_hdr_v_0_1_2");
                v71 = (*v48)[14];
                if ( !v71 )
                  v71 = **v48;
                printk(&unk_22ADF, v71, "aw_monitor_parse_hdr_v_0_1_2");
                v72 = (*v48)[14];
                if ( !v72 )
                  v72 = **v48;
                printk(&unk_28069, v72, "aw_monitor_parse_hdr_v_0_1_2");
                v73 = (*v48)[14];
                if ( !v73 )
                  v73 = **v48;
                printk(&unk_244A0, v73, "aw_monitor_parse_hdr_v_0_1_2");
                v74 = (*v48)[14];
                if ( !v74 )
                  v74 = **v48;
                printk(&unk_24452, v74, "aw_monitor_parse_hdr_v_0_1_2");
                v75 = (*v48)[14];
                if ( !v75 )
                  v75 = **v48;
                printk(&unk_25317, v75, "aw_monitor_parse_temp_data_v_0_1_2");
                v76 = *((_QWORD *)v49 + 22);
                if ( v76 )
                {
                  devm_kfree(*v48, v76);
                  *((_QWORD *)v49 + 22) = 0;
                }
                v77 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[11], 3520);
                *((_QWORD *)v49 + 22) = v77;
                if ( !v77 )
                  return 4294967284LL;
                *((_BYTE *)v49 + 168) = a2[11];
                aw_monitor_write_data_to_table(v19, v49 + 42, (char *)a2 + (unsigned int)a2[13]);
                v78 = (*v48)[14];
                if ( !v78 )
                  v78 = **v48;
                printk(&unk_280B6, v78, "aw_monitor_parse_temp_data_v_0_1_2");
                v79 = (*v48)[14];
                if ( !v79 )
                  v79 = **v48;
                printk(&unk_22E77, v79, "aw_monitor_parse_vol_data_v_0_1_2");
                v80 = *((_QWORD *)v49 + 24);
                if ( v80 )
                {
                  devm_kfree(*v48, v80);
                  *((_QWORD *)v49 + 24) = 0;
                }
                v81 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[15], 3520);
                v64 = v49;
                *((_QWORD *)v49 + 24) = v81;
                if ( !v81 )
                  goto LABEL_159;
                *((_BYTE *)v49 + 184) = a2[15];
                aw_monitor_write_data_to_table(v19, v49 + 46, (char *)a2 + (unsigned int)a2[17]);
                v65 = (*v48)[14];
                if ( !v65 )
                  v65 = **v48;
                v66 = "aw_monitor_parse_vol_data_v_0_1_2";
LABEL_164:
                printk(&unk_24957, v65, v66);
                *((_BYTE *)v49 + 104) = 1;
                return 0;
              }
              v30 = a1;
              v44 = *((__int64 **)a1 - 70);
              v32 = v44[14];
              if ( !v32 )
                v32 = *v44;
              v33 = &unk_2491E;
            }
            else
            {
              v30 = a1;
              v40 = *((__int64 **)a1 - 70);
              v32 = v40[14];
              if ( !v32 )
                v32 = *v40;
              v33 = &unk_26860;
            }
          }
          else
          {
            v30 = a1;
            v37 = *((__int64 **)a1 - 70);
            v32 = v37[14];
            if ( !v32 )
              v32 = *v37;
            v33 = &unk_23968;
          }
        }
        else
        {
          v30 = a1;
          v31 = *((__int64 **)a1 - 70);
          v32 = v31[14];
          if ( !v32 )
            v32 = *v31;
          v33 = &unk_2337A;
        }
        printk(v33, v32, "aw_monitor_check_fw_v_0_1_2");
        v45 = *((__int64 **)v30 - 70);
        v4 = v45[14];
        if ( !v4 )
          v4 = *v45;
        v5 = &unk_283E6;
        v6 = "aw_monitor_parse_data_v_0_1_2";
        goto LABEL_7;
      case 65792:
        if ( a2[13] <= (unsigned int)a3 )
        {
          if ( a2[17] <= (unsigned int)a3 )
          {
            if ( a2[12] * a2[11] <= (unsigned int)a3 )
            {
              if ( a2[16] * a2[15] <= (unsigned int)a3 )
              {
                v48 = (__int64 **)(a1 - 140);
                v49 = a1;
                v50 = *((__int64 **)a1 - 70);
                a1[27] = a2[9] & 1;
                a1[28] = a2[7];
                a1[29] = a2[8];
                a1[35] = (a2[9] >> 2) & 1;
                a1[30] = (a2[9] >> 1) & 1;
                a1[36] = (a2[9] >> 3) & 1;
                a1[37] = (a2[9] >> 4) & 1;
                a1[31] = (a2[9] >> 5) & 1;
                a1[32] = a2[10];
                a1[33] = (a2[9] >> 6) & 1;
                a1[34] = a2[14];
                v51 = v50[14];
                if ( !v51 )
                  v51 = *v50;
                printk(&unk_28F21, v51, "aw_monitor_parse_hdr_v_0_1_1");
                v53 = (*v48)[14];
                if ( !v53 )
                  v53 = **v48;
                printk(&unk_23612, v53, "aw_monitor_parse_hdr_v_0_1_1");
                v54 = (*v48)[14];
                if ( !v54 )
                  v54 = **v48;
                printk(&unk_28069, v54, "aw_monitor_parse_hdr_v_0_1_1");
                v55 = (*v48)[14];
                if ( !v55 )
                  v55 = **v48;
                printk(&unk_244A0, v55, "aw_monitor_parse_hdr_v_0_1_1");
                v56 = (*v48)[14];
                if ( !v56 )
                  v56 = **v48;
                printk(&unk_24452, v56, "aw_monitor_parse_hdr_v_0_1_1");
                v57 = (*v48)[14];
                if ( !v57 )
                  v57 = **v48;
                printk(&unk_25317, v57, "aw_monitor_parse_temp_data_v_0_1_1");
                v58 = *((_QWORD *)v49 + 22);
                if ( v58 )
                {
                  devm_kfree(*v48, v58);
                  *((_QWORD *)v49 + 22) = 0;
                }
                v59 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[11], 3520);
                *((_QWORD *)v49 + 22) = v59;
                if ( !v59 )
                  return 4294967284LL;
                *((_BYTE *)v49 + 168) = a2[11];
                aw_monitor_write_data_to_table(v19, v49 + 42, (char *)a2 + (unsigned int)a2[13]);
                v60 = (*v48)[14];
                if ( !v60 )
                  v60 = **v48;
                printk(&unk_280B6, v60, "aw_monitor_parse_temp_data_v_0_1_1");
                v61 = (*v48)[14];
                if ( !v61 )
                  v61 = **v48;
                printk(&unk_22E77, v61, "aw_monitor_parse_vol_data_v_0_1_1");
                v62 = *((_QWORD *)v49 + 24);
                if ( v62 )
                {
                  devm_kfree(*v48, v62);
                  *((_QWORD *)v49 + 24) = 0;
                }
                v63 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[15], 3520);
                v64 = v49;
                *((_QWORD *)v49 + 24) = v63;
                if ( !v63 )
                {
LABEL_159:
                  v96 = *((_QWORD *)v64 + 22);
                  if ( v96 )
                  {
                    devm_kfree(*v48, v96);
                    *((_QWORD *)v49 + 22) = 0;
                    *((_BYTE *)v49 + 168) = 0;
                    return 4294967284LL;
                  }
                  return 4294967284LL;
                }
                *((_BYTE *)v49 + 184) = a2[15];
                aw_monitor_write_data_to_table(v19, v49 + 46, (char *)a2 + (unsigned int)a2[17]);
                v65 = (*v48)[14];
                if ( !v65 )
                  v65 = **v48;
                v66 = "aw_monitor_parse_vol_data_v_0_1_1";
                goto LABEL_164;
              }
              v26 = a1;
              v42 = *((__int64 **)a1 - 70);
              v28 = v42[14];
              if ( !v28 )
                v28 = *v42;
              v29 = &unk_2491E;
            }
            else
            {
              v26 = a1;
              v39 = *((__int64 **)a1 - 70);
              v28 = v39[14];
              if ( !v28 )
                v28 = *v39;
              v29 = &unk_26860;
            }
          }
          else
          {
            v26 = a1;
            v36 = *((__int64 **)a1 - 70);
            v28 = v36[14];
            if ( !v28 )
              v28 = *v36;
            v29 = &unk_23968;
          }
        }
        else
        {
          v26 = a1;
          v27 = *((__int64 **)a1 - 70);
          v28 = v27[14];
          if ( !v28 )
            v28 = *v27;
          v29 = &unk_2337A;
        }
        printk(v29, v28, "aw_monitor_check_fw_v_0_1_1");
        v43 = *((__int64 **)v26 - 70);
        v4 = v43[14];
        if ( !v4 )
          v4 = *v43;
        v5 = &unk_283E6;
        v6 = "aw_monitor_parse_data_v_0_1_1";
        goto LABEL_7;
      case 65536:
        if ( a2[15] > (unsigned int)a3 )
        {
          v20 = a1;
          v21 = *((__int64 **)a1 - 70);
          v22 = v21[14];
          if ( !v22 )
            v22 = *v21;
          v23 = &unk_2337A;
LABEL_81:
          printk(v23, v22, "aw_monitor_check_fw");
          v47 = *((__int64 **)v20 - 70);
          v4 = v47[14];
          if ( !v4 )
            v4 = *v47;
          v5 = &unk_283E6;
          v6 = "aw_monitor_parse_data";
          goto LABEL_7;
        }
        if ( a2[20] > (unsigned int)a3 )
        {
          v20 = a1;
          v38 = *((__int64 **)a1 - 70);
          v22 = v38[14];
          if ( !v22 )
            v22 = *v38;
          v23 = &unk_23968;
          goto LABEL_81;
        }
        if ( a2[14] * a2[13] > (unsigned int)a3 )
        {
          v20 = a1;
          v41 = *((__int64 **)a1 - 70);
          v22 = v41[14];
          if ( !v22 )
            v22 = *v41;
          v23 = &unk_26860;
          goto LABEL_81;
        }
        if ( a2[19] * a2[18] > (unsigned int)a3 )
        {
          v20 = a1;
          v46 = *((__int64 **)a1 - 70);
          v22 = v46[14];
          if ( !v22 )
            v22 = *v46;
          v23 = &unk_2491E;
          goto LABEL_81;
        }
        v48 = (__int64 **)(a1 - 140);
        v49 = a1;
        v82 = *((__int64 **)a1 - 70);
        a1[27] = a2[5];
        a1[28] = a2[6];
        a1[29] = a2[7];
        a1[35] = a2[8];
        a1[36] = a2[9];
        a1[37] = a2[10];
        a1[31] = a2[11];
        a1[32] = a2[12];
        a1[33] = a2[16];
        a1[34] = a2[17];
        v83 = v82[14];
        if ( !v83 )
          v83 = *v82;
        printk(&unk_28F21, v83, "aw_monitor_parse_hdr");
        v85 = (*v48)[14];
        if ( !v85 )
          v85 = **v48;
        printk(&unk_23612, v85, "aw_monitor_parse_hdr");
        v86 = (*v48)[14];
        if ( !v86 )
          v86 = **v48;
        printk(&unk_28069, v86, "aw_monitor_parse_hdr");
        v87 = (*v48)[14];
        if ( !v87 )
          v87 = **v48;
        printk(&unk_27A0A, v87, "aw_monitor_parse_hdr");
        v88 = (*v48)[14];
        if ( !v88 )
          v88 = **v48;
        printk(&unk_24452, v88, "aw_monitor_parse_hdr");
        v89 = (*v48)[14];
        if ( !v89 )
          v89 = **v48;
        printk(&unk_25317, v89, "aw_monitor_parse_temp_data");
        v90 = *((_QWORD *)v49 + 22);
        if ( v90 )
        {
          devm_kfree(*v48, v90);
          *((_QWORD *)v49 + 22) = 0;
        }
        v91 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[13], 3520);
        *((_QWORD *)v49 + 22) = v91;
        if ( !v91 )
          return 4294967284LL;
        *((_BYTE *)v49 + 168) = a2[13];
        aw_monitor_write_data_to_table(v19, v49 + 42, (char *)a2 + (unsigned int)a2[15]);
        v92 = (*v48)[14];
        if ( !v92 )
          v92 = **v48;
        printk(&unk_280B6, v92, "aw_monitor_parse_temp_data");
        v93 = (*v48)[14];
        if ( !v93 )
          v93 = **v48;
        printk(&unk_22E77, v93, "aw_monitor_parse_vol_data");
        v94 = *((_QWORD *)v49 + 24);
        if ( v94 )
        {
          devm_kfree(*v48, v94);
          *((_QWORD *)v49 + 24) = 0;
        }
        v95 = devm_kmalloc(*v48, 12LL * (unsigned int)a2[18], 3520);
        v64 = v49;
        *((_QWORD *)v49 + 24) = v95;
        if ( !v95 )
          goto LABEL_159;
        *((_BYTE *)v49 + 184) = a2[18];
        aw_monitor_write_data_to_table(v19, v49 + 46, (char *)a2 + (unsigned int)a2[20]);
        v65 = (*v48)[14];
        if ( !v65 )
          v65 = **v48;
        v66 = "aw_monitor_parse_vol_data";
        goto LABEL_164;
    }
    v34 = *((__int64 **)a1 - 70);
    v35 = v34[14];
    if ( !v35 )
      v35 = *v34;
    printk(&unk_25F20, v35, "aw882xx_monitor_parse_fw");
    return 4294967274LL;
  }
  v24 = *((__int64 **)a1 - 70);
  v25 = v24[14];
  if ( !v25 )
    v25 = *v24;
  printk(&unk_248D8, v25, "aw_monitor_param_check_sum");
  return 4294967284LL;
}
