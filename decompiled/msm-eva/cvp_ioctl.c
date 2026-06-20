__int64 __fastcall cvp_ioctl(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  __int64 v6; // x0
  unsigned int *v7; // x23
  __int64 v8; // x14
  char **v9; // x13
  unsigned __int64 StatusReg; // x16
  __int64 v11; // x19
  unsigned __int64 v12; // x15
  unsigned __int64 v13; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x8
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v41; // x10
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  unsigned __int64 v46; // x8
  unsigned __int64 v48; // x9
  unsigned __int64 v50; // x10
  unsigned __int64 v52; // x8
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x9
  unsigned __int64 v58; // x9
  unsigned __int64 v60; // x10
  unsigned __int64 v61; // x21
  int v63; // w0
  __int64 v64; // x3
  __int64 result; // x0
  unsigned __int64 v66; // x8
  unsigned __int64 v68; // x9
  unsigned __int64 v70; // x10
  unsigned __int64 v72; // x9
  unsigned __int64 v74; // x10
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x9
  unsigned __int64 v78; // x9
  unsigned __int64 v80; // x10
  unsigned __int64 v82; // x9
  unsigned __int64 v84; // x10
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x9
  __int64 v88; // x28
  unsigned __int64 v89; // x9
  unsigned __int64 v91; // x10
  __int64 v93; // x0
  int v94; // w8
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x9
  __int64 v98; // x0
  __int64 v100; // x0
  unsigned __int64 v101; // x8
  __int64 v103; // x0
  __int64 v105; // x0
  unsigned __int64 v106; // x8
  unsigned __int64 v107; // x9
  __int64 v109; // x0
  __int64 v111; // x0
  unsigned __int64 v112; // x8
  unsigned __int64 v113; // x9
  __int64 v115; // x0
  __int64 v117; // x0
  unsigned __int64 v118; // x8
  unsigned __int64 v119; // x9
  __int64 v121; // x0
  __int64 v123; // x0
  unsigned int *v124; // x22
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x9
  __int64 v128; // x0
  __int64 v130; // x0
  unsigned __int64 v131; // x8
  unsigned __int64 v132; // x9
  __int64 v134; // x0
  __int64 v136; // x0
  unsigned __int64 v137; // x8
  unsigned __int64 v138; // x9
  _DWORD *v139; // x24
  __int64 v141; // x0
  __int64 v143; // x0
  unsigned __int64 v144; // x8
  unsigned __int64 v145; // x9
  __int64 v147; // x0
  __int64 v149; // x0
  unsigned __int64 v150; // x8
  unsigned __int64 v151; // x9
  __int64 v153; // x0
  __int64 v155; // x0
  unsigned __int64 v156; // x8
  unsigned __int64 v157; // x9
  __int64 v159; // x0
  __int64 v161; // x0
  unsigned __int64 v162; // x8
  unsigned __int64 v163; // x9
  __int64 v165; // x0
  int session_ctrl_from_user; // w0
  unsigned int *v168; // x22
  unsigned __int64 v169; // x23
  int v170; // w0
  __int64 v171; // x1
  __int64 v172; // x2
  void *v173; // x0
  unsigned __int64 v174; // x8
  unsigned __int64 v175; // x9
  __int64 v177; // x0
  __int64 v179; // x0
  unsigned __int64 v180; // x8
  __int64 v182; // x0
  __int64 v184; // x0
  unsigned __int64 v185; // x8
  unsigned __int64 v186; // x9
  __int64 v188; // x0
  __int64 v190; // x0
  unsigned __int64 v191; // x8
  unsigned __int64 v192; // x9
  __int64 v194; // x0
  __int64 v196; // x0
  unsigned __int64 v197; // x8
  unsigned __int64 v198; // x9
  __int64 v200; // x0
  __int64 v202; // x0
  unsigned __int64 v203; // x8
  unsigned __int64 v204; // x9
  __int64 v206; // x0
  __int64 v208; // x0
  unsigned __int64 v209; // x8
  unsigned __int64 v210; // x9
  __int64 v212; // x0
  __int64 v214; // x0
  unsigned __int64 v215; // x8
  unsigned __int64 v216; // x9
  __int64 v218; // x0
  __int64 v220; // x0
  unsigned __int64 v221; // x8
  unsigned __int64 v222; // x9
  __int64 v224; // x0
  __int64 v226; // x0
  unsigned __int64 v227; // x8
  unsigned __int64 v228; // x9
  __int64 v230; // x0
  __int64 v232; // x0
  unsigned __int64 v233; // x8
  unsigned __int64 v234; // x9
  __int64 v236; // x0
  __int64 v238; // x0
  unsigned __int64 v239; // x8
  unsigned __int64 v240; // x9
  int v242; // w0
  __int64 pkt_name_from_type; // x24
  __int64 v244; // x0
  int v245; // w22
  char v246; // w8
  unsigned __int64 v247; // x8
  unsigned __int64 v249; // x10
  unsigned __int64 v251; // x11
  unsigned __int64 v252; // x8
  unsigned __int64 v254; // x9
  int v255; // w5
  unsigned __int64 v256; // x9
  __int64 v258; // x0
  __int64 v259; // x0
  unsigned __int64 v260; // x8
  unsigned int *v261; // x25
  __int64 v263; // x0
  __int64 v264; // x0
  unsigned __int64 v265; // x9
  __int64 v267; // x0
  __int64 v268; // x0
  unsigned __int64 v269; // x9
  __int64 v271; // x0
  __int64 v272; // x0
  unsigned __int64 v273; // x9
  __int64 v275; // x0
  __int64 v276; // x0
  unsigned __int64 v277; // x9
  __int64 v279; // x0
  __int64 v280; // x0
  unsigned __int64 v281; // x9
  __int64 v283; // x0
  __int64 v284; // x0
  unsigned __int64 v285; // x9
  __int64 v287; // x0
  __int64 v288; // x0
  unsigned __int64 v289; // x9
  __int64 v291; // x0
  __int64 v292; // x0
  unsigned __int64 v293; // x9
  __int64 v295; // x0
  __int64 v296; // x0
  unsigned __int64 v297; // x9
  __int64 v299; // x0
  __int64 v300; // x0
  unsigned __int64 v301; // x9
  __int64 v303; // x0
  int v304; // w0
  unsigned int msg_size; // w0
  unsigned __int64 v306; // x8
  __int64 v307; // x11
  unsigned __int64 v309; // x14
  unsigned __int64 v311; // x15
  unsigned __int64 v312; // x12
  unsigned __int64 v314; // x13
  unsigned __int64 v315; // x9
  __int64 v317; // x0
  __int64 v318; // x0
  unsigned __int64 v319; // x8
  __int64 v321; // x0
  __int64 v322; // x0
  unsigned __int64 v323; // x9
  __int64 v325; // x0
  __int64 v326; // x0
  unsigned __int64 v327; // x9
  __int64 v329; // x0
  __int64 v330; // x0
  unsigned __int64 v331; // x9
  __int64 v333; // x0
  __int64 v334; // x0
  unsigned __int64 v335; // x9
  __int64 v337; // x0
  __int64 v338; // x0
  unsigned __int64 v339; // x9
  __int64 v341; // x0
  __int64 v342; // x0
  unsigned __int64 v343; // x9
  __int64 v345; // x0
  __int64 v346; // x0
  unsigned __int64 v347; // x9
  __int64 v349; // x0
  __int64 v350; // x0
  unsigned __int64 v351; // x9
  __int64 v353; // x0
  __int64 v354; // x0
  unsigned __int64 v355; // x9
  __int64 v357; // x0
  __int64 v358; // x0
  unsigned __int64 v359; // x9
  __int64 v361; // x20
  unsigned __int64 v362; // x8
  unsigned __int64 v364; // x9
  __int64 v365; // [xsp+0h] [xbp-30h]
  __int64 v366; // [xsp+8h] [xbp-28h]
  unsigned int v367; // [xsp+8h] [xbp-28h]
  unsigned int v368; // [xsp+8h] [xbp-28h]
  __int64 v369; // [xsp+8h] [xbp-28h]
  unsigned __int64 v370; // [xsp+10h] [xbp-20h]
  unsigned int *v371; // [xsp+10h] [xbp-20h]
  __int64 v372; // [xsp+18h] [xbp-18h] BYREF
  int v373; // [xsp+20h] [xbp-10h]
  __int64 v374; // [xsp+28h] [xbp-8h]

  v374 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 2704);
  v7 = (unsigned int *)v6;
  if ( !v6 )
  {
    result = -12;
    goto LABEL_379;
  }
  v8 = (__int64)&unk_1000;
  v9 = off_6C000;
  v373 = 0;
  v372 = 0;
  if ( !a3 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v63 = __ratelimit(&convert_from_user__rs, "convert_from_user");
      v8 = (__int64)&unk_1000;
      v9 = off_6C000;
      if ( v63 )
      {
        printk(&unk_8B716, &unk_8E7CE, "convert_from_user", v64);
        v8 = (__int64)&unk_1000;
        v9 = off_6C000;
      }
    }
    goto LABEL_374;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = a3 << 8;
  v12 = a3 + 16;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v13 = a3 & (v11 >> 8);
  LODWORD(_X25) = 0;
  _X2 = 0;
  if ( v13 >= 0x7FFFFFFFFDLL )
    goto LABEL_30;
  _X8 = a3 & 0xFF7FFFFFFFFFFFFFLL;
  v17 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v23);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v17);
  __asm { LDTR            W2, [X8] }
  v24 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v26 - 4096);
  _WriteStatusReg(TTBR1_EL1, v26);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v24);
  v27 = a3 + 4;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v28 = a3 + 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v28 = v27 & ((__int64)(v27 << 8) >> 8);
  LODWORD(_X25) = 0;
  if ( v28 >= 0x7FFFFFFFFDLL )
    goto LABEL_30;
  _X8 = v27 & 0xFF7FFFFFFFFFFFFFLL;
  v30 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v32 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v32 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v32);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v30);
  __asm { LDTR            W25, [X8] }
  v33 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v35 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v35 - 4096);
  _WriteStatusReg(TTBR1_EL1, v35);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v33);
  v36 = a3 + 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v37 = a3 + 8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v37 = v36 & ((__int64)(v36 << 8) >> 8);
  if ( v37 >= 0x7FFFFFFFFDLL )
    goto LABEL_30;
  _X8 = v36 & 0xFF7FFFFFFFFFFFFFLL;
  v39 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v41 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v41);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v39);
  __asm { LDTR            W26, [X8] }
  v43 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v45 - 4096);
  _WriteStatusReg(TTBR1_EL1, v45);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v43);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v46 = a3 + 16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v46 = v12 & ((__int64)(v12 << 8) >> 8);
  if ( v46 >= 0x7FFFFFFFFDLL )
    goto LABEL_30;
  _X8 = v12 & 0xFF7FFFFFFFFFFFFFLL;
  v48 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v50 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v50 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v50);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v48);
  __asm { LDTR            W27, [X8] }
  v52 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v54 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v54 - 4096);
  _WriteStatusReg(TTBR1_EL1, v54);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v52);
  v55 = a3 + 20;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v56 = a3 + 20, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v56 = v55 & ((__int64)(v55 << 8) >> 8);
  if ( v56 >= 0x7FFFFFFFFDLL )
  {
LABEL_30:
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v369 = _X2;
      v371 = (unsigned int *)v6;
      v61 = StatusReg;
      v6 = printk(&unk_88787, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      _X2 = v369;
      v12 = a3 + 16;
      v7 = v371;
      v8 = (__int64)&unk_1000;
      v11 = a3 << 8;
      v9 = off_6C000;
    }
    else
    {
      v61 = StatusReg;
    }
  }
  else
  {
    _X8 = v55 & 0xFF7FFFFFFFFFFFFFLL;
    v58 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v60 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v60 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v60);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v58);
    v61 = StatusReg;
    v366 = _X2;
    __asm { LDTR            W28, [X8] }
    v6 = ((__int64 (*)(void))uaccess_ttbr0_disable_0)();
    _X2 = v366;
    v12 = a3 + 16;
    v9 = off_6C000;
    v8 = (__int64)&unk_1000;
  }
  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
  {
    v368 = a2;
    v168 = v7;
    v169 = v12;
    v6 = printk(&unk_8330D, "hfi", _X2, (unsigned int)_X25);
    v12 = v169;
    v7 = v168;
    a2 = v368;
    v8 = (__int64)&unk_1000;
    v9 = off_6C000;
    if ( (*(_BYTE *)(v61 + 70) & 0x20) == 0 )
    {
LABEL_35:
      v66 = a3;
      if ( (*(_QWORD *)v61 & 0x4000000) == 0 )
        goto LABEL_37;
    }
  }
  else if ( (*(_BYTE *)(v61 + 70) & 0x20) == 0 )
  {
    goto LABEL_35;
  }
  v66 = a3 & (v11 >> 8);
