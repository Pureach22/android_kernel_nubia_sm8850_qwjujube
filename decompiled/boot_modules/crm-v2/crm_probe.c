__int64 __fastcall crm_probe(_QWORD *a1)
{
  __int64 *v1; // x21
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 match_data; // x0
  __int64 property; // x3
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  const char *v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  unsigned __int64 v13; // x0
  const char *v14; // x21
  unsigned __int64 v15; // x0
  const char *v16; // x21
  unsigned __int64 v17; // x0
  const char *v18; // x21
  unsigned __int64 v19; // x0
  unsigned int irq; // w24
  int v21; // w0
  _DWORD *v22; // x8
  int v23; // w21
  unsigned int v24; // w9
  unsigned int v25; // w10
  bool v26; // zf
  unsigned int v27; // w9
  char v28; // w10
  unsigned int v29; // w9
  unsigned int v30; // w10
  unsigned int v31; // w9
  char v32; // w10
  unsigned int v33; // w8
  unsigned int v34; // w9
  unsigned int v35; // w8
  char v36; // w9
  unsigned int v37; // w0
  unsigned __int64 drvs; // x0
  unsigned int v39; // w0
  unsigned __int64 v40; // x0
  int v41; // w8
  __int64 v42; // x26
  __int64 n; // x25
  __int64 v44; // x21
  unsigned int v45; // w0
  __int64 v46; // x0
  unsigned int v47; // w24
  __int64 v48; // x0
  unsigned int v49; // w24
  __int64 v50; // x0
  unsigned int v51; // w24
  int v52; // w8
  int v53; // w9
  int v54; // w0
  _DWORD *v55; // x9
  unsigned int v56; // w1
  unsigned int v57; // w10
  unsigned int v58; // w2
  unsigned int v59; // w11
  unsigned int v60; // w8
  unsigned int v61; // w12
  unsigned int v62; // w9
  unsigned int v63; // w14
  unsigned int v64; // w15
  char v65; // w13
  unsigned int v66; // w16
  unsigned int v67; // w17
  char v68; // w10
  char v69; // w14
  char v70; // w15
  char v71; // w10
  char v72; // w14
  unsigned int v73; // w28
  char v74; // w13
  char v75; // w9
  unsigned int v76; // w12
  int v77; // w9
  unsigned int v78; // w11
  unsigned int v79; // w25
  unsigned int v80; // w24
  __int64 v81; // x23
  __int64 v82; // x22
  __int64 v83; // x27
  __int64 v84; // x8
  __int64 v85; // x0
  int i; // w26
  __int64 v87; // x8
  __int64 v88; // x0
  int j; // w26
  __int64 v90; // x8
  __int64 v91; // x0
  int k; // w26
  __int64 m; // x23
  __int64 v95; // x27
  __int64 v96; // x8
  __int64 v97; // x0
  int v98; // w22
  __int64 v99; // x8
  __int64 v100; // x0
  int v101; // w22
  __int64 v102; // x8
  __int64 v103; // x0
  int v104; // w22
  __int64 v105; // x9
  __int64 v106; // x0
  char v107; // [xsp+10h] [xbp-30h]
  char v108; // [xsp+14h] [xbp-2Ch]
  unsigned int v109; // [xsp+18h] [xbp-28h]
  unsigned int v110; // [xsp+1Ch] [xbp-24h]
  unsigned int v111; // [xsp+28h] [xbp-18h]
  _QWORD v112[2]; // [xsp+30h] [xbp-10h] BYREF

  v1 = a1 + 2;
  v112[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[95];
  v4 = devm_kmalloc(a1 + 2, 312, 3520);
  if ( !v4 )
    goto LABEL_32;
  v5 = v4;
  match_data = of_device_get_match_data(v1);
  *(_QWORD *)(v5 + 288) = match_data;
  if ( !match_data )
    goto LABEL_119;
  property = of_get_property(v3, "label", 0);
  if ( !property )
  {
    property = a1[16];
    if ( !property )
      property = *v1;
  }
  *(_QWORD *)(v5 + 296) = v1;
  *(_QWORD *)(v5 + 304) = a1;
  scnprintf(v5, 20, &unk_B585, property);
  v112[0] = 0;
  v8 = devm_platform_get_and_ioremap_resource(a1, 0, 0);
  *(_QWORD *)(v5 + 32) = v8;
  if ( v8 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_32;
  v9 = devm_platform_get_and_ioremap_resource(a1, 1, v112);
  *(_QWORD *)(v5 + 104) = v9;
  if ( v9 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_32;
  v10 = *(const char **)(v112[0] + 16LL);
  v11 = strnlen(v10, 0x14u);
  if ( v11 == -1 )
    goto LABEL_148;
  if ( v11 == 20 )
    v12 = 20;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x15 )
    goto LABEL_149;
  sized_strscpy(v5 + 80, v10);
  v13 = devm_platform_get_and_ioremap_resource(a1, 2, v112);
  *(_QWORD *)(v5 + 152) = v13;
  if ( v13 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_32;
  v14 = *(const char **)(v112[0] + 16LL);
  v11 = strnlen(v14, 0x14u);
  if ( v11 == -1 )
    goto LABEL_148;
  if ( v11 == 20 )
    v12 = 20;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x15 )
    goto LABEL_149;
  sized_strscpy(v5 + 128, v14);
  v15 = devm_platform_get_and_ioremap_resource(a1, 3, v112);
  *(_QWORD *)(v5 + 200) = v15;
  if ( v15 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_32;
  v16 = *(const char **)(v112[0] + 16LL);
  v11 = strnlen(v16, 0x14u);
  if ( v11 == -1 )
    goto LABEL_148;
  if ( v11 == 20 )
    v12 = 20;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x15 )
    goto LABEL_149;
  sized_strscpy(v5 + 176, v16);
  v17 = devm_platform_get_and_ioremap_resource(a1, 4, v112);
  *(_QWORD *)(v5 + 248) = v17;
  if ( v17 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_32;
  v18 = *(const char **)(v112[0] + 16LL);
  v11 = strnlen(v18, 0x14u);
  if ( v11 == -1 )
  {
LABEL_148:
    _fortify_panic(2, -1, v11 + 1);
  }
  else
  {
    if ( v11 == 20 )
      v12 = 20;
    else
      v12 = v11 + 1;
    if ( v12 < 0x15 )
    {
      sized_strscpy(v5 + 224, v18);
      v19 = devm_platform_get_and_ioremap_resource(a1, 5, v112);
      *(_QWORD *)(v5 + 24) = v19;
      if ( v19 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_32;
      if ( (unsigned int)readl_relaxed((unsigned int *)(v19 + *(unsigned int *)(*(_QWORD *)(v5 + 288) + 64LL))) )
      {
        readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 24) + *(unsigned int *)(*(_QWORD *)(v5 + 288) + 8LL)));
        v21 = readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 24) + *(unsigned int *)(*(_QWORD *)(v5 + 288) + 20LL)));
        v22 = *(_DWORD **)(v5 + 288);
        v23 = v21;
        v24 = v22[9];
        v25 = __rbit32(v24);
        v26 = v24 == 0;
        v27 = v24 & v21;
        v28 = __clz(v25);
        if ( v26 )
          v28 = -1;
        *(_DWORD *)(v5 + 52) = v27 >> v28;
        v29 = v22[8];
        v30 = __rbit32(v29);
        v26 = v29 == 0;
        v31 = v29 & v21;
        v32 = __clz(v30);
        if ( v26 )
          v32 = -1;
        *(_DWORD *)(v5 + 76) = v31 >> v32;
        v33 = v22[12];
        v34 = __rbit32(v33);
        v26 = v33 == 0;
        v35 = v33 & v21;
        v36 = __clz(v34);
        if ( v26 )
          v36 = -1;
        *(_DWORD *)(v5 + 56) = v35 >> v36;
        v37 = of_property_count_elems_of_size(v3, "qcom,hw-drv-ids", 4);
        *(_DWORD *)(v5 + 48) = v37;
        if ( (v37 & 0x80000000) != 0 )
        {
          *(_DWORD *)(v5 + 48) = 0;
        }
        else
        {
          drvs = crm_probe_get_drvs(v5, v37, "qcom,hw-drv-ids", "hw_drv");
          irq = drvs;
          *(_QWORD *)(v5 + 40) = drvs;
          if ( drvs > 0xFFFFFFFFFFFFF000LL )
          {
LABEL_49:
            if ( irq )
              goto LABEL_120;
            v41 = *(_DWORD *)(v5 + 72);
            if ( v41 >= 1 )
              goto LABEL_51;
            goto LABEL_147;
          }
        }
        v39 = of_property_count_elems_of_size(v3, "qcom,sw-drv-ids", 4);
        *(_DWORD *)(v5 + 72) = v39;
        if ( (v39 & 0x80000000) != 0 )
        {
          v52 = 0;
          *(_DWORD *)(v5 + 72) = 0;
        }
        else
        {
          v40 = crm_probe_get_drvs(v5, v39, "qcom,sw-drv-ids", "sw_drv");
          irq = v40;
          *(_QWORD *)(v5 + 64) = v40;
          if ( v40 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_49;
          v52 = *(_DWORD *)(v5 + 72);
        }
        if ( v52 <= *(_DWORD *)(v5 + 76) )
        {
          v53 = *(_DWORD *)(v5 + 48);
          irq = -22;
          if ( v53 > *(_DWORD *)(v5 + 52) || !(v53 | v52) )
            goto LABEL_120;
          v54 = readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 24) + *(unsigned int *)(*(_QWORD *)(v5 + 288) + 56LL)));
          v55 = *(_DWORD **)(v5 + 288);
          v56 = v55[10];
          v57 = v55[11];
          v59 = v55[6];
          v58 = v55[7];
          v60 = v55[13];
          v61 = v55[15];
          v62 = v57 & v23;
          v26 = v57 == 0;
          v63 = __rbit32(v60);
          v64 = __rbit32(v59);
          v65 = __clz(__rbit32(v57));
          v66 = __rbit32(v56);
          v67 = __rbit32(v61);
          v68 = __clz(__rbit32(v58));
          if ( v26 )
            v65 = -1;
          v69 = __clz(v63);
          if ( !v58 )
            v68 = -1;
          v108 = v68;
          v109 = v58;
          v70 = __clz(v64);
          if ( v60 )
            v71 = v69;
          else
            v71 = -1;
          v72 = __clz(v66);
          v73 = v62 >> v65;
          if ( !v59 )
            v70 = -1;
          v74 = __clz(v67);
          if ( v56 )
            v75 = v72;
          else
            v75 = -1;
          v26 = v61 == 0;
          v76 = v61 & v54;
          v107 = v75;
          v77 = *(_DWORD *)(v5 + 48);
          v78 = v59 & v23;
          if ( v26 )
            v74 = -1;
          v79 = v78 >> v70;
          v110 = v56;
          v80 = v76 >> v74;
          if ( v77 >= 1 )
          {
            v81 = 0;
            v111 = (v60 & v23) >> v71;
            v82 = 4LL * v111;
            do
            {
              v83 = *(_QWORD *)(v5 + 40) + 192 * v81;
              if ( *(_BYTE *)(v83 + 180) == 1 )
              {
                *(_DWORD *)v83 = 0;
                v84 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v84 + 4) & 1) != 0 )
                {
                  *(_QWORD *)(v83 + 64) = v84 + 192;
                  *(_DWORD *)(v83 + 56) = v111;
                  *(_DWORD *)(v83 + 60) = v73;
                  v85 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v73, 3520);
                  *(_QWORD *)(v83 + 48) = v85;
                  if ( !v85 )
                    goto LABEL_32;
                  if ( v73 )
                  {
                    for ( i = 0; i != v73; ++i )
                    {
                      *(_QWORD *)(*(_QWORD *)(v83 + 48) + 8LL * i) = devm_kmalloc(*(_QWORD *)(v5 + 296), v82, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v83 + 48) + 8LL * i) )
                        goto LABEL_32;
                    }
                  }
                }
                v87 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v87 + 4) & 2) != 0 )
                {
                  *(_QWORD *)(v83 + 104) = v87 + 256;
                  *(_DWORD *)(v83 + 96) = v111;
                  *(_DWORD *)(v83 + 100) = v80;
                  v88 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v80, 3520);
                  *(_QWORD *)(v83 + 88) = v88;
                  if ( !v88 )
                    goto LABEL_32;
                  if ( v80 )
                  {
                    for ( j = 0; j != v80; ++j )
                    {
                      *(_QWORD *)(*(_QWORD *)(v83 + 88) + 8LL * j) = devm_kmalloc(*(_QWORD *)(v5 + 296), v82, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v83 + 88) + 8LL * j) )
                        goto LABEL_32;
                    }
                  }
                }
                v90 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v90 + 4) & 4) != 0 )
                {
                  *(_QWORD *)(v83 + 144) = v90 + 320;
                  *(_DWORD *)(v83 + 136) = v111;
                  *(_DWORD *)(v83 + 140) = v79;
                  v91 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v79, 3520);
                  *(_QWORD *)(v83 + 128) = v91;
                  if ( !v91 )
                    goto LABEL_32;
                  if ( v79 )
                  {
                    for ( k = 0; k != v79; ++k )
                    {
                      *(_QWORD *)(*(_QWORD *)(v83 + 128) + 8LL * k) = devm_kmalloc(*(_QWORD *)(v5 + 296), v82, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v83 + 128) + 8LL * k) )
                        goto LABEL_32;
                    }
                  }
                }
                v77 = *(_DWORD *)(v5 + 48);
              }
              ++v81;
            }
            while ( v81 < v77 );
          }
          v41 = *(_DWORD *)(v5 + 72);
          if ( v41 >= 1 )
          {
            for ( m = 0; m < v41; ++m )
            {
              v95 = *(_QWORD *)(v5 + 64) + 192 * m;
              if ( *(_BYTE *)(v95 + 180) == 1 )
              {
                *(_DWORD *)v95 = 1;
                v96 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v96 + 4) & 1) != 0 )
                {
                  *(_QWORD *)(v95 + 64) = v96 + 384;
                  *(_DWORD *)(v95 + 56) = 3;
                  *(_DWORD *)(v95 + 60) = v73;
                  v97 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v73, 3520);
                  *(_QWORD *)(v95 + 48) = v97;
                  if ( !v97 )
                    goto LABEL_32;
                  if ( v73 )
                  {
                    v98 = 0;
                    while ( 1 )
                    {
                      *(_QWORD *)(*(_QWORD *)(v95 + 48) + 8LL * v98) = devm_kmalloc(*(_QWORD *)(v5 + 296), 12, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v95 + 48) + 8LL * v98) )
                        break;
                      if ( v73 == ++v98 )
                        goto LABEL_132;
                    }
