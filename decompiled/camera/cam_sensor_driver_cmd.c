// positive sp value has been detected, the output may be wrong!
__int64 __fastcall cam_sensor_driver_cmd(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  int v5; // w6
  __int64 v6; // x1
  int v7; // w7
  int v8; // w8
  unsigned int buf_to_list; // w20
  unsigned int v10; // w7
  const char *v11; // x5
  __int64 v12; // x6
  __int64 v13; // x2
  __int64 v14; // x4
  const char *v15; // x5
  __int64 v16; // x6
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x4
  _DWORD *v20; // x8
  int v21; // w10
  int v22; // w11
  unsigned int v23; // w11
  unsigned __int64 StatusReg; // x9
  char v25; // w12
  int v26; // w10
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x10
  unsigned __int64 v35; // x9
  int v36; // w8
  int v37; // w7
  int v39; // w6
  unsigned int v40; // w0
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w0
  unsigned int v45; // w0
  unsigned int matched; // w0
  unsigned int v47; // w0
  unsigned int v48; // w0
  int v49; // w8
  __int64 v50; // x8
  __int64 (__fastcall *v51)(_QWORD); // x8
  int v52; // w10
  const char *v53; // x5
  __int64 v54; // x6
  __int64 v55; // x4
  unsigned int cpu_buf; // w0
  unsigned int v57; // w0
  int device_hdl; // w0
  int v59; // w9
  char v60; // w8
  unsigned int v61; // w0
  __int64 v62; // x0
  _DWORD *v63; // x8
  const char *v64; // x5
  __int64 v65; // x6
  __int64 v66; // x4
  int *v67; // x8
  const char *v68; // x5
  __int64 v69; // x7
  int v70; // w8
  __int64 v71; // x6
  __int64 v72; // x2
  __int64 v73; // x4
  int *v74; // x8
  unsigned int *v75; // x8
  unsigned int v76; // w9
  __int64 v77; // x6
  __int64 v78; // x4
  int *v79; // x8
  const char *v80; // x5
  __int64 v81; // x4
  unsigned __int64 v82; // x7
  unsigned __int64 v83; // x6
  _QWORD *v84; // x0
  _QWORD *v85; // x0
  unsigned int *v86; // x22
  int v87; // w24
  char v88; // w9
  char *v89; // x8
  const char *v90; // x5
  __int64 v91; // x4
  __int64 v92; // x9
  __int64 v93; // x7
  __int64 v94; // x22
  __int64 v95; // x11
  __int64 v96; // x8
  __int64 v97; // x10
  __int64 v98; // x10
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x25
  const char *v102; // x5
  __int64 v103; // x1
  __int64 v104; // x4
  __int64 v105; // x9
  __int64 v106; // x9
  const char *v107; // x5
  __int64 v108; // x4
  unsigned int *v109; // x21
  __int64 v110; // x25
  unsigned int *v111; // x1
  signed int v112; // w23
  __int64 v113; // x26
  int v114; // w8
  __int64 v115; // x27
  __int64 v116; // x7
  __int64 v117; // x20
  __int64 v118; // x7
  __int64 v119; // x20
  __int64 v120; // x7
  __int64 v121; // x20
  int v122; // w20
  __int64 v123; // x25
  __int64 v124; // x8
  __int64 v125; // x4
  __int64 v126; // x9
  unsigned __int64 v127; // x8
  unsigned __int64 v128; // x9
  _QWORD *v129; // x9
  _QWORD *v130; // x8
  __int64 v131; // x10
  __int64 v132; // x11
  __int64 v133; // x10
  __int64 v134; // x12
  __int64 v135; // x13
  __int64 v136; // x10
  __int64 v137; // x11
  __int64 v138; // x9
  __int64 v139; // x12
  unsigned int v140; // w8
  __int64 v141; // x21
  unsigned int data; // w0
  unsigned int v143; // w0
  const char *v144; // x5
  __int64 v145; // x6
  __int64 v146; // x4
  int v147; // [xsp-2Ch] [xbp-FCh]
  __int64 v148; // [xsp-28h] [xbp-F8h]
  __int64 v149; // [xsp-20h] [xbp-F0h]
  unsigned __int64 v150; // [xsp-18h] [xbp-E8h] BYREF
  __int64 v151; // [xsp-10h] [xbp-E0h]
  __int64 v152; // [xsp-8h] [xbp-D8h] BYREF
  unsigned __int64 v153; // [xsp+0h] [xbp-D0h]
  __int64 v154; // [xsp+8h] [xbp-C8h]
  unsigned __int64 v155; // [xsp+10h] [xbp-C0h] BYREF
  unsigned int *v156; // [xsp+18h] [xbp-B8h] BYREF
  __int64 v157; // [xsp+20h] [xbp-B0h] BYREF
  __int128 v158; // [xsp+28h] [xbp-A8h] BYREF
  __int64 v159; // [xsp+38h] [xbp-98h]
  __int64 v160; // [xsp+40h] [xbp-90h]
  __int64 v161; // [xsp+48h] [xbp-88h]
  __int64 v162; // [xsp+50h] [xbp-80h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v150 = 0;
  v151 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_driver_cmd",
      1376,
      "s_ctrl is NULL");
    buf_to_list = -22;
    goto LABEL_50;
  }
  v3 = *(_QWORD *)(a1 + 3656);
  if ( *(_DWORD *)a2 != 267 )
  {
    v5 = *(_DWORD *)(a2 + 8);
    if ( v5 != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_driver_cmd",
        1385,
        "Invalid handle type: %d",
        v5);
      buf_to_list = -22;
      goto LABEL_50;
    }
  }
  mutex_lock(a1 + 3608);
  v7 = *(_DWORD *)a2;
  if ( *(int *)a2 <= 259 )
  {
    if ( v7 == 257 )
    {
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_driver_cmd",
          1673,
          "%s Sensor Queried",
          (const char *)(a1 + 7560));
      v20 = *(_DWORD **)(a1 + 3656);
      v21 = v20[8];
      v22 = v20[9];
      HIDWORD(v158) = v20[7];
      LODWORD(v159) = v21;
      DWORD2(v158) = v22;
      v23 = *(_DWORD *)(a1 + 52);
      HIDWORD(v159) = v20[11];
      HIDWORD(v161) = v20[15];
      LODWORD(v160) = v20[12];
      LODWORD(v161) = v20[13];
      StatusReg = _ReadStatusReg(SP_EL0);
      v25 = *(_BYTE *)(StatusReg + 70);
      v26 = v20[16];
      v27 = *(_QWORD *)(a2 + 16);
      *(_QWORD *)&v158 = v23;
      HIDWORD(v160) = v26;
      if ( (v25 & 0x20) != 0 || (v28 = v27, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v28 = v27 & ((__int64)(v27 << 8) >> 8);
      if ( v28 <= 0x7FFFFFFFD8LL )
      {
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v35 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v35 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v35);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
        JUMPOUT(0x294210);
      }
      JUMPOUT(0x29424C);
    }
    if ( v7 != 258 )
    {
      if ( v7 == 259 )
      {
        v10 = *(_DWORD *)(a1 + 6544);
        DWORD2(v158) = 0;
        *(_QWORD *)&v158 = 0;
        if ( v10 > 4 || ((1 << v10) & 0x15) == 0 )
        {
          if ( *(_DWORD *)(a1 + 7160) && !*(_QWORD *)(a1 + 7168) )
          {
            buf_to_list = cam_sensor_apply_settings(a1, 0, 0);
            if ( (buf_to_list & 0x80000000) != 0 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_driver_cmd",
                1703,
                "cannot apply streamon settings for %s",
                (const char *)(a1 + 7560));
              goto LABEL_48;
            }
          }
          else
          {
            buf_to_list = 0;
          }
          v49 = *(unsigned __int8 *)(a1 + 7621);
          *(_DWORD *)(a1 + 6544) = 4;
          if ( v49 == 1 )
            *(_BYTE *)(a1 + 7620) = 0;
          v50 = *(_QWORD *)(a1 + 7528);
          if ( !v50 )
            goto LABEL_95;
          v51 = *(__int64 (__fastcall **)(_QWORD))(v50 + 24);
          if ( !v51 )
            goto LABEL_95;
          v52 = *(_DWORD *)(a1 + 7456);
          LODWORD(v158) = *(_DWORD *)(a1 + 7464);
          DWORD1(v158) = v52;
          BYTE8(v158) = 1;
          if ( *((_DWORD *)v51 - 1) != -1398328256 )
            __break(0x8228u);
          buf_to_list = v51(&v158);
          if ( !buf_to_list )
          {
LABEL_95:
            ktime_get_real_ts64(&v150);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              32,
              3,
              "cam_sensor_driver_cmd",
              1735,
              "%llu:%llu:%llu.%llu CAM_START_DEV Success for %s sensor_id:0x%x,sensor_slave_addr:0x%x num_batched_frames:%d",
              (_QWORD)(v150 / 0xE10 - 24 * ((v150 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
              v150 / 0x3C
            - 60 * ((unsigned __int64)((v150 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
              v150 % 0x3C,
              v151 / 1000000,
              (const char *)(a1 + 7560),
              *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 8LL),
              **(_DWORD **)(a1 + 3656),
              *(_DWORD *)(a1 + 7616));
            goto LABEL_48;
          }
          v53 = "%s Enable CRM SOF freeze timer failed rc: %d";
          v54 = a1 + 7560;
          v55 = 1721;
LABEL_104:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_driver_cmd",
            v55,
            v53,
            v54,
            buf_to_list);
          goto LABEL_48;
        }
        v11 = "Not in right state to start %s state: %d";
        v12 = a1 + 7560;
        v13 = 2;
        v14 = 1692;
        goto LABEL_46;
      }
      goto LABEL_33;
    }
    v36 = *(unsigned __int8 *)(a1 + 6548);
    v37 = *(_DWORD *)(a1 + 6544);
    v153 = 0;
    v154 = 0;
    v152 = 0;
    *((_QWORD *)&v158 + 1) = 0;
    if ( !v36 || v37 )
    {
      v11 = "Not in right state to aquire %s state: %d";
      v12 = a1 + 7560;
      v13 = 2;
      v14 = 1530;
      goto LABEL_46;
    }
    if ( *(_DWORD *)(a1 + 7456) != -1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_driver_cmd",
        1538,
        "%s Device is already acquired",
        (const char *)(a1 + 7560));
      goto LABEL_47;
    }
    buf_to_list = ((__int64 (__fastcall *)(__int64 *, _QWORD))inline_copy_from_user_11)(&v152, *(_QWORD *)(a2 + 16));
    if ( (buf_to_list & 0x80000000) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_driver_cmd",
        1546,
        "Failed Copying from user");
      goto LABEL_48;
    }
    *(_QWORD *)((char *)&v158 + 4) = 0;
    LODWORD(v158) = v152;
    v160 = a1 + 7472;
    v161 = a1;
    v159 = 32;
    device_hdl = cam_create_device_hdl((__int64)&v158);
    HIDWORD(v152) = device_hdl;
    if ( !device_hdl )
      goto LABEL_318;
    v59 = v152;
    v60 = debug_mdl;
    *(_DWORD *)(a1 + 7456) = device_hdl;
    *(_DWORD *)(a1 + 7460) = v59;
    if ( (v60 & 0x20) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v60 & 0x20,
        4,
        "cam_sensor_driver_cmd",
        1568,
        "%s Device Handle: %d",
        (const char *)(a1 + 7560),
        device_hdl);
    if ( ((__int64 (__fastcall *)(_QWORD, __int64 *, __int64))inline_copy_to_user_9)(*(_QWORD *)(a2 + 16), &v152, 24) )
LABEL_318:
      JUMPOUT(0x29426C);
    buf_to_list = ((__int64 (__fastcall *)(__int64))cam_sensor_power_up)(a1);
    if ( (buf_to_list & 0x80000000) != 0 )
    {
      v79 = *(int **)(a1 + 3656);
      v68 = "Sensor Power up failed for %s sensor_id:0x%x, slave_addr:0x%x";
      v69 = (unsigned int)v79[2];
      v70 = *v79;
      v71 = a1 + 7560;
      v72 = 1;
      v73 = 1584;
    }
    else
    {
      *(_DWORD *)(a1 + 6544) = 1;
      *(_DWORD *)(a1 + 7552) = 0;
      *(_QWORD *)(a1 + 7624) = 0;
      *(_BYTE *)(a1 + 7622) = 0;
      *(_DWORD *)(a1 + 7636) = 0;
      *(_QWORD *)(a1 + 7600) = 0;
      *(_QWORD *)(a1 + 7608) = 0;
      *(_QWORD *)(a1 + 7613) = 0;
      memset((void *)(a1 + 3664), 0, 0xB00u);
      v74 = *(int **)(a1 + 3656);
      *(_QWORD *)(a1 + 7640) = 0;
      *(_QWORD *)(a1 + 7648) = 0;
      *(_QWORD *)(a1 + 7656) = 0;
      v68 = "CAM_ACQUIRE_DEV Success for %s sensor_id:0x%x,sensor_slave_addr:0x%x";
      *(_QWORD *)(a1 + 7664) = 0;
      v71 = a1 + 7560;
      *(_QWORD *)(a1 + 7672) = 0;
      v72 = 3;
      *(_QWORD *)(a1 + 7680) = 0;
      v73 = 1603;
      *(_QWORD *)(a1 + 7688) = 0;
      *(_QWORD *)(a1 + 7696) = 0;
      *(_QWORD *)(a1 + 7704) = 0;
      *(_QWORD *)(a1 + 7712) = 0;
      *(_QWORD *)(a1 + 7720) = 0;
      *(_QWORD *)(a1 + 7728) = 0;
      *(_QWORD *)(a1 + 7736) = 0;
      *(_QWORD *)(a1 + 7744) = 0;
      *(_QWORD *)(a1 + 7752) = 0;
      *(_QWORD *)(a1 + 7760) = 0;
      *(_QWORD *)(a1 + 7768) = 0;
      *(_QWORD *)(a1 + 7776) = 0;
      *(_QWORD *)(a1 + 7784) = 0;
      *(_QWORD *)(a1 + 7792) = 0;
      *(_QWORD *)(a1 + 7800) = 0;
      *(_QWORD *)(a1 + 7808) = 0;
      *(_QWORD *)(a1 + 7816) = 0;
      *(_QWORD *)(a1 + 7824) = 0;
      *(_QWORD *)(a1 + 7832) = 0;
      *(_QWORD *)(a1 + 7840) = 0;
      *(_QWORD *)(a1 + 7848) = 0;
      *(_QWORD *)(a1 + 7856) = 0;
      *(_QWORD *)(a1 + 7864) = 0;
      *(_QWORD *)(a1 + 7872) = 0;
      *(_QWORD *)(a1 + 7880) = 0;
      *(_QWORD *)(a1 + 7888) = 0;
      v69 = (unsigned int)v74[2];
      v70 = *v74;
    }
LABEL_133:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      32,
      v72,
      "cam_sensor_driver_cmd",
      v73,
      v68,
      v71,
      v69,
      v70);
    goto LABEL_48;
  }
  if ( v7 > 261 )
  {
    if ( v7 != 262 )
    {
      if ( v7 == 267 )
      {
        if ( *(_BYTE *)(a1 + 6548) == 1 )
        {
          v15 = "Sensor %s already Probed in the slot";
          v16 = a1 + 7560;
          v17 = 32;
          v18 = 2;
          v19 = 1396;
          goto LABEL_23;
        }
        v39 = *(_DWORD *)(a2 + 8);
        if ( v39 == 2 )
        {
          v40 = cam_handle_mem_ptr(*(_QWORD *)(a2 + 16), v6, (_QWORD *)a1);
          if ( (v40 & 0x80000000) != 0 )
          {
            buf_to_list = v40;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              32,
              1,
              "cam_sensor_driver_cmd",
              1405,
              "Get Buffer Handle Failed");
            goto LABEL_48;
          }
          v41 = msm_camera_fill_vreg_params(
                  a1 + 32,
                  *(_QWORD *)(*(_QWORD *)(a1 + 3656) + 120LL),
                  *(unsigned __int16 *)(*(_QWORD *)(a1 + 3656) + 128LL));
          if ( (v41 & 0x80000000) != 0 )
          {
            buf_to_list = v41;
            v64 = "Fail in filling vreg params for %s PUP rc %d";
            v65 = a1 + 7560;
            v66 = 1423;
          }
          else
          {
            v42 = msm_camera_fill_vreg_params(
                    a1 + 32,
                    *(_QWORD *)(*(_QWORD *)(a1 + 3656) + 136LL),
                    *(unsigned __int16 *)(*(_QWORD *)(a1 + 3656) + 144LL));
            if ( (v42 & 0x80000000) == 0 )
            {
              v43 = ((__int64 (__fastcall *)(__int64))cam_sensor_power_up)(a1);
              if ( (v43 & 0x80000000) != 0 )
              {
                buf_to_list = v43;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_sensor_driver_cmd",
                  1447,
                  "Power up failed for %s sensor_id: 0x%x, slave_addr: 0x%x",
                  (const char *)(a1 + 7560),
                  *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 8LL),
                  **(_DWORD **)(a1 + 3656));
                goto LABEL_150;
              }
              if ( *(_DWORD *)(a1 + 7336) )
              {
                v44 = cam_sensor_apply_settings(a1, 0, 9u);
                if ( (v44 & 0x80000000) != 0 )
                {
                  buf_to_list = v44;
                  v80 = "REG_bank unlock failed";
                  v81 = 1455;
                  goto LABEL_148;
                }
                v45 = delete_request(a1 + 7320);
                if ( (v45 & 0x80000000) != 0 )
                {
                  buf_to_list = v45;
                  v80 = "failed while deleting REG_bank unlock settings";
                  v81 = 1462;
                  goto LABEL_148;
                }
              }
              matched = cam_sensor_match_id(a1);
              if ( (matched & 0x80000000) != 0 )
              {
                buf_to_list = matched;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  32,
                  3,
                  "cam_sensor_driver_cmd",
                  1476,
                  "Probe failed for %s slot:%d, slave_addr:0x%x, sensor_id:0x%x",
                  (const char *)(a1 + 7560),
                  *(_DWORD *)(a1 + 52),
                  **(_DWORD **)(a1 + 3656),
                  *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 8LL));
LABEL_149:
                cam_sensor_power_down(a1);
                goto LABEL_150;
              }
              if ( !*(_DWORD *)(a1 + 7384) )
              {
LABEL_67:
                buf_to_list = cam_sensor_power_down(a1);
                if ( (buf_to_list & 0x80000000) == 0 )
                {
                  *(_DWORD *)(a1 + 6544) = 0;
                  *(_BYTE *)(a1 + 6548) = 1;
                  ((void (__fastcall *)(__int64))msm_sensor_enable_debugfs)(a1);
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    32,
                    3,
                    "cam_sensor_driver_cmd",
                    1518,
                    "Probe success for %s slot:%d,slave_addr:0x%x,sensor_id:0x%x",
                    (const char *)(a1 + 7560),
                    *(_DWORD *)(a1 + 52),
                    **(_DWORD **)(a1 + 3656),
                    *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 8LL));
                  goto LABEL_48;
                }
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_sensor_driver_cmd",
                  1501,
                  "Fail in %s sensor Power Down",
                  (const char *)(a1 + 7560));