LABEL_37:
  if ( v66 > 0x7FFFFFFFFCLL )
  {
LABEL_38:
    *v7 = 0;
    goto LABEL_374;
  }
  _X8 = a3 & 0xFF7FFFFFFFFFFFFFLL;
  v68 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v70 = *(_QWORD *)(v61 + 8);
  _WriteStatusReg(TTBR1_EL1, v70 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v70);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v68);
  __asm { LDTR            W8, [X8] }
  v72 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v74 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v74 - 4096);
  _WriteStatusReg(TTBR1_EL1, v74);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v72);
  *v7 = _X8;
  v75 = a3 + 4;
  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v76 = a3 + 4, (*(_QWORD *)v61 & 0x4000000) != 0) )
    v76 = v75 & ((__int64)(v75 << 8) >> 8);
  if ( v76 >= 0x7FFFFFFFFDLL )
  {
    v7[1] = 0;
    goto LABEL_374;
  }
  _X8 = v75 & 0xFF7FFFFFFFFFFFFFLL;
  v78 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v80 = *(_QWORD *)(v61 + 8);
  _WriteStatusReg(TTBR1_EL1, v80 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v80);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v78);
  __asm { LDTR            W8, [X8] }
  v82 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v84 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v84 - 4096);
  _WriteStatusReg(TTBR1_EL1, v84);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v82);
  v7[1] = _X8;
  v85 = a3 + 8;
  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v86 = a3 + 8, (*(_QWORD *)v61 & 0x4000000) != 0) )
    v86 = v85 & ((__int64)(v85 << 8) >> 8);
  if ( v86 >= 0x7FFFFFFFFDLL )
  {
    v7[2] = 0;
    goto LABEL_374;
  }
  _X8 = v85 & 0xFF7FFFFFFFFFFFFFLL;
  v88 = a1;
  v89 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v91 = *(_QWORD *)(v61 + 8);
  _WriteStatusReg(TTBR1_EL1, v91 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v91);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v89);
  v370 = v12;
  __asm { LDTR            W24, [X8] }
  v93 = uaccess_ttbr0_disable_0(v6);
  v94 = *v7;
  v7[2] = _X24;
  if ( v94 <= 268439617 )
  {
    if ( v94 <= 268439568 )
    {
      if ( v94 != 268439553 )
      {
        if ( v94 == 268439555 )
        {
          v174 = a3 + 20;
          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v175 = a3 + 20, (*(_QWORD *)v61 & 0x4000000) != 0) )
            v175 = v174 & ((__int64)(v174 << 8) >> 8);
          if ( v175 >= 0x7FFFFFFFFDLL )
          {
            v7[5] = 0;
LABEL_388:
            v9 = off_6C000;
            v8 = (__int64)&unk_1000;
            goto LABEL_374;
          }
          _X24 = v174 & 0xFF7FFFFFFFFFFFFFLL;
          v177 = uaccess_ttbr0_enable_0(v93);
          __asm { LDTR            W24, [X24] }
          v179 = uaccess_ttbr0_disable_0(v177);
          v7[5] = _X24;
          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v180 = v370, (*(_QWORD *)v61 & 0x4000000) != 0) )
            v180 = v370 & ((__int64)(v370 << 8) >> 8);
          if ( v180 < 0x7FFFFFFFFDLL )
          {
            _X24 = v370 & 0xFF7FFFFFFFFFFFFFLL;
            v182 = uaccess_ttbr0_enable_0(v179);
            __asm { LDTR            W24, [X24] }
            v184 = uaccess_ttbr0_disable_0(v182);
            v7[4] = _X24;
            v185 = a3 + 24;
            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v186 = a3 + 24, (*(_QWORD *)v61 & 0x4000000) != 0) )
              v186 = v185 & ((__int64)(v185 << 8) >> 8);
            if ( v186 < 0x7FFFFFFFFDLL )
            {
              _X24 = v185 & 0xFF7FFFFFFFFFFFFFLL;
              v188 = uaccess_ttbr0_enable_0(v184);
              __asm { LDTR            W24, [X24] }
              v190 = uaccess_ttbr0_disable_0(v188);
              v7[6] = _X24;
              v191 = a3 + 28;
              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v192 = a3 + 28, (*(_QWORD *)v61 & 0x4000000) != 0) )
                v192 = v191 & ((__int64)(v191 << 8) >> 8);
              if ( v192 < 0x7FFFFFFFFDLL )
              {
                _X24 = v191 & 0xFF7FFFFFFFFFFFFFLL;
                v194 = uaccess_ttbr0_enable_0(v190);
                __asm { LDTR            W24, [X24] }
                v196 = uaccess_ttbr0_disable_0(v194);
                v7[7] = _X24;
                v197 = a3 + 32;
                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v198 = a3 + 32, (*(_QWORD *)v61 & 0x4000000) != 0) )
                  v198 = v197 & ((__int64)(v197 << 8) >> 8);
                if ( v198 < 0x7FFFFFFFFDLL )
                {
                  v367 = a2;
                  v365 = v11;
                  _X24 = v197 & 0xFF7FFFFFFFFFFFFFLL;
                  v200 = uaccess_ttbr0_enable_0(v196);
                  __asm { LDTR            W24, [X24] }
                  v202 = uaccess_ttbr0_disable_0(v200);
                  v7[8] = _X24;
                  v124 = v7;
                  v203 = a3 + 36;
                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v204 = a3 + 36, (*(_QWORD *)v61 & 0x4000000) != 0) )
                    v204 = v203 & ((__int64)(v203 << 8) >> 8);
                  if ( v204 < 0x7FFFFFFFFDLL )
                  {
                    _X24 = v203 & 0xFF7FFFFFFFFFFFFFLL;
                    v206 = uaccess_ttbr0_enable_0(v202);
                    __asm { LDTR            W24, [X24] }
                    v208 = uaccess_ttbr0_disable_0(v206);
                    v7[9] = _X24;
                    v209 = a3 + 40;
                    if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v210 = a3 + 40, (*(_QWORD *)v61 & 0x4000000) != 0) )
                      v210 = v209 & ((__int64)(v209 << 8) >> 8);
                    if ( v210 < 0x7FFFFFFFFDLL )
                    {
                      _X24 = v209 & 0xFF7FFFFFFFFFFFFFLL;
                      v212 = uaccess_ttbr0_enable_0(v208);
                      __asm { LDTR            W24, [X24] }
                      v214 = uaccess_ttbr0_disable_0(v212);
                      v7[10] = _X24;
                      v215 = a3 + 44;
                      if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v216 = a3 + 44, (*(_QWORD *)v61 & 0x4000000) != 0) )
                        v216 = v215 & ((__int64)(v215 << 8) >> 8);
                      v139 = v7 + 11;
                      if ( v216 < 0x7FFFFFFFFDLL )
                      {
                        _X25 = v215 & 0xFF7FFFFFFFFFFFFFLL;
                        v218 = uaccess_ttbr0_enable_0(v214);
                        __asm { LDTR            W25, [X25] }
                        v220 = uaccess_ttbr0_disable_0(v218);
                        *v139 = _X25;
                        v221 = a3 + 48;
                        if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v222 = a3 + 48, (*(_QWORD *)v61 & 0x4000000) != 0) )
                          v222 = v221 & ((__int64)(v221 << 8) >> 8);
                        if ( v222 < 0x7FFFFFFFFDLL )
                        {
                          _X25 = v221 & 0xFF7FFFFFFFFFFFFFLL;
                          v224 = uaccess_ttbr0_enable_0(v220);
                          __asm { LDTR            W25, [X25] }
                          v226 = uaccess_ttbr0_disable_0(v224);
                          v7[12] = _X25;
                          v227 = a3 + 52;
                          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v228 = a3 + 52, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            v228 = v227 & ((__int64)(v227 << 8) >> 8);
                          if ( v228 < 0x7FFFFFFFFDLL )
                          {
                            _X25 = v227 & 0xFF7FFFFFFFFFFFFFLL;
                            v230 = uaccess_ttbr0_enable_0(v226);
                            __asm { LDTR            W25, [X25] }
                            v232 = uaccess_ttbr0_disable_0(v230);
                            v7[13] = _X25;
                            v233 = a3 + 56;
                            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                              || (v234 = a3 + 56, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            {
                              v234 = v233 & ((__int64)(v233 << 8) >> 8);
                            }
                            if ( v234 < 0x7FFFFFFFFDLL )
                            {
                              _X25 = v233 & 0xFF7FFFFFFFFFFFFFLL;
                              v236 = uaccess_ttbr0_enable_0(v232);
                              __asm { LDTR            W25, [X25] }
                              v238 = uaccess_ttbr0_disable_0(v236);
                              v7[14] = _X25;
                              v239 = a3 + 60;
                              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                || (v240 = a3 + 60, (*(_QWORD *)v61 & 0x4000000) != 0) )
                              {
                                v240 = v239 & ((__int64)(v239 << 8) >> 8);
                              }
                              if ( v240 < 0x7FFFFFFFFDLL )
                              {
                                _X25 = v239 & 0xFF7FFFFFFFFFFFFFLL;
                                v165 = uaccess_ttbr0_enable_0(v238);
                                __asm { LDTR            W25, [X25] }
                                goto LABEL_178;
                              }
                              goto LABEL_369;
                            }
                            goto LABEL_368;
                          }
                          goto LABEL_367;
                        }
                        goto LABEL_366;
                      }
