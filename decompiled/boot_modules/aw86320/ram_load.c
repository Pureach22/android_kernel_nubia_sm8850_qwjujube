__int64 __fastcall ram_load(
        unsigned __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 result; // x0
  __int64 v10; // x5
  __int64 v11; // x6
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x24
  __int64 v15; // x10
  unsigned __int64 v16; // x12
  unsigned int v17; // w20
  unsigned __int64 v18; // x11
  int v19; // w10
  int v20; // w12
  __int64 v21; // x4
  __int64 v22; // x6
  __int64 v23; // x4
  __int64 v24; // x6
  __int64 v25; // x4
  __int64 v26; // x6
  __int64 v27; // x4
  __int64 v28; // x6
  __int64 v29; // x4
  __int64 v30; // x6
  __int64 v31; // x4
  __int64 v32; // x6
  __int64 v33; // x4
  __int64 v34; // x6
  __int64 v35; // x4
  __int64 v36; // x6
  __int64 v37; // x4
  __int64 v38; // x6
  size_t v39; // x23
  __int64 v40; // x5
  __int64 v41; // x6
  unsigned int *v42; // x20
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  unsigned __int64 v46; // x11
  int v47; // w13
  int v48; // w14
  unsigned __int8 *v49; // x16
  unsigned __int64 v50; // x17
  int v51; // w0
  int v52; // t1
  __int64 v53; // x4
  size_t v54; // x2
  unsigned int v55; // w0
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x4
  void *v59; // x0
  __int64 v60; // x2
  unsigned int v61; // w0
  unsigned int v62; // w23
  unsigned int v63; // w21
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x6
  __int16 v67; // w24
  unsigned int v68; // w0
  __int64 v69; // x5
  __int64 v70; // x6
  __int64 v71; // x4
  void *v72; // x0
  __int64 v73; // x2
  unsigned int v74; // w0
  __int64 v75; // x5
  __int64 v76; // x6
  __int64 v77; // x8
  unsigned __int16 v78; // w10
  __int64 v79; // x0
  unsigned int v80; // w10
  int v81; // w0
  __int64 v82; // x4
  __int64 v83; // x5
  __int64 v84; // x6
  void *v85; // x0
  __int64 v86; // x2
  __int64 v87; // x8
  __int64 v88; // x9
  int v89; // w10
  int v90; // w10
  int v91; // w11
  unsigned __int8 *v92; // x12
  __int64 v93; // x13
  int v94; // w14
  int v95; // t1
  __int64 v96; // x8
  unsigned __int8 *v97; // x9
  int v98; // t1
  unsigned int v99; // w0
  __int64 v100; // x5
  __int64 v101; // x6
  __int64 v102; // x4
  void *v103; // x0
  __int64 v104; // x2
  unsigned int v105; // w0
  __int64 v106; // x5
  __int64 v107; // x6
  __int64 v108; // x4
  void *v109; // x0
  __int64 v110; // x2
  unsigned int v111; // w0
  __int64 v112; // x4
  __int64 v113; // x5
  __int64 v114; // x6
  void *v115; // x0
  __int64 v116; // x2
  unsigned int v117; // w0
  __int64 v118; // x4
  __int64 v119; // x5
  __int64 v120; // x6
  char v121; // [xsp+8h] [xbp-2E8h] BYREF
  _BYTE s[700]; // [xsp+Ch] [xbp-2E4h] BYREF
  unsigned __int16 v123; // [xsp+2C8h] [xbp-28h] BYREF
  int v124; // [xsp+2CAh] [xbp-26h]
  __int16 v125; // [xsp+2CEh] [xbp-22h]
  char *v126; // [xsp+2D0h] [xbp-20h]
  unsigned __int16 v127; // [xsp+2D8h] [xbp-18h]
  __int16 v128; // [xsp+2DAh] [xbp-16h]
  int v129; // [xsp+2DCh] [xbp-14h]
  _BYTE *v130; // [xsp+2E0h] [xbp-10h]
  __int64 v131; // [xsp+2E8h] [xbp-8h]

  v131 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    printk(&unk_A1AF, "aw86320", 446, "ram_load", "micop_ram.bin", *a1, a7);
    v13 = *a1;
    v12 = a1[1];
    v14 = *(unsigned __int8 *)(v12 + 12);
    v15 = v14 + 21;
    if ( *a1 <= v14 + 21 )
    {
      v17 = 0;
      goto LABEL_11;
    }
    v16 = v13 - v14 - 21;
    if ( v16 >= 2 )
    {
      v17 = 0;
      v46 = v13 - v14 - 22;
      if ( (int)v15 + (int)v46 >= (int)v15 && (int)v13 >= (int)v14 + 22 && !HIDWORD(v46) )
      {
        v47 = 0;
        v48 = 0;
        v18 = (v16 & 0xFFFFFFFFFFFFFFFELL) + v15;
        LODWORD(v15) = v15 + (v16 & 0xFFFFFFFE);
        v49 = (unsigned __int8 *)(v14 + v12 + 22);
        v50 = v16 & 0xFFFFFFFFFFFFFFFELL;
        do
        {
          v51 = *(v49 - 1);
          v52 = *v49;
          v49 += 2;
          v50 -= 2LL;
          v47 += v51;
          v48 += v52;
        }
        while ( v50 );
        v17 = v48 + v47;
        if ( v16 == (v16 & 0xFFFFFFFFFFFFFFFELL) )
        {
LABEL_11:
          if ( v17 != *(_DWORD *)v12 )
          {
            printk(&unk_966D, "aw86320", 456, "ram_load", v17, v10, v11);
            result = release_firmware(a1);
            goto LABEL_72;
          }
          printk(&unk_A2E9, "aw86320", 460, "ram_load", v17, v10, v11);
          *(_DWORD *)(a2 + 820) = v17;
          *(_WORD *)(a2 + 848) = *(_WORD *)(a1[1] + 4);
          *(_WORD *)(a2 + 850) = *(_WORD *)(a1[1] + 6);
          *(_WORD *)(a2 + 852) = *(_WORD *)(a1[1] + 8);
          *(_WORD *)(a2 + 854) = *(_WORD *)(a1[1] + 10);
          v21 = *(unsigned __int8 *)(a1[1] + 12);
          *(_BYTE *)(a2 + 856) = v21;
          if ( (_DWORD)v21 )
          {
            v22 = *(unsigned __int8 *)(a1[1] + 13);
            *(_BYTE *)(a2 + 858) = v22;
            printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v21, 1, v22);
            v23 = *(unsigned __int8 *)(a2 + 856);
            if ( (unsigned int)v23 > 1 )
            {
              v24 = *(unsigned __int8 *)(a1[1] + 14);
              *(_BYTE *)(a2 + 859) = v24;
              printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v23, 2, v24);
              v25 = *(unsigned __int8 *)(a2 + 856);
              if ( (unsigned int)v25 >= 3 )
              {
                v26 = *(unsigned __int8 *)(a1[1] + 15);
                *(_BYTE *)(a2 + 860) = v26;
                printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v25, 3, v26);
                v27 = *(unsigned __int8 *)(a2 + 856);
                if ( (unsigned int)v27 >= 4 )
                {
                  v28 = *(unsigned __int8 *)(a1[1] + 16);
                  *(_BYTE *)(a2 + 861) = v28;
                  printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v27, 4, v28);
                  v29 = *(unsigned __int8 *)(a2 + 856);
                  if ( (unsigned int)v29 >= 5 )
                  {
                    v30 = *(unsigned __int8 *)(a1[1] + 17);
                    *(_BYTE *)(a2 + 862) = v30;
                    printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v29, 5, v30);
                    v31 = *(unsigned __int8 *)(a2 + 856);
                    if ( (unsigned int)v31 >= 6 )
                    {
                      v32 = *(unsigned __int8 *)(a1[1] + 18);
                      *(_BYTE *)(a2 + 863) = v32;
                      printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v31, 6, v32);
                      v33 = *(unsigned __int8 *)(a2 + 856);
                      if ( (unsigned int)v33 >= 7 )
                      {
                        v34 = *(unsigned __int8 *)(a1[1] + 19);
                        *(_BYTE *)(a2 + 864) = v34;
                        printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v33, 7, v34);
                        v35 = *(unsigned __int8 *)(a2 + 856);
                        if ( (unsigned int)v35 >= 8 )
                        {
                          v36 = *(unsigned __int8 *)(a1[1] + 20);
                          *(_BYTE *)(a2 + 865) = v36;
                          printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v35, 8, v36);
                          v37 = *(unsigned __int8 *)(a2 + 856);
                          if ( (unsigned int)v37 >= 9 )
                          {
                            v38 = *(unsigned __int8 *)(a1[1] + 21);
                            *(_BYTE *)(a2 + 866) = v38;
                            printk(&unk_9C72, "aw86320", 426, "haptic_parsing_bin_file", v37, 9, v38);
                            if ( *(unsigned __int8 *)(a2 + 856) > 9u )
                              goto LABEL_74;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v39 = *(unsigned __int16 *)(a2 + 854);
          v42 = (unsigned int *)_kmalloc_noprof(v39 + 4, 3520);
          if ( !v42 )
          {
            release_firmware(a1);
            result = printk(&unk_996B, "aw86320", 469, "ram_load", v43, v44, v45);
            goto LABEL_72;
          }
          v53 = *(unsigned __int16 *)(a2 + 854);
          *v42 = v53;
          printk(&unk_98AD, "aw86320", 474, "ram_load", v53, v40, v41);
          v54 = (int)*v42;
          if ( v39 < v54 )
          {
            _fortify_panic(17);
            goto LABEL_74;
          }
          memcpy(v42 + 1, (const void *)(a1[1] + v14 + 21), v54);
          release_firmware(a1);
          memset(s, 0, sizeof(s));
          mutex_lock(a2 + 496);
          v123 = 0;
          v55 = haptic_i2c_read(a2, 17, &v123);
          if ( (v55 & 0x80000000) != 0 )
          {
            v58 = v55;
            v59 = &unk_A1EE;
            v60 = 175;
          }
          else
          {
            v61 = haptic_i2c_write(a2, 17, v123 | 0x10u);
            if ( (v61 & 0x80000000) == 0 )
              goto LABEL_38;
            v58 = v61;
            v59 = &unk_A45E;
            v60 = 184;
          }
          printk(v59, "aw86320", v60, "haptic_i2c_write_bits", v58, v56, v57);
LABEL_38:
          usleep_range_state(1000, 1050, 2);
          v62 = *(unsigned __int16 *)(a2 + 852);
          v63 = *(unsigned __int16 *)(a2 + 850);
          v64 = *(unsigned __int16 *)(a2 + 848);
          v65 = *(unsigned __int16 *)(a2 + 852);
          v66 = *(unsigned __int16 *)(a2 + 850);
          *(_WORD *)(a2 + 824) = v64;
          printk(&unk_A090, "aw86320", 326, "aw86320_container_update", v64, v65, v66);
          v67 = *(_WORD *)(a2 + 824);
          v123 = 0;
          v68 = haptic_i2c_read(a2, 23, &v123);
          if ( (v68 & 0x80000000) != 0 )
          {
            v71 = v68;
            v72 = &unk_A1EE;
            v73 = 175;
          }
          else
          {
            v74 = haptic_i2c_write(a2, 23, v123 & 0xFC00 | v67 & 0x3FFu);
            if ( (v74 & 0x80000000) == 0 )
              goto LABEL_43;
            v71 = v74;
            v72 = &unk_A45E;
            v73 = 184;
          }
          printk(v72, "aw86320", v73, "haptic_i2c_write_bits", v71, v69, v70);
LABEL_43:
          haptic_i2c_write(a2, 24, v62);
          haptic_i2c_write(a2, 25, v63);
          printk(&unk_9E5E, "aw86320", 334, "aw86320_container_update", *v42, v75, v76);
          haptic_i2c_writes(a2, 0x20u, v42 + 1, *v42);
          _const_udelay(21475000);
          haptic_i2c_write(a2, 31, 0x200u);
          v77 = *(_QWORD *)(a2 + 488);
          v121 = 32;
          v78 = *(_WORD *)(v77 + 2);
          v124 = 0x10000;
          v126 = &v121;
          v128 = 1;
          v130 = s;
          v123 = v78;
          v79 = *(_QWORD *)(v77 + 24);
          v127 = v78;
          v80 = *v42;
          v125 = 0;
          v129 = (unsigned __int16)v80;
          v81 = i2c_transfer(v79, &v123, 2);
          if ( v81 < 0 )
          {
            v85 = &unk_9A3E;
            v86 = 78;
          }
          else
          {
            if ( v81 == 2 )
              goto LABEL_48;
            v85 = &unk_9E7F;
            v86 = 81;
          }
          printk(v85, "aw86320", v86, "haptic_i2c_reads", v82, v83, v84);
LABEL_48:
          v87 = *v42;
          if ( (int)v87 < 1 )
          {
            v89 = 0;
            goto LABEL_58;
          }
          if ( (unsigned int)(v87 - 701) >= 0xFFFFFD44 )
          {
            if ( (_DWORD)v87 == 1 )
            {
              v88 = 0;
              v89 = 0;
            }
            else
            {
              v88 = v87 & 0x3FE;
              v90 = 0;
              v91 = 0;
              v92 = &s[1];
              v93 = v88;
              do
              {
                v94 = *(v92 - 1);
                v95 = *v92;
                v92 += 2;
                v93 -= 2;
                v90 += v94;
                v91 += v95;
              }
              while ( v93 );
              v89 = v91 + v90;
              if ( v88 == v87 )
              {
LABEL_58:
                if ( *(_DWORD *)(a2 + 820) == v89 )
                {
                  printk(&unk_A571, "aw86320", 346, "aw86320_container_update", v82, v83, v84);
                  v123 = 0;
                  v99 = haptic_i2c_read(a2, 17, &v123);
                  if ( (v99 & 0x80000000) != 0 )
                  {
                    v102 = v99;
                    v103 = &unk_A1EE;
                    v104 = 175;
                  }
                  else
                  {
                    v111 = haptic_i2c_write(a2, 17, v123 & 0xFFEF);
                    if ( (v111 & 0x80000000) == 0 )
                    {
LABEL_66:
                      mutex_unlock(a2 + 496);
                      v115 = &unk_9F97;
                      *(_BYTE *)a2 = 1;
                      v116 = 482;
LABEL_71:
                      printk(v115, "aw86320", v116, "ram_load", v112, v113, v114);
                      result = kfree(v42);
                      goto LABEL_72;
                    }
                    v102 = v111;
                    v103 = &unk_A45E;
                    v104 = 184;
                  }
                  printk(v103, "aw86320", v104, "haptic_i2c_write_bits", v102, v100, v101);
                  goto LABEL_66;
                }
                v123 = 0;
                v105 = haptic_i2c_read(a2, 17, &v123);
                if ( (v105 & 0x80000000) != 0 )
                {
                  v108 = v105;
                  v109 = &unk_A1EE;
                  v110 = 175;
                }
                else
                {
                  v117 = haptic_i2c_write(a2, 17, v123 & 0xFFEF);
                  if ( (v117 & 0x80000000) == 0 )
                  {
LABEL_70:
                    mutex_unlock(a2 + 496);
                    printk(&unk_9B5B, "aw86320", 351, "aw86320_container_update", v118, v119, v120);
                    v115 = &unk_A28A;
                    v116 = 479;
                    goto LABEL_71;
                  }
                  v108 = v117;
                  v109 = &unk_A45E;
                  v110 = 184;
                }
                printk(v109, "aw86320", v110, "haptic_i2c_write_bits", v108, v106, v107);
                goto LABEL_70;
              }
            }
            v96 = v87 - v88;
            v97 = &s[v88];
            do
            {
              v98 = *v97++;
              --v96;
              v89 += v98;
            }
            while ( v96 );
            goto LABEL_58;
          }
LABEL_74:
          __break(0x5512u);
        }
LABEL_7:
        v19 = v15 + 1;
        do
        {
          v20 = *(unsigned __int8 *)(v12 + v18);
          v18 = v19++;
          v17 += v20;
        }
        while ( v13 > v18 );
        goto LABEL_11;
      }
    }
    else
    {
      v17 = 0;
    }
    v18 = v14 + 21;
    goto LABEL_7;
  }
  printk(&unk_9C4F, "aw86320", 442, "ram_load", "micop_ram.bin", a6, a7);
  result = release_firmware(0);
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