LABEL_150:
                v84 = *(_QWORD **)(v3 + 120);
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v84, 0);
                else
                  kvfree(v84);
                v85 = *(_QWORD **)(v3 + 136);
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v85, 0);
                else
                  kvfree(v85);
                *(_QWORD *)(v3 + 120) = 0;
                *(_QWORD *)(v3 + 136) = 0;
                *(_WORD *)(v3 + 144) = 0;
                *(_WORD *)(v3 + 128) = 0;
                goto LABEL_49;
              }
              v47 = cam_sensor_apply_settings(a1, 0, 0xAu);
              if ( (v47 & 0x80000000) != 0 )
              {
                buf_to_list = v47;
                v80 = "REG_bank lock failed";
                v81 = 1485;
              }
              else
              {
                v48 = delete_request(a1 + 7368);
                if ( (v48 & 0x80000000) == 0 )
                  goto LABEL_67;
                buf_to_list = v48;
                v80 = "failed while deleting REG_bank lock settings";
                v81 = 1492;
              }
LABEL_148:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_driver_cmd",
                v81,
                v80);
              goto LABEL_149;
            }
            buf_to_list = v42;
            v64 = "Fail in filling vreg params for %s PDOWN rc %d";
            v65 = a1 + 7560;
            v66 = 1435;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_driver_cmd",
            v66,
            v64,
            v65,
            buf_to_list);
          goto LABEL_150;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_driver_cmd",
          1410,
          "Invalid Command Type: %d",
          v39);
