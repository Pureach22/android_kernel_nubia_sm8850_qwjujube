__int64 __fastcall syna_cdev_ioctls(__int64 a1, unsigned __int8 a2, unsigned __int64 a3)
{
  _QWORD *v5; // x20
  size_t v6; // x22
  __int64 v7; // x9
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x1
  unsigned __int64 StatusReg; // x26
  __int64 v12; // x27
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v19; // x9
  size_t v20; // x0
  __int64 v21; // x2
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  size_t v25; // x23
  int v26; // w8
  unsigned __int64 v27; // x21
  char v28; // w8
  __int64 v29; // x24
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x1
  const char *v32; // x1
  __int64 v33; // x2
  __int64 v34; // x2
  __int64 (__fastcall *v35)(_QWORD); // x8
  void *v36; // x0
  char v37; // w8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v41; // x9
  size_t v42; // x2
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  unsigned int v46; // w23
  __int64 v47; // x0
  int v48; // w8
  __int64 v50; // x23
  int v51; // w8
  bool v52; // zf
  int v53; // w8
  bool v54; // zf
  char v55; // w9
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
  unsigned __int64 v59; // x9
  int v60; // w0
  unsigned __int64 v61; // x8
  unsigned __int64 v63; // x9
  void *v64; // x0
  __int64 v65; // x22
  char v66; // w8
  void *v67; // x0
  size_t v68; // x20
  __int64 v69; // x24
  __int64 v70; // x0
  __int64 v71; // x2
  __int64 v72; // x0
  __int64 v73; // x2
  _QWORD *v74; // x21
  _QWORD **v75; // x22
  _QWORD *v76; // x8
  __int64 v77; // x9
  __int64 v78; // x0
  int v79; // w8
  char v80; // w8
  __int64 v81; // x28
  unsigned __int64 v82; // x8
  unsigned __int64 v83; // x8
  unsigned __int64 v85; // x9
  unsigned __int64 v86; // x8
  unsigned __int64 v88; // x9
  unsigned int v89; // w22
  _QWORD *v90; // x24
  __int64 v91; // x0
  int v92; // w8
  bool v93; // zf
  __int64 v94; // x22
  int v95; // w8
  bool v96; // zf
  int v97; // w8
  bool v98; // zf
  _QWORD *v99; // x24
  __int64 v100; // x25
  __int64 v101; // x22
  unsigned __int64 v102; // x8
  unsigned __int64 v103; // x8
  unsigned __int64 v105; // x9
  unsigned __int64 v106; // x8
  unsigned __int64 v108; // x9
  _QWORD *v109; // x8
  __int64 v110; // x9
  unsigned int v111; // w8
  void (__fastcall *v112)(__int64, __int64); // x8
  __int64 *v113; // x0
  int v114; // w0
  __int64 v115; // x2
  __int64 v116; // x24
  unsigned int v117; // w22
  void *v118; // x0
  __int64 v119; // x22
  __int64 v120; // x0
  __int64 v121; // x2
  __int64 v122; // x0
  __int64 v123; // x2
  __int64 v124; // x2
  __int64 v125; // x8
  __int64 v126; // x1
  __int16 v127; // w8
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x8
  unsigned __int64 v131; // x9
  int v132; // w0
  unsigned __int64 v133; // x8
  unsigned __int64 v135; // x9
  __int64 v136; // x2
  char v137; // w9
  __int64 v138; // x8
  int v139; // w23
  unsigned __int64 v140; // x8
  unsigned __int64 v141; // x8
  unsigned __int64 v143; // x9
  unsigned __int64 v144; // x8
  unsigned __int64 v146; // x9
  int v147; // w8
  void (*v148)(void); // x8
  __int64 (__fastcall *v149)(_QWORD); // x8
  __int64 v150; // x2
  __int64 v151; // x22
  unsigned int v152; // w23
  void *v153; // x0
  __int64 v154; // x23
  __int64 v155; // x0
  __int64 v156; // x2
  __int64 v157; // x0
  __int64 v158; // x2
  char v159; // w8
  __int64 v160; // x23
  unsigned __int64 v161; // x8
  size_t v162; // x21
  int v163; // w8
  unsigned __int64 v164; // x8
  size_t v165; // x0
  unsigned __int64 v166; // x8
  unsigned __int64 v168; // x9
  unsigned __int64 v169; // x8
  unsigned __int64 v171; // x9
  __int64 v172; // x21
  int v173; // w0
  __int64 v174; // x23
  __int64 v175; // x0
  __int64 v176; // x2
  __int64 v177; // x0
  __int64 v178; // x2
  char *v179; // x0
  char *v180; // x23
  unsigned __int64 v181; // x8
  _QWORD *v182; // x1
  void *v183; // x0
  const char *v184; // x1
  __int64 v185; // x2
  unsigned int v186; // w19
  unsigned __int64 v187; // x8
  unsigned __int64 v189; // x9
  unsigned __int64 v190; // x8
  unsigned __int64 v192; // x9
  __int64 v193; // x21
  int v194; // w2
  int v195; // w8
  bool v196; // zf
  bool v197; // w8
  const char *v198; // x1
  size_t v199; // x24
  _BYTE *v200; // x20
  unsigned __int64 v201; // x8
  size_t v202; // x25
  unsigned __int64 v203; // x8
  unsigned __int64 v205; // x9
  unsigned __int64 v206; // x8
  unsigned __int64 v208; // x9
  _DWORD *v209; // x8
  int v210; // w0
  __int64 v211; // x2
  void *v212; // x0
  unsigned __int64 v213; // x8
  unsigned __int64 v215; // x9
  unsigned __int64 v216; // x8
  unsigned __int64 v218; // x9
  unsigned __int64 v219; // x8
  unsigned __int64 v221; // x9
  unsigned __int64 v222; // x8
  unsigned __int64 v224; // x9
  unsigned int v225; // w25
  __int64 v226; // x2
  int v227; // w8
  int v228; // w9
  __int16 v229; // w8
  unsigned int v230; // w12
  int v231; // w8
  __int64 v232; // x22
  unsigned __int64 v233; // x8
  unsigned __int64 v234; // x8
  unsigned __int64 v236; // x9
  unsigned __int64 v237; // x8
  unsigned __int64 v239; // x9
  char v240; // w8
  __int64 v241; // x0
  void *v242; // x20
  __int64 v243; // x0
  __int64 v244; // x2
  void (__fastcall *v245)(_QWORD); // x8
  unsigned int v246; // w8
  unsigned int v247; // w20
  __int64 v248; // x2
  int v249; // w8
  char v250; // w8
  unsigned __int64 v251; // x8
  unsigned __int64 v252; // x8
  unsigned __int64 v254; // x9
  unsigned __int64 v255; // x8
  unsigned __int64 v257; // x9
  const char *v259; // x1
  void *v260; // x0
  const char *v261; // x1
  void *v262; // x0
  const char *v263; // x1
  void *v264; // x0
  const char *v265; // x1
  unsigned int v266; // w20
  void *v267; // x0
  size_t v268; // x8
  size_t v269; // x2
  unsigned __int64 v270; // x1
  __int64 v271; // x0
  const char *v272; // x2
  __int64 (__fastcall *v273)(__int64, __int64); // x8
  int v274; // w0
  int v275; // w8
  void *v276; // x0
  __int64 (__fastcall *v277)(__int64, __int64); // x8
  __int64 v278; // x0
  __int64 v279; // x0
  __int64 v280; // x0
  __int64 v281; // x0
  __int64 v282; // [xsp+8h] [xbp-128h] BYREF
  unsigned __int64 v283; // [xsp+10h] [xbp-120h]
  unsigned int v284; // [xsp+1Ch] [xbp-114h] BYREF
  void *src; // [xsp+20h] [xbp-110h] BYREF
  size_t n; // [xsp+28h] [xbp-108h]
  __int64 v287; // [xsp+30h] [xbp-100h] BYREF
  __int64 v288; // [xsp+38h] [xbp-F8h]
  __int64 v289; // [xsp+40h] [xbp-F0h]
  __int64 v290; // [xsp+48h] [xbp-E8h]
  __int64 v291; // [xsp+50h] [xbp-E0h]
  __int64 v292; // [xsp+58h] [xbp-D8h]
  __int64 v293; // [xsp+60h] [xbp-D0h]
  __int64 v294; // [xsp+68h] [xbp-C8h]
  __int64 v295; // [xsp+70h] [xbp-C0h]
  __int64 v296; // [xsp+78h] [xbp-B8h]
  __int64 v297; // [xsp+80h] [xbp-B0h]
  __int64 v298; // [xsp+88h] [xbp-A8h]
  __int64 v299; // [xsp+90h] [xbp-A0h]
  __int64 v300; // [xsp+98h] [xbp-98h]
  __int64 v301; // [xsp+A0h] [xbp-90h]
  __int64 v302; // [xsp+A8h] [xbp-88h]
  __int64 v303; // [xsp+B0h] [xbp-80h]
  __int64 v304; // [xsp+B8h] [xbp-78h]
  __int64 v305; // [xsp+C0h] [xbp-70h]
  __int64 v306; // [xsp+C8h] [xbp-68h]
  __int64 v307; // [xsp+D0h] [xbp-60h]
  __int64 v308; // [xsp+D8h] [xbp-58h]
  __int64 v309; // [xsp+E0h] [xbp-50h]
  __int64 v310; // [xsp+E8h] [xbp-48h]
  __int64 v311; // [xsp+F0h] [xbp-40h]
  __int64 v312; // [xsp+F8h] [xbp-38h]
  __int64 v313; // [xsp+100h] [xbp-30h]
  __int64 v314; // [xsp+108h] [xbp-28h]
  __int64 v315; // [xsp+110h] [xbp-20h]
  __int64 v316; // [xsp+118h] [xbp-18h]
  __int64 v317; // [xsp+120h] [xbp-10h]

  v317 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v282 = 0;
  v283 = 0;
  v5 = *(_QWORD **)(g_cdev_data + 168);
  mutex_lock(&qword_316A0);
  v6 = a2;
  if ( a2 <= 0xFu )
  {
    if ( a2 <= 1u )
    {
      if ( a2 )
      {
        v7 = v5[78];
        v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 64);
        if ( v8 )
        {
          if ( a3 == 1 )
          {
            v9 = v7 + 8;
            v10 = 1;
            goto LABEL_44;
          }
          if ( !a3 )
          {
            v9 = v7 + 8;
            v10 = 0;
LABEL_44:
            if ( *((_DWORD *)v8 - 1) != 875454897 )
              __break(0x8228u);
            LODWORD(v6) = v8(v9, v10);
            goto LABEL_357;
          }
          goto LABEL_356;
        }
        LODWORD(v6) = -22;
      }
      else
      {
        LODWORD(v6) = syna_tcm_reset(*v5, *(unsigned int *)(*v5 + 524LL));
        if ( (v6 & 0x80000000) != 0 )
        {
          v36 = &unk_39948;
        }
        else
        {
          if ( *(_BYTE *)(*v5 + 9LL) != 1 )
            goto LABEL_357;
          v35 = (__int64 (__fastcall *)(_QWORD))v5[215];
          if ( *((_DWORD *)v35 - 1) != -1373616356 )
            __break(0x8228u);
          LODWORD(v6) = v35(v5);
          if ( (v6 & 0x80000000) == 0 )
            goto LABEL_357;
          v36 = &unk_324EB;
        }
        printk(v36, "syna_cdev_ioctl_old_dispatch", v34);
      }
LABEL_357:
      mutex_unlock(&qword_316A0);
      _ReadStatusReg(SP_EL0);
      return (int)v6;
    }
    if ( a2 != 2 )
    {
      if ( a2 == 3 )
      {
        LODWORD(v6) = 0;
        *((_BYTE *)v5 + 1412) = 1;
      }
      else
      {
        v198 = "syna_cdev_ioctl_old_dispatch";
LABEL_280:
        printk(&unk_3550D, v198, (unsigned int)v6);
        LODWORD(v6) = -22;
      }
      goto LABEL_357;
    }
LABEL_356:
    LODWORD(v6) = 0;
    goto LABEL_357;
  }
  if ( a2 == 16 )
  {
    LODWORD(v6) = 1;
    goto LABEL_357;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = a3 << 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v13 = a3 & (v12 >> 8);
  if ( v13 > 0x7FFFFFFFF0LL )
  {
    v20 = 16;
    goto LABEL_269;
  }
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v19 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v19);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  v20 = _arch_copy_from_user(&v282, a3 & 0xFF7FFFFFFFFFFFFFLL, 16);
  v22 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v24 - 4096);
  _WriteStatusReg(TTBR1_EL1, v24);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v22);
  if ( v20 )
  {
LABEL_269:
    if ( v20 < 0x11 )
    {
      v186 = v20;
      memset((char *)&v282 - v20 + 16, 0, v20);
      v183 = &unk_34178;
      v184 = "syna_cdev_ioctls";
      v185 = v186;
      goto LABEL_360;
    }
LABEL_462:
    v42 = v20;
LABEL_463:
    _fortify_panic(15, 0, v42);
LABEL_464:
    _fortify_panic(15, v270, v269);
LABEL_465:
    _fortify_panic(15, v31, v6);
    goto LABEL_466;
  }
  v25 = HIDWORD(v282);
  if ( HIDWORD(v282) > 0x1000 )
  {
    printk(&unk_3770F, "syna_cdev_ioctls", v21);
    LODWORD(v6) = -52;
    goto LABEL_357;
  }
  v26 = a2 - 17;
  v27 = v283;
  switch ( v26 )
  {
    case 0:
      printk(&unk_37E75, "syna_cdev_ioctl_store_pid", v21);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 )
        goto LABEL_353;
      goto LABEL_352;
    case 1:
      v28 = *((_BYTE *)v5 + 1410);
      LODWORD(src) = 0;
      if ( (v28 & 1) == 0 )
      {
        v259 = "syna_cdev_ioctl_enable_irq";
LABEL_422:
        printk(&unk_3D1E9, v259, v21);
        LODWORD(v6) = -6;
        goto LABEL_350;
      }
      if ( *((_DWORD *)v5 + 351) == 3 )
      {
        v262 = &unk_382A7;
        v263 = "syna_cdev_ioctl_enable_irq";
LABEL_381:
        printk(v262, v263, v21);
        LODWORD(v6) = 0;
        goto LABEL_350;
      }
      if ( HIDWORD(v282) < 4 || (unsigned int)v282 <= 3 )
      {
        v264 = &unk_3940D;
        v265 = "syna_cdev_ioctl_enable_irq";
        v21 = HIDWORD(v282);
      }
      else
      {
        v29 = v5[78];
        if ( *(_QWORD *)(v29 + 64) )
        {
          if ( HIDWORD(v282) >= 5 )
          {
            _copy_overflow(4, HIDWORD(v282));
            goto LABEL_35;
          }
          _check_object_size(&src, HIDWORD(v282), 0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v30 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v30 = v27 & ((__int64)(v27 << 8) >> 8);
          v6 = v25;
          if ( 0x8000000000LL - v25 >= v30 )
          {
            v203 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v205 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v205 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v205);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v203);
            v6 = _arch_copy_from_user(&src, v27 & 0xFF7FFFFFFFFFFFFFLL, v25);
            v206 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v208 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v208 - 4096);
            _WriteStatusReg(TTBR1_EL1, v208);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v206);
            if ( !v6 )
            {
LABEL_292:
              if ( (_DWORD)src == 1 )
              {
                if ( (*(_BYTE *)(v5[78] + 188LL) & 1) != 0 )
                  goto LABEL_302;
                v277 = *(__int64 (__fastcall **)(__int64, __int64))(v29 + 64);
                if ( *((_DWORD *)v277 - 1) != 875454897 )
                  __break(0x8228u);
                v274 = v277(v29 + 8, 1);
                if ( (v274 & 0x80000000) == 0 )
                {
                  printk(&unk_3B187, "syna_cdev_ioctl_enable_irq", v211);
                  LODWORD(v6) = 0;
                  LODWORD(qword_31700) = 0;
                  goto LABEL_350;
                }
              }
              else
              {
                if ( !(_DWORD)src )
                {
                  if ( *(_BYTE *)(v5[78] + 188LL) == 1 )
                  {
                    v209 = *(_DWORD **)(v29 + 64);
                    if ( *(v209 - 1) != 875454897 )
                      __break(0x8228u);
                    v210 = ((__int64 (__fastcall *)(__int64, _QWORD))v209)(v29 + 8, 0);
                    if ( v210 < 0 )
                    {
                      LODWORD(v6) = v210;
                      v212 = &unk_33001;
LABEL_442:
                      printk(v212, "syna_cdev_ioctl_enable_irq", v211);
                      goto LABEL_350;
                    }
                    printk(&unk_37732, "syna_cdev_ioctl_enable_irq", v211);
                    LODWORD(v6) = 0;
                    LODWORD(qword_31700) = *(_DWORD *)(*v5 + 524LL);
LABEL_350:
                    if ( (v6 & 0x80000000) != 0 )
                      goto LABEL_357;
LABEL_351:
                    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) == 0 )
                    {
LABEL_352:
                      v251 = a3;
                      if ( (*(_QWORD *)StatusReg & 0x4000000) == 0 )
                      {
LABEL_354:
                        if ( v251 > 0x7FFFFFFFF0LL )
                        {
                          v185 = 16;
                        }
                        else
                        {
                          v252 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v254 = *(_QWORD *)(StatusReg + 8);
                          _WriteStatusReg(
                            TTBR1_EL1,
                            v254 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                          _WriteStatusReg(TTBR0_EL1, v254);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v252);
                          v185 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v282, 16);
                          v255 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v257 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                          _WriteStatusReg(TTBR0_EL1, v257 - 4096);
                          _WriteStatusReg(TTBR1_EL1, v257);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v255);
                          if ( !(_DWORD)v185 )
                            goto LABEL_356;
                        }
                        v183 = &unk_3B874;
                        v184 = "syna_cdev_ioctls";
LABEL_360:
                        printk(v183, v184, v185);
                        LODWORD(v6) = -52;
                        goto LABEL_357;
                      }
                    }