LABEL_365:
                      v361 = 0;
LABEL_370:
                      v139[v361] = 0;
                      v9 = off_6C000;
                      v8 = (__int64)&unk_1000;
                      v7 = v124;
                      goto LABEL_374;
                    }
                    goto LABEL_387;
                  }
                  goto LABEL_386;
                }
                goto LABEL_385;
              }
              goto LABEL_384;
            }
            goto LABEL_383;
          }
LABEL_382:
          v7[4] = 0;
          goto LABEL_388;
        }
        v9 = off_6C000;
        v8 = (__int64)&unk_1000;
        if ( v94 == 268439556 )
        {
          v95 = a3 + 20;
          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v96 = a3 + 20, (*(_QWORD *)v61 & 0x4000000) != 0) )
            v96 = v95 & ((__int64)(v95 << 8) >> 8);
          if ( v96 >= 0x7FFFFFFFFDLL )
          {
            v7[5] = 0;
            goto LABEL_374;
          }
          _X24 = v95 & 0xFF7FFFFFFFFFFFFFLL;
          v98 = uaccess_ttbr0_enable_0(v93);
          __asm { LDTR            W24, [X24] }
          v100 = uaccess_ttbr0_disable_0(v98);
          v7[5] = _X24;
          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v101 = v370, (*(_QWORD *)v61 & 0x4000000) != 0) )
            v101 = v370 & ((__int64)(v370 << 8) >> 8);
          if ( v101 < 0x7FFFFFFFFDLL )
          {
            _X24 = v370 & 0xFF7FFFFFFFFFFFFFLL;
            v103 = uaccess_ttbr0_enable_0(v100);
            __asm { LDTR            W24, [X24] }
            v105 = uaccess_ttbr0_disable_0(v103);
            v7[4] = _X24;
            v106 = a3 + 24;
            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v107 = a3 + 24, (*(_QWORD *)v61 & 0x4000000) != 0) )
              v107 = v106 & ((__int64)(v106 << 8) >> 8);
            if ( v107 < 0x7FFFFFFFFDLL )
            {
              _X24 = v106 & 0xFF7FFFFFFFFFFFFFLL;
              v109 = uaccess_ttbr0_enable_0(v105);
              __asm { LDTR            W24, [X24] }
              v111 = uaccess_ttbr0_disable_0(v109);
              v7[6] = _X24;
              v112 = a3 + 28;
              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v113 = a3 + 28, (*(_QWORD *)v61 & 0x4000000) != 0) )
                v113 = v112 & ((__int64)(v112 << 8) >> 8);
              if ( v113 < 0x7FFFFFFFFDLL )
              {
                _X24 = v112 & 0xFF7FFFFFFFFFFFFFLL;
                v115 = uaccess_ttbr0_enable_0(v111);
                __asm { LDTR            W24, [X24] }
                v117 = uaccess_ttbr0_disable_0(v115);
                v7[7] = _X24;
                v118 = a3 + 32;
                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v119 = a3 + 32, (*(_QWORD *)v61 & 0x4000000) != 0) )
                  v119 = v118 & ((__int64)(v118 << 8) >> 8);
                if ( v119 < 0x7FFFFFFFFDLL )
                {
                  v367 = a2;
                  v365 = v11;
                  _X24 = v118 & 0xFF7FFFFFFFFFFFFFLL;
                  v121 = uaccess_ttbr0_enable_0(v117);
                  __asm { LDTR            W24, [X24] }
                  v123 = uaccess_ttbr0_disable_0(v121);
                  v7[8] = _X24;
                  v124 = v7;
                  v125 = a3 + 36;
                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v126 = a3 + 36, (*(_QWORD *)v61 & 0x4000000) != 0) )
                    v126 = v125 & ((__int64)(v125 << 8) >> 8);
                  if ( v126 < 0x7FFFFFFFFDLL )
                  {
                    _X24 = v125 & 0xFF7FFFFFFFFFFFFFLL;
                    v128 = uaccess_ttbr0_enable_0(v123);
                    __asm { LDTR            W24, [X24] }
                    v130 = uaccess_ttbr0_disable_0(v128);
                    v7[9] = _X24;
                    v131 = a3 + 40;
                    if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v132 = a3 + 40, (*(_QWORD *)v61 & 0x4000000) != 0) )
                      v132 = v131 & ((__int64)(v131 << 8) >> 8);
                    if ( v132 < 0x7FFFFFFFFDLL )
                    {
                      _X24 = v131 & 0xFF7FFFFFFFFFFFFFLL;
                      v134 = uaccess_ttbr0_enable_0(v130);
                      __asm { LDTR            W24, [X24] }
                      v136 = uaccess_ttbr0_disable_0(v134);
                      v7[10] = _X24;
                      v137 = a3 + 44;
                      if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v138 = a3 + 44, (*(_QWORD *)v61 & 0x4000000) != 0) )
                        v138 = v137 & ((__int64)(v137 << 8) >> 8);
                      v139 = v7 + 11;
                      if ( v138 < 0x7FFFFFFFFDLL )
                      {
                        _X25 = v137 & 0xFF7FFFFFFFFFFFFFLL;
                        v141 = uaccess_ttbr0_enable_0(v136);
                        __asm { LDTR            W25, [X25] }
                        v143 = uaccess_ttbr0_disable_0(v141);
                        *v139 = _X25;
                        v144 = a3 + 48;
                        if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v145 = a3 + 48, (*(_QWORD *)v61 & 0x4000000) != 0) )
                          v145 = v144 & ((__int64)(v144 << 8) >> 8);
                        if ( v145 < 0x7FFFFFFFFDLL )
                        {
                          _X25 = v144 & 0xFF7FFFFFFFFFFFFFLL;
                          v147 = uaccess_ttbr0_enable_0(v143);
                          __asm { LDTR            W25, [X25] }
                          v149 = uaccess_ttbr0_disable_0(v147);
                          v7[12] = _X25;
                          v150 = a3 + 52;
                          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v151 = a3 + 52, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            v151 = v150 & ((__int64)(v150 << 8) >> 8);
                          if ( v151 < 0x7FFFFFFFFDLL )
                          {
                            _X25 = v150 & 0xFF7FFFFFFFFFFFFFLL;
                            v153 = uaccess_ttbr0_enable_0(v149);
                            __asm { LDTR            W25, [X25] }
                            v155 = uaccess_ttbr0_disable_0(v153);
                            v7[13] = _X25;
                            v156 = a3 + 56;
                            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                              || (v157 = a3 + 56, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            {
                              v157 = v156 & ((__int64)(v156 << 8) >> 8);
                            }
                            if ( v157 < 0x7FFFFFFFFDLL )
                            {
                              _X25 = v156 & 0xFF7FFFFFFFFFFFFFLL;
                              v159 = uaccess_ttbr0_enable_0(v155);
                              __asm { LDTR            W25, [X25] }
                              v161 = uaccess_ttbr0_disable_0(v159);
                              v7[14] = _X25;
                              v162 = a3 + 60;
                              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                || (v163 = a3 + 60, (*(_QWORD *)v61 & 0x4000000) != 0) )
                              {
                                v163 = v162 & ((__int64)(v162 << 8) >> 8);
                              }
                              if ( v163 < 0x7FFFFFFFFDLL )
                              {
                                _X25 = v162 & 0xFF7FFFFFFFFFFFFFLL;
                                v165 = uaccess_ttbr0_enable_0(v161);
                                __asm { LDTR            W25, [X25] }
LABEL_178:
                                uaccess_ttbr0_disable_0(v165);
                                v7 = v124;
                                v124[15] = _X25;
                                v11 = v365;
                                a2 = v367;
                                goto LABEL_199;
                              }
LABEL_369:
                              v361 = 4;
                              goto LABEL_370;
                            }
LABEL_368:
                            v361 = 3;
                            goto LABEL_370;
                          }
LABEL_367:
                          v361 = 2;
                          goto LABEL_370;
                        }