LABEL_47:
        buf_to_list = -22;
        goto LABEL_48;
      }
LABEL_33:
      v11 = "%s: Invalid Opcode: %d";
      v12 = a1 + 7560;
      v13 = 1;
      v14 = 1867;
LABEL_46:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        32,
        v13,
        "cam_sensor_driver_cmd",
        v14,
        v11,
        v12);
      goto LABEL_47;
    }
    if ( (*(_DWORD *)(a1 + 6544) | 4) == 4 )
    {
      v11 = "Not in right state to release %s state: %d";
      v12 = a1 + 7560;
      v13 = 2;
      v14 = 1612;
      goto LABEL_46;
    }
    if ( *(_DWORD *)(a1 + 7464) != -1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_driver_cmd",
        1621,
        "%s Device [%d] still active on link 0x%x",
        a1 + 7560);
      buf_to_list = -11;
      goto LABEL_48;
    }
    v61 = cam_sensor_power_down(a1);
    if ( (v61 & 0x80000000) == 0 )
    {
      cam_sensor_release_per_frame_resource(a1);
      cam_sensor_release_stream_rsc(a1);
      v62 = *(unsigned int *)(a1 + 7456);
      if ( (_DWORD)v62 != -1 )
      {
        buf_to_list = cam_destroy_device_hdl(v62);
        if ( (buf_to_list & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_driver_cmd",
            1652,
            "Failed in destroying %s device hdl",
            (const char *)(a1 + 7560));
        *(_DWORD *)(a1 + 6544) = 0;
        *(_QWORD *)(a1 + 7456) = -1;
        v63 = *(_DWORD **)(a1 + 3656);
        *(_DWORD *)(a1 + 7464) = -1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          3,
          "cam_sensor_driver_cmd",
          1662,
          "CAM_RELEASE_DEV Success for %s sensor_id:0x%x, slave_addr:0x%x",
          (const char *)(a1 + 7560),
          v63[2],
          *v63);
        *(_QWORD *)(a1 + 7536) = 0;
        *(_DWORD *)(a1 + 7552) = 0;
        *(_QWORD *)(a1 + 7624) = 0;
        *(_BYTE *)(a1 + 7622) = 0;
        goto LABEL_48;
      }
      v11 = "Invalid Handles: %s link hdl: %d device hdl: %d";
      v12 = a1 + 7560;
      v13 = 1;
      v14 = 1644;
      goto LABEL_46;
    }
    v67 = *(int **)(a1 + 3656);
    buf_to_list = v61;
    v68 = "Sensor Power Down failed for %s sensor_id: 0x%x, slave_addr:0x%x";
    v69 = (unsigned int)v67[2];
    v70 = *v67;
    v71 = a1 + 7560;
    v72 = 1;
    v73 = 1633;
    goto LABEL_133;
  }
  if ( v7 != 260 )
  {
    v8 = *(_DWORD *)(a2 + 8);
    v156 = nullptr;
    v157 = 0;
    v159 = 0;
    v160 = 0;
    v158 = 0u;
    v155 = 0;
    v153 = 0;
    v154 = 0;
    v152 = 0;
    if ( v8 != 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_pkt_parse",
        383,
        "Invalid Handle Type");
      buf_to_list = -22;
      goto LABEL_53;
    }
    if ( ((__int64 (__fastcall *)(__int64 *, _QWORD))inline_copy_from_user_11)(&v152, *(_QWORD *)(a2 + 16)) )
    {
      buf_to_list = -14;
      goto LABEL_53;
    }
    cpu_buf = cam_mem_get_cpu_buf(v154, &v157, &v155);
    if ( (cpu_buf & 0x80000000) != 0 )
    {
      buf_to_list = cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_pkt_parse",
        397,
        "Failed in getting the packet: %d",
        cpu_buf);
      goto LABEL_53;
    }
    if ( v155 < 0x40 || v153 >= v155 - 64 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_pkt_parse",
        407,
        "Inval cam_packet strut size: %zu, len_of_buff: %zu",
        64);
      cam_mem_put_cpu_buf(v154);
      buf_to_list = -22;
