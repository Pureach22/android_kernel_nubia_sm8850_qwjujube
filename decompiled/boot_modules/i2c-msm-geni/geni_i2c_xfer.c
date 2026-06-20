__int64 __fastcall geni_i2c_xfer(__int64 a1, unsigned __int16 *a2, unsigned int a3)
{
  __int64 v3; // x24
  __int64 v4; // x20
  _QWORD *v6; // x19
  __int64 v7; // x21
  unsigned __int64 v8; // x23
  unsigned int v9; // w22
  _BYTE *v10; // x25
  unsigned int v11; // w0
  int v12; // w0
  void (*v13)(void); // x8
  __int64 v14; // x0
  char v15; // w0
  __int64 v16; // x0
  __int64 v17; // x20
  unsigned int v18; // w0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x21
  unsigned __int16 *v23; // x9
  int v24; // t1
  __int64 v25; // x0
  char v26; // w8
  __int64 v27; // x20
  __int64 v28; // x0
  unsigned int v29; // w27
  unsigned int v30; // w0
  int v31; // w8
  int v32; // w9
  unsigned __int64 v33; // x21
  __int64 v34; // x0
  unsigned __int16 *v35; // x22
  unsigned __int64 v36; // x25
  const char *v37; // x26
  __int64 v38; // x21
  _BOOL4 v39; // w28
  __int64 v40; // x21
  int v41; // w4
  __int64 v42; // x0
  const char *v43; // x20
  __int64 dma_safe_msg_buf; // x26
  __int64 v45; // x0
  int v46; // w3
  int v47; // w21
  int v48; // w21
  unsigned int v49; // w0
  int v50; // w0
  int v51; // w8
  __int64 v52; // x21
  __int64 v53; // x28
  __int64 v54; // x8
  const char *v55; // x4
  __int64 v56; // x21
  int v57; // w26
  int v58; // w27
  unsigned __int64 v59; // x3
  unsigned __int64 v60; // x4
  unsigned int v61; // w21
  __int64 v62; // x2
  __int64 v63; // x8
  int v64; // w0
  unsigned int gpii_chan_req_tres; // w0
  __int16 *v66; // x9
  __int64 v67; // x8
  __int16 v68; // t1
  __int64 v69; // x0
  __int64 v70; // x1
  __int64 v71; // x2
  __int64 updated; // x0
  unsigned __int64 v73; // x22
  int v74; // w8
  unsigned __int64 v75; // x9
  char *v76; // x11
  __int64 v77; // x0
  __int64 v78; // x21
  unsigned __int64 v79; // x20
  __int64 v80; // x2
  unsigned int v81; // w21
  __int64 v82; // x22
  __int64 v83; // x20
  __int64 v84; // x0
  unsigned __int16 *v85; // x10
  int v86; // w9
  int v87; // w11
  int v88; // w12
  __int64 v89; // x0
  int v90; // w5
  int v91; // w2
  int v92; // w9
  int v93; // w10
  int v94; // w4
  __int64 v95; // x0
  _BYTE *v96; // x21
  __int64 v97; // x22
  int v98; // w12
  int v99; // w8
  unsigned int v100; // w8
  unsigned int v101; // w22
  __int64 v102; // x10
  char v103; // w8
  int v104; // w8
  __int64 v105; // x20
  int v106; // w4
  __int64 v107; // x0
  int v108; // w28
  __int64 v109; // x20
  unsigned int v110; // w21
  __int64 v111; // x0
  __int64 v112; // x8
  size_t v113; // x2
  __int64 v114; // x0
  int v115; // w8
  __int64 v116; // x27
  __int64 v117; // x21
  __int64 v118; // x8
  __int64 v119; // x8
  __int64 v120; // x8
  int v121; // w11
  __int16 v122; // w9
  int v123; // w10
  bool v124; // zf
  int v125; // w8
  int v126; // w9
  int v127; // w10
  int v128; // w2
  int v129; // w8
  unsigned __int16 v130; // w9
  int v131; // w4
  bool v132; // zf
  int v133; // w8
  unsigned int v134; // w9
  __int64 v135; // x0
  __int64 v136; // x28
  __int64 v137; // x8
  unsigned int v138; // w8
  __int64 v139; // x26
  __int64 v140; // x22
  __int64 *v141; // x25
  __int64 v142; // x22
  __int64 v143; // x0
  const char **v144; // x27
  __int64 v145; // x26
  char v146; // w0
  __int64 v147; // x0
  __int64 v148; // x9
  __int64 v149; // x9
  int v150; // w8
  __int64 v151; // x20
  __int64 v152; // x0
  __int64 (__fastcall *v153)(_QWORD); // x8
  unsigned int v154; // w0
  __int64 v155; // x0
  void (__fastcall *v156)(_QWORD); // x8
  __int64 v157; // x8
  __int64 v158; // x0
  __int64 (__fastcall *v159)(_QWORD); // x8
  int v160; // w0
  __int64 v161; // x0
  void (__fastcall *v162)(_QWORD); // x8
  int v163; // w26
  __int64 v164; // x8
  int v165; // w8
  unsigned int v166; // w9
  unsigned int v167; // w10
  int v168; // w8
  unsigned int v169; // w9
  __int64 v170; // x11
  unsigned int v171; // w10
  __int64 v172; // x11
  __int64 v173; // x0
  const char **v174; // x27
  __int64 v175; // x24
  char v176; // w0
  __int64 *v177; // x25
  __int64 v178; // x0
  __int64 v179; // x8
  __int64 v180; // x9
  int v181; // w8
  int v182; // w28
  __int64 v183; // x0
  __int64 v184; // x22
  __int64 v185; // x8
  int v186; // w8
  __int64 v187; // x0
  __int64 v188; // x8
  int v189; // w8
  __int64 v190; // x0
  __int64 v191; // x8
  __int64 v192; // x0
  __int64 v193; // x8
  int v194; // w9
  __int64 v195; // x8
  __int64 v196; // x0
  __int64 v197; // x0
  int v198; // w2
  unsigned int v199; // w20
  __int64 (*v200)(void); // x8
  int v201; // w0
  __int64 (*v202)(void); // x8
  __int64 v203; // x21
  unsigned int v204; // w3
  int v205; // w22
  int v206; // w0
  __int64 v207; // x0
  __int64 v208; // x0
  __int64 v209; // x21
  __int64 v210; // x0
  __int64 (*v211)(void); // x8
  int v212; // w20
  int v213; // w8
  __int16 v214; // w8
  const char *v215; // x4
  __int64 v216; // x20
  int v217; // w22
  int v218; // w21
  unsigned __int64 v219; // x3
  unsigned __int64 v220; // x4
  __int64 v221; // x0
  __int64 v222; // x1
  __int64 v223; // x2
  unsigned int v224; // w20
  __int64 v225; // x0
  __int64 v226; // x1
  __int64 v227; // x2
  unsigned int v228; // w20
  __int64 v229; // x0
  unsigned __int16 *v230; // x8
  unsigned int v231; // w2
  __int64 v232; // x8
  char v233; // w8
  char v234; // w21
  const char *v235; // x0
  const char *v236; // x2
  char v237; // w25
  const char *v238; // x0
  const char *v239; // x2
  __int64 v240; // x0
  int v241; // w8
  __int64 v242; // x20
  __int64 v243; // x0
  __int64 v244; // x20
  __int64 v245; // x0
  int v246; // w3
  __int64 v247; // x0
  __int64 v248; // x20
  __int64 v249; // x0
  int v251; // w2
  unsigned int *v252; // x1
  unsigned int *v253; // x1
  __int64 v254; // x21
  __int64 v255; // x0
  unsigned int v256; // w22
  __int64 v257; // x0
  __int64 v258; // x0
  __int64 v259; // x2
  __int64 v260; // x20
  __int64 v261; // x2
  unsigned int v262; // w21
  __int64 v263; // x2
  unsigned int v264; // w22
  __int64 v265; // x2
  __int64 v266; // x2
  __int64 v267; // x0
  __int64 v268; // x2
  unsigned __int64 v269; // x21
  __int64 v270; // x22
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-160h]
  int v272; // [xsp+Ch] [xbp-154h]
  unsigned __int64 v273; // [xsp+10h] [xbp-150h]
  int v274; // [xsp+1Ch] [xbp-144h]
  unsigned __int64 v275; // [xsp+20h] [xbp-140h]
  __int64 v276; // [xsp+28h] [xbp-138h]
  unsigned __int64 v277; // [xsp+38h] [xbp-128h]
  int v278; // [xsp+44h] [xbp-11Ch]
  __int64 *v279; // [xsp+48h] [xbp-118h]
  int v280; // [xsp+54h] [xbp-10Ch]
  unsigned __int64 v281; // [xsp+58h] [xbp-108h]
  __int64 *v282; // [xsp+60h] [xbp-100h]
  _QWORD *v283; // [xsp+68h] [xbp-F8h]
  int v284; // [xsp+74h] [xbp-ECh]
  unsigned __int64 v285; // [xsp+78h] [xbp-E8h]
  unsigned __int64 v286; // [xsp+90h] [xbp-D0h]
  __int64 v287; // [xsp+A8h] [xbp-B8h]
  __int64 *v288; // [xsp+B0h] [xbp-B0h]
  __int64 *v289; // [xsp+B8h] [xbp-A8h]
  unsigned int v290; // [xsp+C0h] [xbp-A0h]
  __int64 v291; // [xsp+C0h] [xbp-A0h]
  unsigned int v292; // [xsp+CCh] [xbp-94h]
  unsigned __int64 v293; // [xsp+D0h] [xbp-90h]
  unsigned int v294; // [xsp+DCh] [xbp-84h]
  __int64 v295; // [xsp+E0h] [xbp-80h]
  __int64 v296; // [xsp+E8h] [xbp-78h]
  __int64 v297; // [xsp+F8h] [xbp-68h]
  __int64 v298; // [xsp+F8h] [xbp-68h]
  _DWORD *v299; // [xsp+100h] [xbp-60h]
  __int64 v300; // [xsp+100h] [xbp-60h]
  unsigned __int64 v301; // [xsp+108h] [xbp-58h]
  unsigned int v302; // [xsp+108h] [xbp-58h]
  unsigned __int64 v303; // [xsp+108h] [xbp-58h]
  __int64 v304; // [xsp+110h] [xbp-50h]
  int v305; // [xsp+11Ch] [xbp-44h] BYREF
  __int64 v306; // [xsp+120h] [xbp-40h] BYREF
  __int64 v307; // [xsp+128h] [xbp-38h] BYREF
  __int64 v308; // [xsp+130h] [xbp-30h] BYREF
  __int64 v309; // [xsp+138h] [xbp-28h]
  __int64 v310; // [xsp+140h] [xbp-20h]
  __int64 v311; // [xsp+148h] [xbp-18h]
  __int64 v312; // [xsp+150h] [xbp-10h]

  v3 = a3;
  v4 = a1;
  v312 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 264);
  v7 = v6[638];
  if ( v7 )
  {
    if ( *((_DWORD *)v6 + 1278) )
    {
      v8 = ((__int64 (*)(void))sched_clock)();
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_xfer", v8, v8 / 0x3E8);
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    v8 = -22;
  }
  *((_DWORD *)v6 + 6) = 0;
  *((_DWORD *)v6 + 2279) = 1;
  if ( (*(_WORD *)(*v6 + 488LL) & 7) != 0 )
  {
    ipc_log_string(v6[637], "%s: System suspended\n", "geni_i2c_xfer");
    if ( *v6 )
      i2c_trace_log();
    *((_DWORD *)v6 + 2279) = 0;
    v9 = -13;
    goto LABEL_512;
  }
  v10 = v6 + 1024;
  if ( (v6[1138] & 1) == 0 && (*((_BYTE *)v6 + 9106) & 1) == 0 )
  {
    v11 = _pm_runtime_resume();
    if ( (v11 & 0x80000000) != 0 )
    {
      v9 = v11;
      ipc_log_string(v6[637], "error turning SE resources:%d\n", v11);
      if ( *v6 )
        dev_err(*v6, "error turning SE resources:%d\n", v9);
      else
        printk(&unk_102BF, v9, v80);
      if ( *v6 )
        i2c_trace_log();
      pm_runtime_put_noidle();
      _pm_runtime_set_status(*v6, 2);
      *((_DWORD *)v6 + 2279) = 0;
      goto LABEL_512;
    }
  }
  if ( *((_BYTE *)v6 + 9111) == 1 && *((_BYTE *)v6 + 9113) == 1 )
  {
    v12 = readl_relaxed((unsigned int *)(v6[1] + 2312LL));
    if ( (~v12 & 3) != 0 )
    {
      v81 = v12;
      ipc_log_string(v6[637], "%s: IOS:0x%x, bad state\n", "do_pending_cancel", v12);
      if ( *v6 )
        dev_err(*v6, "%s: IOS:0x%x, bad state\n", "do_pending_cancel", v81);
      else
        printk(&unk_F7C4, "do_pending_cancel", v81);
      writel_relaxed(1u, (unsigned int *)(v6[1] + 32LL));
      v256 = readl_relaxed((unsigned int *)(v6[1] + 2312LL));
      v257 = v6[637];
      if ( (~v256 & 3) != 0 )
      {
        ipc_log_string(v257, "%s: IOS:0x%x, Fix from Slave side\n", "do_pending_cancel", v256);
        if ( *v6 )
          v258 = dev_err(*v6, "%s: IOS:0x%x, Fix from Slave side\n", "do_pending_cancel", v256);
        else
          v258 = printk(&unk_10143, "do_pending_cancel", v256);
        if ( (v6[1138] & 1) == 0 && (*((_BYTE *)v6 + 9106) & 1) == 0 )
        {
          v260 = *v6;
          *(_QWORD *)(v260 + 520) = ktime_get_mono_fast_ns(v258);
          _pm_runtime_suspend(*v6, 13);
        }
        *((_DWORD *)v6 + 2279) = 0;
        v9 = -22;
        goto LABEL_512;
      }
      ipc_log_string(v257, "%s: IOS:0x%x restored properly\n", "do_pending_cancel", v256);
      if ( *v6 )
        dev_err(*v6, "%s: IOS:0x%x restored properly\n", "do_pending_cancel", v256);
      else
        printk(&unk_F7DF, "do_pending_cancel", v256);
    }
    if ( *((_DWORD *)v6 + 2270) == 2 )
    {
      v13 = *(void (**)(void))(*(_QWORD *)v6[640] + 336LL);
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -403578064 )
          __break(0x8228u);
        v13();
      }
      *((_DWORD *)v6 + 2238) = 0;
    }
    else if ( (unsigned int)geni_i2c_stop_with_cancel((__int64)v6) )
    {
      ipc_log_string(v6[637], "%s: geni_i2c_stop_with_cancel failed\n", "do_pending_cancel");
      if ( *v6 )
        i2c_trace_log();
    }
    v14 = v6[637];
    *((_BYTE *)v6 + 9111) = 0;
    ipc_log_string(v14, "%s: Pending Cancel done\n", "do_pending_cancel");
    if ( *v6 )
      i2c_trace_log();
  }
  v15 = readl_relaxed((unsigned int *)(v6[1] + 2312LL));
  if ( (*((_BYTE *)v6 + 9085) & 1) == 0 && (v15 & 3) != 3 )
  {
    ipc_log_string(v6[637], "IO lines in bad state, Power the slave\n");
    v16 = *v6;
    if ( *v6 )
      i2c_trace_log();
    if ( (v6[1138] & 1) == 0 && (*((_BYTE *)v6 + 9106) & 1) == 0 )
    {
      v17 = *v6;
      *(_QWORD *)(v17 + 520) = ktime_get_mono_fast_ns(v16);
      _pm_runtime_suspend(*v6, 13);
    }
    *((_DWORD *)v6 + 2279) = 0;
    v9 = -6;
    goto LABEL_512;
  }
  if ( *((_BYTE *)v6 + 9104) != 1 || (*((_BYTE *)v6 + 9108) & 1) != 0 )
    goto LABEL_41;
  *((_BYTE *)v6 + 9108) = 1;
  v18 = geni_i2c_prepare(v6);
  if ( v18 )
  {
    v9 = v18;
    ipc_log_string(v6[637], "%s I2C prepare failed: %d\n", "geni_i2c_xfer", v18);
    if ( *v6 )
      dev_err(*v6, "%s I2C prepare failed: %d\n", "geni_i2c_xfer", v9);
    else
      printk(&unk_F85E, "geni_i2c_xfer", v9);
    if ( !*v6 )
      goto LABEL_567;
LABEL_566:
    i2c_trace_log();
LABEL_567:
    *((_DWORD *)v6 + 2279) = 0;
    goto LABEL_512;
  }
  v9 = geni_i2c_lock_bus(v6);
  v19 = v6[637];
  if ( v9 )
  {
    ipc_log_string(v19, "%s lock failed: %d\n", "geni_i2c_xfer", v9);
    if ( *v6 )
      dev_err(*v6, "%s lock failed: %d\n", "geni_i2c_xfer", v9);
    else
      printk(&unk_10C4C, "geni_i2c_xfer", v9);
    if ( !*v6 )
      goto LABEL_567;
    goto LABEL_566;
  }
  ipc_log_string(v19, "LE-VM first xfer\n");
  if ( *v6 )
    i2c_trace_log();