LABEL_353:
                    v251 = a3 & (v12 >> 8);
                    goto LABEL_354;
                  }
LABEL_302:
                  LODWORD(v6) = 0;
                  goto LABEL_350;
                }
                v273 = *(__int64 (__fastcall **)(__int64, __int64))(v29 + 64);
                if ( *((_DWORD *)v273 - 1) != 875454897 )
                  __break(0x8228u);
                v274 = v273(v29 + 8, 1);
                if ( (v274 & 0x80000000) == 0 )
                {
                  v275 = (int)src;
                  if ( (unsigned int)src < *(_DWORD *)(*v5 + 524LL) )
                  {
                    v275 = *(_DWORD *)(*v5 + 524LL);
                    LODWORD(src) = v275;
                  }
                  LODWORD(qword_31700) = v275;
                  printk(&unk_3B187, "syna_cdev_ioctl_enable_irq", v211);
                  printk(&unk_3C517, "syna_cdev_ioctl_enable_irq", (unsigned int)qword_31700);
                  goto LABEL_302;
                }
              }
              LODWORD(v6) = v274;
              v212 = &unk_33CD2;
              goto LABEL_442;
            }
          }
          if ( v25 - v6 <= 4 )
            v31 = 4 - (v25 - v6);
          else
            v31 = 0;
          if ( v31 >= v6 )
          {
            memset((char *)&src + v25 - v6, 0, v6);
            LODWORD(v25) = v6;
            if ( !(_DWORD)v6 )
              goto LABEL_292;
LABEL_35:
            v32 = "syna_cdev_ioctl_enable_irq";
            v33 = (unsigned int)v25;
            goto LABEL_410;
          }
          goto LABEL_465;
        }
        v264 = &unk_33CAB;
        v265 = "syna_cdev_ioctl_enable_irq";
      }