LABEL_103:
      v53 = "%s:Failed pkt parse. rc: %d";
      v54 = a1 + 7560;
      v55 = 1762;
      goto LABEL_104;
    }
    v57 = cam_packet_util_copy_pkt_to_kmd(v157 + (unsigned int)v153, &v156, v155 - v153);
    if ( v57 )
    {
      buf_to_list = v57;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_pkt_parse",
        417,
        "Copying packet to KMD failed");
      goto LABEL_281;
    }
    v75 = v156;
    v76 = *v156 & 0xFFFFFF;
    if ( v76 != 2 && v76 != 5 )
    {
      v82 = *(unsigned int *)(a1 + 7552);
      if ( (_DWORD)v82 )
      {
        v83 = *((_QWORD *)v156 + 1);
        if ( v83 <= v82 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_pkt_parse",
            429,
            "reject request %lld, last request to flush %u",
            v83,
            v82);
          buf_to_list = -53;
          goto LABEL_280;
        }
      }
    }
    if ( *((_QWORD *)v156 + 1) > (unsigned __int64)*(unsigned int *)(a1 + 7552) )
      *(_DWORD *)(a1 + 7552) = 0;
    *(_BYTE *)(a1 + 7623) = 0;
    v148 = *(_QWORD *)(a1 + 7600);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_pkt_parse",
        441,
        "Header OpCode: %d",
        *v75);
      v75 = v156;
    }
    v77 = *v75 & 0xFFFFFF;
    if ( (*v75 & 0xFFFFFF) > 4 )
    {
      if ( (*v75 & 0xFFFFFF) > 6 )
      {
        switch ( (_DWORD)v77 )
        {
          case 7:
            if ( *(_DWORD *)(a1 + 6544) <= 1u )
            {
              v78 = 549;
              goto LABEL_178;
            }
            buf_to_list = 0;
            v86 = nullptr;
            v149 = *(_QWORD *)(a1 + 7304) + 48 * (*((_QWORD *)v75 + 1) & 0x1FLL);
            if ( (debug_mdl & 0x20) == 0 || debug_priority )
              goto LABEL_203;
            v102 = "Received not ready packet: %lld req: %lld";
            v103 = debug_mdl & 0x20;
            v104 = 558;
            break;
          case 0xB:
            if ( *(_DWORD *)(a1 + 6544) <= 1u )
            {
              v78 = 565;
              goto LABEL_178;
            }
            buf_to_list = 0;
            v86 = nullptr;
            v149 = *(_QWORD *)(a1 + 7312) + 48 * (*((_QWORD *)v75 + 1) & 0x1FLL);
            if ( (debug_mdl & 0x20) == 0 || debug_priority )
            {
LABEL_203:
              v87 = 0;
              goto LABEL_213;
            }
            v102 = "Received bubble update packet: %lld req: %lld";
            v103 = debug_mdl & 0x20;
            v104 = 574;
            break;
          case 0x7F:
            if ( *(_DWORD *)(a1 + 6544) <= 1u )
            {
              v78 = 581;
LABEL_178:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                32,
                2,
                "cam_sensor_pkt_parse",
                v78,
                "Rxed Update packets without linking in state: %d");
LABEL_208:
              buf_to_list = 0;
              goto LABEL_280;
            }
            v105 = *(unsigned int *)(a1 + 7636);
            if ( (unsigned int)v105 > 0x1F )
              goto LABEL_314;
            *(_QWORD *)(a1 + 8 * v105 + 7640) = *((_QWORD *)v75 + 1);
            cam_common_inc_idx((int *)(a1 + 7636), 1, 32);
            v106 = *(_QWORD *)(a1 + 7288) + 48 * (*((_QWORD *)v156 + 1) & 0x1FLL);
            *(_QWORD *)(v106 + 24) = *((_QWORD *)v156 + 1);
            *(_DWORD *)(v106 + 16) = 1;
            v149 = v106;
            buf_to_list = ((__int64 (__fastcall *)(__int64, unsigned int *))cam_sensor_update_req_mgr)(a1, v156);
            if ( buf_to_list )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_pkt_parse",
                597,
                "Failed in adding request to req_mgr");
            goto LABEL_212;
          default:
LABEL_179:
            v90 = "Invalid Packet Header opcode: %d";
            v91 = 602;
LABEL_255:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              32,
              1,
              "cam_sensor_pkt_parse",
              v91,
              v90,
              v77);
            buf_to_list = -22;
            goto LABEL_280;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v103,
          4,
          "cam_sensor_pkt_parse",
          v104,
          v102);