LABEL_366:
                        v361 = 1;
                        goto LABEL_370;
                      }
                      goto LABEL_365;
                    }
LABEL_387:
                    v7 = v124;
                    v124[10] = 0;
                    goto LABEL_388;
                  }
LABEL_386:
                  v7 = v124;
                  v124[9] = 0;
                  goto LABEL_388;
                }
LABEL_385:
                v7[8] = 0;
                goto LABEL_388;
              }
LABEL_384:
              v7[7] = 0;
              goto LABEL_388;
            }
LABEL_383:
            v7[6] = 0;
            goto LABEL_388;
          }
          goto LABEL_382;
        }
LABEL_188:
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v242 = __ratelimit(&convert_from_user__rs_35, "convert_from_user");
          v8 = (__int64)&unk_1000;
          v9 = off_6C000;
          if ( v242 )
          {
            printk(&unk_89971, &unk_8E7CE, "convert_from_user", *v7);
            goto LABEL_296;
          }
        }
LABEL_374:
        if ( (*(_BYTE *)(v8 + 3992) & 1) != 0
          && !*((_DWORD *)v9 + 366)
          && (unsigned int)__ratelimit(&cvp_ioctl__rs, "cvp_ioctl") )
        {
          printk(&unk_95E8F, &unk_8E7CE, "cvp_ioctl", *v7);
        }
