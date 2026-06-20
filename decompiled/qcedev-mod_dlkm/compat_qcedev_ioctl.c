__int64 __fastcall compat_qcedev_ioctl(__int64 a1, int a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int *v7; // x0
  __int64 v8; // x9
  int v9; // w8
  __int64 v10; // x22
  unsigned __int64 v11; // x21
  unsigned int *v12; // x13
  int v14; // w10
  unsigned __int64 v16; // x11
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x10
  unsigned __int64 v25; // x12
  unsigned __int64 v26; // x13
  int v27; // w12
  unsigned __int64 v29; // x12
  unsigned __int64 v31; // x13
  unsigned __int64 v32; // x12
  unsigned __int64 v34; // x13
  __int64 v35; // x0
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v38; // x9
  unsigned __int64 v40; // x10
  unsigned __int64 v42; // x9
  unsigned __int64 v44; // x10
  unsigned __int64 v46; // x9
  unsigned __int64 v48; // x10
  unsigned __int64 v50; // x8
  unsigned __int64 v52; // x9
  int v53; // w8
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x14
  unsigned __int64 v57; // x13
  int v59; // w11
  unsigned __int64 v61; // x12
  unsigned __int64 v63; // x13
  unsigned __int64 v64; // x11
  unsigned __int64 v66; // x13
  unsigned __int64 v67; // x14
  int v68; // w13
  unsigned __int64 v70; // x13
  unsigned __int64 v72; // x14
  unsigned __int64 v73; // x13
  unsigned __int64 v75; // x14
  unsigned __int64 v77; // x10
  unsigned __int64 v79; // x11
  unsigned __int64 v81; // x10
  unsigned __int64 v83; // x11
  unsigned __int64 v85; // x11
  unsigned __int64 v87; // x12
  __int64 v89; // x17
  unsigned __int64 v90; // x9
  unsigned __int64 v92; // x12
  __int64 v93; // x9
  __int64 v94; // x24
  char *v95; // x12
  int v97; // w11
  unsigned __int64 v99; // x11
  unsigned __int64 v101; // x12
  unsigned __int64 v102; // x11
  unsigned __int64 v104; // x12
  unsigned __int64 v106; // x10
  unsigned __int64 v108; // x11
  unsigned __int64 v110; // x9
  unsigned __int64 v112; // x11
  unsigned __int64 v114; // x11
  unsigned __int64 v116; // x12
  unsigned __int64 v118; // x10
  unsigned __int64 v120; // x12
  unsigned __int64 v122; // x12
  unsigned __int64 v124; // x13
  unsigned __int64 v126; // x11
  unsigned __int64 v128; // x13
  unsigned __int64 v130; // x13
  unsigned __int64 v132; // x14
  unsigned __int64 v134; // x13
  unsigned __int64 v136; // x14
  int v137; // w26
  __int64 v138; // x20
  int v139; // w0
  __int64 v140; // x19
  int v141; // w0
  int v142; // w22
  unsigned int *v143; // x8
  __int64 v144; // x1
  unsigned __int64 v146; // x10
  unsigned __int64 v148; // x11
  unsigned __int64 v150; // x9
  unsigned __int64 v152; // x11
  __int64 v153; // x9
  __int64 v154; // x10
  __int64 v155; // x14
  unsigned __int64 v156; // x13
  int v158; // w11
  unsigned __int64 v160; // x12
  unsigned __int64 v162; // x13
  unsigned __int64 v163; // x11
  unsigned __int64 v165; // x13
  unsigned __int64 v166; // x14
  int v167; // w13
  unsigned __int64 v169; // x13
  unsigned __int64 v171; // x14
  unsigned __int64 v172; // x13
  unsigned __int64 v174; // x14
  unsigned __int64 v176; // x9
  unsigned __int64 v178; // x11
  unsigned __int64 v180; // x10
  unsigned __int64 v182; // x11
  unsigned __int64 v184; // x10
  unsigned __int64 v186; // x11
  unsigned __int64 v188; // x10
  unsigned __int64 v190; // x11
  unsigned __int64 v192; // x10
  unsigned __int64 v194; // x11
  unsigned __int64 v196; // x10
  unsigned __int64 v198; // x11
  __int64 i; // x9
  __int64 v200; // x12
  int v202; // w11
  unsigned __int64 v204; // x11
  unsigned __int64 v206; // x12
  unsigned __int64 v207; // x11
  unsigned __int64 v209; // x12
  unsigned __int64 v211; // x10
  unsigned __int64 v213; // x11
  unsigned __int64 v215; // x10
  unsigned __int64 v217; // x11
  __int64 j; // x9
  __int64 v219; // x12
  int v221; // w11
  unsigned __int64 v223; // x11
  unsigned __int64 v225; // x12
  unsigned __int64 v226; // x11
  unsigned __int64 v228; // x12
  unsigned __int64 v230; // x10
  unsigned __int64 v232; // x11
  unsigned __int64 v234; // x9
  unsigned __int64 v236; // x11
  unsigned __int64 v238; // x11
  unsigned __int64 v240; // x12
  unsigned __int64 v242; // x10
  unsigned __int64 v244; // x12
  unsigned __int64 v246; // x12
  unsigned __int64 v248; // x13
  unsigned __int64 v250; // x11
  unsigned __int64 v252; // x13
  unsigned __int64 v254; // x13
  unsigned __int64 v256; // x14
  unsigned __int64 v258; // x12
  unsigned __int64 v260; // x14
  unsigned __int64 v262; // x14
  unsigned __int64 v264; // x15
  unsigned __int64 v266; // x14
  unsigned __int64 v268; // x15
  int v269; // w19
  int *v270; // x26
  __int64 v271; // x25
  unsigned __int8 *v272; // x19
  __int64 v273; // x1
  __int64 v274; // x10
  __int64 v275; // x11
  __int64 v276; // x15
  unsigned __int64 v277; // x14
  int v279; // w12
  unsigned __int64 v281; // x13
  unsigned __int64 v283; // x14
  unsigned __int64 v284; // x12
  unsigned __int64 v286; // x14
  unsigned __int64 v287; // x15
  int v288; // w14
  unsigned __int64 v290; // x14
  unsigned __int64 v292; // x15
  unsigned __int64 v293; // x14
  unsigned __int64 v295; // x15
  __int64 v296; // x10
  __int64 v297; // x11
  __int64 v298; // x15
  unsigned __int64 v299; // x14
  int v301; // w12
  unsigned __int64 v303; // x13
  unsigned __int64 v305; // x14
  unsigned __int64 v306; // x12
  unsigned __int64 v308; // x14
  unsigned __int64 v309; // x15
  int v310; // w14
  unsigned __int64 v312; // x14
  unsigned __int64 v314; // x15
  unsigned __int64 v315; // x14
  unsigned __int64 v317; // x15
  int v318; // w21
  __int64 v319; // x8
  unsigned int *v320; // x20
  __int64 v321; // x0
  __int64 v322; // x9
  int v323; // w8
  int v325; // w10
  unsigned __int64 v326; // x12
  unsigned __int64 v328; // x13
  unsigned __int64 v329; // x10
  unsigned __int64 v331; // x11
  int v333; // w12
  unsigned __int64 v334; // x13
  unsigned __int64 v336; // x14
  unsigned __int64 v337; // x11
  unsigned __int64 v339; // x12
  unsigned __int64 v341; // x11
  unsigned __int64 v343; // x12
  unsigned __int64 v344; // x9
  unsigned __int64 v346; // x10
  unsigned __int64 v348; // x12
  unsigned __int64 v350; // x13
  unsigned __int64 v351; // x9
  unsigned __int64 v353; // x11
  __int64 ii; // x9
  unsigned __int64 v356; // x12
  unsigned __int64 v358; // x13
  unsigned __int64 v359; // x10
  unsigned __int64 v361; // x11
  unsigned __int64 v363; // x11
  unsigned __int64 v365; // x12
  unsigned __int64 v366; // x9
  unsigned __int64 v369; // x12
  unsigned __int64 v371; // x13
  unsigned __int64 v372; // x10
  unsigned __int64 v374; // x11
  unsigned __int64 v376; // x13
  unsigned __int64 v378; // x14
  unsigned __int64 v379; // x11
  unsigned __int64 v382; // x14
  unsigned __int64 v384; // x15
  unsigned __int64 v385; // x12
  unsigned __int64 v387; // x13
  int v388; // w19
  __int64 v389; // x0
  unsigned __int8 *v391; // x8
  unsigned __int64 v392; // x11
  unsigned __int64 v394; // x12
  unsigned __int8 *v395; // x0
  unsigned __int64 v396; // x8
  unsigned __int64 v398; // x10
  unsigned __int64 v400; // x11
  unsigned __int64 v402; // x12
  unsigned __int64 v403; // x9
  unsigned __int64 v405; // x10
  __int64 v406; // x10
  unsigned __int8 *v407; // x11
  int v409; // w12
  unsigned __int64 v410; // x14
  unsigned __int64 v412; // x15
  unsigned __int64 v413; // x12
  unsigned __int64 v415; // x13
  int v417; // w14
  unsigned __int64 v418; // x15
  unsigned __int64 v420; // x16
  unsigned __int64 v421; // x13
  unsigned __int64 v423; // x14
  unsigned __int64 v425; // x12
  unsigned __int64 v427; // x13
  unsigned __int64 v428; // x10
  unsigned __int64 v430; // x11
  __int64 v431; // x10
  unsigned __int8 *v432; // x11
  int v434; // w12
  unsigned __int64 v435; // x14
  unsigned __int64 v437; // x15
  unsigned __int64 v438; // x12
  unsigned __int64 v440; // x13
  int v442; // w14
  unsigned __int64 v443; // x15
  unsigned __int64 v445; // x16
  unsigned __int64 v446; // x13
  unsigned __int64 v448; // x14
  __int64 k; // x10
  int v451; // w11
  unsigned __int64 v452; // x13
  unsigned __int64 v454; // x14
  unsigned __int64 v455; // x11
  unsigned __int64 v457; // x12
  int v459; // w13
  unsigned __int64 v460; // x14
  unsigned __int64 v462; // x15
  unsigned __int64 v463; // x12
  unsigned __int64 v465; // x13
  __int64 v466; // x10
  unsigned __int8 *v467; // x11
  int v469; // w12
  unsigned __int64 v470; // x14
  unsigned __int64 v472; // x15
  unsigned __int64 v473; // x12
  unsigned __int64 v475; // x13
  int v477; // w14
  unsigned __int64 v478; // x15
  unsigned __int64 v480; // x16
  unsigned __int64 v481; // x13
  unsigned __int64 v483; // x14
  int v485; // w8
  unsigned __int64 v486; // x9
  unsigned __int64 v488; // x12
  unsigned __int64 v489; // x9
  unsigned __int64 v491; // x10
  unsigned __int64 v493; // x10
  unsigned __int64 v495; // x12
  unsigned __int64 v498; // x10
  unsigned __int64 v499; // x10
  unsigned __int64 v501; // x12
  unsigned __int64 v502; // x9
  unsigned __int64 v504; // x10
  __int64 m; // x9
  unsigned __int64 v507; // x12
  unsigned __int64 v509; // x13
  unsigned __int64 v510; // x10
  unsigned __int64 v512; // x11
  unsigned __int64 v514; // x11
  unsigned __int64 v516; // x12
  unsigned __int64 v517; // x9
  unsigned __int64 v519; // x10
  __int64 n; // x9
  unsigned __int64 v522; // x12
  unsigned __int64 v524; // x13
  unsigned __int64 v525; // x10
  unsigned __int64 v527; // x11
  unsigned __int64 v529; // x11
  unsigned __int64 v531; // x12
  unsigned __int64 v532; // x9
  unsigned __int64 v534; // x10
  unsigned __int64 v536; // x12
  unsigned __int64 v538; // x13
  unsigned __int64 v539; // x10
  unsigned __int64 v542; // x13
  unsigned __int64 v544; // x14
  unsigned __int64 v545; // x11
  unsigned __int64 v548; // x14
  unsigned __int64 v550; // x15
  unsigned __int64 v551; // x12
  unsigned __int64 v554; // x15
  unsigned __int64 v556; // x16
  unsigned __int64 v557; // x13
  unsigned __int64 v559; // x14
  int v560; // w20
  __int64 v561; // [xsp+30h] [xbp-10h]

  result = -515;
  if ( a2 > -1039628535 )
  {
    if ( (unsigned int)(a2 + 1028094207) >= 2 )
    {
      if ( a2 != -1039628534 )
        return result;
      v138 = _kmalloc_cache_noprof(memmove, 3264, 328);
      if ( v138 )
      {
        v139 = compat_xfer_qcedev_map_buf_req(a3, v138, 1);
        if ( v139 )
        {
LABEL_33:
          v142 = v139;
          kfree(v138);
          return v142;
        }
        v140 = qcedev_ioctl(a1, 3242755850LL, v138);
        v141 = compat_xfer_qcedev_map_buf_req(a3, v138, 0);
        goto LABEL_84;
      }
      return -22;
    }
    v35 = _kmalloc_cache_noprof(_arch_copy_to_user, 3264, 672);
    if ( !v35 )
      return -14;
    StatusReg = _ReadStatusReg(SP_EL0);
    _X8 = a3;
    v38 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v40 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v40);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v38);
    __asm { LDTRB           W8, [X8] }
    v42 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v44 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v44 - 4096);
    _WriteStatusReg(TTBR1_EL1, v44);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v42);
    *(_BYTE *)v35 = _X8;
    if ( (_BYTE)_X8 )
    {
      _X8 = (a3 + 8LL) & 0xFF7FFFFFFFFFFFFFLL;
      v46 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v48 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v48 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v48);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v46);
      __asm { LDTR            W10, [X8] }
      v50 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v52 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v52 - 4096);
      _WriteStatusReg(TTBR1_EL1, v52);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v50);
      v53 = 0;
      v54 = 0;
      *(_DWORD *)(v35 + 8) = _X10;
      v55 = v35 + 16;
      do
      {
        v57 = a3 + v54 + 16;
        LODWORD(_X12) = 0;
        v59 = -14;
        if ( v57 < 0x7FFFFFFFF9LL )
        {
          _X11 = v57 & 0xFF7FFFFFFFFFFFFFLL;
          v61 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v63 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v63 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v63);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v61);
          __asm { LDTR            X12, [X11] }
          v64 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v66 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v66 - 4096);
          _WriteStatusReg(TTBR1_EL1, v66);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v64);
          v59 = 0;
        }
        *(_DWORD *)(v55 + v54) = _X12;
        v67 = a3 + v54 + 24;
        LODWORD(_X12) = 0;
        v68 = -14;
        if ( v67 < 0x7FFFFFFFF9LL )
        {
          _X12 = v67 & 0xFF7FFFFFFFFFFFFFLL;
          v70 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v72 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v72 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v72);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v70);
          __asm { LDTR            X12, [X12] }
          v73 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v75 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v75 - 4096);
          _WriteStatusReg(TTBR1_EL1, v75);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v73);
          v68 = 0;
        }
        v56 = v55 + v54;
        v54 += 16;
        v53 |= v59 | v68;
        *(_DWORD *)(v56 + 8) = _X12;
      }
      while ( v54 != 256 );
      _X9 = (a3 + 272LL) & 0xFF7FFFFFFFFFFFFFLL;
      v146 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v148 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v148 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v148);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v146);
      __asm { LDTR            W10, [X9] }
      v150 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v152 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v152 - 4096);
      _WriteStatusReg(TTBR1_EL1, v152);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v150);
      v153 = 0;
      *(_DWORD *)(v35 + 272) = _X10;
      v154 = v35 + 280;
      do
      {
        v156 = a3 + v153 + 280;
        LODWORD(_X12) = 0;
        v158 = -14;
        if ( v156 < 0x7FFFFFFFF9LL )
        {
          _X11 = v156 & 0xFF7FFFFFFFFFFFFFLL;
          v160 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v162 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v162 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v162);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v160);
          __asm { LDTR            X12, [X11] }
          v163 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v165 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v165 - 4096);
          _WriteStatusReg(TTBR1_EL1, v165);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v163);
          v158 = 0;
        }
        *(_DWORD *)(v154 + v153) = _X12;
        v166 = a3 + v153 + 288;
        LODWORD(_X12) = 0;
        v167 = -14;
        if ( v166 < 0x7FFFFFFFF9LL )
        {
          _X12 = v166 & 0xFF7FFFFFFFFFFFFFLL;
          v169 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v171 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v171 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v171);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v169);
          __asm { LDTR            X12, [X12] }
          v172 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v174 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v174 - 4096);
          _WriteStatusReg(TTBR1_EL1, v174);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v172);
          v167 = 0;
        }
        v155 = v154 + v153;
        v153 += 16;
        v53 |= v158 | v167;
        *(_DWORD *)(v155 + 8) = _X12;
      }
      while ( v153 != 256 );
    }
    else
    {
      v274 = 0;
      v53 = 0;
      v275 = v35 + 8;
      do
      {
        v277 = a3 + v274 + 8;
        LODWORD(_X13) = 0;
        v279 = -14;
        if ( v277 < 0x7FFFFFFFFDLL )
        {
          _X12 = v277 & 0xFF7FFFFFFFFFFFFFLL;
          v281 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v283 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v283 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v283);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v281);
          __asm { LDTR            W13, [X12] }
          v284 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v286 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v286 - 4096);
          _WriteStatusReg(TTBR1_EL1, v286);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v284);
          v279 = 0;
        }
        *(_DWORD *)(v275 + v274) = _X13;
        v287 = a3 + v274 + 16;
        LODWORD(_X13) = 0;
        v288 = -14;
        if ( v287 < 0x7FFFFFFFF9LL )
        {
          _X13 = v287 & 0xFF7FFFFFFFFFFFFFLL;
          v290 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v292 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v292 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v292);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v290);
          __asm { LDTR            X13, [X13] }
          v293 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v295 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v295 - 4096);
          _WriteStatusReg(TTBR1_EL1, v295);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v293);
          v288 = 0;
        }
        v276 = v275 + v274;
        v274 += 16;
        v53 |= v279 | v288;
        *(_DWORD *)(v276 + 8) = _X13;
      }
      while ( v274 != 256 );
      v296 = 0;
      v297 = v35 + 264;
      do
      {
        v299 = a3 + v296 + 264;
        LODWORD(_X13) = 0;
        v301 = -14;
        if ( v299 < 0x7FFFFFFFFDLL )
        {
          _X12 = v299 & 0xFF7FFFFFFFFFFFFFLL;
          v303 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v305 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v305 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v305);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v303);
          __asm { LDTR            W13, [X12] }
          v306 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v308 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v308 - 4096);
          _WriteStatusReg(TTBR1_EL1, v308);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v306);
          v301 = 0;
        }
        *(_DWORD *)(v297 + v296) = _X13;
        v309 = a3 + v296 + 272;
        LODWORD(_X13) = 0;
        v310 = -14;
        if ( v309 < 0x7FFFFFFFF9LL )
        {
          _X13 = v309 & 0xFF7FFFFFFFFFFFFFLL;
          v312 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v314 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v314 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v314);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v312);
          __asm { LDTR            X13, [X13] }
          v315 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v317 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v317 - 4096);
          _WriteStatusReg(TTBR1_EL1, v317);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v315);
          v310 = 0;
        }
        v298 = v297 + v296;
        v296 += 16;
        v53 |= v301 | v310;
        *(_DWORD *)(v298 + 8) = _X13;
      }
      while ( v296 != 256 );
    }
    _X10 = (a3 + 536LL) & 0xFF7FFFFFFFFFFFFFLL;
    v176 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v178 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v178 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v178);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v176);
    __asm { LDTR            X9, [X10] }
    v180 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v182 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v182 - 4096);
    _WriteStatusReg(TTBR1_EL1, v182);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v180);
    *(_DWORD *)(v35 + 536) = _X9;
    _X9 = (a3 + 544LL) & 0xFF7FFFFFFFFFFFFFLL;
    v184 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v186 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v186 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v186);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v184);
    __asm { LDTR            X9, [X9] }
    v188 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v190 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v190 - 4096);
    _WriteStatusReg(TTBR1_EL1, v190);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v188);
    *(_DWORD *)(v35 + 540) = _X9;
    _X9 = (a3 + 552LL) & 0xFF7FFFFFFFFFFFFFLL;
    v192 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v194 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v194 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v194);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v192);
    __asm { LDTRB           W9, [X9] }
    v196 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v198 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v198 - 4096);
    _WriteStatusReg(TTBR1_EL1, v198);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v196);
    *(_BYTE *)(v35 + 544) = _X9;
    for ( i = 553; i != 617; ++i )
    {
      LOBYTE(_X10) = 0;
      v202 = -14;
      if ( !(((unsigned __int64)a3 + i) >> 39) )
      {
        _X10 = (a3 + i) & 0xFF7FFFFFFFFFFFFFLL;
        v204 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v206 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v206 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v206);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v204);
        __asm { LDTRB           W10, [X10] }
        v207 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v209 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v209 - 4096);
        _WriteStatusReg(TTBR1_EL1, v209);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v207);
        v202 = 0;
      }
      v200 = v35 + i;
      v53 |= v202;
      *(_BYTE *)(v200 - 8) = _X10;
    }
    _X9 = (a3 + 624LL) & 0xFF7FFFFFFFFFFFFFLL;
    v211 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v213 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v213 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v213);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v211);
    __asm { LDTR            X9, [X9] }
    v215 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v217 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v217 - 4096);
    _WriteStatusReg(TTBR1_EL1, v217);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v215);
    *(_DWORD *)(v35 + 612) = _X9;
    for ( j = 632; j != 664; ++j )
    {
      LOBYTE(_X10) = 0;
      v221 = -14;
      if ( !(((unsigned __int64)a3 + j) >> 39) )
      {
        _X10 = (a3 + j) & 0xFF7FFFFFFFFFFFFFLL;
        v223 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v225 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v225 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v225);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v223);
        __asm { LDTRB           W10, [X10] }
        v226 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v228 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v228 - 4096);
        _WriteStatusReg(TTBR1_EL1, v228);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v226);
        v221 = 0;
      }
      v219 = v35 + j;
      v53 |= v221;
      *(_BYTE *)(v219 - 16) = _X10;
    }
    _X9 = (a3 + 664LL) & 0xFF7FFFFFFFFFFFFFLL;
    v230 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v232 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v232 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v232);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v230);
    __asm { LDTR            X10, [X9] }
    v234 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v236 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v236 - 4096);
    _WriteStatusReg(TTBR1_EL1, v236);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v234);
    *(_DWORD *)(v35 + 648) = _X10;
    _X10 = (a3 + 672LL) & 0xFF7FFFFFFFFFFFFFLL;
    v238 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v240 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v240 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v240);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v238);
    __asm { LDTR            X11, [X10] }
    v242 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v244 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v244 - 4096);
    _WriteStatusReg(TTBR1_EL1, v244);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v242);
    *(_DWORD *)(v35 + 652) = _X11;
    _X11 = (a3 + 680LL) & 0xFF7FFFFFFFFFFFFFLL;
    v246 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v248 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v248 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v248);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v246);
    __asm { LDTR            W12, [X11] }
    v250 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v252 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v252 - 4096);
    _WriteStatusReg(TTBR1_EL1, v252);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v250);
    *(_DWORD *)(v35 + 656) = _X12;
    _X12 = (a3 + 684LL) & 0xFF7FFFFFFFFFFFFFLL;
    v254 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v256 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v256 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v256);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v254);
    __asm { LDTR            W13, [X12] }
    v258 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v260 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v260 - 4096);
    _WriteStatusReg(TTBR1_EL1, v260);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v258);
    *(_DWORD *)(v35 + 660) = _X13;
    _X13 = (a3 + 688LL) & 0xFF7FFFFFFFFFFFFFLL;
    v262 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v264 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v264 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v264);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v262);
    __asm { LDTR            W13, [X13] }
    v266 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v268 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v268 - 4096);
    _WriteStatusReg(TTBR1_EL1, v268);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v266);
    *(_DWORD *)(v35 + 664) = _X13;
    v269 = v53;
    if ( v53 )
    {
      ((void (*)(void))kfree)();
      return v269;
    }
    if ( a2 <= -1051687163 )
    {
      v270 = (int *)(v35 + 8);
      v271 = a3 + 8LL;
      v272 = (unsigned __int8 *)v35;
      if ( a2 > -1051687165 )
      {
        if ( a2 == -1051687164 )
          v273 = 3242231556LL;
        else
          v273 = 3242231557LL;
        goto LABEL_115;
      }
      if ( a2 == -1064794357 )
      {
        v273 = 3225716491LL;
        goto LABEL_115;
      }
      if ( a2 == -1051687165 )
      {
        v273 = 3242231555LL;
        goto LABEL_115;
      }
    }
    else
    {
      v270 = (int *)(v35 + 8);
      v271 = a3 + 8LL;
      v272 = (unsigned __int8 *)v35;
      if ( a2 <= -1039628535 )
      {
        if ( a2 == -1051687162 )
        {
          v273 = 3242231558LL;
          goto LABEL_115;
        }
        if ( a2 == -1051687159 )
        {
          v273 = 3242231561LL;
          goto LABEL_115;
        }
      }
      else
      {
        if ( a2 == -1039628534 )
        {
          v273 = 3242755850LL;
          goto LABEL_115;
        }
        v273 = 3265300225LL;
        if ( a2 == -1028094207 )
        {
LABEL_115:
          v389 = qcedev_ioctl(a1, v273, v272);
          _W9 = *v272;
          v391 = v272;
          v140 = v389;
          v392 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v394 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v394 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v394);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v392);
          v395 = v391;
          __asm { STTRB           W9, [X10] }
          v396 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v398 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v398 - 4096);
          _WriteStatusReg(TTBR1_EL1, v398);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v396);
          if ( _W9 )
          {
            _W9 = *v270;
            v400 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v402 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v402 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v402);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v400);
            __asm { STTR            W9, [X10] }
            v403 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v405 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v405 - 4096);
            _WriteStatusReg(TTBR1_EL1, v405);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v403);
            _W9 = 0;
            v406 = 0;
            v407 = v395 + 16;
            do
            {
              _X13 = *(unsigned int *)&v407[v406];
              v409 = -14;
              if ( (unsigned __int64)a3 + v406 + 16 < 0x7FFFFFFFF9LL )
              {
                v410 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v412 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v412 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v412);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v410);
                __asm { STTR            X13, [X12] }
                v413 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v415 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v415 - 4096);
                _WriteStatusReg(TTBR1_EL1, v415);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v413);
                v409 = 0;
              }
              _X13 = *(unsigned int *)&v407[v406 + 8];
              v417 = -14;
              if ( (unsigned __int64)a3 + v406 + 24 < 0x7FFFFFFFF9LL )
              {
                v418 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v420 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v420 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v420);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v418);
                __asm { STTR            X13, [X14] }
                v421 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v423 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v423 - 4096);
                _WriteStatusReg(TTBR1_EL1, v423);
                __isb(0xFu);
                v417 = 0;
                _WriteStatusReg(DAIF, v421);
              }
              v406 += 16;
              _W9 |= v409 | v417;
            }
            while ( v406 != 256 );
            _W10 = *((_DWORD *)v395 + 68);
            v425 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v427 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v427 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v427);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v425);
            __asm { STTR            W10, [X11] }
            v428 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v430 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v430 - 4096);
            _WriteStatusReg(TTBR1_EL1, v430);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v428);
            v431 = 0;
            v432 = v395 + 280;
            do
            {
              _X13 = *(unsigned int *)&v432[v431];
              v434 = -14;
              if ( (unsigned __int64)a3 + v431 + 280 < 0x7FFFFFFFF9LL )
              {
                v435 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v437 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v437 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v437);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v435);
                __asm { STTR            X13, [X12] }
                v438 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v440 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v440 - 4096);
                _WriteStatusReg(TTBR1_EL1, v440);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v438);
                v434 = 0;
              }
              _X13 = *(unsigned int *)&v432[v431 + 8];
              v442 = -14;
              if ( (unsigned __int64)a3 + v431 + 288 < 0x7FFFFFFFF9LL )
              {
                v443 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v445 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v445 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v445);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v443);
                __asm { STTR            X13, [X14] }
                v446 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v448 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v448 - 4096);
                _WriteStatusReg(TTBR1_EL1, v448);
                __isb(0xFu);
                v442 = 0;
                _WriteStatusReg(DAIF, v446);
              }
              v431 += 16;
              _W9 |= v434 | v442;
            }
            while ( v431 != 256 );
          }
          else
          {
            for ( k = 0; k != 64; k += 4 )
            {
              _W12 = v270[k];
              v451 = -14;
              if ( (unsigned __int64)(v271 + k * 4) < 0x7FFFFFFFFDLL )
              {
                v452 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v454 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v454 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v454);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v452);
                __asm { STTR            W12, [X11] }
                v455 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v457 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v457 - 4096);
                _WriteStatusReg(TTBR1_EL1, v457);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v455);
                v451 = 0;
              }
              _X12 = (unsigned int)v270[k + 2];
              v459 = -14;
              if ( (unsigned __int64)(v271 + k * 4 + 8) < 0x7FFFFFFFF9LL )
              {
                v460 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v462 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v462 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v462);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v460);
                __asm { STTR            X12, [X13] }
                v463 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v465 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v465 - 4096);
                _WriteStatusReg(TTBR1_EL1, v465);
                __isb(0xFu);
                v459 = 0;
                _WriteStatusReg(DAIF, v463);
              }
              _W9 |= v451 | v459;
            }
            v466 = 0;
            v467 = v395 + 264;
            do
            {
              _W13 = *(_DWORD *)&v467[v466];
              v469 = -14;
              if ( (unsigned __int64)a3 + v466 + 264 < 0x7FFFFFFFFDLL )
              {
                v470 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v472 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v472 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v472);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v470);
                __asm { STTR            W13, [X12] }
                v473 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v475 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v475 - 4096);
                _WriteStatusReg(TTBR1_EL1, v475);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v473);
                v469 = 0;
              }
              _X13 = *(unsigned int *)&v467[v466 + 8];
              v477 = -14;
              if ( (unsigned __int64)a3 + v466 + 272 < 0x7FFFFFFFF9LL )
              {
                v478 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v480 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v480 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v480);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v478);
                __asm { STTR            X13, [X14] }
                v481 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v483 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v483 - 4096);
                _WriteStatusReg(TTBR1_EL1, v483);
                __isb(0xFu);
                v477 = 0;
                _WriteStatusReg(DAIF, v481);
              }
              v466 += 16;
              _W9 |= v469 | v477;
            }
            while ( v466 != 256 );
          }
          _X10 = *((unsigned int *)v395 + 134);
          v485 = _W9;
          v486 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v488 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v488 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v488);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v486);
          __asm { STTR            X10, [X11] }
          v489 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v491 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v491 - 4096);
          _WriteStatusReg(TTBR1_EL1, v491);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v489);
          _X9 = *((unsigned int *)v395 + 135);
          v493 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v495 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v495 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v495);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v493);
          __asm { STTR            X9, [X11] }
          _X9 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v498 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v498 - 4096);
          _WriteStatusReg(TTBR1_EL1, v498);
          __isb(0xFu);
          _WriteStatusReg(DAIF, _X9);
          LODWORD(_X9) = v395[544];
          v499 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v501 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v501 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v501);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v499);
          __asm { STTRB           W9, [X11] }
          v502 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v504 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v504 - 4096);
          _WriteStatusReg(TTBR1_EL1, v504);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v502);
          for ( m = 0; m != 64; ++m )
          {
            _W10 = v395[m + 545];
            v507 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v509 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v509 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v509);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v507);
            __asm { STTRB           W10, [X11] }
            v510 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v512 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v512 - 4096);
            _WriteStatusReg(TTBR1_EL1, v512);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v510);
          }
          _X9 = *((unsigned int *)v395 + 153);
          v514 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v516 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v516 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v516);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v514);
          __asm { STTR            X9, [X10] }
          v517 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v519 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v519 - 4096);
          _WriteStatusReg(TTBR1_EL1, v519);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v517);
          for ( n = 0; n != 32; ++n )
          {
            _W10 = v395[n + 616];
            v522 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v524 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v524 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v524);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v522);
            __asm { STTRB           W10, [X11] }
            v525 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v527 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v527 - 4096);
            _WriteStatusReg(TTBR1_EL1, v527);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v525);
          }
          _X9 = *((unsigned int *)v395 + 162);
          v529 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v531 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v531 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v531);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v529);
          __asm { STTR            X9, [X10] }
          v532 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v534 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v534 - 4096);
          _WriteStatusReg(TTBR1_EL1, v534);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v532);
          _X10 = *((unsigned int *)v395 + 163);
          v536 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v538 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v538 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v538);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v536);
          __asm { STTR            X10, [X11] }
          v539 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          _X11 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, _X11 - 4096);
          _WriteStatusReg(TTBR1_EL1, _X11);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v539);
          LODWORD(_X11) = *((_DWORD *)v395 + 164);
          v542 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v544 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v544 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v544);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v542);
          __asm { STTR            W11, [X12] }
          v545 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          _X12 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, _X12 - 4096);
          _WriteStatusReg(TTBR1_EL1, _X12);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v545);
          LODWORD(_X12) = *((_DWORD *)v395 + 165);
          v548 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v550 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v550 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v550);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v548);
          __asm { STTR            W12, [X13] }
          v551 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          _X13 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, _X13 - 4096);
          _WriteStatusReg(TTBR1_EL1, _X13);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v551);
          LODWORD(_X13) = *((_DWORD *)v395 + 166);
          v554 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v556 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v556 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v556);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v554);
          __asm { STTR            W13, [X14] }
          v557 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v559 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v559 - 4096);
          _WriteStatusReg(TTBR1_EL1, v559);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v557);
          v560 = v485;
          ((void (*)(void))kfree)();
          v319 = v560;
          goto LABEL_145;
        }
        if ( a2 == -1028094206 )
        {
          v273 = 3265300226LL;
          goto LABEL_115;
        }
      }
    }
    v273 = (unsigned int)a2;
    goto LABEL_115;
  }
  if ( (unsigned int)(a2 + 1051687165) > 6 || ((1 << (a2 - 3)) & 0x4F) == 0 )
  {
    if ( a2 != -1064794357 )
      return result;
    v138 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 68);
    if ( v138 )
    {
      v139 = compat_xfer_qcedev_unmap_buf_req(a3, v138, 1);
      if ( v139 )
        goto LABEL_33;
      v140 = qcedev_ioctl(a1, 3225716491LL, v138);
      v141 = compat_xfer_qcedev_unmap_buf_req(a3, v138, 0);
LABEL_84:
      v318 = v141;
      kfree(v138);
      v319 = v318;
LABEL_145:
      if ( v140 )
        return v140;
      else
        return v319;
    }
    return -22;
  }
  v7 = (unsigned int *)_kmalloc_cache_noprof(memmove, 3264, 320);
  if ( !v7 )
    return -14;
  v8 = 0;
  v9 = 0;
  v10 = a3;
  v11 = _ReadStatusReg(SP_EL0);
  do
  {
    LODWORD(_X11) = 0;
    v14 = -14;
    if ( (unsigned __int64)(v10 + v8 * 4) < 0x7FFFFFFFFDLL )
    {
      _X10 = (v10 + v8 * 4) & 0xFF7FFFFFFFFFFFFFLL;
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      __asm { LDTR            W11, [X10] }
      v23 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v25 - 4096);
      _WriteStatusReg(TTBR1_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v23);
      v14 = 0;
    }
    v7[v8] = _X11;
    v26 = v10 + v8 * 4 + 8;
    LODWORD(_X11) = 0;
    v27 = -14;
    if ( v26 < 0x7FFFFFFFF9LL )
    {
      _X11 = v26 & 0xFF7FFFFFFFFFFFFFLL;
      v29 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v31 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v31 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v31);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v29);
      __asm { LDTR            X11, [X11] }
      v32 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v34 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v34 - 4096);
      _WriteStatusReg(TTBR1_EL1, v34);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v32);
      v27 = 0;
    }
    v12 = &v7[v8];
    v8 += 4;
    v9 |= v14 | v27;
    v12[2] = _X11;
  }
  while ( v8 != 64 );
  _X9 = (v10 + 256) & 0xFF7FFFFFFFFFFFFFLL;
  v77 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v79 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v79 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v79);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v77);
  __asm { LDTR            X9, [X9] }
  v81 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v83 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v83 - 4096);
  _WriteStatusReg(TTBR1_EL1, v83);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v81);
  v7[64] = _X9;
  _X9 = (v10 + 264) & 0xFF7FFFFFFFFFFFFFLL;
  v85 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v87 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v87 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v87);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v85);
  __asm { LDTR            X11, [X9] }
  v89 = a1;
  v90 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v92 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v92 - 4096);
  _WriteStatusReg(TTBR1_EL1, v92);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v90);
  v93 = 0;
  v94 = v10 + 272;
  v7[65] = _X11;
  do
  {
    LOBYTE(_X10) = 0;
    v97 = -14;
    if ( !((unsigned __int64)(v94 + v93) >> 39) )
    {
      _X10 = (v94 + v93) & 0xFF7FFFFFFFFFFFFFLL;
      v99 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v101 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v101 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v101);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v99);
      __asm { LDTRB           W10, [X10] }
      v102 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v104 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v104 - 4096);
      _WriteStatusReg(TTBR1_EL1, v104);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v102);
      v97 = 0;
    }
    v95 = (char *)v7 + v93++;
    v9 |= v97;
    v95[264] = _X10;
  }
  while ( v93 != 32 );
  _X9 = (v10 + 304) & 0xFF7FFFFFFFFFFFFFLL;
  v106 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v108 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v108 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v108);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v106);
  __asm { LDTR            X10, [X9] }
  v110 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v112 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v112 - 4096);
  _WriteStatusReg(TTBR1_EL1, v112);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v110);
  v7[74] = _X10;
  _X10 = (v10 + 312) & 0xFF7FFFFFFFFFFFFFLL;
  v114 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v116 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v116 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v116);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v114);
  __asm { LDTR            W11, [X10] }
  v118 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v120 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v120 - 4096);
  _WriteStatusReg(TTBR1_EL1, v120);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v118);
  v7[76] = _X11;
  _X11 = (v10 + 320) & 0xFF7FFFFFFFFFFFFFLL;
  v122 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v124 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v124 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v124);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v122);
  __asm { LDTR            X12, [X11] }
  v126 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v128 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v128 - 4096);
  _WriteStatusReg(TTBR1_EL1, v128);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v126);
  v7[78] = _X12;
  _X12 = (v10 + 328) & 0xFF7FFFFFFFFFFFFFLL;
  v130 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v132 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v132 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v132);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v130);
  __asm { LDTR            W12, [X12] }
  v134 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v136 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v136 - 4096);
  _WriteStatusReg(TTBR1_EL1, v136);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v134);
  v7[79] = _X12;
  v137 = v9;
  if ( v9 )
  {
    kfree(v7);
    return v137;
  }
  if ( a2 > -1051687163 )
  {
    if ( a2 <= -1039628535 )
    {
      v143 = v7;
      if ( a2 == -1051687162 )
      {
        v144 = 3242231558LL;
        goto LABEL_94;
      }
      if ( a2 == -1051687159 )
      {
        v144 = 3242231561LL;
        goto LABEL_94;
      }
    }
    else
    {
      v143 = v7;
      if ( a2 == -1039628534 )
      {
        v144 = 3242755850LL;
        goto LABEL_94;
      }
      v144 = 3265300225LL;
      if ( a2 == -1028094207 )
        goto LABEL_94;
      if ( a2 == -1028094206 )
      {
        v144 = 3265300226LL;
        goto LABEL_94;
      }
    }
    goto LABEL_93;
  }
  if ( a2 <= -1051687165 )
  {
    v143 = v7;
    if ( a2 == -1064794357 )
    {
      v144 = 3225716491LL;
      goto LABEL_94;
    }
    if ( a2 == -1051687165 )
    {
      v144 = 3242231555LL;
      goto LABEL_94;
    }
LABEL_93:
    v144 = (unsigned int)a2;
    goto LABEL_94;
  }
  v143 = v7;
  if ( a2 == -1051687164 )
    v144 = 3242231556LL;
  else
    v144 = 3242231557LL;