LABEL_211:
        buf_to_list = 0;
LABEL_212:
        v86 = nullptr;
        v87 = 0;
LABEL_213:
        v109 = v156;
        v110 = v156[6];
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_pkt_parse",
            613,
            "cam:%d req:%llu number of command buffers:%d",
            *(_DWORD *)(a1 + 52),
            *((_QWORD *)v156 + 1),
            v156[7]);
          v111 = v156;
          if ( v156[7] )
            goto LABEL_216;
        }
        else
        {
          v111 = v156;
          if ( v156[7] )
          {
LABEL_216:
            v112 = 0;
            v113 = (__int64)v109 + v110 + 56;
            if ( v86 )
              v114 = v87;
            else
              v114 = 0;
            v147 = v114;
            do
            {
              v115 = v113 + 24LL * v112;
              if ( !*(_DWORD *)(v115 + 12) )
                goto LABEL_220;
              if ( (unsigned int)cam_packet_util_validate_cmd_desc((int *)(v113 + 24LL * v112)) )
              {
                v90 = "invalud cmd[%d] buf";
                v91 = 621;
                v77 = (unsigned int)v112;
                goto LABEL_255;
              }
              v77 = *(unsigned int *)(v115 + 20);
              if ( (debug_mdl & 0x20) != 0 && !debug_priority )
              {
                v122 = *(_DWORD *)(v115 + 20);
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x20,
                  4,
                  "cam_sensor_pkt_parse",
                  628,
                  "cam:%d cmd_buf_type:%d",
                  *(_DWORD *)(a1 + 52),
                  v77);
                v77 = (unsigned int)v122;
                if ( v122 > 1 )
                {
LABEL_226:
                  switch ( (_DWORD)v77 )
                  {
                    case 2:
                      v120 = *((_QWORD *)v156 + 1);
                      v121 = *(_QWORD *)(a1 + 7296) + 48 * (v120 & 0x1F);
                      if ( *(_DWORD *)(v121 + 16) )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                          3,
                          32,
                          2,
                          "cam_sensor_pkt_parse",
                          662,
                          "Sensor[%s] receiving duplicate deferred meta settings for req: %llu",
                          a1 + 7560);
                        v120 = *((_QWORD *)v156 + 1);
                      }
                      *(_QWORD *)(v121 + 24) = v120;
                      buf_to_list = cam_sensor_i2c_command_parser(a1 + 6480, v121, v113 + 24LL * v112, 1, v86);
                      if ( (buf_to_list & 0x80000000) != 0 )
                      {
                        v125 = 668;
                        goto LABEL_258;
                      }
                      break;
                    case 3:
                      v118 = *((_QWORD *)v156 + 1);
                      v119 = *(_QWORD *)(a1 + 7304) + 48 * (v118 & 0x1F);
                      if ( *(_DWORD *)(v119 + 16) )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                          3,
                          32,
                          2,
                          "cam_sensor_pkt_parse",
                          712,
                          "Sensor[%s] receiving duplicate frame skip meta settings for req: %llu",
                          a1 + 7560);
                        v118 = *((_QWORD *)v156 + 1);
                      }
                      *(_QWORD *)(v119 + 24) = v118;
                      buf_to_list = cam_sensor_i2c_command_parser(a1 + 6480, v119, v113 + 24LL * v112, 1, v86);
                      if ( (buf_to_list & 0x80000000) != 0 )
                      {
                        v125 = 718;
                        goto LABEL_258;
                      }
                      break;
                    case 4:
                      v116 = *((_QWORD *)v156 + 1);
                      v117 = *(_QWORD *)(a1 + 7312) + 48 * (v116 & 0x1F);
                      if ( *(_DWORD *)(v117 + 16) )
                      {
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                          3,
                          32,
                          2,
                          "cam_sensor_pkt_parse",
                          693,
                          "Sensor[%s] receiving duplicate bubble meta settings for req: %llu",
                          a1 + 7560);
                        v116 = *((_QWORD *)v156 + 1);
                      }
                      *(_QWORD *)(v117 + 24) = v116;
                      buf_to_list = cam_sensor_i2c_command_parser(a1 + 6480, v117, v113 + 24LL * v112, 1, v86);
                      if ( (buf_to_list & 0x80000000) != 0 )
                      {
                        v125 = 698;
LABEL_258:
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                          3,
                          32,
                          1,
                          "cam_sensor_pkt_parse",
                          v125,
                          "Fail parsing I2C Pkt: %d",
                          buf_to_list);
                        goto LABEL_280;
                      }
                      break;
                    default:
                      goto LABEL_256;
                  }
                  goto LABEL_220;
                }
              }
              else if ( (int)v77 > 1 )
              {
                goto LABEL_226;
              }
              if ( (_DWORD)v77 )
              {
                if ( (_DWORD)v77 != 1 )
                {
LABEL_256:
                  v90 = "invalid cmd buf type %d";
                  v91 = 725;
                  goto LABEL_255;
                }
                v123 = *((_QWORD *)v156 + 1);
                *(_QWORD *)(a1 + 7600) = v123;
                buf_to_list = cam_packet_util_process_generic_cmd_buffer(
                                (int *)(v113 + 24LL * v112),
                                cam_sensor_generic_blob_handler,
                                a1);
                if ( buf_to_list )
                {
                  if ( v123 <= 0 )
                    v124 = -(-v123 & 0x1F);
                  else
                    LODWORD(v124) = v123 & 0x1F;
                  if ( (unsigned int)v124 > 0x1FuLL )
                    goto LABEL_314;
                  *(_QWORD *)(a1 + 3664 + 88LL * (unsigned int)v124 + 16) = 0;
                }
              }
              else
              {
                buf_to_list = cam_sensor_i2c_command_parser(a1 + 6480, v149, v113 + 24LL * v112, 1, v86);
                if ( (buf_to_list & 0x80000000) != 0 )
                {
                  v125 = 635;
                  goto LABEL_258;
                }
                if ( v147 )
                {
                  mutex_lock(a1 + 7928);
                  buf_to_list = cam_sensor_util_add_read_buf_to_list(a1 + 7912, *v86);
                  if ( (buf_to_list & 0x80000000) != 0 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      32,
                      1,
                      "cam_sensor_pkt_parse",
                      644,
                      "Add read buf to list failed rc:%d",
                      buf_to_list);
                    mutex_unlock(a1 + 7928);
                    goto LABEL_280;
                  }
                  mutex_unlock(a1 + 7928);
                }
              }