LABEL_378:
        kfree(v7);
        result = -14;
        goto LABEL_379;
      }
      if ( (unsigned int)get_session_info_from_user(v7 + 4, v370) )
      {
        v9 = off_6C000;
        v8 = (__int64)&unk_1000;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_374;
        v171 = *(unsigned int *)(v61 + 1800);
        v172 = *(unsigned int *)(v61 + 1804);
        v173 = &unk_871A5;
LABEL_183:
        printk(v173, v171, v172, &unk_8E7CE);
LABEL_296:
        v8 = (__int64)&unk_1000;
        v9 = off_6C000;
        goto LABEL_374;
      }
      goto LABEL_199;
    }
    if ( v94 == 268439569 )
      goto LABEL_199;
    if ( v94 != 268439616 )
    {
      v9 = off_6C000;
      v8 = (__int64)&unk_1000;
      if ( v94 != 268439617 )
        goto LABEL_188;
      goto LABEL_199;
    }
    if ( (unsigned int)get_pkt_hdr_from_user(a3, &v372) )
    {
      v8 = (__int64)&unk_1000;
      v9 = off_6C000;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_374;
LABEL_187:
      printk(&unk_935F7, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
      goto LABEL_296;
    }
    session_ctrl_from_user = copy_pkt_from_user(v7, a3, 0, (unsigned int)v372 >> 2);
    goto LABEL_198;
  }
  if ( v94 > 268439620 )
  {
    if ( v94 != 268439621 )
    {
      if ( v94 != 268439622 )
      {
        v9 = off_6C000;
        v8 = (__int64)&unk_1000;
        if ( v94 != 268439623 )
          goto LABEL_188;
        v170 = copy_frameid_from_user(v7, a3);
        v8 = (__int64)&unk_1000;
        v9 = off_6C000;
        if ( v170 )
          goto LABEL_374;
      }
      goto LABEL_199;
    }
    if ( (unsigned int)get_fence_pkt_hdr_from_user(a3, &v372) )
    {
      v8 = (__int64)&unk_1000;
      v9 = off_6C000;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_374;
      goto LABEL_187;
    }
    if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
      printk(&unk_9295E, "hfi", (unsigned int)v372, HIDWORD(v372));
    if ( (get_pkt_index(&v372) & 0x80000000) != 0 )
    {
      v8 = (__int64)&unk_1000;
      v9 = off_6C000;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_84FA2, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
        goto LABEL_296;
      }
      goto LABEL_374;
    }
    session_ctrl_from_user = copy_fence_pkt_from_user(v7, a3);