LABEL_390:
      printk(v264, v265, v21);
      LODWORD(v6) = -22;
      goto LABEL_350;
    case 2:
      v114 = syna_cdev_ioctl_raw_read(v5, v283, HIDWORD(v282), (unsigned int)v282);
      goto LABEL_192;
    case 3:
      v114 = syna_cdev_ioctl_raw_write(v5, v283, HIDWORD(v282), (unsigned int)v282);
LABEL_192:
      LODWORD(v6) = v114;
      goto LABEL_350;
    case 4:
      v80 = *((_BYTE *)v5 + 1410);
      v81 = v5[78];
      v284 = 0;
      if ( (v80 & 1) == 0 )
      {
        v259 = "syna_cdev_ioctl_get_frame";
        goto LABEL_422;
      }
      if ( *((_DWORD *)v5 + 351) == 3 )
      {
        v262 = &unk_382DE;
        v263 = "syna_cdev_ioctl_get_frame";
        goto LABEL_381;
      }
      if ( HIDWORD(v282) <= 3 )
      {
        v264 = &unk_35535;
        v265 = "syna_cdev_ioctl_get_frame";
        v21 = HIDWORD(v282);
        goto LABEL_390;
      }
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v82 = v283, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v82 = v283 & ((__int64)(v283 << 8) >> 8);
      if ( v82 > 0x7FFFFFFFFCLL )
      {
        v20 = 4;
      }
      else
      {
        v83 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v85 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v85 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v85);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v83);
        v20 = _arch_copy_from_user(&v284, v27 & 0xFF7FFFFFFFFFFFFFLL, 4);
        v86 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v88 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v88 - 4096);
        _WriteStatusReg(TTBR1_EL1, v88);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v86);
        if ( !v20 )
        {
          v89 = v284;
          v90 = v5 + 159;
          if ( (_QWORD *)v5[159] == v5 + 159 )
          {
            v91 = _msecs_to_jiffies(v284);
            v92 = *((_DWORD *)v5 + 316);
            if ( v91 )
              v93 = 1;
            else
              v93 = v92 == 0;
            if ( !v93 )
              v91 = 1;
            if ( !v92 && v91 )
            {
              v288 = 0;
              v289 = 0;
              n = 0;
              v287 = 0;
              src = nullptr;
              v94 = _msecs_to_jiffies(v89);
              init_wait_entry(&src, 0);
              v91 = prepare_to_wait_event(v5 + 161, &src, 1);
              v95 = *((_DWORD *)v5 + 316);
              if ( v94 )
                v96 = 1;
              else
                v96 = v95 == 0;
              if ( !v96 )
                v94 = 1;
              if ( v95 || !v94 )
              {
LABEL_145:
                finish_wait(v5 + 161, &src);
                LODWORD(v91) = v94;
              }
              else
              {
                while ( !v91 )
                {
                  v94 = schedule_timeout(v94);
                  v91 = prepare_to_wait_event(v5 + 161, &src, 1);
                  v97 = *((_DWORD *)v5 + 316);
                  if ( v94 )
                    v98 = 1;
                  else
                    v98 = v97 == 0;
                  if ( !v98 )
                    v94 = 1;
                  if ( v97 || !v94 )
                    goto LABEL_145;
                }
              }
            }
            if ( !(_DWORD)v91 )
            {
              LODWORD(v282) = 0;
              LODWORD(v6) = -110;
              goto LABEL_350;
            }
          }
          if ( (_QWORD *)*v90 == v90 )
          {
            LODWORD(v6) = -61;
            goto LABEL_350;
          }
          mutex_lock(&qword_316D0);
          v99 = (_QWORD *)*v90;
          v100 = *((unsigned int *)v99 + 6);
          if ( (unsigned int)v100 > (unsigned int)v25 )
          {
            printk(&unk_361C4, "syna_cdev_ioctl_get_frame", (unsigned int)v25);
            LODWORD(v6) = -75;
            goto LABEL_350;
          }
          v101 = v99[2];
          _check_object_size(v101, *((unsigned int *)v99 + 6), 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v102 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v102 = v27 & ((__int64)(v27 << 8) >> 8);
          if ( 0x8000000000LL - v100 >= v102 )
          {
            v103 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v105 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v105 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v105);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v103);
            LODWORD(v100) = _arch_copy_to_user(v27 & 0xFF7FFFFFFFFFFFFFLL, v101, v100);
            v106 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v108 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v108 - 4096);
            _WriteStatusReg(TTBR1_EL1, v108);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v106);
          }
          if ( (_DWORD)v100 )
          {
            printk(&unk_36B08, "syna_cdev_ioctl_get_frame", (unsigned int)v100);
            LODWORD(v6) = -52;
          }
          else
          {
            LODWORD(v6) = 0;
          }
          v109 = (_QWORD *)v99[1];
          LODWORD(v282) = *((_DWORD *)v99 + 6);
          if ( (_QWORD *)*v109 == v99 && (v110 = *v99, *(_QWORD **)(*v99 + 8LL) == v99) )
          {
            *(_QWORD *)(v110 + 8) = v109;
            *v109 = v110;
          }
          else
          {
            _list_del_entry_valid_or_report(v99);
          }
          *v99 = 0xDEAD000000000100LL;
          v99[1] = 0xDEAD000000000122LL;
          if ( !(_DWORD)v100 )
            LODWORD(v6) = *((_DWORD *)v99 + 6);
          kfree(v99[2]);
          kfree(v99);
          v111 = *((_DWORD *)v5 + 316);
          if ( v111 )
            *((_DWORD *)v5 + 316) = --v111;
          if ( v111 < (unsigned int)qword_31708 && (*(_BYTE *)(v5[78] + 188LL) & 1) == 0 )
          {
            v112 = *(void (__fastcall **)(__int64, __int64))(v81 + 64);
            if ( v112 )
            {
              if ( *((_DWORD *)v112 - 1) != 875454897 )
                __break(0x8228u);
              v112(v81 + 8, 1);
            }
          }
          v113 = &qword_316D0;
          goto LABEL_349;
        }
      }
      if ( v20 >= 5 )
        goto LABEL_462;
      v266 = v20;
      memset((char *)&v284 - v20 + 4, 0, v20);
      v32 = "syna_cdev_ioctl_get_frame";
      goto LABEL_409;
    case 5:
      v65 = *v5;
      v66 = *((_BYTE *)v5 + 1410);
      LOBYTE(v284) = 0;
      v292 = 0;
      v293 = 0;
      v290 = 0;
      v291 = 0;
      v288 = 0;
      v289 = 0;
      n = 0;
      v287 = 0;
      src = nullptr;
      if ( (v66 & 1) == 0 )
      {
        v259 = "syna_cdev_ioctl_send_message";
        goto LABEL_422;
      }
      if ( *((_DWORD *)v5 + 351) == 3 )
      {
        v262 = &unk_33683;
        v263 = "syna_cdev_ioctl_send_message";
        goto LABEL_381;
      }
      if ( (unsigned int)(HIDWORD(qword_31700) + 3) > HIDWORD(v282) )
      {
        v264 = &unk_35535;
        v265 = "syna_cdev_ioctl_send_message";
        v21 = HIDWORD(v282);
        goto LABEL_390;
      }
      v21 = (unsigned int)v282;
      if ( (unsigned int)v282 > HIDWORD(v282) || (unsigned int)(v282 - 4097) <= 0xFFFFF001 )
      {
        v264 = &unk_35568;
        v265 = "syna_cdev_ioctl_send_message";
        goto LABEL_390;
      }
      if ( (_BYTE)qword_31698 )
        printk(&unk_38244, "syna_tcm_buf_lock", (unsigned __int8)qword_31698);
      mutex_lock(&qword_31668);
      v67 = (void *)qword_31658;
      v68 = (HIDWORD(qword_31700) & ~(SHIDWORD(qword_31700) >> 31)) + (unsigned int)v25;
      LOBYTE(qword_31698) = qword_31698 + 1;
      if ( (unsigned int)qword_31660 >= (unsigned int)v68 )
      {
        v68 = (unsigned int)qword_31660;
LABEL_284:
        memset(v67, 0, v68);
        v199 = (unsigned int)v282;
        v200 = (_BYTE *)qword_31658;
        HIDWORD(qword_31660) = 0;
        if ( (v282 & 0x80000000) != 0 )
        {
          __break(0x800u);
          if ( (_DWORD)v199 )
          {
LABEL_290:
            printk(&unk_3489E, "syna_cdev_ioctl_send_message", (unsigned int)v282);
            LODWORD(v6) = -52;
            goto LABEL_325;
          }
        }
        else
        {
          _check_object_size(qword_31658, (unsigned int)v282, 0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v201 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v201 = v27 & ((__int64)(v27 << 8) >> 8);
          v202 = v199;
          if ( 0x8000000000LL - v199 < v201 )
            goto LABEL_469;
          v219 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v221 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v221 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v221);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v219);
          v202 = _arch_copy_from_user(v200, v27 & 0xFF7FFFFFFFFFFFFFLL, v199);
          v222 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v224 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v224 - 4096);
          _WriteStatusReg(TTBR1_EL1, v224);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v222);
          if ( v202 )
          {
LABEL_469:
            memset(&v200[v199 - v202], 0, v202);
            if ( (_DWORD)v202 )
              goto LABEL_290;
          }
        }
        v225 = *(unsigned __int16 *)(v200 + 1);
        if ( v225 > (unsigned int)v282 )
        {
          printk(&unk_3776A, "syna_cdev_ioctl_send_message", *(unsigned __int16 *)(v200 + 1));
          LODWORD(v6) = -52;
        }
        else
        {
          LOBYTE(v293) = 0;
          src = nullptr;
          n = 0;
          _mutex_init(&v287, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_0);
          if ( (syna_tcm_send_command(
                  v65,
                  (unsigned __int8)*v200,
                  v200 + 3,
                  v225,
                  &v284,
                  &src,
                  (unsigned int)qword_31700)
              & 0x80000000) != 0 )
            printk(&unk_36B40, "syna_cdev_ioctl_send_message", (unsigned __int8)*v200);
          memset(v200, 0, v25);
          *v200 = v284;
          *(_WORD *)(v200 + 1) = WORD2(n);
          v226 = (unsigned int)qword_31660;
          if ( (unsigned int)qword_31660 < HIDWORD(n) )
          {
            printk(&unk_361C4, "syna_cdev_ioctl_send_message", (unsigned int)qword_31660);
            LODWORD(v6) = -75;
          }
          else
          {
            if ( !HIDWORD(n) )
              goto LABEL_316;
            if ( v200 != (_BYTE *)-3LL && src )
            {
              if ( HIDWORD(n) <= (unsigned int)(qword_31660 - 3) && HIDWORD(n) <= (unsigned int)n )
              {
                memcpy(v200 + 3, src, HIDWORD(n));
                v227 = HIDWORD(qword_31700);
                if ( SHIDWORD(qword_31700) <= 1 )
                  goto LABEL_317;
                v228 = HIDWORD(n);
                v229 = *(_WORD *)(v65 + 898);
                v230 = HIDWORD(n) + 4;
                v200[HIDWORD(n) + 3] = v229;
                v200[v230] = HIBYTE(v229);
                v227 = HIDWORD(qword_31700);
                if ( WORD2(qword_31700) == 2 )
                  goto LABEL_317;
                v200[v228 + 5] = *(_BYTE *)(v65 + 901);
LABEL_316:
                v227 = HIDWORD(qword_31700);
LABEL_317:
                v231 = HIDWORD(n) + (v227 & ~(v227 >> 31));
                v232 = (unsigned int)(v231 + 3);
                LODWORD(v282) = v231 + 3;
                if ( v231 + 3 < 0 )
                {
                  __break(0x800u);
                }
                else
                {
                  _check_object_size(v200, (unsigned int)(v231 + 3), 1);
                  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v233 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                    v233 = v27 & ((__int64)(v27 << 8) >> 8);
                  if ( 0x8000000000LL - v232 >= v233 )
                  {
                    v234 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v236 = *(_QWORD *)(StatusReg + 8);
                    _WriteStatusReg(
                      TTBR1_EL1,
                      v236 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                    _WriteStatusReg(TTBR0_EL1, v236);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v234);
                    LODWORD(v232) = _arch_copy_to_user(v27 & 0xFF7FFFFFFFFFFFFFLL, v200, v232);
                    v237 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v239 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                    _WriteStatusReg(TTBR0_EL1, v239 - 4096);
                    _WriteStatusReg(TTBR1_EL1, v239);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v237);
                  }
                }
                if ( (_DWORD)v232 )
                {
                  printk(&unk_36141, "syna_cdev_ioctl_send_message", v226);
                  LODWORD(v6) = -52;
                }
                else
                {
                  LODWORD(v6) = v282;
                }
                goto LABEL_325;
              }
              printk(&unk_3944E, "syna_pal_mem_cpy", (unsigned int)n);
            }
            printk(&unk_341B8, "syna_cdev_ioctl_send_message", v226);
            LODWORD(v6) = -22;
          }
        }