LABEL_220:
              v111 = v156;
              ++v112;
            }
            while ( v112 < v156[7] );
          }
        }
        if ( (*(_BYTE *)(a1 + 7623) & 1) != 0 || (v126 = *((_QWORD *)v111 + 1)) == 0 )
        {
LABEL_272:
          v140 = *v111;
          if ( (*v111 & 0xFFFFFF) == 1 )
          {
            *(_QWORD *)(v149 + 24) = *((_QWORD *)v111 + 1);
            buf_to_list = ((__int64 (__fastcall *)(__int64))cam_sensor_update_req_mgr)(a1);
            if ( buf_to_list )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_pkt_parse",
                756,
                "Failed in adding request to req_mgr");
LABEL_280:
              cam_common_mem_free((__int64)v156);
LABEL_281:
              cam_mem_put_cpu_buf(v154);
              if ( (buf_to_list & 0x80000000) == 0 )
              {
                if ( !*(_DWORD *)(a1 + 7064) || *(_QWORD *)(a1 + 7072) )
                {
LABEL_284:
                  if ( *(_DWORD *)(a1 + 7112) && !*(_QWORD *)(a1 + 7120) )
                  {
                    v141 = 7096;
                    if ( *(_DWORD *)(a1 + 6544) == 4 )
                    {
                      delete_request(a1 + 7096);
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        32,
                        1,
                        "cam_sensor_driver_cmd",
                        1809,
                        "%s: get config setting in start state",
                        (const char *)(a1 + 7560));
                      goto LABEL_48;
                    }
                    v143 = cam_sensor_apply_settings(a1, 0, 4u);
                    *(_QWORD *)(a1 + 7120) = -1;
                    if ( (v143 & 0x80000000) != 0 )
                    {
                      buf_to_list = v143;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        32,
                        1,
                        "cam_sensor_driver_cmd",
                        1821,
                        "%s: cannot apply config settings",
                        (const char *)(a1 + 7560));
                      goto LABEL_311;
                    }
                    buf_to_list = delete_request(a1 + 7096);
                    if ( (buf_to_list & 0x80000000) != 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        32,
                        1,
                        "cam_sensor_driver_cmd",
                        1830,
                        "%s: Fail in deleting the config settings",
                        (const char *)(a1 + 7560));
                      goto LABEL_48;
                    }
                    *(_DWORD *)(a1 + 6544) = 3;
                    if ( !*(_DWORD *)(a1 + 7256) )
                      goto LABEL_290;
                  }
                  else if ( !*(_DWORD *)(a1 + 7256) )
                  {
                    goto LABEL_290;
                  }
                  v141 = 7240;
                  if ( (*(_BYTE *)(a1 + 7632) & 1) != 0
                    || (data = cam_sensor_i2c_read_data(a1 + 7240, a1 + 6480), (data & 0x80000000) == 0) )
                  {
                    buf_to_list = delete_request(a1 + 7240);
                    if ( (buf_to_list & 0x80000000) != 0 )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        32,
                        1,
                        "cam_sensor_driver_cmd",
                        1852,
                        "%s: Fail in deleting the read settings",
                        (const char *)(a1 + 7560));
                      goto LABEL_48;
                    }
