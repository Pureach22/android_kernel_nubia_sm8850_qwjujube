__int64 __fastcall dp_audio_info_setup(__int64 a1, __int64 a2)
{
  unsigned __int64 data; // x0
  unsigned __int64 v4; // x19
  __int64 v5; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v8; // x0
  __int64 v9; // x9
  void (*v10)(void); // x8
  void (*v11)(void); // x8
  __int64 v12; // x20
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x0
  unsigned int v15; // w21
  __int64 v16; // x0
  unsigned __int64 v17; // x23
  void (__fastcall *v18)(_QWORD); // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x0
  int v21; // w21
  __int64 v22; // x0
  void (__fastcall *v23)(_QWORD); // x8
  void (__fastcall *v24)(_QWORD); // x9
  int v25; // w8
  int v26; // w13
  unsigned int v27; // w11
  int v28; // w9
  int v29; // w12
  unsigned int v30; // w14
  unsigned __int8 v31; // w13
  unsigned __int8 v32; // w17
  unsigned int v33; // w15
  __int64 v34; // x0
  int v35; // w24
  int v36; // w21
  __int64 v37; // x0
  void (__fastcall *v38)(_QWORD); // x9
  __int64 v39; // x20
  __int64 (__fastcall *v40)(_QWORD); // x9
  __int64 v41; // x0
  int v42; // w21
  __int64 v43; // x0
  void (__fastcall *v44)(_QWORD); // x9
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x0
  int v47; // w21
  __int64 v48; // x0
  void (__fastcall *v49)(_QWORD); // x8
  __int64 (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  int v52; // w21
  __int64 v53; // x0
  void (__fastcall *v54)(_QWORD); // x8
  __int64 v55; // x20
  __int64 (__fastcall *v56)(_QWORD); // x9
  __int64 v57; // x0
  unsigned int v58; // w21
  __int64 v59; // x0
  void (__fastcall *v60)(_QWORD); // x9
  __int64 (__fastcall *v61)(_QWORD); // x8
  __int64 v62; // x0
  int v63; // w21
  __int64 v64; // x0
  void (__fastcall *v65)(_QWORD); // x8
  __int64 (__fastcall *v66)(_QWORD); // x8
  __int64 v67; // x0
  int v68; // w24
  __int64 v69; // x0
  void (__fastcall *v70)(_QWORD); // x9
  __int64 v71; // x20
  __int64 (__fastcall *v72)(_QWORD); // x9
  __int64 v73; // x0
  unsigned int v74; // w21
  __int64 v75; // x0
  void (__fastcall *v76)(_QWORD); // x9
  __int64 (__fastcall *v77)(_QWORD); // x8
  __int64 v78; // x0
  int v79; // w21
  __int64 v80; // x0
  void (__fastcall *v81)(_QWORD); // x8
  __int64 (__fastcall *v82)(_QWORD); // x8
  __int64 v83; // x0
  int v84; // w21
  __int64 v85; // x0
  void (__fastcall *v86)(_QWORD); // x8
  __int64 v87; // x20
  __int64 (__fastcall *v88)(_QWORD); // x9
  __int64 v89; // x0
  int v90; // w21
  __int64 v91; // x0
  void (__fastcall *v92)(_QWORD); // x9
  __int64 (__fastcall *v93)(_QWORD); // x8
  __int64 v94; // x0
  int v95; // w21
  __int64 v96; // x0
  void (__fastcall *v97)(_QWORD); // x8
  __int64 v98; // x0
  int v99; // w8
  int v100; // w8
  __int64 v101; // x0
  __int64 v102; // x20
  __int64 v103; // x0
  unsigned __int64 v104; // x21
  __int64 (*v105)(void); // x9
  __int64 v106; // x0
  __int64 v107; // x20
  __int64 (*v108)(void); // x8
  void (__fastcall *v109)(_QWORD); // x8
  __int64 v110; // x0
  __int64 v111; // x0
  unsigned __int64 v112; // x19
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0

  data = dp_audio_get_data();
  v4 = data;
  if ( data < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(_QWORD *)(data + 136);
    if ( v5 && *(_QWORD *)(v5 + 1176) )
    {
      if ( *(_BYTE *)(data + 360) == 1 )
      {
        ipc_log_context = get_ipc_log_context(data);
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(ipc_log_context, "[d][%-4d]TUI session active\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TUI session active\n", *(unsigned int *)(StatusReg + 1800));
LABEL_130:
        LODWORD(v4) = 0;
        return (unsigned int)v4;
      }
      v8 = mutex_lock(data + 304);
      v9 = *(_QWORD *)(v4 + 136);
      *(_DWORD *)(v4 + 156) = *(_DWORD *)(a2 + 4);
      if ( *(_DWORD *)(v9 + 912) >= 2u )
      {
        v114 = get_ipc_log_context(v8);
        ipc_log_string(
          v114,
          "[e][%-4d]invalid stream id: %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(*(_QWORD *)(v4 + 136) + 912LL));
        printk(&unk_2189B2, "dp_audio_info_setup");
        mutex_unlock(v4 + 304);
        LODWORD(v4) = -22;
        return (unsigned int)v4;
      }
      if ( *(_DWORD *)(v4 + 148) )
      {
        *(_DWORD *)(*(_QWORD *)(v4 + 16) + 12LL) = 0;
        v10 = *(void (**)(void))(*(_QWORD *)(v4 + 16) + 40LL);
        if ( *((_DWORD *)v10 - 1) != 1586062320 )
          __break(0x8228u);
        v10();
        if ( *(_DWORD *)(*(_QWORD *)(v4 + 136) + 912LL) == 1 )
        {
          *(_DWORD *)(*(_QWORD *)(v4 + 16) + 12LL) = 1;
          v11 = *(void (**)(void))(*(_QWORD *)(v4 + 16) + 40LL);
          if ( *((_DWORD *)v11 - 1) != 1586062320 )
            __break(0x8228u);
          v11();
        }
        v12 = *(_QWORD *)(v4 + 16);
        v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 56);
        *(_QWORD *)v12 = 0;
        if ( *((_DWORD *)v13 - 1) != 1586062320 )
          __break(0x8228u);
        v14 = v13(v12);
        v15 = *(unsigned __int16 *)(v12 + 8) | 0xCE020000;
        v16 = get_ipc_log_context(v14);
        v17 = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v16,
          "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v15,
          206);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v15,
            206);
        v18 = *(void (__fastcall **)(_QWORD))(v12 + 48);
        *(_QWORD *)v12 = 0;
        *(_DWORD *)(v12 + 8) = v15;
        if ( *((_DWORD *)v18 - 1) != 1586062320 )
          __break(0x8228u);
        v18(v12);
        v19 = *(__int64 (__fastcall **)(_QWORD))(v12 + 56);
        *(_QWORD *)v12 = 0x100000000LL;
        if ( *((_DWORD *)v19 - 1) != 1586062320 )
          __break(0x8228u);
        v20 = v19(v12);
        v21 = *(unsigned __int16 *)(v12 + 10) << 16;
        v22 = get_ipc_log_context(v20);
        ipc_log_string(
          v22,
          "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v21,
          0);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v21,
            0);
        v23 = *(void (__fastcall **)(_QWORD))(v12 + 48);
        *(_QWORD *)v12 = 0x100000000LL;
        *(_DWORD *)(v12 + 8) = v21;
        if ( *((_DWORD *)v23 - 1) != 1586062320 )
          __break(0x8228u);
        v23(v12);
        v24 = *(void (__fastcall **)(_QWORD))(v12 + 56);
        *(_QWORD *)v12 = 0x200000000LL;
        if ( *((_DWORD *)v24 - 1) != 1586062320 )
          __break(0x8229u);
        v24(v12);
        v25 = 0;
        LOBYTE(v26) = 0;
        v27 = *(_DWORD *)(v4 + 156) - 1;
        v28 = 0;
        if ( v27 <= 0xFF )
          v29 = 2;
        else
          v29 = 8;
        do
        {
          v30 = v27 >> v25;
          --v29;
          v25 += 4;
          v31 = v30 & 0xF ^ v26;
          v32 = (v31 >> 3) ^ v31;
          v33 = v31;
          v34 = v32 & 1
              | (4 * (((v31 >> 2) ^ (v31 >> 1)) & 1)) & 0xF5
              | (8 * (((v31 >> 2) ^ (v31 >> 3)) & 1))
              | (2 * ((v32 ^ (v31 >> 1)) & 1u));
          LOBYTE(v30) = 2 * v31;
          v26 = v34 ^ v28;
          v28 = v30 & 0xC | (v33 >> 3) & 1 | (2 * (v32 & 1));
        }
        while ( v29 );
        v35 = v26 | (16 * v28);
        v36 = *(unsigned __int16 *)(v12 + 8) | (v27 << 16) | (v35 << 24);
        v37 = get_ipc_log_context(v34);
        ipc_log_string(
          v37,
          "[d][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v36,
          (unsigned __int8)v35);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v36,
            (unsigned __int8)v35);
        v38 = *(void (__fastcall **)(_QWORD))(v12 + 48);
        *(_QWORD *)v12 = 0x200000000LL;
        *(_DWORD *)(v12 + 8) = v36;
        if ( *((_DWORD *)v38 - 1) != 1586062320 )
          __break(0x8229u);
        v38(v12);
        v39 = *(_QWORD *)(v4 + 16);
        v40 = *(__int64 (__fastcall **)(_QWORD))(v39 + 56);
        *(_QWORD *)v39 = 1;
        if ( *((_DWORD *)v40 - 1) != 1586062320 )
          __break(0x8229u);
        v41 = v40(v39);
        v42 = *(unsigned __int16 *)(v39 + 8) | 0x67010000;
        v43 = get_ipc_log_context(v41);
        ipc_log_string(
          v43,
          "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v42,
          103);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v42,
            103);
        v44 = *(void (__fastcall **)(_QWORD))(v39 + 48);
        *(_QWORD *)v39 = 1;
        *(_DWORD *)(v39 + 8) = v42;
        if ( *((_DWORD *)v44 - 1) != 1586062320 )
          __break(0x8229u);
        v44(v39);
        v45 = *(__int64 (__fastcall **)(_QWORD))(v39 + 56);
        *(_QWORD *)v39 = 0x100000001LL;
        if ( *((_DWORD *)v45 - 1) != 1586062320 )
          __break(0x8228u);
        v46 = v45(v39);
        v47 = (*(unsigned __int16 *)(v39 + 10) << 16) | 0x3517;
        v48 = get_ipc_log_context(v46);
        ipc_log_string(
          v48,
          "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v47,
          53);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v47,
            53);
        v49 = *(void (__fastcall **)(_QWORD))(v39 + 48);
        *(_QWORD *)v39 = 0x100000001LL;
        *(_DWORD *)(v39 + 8) = v47;
        if ( *((_DWORD *)v49 - 1) != 1586062320 )
          __break(0x8228u);
        v49(v39);
        v50 = *(__int64 (__fastcall **)(_QWORD))(v39 + 56);
        *(_QWORD *)v39 = 0x200000001LL;
        if ( *((_DWORD *)v50 - 1) != 1586062320 )
          __break(0x8228u);
        v51 = v50(v39);
        v52 = *(unsigned __int16 *)(v39 + 8) | 0x33440000;
        v53 = get_ipc_log_context(v51);
        ipc_log_string(
          v53,
          "[d][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v52,
          51);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v52,
            51);
        v54 = *(void (__fastcall **)(_QWORD))(v39 + 48);
        *(_QWORD *)v39 = 0x200000001LL;
        *(_DWORD *)(v39 + 8) = v52;
        if ( *((_DWORD *)v54 - 1) != 1586062320 )
          __break(0x8228u);
        v54(v39);
        v55 = *(_QWORD *)(v4 + 16);
        v56 = *(__int64 (__fastcall **)(_QWORD))(v55 + 56);
        *(_QWORD *)v55 = 2;
        if ( *((_DWORD *)v56 - 1) != 1586062320 )
          __break(0x8229u);
        v57 = v56(v55);
        v58 = *(unsigned __int16 *)(v55 + 8) | 0x84840000;
        v59 = get_ipc_log_context(v57);
        ipc_log_string(
          v59,
          "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v58,
          132);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v58,
            132);
        v60 = *(void (__fastcall **)(_QWORD))(v55 + 48);
        *(_QWORD *)v55 = 2;
        *(_DWORD *)(v55 + 8) = v58;
        if ( *((_DWORD *)v60 - 1) != 1586062320 )
          __break(0x8229u);
        v60(v55);
        v61 = *(__int64 (__fastcall **)(_QWORD))(v55 + 56);
        *(_QWORD *)v55 = 0x100000002LL;
        if ( *((_DWORD *)v61 - 1) != 1586062320 )
          __break(0x8228u);
        v62 = v61(v55);
        v63 = (*(unsigned __int16 *)(v55 + 10) << 16) | 0xD71B;
        v64 = get_ipc_log_context(v62);
        ipc_log_string(
          v64,
          "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v63,
          215);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v63,
            215);
        v65 = *(void (__fastcall **)(_QWORD))(v55 + 48);
        *(_QWORD *)v55 = 0x100000002LL;
        *(_DWORD *)(v55 + 8) = v63;
        if ( *((_DWORD *)v65 - 1) != 1586062320 )
          __break(0x8228u);
        v65(v55);
        v66 = *(__int64 (__fastcall **)(_QWORD))(v55 + 56);
        *(_QWORD *)v55 = 0x200000002LL;
        if ( *((_DWORD *)v66 - 1) != 1586062320 )
          __break(0x8228u);
        v67 = v66(v55);
        v68 = *(unsigned __int16 *)(v55 + 8);
        v69 = get_ipc_log_context(v67);
        ipc_log_string(
          v69,
          "[d][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          68,
          51);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            68,
            51);
        v70 = *(void (__fastcall **)(_QWORD))(v55 + 48);
        *(_QWORD *)v55 = 0x200000002LL;
        *(_DWORD *)(v55 + 8) = v68 | 0x33440000;
        if ( *((_DWORD *)v70 - 1) != 1586062320 )
          __break(0x8229u);
        v70(v55);
        v71 = *(_QWORD *)(v4 + 16);
        v72 = *(__int64 (__fastcall **)(_QWORD))(v71 + 56);
        *(_QWORD *)v71 = 3;
        if ( *((_DWORD *)v72 - 1) != 1586062320 )
          __break(0x8229u);
        v73 = v72(v71);
        v74 = *(unsigned __int16 *)(v71 + 8) | 0xD8050000;
        v75 = get_ipc_log_context(v73);
        ipc_log_string(
          v75,
          "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v74,
          216);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v74,
            216);
        v76 = *(void (__fastcall **)(_QWORD))(v71 + 48);
        *(_QWORD *)v71 = 3;
        *(_DWORD *)(v71 + 8) = v74;
        if ( *((_DWORD *)v76 - 1) != 1586062320 )
          __break(0x8229u);
        v76(v71);
        v77 = *(__int64 (__fastcall **)(_QWORD))(v71 + 56);
        *(_QWORD *)v71 = 0x100000003LL;
        if ( *((_DWORD *)v77 - 1) != 1586062320 )
          __break(0x8228u);
        v78 = v77(v71);
        v79 = (*(unsigned __int16 *)(v71 + 10) << 16) | 0x4B0F;
        v80 = get_ipc_log_context(v78);
        ipc_log_string(
          v80,
          "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v79,
          75);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v79,
            75);
        v81 = *(void (__fastcall **)(_QWORD))(v71 + 48);
        *(_QWORD *)v71 = 0x100000003LL;
        *(_DWORD *)(v71 + 8) = v79;
        if ( *((_DWORD *)v81 - 1) != 1586062320 )
          __break(0x8228u);
        v81(v71);
        v82 = *(__int64 (__fastcall **)(_QWORD))(v71 + 56);
        *(_QWORD *)v71 = 0x200000003LL;
        if ( *((_DWORD *)v82 - 1) != 1586062320 )
          __break(0x8228u);
        v83 = v82(v71);
        v84 = *(unsigned __int16 *)(v71 + 8);
        v85 = get_ipc_log_context(v83);
        ipc_log_string(
          v85,
          "[d][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v84,
          0);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v84,
            0);
        v86 = *(void (__fastcall **)(_QWORD))(v71 + 48);
        *(_QWORD *)v71 = 0x200000003LL;
        *(_DWORD *)(v71 + 8) = v84;
        if ( *((_DWORD *)v86 - 1) != 1586062320 )
          __break(0x8228u);
        v86(v71);
        v87 = *(_QWORD *)(v4 + 16);
        v88 = *(__int64 (__fastcall **)(_QWORD))(v87 + 56);
        *(_QWORD *)v87 = 4;
        if ( *((_DWORD *)v88 - 1) != 1586062320 )
          __break(0x8229u);
        v89 = v88(v87);
        v90 = *(unsigned __int16 *)(v87 + 8) | 0x71060000;
        v91 = get_ipc_log_context(v89);
        ipc_log_string(
          v91,
          "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v90,
          113);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v90,
            113);
        v92 = *(void (__fastcall **)(_QWORD))(v87 + 48);
        *(_QWORD *)v87 = 4;
        *(_DWORD *)(v87 + 8) = v90;
        if ( *((_DWORD *)v92 - 1) != 1586062320 )
          __break(0x8229u);
        v92(v87);
        v93 = *(__int64 (__fastcall **)(_QWORD))(v87 + 56);
        *(_QWORD *)v87 = 0x100000004LL;
        if ( *((_DWORD *)v93 - 1) != 1586062320 )
          __break(0x8228u);
        v94 = v93(v87);
        v95 = (*(unsigned __int16 *)(v87 + 10) << 16) | 0x4B0F;
        v96 = get_ipc_log_context(v94);
        ipc_log_string(
          v96,
          "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(v17 + 1800),
          v95,
          75);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
            *(_DWORD *)(v17 + 1800),
            v95,
            75);
        v97 = *(void (__fastcall **)(_QWORD))(v87 + 48);
        *(_QWORD *)v87 = 0x100000004LL;
        *(_DWORD *)(v87 + 8) = v95;
        if ( *((_DWORD *)v97 - 1) != 1586062320 )
          __break(0x8228u);
        v97(v87);
      }
      else
      {
        v115 = get_ipc_log_context(v8);
        ipc_log_string(v115, "[w][%-4d]session inactive\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_26145F, "dp_audio_setup_sdp");
      }
      v98 = *(_QWORD *)(v4 + 16);
      if ( !*(_DWORD *)(v4 + 148) )
      {
        v116 = get_ipc_log_context(v98);
        ipc_log_string(v116, "[w][%-4d]session inactive\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        v106 = printk(&unk_26145F, "dp_audio_setup_acr");
LABEL_121:
        v107 = *(_QWORD *)(v4 + 16);
        *(_BYTE *)(v4 + 152) = 1;
        if ( *(_DWORD *)(v4 + 148) )
        {
          *(_DWORD *)(v107 + 8) = 1;
          v108 = *(__int64 (**)(void))(*(_QWORD *)(v4 + 136) + 1176LL);
          if ( *((_DWORD *)v108 - 1) != -1505889699 )
            __break(0x8228u);
          if ( (v108() & 1) != 0 )
          {
            v109 = *(void (__fastcall **)(_QWORD))(v107 + 24);
            if ( *((_DWORD *)v109 - 1) != 1586062320 )
              __break(0x8228u);
            v109(v107);
          }
        }
        else
        {
          v117 = get_ipc_log_context(v106);
          ipc_log_string(v117, "[w][%-4d]session inactive. enable=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 1);
          printk(&unk_21C490, "dp_audio_enable");
        }
        v110 = mutex_unlock(v4 + 304);
        v111 = get_ipc_log_context(v110);
        v112 = _ReadStatusReg(SP_EL0);
        ipc_log_string(v111, "[d][%-4d]audio stream configured\n", *(_DWORD *)(v112 + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]audio stream configured\n", *(unsigned int *)(v112 + 1800));
        goto LABEL_130;
      }
      v99 = *(_DWORD *)(v4 + 356);
      if ( v99 > 19 )
      {
        if ( v99 == 20 )
        {
          v100 = 2;
          goto LABEL_118;
        }
        if ( v99 == 30 )
        {
          v100 = 3;
          goto LABEL_118;
        }
      }
      else
      {
        if ( v99 == 6 )
        {
          v100 = 0;
          goto LABEL_118;
        }
        if ( v99 == 10 )
        {
          v100 = 1;
LABEL_118:
          v105 = *(__int64 (**)(void))(v98 + 32);
          *(_DWORD *)(v98 + 8) = v100;
          if ( *((_DWORD *)v105 - 1) != 1586062320 )
            __break(0x8229u);
          v106 = v105();
          goto LABEL_121;
        }
      }
      v102 = *(_QWORD *)(v4 + 16);
      v103 = get_ipc_log_context(v98);
      v104 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v103, "[d][%-4d]Unknown link rate\n", *(_DWORD *)(v104 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Unknown link rate\n", *(_DWORD *)(v104 + 1800));
      v100 = 0;
      v98 = v102;
      goto LABEL_118;
    }
    v101 = get_ipc_log_context(data);
    ipc_log_string(v101, "[e][%-4d]invalid panel data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_2760FF, "dp_audio_info_setup");
    LODWORD(v4) = -22;
  }
  return (unsigned int)v4;
}