LABEL_325:
        if ( (unsigned __int8)qword_31698 == 1 )
        {
          v240 = 0;
        }
        else
        {
          printk(&unk_38244, "syna_tcm_buf_unlock", (unsigned __int8)qword_31698);
          v240 = qword_31698 - 1;
        }
        LOBYTE(qword_31698) = v240;
        v241 = mutex_unlock(&qword_31668);
        if ( (_BYTE)v293 )
          v241 = printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v293);
        v242 = src;
        v243 = syna_request_managed_device(v241);
        if ( v243 )
        {
          if ( v242 )
            devm_kfree(v243, v242);
        }
        else
        {
          printk(&unk_3BE43, "syna_pal_mem_free", v244);
        }
        goto LABEL_350;
      }
      if ( !qword_31658 )
        goto LABEL_99;
      v69 = qword_31658;
      v70 = syna_request_managed_device(qword_31658);
      if ( v70 )
      {
        v67 = (void *)devm_kfree(v70, v69);
LABEL_99:
        v72 = syna_request_managed_device(v67);
        if ( v72 )
          goto LABEL_100;
      }
      else
      {
        v280 = printk(&unk_3BE43, "syna_pal_mem_free", v71);
        v72 = syna_request_managed_device(v280);
        if ( v72 )
        {
LABEL_100:
          if ( (int)v68 > 0 )
          {
            v67 = (void *)devm_kmalloc(v72, v68, 3520);
            qword_31658 = (__int64)v67;
            if ( v67 )
            {
              LODWORD(qword_31660) = v68;
              goto LABEL_284;
            }
LABEL_454:
            printk(&unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v68);
            qword_31660 = 0;
            printk(&unk_376CF, "syna_cdev_ioctl_send_message", (unsigned int)v25);
            LODWORD(v6) = -243;
            goto LABEL_325;
          }
          v276 = &unk_38286;
LABEL_453:
          printk(v276, "syna_pal_mem_alloc", v73);
          qword_31658 = 0;
          goto LABEL_454;
        }
      }
      v276 = &unk_3BE43;
      goto LABEL_453;
    case 6:
      v163 = *((_DWORD *)v5 + 351);
      v6 = (unsigned int)v282;
      v315 = 0;
      v316 = 0;
      v313 = 0;
      v314 = 0;
      v311 = 0;
      v312 = 0;
      v309 = 0;
      v310 = 0;
      v307 = 0;
      v308 = 0;
      v305 = 0;
      v306 = 0;
      v303 = 0;
      v304 = 0;
      v301 = 0;
      v302 = 0;
      v299 = 0;
      v300 = 0;
      v297 = 0;
      v298 = 0;
      v295 = 0;
      v296 = 0;
      v293 = 0;
      v294 = 0;
      v291 = 0;
      v292 = 0;
      v289 = 0;
      v290 = 0;
      v287 = 0;
      v288 = 0;
      src = nullptr;
      n = 0;
      if ( v163 == 3 )
      {
        v262 = &unk_35AF4;
        v263 = "syna_cdev_ioctl_set_queued_types";
        goto LABEL_381;
      }
      if ( HIDWORD(v282) <= 0xFF )
      {
        v264 = &unk_32516;
        v265 = "syna_cdev_ioctl_set_queued_types";
        v21 = HIDWORD(v282);
        goto LABEL_390;
      }
      if ( !(_DWORD)v282 )
      {
        v264 = &unk_3CBAE;
        v265 = "syna_cdev_ioctl_set_queued_types";
        goto LABEL_390;
      }
      if ( (unsigned int)v282 >= 0x101 )
      {
        _copy_overflow(256, (unsigned int)v282);
        goto LABEL_400;
      }
      _check_object_size(&src, (unsigned int)v282, 0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v164 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v164 = v27 & ((__int64)(v27 << 8) >> 8);
      v165 = v6;
      if ( 0x8000000000LL - v6 >= v164 )
      {
        v166 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v168 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v168 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v168);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v166);
        v165 = _arch_copy_from_user(&src, v27 & 0xFF7FFFFFFFFFFFFFLL, v6);
        v169 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v171 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v171 - 4096);
        _WriteStatusReg(TTBR1_EL1, v171);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v169);
        if ( !v165 )
        {
          v172 = 0;
          while ( 1 )
          {
            if ( *((_BYTE *)&src + v172) == 1 )
            {
              v173 = syna_tcm_set_data_duplicator(*v5, (unsigned int)v172, syna_cdev_process_reports, v5);
              if ( v173 < 0 )
                break;
            }
            if ( ++v172 == 256 )
              goto LABEL_302;
          }
          LODWORD(v6) = v173;
          printk(&unk_3AA0E, "syna_cdev_ioctl_set_queued_types", (unsigned int)v172);
          goto LABEL_350;
        }
      }
      v268 = v6 - v165;
      v269 = v165;
      if ( v6 - v165 <= 0x100 )
        v270 = 256 - (v6 - v165);
      else
        v270 = 0;
      if ( v270 >= v165 )
      {
        LODWORD(v6) = v165;
        memset((char *)&src + v268, 0, v165);
LABEL_400:
        v32 = "syna_cdev_ioctl_set_queued_types";
        v33 = (unsigned int)v6;
        goto LABEL_410;
      }
      goto LABEL_464;
    case 7:
      v37 = *((_BYTE *)v5 + 1410);
      v6 = (unsigned int)v282;
      v284 = 0;
      if ( (v37 & 1) == 0 )
      {
        v259 = "syna_cdev_ioctl_check_frame";
        goto LABEL_422;
      }
      if ( *((_DWORD *)v5 + 351) == 3 )
      {
        v262 = &unk_382DE;
        v263 = "syna_cdev_ioctl_check_frame";
        goto LABEL_381;
      }
      if ( HIDWORD(v282) < 4 || (unsigned int)v282 <= 3 )
      {
        v264 = &unk_34E03;
        v265 = "syna_cdev_ioctl_check_frame";
        v21 = HIDWORD(v282);
        goto LABEL_390;
      }
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v38 = v283, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v38 = v283 & ((__int64)(v283 << 8) >> 8);
      if ( v38 > 0x7FFFFFFFFCLL )
      {
        v42 = 4;
      }
      else
      {
        v39 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v41 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v41);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v39);
        v42 = _arch_copy_from_user(&v284, v27 & 0xFF7FFFFFFFFFFFFFLL, 4);
        v43 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v45 - 4096);
        _WriteStatusReg(TTBR1_EL1, v45);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v43);
        if ( !v42 )
        {
          v46 = v284;
          if ( (_QWORD *)v5[159] == v5 + 159 )
          {
            v47 = _msecs_to_jiffies(v284);
            v48 = *((_DWORD *)v5 + 316);
            if ( v47 )
              _ZF = 1;
            else
              _ZF = v48 == 0;
            if ( !_ZF )
              v47 = 1;
            if ( !v48 && v47 )
            {
              v288 = 0;
              v289 = 0;
              n = 0;
              v287 = 0;
              src = nullptr;
              v50 = _msecs_to_jiffies(v46);
              init_wait_entry(&src, 0);
              v47 = prepare_to_wait_event(v5 + 161, &src, 1);
              v51 = *((_DWORD *)v5 + 316);
              if ( v50 )
                v52 = 1;
              else
                v52 = v51 == 0;
              if ( !v52 )
                v50 = 1;
              if ( v51 || !v50 )
              {
LABEL_79:
                finish_wait(v5 + 161, &src);
                LODWORD(v47) = v50;
              }
              else
              {
                while ( !v47 )
                {
                  v50 = schedule_timeout(v50);
                  v47 = prepare_to_wait_event(v5 + 161, &src, 1);
                  v53 = *((_DWORD *)v5 + 316);
                  if ( v50 )
                    v54 = 1;
                  else
                    v54 = v53 == 0;
                  if ( !v54 )
                    v50 = 1;
                  if ( v53 || !v50 )
                    goto LABEL_79;
                }
              }
            }
            if ( !(_DWORD)v47 )
            {
              LODWORD(v6) = -110;
              goto LABEL_350;
            }
          }
          if ( (int)v6 < 1 )
            goto LABEL_350;
          v55 = *(_BYTE *)(StatusReg + 70);
          v284 = *((_DWORD *)v5 + 316);
          if ( (v55 & 0x20) != 0 || (v56 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v56 = v27 & ((__int64)(v27 << 8) >> 8);
          if ( v56 <= 0x7FFFFFFFFCLL )
          {
            v57 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v59 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v59 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v59);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v57);
            v60 = _arch_copy_to_user(v27 & 0xFF7FFFFFFFFFFFFFLL, &v284, 4);
            v61 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v63 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v63 - 4096);
            _WriteStatusReg(TTBR1_EL1, v63);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v61);
            if ( !v60 )
              goto LABEL_350;
          }
          v64 = &unk_36141;