LABEL_290:
                    if ( *(_BYTE *)(a1 + 7622) == 1 && *(_DWORD *)(a1 + 6544) == 3 )
                    {
                      buf_to_list = ((__int64 (__fastcall *)(__int64))cam_sensor_notify_msg_req_mgr)(a1);
                      if ( !buf_to_list )
                        *(_BYTE *)(a1 + 7622) = 0;
                    }
                    goto LABEL_48;
                  }
                  buf_to_list = data;
                  v144 = "%s: cannot read data: %d";
                  v145 = a1 + 7560;
                  v146 = 1843;
LABEL_310:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
                    3,
                    32,
                    1,
                    "cam_sensor_driver_cmd",
                    v146,
                    v144,
                    v145,
                    buf_to_list);
LABEL_311:
                  delete_request(a1 + v141);
                  goto LABEL_48;
                }
                v141 = 7048;
                buf_to_list = cam_sensor_apply_settings(a1, 0, 2u);
                if ( buf_to_list == -11 )
                {
                  if ( *(_DWORD *)(a1 + 6480) != 1 )
                  {
                    buf_to_list = -11;
                    *(_QWORD *)(a1 + 7072) = -1;
                    goto LABEL_309;
                  }
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    32,
                    2,
                    "cam_sensor_driver_cmd",
                    1780,
                    "%s: Reapplying the Init settings due to cci hw reset",
                    (const char *)(a1 + 7560));
                  usleep_range_state(1000, 1010, 2);
                  buf_to_list = cam_sensor_apply_settings(a1, 0, 2u);
                }
                *(_QWORD *)(a1 + 7072) = -1;
                if ( (buf_to_list & 0x80000000) == 0 )
                {
                  buf_to_list = delete_request(a1 + 7048);
                  if ( (buf_to_list & 0x80000000) != 0 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      32,
                      1,
                      "cam_sensor_driver_cmd",
                      1798,
                      "%s: Fail in deleting the Init settings",
                      (const char *)(a1 + 7560));
                    goto LABEL_48;
                  }
                  goto LABEL_284;
                }
LABEL_309:
                v144 = "%s: cannot apply init settings rc= %d";
                v145 = a1 + 7560;
                v146 = 1790;
                goto LABEL_310;
              }
LABEL_53:
              if ( buf_to_list == -53 )
              {
                buf_to_list = -53;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  32,
                  3,
                  "cam_sensor_driver_cmd",
                  1758,
                  "%s:Failed pkt parse. rc: %d, it has been flushed",
                  (const char *)(a1 + 7560),
                  -53);
                goto LABEL_48;
              }
              goto LABEL_103;
            }
            v111 = v156;
            v140 = *v156;
          }
          if ( (v140 & 0xFFFFFF) == 7 )
          {
            *(_QWORD *)(v149 + 24) = *((_QWORD *)v111 + 1);
            v140 = *v111;
          }
          if ( (v140 & 0xFFFFFF) == 0xB )
            *(_QWORD *)(v149 + 24) = *((_QWORD *)v111 + 1);
          goto LABEL_280;
        }
        *(_QWORD *)(a1 + 7600) = v126;
        if ( v126 <= 0 )
          v127 = -(-v126 & 0x1F);
        else
          v127 = v126 & 0x1F;
        if ( v127 <= 0x20 )
        {
          v128 = v148 <= 0 ? -(-v148 & 0x1F) : v148 & 0x1F;
          if ( v128 <= 0x20 )
          {
            v129 = (_QWORD *)(a1 + 3664 + 88 * v128);
            v130 = (_QWORD *)(a1 + 3664 + 88 * v127);
            v132 = v129[1];
            v131 = v129[2];
            *v130 = *v129;
            v130[1] = v132;
            v130[2] = v131;
            v133 = v129[6];
            v134 = v129[3];
            v135 = v129[4];
            v130[5] = v129[5];
            v130[6] = v133;
            v130[3] = v134;
            v130[4] = v135;
            v137 = v129[9];
            v136 = v129[10];
            v139 = v129[7];
            v138 = v129[8];
            v130[9] = v137;
            v130[10] = v136;
            v130[7] = v139;
            v130[8] = v138;
            goto LABEL_272;
          }
        }