LABEL_41:
  ipc_log_string(v6[637], "n:%d addr:0x%x\n", v3, *a2);
  if ( *v6 )
    i2c_trace_log();
  v20 = v6[1137];
  *((_DWORD *)v6 + 2272) = v3;
  kfree(v20);
  v296 = v3;
  v304 = (__int64)a2;
  if ( (v3 & 0x80000000) != 0 )
  {
    v6[1137] = 0;
  }
  else
  {
    v21 = _kmalloc_noprof(16LL * (unsigned int)v3, 3520);
    v6[1137] = v21;
    if ( v21 )
      goto LABEL_47;
  }
LABEL_45:
  ipc_log_string(v6[637], "Buf logging pointer not available\n");
  v21 = *v6;
  if ( *v6 )
    i2c_trace_log();
  while ( 1 )
  {
LABEL_47:
    if ( *((_DWORD *)v6 + 2270) != 2 )
    {
      v286 = v8;
      v10[893] = 0;
      v34 = sched_clock(v21);
      v295 = v34;
      v301 = (unsigned int)(v3 - 1);
      if ( (int)v3 < 1 )
      {
LABEL_184:
        v29 = *((_DWORD *)v6 + 6);
LABEL_185:
        v82 = v295;
LABEL_186:
        v83 = v6[637];
        v84 = sched_clock(v34);
        v28 = ipc_log_string(v83, "%s Time took for %d xfers = %llu nsecs\n", "geni_i2c_execute_xfer", v3, v84 - v82);
        if ( *v6 )
        {
          sched_clock(v28);
          i2c_trace_log();
        }
LABEL_188:
        v10 = v6 + 1024;
        goto LABEL_500;
      }
      v35 = (unsigned __int16 *)v304;
      v36 = 0;
      v37 = "%s: us:%lu jiffies:%d\n";
      v4 = (__int64)"qcom_geni_i2c_calc_timeout";
      v297 = (unsigned int)v3;
      v299 = v6 + 159;
      while ( 1 )
      {
        v38 = v6[638];
        v306 = 0;
        v307 = 0;
        if ( v38 )
        {
          if ( *((_DWORD *)v6 + 1278) )
          {
            v8 = sched_clock(v34);
            ipc_log_string(v38, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_execute_xfer", v8, v8 / 0x3E8);
          }
          else
          {
            v8 = 0;
          }
        }
        else
        {
          v8 = -22;
        }
        *((_DWORD *)v6 + 318) = 0;
        LODWORD(v3) = *v35;
        v6[167] = v35;
        v39 = v36 < v301;
        if ( !v35 )
        {
          ipc_log_string(v6[637], "%s: Invalid buffer\n", "geni_i2c_execute_xfer");
          v34 = *v6;
          LODWORD(v3) = v296;
          if ( *v6 )
            i2c_trace_log();
          v29 = -12;
          goto LABEL_185;
        }
        if ( *((_DWORD *)v6 + 1279) >= 4u )
          goto LABEL_618;
        v40 = 90 * v35[2] * (__int64)(1000000 / *((_DWORD *)v6 + 2239)) + 500000;
        v41 = _usecs_to_jiffies((unsigned int)v40);
        v42 = v6[637];
        *((_DWORD *)v6 + 7) = v41;
        ipc_log_string(v42, v37, "qcom_geni_i2c_calc_timeout", v40);
        if ( *v6 )
          i2c_trace_log();
        v43 = v37;
        if ( (*((_BYTE *)v6 + 9110) & 1) != 0 || v35[2] <= 0x20u )
        {
          v305 = 1;
          geni_se_select_mode(v6 + 620, 1);
          dma_safe_msg_buf = 0;
        }
        else
        {
          v305 = 2;
          geni_se_select_mode(v6 + 620, 2);
          dma_safe_msg_buf = i2c_get_dma_safe_msg_buf(v35, 1);
          if ( !dma_safe_msg_buf )
          {
            geni_i2c_stop_on_bus((__int64)v6);
            LODWORD(v3) = v296;
            v29 = -12;
            goto LABEL_185;
          }
        }
        ipc_log_string(
          v6[637],
          "%s: stretch:%d, m_param:0x%x\n",
          "geni_i2c_execute_xfer",
          v36 < v301,
          ((v3 & 0x7F) << 9) | (4 * v39));
        if ( *v6 )
          i2c_trace_log();
        geni_i2c_fifo_dma_rw(
          (__int64)v6,
          v304,
          v36,
          &v305,
          (__int64)&v306,
          (__int64)&v307,
          dma_safe_msg_buf,
          ((v3 & 0x7F) << 9) | (4 * v39));
        if ( (unsigned int)wait_for_completion_timeout(v299, *((unsigned int *)v6 + 7)) )
        {
          v45 = v6[637];
          v46 = v35[2];
          LODWORD(v3) = v296;
          if ( (v35[1] & 1) != 0 )
          {
            ipc_log_string(v45, "%s: Read operation completed for len:%d\n", "geni_i2c_execute_xfer", v46);
            if ( !*v6 )
              goto LABEL_92;
          }
          else
          {
            ipc_log_string(v45, "%s:Write operation completed for len:%d\n", "geni_i2c_execute_xfer", v46);
            if ( !*v6 )
              goto LABEL_92;
          }
          i2c_trace_log();
        }
        else
        {
          v61 = readl_relaxed((unsigned int *)(v6[1] + 1552LL));
          writel_relaxed(0, (unsigned int *)(v6[1] + 2060LL));
          LODWORD(v3) = v296;
          if ( v61 )
            writel_relaxed(v61, (unsigned int *)(v6[1] + 1560LL));
          ipc_log_string(v6[637], "I2C xfer timeout: %d\n", *((_DWORD *)v6 + 7));
          v62 = *((unsigned int *)v6 + 7);
          if ( *v6 )
            dev_err(*v6, "I2C xfer timeout: %d\n", v62);
          else
            printk(&unk_10EE6, (unsigned int)v62, v62);
          if ( *v6 )
            i2c_trace_log();
          ipc_log_string(v6[637], "%s\n", "I2C TXN timed out");
          if ( *v6 )
            i2c_trace_log();
          geni_i2c_se_dump_dbg_regs((__int64)(v6 + 620), v6[1], v6[637]);
          v63 = v6[1];
          *((_DWORD *)v6 + 6) = -110;
          v64 = readl_relaxed((unsigned int *)(v63 + 2312));
          if ( (~v64 & 3) != 0 )
          {
            ipc_log_string(v6[637], "%s: IO lines not good: 0x%x\n", "geni_i2c_execute_xfer", v64);
            v34 = *v6;
            if ( *v6 )
              i2c_trace_log();
            if ( (*((_BYTE *)v6 + 9113) & 1) != 0 )
              goto LABEL_183;
          }
        }
LABEL_92:
        if ( *((_DWORD *)v6 + 6) )
        {
          if ( *((_BYTE *)v6 + 9113) == 1 )
          {
            if ( (~(unsigned int)readl_relaxed((unsigned int *)(v6[1] + 2312LL)) & 3) != 0 )
            {
              ipc_log_string(v6[637], "%s: IO lines not in good state\n", "geni_i2c_execute_xfer");
              v34 = *v6;
              if ( *v6 )
                i2c_trace_log();
LABEL_183:
              *((_BYTE *)v6 + 9111) = 1;
              goto LABEL_184;
            }
            if ( *((_DWORD *)v6 + 6) == -16 )
            {
              ipc_log_string(v6[637], "%s:run reg68 war\n", "geni_i2c_execute_xfer");
              if ( *v6 )
                i2c_trace_log();
              v47 = readl_relaxed((unsigned int *)(v6[1] + 1536LL));
              ipc_log_string(v6[637], "%s: SE_GENI_M_CMD0:0x%x\n", "do_reg68_war_for_rtl_se", v47);
              if ( (v47 & 4) != 0 && *((_BYTE *)v6 + 9113) == 1 )
              {
                v48 = readl_relaxed((unsigned int *)(v6[1] + 528LL));
                ipc_log_string(v6[637], "%s: Before WAR REG68:0x%x\n", "do_reg68_war_for_rtl_se", v48);
                if ( (v48 & 0x20) != 0 )
                  v49 = 1048848;
                else
                  v49 = 1048864;
                writel_relaxed(v49, (unsigned int *)(v6[1] + 528LL));
                v50 = readl_relaxed((unsigned int *)(v6[1] + 528LL));
                ipc_log_string(v6[637], "%s: After WAR REG68:0x%x\n", "do_reg68_war_for_rtl_se", v50);
              }
            }
          }
          geni_i2c_stop_with_cancel((__int64)v6);
          v29 = *((_DWORD *)v6 + 6);
        }
        else
        {
          v29 = 0;
        }
        v51 = v305;
        v6[635] = 0;
        if ( v51 == 2 )
        {
          v52 = v306;
          v53 = v307;
          if ( v29 )
          {
            *((_DWORD *)v6 + 318) = 0;
            v54 = 3160;
            if ( v35[1] == 1 )
              v54 = 3416;
            writel_relaxed(1u, (unsigned int *)(v6[1] + v54));
            if ( !(unsigned int)wait_for_completion_timeout(v299, 250) )
            {
              ipc_log_string(v6[637], "%s: FSM Reset failed\n", "gi2c_se_dma_clear_process");
              if ( *v6 )
                i2c_trace_log();
            }
          }
          if ( v52 )
            geni_se_rx_dma_unprep(v6 + 620, v52, v35[2]);
          if ( v53 )
            geni_se_tx_dma_unprep(v6 + 620, v53, v35[2]);
          i2c_put_dma_safe_msg_buf(dma_safe_msg_buf, v35, *((_DWORD *)v6 + 6) == 0);
          v29 = *((_DWORD *)v6 + 6);
        }
        if ( v29 )
        {
          ipc_log_string(v6[637], "i2c error :%d\n", v29);
          v77 = *v6;
          if ( *v6 )
            i2c_trace_log();
          v78 = v6[638];
          if ( v78 )
          {
            if ( *((_DWORD *)v6 + 1278) )
            {
              v79 = sched_clock(v77);
              ipc_log_string(v78, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_bus_recovery", v79, v79 / 0x3E8);
            }
            else
            {
              v79 = 0;
            }
          }
          else
          {
            v79 = -22;
          }
          if ( *((_BYTE *)v6 + 9120) != 1
            || (readl_relaxed((unsigned int *)(v6[1] + 2312LL)) & 1) != 0
            || (v251 = *((_DWORD *)v6 + 6), v251 != -110) && v251 != -16 && v251 != -71 )
          {
            v34 = ipc_log_string(v6[637], "Bus Recovery not required/enabled\n");
            goto LABEL_185;
          }
          ipc_log_string(v6[637], "%d:SDA Line stuck\n", v251);
          ipc_log_string(v6[637], "%s: start recovery\n", "geni_i2c_bus_recovery");
          v82 = v295;
          if ( *v6 )
            i2c_trace_log();
          v252 = (unsigned int *)(v6[620] + 1536LL);
          *v299 = 0;
          writel(0x30000000u, v252);
          if ( (unsigned int)wait_for_completion_timeout(v299, 250) )
            goto LABEL_525;
          ipc_log_string(v6[637], "%s\n", "I2C TXN timed out");
          if ( *v6 )
            i2c_trace_log();
          geni_i2c_se_dump_dbg_regs((__int64)(v6 + 620), v6[1], v6[637]);
          v6[167] = 0;
          *((_DWORD *)v6 + 6) = -110;
          if ( (unsigned int)geni_i2c_stop_with_cancel((__int64)v6) )
          {
            ipc_log_string(v6[637], "%s: Bus clear Failed\n", "geni_i2c_bus_recovery");
            if ( *v6 )
              goto LABEL_609;
          }
          else
          {
LABEL_525:
            ipc_log_string(v6[637], "%s: BUS_CLEAR success\n", "geni_i2c_bus_recovery");
            if ( *v6 )
              i2c_trace_log();
            v253 = (unsigned int *)(v6[620] + 1536LL);
            *v299 = 0;
            writel(0x38000000u, v253);
            if ( (unsigned int)wait_for_completion_timeout(v299, 250) )
              goto LABEL_531;
            ipc_log_string(v6[637], "%s\n", "I2C TXN timed out");
            if ( *v6 )
              i2c_trace_log();
            geni_i2c_se_dump_dbg_regs((__int64)(v6 + 620), v6[1], v6[637]);
            v6[167] = 0;
            *((_DWORD *)v6 + 6) = -110;
            if ( !(unsigned int)geni_i2c_stop_with_cancel((__int64)v6) )
            {
LABEL_531:
              ipc_log_string(v6[637], "%s: success\n", "geni_i2c_bus_recovery");
              v34 = *v6;
              if ( *v6 )
                i2c_trace_log();
              v254 = v6[638];
              if ( v254 && v79 && *((_DWORD *)v6 + 1278) )
              {
                v255 = sched_clock(v34);
                v34 = ipc_log_string(
                        v254,
                        "%s:took %llu nsec(%llu usec)\n",
                        "geni_i2c_bus_recovery",
                        v255 - v79,
                        (v255 - v79) / 0x3E8);
              }
              goto LABEL_186;
            }
            ipc_log_string(v6[637], "%s:Bus Stop Failed\n", "geni_i2c_bus_recovery");
            if ( *v6 )
LABEL_609:
              i2c_trace_log();
          }
          ipc_log_string(v6[637], "%s:Bus Recovery failed\n", "geni_i2c_execute_xfer");
          if ( *v6 )
            v34 = dev_err(*v6, "%s:Bus Recovery failed\n", "geni_i2c_execute_xfer");
          else
            v34 = printk(&unk_1065A, "geni_i2c_execute_xfer", v266);
          goto LABEL_186;
        }
        v37 = v43;
        if ( (v35[1] & 1) != 0 )
          v55 = "_rd";
        else
          v55 = "_wr";
        v310 = 0;
        v311 = 0;
        v308 = 0;
        v309 = 0;
        v34 = scnprintf(&v308, 32, "%s%s", "geni_i2c_execute_xfer", v55);
        v56 = v6[638];
        if ( v56 && v8 && *((_DWORD *)v6 + 1278) )
        {
          v57 = v35[2];
          v58 = *((_DWORD *)v6 + 2239);
          v59 = sched_clock(v34) - v8;
          v60 = v59 / 0x3E8;
          if ( v57 )
          {
            if ( v58 )
              v34 = ipc_log_string(
                      v56,
                      "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                      (const char *)&v308,
                      v59,
                      v60,
                      v57,
                      v58);
            else
              v34 = ipc_log_string(
                      v56,
                      "%s:took %llu nsec(%llu usec) for %u bytes\n",
                      (const char *)&v308,
                      v59,
                      v60,
                      v57);
          }
          else
          {
            v34 = ipc_log_string(v56, "%s:took %llu nsec(%llu usec)\n", (const char *)&v308, v59, v60);
          }
          v37 = v43;
        }
        ++v36;
        v35 += 8;
        v4 = (__int64)"qcom_geni_i2c_calc_timeout";
        if ( v297 == v36 )
          goto LABEL_184;
      }
    }
    if ( (_DWORD)v3 )
      break;
LABEL_52:
    v286 = v8;
    v8 = *(_QWORD *)(v4 + 264);
    v25 = sched_clock(v21);
    v26 = *(_BYTE *)(v8 + 9107);
    v27 = v25;
    *(_BYTE *)(v8 + 9112) = 0;
    if ( (v26 & 1) == 0 )
    {
      v28 = geni_i2c_gsi_request_channel(v8);
      v29 = v28;
      if ( (_DWORD)v28 )
        goto LABEL_500;
    }
    if ( *(_BYTE *)(v8 + 9104) == 1 && *(_BYTE *)(v8 + 9109) == 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v8 + 5096),
        "%s doing gsi lock, due to levm gsi reset\n",
        "geni_i2c_gsi_channel_init_and_lock");
      if ( *(_QWORD *)v8 )
        i2c_trace_log();
      v30 = geni_i2c_lock_bus(v8);
      if ( v30 )
      {
        v29 = v30;
        ipc_log_string(*(_QWORD *)(v8 + 5096), "%s lock bus failed: %d\n", "geni_i2c_gsi_channel_init_and_lock", v30);
        if ( *(_QWORD *)v8 )
          dev_err(*(_QWORD *)v8, "%s lock bus failed: %d\n", "geni_i2c_gsi_channel_init_and_lock", v29);
        else
          printk(&unk_FA69, "geni_i2c_gsi_channel_init_and_lock", v29);
        v28 = *(_QWORD *)v8;
        if ( *(_QWORD *)v8 )
          i2c_trace_log();
        goto LABEL_500;
      }
      *(_BYTE *)(v8 + 9109) = 0;
    }
    v276 = v27;
    if ( *(_BYTE *)(v8 + 9085) == 1 )
    {
      v31 = *(unsigned __int8 *)(v8 + 1360);
      *(_QWORD *)(v8 + 5136) = 0;
      *(_DWORD *)(v8 + 5144) = 0;
      if ( v31 )
        v32 = 3146753;
      else
        v32 = 3145729;
      v33 = v8 + 5136;
      *(_DWORD *)(v8 + 5148) = v32;
      v4 = v8 + 5152;
      *(_QWORD *)(v8 + 5152) = 0;
      *(_QWORD *)(v8 + 5160) = 0x31010000000000LL;
    }
    else
    {
      v33 = 0;
      v4 = 0;
    }
    gpii_chan_req_tres = get_gpii_chan_req_tres(*(_QWORD *)(v8 + 5120));
    if ( gpii_chan_req_tres )
    {
      if ( (int)v3 >= 4 && (*(_BYTE *)(v8 + 9122) & 1) == 0 )
      {
        v66 = (__int16 *)(v304 + 2);
        *(_BYTE *)(v8 + 1360) = 1;
        v67 = (unsigned int)v3;
        while ( 1 )
        {
          v68 = *v66;
          v66 += 8;
          if ( (v68 & 1) != 0 )
            break;
          if ( !--v67 )
          {
            if ( gpii_chan_req_tres <= 0x40 )
            {
              v69 = *(_QWORD *)(v8 + 5096);
              *(_BYTE *)(v8 + 1360) = 0;
              ipc_log_string(v69, "TRE size too small. Use >= 2x DEFAULT_TRE_SIZE\n");
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "TRE size too small. Use >= 2x DEFAULT_TRE_SIZE\n");
              else
                printk(&unk_F28E, v70, v71);
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
            }
            goto LABEL_157;
          }
        }
      }
      *(_BYTE *)(v8 + 1360) = 0;
LABEL_157:
      updated = gpi_update_multi_desc_flag(*(_QWORD *)(v8 + 5120), *(unsigned __int8 *)(v8 + 1360), (unsigned int)v3);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v8 + 5096), "%s TRE size is zero, check!\n", "geni_i2c_check_for_gsi_multi_desc_mode");
      if ( *(_QWORD *)v8 )
        dev_err(*(_QWORD *)v8, "%s TRE size is zero, check!\n", "geni_i2c_check_for_gsi_multi_desc_mode");
      else
        printk(&unk_FA83, "geni_i2c_check_for_gsi_multi_desc_mode", v259);
      updated = *(_QWORD *)v8;
      if ( *(_QWORD *)v8 )
        i2c_trace_log();
    }
    if ( *(_DWORD *)(v8 + 8952) )
    {
      v73 = 0;
      goto LABEL_197;
    }
    LODWORD(v3) = 3400000;
    v74 = *(unsigned __int8 *)(v8 + 1360);
    if ( *(_BYTE *)(v8 + 9113) == 1 )
    {
      v75 = *(unsigned int *)(v8 + 5116);
      if ( (unsigned int)v75 >= 4 )
        goto LABEL_618;
      v76 = (char *)&geni_i2c_hub_clk_map;
    }
    else
    {
      v75 = *(unsigned int *)(v8 + 5116);
      if ( *(_DWORD *)(v8 + 8956) == 3400000 )
      {
        if ( (unsigned int)v75 > 3 )
          goto LABEL_618;
        v76 = (char *)&geni_i2c_hs_clk_map;
      }
      else
      {
        if ( (unsigned int)v75 > 3 )
        {
LABEL_618:
          __break(0x5512u);
LABEL_619:
          _fortify_panic(17);
          goto LABEL_620;
        }
        v76 = (char *)&geni_i2c_clk_map;
      }
    }
    v85 = (unsigned __int16 *)&v76[12 * (unsigned int)v75];
    if ( v75 <= 2 )
    {
      v86 = v85[5];
      v87 = v85[3];
      v88 = v85[4];
      *(_DWORD *)(v8 + 5172) = 0;
      v89 = *(_QWORD *)(v8 + 5096);
      v90 = (v74 << 10) + 2228225;
      v91 = (v86 << 16) | (v87 << 8) | v88 | 0x3000000;
      v92 = *(_DWORD *)(v8 + 8960);
      *(_DWORD *)(v8 + 5168) = v91;
      v93 = v85[2];
      *(_DWORD *)(v8 + 5180) = v90;
      v94 = v93 | (v92 << 16);
      v73 = v8 + 5168;
      *(_DWORD *)(v8 + 5176) = v94;
      ipc_log_string(v89, "cfg_tre 0x%x 0x%x 0x%x 0x%x\n", v91, 0, v94, v90);
      updated = *(_QWORD *)v8;
      if ( *(_QWORD *)v8 )
        i2c_trace_log();
      if ( *(_DWORD *)(v8 + 8956) == 3400000 )
      {
        v95 = *(_QWORD *)(v8 + 5096);
        *(_DWORD *)(v8 + 5192) = 0;
        v3 = v8 + 5184;
        *(_QWORD *)(v8 + 5184) = 28710;
        *(_DWORD *)(v8 + 5196) = 2293761;
        ipc_log_string(v95, "cfg1_tre 0x%x 0x%x 0x%x 0x%x\n", 28710, 0, 0, 2293761);
        updated = *(_QWORD *)v8;
        if ( *(_QWORD *)v8 )
          i2c_trace_log();
      }
      else
      {
LABEL_197:
        v3 = 0;
      }
      *(_QWORD *)(v8 + 1344) = v304;
      *(_QWORD *)(v8 + 1352) = 0;
      *(_DWORD *)(v8 + 1368) = 0;
      *(_DWORD *)(v8 + 1364) = 0;
      *(_DWORD *)(v8 + 1272) = 0;
      if ( (_DWORD)v296 )
      {
        updated = 0x8000000000LL;
        v287 = 0;
        v288 = (__int64 *)(v8 + 9176);
        v283 = (_QWORD *)(v8 + 9136);
        v282 = (__int64 *)(v8 + 9152);
        v273 = ((unsigned __int64)(((__int64)(v33 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v272 = v33 & 0xFFF;
        v96 = (_BYTE *)(v8 + 0x2000);
        v281 = ((unsigned __int64)(((__int64)(v73 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v275 = ((unsigned __int64)((v3 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v280 = v73 & 0xFFF;
        v97 = 0;
        v98 = v3 & 0xFFF;
        v289 = (__int64 *)(v8 + 8864);
        LODWORD(v3) = v296;
        v290 = 0;
        v292 = 0;
        v274 = v98;
        v285 = ((unsigned __int64)((v4 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v284 = v4 & 0xFFF;
        if ( (_DWORD)v296 == 1 )
          v99 = 2;
        else
          v99 = 1;
        v278 = v99;
        v100 = (unsigned int)v296 >> 6;
        if ( (v296 & 0x3F) != 0 )
          ++v100;
        v294 = v100;
        v277 = v8 + 1376;
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v4 = *(_QWORD *)(v8 + 5104);
          if ( v4 )
          {
            if ( *(_DWORD *)(v8 + 5112) )
            {
              v293 = sched_clock(updated);
              ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_gsi_xfer", v293, v293 / 0x3E8);
            }
            else
            {
              v293 = 0;
            }
          }
          else
          {
            v293 = -22;
          }
          v102 = v304 + 16LL * (unsigned int)v97;
          v103 = *(_WORD *)(v102 + 2);
          *(_DWORD *)(v8 + 9192) = 0;
          *v288 = 0;
          *(_QWORD *)(v8 + 9184) = 0;
          *(_QWORD *)(v8 + 1336) = v102;
          if ( (v103 & 1) != 0 )
            v104 = 1;
          else
            v104 = 2;
          v302 = v104;
          if ( !v102 )
          {
            ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: Invalid buffer\n", "geni_i2c_gsi_xfer");
            updated = *(_QWORD *)v8;
            if ( *(_QWORD *)v8 )
              i2c_trace_log();
            v241 = -12;
            goto LABEL_493;
          }
          if ( *(_DWORD *)(v8 + 5116) >= 4u )
            goto LABEL_618;
          v300 = v304 + 16LL * (unsigned int)v97;
          v105 = 90 * *(unsigned __int16 *)(v102 + 4) * (__int64)(1000000 / *(_DWORD *)(v8 + 8956)) + 500000;
          v106 = _usecs_to_jiffies((unsigned int)v105);
          v107 = *(_QWORD *)(v8 + 5096);
          *(_DWORD *)(v8 + 28) = v106;
          ipc_log_string(v107, "%s: us:%lu jiffies:%d\n", "qcom_geni_i2c_calc_timeout", v105, v106);
          if ( *(_QWORD *)v8 )
            i2c_trace_log();
          v298 = v97;
          if ( v96[930] != 1 )
          {
            v108 = v296 - 1;
LABEL_229:
            if ( *(_DWORD *)(v8 + 8952) )
              goto LABEL_234;
            goto LABEL_230;
          }
          v108 = v296 - 1;
          if ( (*(_WORD *)(v300 + 2) & 1) != 0 )
            goto LABEL_229;
          *(_DWORD *)(v8 + 9144) = 0;
          *v283 = 0;
          *v282 = 0;
          *(_QWORD *)(v8 + 9160) = 0;
          *(_QWORD *)(v8 + 9168) = 0;
          *(_DWORD *)(v8 + 9124) = *(unsigned __int16 *)(v300 + 4);
          v109 = *(_QWORD *)(v300 + 8);
          *(_QWORD *)(v8 + 9128) = v109;
          v110 = *(unsigned __int16 *)(v300 + 4);
          if ( v110 >= 0x10 && (v109 & 0xF) != 0 )
            break;
          ipc_log_string(*(_QWORD *)(v8 + 5096), "using client buffer\n");
          if ( *(_QWORD *)v8 )
            i2c_trace_log();
          if ( v110 > 0xF )
            goto LABEL_304;
          v166 = v110 - 8;
          if ( v110 >= 8 )
            v167 = 8;
          else
            v167 = v110;
          *v282 = v109;
          v168 = 1;
          *(_DWORD *)v283 = v167;
          if ( v110 < 9 )
            goto LABEL_386;
          v96 = (_BYTE *)(v8 + 0x2000);
          if ( v166 )
          {
            *(_DWORD *)(v8 + 9140) = v166;
            *(_QWORD *)(v8 + 9160) = v109 + v167;
            v168 = 2;
          }
LABEL_387:
          *(_DWORD *)(v8 + 9192) = v168;
          v302 = v302 + v168 - 1;
          if ( *(_DWORD *)(v8 + 8952) )
            goto LABEL_234;
LABEL_230:
          if ( *(_DWORD *)(v8 + 8956) == 3400000 )
            v115 = 2;
          else
            v115 = 1;
          v302 += v115;
LABEL_234:
          v116 = v304;
          if ( v96[893] == 1 && (!(_DWORD)v97 || v108 == (_DWORD)v97) )
          {
            v302 += v278;
            sg_init_table(*(_QWORD *)(v8 + 8920), v302);
            if ( !(_DWORD)v97 )
            {
              v164 = *(_QWORD *)(v8 + 8920);
              v117 = 1;
              *(_QWORD *)v164 = *(_QWORD *)v164 & 3LL | v273;
              *(_DWORD *)(v164 + 8) = v272;
              *(_DWORD *)(v164 + 12) = 16;
              goto LABEL_239;
            }
          }
          else
          {
            sg_init_table(*(_QWORD *)(v8 + 8920), v302);
          }
          v117 = 0;
LABEL_239:
          if ( !*(_DWORD *)(v8 + 8952) )
          {
            v118 = *(_QWORD *)(v8 + 8920) + 32 * v117;
            *(_QWORD *)v118 = *(_QWORD *)v118 & 3LL | v281;
            *(_DWORD *)(v118 + 8) = v280;
            *(_DWORD *)(v118 + 12) = 16;
            v119 = v117 + 1;
            if ( *(_DWORD *)(v8 + 8956) == 3400000 )
            {
              v120 = *(_QWORD *)(v8 + 8920) + 32 * v119;
              *(_QWORD *)v120 = *(_QWORD *)v120 & 3LL | v275;
              *(_DWORD *)(v120 + 8) = v274;
              *(_DWORD *)(v120 + 12) = 16;
              v119 = v117 | 2;
            }
            v117 = v119;
            *(_DWORD *)(v8 + 8952) = 1;
          }
          v4 = v304 + 16LL * (int)v97;
          v121 = *(_DWORD *)(v8 + 8956);
          v122 = *(_WORD *)(v4 + 2);
          v123 = *(unsigned __int16 *)v4;
          *(_DWORD *)(v8 + 5204) = 0;
          v124 = (v122 & 1) == 0;
          v125 = ((v108 > (int)v97) << 26) | (v123 << 8);
          if ( (v122 & 1) != 0 )
            v126 = 2;
          else
            v126 = 1;
          if ( v124 )
            v127 = 10;
          else
            v127 = 11;
          if ( v121 == 3400000 )
            v126 = v127;
          v128 = v125 | v126;
          v129 = *(unsigned __int8 *)(v8 + 1360);
          *(_DWORD *)(v8 + 5200) = v128;
          if ( (*(_BYTE *)(v4 + 2) & 1) != 0 )
          {
            v131 = *(unsigned __int16 *)(v4 + 4);
            v132 = ((v108 == (_DWORD)v97) & *(_BYTE *)(v8 + 9085)) == 0;
            v130 = 2047;
            v133 = -194305;
          }
          else
          {
            v130 = 1024;
            v131 = 0;
            v132 = v129 == 0;
            v133 = -196608;
          }
          v134 = v130 | 0xFFFD0000;
          if ( !v132 )
            v133 = v134;
          v135 = *(_QWORD *)(v8 + 5096);
          *(_DWORD *)(v8 + 5208) = v131;
          *(_DWORD *)(v8 + 5212) = v133 + 2293761;
          ipc_log_string(v135, "go_tre 0x%x 0x%x 0x%x 0x%x\n");
          if ( *(_QWORD *)v8 )
            i2c_trace_log();
          v136 = v117 + 1;
          v137 = *(_QWORD *)(v8 + 8920) + 32 * v117;
          *(_QWORD *)v137 = *(_QWORD *)v137 & 3LL
                          | (((unsigned __int64)(((__int64)((v8 + 5200) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                           - 0x140000000LL);
          *(_DWORD *)(v137 + 8) = (v8 + 5200) & 0xFFF;
          *(_DWORD *)(v137 + 12) = 16;
          if ( (*(_WORD *)(v300 + 2) & 1) != 0 )
          {
            *(_DWORD *)(v8 + 1272) = 0;
            v142 = i2c_get_dma_safe_msg_buf(v304 + 16LL * (int)v97, 1);
            v143 = *(_QWORD *)(v8 + 5096);
            if ( !v142 )
            {
              ipc_log_string(v143, "i2c_get_dma_safe_msg_buf failed :%d\n", -12);
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "i2c_get_dma_safe_msg_buf failed :%d\n", -12);
              else
                printk(&unk_FDEE, 4294967284LL, v261);
              if ( *(_QWORD *)v8 )
LABEL_592:
                i2c_trace_log();
LABEL_604:
              geni_i2c_stop_on_bus(v8);
              v241 = *(_DWORD *)(v8 + 24);
LABEL_493:
              v290 = v241;
              goto LABEL_494;
            }
            ipc_log_string(v143, "msg[%d].len:%d R\n", v298, *(unsigned __int16 *)(*(_QWORD *)(v8 + 1336) + 4LL));
            if ( *(_QWORD *)v8 )
              i2c_trace_log();
            sg_init_table(*(_QWORD *)(v8 + 8928), 1);
            v144 = *(const char ***)(v8 + 5088);
            v3 = v8 + 0x2000;
            if ( !v144 )
            {
              v262 = -22;
LABEL_584:
              LODWORD(v3) = v296;
              ipc_log_string(*(_QWORD *)(v8 + 5096), "geni_se_common_iommu_map_buf for rx failed :%d\n", v262);
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "geni_se_common_iommu_map_buf for rx failed :%d\n", v262);
              else
                printk(&unk_F0C3, v262, v263);
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
              i2c_put_dma_safe_msg_buf(v142, v4, 0);
              goto LABEL_604;
            }
            v145 = *(unsigned __int16 *)(v4 + 4);
            v146 = is_vmalloc_addr(v142);
            if ( (v146 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
            {
              v234 = v146;
              dma_map_single_attrs___already_done = 1;
              v235 = (const char *)dev_driver_string(v144);
              v236 = v144[14];
              if ( !v236 )
                v236 = *v144;
              _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v235, v236);
              __break(0x800u);
              v3 = v8 + 0x2000;
              if ( (v234 & 1) != 0 )
              {
LABEL_582:
                *v289 = -1;
LABEL_583:
                v262 = -5;
                goto LABEL_584;
              }
            }
            else if ( (v146 & 1) != 0 )
            {
              goto LABEL_582;
            }
            v147 = dma_map_page_attrs(
                     v144,
                     ((unsigned __int64)((v142 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                     v142 & 0xFFF,
                     v145,
                     2,
                     0);
            *v289 = v147;
            if ( v147 == -1 )
              goto LABEL_583;
            v148 = *(_QWORD *)(v8 + 9096);
            if ( v148 )
            {
              *(_QWORD *)(v148 + 16LL * (int)v298) = v142;
              *(_QWORD *)(*(_QWORD *)(v8 + 9096) + 16LL * (int)v298 + 8) = v289;
              v147 = *(_QWORD *)(v8 + 8864);
            }
            *(_QWORD *)(v8 + 5264) = v147;
            v149 = *(_QWORD *)(v8 + 8928);
            v150 = *(unsigned __int16 *)(v304 + 16LL * (int)v298 + 4);
            *(_DWORD *)(v8 + 5276) = 1049088;
            v151 = v300;
            *(_DWORD *)(v8 + 5272) = v150;
            *(_QWORD *)v149 = *(_QWORD *)v149 & 3LL
                            | (((unsigned __int64)(((__int64)((v8 + 5264) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                             - 0x140000000LL);
            *(_DWORD *)(v149 + 8) = (v8 + 5264) & 0xFFF;
            *(_DWORD *)(v149 + 12) = 16;
            v152 = geni_i2c_prep_desc((_QWORD *)v8, v302, 0);
            *(_QWORD *)(v8 + 8976) = v152;
            if ( !v152 )
            {
              v165 = -12;
LABEL_292:
              v101 = v298;
              *(_DWORD *)(v8 + 24) = v165;
              v96 = (_BYTE *)v3;
              LODWORD(v3) = v296;
              goto LABEL_293;
            }
            v153 = *(__int64 (__fastcall **)(_QWORD))(v152 + 24);
            if ( *((_DWORD *)v153 - 1) != 1188179853 )
              __break(0x8228u);
            v154 = v153(v152);
            if ( (v154 & 0x80000000) != 0 )
            {
              printk(&unk_F551, "geni_i2c_gsi_read", v154);
              v165 = -22;
              goto LABEL_292;
            }
            v155 = *(_QWORD *)(v8 + 5128);
            v156 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v155 + 360LL);
            if ( *((_DWORD *)v156 - 1) != 905352215 )
              __break(0x8228u);
            v156(v155);
            if ( (_DWORD)v296 - 1 == (_DWORD)v298 && (*(_BYTE *)(v3 + 893) & 1) != 0 )
            {
              v157 = *(_QWORD *)(v8 + 8920) + 32 * v136;
              *(_QWORD *)v157 = *(_QWORD *)v157 & 3LL | v285;
              *(_DWORD *)(v157 + 8) = v284;
              *(_DWORD *)(v157 + 12) = 16;
            }
            v158 = geni_i2c_prep_desc((_QWORD *)v8, v302, 1);
            *(_QWORD *)(v8 + 8968) = v158;
            if ( v158 )
            {
              v159 = *(__int64 (__fastcall **)(_QWORD))(v158 + 24);
              if ( *((_DWORD *)v159 - 1) != 1188179853 )
                __break(0x8228u);
              v160 = v159(v158);
              v96 = (_BYTE *)v3;
              if ( (v160 & 0x80000000) == 0 )
              {
                v161 = *(_QWORD *)(v8 + 5120);
                v162 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v161 + 360LL);
                if ( *((_DWORD *)v162 - 1) != 905352215 )
                  __break(0x8228u);
                v162(v161);
                v163 = wait_for_completion_timeout(v8 + 1272, *(unsigned int *)(v8 + 28));
                LODWORD(v3) = v296;
LABEL_397:
                v287 = v142;
                v101 = v298;
                if ( v163 )
                {
LABEL_398:
                  v290 = 0;
                  if ( *(_DWORD *)(v8 + 24) )
                    goto LABEL_400;
                  goto LABEL_399;
                }
LABEL_469:
                ipc_log_string(
                  *(_QWORD *)(v8 + 5096),
                  "I2C gsi xfer timeout:%u flags:%d addr:0x%x\n",
                  *(_DWORD *)(v8 + 28),
                  *(unsigned __int16 *)(*(_QWORD *)(v8 + 1336) + 2LL),
                  **(unsigned __int16 **)(v8 + 1336));
                v230 = *(unsigned __int16 **)(v8 + 1336);
                v231 = *(_DWORD *)(v8 + 28);
                if ( *(_QWORD *)v8 )
                  dev_err(*(_QWORD *)v8, "I2C gsi xfer timeout:%u flags:%d addr:0x%x\n", v231, v230[1], *v230);
                else
                  printk(&unk_FDC0, v231, v230[1]);
                if ( *(_QWORD *)v8 )
                  i2c_trace_log();
                geni_i2c_se_dump_dbg_regs(v8 + 4960, *(_QWORD *)(v8 + 8), *(_QWORD *)(v8 + 5096));
                v232 = *(_QWORD *)(v8 + 8);
                *(_DWORD *)(v8 + 24) = -110;
                if ( (~(unsigned int)readl_relaxed((unsigned int *)(v232 + 2312)) & 3) != 0 )
                {
                  ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: IO lines not in good state\n", "geni_i2c_gsi_xfer");
                  if ( *(_QWORD *)v8 )
                    i2c_trace_log();
                  if ( v96[921] == 1 )
                  {
                    v233 = v96[893];
                    v151 = v300;
                    v290 = 0;
                    v96[919] = 1;
                    if ( (v233 & 1) == 0 )
                      goto LABEL_420;
                    goto LABEL_416;
                  }
                }
LABEL_374:
                v151 = v300;
                goto LABEL_398;
              }
              v228 = v160;
              ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_read", v160);
              v101 = v298;
              LODWORD(v3) = v296;
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_read", v228);
              else
                printk(&unk_F551, "geni_i2c_gsi_read", v228);
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
              goto LABEL_465;
            }
            v225 = *(_QWORD *)(v8 + 5096);
            *(_DWORD *)(v8 + 24) = -12;
            ipc_log_string(v225, "geni_i2c_prep_desc failed\n");
            v96 = (_BYTE *)v3;
            if ( *(_QWORD *)v8 )
              dev_err(*(_QWORD *)v8, "geni_i2c_prep_desc failed\n");
            else
              printk(&unk_1023F, v226, v227);
            v101 = v298;
            v151 = v300;
            v229 = *(_QWORD *)v8;
            LODWORD(v3) = v296;
LABEL_460:
            if ( v229 )
              i2c_trace_log();
LABEL_293:
            v290 = *(_DWORD *)(v8 + 24);
            if ( v290 )
              goto LABEL_400;
LABEL_399:
            if ( v96[920] != 1 )
              goto LABEL_410;
LABEL_400:
            v211 = *(__int64 (**)(void))(**(_QWORD **)(v8 + 5120) + 336LL);
            if ( v211 )
            {
              if ( *((_DWORD *)v211 - 1) != -403578064 )
                __break(0x8228u);
              v212 = v211();
              if ( !v212 )
                goto LABEL_408;
            }
            else
            {
              v212 = -38;
            }
            ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: gpi terminate failed ret:%d\n", "geni_i2c_err_prep_sg", v212);
            if ( *(_QWORD *)v8 )
              i2c_trace_log();
LABEL_408:
            v213 = (unsigned __int8)v96[912];
            v151 = v300;
            *(_DWORD *)(v8 + 8952) = 0;
            if ( v213 == 1 )
              v96[917] = 1;
LABEL_410:
            if ( v96[920] == 1 )
            {
              if ( !*(_DWORD *)(v8 + 24) )
                *(_DWORD *)(v8 + 24) = -5;
              v96[920] = 0;
            }
            if ( v96[893] == 1 )
            {
              *(_DWORD *)(v8 + 8952) = 0;
LABEL_416:
              if ( *(_DWORD *)(v8 + 24) )
              {
                ipc_log_string(*(_QWORD *)(v8 + 5096), "Unlock bus\n");
                if ( *(_QWORD *)v8 )
                  i2c_trace_log();
                geni_i2c_unlock_bus(v8);
              }
            }
LABEL_420:
            if ( (*(_WORD *)(v151 + 2) & 1) != 0 )
            {
              if ( *v289 != -1 )
                dma_unmap_page_attrs(*(_QWORD *)(v8 + 5088), *v289, *(unsigned __int16 *)(v151 + 4), 2, 0);
              updated = i2c_put_dma_safe_msg_buf(v287, v151, *(_DWORD *)(v8 + 24) == 0);
              if ( *(_DWORD *)(v8 + 24) )
                goto LABEL_494;
LABEL_431:
              v214 = *(_WORD *)(v151 + 2);
              v215 = "_rd";
              v310 = 0;
              v311 = 0;
              v308 = 0;
              v309 = 0;
              if ( (v214 & 1) != 0 )
                goto LABEL_433;
              goto LABEL_432;
            }
            if ( *(_DWORD *)(v8 + 24) )
            {
              if ( *(_BYTE *)(v8 + 1360) == 1 )
              {
                updated = gi2c_gsi_tre_process(v8, (unsigned int)v3);
                if ( *(_DWORD *)(v8 + 24) )
                  goto LABEL_494;
              }
              else
              {
                updated = ((__int64 (__fastcall *)(unsigned __int64, _QWORD, _QWORD))gi2c_gsi_tx_unmap)(
                            v8,
                            v101,
                            v292 - 1);
                if ( *(_DWORD *)(v8 + 24) )
                  goto LABEL_494;
              }
              goto LABEL_431;
            }
            v310 = 0;
            v311 = 0;
            v308 = 0;
            v309 = 0;
LABEL_432:
            v215 = "_wr";
LABEL_433:
            updated = scnprintf(&v308, 32, "%s%s", "geni_i2c_gsi_xfer", v215);
            v216 = *(_QWORD *)(v8 + 5104);
            if ( v216 && v293 && *(_DWORD *)(v8 + 5112) )
            {
              v217 = *(_DWORD *)(v8 + 8956);
              v218 = *(unsigned __int16 *)(v300 + 4);
              v219 = sched_clock(updated) - v293;
              v220 = v219 / 0x3E8;
              if ( v218 )
              {
                if ( v217 )
                  updated = ipc_log_string(
                              v216,
                              "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                              (const char *)&v308,
                              v219,
                              v220,
                              v218,
                              v217);
                else
                  updated = ipc_log_string(
                              v216,
                              "%s:took %llu nsec(%llu usec) for %u bytes\n",
                              (const char *)&v308,
                              v219,
                              v220,
                              v218);
              }
              else
              {
                updated = ipc_log_string(v216, "%s:took %llu nsec(%llu usec)\n", (const char *)&v308, v219, v220);
              }
              v96 = (_BYTE *)(v8 + 0x2000);
              v101 = v298;
            }
            v97 = v101 + 1;
            if ( (_DWORD)v97 == (_DWORD)v3 )
              goto LABEL_494;
          }
          else
          {
            v138 = *(unsigned __int16 *)(v4 + 4);
            v139 = v117 + 1;
            LOBYTE(v308) = 0;
            if ( v138 >= 9 )
            {
              v140 = *(_QWORD *)(v8 + 9184);
              if ( v140 )
              {
                if ( v292 > 0x1BF )
                  goto LABEL_618;
                v141 = (__int64 *)(v277 + 8LL * v292);
                v291 = v292;
                *v141 = v140;
              }
              else
              {
                v173 = i2c_get_dma_safe_msg_buf(v4, 1);
                if ( v292 > 0x1BF )
                  goto LABEL_618;
                v140 = v173;
                v141 = (__int64 *)(v277 + 8LL * v292);
                *v141 = v173;
                if ( !v173 )
                {
                  v267 = *(_QWORD *)(v8 + 5096);
                  *(_DWORD *)(v8 + 24) = -12;
                  ipc_log_string(v267, "i2c_get_dma_safe_msg_buf failed :%d\n", 0);
                  if ( *(_QWORD *)v8 )
                    dev_err(*(_QWORD *)v8, "i2c_get_dma_safe_msg_buf failed :%d\n", 0);
                  else
                    printk(&unk_FDEE, 0, v268);
                  LODWORD(v3) = v296;
                  if ( *(_QWORD *)v8 )
                    goto LABEL_592;
                  goto LABEL_604;
                }
                v291 = v292;
              }
              v174 = *(const char ***)(v8 + 5088);
              if ( !v174 )
              {
                v264 = -22;
LABEL_596:
                ipc_log_string(*(_QWORD *)(v8 + 5096), "geni iommu_map_buf for tx failed :%d\n", v264);
                if ( *(_QWORD *)v8 )
                  dev_err(*(_QWORD *)v8, "geni iommu_map_buf for tx failed :%d\n", v264);
                else
                  printk(&unk_10471, v264, v265);
                if ( *(_QWORD *)v8 )
                  i2c_trace_log();
                if ( !*(_QWORD *)(v8 + 9184) )
                  i2c_put_dma_safe_msg_buf(*v141, v4, 0);
                *(_DWORD *)(v8 + 24) = v264;
                goto LABEL_604;
              }
              v175 = *(unsigned __int16 *)(v4 + 4);
              v279 = v141;
              v176 = is_vmalloc_addr(v140);
              if ( (v176 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
              {
                v237 = v176;
                dma_map_single_attrs___already_done = 1;
                v238 = (const char *)dev_driver_string(v174);
                v239 = v174[14];
                if ( !v239 )
                  v239 = *v174;
                _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v238, v239);
                v176 = v237;
                __break(0x800u);
              }
              v177 = (__int64 *)(v8 + 5280 + 8 * v291);
              if ( (v176 & 1) != 0 )
              {
                *v177 = -1;
LABEL_595:
                LODWORD(v3) = v296;
                v141 = v279;
                v264 = -5;
                goto LABEL_596;
              }
              v178 = dma_map_page_attrs(
                       v174,
                       ((unsigned __int64)((v140 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                       v140 & 0xFFF,
                       v175,
                       1,
                       0);
              *v177 = v178;
              if ( v178 == -1 )
                goto LABEL_595;
              v179 = *(_QWORD *)(v8 + 9096);
              LODWORD(v3) = v296;
              v116 = v304;
              LODWORD(v97) = v298;
              if ( v179 )
              {
                v180 = 16 * v291;
                *(_QWORD *)(v179 + v180) = *v279;
                *(_QWORD *)(*(_QWORD *)(v8 + 9096) + v180 + 8) = v177;
              }
            }
            ipc_log_string(
              *(_QWORD *)(v8 + 5096),
              "msg[%d].len:%d W cnt:%d idx:%d\n",
              v97,
              *(unsigned __int16 *)(*(_QWORD *)(v8 + 1336) + 4LL),
              *(_DWORD *)(v8 + 1352),
              v292);
            if ( *(_QWORD *)v8 )
              i2c_trace_log();
            if ( *(_BYTE *)(v8 + 9122) == 1 )
            {
              v181 = *(_DWORD *)(v8 + 9192);
              v182 = v296 - 1;
              if ( v181 < 1 )
              {
                v184 = v117 + 1;
              }
              else
              {
                *(_WORD *)(v4 + 4) = *(_DWORD *)(v8 + 9136);
                *(_QWORD *)(v4 + 8) = *(_QWORD *)(v8 + 9152);
                v183 = setup_tx_tre(v8, v116, (unsigned int)v97, (unsigned int)v3, &v308, v292, v181 != 1, 0, StatusReg);
                v184 = v117 + 2;
                v185 = *(_QWORD *)(v8 + 8920) + 32 * v139;
                *(_QWORD *)v185 = (((unsigned __int64)((v183 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                                | *(_QWORD *)v185 & 3LL;
                *(_DWORD *)(v185 + 8) = v183 & 0xFFF;
                *(_DWORD *)(v185 + 12) = 16;
                v186 = *(_DWORD *)(v8 + 9192);
                if ( v186 >= 2 )
                {
                  *(_WORD *)(v4 + 4) = *(_DWORD *)(v8 + 9140);
                  *(_QWORD *)(v4 + 8) = *(_QWORD *)(v8 + 9160);
                  v187 = setup_tx_tre(v8, v116, v298, v296, &v308, v292, v186 != 2, 1, StatusReg);
                  v3 = v117 + 3;
                  v188 = *(_QWORD *)(v8 + 8920) + 32 * v184;
                  v184 = v117 + 3;
                  *(_QWORD *)v188 = (((unsigned __int64)((v187 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                                  | *(_QWORD *)v188 & 3LL;
                  *(_DWORD *)(v188 + 8) = v187 & 0xFFF;
                  *(_DWORD *)(v188 + 12) = 16;
                  v189 = *(_DWORD *)(v8 + 9192);
                  if ( v189 >= 3 )
                  {
                    *(_WORD *)(v4 + 4) = *(_DWORD *)(v8 + 9144);
                    *(_QWORD *)(v4 + 8) = *(_QWORD *)(v8 + 9168);
                    v190 = setup_tx_tre(v8, v116, v298, v296, &v308, v292, v189 != 3, 2, StatusReg);
                    v191 = *(_QWORD *)(v8 + 8920) + 32 * v3;
                    *(_QWORD *)v191 = (((unsigned __int64)((v190 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                                    | *(_QWORD *)v191 & 3LL;
                    *(_DWORD *)(v191 + 8) = v190 & 0xFFF;
                    *(_DWORD *)(v191 + 12) = 16;
                    if ( *(int *)(v8 + 9192) > 3 )
                      goto LABEL_618;
                    v182 = v296 - 1;
                    v184 = v117 | 4;
                  }
                }
              }
              LODWORD(v3) = v296;
              v194 = v298;
              *(_WORD *)(v4 + 4) = *(_DWORD *)(v8 + 9124);
              *(_QWORD *)(v4 + 8) = *(_QWORD *)(v8 + 9128);
            }
            else
            {
              v192 = setup_tx_tre(v8, v116, (unsigned int)v97, (unsigned int)v3, &v308, v292, 0, 0, StatusReg);
              v182 = v296 - 1;
              v193 = *(_QWORD *)(v8 + 8920) + 32 * v139;
              *(_QWORD *)v193 = (((unsigned __int64)((v192 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                              | *(_QWORD *)v193 & 3LL;
              v194 = v97;
              v184 = v117 + 2;
              *(_DWORD *)(v193 + 8) = v192 & 0xFFF;
              *(_DWORD *)(v193 + 12) = 16;
            }
            v96 = (_BYTE *)(v8 + 0x2000);
            if ( v182 == v194 && (*(_BYTE *)(v8 + 9085) & 1) != 0 )
            {
              v195 = *(_QWORD *)(v8 + 8920) + 32 * v184;
              *(_QWORD *)v195 = *(_QWORD *)v195 & 3LL | v285;
              *(_DWORD *)(v195 + 8) = v284;
              *(_DWORD *)(v195 + 12) = 16;
              if ( *(_BYTE *)(v8 + 1360) == 1 )
                LOBYTE(v308) = 0;
            }
            v196 = geni_i2c_prep_desc((_QWORD *)v8, v302, 1);
            *(_QWORD *)(v8 + 8968) = v196;
            if ( !v196 )
            {
              v221 = *(_QWORD *)(v8 + 5096);
              *(_DWORD *)(v8 + 24) = -12;
              ipc_log_string(v221, "geni_i2c_prep_desc failed\n");
              v101 = v298;
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "geni_i2c_prep_desc failed\n");
              else
                printk(&unk_1023F, v222, v223);
              v151 = v300;
              v229 = *(_QWORD *)v8;
              goto LABEL_460;
            }
            v101 = v298;
            if ( (unsigned __int8)v308 == 1 )
            {
              ipc_log_string(*(_QWORD *)(v8 + 5096), "geni tx desc call back null %d\n", v298);
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
              *(_QWORD *)(*(_QWORD *)(v8 + 8968) + 40LL) = 0;
              *(_QWORD *)(*(_QWORD *)(v8 + 8968) + 56LL) = 0;
            }
            v197 = *(_QWORD *)(v8 + 5096);
            v198 = *(_DWORD *)(v8 + 1352) + 1;
            *(_DWORD *)(v8 + 1352) = v198;
            ipc_log_string(v197, "tx_cnt:%d", v198);
            if ( *(_QWORD *)v8 )
              i2c_trace_log();
            v199 = v298 + 1;
            v292 = ((int)v298 + 1) % 448;
            v200 = *(__int64 (**)(void))(*(_QWORD *)(v8 + 8968) + 24LL);
            if ( *((_DWORD *)v200 - 1) != 1188179853 )
              __break(0x8228u);
            v201 = v200();
            if ( v201 < 0 )
            {
              v224 = v201;
              ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_write", v201);
              if ( *(_QWORD *)v8 )
                dev_err(*(_QWORD *)v8, "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_write", v224);
              else
                printk(&unk_F551, "geni_i2c_gsi_write", v224);
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
LABEL_465:
              *(_DWORD *)(v8 + 24) = -22;
              v151 = v300;
              goto LABEL_293;
            }
            v202 = *(__int64 (**)(void))(**(_QWORD **)(v8 + 5120) + 360LL);
            if ( *((_DWORD *)v202 - 1) != 905352215 )
              __break(0x8228u);
            updated = v202();
            if ( (_DWORD)v298 == v182
              || !*(_BYTE *)(v8 + 1360)
              || *(_DWORD *)(v8 + 1352) >= (unsigned int)(*(_DWORD *)(v8 + 1356) + 448) )
            {
              v203 = *(_QWORD *)(v8 + 5104);
              v204 = v294;
              if ( v203 )
              {
                if ( *(_DWORD *)(v8 + 5112) )
                {
                  v303 = sched_clock(updated);
                  ipc_log_string(
                    v203,
                    "%s:start at %llu nsec(%llu usec)\n",
                    "geni_i2c_gsi_tx_tre_optimization",
                    v303,
                    v303 / 0x3E8);
                  v204 = v294;
                  if ( (*(_BYTE *)(v8 + 1360) & 1) != 0 )
                    goto LABEL_355;
LABEL_369:
                  v163 = wait_for_completion_timeout(v8 + 1272, *(unsigned int *)(v8 + 28));
                  v207 = *(_QWORD *)(v8 + 5096);
                  *(_DWORD *)(v8 + 1272) = 0;
                  ipc_log_string(v207, "%s: msg_idx:%d wr_idx:%d\n", "geni_i2c_gsi_tx_tre_optimization", v298, v292 - 1);
                  if ( *(_QWORD *)v8 )
                    i2c_trace_log();
                  if ( *(_BYTE *)(v8 + 9112) == 1 )
                  {
                    ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: gsi error\n", "geni_i2c_gsi_tx_tre_optimization");
                    v96 = (_BYTE *)(v8 + 0x2000);
                    if ( *(_QWORD *)v8 )
LABEL_373:
                      i2c_trace_log();
                    goto LABEL_374;
                  }
                  if ( v163 )
                  {
                    if ( !*(_DWORD *)(v8 + 24) )
                      ((void (__fastcall *)(unsigned __int64, _QWORD, _QWORD))gi2c_gsi_tx_unmap)(
                        v8,
                        (unsigned int)v298,
                        v292 - 1);
                    goto LABEL_383;
                  }
                  goto LABEL_389;
                }
                v303 = 0;
                if ( !*(_BYTE *)(v8 + 1360) )
                  goto LABEL_369;
              }
              else
              {
                v303 = -22;
                if ( !*(_BYTE *)(v8 + 1360) )
                  goto LABEL_369;
              }
LABEL_355:
              if ( v204 )
              {
                v96 = (_BYTE *)(v8 + 0x2000);
                v205 = 0;
                v163 = 1;
                while ( 1 )
                {
                  if ( v204 != *(_DWORD *)(v8 + 1364) )
                  {
                    ipc_log_string(
                      *(_QWORD *)(v8 + 5096),
                      "%s: calling wait for_completion %d\n",
                      "geni_i2c_gsi_tx_tre_optimization",
                      v205);
                    if ( *(_QWORD *)v8 )
                      i2c_trace_log();
                    v206 = wait_for_completion_timeout(v8 + 1272, *(unsigned int *)(v8 + 28));
                    v204 = v294;
                    v163 = v206;
                    *(_DWORD *)(v8 + 1272) = 0;
                    if ( !v206 )
                    {
                      ipc_log_string(
                        *(_QWORD *)(v8 + 5096),
                        "%s: msg xfer timeout\n",
                        "geni_i2c_gsi_tx_tre_optimization");
                      if ( *(_QWORD *)v8 )
                        i2c_trace_log();
                      v101 = v298;
                      goto LABEL_469;
                    }
                  }
                  ipc_log_string(
                    *(_QWORD *)(v8 + 5096),
                    "%s: maxirq_cnt:%d i:%d\n",
                    "geni_i2c_gsi_tx_tre_optimization",
                    v204,
                    v205);
                  if ( *(_QWORD *)v8 )
                    i2c_trace_log();
                  if ( *(_BYTE *)(v8 + 9112) == 1 )
                    break;
                  gi2c_gsi_tre_process(v8, (unsigned int)v3);
                  if ( *(_DWORD *)(v8 + 1352) < (unsigned int)v3 )
                  {
                    v142 = v287;
                    v151 = v300;
                    goto LABEL_397;
                  }
                  v204 = v294;
                  if ( v294 == ++v205 )
                  {
                    if ( !v163 )
                      goto LABEL_389;
                    goto LABEL_383;
                  }
                }
                ipc_log_string(*(_QWORD *)(v8 + 5096), "%s: gsi error\n", "geni_i2c_gsi_tx_tre_optimization");
                v101 = v298;
                if ( *(_QWORD *)v8 )
                  goto LABEL_373;
                goto LABEL_374;
              }
              v163 = 1;
LABEL_383:
              if ( *(_BYTE *)(v8 + 1360) == 1 )
                gi2c_gsi_tre_process(v8, (unsigned int)v3);
LABEL_389:
              ipc_log_string(*(_QWORD *)(v8 + 5096), "%s:  timeout :%d\n", "geni_i2c_gsi_tx_tre_optimization", v163);
              v208 = *(_QWORD *)v8;
              if ( *(_QWORD *)v8 )
                i2c_trace_log();
              v209 = *(_QWORD *)(v8 + 5104);
              if ( v209 )
              {
                v151 = v300;
                if ( v303 && *(_DWORD *)(v8 + 5112) )
                {
                  v210 = sched_clock(v208);
                  ipc_log_string(
                    v209,
                    "%s:took %llu nsec(%llu usec)\n",
                    "geni_i2c_gsi_tx_tre_optimization",
                    v210 - v303,
                    (v210 - v303) / 0x3E8);
                }
                v142 = v287;
                v96 = (_BYTE *)(v8 + 0x2000);
              }
              else
              {
                v142 = v287;
                v96 = (_BYTE *)(v8 + 0x2000);
                v151 = v300;
              }
              goto LABEL_397;
            }
            v290 = 0;
            v97 = v199;
            if ( v199 == (_DWORD)v3 )
              goto LABEL_494;
          }
        }
        v4 = *(unsigned __int16 *)(v300 + 4) + 16LL;
        v111 = _kmalloc_noprof(v4, 3520);
        v29 = v290;
        if ( !v111 )
        {
          v240 = *(_QWORD *)(v8 + 5096);
          *(_DWORD *)(v8 + 9192) = -12;
          ipc_log_string(v240, "%s: split tx dma tre failed ret:%d\n", "geni_i2c_gsi_xfer", v290);
          v28 = *(_QWORD *)v8;
          if ( *(_QWORD *)v8 )
            i2c_trace_log();
          goto LABEL_188;
        }
        *v288 = v111;
        v112 = 16 - (v111 & 8);
        v113 = *(unsigned __int16 *)(v300 + 4);
        if ( v4 - v112 < v113 )
          goto LABEL_619;
        v109 = v111 + v112;
        memcpy((void *)(v111 + v112), *(const void **)(v300 + 8), v113);
        v114 = *(_QWORD *)(v8 + 5096);
        *(_QWORD *)(v8 + 9184) = v109;
        ipc_log_string(v114, "allocating 16 byte aligned\n");
        if ( *(_QWORD *)v8 )
          i2c_trace_log();
LABEL_304:
        v169 = v110 & 0xF;
        if ( (v110 & 0xF) != 0 )
        {
          v170 = (unsigned __int16)v110 & 0xFFF0;
          if ( v169 >= 8 )
            v171 = 8;
          else
            v171 = v110 & 0xF;
          *(_DWORD *)(v8 + 9136) = v170;
          v172 = v109 + v170;
          *(_QWORD *)(v8 + 9152) = v109;
          *(_DWORD *)(v8 + 9140) = v171;
          *(_QWORD *)(v8 + 9160) = v172;
          if ( v169 >= 9 )
          {
            *(_DWORD *)(v8 + 9144) = v169 - 8;
            v168 = 3;
            *(_QWORD *)(v8 + 9168) = v172 + v171;
          }
          else
          {
            v168 = 2;
          }
        }
        else
        {
          *(_DWORD *)v283 = v110;
          v168 = 1;
          *v282 = v109;
        }
LABEL_386:
        v96 = (_BYTE *)(v8 + 0x2000);
        goto LABEL_387;
      }
      v290 = 0;
      LODWORD(v3) = 0;
LABEL_494:
      if ( *(_BYTE *)(v8 + 1360) == 1 )
        updated = gpi_update_multi_desc_flag(*(_QWORD *)(v8 + 5120), 0, 0);
      v10 = v6 + 1024;
      v29 = v290;
      if ( !v290 )
        v29 = *(_DWORD *)(v8 + 24);
      v242 = *(_QWORD *)(v8 + 5096);
      v243 = sched_clock(updated);
      v28 = ipc_log_string(v242, "%s Time took for %d xfers = %llu nsecs\n", "geni_i2c_gsi_xfer", v3, v243 - v276);
      if ( *(_QWORD *)v8 )
      {
        sched_clock(v28);
        i2c_trace_log();
      }
LABEL_500:
      if ( v29 )
        v9 = v29;
      else
        v9 = v3;
      if ( (v10[912] & 1) == 0 && (v10[914] & 1) == 0 )
      {
        v244 = *v6;
        *(_QWORD *)(v244 + 520) = ktime_get_mono_fast_ns(v28);
        _pm_runtime_suspend(*v6, 13);
      }
      *((_DWORD *)v6 + 2279) = 0;
      v245 = v6[637];
      v246 = *((_DWORD *)v6 + 2239);
      v6[167] = 0;
      *((_DWORD *)v6 + 6) = 0;
      ipc_log_string(v245, "i2c txn ret:%d freq=%dHz\n", v9, v246);
      v247 = *v6;
      if ( *v6 )
        i2c_trace_log();
      v248 = v6[638];
      if ( v248 && v286 && *((_DWORD *)v6 + 1278) )
      {
        v249 = sched_clock(v247);
        ipc_log_string(v248, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_xfer", v249 - v286, (v249 - v286) / 0x3E8);
      }
      goto LABEL_512;
    }
LABEL_620:
    __break(1u);
    v269 = _ReadStatusReg(SP_EL0);
    v270 = *(_QWORD *)(v269 + 80);
    *(_QWORD *)(v269 + 80) = &_start_alloc_tags;
    if ( (v3 & 0x80000000) != 0 )
      v21 = 0;
    else
      v21 = _kmalloc_noprof(16LL * (unsigned int)v296, 3520);
    LODWORD(v3) = v296;
    v10 = v6 + 1024;
    a2 = (unsigned __int16 *)v304;
    *(_QWORD *)(v269 + 80) = v270;
    v6[1137] = v21;
    if ( !v21 )
      goto LABEL_45;
  }
  v22 = 0;
  v23 = a2 + 2;
  while ( 1 )
  {
    v24 = *v23;
    v23 += 8;
    if ( !v24 )
      break;
    if ( (unsigned int)v3 == ++v22 )
      goto LABEL_52;
  }
  ipc_log_string(v6[637], "%s: I2C msg[%d] length is NULL\n", "geni_i2c_xfer", v22);
  if ( *v6 )
    i2c_trace_log();
  v9 = -22;
LABEL_512:
  _ReadStatusReg(SP_EL0);
  return v9;
}