LABEL_404:
          printk(v64, "syna_cdev_ioctl_check_frame", v42);
          LODWORD(v6) = -52;
          goto LABEL_350;
        }
      }
      if ( v42 >= 5 )
        goto LABEL_463;
      memset((char *)&v284 - v42 + 4, 0, v42);
      v64 = &unk_3AA48;
      goto LABEL_404;
    case 8:
      mutex_lock(&qword_316D0);
      v74 = (_QWORD *)v5[159];
      v75 = (_QWORD **)(v5 + 159);
      if ( v74 != v5 + 159 )
      {
        do
        {
          v76 = (_QWORD *)v74[1];
          if ( (_QWORD *)*v76 == v74 && (v77 = *v74, *(_QWORD **)(*v74 + 8LL) == v74) )
          {
            *(_QWORD *)(v77 + 8) = v76;
            *v76 = v77;
          }
          else
          {
            _list_del_entry_valid_or_report(v74);
          }
          v78 = v74[2];
          *v74 = 0xDEAD000000000100LL;
          v74[1] = 0xDEAD000000000122LL;
          kfree(v78);
          kfree(v74);
          v79 = *((_DWORD *)v5 + 316);
          if ( v79 )
            *((_DWORD *)v5 + 316) = v79 - 1;
          v74 = *v75;
        }
        while ( *v75 != v75 );
      }
      mutex_unlock(&qword_316D0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 )
        goto LABEL_353;
      goto LABEL_352;
    case 9:
      v6 = (unsigned int)v282;
      if ( (*((_BYTE *)v5 + 1410) & 1) == 0 && *((_DWORD *)v5 + 351) != 3 )
      {
        printk(&unk_3D1E9, "syna_cdev_ioctl_application_info", v21);
        LODWORD(v6) = -6;
        goto LABEL_357;
      }
      if ( !HIDWORD(v282) || (unsigned int)v282 > HIDWORD(v282) )
      {
        v260 = &unk_3621C;
        v261 = "syna_cdev_ioctl_application_info";
        v115 = HIDWORD(v282);
        goto LABEL_376;
      }
      v174 = v5[181];
      if ( !v174 )
        goto LABEL_255;
      v175 = syna_request_managed_device(0);
      if ( !v175 )
      {
        v271 = printk(&unk_3BE43, "syna_pal_mem_free", v176);
        v177 = syna_request_managed_device(v271);
        if ( v177 )
          goto LABEL_256;
LABEL_418:
        v267 = &unk_3BE43;
        goto LABEL_419;
      }
      v20 = devm_kfree(v175, v174);