LABEL_314:
        __break(0x5512u);
        JUMPOUT(0x295E78);
      }
      if ( (_DWORD)v77 == 5 )
      {
        if ( *(_DWORD *)(a1 + 7540) )
          delete_request(a1 + 7192);
        buf_to_list = 0;
        v86 = nullptr;
        v87 = 0;
        *(_DWORD *)(a1 + 7540) = 1;
        *(_QWORD *)(a1 + 7216) = 0;
        v149 = a1 + 7192;
        *(_DWORD *)(a1 + 7208) = 1;
        goto LABEL_213;
      }
      if ( (_DWORD)v77 != 6 )
        goto LABEL_179;
      v88 = debug_mdl;
      *(_QWORD *)(a1 + 7264) = 0;
      *(_DWORD *)(a1 + 7256) = 1;
      if ( (v88 & 0x20) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v88 & 0x20,
          4,
          "cam_sensor_pkt_parse",
          485,
          "number of IO configs: %d:",
          v75[9]);
        v75 = v156;
        if ( v156[9] )
          goto LABEL_165;
      }
      else if ( v75[9] )
      {
LABEL_165:
        v89 = (char *)v75 + v75[8];
        v86 = (unsigned int *)(v89 + 56);
        if ( v89 != (char *)-56LL )
        {
          buf_to_list = 0;
          v87 = 1;
          v149 = a1 + 7240;
          goto LABEL_213;
        }
        v107 = "I/O config is invalid(NULL)";
        v108 = 496;
LABEL_207:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_pkt_parse",
          v108,
          v107);
        goto LABEL_208;
      }
      v107 = "No I/O configs to process";
      v108 = 487;
      goto LABEL_207;
    }
    if ( (*v75 & 0xFFFFFF) > 1 )
    {
      if ( (_DWORD)v77 == 2 )
      {
        buf_to_list = 0;
        v86 = nullptr;
        v87 = 0;
        *(_QWORD *)(a1 + 7072) = 0;
        v149 = a1 + 7048;
        *(_DWORD *)(a1 + 7064) = 1;
        goto LABEL_213;
      }
      if ( (_DWORD)v77 == 4 )
      {
        buf_to_list = 0;
        v86 = nullptr;
        v87 = 0;
        *(_QWORD *)(a1 + 7120) = 0;
        v149 = a1 + 7096;
        *(_DWORD *)(a1 + 7112) = 1;
        goto LABEL_213;
      }
      goto LABEL_179;
    }
    if ( !(_DWORD)v77 )
    {
      if ( *(_DWORD *)(a1 + 7536) )
        delete_request(a1 + 7144);
      buf_to_list = 0;
      v86 = nullptr;
      v87 = 0;
      *(_DWORD *)(a1 + 7536) = 1;
      *(_QWORD *)(a1 + 7168) = 0;
      v149 = a1 + 7144;
      *(_DWORD *)(a1 + 7160) = 1;
      goto LABEL_213;
    }
    if ( (_DWORD)v77 != 1 )
      goto LABEL_179;
    if ( *(_DWORD *)(a1 + 6544) <= 1u )
    {
      v78 = 507;
      goto LABEL_178;
    }
    v92 = *(unsigned int *)(a1 + 7636);
    if ( (unsigned int)v92 >= 0x20 )
      goto LABEL_314;
    *(_QWORD *)(a1 + 8 * v92 + 7640) = *((_QWORD *)v75 + 1);
    cam_common_inc_idx((int *)(a1 + 7636), 1, 32);
    v93 = *((_QWORD *)v156 + 1);
    v149 = *(_QWORD *)(a1 + 7288) + 48 * (v93 & 0x1F);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_pkt_parse",
        519,
        "Received Packet: %lld req: %lld",
        v93 & 0x1F,
        v93);
    if ( *(_DWORD *)(v149 + 16) != 1 )
      goto LABEL_211;
    v94 = 0;
    v95 = *(_QWORD *)(a1 + 7304);
    buf_to_list = 0;
    v96 = 48 * (*((_QWORD *)v156 + 1) & 0x1FLL);
    v97 = *(_QWORD *)(a1 + 7296) + v96;
    *(_QWORD *)&v158 = *(_QWORD *)(a1 + 7288) + v96;
    *((_QWORD *)&v158 + 1) = v97;
    v98 = v95 + v96;
    v99 = *(_QWORD *)(a1 + 7312) + v96;
    v159 = v98;
    v160 = v99;
    while ( 1 )
    {
      v100 = *((_QWORD *)&v158 + v94);
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      {
        v101 = *((_QWORD *)&v158 + v94);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_pkt_parse",
          533,
          "setting list idx:%d, request_id:%lld, is_settings_valid:%d",
          v94,
          *(_QWORD *)(v100 + 24),
          *(_DWORD *)(v100 + 16));
        v100 = v101;
        if ( *(_QWORD *)(v101 + 24) )
        {
LABEL_190:
          if ( *(_DWORD *)(v100 + 16) == 1 )
          {
            *(_QWORD *)(v100 + 24) = 0;
            buf_to_list = delete_request(v100);
            if ( (buf_to_list & 0x80000000) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_pkt_parse",
                539,
                "Delete request Failed during parse pkt rc:%d",
                buf_to_list);
          }
        }
      }
      else if ( *(_QWORD *)(v100 + 24) )
      {
        goto LABEL_190;
      }
      if ( ++v94 == 4 )
        goto LABEL_212;
    }
  }
  if ( *(_BYTE *)(a1 + 7621) != 1 )
  {
    buf_to_list = cam_sensor_stream_off(a1);
    goto LABEL_48;
  }
  *(_BYTE *)(a1 + 7620) = 1;
  buf_to_list = 0;
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    goto LABEL_48;
  v15 = "Ignore stop dev cmd, sensor %s already in streamed off state";
  v17 = debug_mdl & 0x20;
  v16 = a1 + 7560;
  v18 = 4;
  v19 = 1743;
LABEL_23:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    v17,
    v18,
    "cam_sensor_driver_cmd",
    v19,
    v15,
    v16);
  buf_to_list = 0;
LABEL_48:
  mutex_lock(a1 + 7928);
  cam_sensor_util_release_read_buf(a1 + 7912);
  mutex_unlock(a1 + 7928);
LABEL_49:
  mutex_unlock(a1 + 3608);
LABEL_50:
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) != v162 )
    JUMPOUT(0x2954E8);
  return buf_to_list;
}