LABEL_198:
    v9 = off_6C000;
    v8 = (__int64)&unk_1000;
    if ( session_ctrl_from_user )
      goto LABEL_374;
    goto LABEL_199;
  }
  if ( v94 != 268439618 )
  {
    if ( v94 == 268439619 )
    {
      if ( !(unsigned int)copy_sysprop_from_user(v7, a3) )
        goto LABEL_199;
      v9 = off_6C000;
      v8 = (__int64)&unk_1000;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_374;
      v171 = *(unsigned int *)(v61 + 1800);
      v172 = *(unsigned int *)(v61 + 1804);
      v173 = &unk_8AE4A;
      goto LABEL_183;
    }
    session_ctrl_from_user = get_session_ctrl_from_user(v7 + 4, v370);
    goto LABEL_198;
  }
  if ( (unsigned int)copy_sysprop_from_user(v7, a3) )
  {
    v9 = off_6C000;
    v8 = (__int64)&unk_1000;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_374;
    v171 = *(unsigned int *)(v61 + 1800);
    v172 = *(unsigned int *)(v61 + 1804);
    v173 = &unk_94982;
    goto LABEL_183;
  }
LABEL_199:
  if ( (msm_cvp_debug & 0x20000) != 0 && *v7 == 268439616 )
  {
    pkt_name_from_type = get_pkt_name_from_type(v7[5]);
    get_aon_time();
    if ( (msm_cvp_debug & 0x20000) != 0 && !msm_cvp_debug_out )
      printk(&unk_87D3A, "perf", "cvp_ioctl", pkt_name_from_type);
  }
  v244 = msm_cvp_private(v88, a2, v7);
  if ( !(_DWORD)v244 )
  {
    v246 = *(_BYTE *)(v61 + 70);
    v373 = 0;
    v372 = 0;
    if ( (v246 & 0x20) != 0 || (v247 = a3, (*(_QWORD *)v61 & 0x4000000) != 0) )
      v247 = a3 & (v11 >> 8);
    if ( v247 > 0x7FFFFFFFFCLL )
      goto LABEL_213;
    _W9 = *v7;
    v249 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v251 = *(_QWORD *)(v61 + 8);
    _WriteStatusReg(TTBR1_EL1, v251 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v251);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v249);
    __asm { STTR            W9, [X8] }
    v252 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v254 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v254 - 4096);
    _WriteStatusReg(TTBR1_EL1, v254);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v252);
    v255 = *v7;
    if ( (int)*v7 > 268439617 )
    {
      if ( v255 > 268439620 )
      {
        if ( (unsigned int)(v255 - 268439622) < 2 )
          goto LABEL_361;
        if ( v255 != 268439621 )
          goto LABEL_362;
        if ( (unsigned int)get_fence_pkt_hdr_from_user(a3, &v372) )
          goto LABEL_213;
        if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
          printk(&unk_8E560, "hfi", (unsigned int)v372, HIDWORD(v372));
        v304 = copy_fence_pkt_to_user(v7, a3);
      }
      else
      {
        if ( v255 == 268439618 )
          goto LABEL_361;
        if ( v255 == 268439619 )
        {
          if ( !(unsigned int)copy_sysprop_to_user(v7, a3) )
            goto LABEL_361;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_85327, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
          goto LABEL_213;
        }
        v304 = copy_session_ctrl_to_user(v7 + 4, v370);
      }
    }
    else
    {
      if ( v255 <= 268439568 )
      {
        if ( v255 != 268439553 )
        {
          if ( v255 == 268439555 )
          {
            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v315 = a3 + 20, (*(_QWORD *)v61 & 0x4000000) != 0) )
              v315 = (a3 + 20) & ((__int64)((a3 + 20) << 8) >> 8);
            if ( v315 < 0x7FFFFFFFFDLL )
            {
              _W19 = v7[5];
              v317 = uaccess_ttbr0_enable_0(v244);
              __asm { STTR            W19, [X22] }
              v318 = uaccess_ttbr0_disable_0(v317);
              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v319 = v370, (*(_QWORD *)v61 & 0x4000000) != 0) )
                v319 = v370 & ((__int64)(v370 << 8) >> 8);
              if ( v319 < 0x7FFFFFFFFDLL )
              {
                v261 = v7;
                _W23 = v7[4];
                v321 = uaccess_ttbr0_enable_0(v318);
                __asm { STTR            W23, [X22] }
                v322 = uaccess_ttbr0_disable_0(v321);
                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v323 = a3 + 24, (*(_QWORD *)v61 & 0x4000000) != 0) )
                  v323 = (a3 + 24) & ((__int64)((a3 + 24) << 8) >> 8);
                v7 = v261;
                if ( v323 < 0x7FFFFFFFFDLL )
                {
                  _W23 = v261[6];
                  v325 = uaccess_ttbr0_enable_0(v322);
                  __asm { STTR            W23, [X22] }
                  v326 = uaccess_ttbr0_disable_0(v325);
                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v327 = a3 + 28, (*(_QWORD *)v61 & 0x4000000) != 0) )
                    v327 = (a3 + 28) & ((__int64)((a3 + 28) << 8) >> 8);
                  v7 = v261;
                  if ( v327 < 0x7FFFFFFFFDLL )
                  {
                    _W23 = v261[7];
                    v329 = uaccess_ttbr0_enable_0(v326);
                    __asm { STTR            W23, [X22] }
                    v330 = uaccess_ttbr0_disable_0(v329);
                    if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v331 = a3 + 32, (*(_QWORD *)v61 & 0x4000000) != 0) )
                      v331 = (a3 + 32) & ((__int64)((a3 + 32) << 8) >> 8);
                    v7 = v261;
                    if ( v331 < 0x7FFFFFFFFDLL )
                    {
                      _W23 = v261[8];
                      v333 = uaccess_ttbr0_enable_0(v330);
                      __asm { STTR            W23, [X22] }
                      v334 = uaccess_ttbr0_disable_0(v333);
                      if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v335 = a3 + 36, (*(_QWORD *)v61 & 0x4000000) != 0) )
                        v335 = (a3 + 36) & ((__int64)((a3 + 36) << 8) >> 8);
                      v7 = v261;
                      if ( v335 < 0x7FFFFFFFFDLL )
                      {
                        _W23 = v261[9];
                        v337 = uaccess_ttbr0_enable_0(v334);
                        __asm { STTR            W23, [X22] }
                        v338 = uaccess_ttbr0_disable_0(v337);
                        if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v339 = a3 + 40, (*(_QWORD *)v61 & 0x4000000) != 0) )
                          v339 = (a3 + 40) & ((__int64)((a3 + 40) << 8) >> 8);
                        v7 = v261;
                        if ( v339 < 0x7FFFFFFFFDLL )
                        {
                          _W23 = v261[10];
                          v341 = uaccess_ttbr0_enable_0(v338);
                          __asm { STTR            W23, [X22] }
                          v342 = uaccess_ttbr0_disable_0(v341);
                          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v343 = a3 + 44, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            v343 = (a3 + 44) & ((__int64)((a3 + 44) << 8) >> 8);
                          v7 = v261;
                          if ( v343 < 0x7FFFFFFFFDLL )
                          {
                            _W23 = v261[11];
                            v345 = uaccess_ttbr0_enable_0(v342);
                            __asm { STTR            W23, [X22] }
                            v346 = uaccess_ttbr0_disable_0(v345);
                            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                              || (v347 = a3 + 48, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            {
                              v347 = (a3 + 48) & ((__int64)((a3 + 48) << 8) >> 8);
                            }
                            v7 = v261;
                            if ( v347 < 0x7FFFFFFFFDLL )
                            {
                              _W23 = v261[12];
                              v349 = uaccess_ttbr0_enable_0(v346);
                              __asm { STTR            W23, [X22] }
                              v350 = uaccess_ttbr0_disable_0(v349);
                              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                || (v351 = a3 + 52, (*(_QWORD *)v61 & 0x4000000) != 0) )
                              {
                                v351 = (a3 + 52) & ((__int64)((a3 + 52) << 8) >> 8);
                              }
                              v7 = v261;
                              if ( v351 < 0x7FFFFFFFFDLL )
                              {
                                _W23 = v261[13];
                                v353 = uaccess_ttbr0_enable_0(v350);
                                __asm { STTR            W23, [X22] }
                                v354 = uaccess_ttbr0_disable_0(v353);
                                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                  || (v355 = a3 + 56, (*(_QWORD *)v61 & 0x4000000) != 0) )
                                {
                                  v355 = (a3 + 56) & ((__int64)((a3 + 56) << 8) >> 8);
                                }
                                v7 = v261;
                                if ( v355 < 0x7FFFFFFFFDLL )
                                {
                                  _W23 = v261[14];
                                  v357 = uaccess_ttbr0_enable_0(v354);
                                  __asm { STTR            W23, [X22] }
                                  v358 = uaccess_ttbr0_disable_0(v357);
                                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                    || (v359 = a3 + 60, (*(_QWORD *)v61 & 0x4000000) != 0) )
                                  {
                                    v359 = (a3 + 60) & ((__int64)((a3 + 60) << 8) >> 8);
                                  }
                                  v7 = v261;
                                  if ( v359 < 0x7FFFFFFFFDLL )
                                  {
                                    _W22 = v261[15];
                                    v303 = uaccess_ttbr0_enable_0(v358);
                                    __asm { STTR            W22, [X20] }
                                    goto LABEL_350;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LABEL_213:
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_9547C, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
            goto LABEL_378;
          }
          if ( v255 == 268439556 )
          {
            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v256 = a3 + 20, (*(_QWORD *)v61 & 0x4000000) != 0) )
              v256 = (a3 + 20) & ((__int64)((a3 + 20) << 8) >> 8);
            if ( v256 < 0x7FFFFFFFFDLL )
            {
              _W19 = v7[5];
              v258 = uaccess_ttbr0_enable_0(v244);
              __asm { STTR            W19, [X22] }
              v259 = uaccess_ttbr0_disable_0(v258);
              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v260 = v370, (*(_QWORD *)v61 & 0x4000000) != 0) )
                v260 = v370 & ((__int64)(v370 << 8) >> 8);
              if ( v260 < 0x7FFFFFFFFDLL )
              {
                v261 = v7;
                _W23 = v7[4];
                v263 = uaccess_ttbr0_enable_0(v259);
                __asm { STTR            W23, [X22] }
                v264 = uaccess_ttbr0_disable_0(v263);
                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v265 = a3 + 24, (*(_QWORD *)v61 & 0x4000000) != 0) )
                  v265 = (a3 + 24) & ((__int64)((a3 + 24) << 8) >> 8);
                v7 = v261;
                if ( v265 < 0x7FFFFFFFFDLL )
                {
                  _W23 = v261[6];
                  v267 = uaccess_ttbr0_enable_0(v264);
                  __asm { STTR            W23, [X22] }
                  v268 = uaccess_ttbr0_disable_0(v267);
                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v269 = a3 + 28, (*(_QWORD *)v61 & 0x4000000) != 0) )
                    v269 = (a3 + 28) & ((__int64)((a3 + 28) << 8) >> 8);
                  v7 = v261;
                  if ( v269 < 0x7FFFFFFFFDLL )
                  {
                    _W23 = v261[7];
                    v271 = uaccess_ttbr0_enable_0(v268);
                    __asm { STTR            W23, [X22] }
                    v272 = uaccess_ttbr0_disable_0(v271);
                    if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v273 = a3 + 32, (*(_QWORD *)v61 & 0x4000000) != 0) )
                      v273 = (a3 + 32) & ((__int64)((a3 + 32) << 8) >> 8);
                    v7 = v261;
                    if ( v273 < 0x7FFFFFFFFDLL )
                    {
                      _W23 = v261[8];
                      v275 = uaccess_ttbr0_enable_0(v272);
                      __asm { STTR            W23, [X22] }
                      v276 = uaccess_ttbr0_disable_0(v275);
                      if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v277 = a3 + 36, (*(_QWORD *)v61 & 0x4000000) != 0) )
                        v277 = (a3 + 36) & ((__int64)((a3 + 36) << 8) >> 8);
                      v7 = v261;
                      if ( v277 < 0x7FFFFFFFFDLL )
                      {
                        _W23 = v261[9];
                        v279 = uaccess_ttbr0_enable_0(v276);
                        __asm { STTR            W23, [X22] }
                        v280 = uaccess_ttbr0_disable_0(v279);
                        if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v281 = a3 + 40, (*(_QWORD *)v61 & 0x4000000) != 0) )
                          v281 = (a3 + 40) & ((__int64)((a3 + 40) << 8) >> 8);
                        v7 = v261;
                        if ( v281 < 0x7FFFFFFFFDLL )
                        {
                          _W23 = v261[10];
                          v283 = uaccess_ttbr0_enable_0(v280);
                          __asm { STTR            W23, [X22] }
                          v284 = uaccess_ttbr0_disable_0(v283);
                          if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v285 = a3 + 44, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            v285 = (a3 + 44) & ((__int64)((a3 + 44) << 8) >> 8);
                          v7 = v261;
                          if ( v285 < 0x7FFFFFFFFDLL )
                          {
                            _W23 = v261[11];
                            v287 = uaccess_ttbr0_enable_0(v284);
                            __asm { STTR            W23, [X22] }
                            v288 = uaccess_ttbr0_disable_0(v287);
                            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                              || (v289 = a3 + 48, (*(_QWORD *)v61 & 0x4000000) != 0) )
                            {
                              v289 = (a3 + 48) & ((__int64)((a3 + 48) << 8) >> 8);
                            }
                            v7 = v261;
                            if ( v289 < 0x7FFFFFFFFDLL )
                            {
                              _W23 = v261[12];
                              v291 = uaccess_ttbr0_enable_0(v288);
                              __asm { STTR            W23, [X22] }
                              v292 = uaccess_ttbr0_disable_0(v291);
                              if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                || (v293 = a3 + 52, (*(_QWORD *)v61 & 0x4000000) != 0) )
                              {
                                v293 = (a3 + 52) & ((__int64)((a3 + 52) << 8) >> 8);
                              }
                              v7 = v261;
                              if ( v293 < 0x7FFFFFFFFDLL )
                              {
                                _W23 = v261[13];
                                v295 = uaccess_ttbr0_enable_0(v292);
                                __asm { STTR            W23, [X22] }
                                v296 = uaccess_ttbr0_disable_0(v295);
                                if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                  || (v297 = a3 + 56, (*(_QWORD *)v61 & 0x4000000) != 0) )
                                {
                                  v297 = (a3 + 56) & ((__int64)((a3 + 56) << 8) >> 8);
                                }
                                v7 = v261;
                                if ( v297 < 0x7FFFFFFFFDLL )
                                {
                                  _W23 = v261[14];
                                  v299 = uaccess_ttbr0_enable_0(v296);
                                  __asm { STTR            W23, [X22] }
                                  v300 = uaccess_ttbr0_disable_0(v299);
                                  if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0
                                    || (v301 = a3 + 60, (*(_QWORD *)v61 & 0x4000000) != 0) )
                                  {
                                    v301 = (a3 + 60) & ((__int64)((a3 + 60) << 8) >> 8);
                                  }
                                  v7 = v261;
                                  if ( v301 < 0x7FFFFFFFFDLL )
                                  {
                                    _W22 = v261[15];
                                    v303 = uaccess_ttbr0_enable_0(v300);
                                    __asm { STTR            W22, [X20] }
LABEL_350:
                                    uaccess_ttbr0_disable_0(v303);
                                    v7 = v261;
                                    goto LABEL_361;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LABEL_213;
          }
LABEL_362:
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_85CA8, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
          goto LABEL_213;
        }
        if ( (unsigned int)put_user_session_info(v7 + 4, v370) )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_890CD, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
          goto LABEL_213;
        }