LABEL_255:
      v177 = syna_request_managed_device(v20);
      if ( !v177 )
        goto LABEL_418;
LABEL_256:
      if ( !(_DWORD)v6 )
      {
        v267 = &unk_38286;
LABEL_419:
        printk(v267, "syna_pal_mem_alloc", v178);
        v5[181] = 0;
        goto LABEL_420;
      }
      v179 = (char *)devm_kmalloc(v177, v6, 3520);
      v5[181] = v179;
      if ( !v179 )
      {
LABEL_420:
        printk(&unk_37EBE, "syna_cdev_ioctl_application_info", (unsigned int)v6);
        LODWORD(v6) = -12;
        goto LABEL_357;
      }
      v180 = v179;
      memset(v179, 0, v6);
      _check_object_size(v180, v6, 0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v181 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v181 = v27 & ((__int64)(v27 << 8) >> 8);
      v5 = (_QWORD *)v6;
      if ( 0x8000000000LL - v6 >= v181 )
      {
        v213 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v215 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v215 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v215);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v213);
        v5 = (_QWORD *)_arch_copy_from_user(v180, v27 & 0xFF7FFFFFFFFFFFFFLL, v6);
        v216 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v218 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v218 - 4096);
        _WriteStatusReg(TTBR1_EL1, v218);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v216);
        if ( !v5 )
          goto LABEL_351;
      }
      if ( v6 >= (unsigned __int64)v5 )
        v182 = v5;
      else
        v182 = nullptr;
      if ( v182 >= v5 )
      {
        memset(&v180[v6 - (_QWORD)v5], 0, (size_t)v5);
        if ( !(_DWORD)v5 )
          goto LABEL_351;
        v183 = &unk_3489E;
        v184 = "syna_cdev_ioctl_application_info";
        v185 = (unsigned int)v5;
        goto LABEL_360;
      }