LABEL_32:
                    irq = -12;
                    goto LABEL_120;
                  }
                }
LABEL_132:
                v99 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v99 + 4) & 2) != 0 )
                {
                  *(_QWORD *)(v95 + 104) = v99 + 448;
                  *(_DWORD *)(v95 + 96) = 3;
                  *(_DWORD *)(v95 + 100) = v80;
                  v100 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v80, 3520);
                  *(_QWORD *)(v95 + 88) = v100;
                  if ( !v100 )
                    goto LABEL_32;
                  if ( v80 )
                  {
                    v101 = 0;
                    do
                    {
                      *(_QWORD *)(*(_QWORD *)(v95 + 88) + 8LL * v101) = devm_kmalloc(*(_QWORD *)(v5 + 296), 12, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v95 + 88) + 8LL * v101) )
                        goto LABEL_32;
                    }
                    while ( v80 != ++v101 );
                  }
                }
                v102 = *(_QWORD *)(v5 + 288);
                if ( (*(_BYTE *)(v102 + 4) & 4) != 0 )
                {
                  *(_QWORD *)(v95 + 144) = v102 + 512;
                  *(_DWORD *)(v95 + 136) = 3;
                  *(_DWORD *)(v95 + 140) = v79;
                  v103 = devm_kmalloc(*(_QWORD *)(v5 + 296), 8LL * v79, 3520);
                  *(_QWORD *)(v95 + 128) = v103;
                  if ( !v103 )
                    goto LABEL_32;
                  if ( v79 )
                  {
                    v104 = 0;
                    do
                    {
                      *(_QWORD *)(*(_QWORD *)(v95 + 128) + 8LL * v104) = devm_kmalloc(*(_QWORD *)(v5 + 296), 12, 3520);
                      if ( !*(_QWORD *)(*(_QWORD *)(v95 + 128) + 8LL * v104) )
                        goto LABEL_32;
                    }
                    while ( v79 != ++v104 );
                  }
                }
                v41 = *(_DWORD *)(v5 + 72);
              }
            }
          }
          v105 = *(_QWORD *)(v5 + 288);
          *(_DWORD *)(v5 + 160) = v79;
          *(_DWORD *)(v5 + 208) = v73;
          *(_QWORD *)(v5 + 120) = v105 + 84;
          *(_DWORD *)(v5 + 112) = (v109 & v23) >> v108;
          *(_QWORD *)(v5 + 168) = v105 + 100;
          *(_QWORD *)(v5 + 216) = v105 + 132;
          *(_QWORD *)(v5 + 264) = v105 + 164;
          *(_DWORD *)(v5 + 256) = (v110 & v23) >> v107;
          if ( v41 >= 1 )
          {
LABEL_51:
            v42 = *(_QWORD *)(v5 + 64);
            for ( n = 0; n < v41; ++n )
            {
              if ( *(_BYTE *)(*(_QWORD *)(v5 + 64) + 192 * n + 180) == 1 )
              {
                v44 = v42 + 192 * n;
                irq = platform_get_irq(*(_QWORD *)(v5 + 304), *(unsigned int *)(v44 + 32));
                if ( (irq & 0x80000000) != 0 )
                  goto LABEL_120;
                v45 = devm_request_threaded_irq(*(_QWORD *)(v5 + 296), irq, crm_vote_complete_irq, 0, 1, v44 + 4, v5);
                if ( v45 )
                {
                  irq = v45;
                  goto LABEL_120;
                }
                *(_DWORD *)(v44 + 176) = irq;
                *(_DWORD *)(v44 + 36) = 0;
                if ( (*(_BYTE *)(*(_QWORD *)(v5 + 288) + 4LL) & 1) != 0 )
                {
                  v46 = devm_kmalloc(*(_QWORD *)(v5 + 296), 80LL * *(unsigned int *)(v44 + 60), 3520);
                  *(_QWORD *)(v44 + 80) = v46;
                  if ( !v46 )
                    goto LABEL_32;
                  if ( *(_DWORD *)(v44 + 60) )
                  {
                    v47 = 0;
                    do
                    {
                      _init_waitqueue_head(
                        *(_QWORD *)(v44 + 80) + 80LL * (int)v47 + 56,
                        "&vcd->sw_votes[k].wait",
                        &crm_probe_get_irqs___key);
                      writel_relaxed(
                        1u,
                        (unsigned int *)(*(_QWORD *)(v44 + 24)
                                       + **(_DWORD **)(v44 + 64)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 64) + 4LL) * *(_DWORD *)(v44 + 32)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 64) + 44LL)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 64) + 8LL) * v47++));
                    }
                    while ( v47 < *(_DWORD *)(v44 + 60) );
                  }
                }
                if ( (*(_BYTE *)(*(_QWORD *)(v5 + 288) + 4LL) & 2) != 0 )
                {
                  v48 = devm_kmalloc(*(_QWORD *)(v5 + 296), 80LL * *(unsigned int *)(v44 + 100), 3520);
                  *(_QWORD *)(v44 + 120) = v48;
                  if ( !v48 )
                    goto LABEL_32;
                  if ( *(_DWORD *)(v44 + 100) )
                  {
                    v49 = 0;
                    do
                    {
                      _init_waitqueue_head(
                        *(_QWORD *)(v44 + 120) + 80LL * (int)v49 + 56,
                        "&vcd->sw_votes[k].wait",
                        &crm_probe_get_irqs___key);
                      writel_relaxed(
                        1u,
                        (unsigned int *)(*(_QWORD *)(v44 + 24)
                                       + **(_DWORD **)(v44 + 104)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 104) + 4LL) * *(_DWORD *)(v44 + 32)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 104) + 44LL)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 104) + 8LL) * v49++));
                    }
                    while ( v49 < *(_DWORD *)(v44 + 100) );
                  }
                }
                if ( (*(_BYTE *)(*(_QWORD *)(v5 + 288) + 4LL) & 4) != 0 )
                {
                  v50 = devm_kmalloc(*(_QWORD *)(v5 + 296), 80LL * *(unsigned int *)(v44 + 140), 3520);
                  *(_QWORD *)(v44 + 160) = v50;
                  if ( !v50 )
                    goto LABEL_32;
                  if ( *(_DWORD *)(v44 + 140) )
                  {
                    v51 = 0;
                    do
                    {
                      _init_waitqueue_head(
                        *(_QWORD *)(v44 + 160) + 80LL * (int)v51 + 56,
                        "&vcd->sw_votes[k].wait",
                        &crm_probe_get_irqs___key);
                      writel_relaxed(
                        1u,
                        (unsigned int *)(*(_QWORD *)(v44 + 24)
                                       + **(_DWORD **)(v44 + 144)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 144) + 4LL) * *(_DWORD *)(v44 + 32)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 144) + 44LL)
                                       + *(_DWORD *)(*(_QWORD *)(v44 + 144) + 8LL) * v51++));
                    }
                    while ( v51 < *(_DWORD *)(v44 + 140) );
                  }
                }
                v41 = *(_DWORD *)(v5 + 72);
              }
            }
          }
LABEL_147:
          crm_set_chn_behave(v5);
          crm_set_hw_chn_switch_ctrl(v5);
          *(_QWORD *)(v5 + 272) = v5 + 272;
          *(_QWORD *)(v5 + 280) = v5 + 272;
          list_add_tail();
          irq = 0;
          a1[21] = v5;
LABEL_120:
          _ReadStatusReg(SP_EL0);
          return irq;
        }
      }
      else
      {
        printk(&unk_B81E, "crm_v2", "crm_probe", v5);
      }
LABEL_119:
      irq = -22;
      goto LABEL_120;
    }
  }
LABEL_149:
  v106 = _fortify_panic(7, 20, v12);
  return crm_set_chn_behave(v106);
}