LABEL_361:
        kfree(v7);
        result = 0;
        goto LABEL_379;
      }
      if ( v255 == 268439569 )
        goto LABEL_361;
      if ( v255 != 268439616 )
      {
        if ( v255 != 268439617 )
          goto LABEL_362;
        msg_size = get_msg_size((__int64)(v7 + 4));
        if ( msg_size >= 4 )
        {
          v306 = 0;
          v307 = v11 + 4096;
          while ( 1 )
          {
            if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v9 = (char **)(v370 + v306), (*(_QWORD *)v61 & 0x4000000) != 0) )
              v9 = (char **)((a3 + 16 + v306) & (v307 >> 8));
            v8 = 0x7FFFFFFFFDLL;
            if ( (unsigned __int64)v9 >= 0x7FFFFFFFFDLL )
              goto LABEL_213;
            if ( v306 == 2400 )
            {
              __break(0x5512u);
              v362 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v364 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v364 - 4096);
              _WriteStatusReg(TTBR1_EL1, v364);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v362);
              goto LABEL_38;
            }
            _W13 = v7[v306 / 4 + 4];
            v309 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v311 = *(_QWORD *)(v61 + 8);
            _WriteStatusReg(TTBR1_EL1, v311 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v311);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v309);
            __asm { STTR            W13, [X12] }
            v312 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v314 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v314 - 4096);
            _WriteStatusReg(TTBR1_EL1, v314);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v312);
            v306 += 4LL;
            v307 += 1024;
            if ( (msg_size & 0xFFFFFFFC) == v306 )
              goto LABEL_361;
          }
        }
        goto LABEL_361;
      }
      if ( (unsigned int)get_pkt_hdr_from_user(a3, &v372) )
        goto LABEL_213;
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        printk(&unk_8E560, "hfi", (unsigned int)v372, HIDWORD(v372));
      v304 = copy_pkt_to_user(v7, a3, (unsigned int)v372 >> 2);
    }
    if ( !v304 )
      goto LABEL_361;
    goto LABEL_213;
  }
  v245 = v244;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    printk(&unk_8B7FB, *(unsigned int *)(v61 + 1800), *(unsigned int *)(v61 + 1804), &unk_8E7CE);
  kfree(v7);
  result = v245;
LABEL_379:
  _ReadStatusReg(SP_EL0);
  return result;
}