LABEL_466:
      v281 = _fortify_panic(15, v182, v5);
      return syna_cdev_open(v281);
    case 10:
      v137 = *((_BYTE *)v5 + 1410);
      BYTE4(src) = 0;
      LODWORD(src) = 0;
      LOBYTE(v284) = 0;
      if ( (v137 & 1) == 0 && *((_DWORD *)v5 + 351) != 3 )
      {
        v259 = "syna_cdev_ioctl_do_hw_reset";
        goto LABEL_422;
      }
      if ( HIDWORD(v282) < 5 || (unsigned int)v282 <= 4 )
      {
        v264 = &unk_34E03;
        v265 = "syna_cdev_ioctl_do_hw_reset";
        v21 = HIDWORD(v282);
        goto LABEL_390;
      }
      v138 = v5[78];
      if ( !*(_QWORD *)(v138 + 392) )
      {
        printk(&unk_3A417, "syna_cdev_ioctl_do_hw_reset", v21);
        LODWORD(v6) = -19;
        goto LABEL_350;
      }
      v6 = *(unsigned int *)(v138 + 248);
      v139 = *(_DWORD *)(v138 + 252);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v140 = v283, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v140 = v283 & ((__int64)(v283 << 8) >> 8);
      if ( v140 > 0x7FFFFFFFFBLL )
      {
        v20 = 5;
      }
      else
      {
        v141 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v143 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v143 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v143);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v141);
        v20 = _arch_copy_from_user(&src, v27 & 0xFF7FFFFFFFFFFFFFLL, 5);
        v144 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v146 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v146 - 4096);
        _WriteStatusReg(TTBR1_EL1, v146);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v144);
        if ( !v20 )
        {
          v147 = *(unsigned __int16 *)((char *)&src + 3);
          if ( *(_WORD *)((char *)&src + 1) )
            *(_DWORD *)(v5[78] + 252LL) = *(unsigned __int16 *)((char *)&src + 1);
          if ( v147 )
            *(_DWORD *)(v5[78] + 248LL) = v147;
          v148 = *(void (**)(void))(v5[78] + 392LL);
          if ( *((_DWORD *)v148 - 1) != 725400091 )
            __break(0x8228u);
          v148();
          *(_DWORD *)(v5[78] + 252LL) = v139;
          _ZF = (unsigned __int8)src == 1;
          *(_DWORD *)(v5[78] + 248LL) = v6;
          if ( !_ZF )
          {
            if ( (*(_BYTE *)(v5[78] + 188LL) & 1) == 0 )
              syna_tcm_get_event_data(*v5, &v284, 0);
            if ( *(_BYTE *)(*v5 + 9LL) == 1 )
            {
              v149 = (__int64 (__fastcall *)(_QWORD))v5[215];
              if ( *((_DWORD *)v149 - 1) != -1373616356 )
                __break(0x8228u);
              LODWORD(v6) = v149(v5);
              if ( (v6 & 0x80000000) != 0 )
                printk(&unk_31FD1, "syna_cdev_ioctl_do_hw_reset", v150);
              goto LABEL_350;
            }
          }
          goto LABEL_302;
        }
      }
      if ( v20 >= 6 )
        goto LABEL_462;
      v266 = v20;
      memset((char *)&src - v20 + 5, 0, v20);
      v32 = "syna_cdev_ioctl_do_hw_reset";
LABEL_409:
      v33 = v266;
LABEL_410:
      printk(&unk_3489E, v32, v33);
      LODWORD(v6) = -52;
      goto LABEL_350;
    case 16:
      v115 = (unsigned int)v282;
      if ( (unsigned int)v282 <= 0x13 )
      {
        v260 = &unk_38DB4;
        v261 = "syna_cdev_ioctl_set_config";
        goto LABEL_376;
      }
      v151 = *v5;
      if ( (_BYTE)qword_31698 )
        printk(&unk_38244, "syna_tcm_buf_lock", (unsigned __int8)qword_31698);
      mutex_lock(&qword_31668);
      v152 = qword_31660;
      v153 = (void *)qword_31658;
      LOBYTE(qword_31698) = qword_31698 + 1;
      if ( (unsigned int)qword_31660 > 0x13 )
        goto LABEL_227;
      if ( !qword_31658 )
        goto LABEL_224;
      v154 = qword_31658;
      v155 = syna_request_managed_device(qword_31658);
      if ( v155 )
      {
        v153 = (void *)devm_kfree(v155, v154);
LABEL_224:
        v157 = syna_request_managed_device(v153);
        if ( v157 )
        {
LABEL_225:
          v152 = 20;
          v153 = (void *)devm_kmalloc(v157, 20, 3520);
          qword_31658 = (__int64)v153;
          if ( v153 )
          {
            LODWORD(qword_31660) = 20;
LABEL_227:
            memset(v153, 0, v152);
            v159 = *(_BYTE *)(StatusReg + 70);
            v160 = qword_31658;
            HIDWORD(qword_31660) = 0;
            if ( (v159 & 0x20) != 0 || (v161 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v161 = v27 & ((__int64)(v27 << 8) >> 8);
            if ( v161 <= 0x7FFFFFFFECLL )
            {
              v187 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v189 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v189 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v189);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v187);
              v162 = _arch_copy_from_user(v160, v27 & 0xFF7FFFFFFFFFFFFFLL, 20);
              v190 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v192 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v192 - 4096);
              _WriteStatusReg(TTBR1_EL1, v192);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v190);
              if ( !v162 )
                goto LABEL_273;
            }
            else
            {
              v162 = 20;
            }
            memset((void *)(v160 - v162 + 20), 0, v162);
            if ( (_DWORD)v162 )
            {
              printk(&unk_3489E, "syna_cdev_ioctl_set_config", (unsigned int)v162);
              LODWORD(v6) = -52;
              goto LABEL_346;
            }
LABEL_273:
            if ( *((_BYTE *)v5 + 1410) != 1 )
            {
LABEL_345:
              LODWORD(v6) = 0;
              goto LABEL_346;
            }
            v193 = qword_31658;
            v194 = *(unsigned __int16 *)(qword_31658 + 4);
            if ( *(_WORD *)(qword_31658 + 4) )
            {
              v195 = *(_DWORD *)(v151 + 60);
              v196 = v195 == v194;
              v197 = v195 != v194;
              if ( !*(_WORD *)(qword_31658 + 2) )
              {
                if ( !v196 )
                {
LABEL_337:
                  v245 = *(void (__fastcall **)(_QWORD))(v151 + 936);
                  if ( *((_DWORD *)v245 - 1) != 77640157 )
                    __break(0x8228u);
                  v245(v151);
                }
LABEL_340:
                v246 = *(unsigned __int16 *)(v193 + 8);
                v247 = v246 & 1;
                if ( v247 != *(unsigned __int8 *)(v151 + 890) )
                {
                  if ( (v246 & 1) != 0 )
                    v272 = "enable";
                  else
                    v272 = "disable";
                  printk(&unk_3BF86, "syna_cdev_ioctl_set_config", v272);
                  syna_tcm_enable_predict_reading(v151, v247);
                  v246 = *(unsigned __int16 *)(v193 + 8);
                }
                v248 = v246 >> 8;
                if ( HIDWORD(qword_31700) != (_DWORD)v248 )
                {
                  HIDWORD(qword_31700) = v246 >> 8;
                  printk(&unk_32556, "syna_cdev_ioctl_set_config", v248);
                }
                v249 = *(unsigned __int8 *)(v193 + 10);
                LODWORD(qword_31708) = 4 * v249;
                if ( v249 )
                  printk(&unk_3668A, "syna_cdev_ioctl_set_config", (unsigned int)(4 * v249));
                goto LABEL_345;
              }
            }
            else
            {
              if ( !*(_WORD *)(qword_31658 + 2) )
                goto LABEL_340;
              v197 = 0;
            }
            if ( *(_DWORD *)(v151 + 56) != *(unsigned __int16 *)(qword_31658 + 2) || v197 )
              goto LABEL_337;
            goto LABEL_340;
          }
          goto LABEL_450;
        }
      }
      else
      {
        v279 = printk(&unk_3BE43, "syna_pal_mem_free", v156);
        v157 = syna_request_managed_device(v279);
        if ( v157 )
          goto LABEL_225;
      }
      printk(&unk_3BE43, "syna_pal_mem_alloc", v158);
      qword_31658 = 0;