LABEL_94:
  v320 = v143;
  v321 = qcedev_ioctl(v89, v144, v143);
  v322 = 0;
  v323 = 0;
  v561 = v321;
  do
  {
    _W11 = v320[v322];
    v325 = -14;
    if ( (unsigned __int64)(v10 + v322 * 4) < 0x7FFFFFFFFDLL )
    {
      v326 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v328 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v328 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v328);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v326);
      __asm { STTR            W11, [X10] }
      v329 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v331 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v331 - 4096);
      _WriteStatusReg(TTBR1_EL1, v331);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v329);
      v325 = 0;
    }
    _X11 = v320[v322 + 2];
    v333 = -14;
    if ( (unsigned __int64)(v10 + v322 * 4 + 8) < 0x7FFFFFFFF9LL )
    {
      v334 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v336 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v336 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v336);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v334);
      __asm { STTR            X11, [X12] }
      v337 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v339 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v339 - 4096);
      _WriteStatusReg(TTBR1_EL1, v339);
      __isb(0xFu);
      v333 = 0;
      _WriteStatusReg(DAIF, v337);
    }
    v322 += 4;
    v323 |= v325 | v333;
  }
  while ( v322 != 64 );
  _X9 = v320[64];
  v341 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v343 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v343 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v343);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v341);
  __asm { STTR            X9, [X10] }
  v344 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v346 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v346 - 4096);
  _WriteStatusReg(TTBR1_EL1, v346);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v344);
  _X9 = v320[65];
  v348 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v350 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v350 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v350);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v348);
  __asm { STTR            X9, [X11] }
  v351 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v353 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v353 - 4096);
  _WriteStatusReg(TTBR1_EL1, v353);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v351);
  for ( ii = 0; ii != 32; ++ii )
  {
    _W10 = *((unsigned __int8 *)v320 + ii + 264);
    v356 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v358 = *(_QWORD *)(v11 + 8);
    _WriteStatusReg(TTBR1_EL1, v358 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v358);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v356);
    __asm { STTRB           W10, [X11] }
    v359 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v361 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v361 - 4096);
    _WriteStatusReg(TTBR1_EL1, v361);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v359);
  }
  _X9 = v320[74];
  v363 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v365 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v365 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v365);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v363);
  __asm { STTR            X9, [X10] }
  v366 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  _X10 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, _X10 - 4096);
  _WriteStatusReg(TTBR1_EL1, _X10);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v366);
  LODWORD(_X10) = v320[76];
  v369 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v371 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v371 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v371);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v369);
  __asm { STTR            W10, [X11] }
  v372 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v374 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v374 - 4096);
  _WriteStatusReg(TTBR1_EL1, v374);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v372);
  _X11 = v320[78];
  v376 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v378 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v378 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v378);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v376);
  __asm { STTR            X11, [X12] }
  v379 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  _X12 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, _X12 - 4096);
  _WriteStatusReg(TTBR1_EL1, _X12);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v379);
  LODWORD(_X12) = v320[79];
  v382 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v384 = *(_QWORD *)(v11 + 8);
  _WriteStatusReg(TTBR1_EL1, v384 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v384);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v382);
  __asm { STTR            W12, [X13] }
  v385 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v387 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v387 - 4096);
  _WriteStatusReg(TTBR1_EL1, v387);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v385);
  v388 = v323;
  kfree(v320);
  if ( v561 )
    return v561;
  else
    return v388;
}