LABEL_450:
      printk(&unk_3703C, "syna_tcm_buf_alloc", 20);
      qword_31660 = 0;
      printk(&unk_376CF, "syna_cdev_ioctl_set_config", 20);
      LODWORD(v6) = -243;
LABEL_346:
      v136 = (unsigned __int8)qword_31698;
      if ( (unsigned __int8)qword_31698 != 1 )
        goto LABEL_382;
LABEL_347:
      v250 = 0;
LABEL_348:
      v113 = &qword_31668;
      LOBYTE(qword_31698) = v250;
LABEL_349:
      mutex_unlock(v113);
      goto LABEL_350;
    case 17:
      v115 = (unsigned int)v282;
      if ( (unsigned int)v282 <= 0x13 )
      {
        v260 = &unk_38DB4;
        v261 = "syna_cdev_ioctl_get_config_params";
LABEL_376:
        printk(v260, v261, v115);
        LODWORD(v6) = -22;
        goto LABEL_357;
      }
      v116 = *v5;
      if ( (_BYTE)qword_31698 )
        printk(&unk_38244, "syna_tcm_buf_lock", (unsigned __int8)qword_31698);
      mutex_lock(&qword_31668);
      v117 = qword_31660;
      v118 = (void *)qword_31658;
      LOBYTE(qword_31698) = qword_31698 + 1;
      if ( (unsigned int)qword_31660 > 0x13 )
        goto LABEL_181;
      if ( !qword_31658 )
        goto LABEL_178;
      v119 = qword_31658;
      v120 = syna_request_managed_device(qword_31658);
      if ( v120 )
      {
        v118 = (void *)devm_kfree(v120, v119);
LABEL_178:
        v122 = syna_request_managed_device(v118);
        if ( v122 )
        {
LABEL_179:
          v117 = 20;
          v118 = (void *)devm_kmalloc(v122, 20, 3520);
          qword_31658 = (__int64)v118;
          if ( v118 )
          {
            LODWORD(qword_31660) = 20;
LABEL_181:
            memset(v118, 0, v117);
            v125 = qword_31658;
            HIDWORD(qword_31660) = 0;
            *(_DWORD *)(qword_31658 + 16) = 0;
            *(_QWORD *)v125 = 0;
            *(_QWORD *)(v125 + 8) = 0;
            v126 = qword_31658;
            *(_WORD *)(qword_31658 + 2) = *(_DWORD *)(v116 + 56);
            *(_WORD *)(v126 + 4) = *(_DWORD *)(v116 + 60);
            LOBYTE(v125) = *(_BYTE *)v126 & 0xFE | *((_BYTE *)v5 + 1410);
            *(_BYTE *)v126 = v125;
            *(_BYTE *)v126 = v125 & 0xF7 | (8 * (*((_DWORD *)v5 + 351) == 3));
            if ( *(_BYTE *)(v116 + 128) )
              *(_BYTE *)(v126 + 1) = *(_BYTE *)(v116 + 128);
            v127 = *(_WORD *)(v126 + 8) & 0xFFFE | *(unsigned __int8 *)(v116 + 890);
            *(_WORD *)(v126 + 8) = v127;
            *(_WORD *)(v126 + 8) = (unsigned __int8)v127 | (unsigned __int16)(WORD2(qword_31700) << 8);
            *(_BYTE *)(v126 + 10) = (unsigned int)qword_31708 >> 2;
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v128 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v128 = v27 & ((__int64)(v27 << 8) >> 8);
            if ( v128 > 0x7FFFFFFFECLL )
              goto LABEL_363;
            v129 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v131 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v131 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v131);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v129);
            v132 = _arch_copy_to_user(v27 & 0xFF7FFFFFFFFFFFFFLL, v126, 20);
            v133 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v135 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v135 - 4096);
            _WriteStatusReg(TTBR1_EL1, v135);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v133);
            if ( v132 )
            {
LABEL_363:
              printk(&unk_36141, "syna_cdev_ioctl_get_config_params", v124);
              LODWORD(v6) = -52;
            }
            else
            {
              LODWORD(v6) = 20;
            }
LABEL_189:
            v136 = (unsigned __int8)qword_31698;
            if ( (unsigned __int8)qword_31698 == 1 )
              goto LABEL_347;
LABEL_382:
            printk(&unk_38244, "syna_tcm_buf_unlock", v136);
            v250 = qword_31698 - 1;
            goto LABEL_348;
          }
LABEL_447:
          printk(&unk_3703C, "syna_tcm_buf_alloc", 20);
          qword_31660 = 0;
          printk(&unk_376CF, "syna_cdev_ioctl_get_config_params", 20);
          LODWORD(v6) = -243;
          goto LABEL_189;
        }
      }
      else
      {
        v278 = printk(&unk_3BE43, "syna_pal_mem_free", v121);
        v122 = syna_request_managed_device(v278);
        if ( v122 )
          goto LABEL_179;
      }
      printk(&unk_3BE43, "syna_pal_mem_alloc", v123);
      qword_31658 = 0;
      goto LABEL_447;
    default:
      v198 = "syna_cdev_ioctl_dispatch";
      goto LABEL_280;
  }
}
