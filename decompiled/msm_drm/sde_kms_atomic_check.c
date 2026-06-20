__int64 __fastcall sde_kms_atomic_check(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  _QWORD *v10; // x28
  __int64 v11; // x8
  _QWORD *i; // x9
  __int64 v13; // x11
  int v14; // w26
  __int64 v15; // x23
  __int64 v16; // x22
  __int64 v17; // x25
  __int64 v18; // x24
  char v19; // w27
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x19
  __int64 v24; // x20
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x9
  char v28; // w0
  char v29; // w24
  int v30; // w8
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  _DWORD *v34; // x8
  unsigned int v35; // w0
  __int64 v36; // x0
  int v37; // w4
  int v38; // w5
  int v39; // w7
  int v40; // w0
  __int64 v41; // x10
  __int64 v42; // x9
  __int64 v43; // x14
  __int64 v44; // x13
  _DWORD *v45; // x22
  __int64 v46; // x0
  unsigned int v47; // w27
  __int64 v48; // x26
  _QWORD *v49; // x10
  __int64 v50; // x8
  unsigned int v51; // w19
  __int64 v52; // x10
  _QWORD *v53; // x9
  _QWORD *v54; // x10
  _DWORD *v55; // x23
  unsigned int v56; // w28
  __int64 v57; // x11
  _QWORD *v58; // x12
  __int64 *v59; // x9
  __int64 v60; // x10
  unsigned int v61; // w19
  char v62; // w12
  __int64 v63; // x9
  __int64 *v64; // x10
  __int64 v65; // x6
  __int64 v66; // x20
  int v67; // w5
  int v68; // w6
  unsigned int v69; // w3
  __int64 v70; // x20
  char v71; // w23
  int v72; // w0
  __int64 (__fastcall *v73)(_QWORD *); // x8
  int v74; // w0
  _DWORD *v75; // x8
  __int64 (__fastcall *v76)(_QWORD); // x8
  __int64 v77; // x0
  __int64 v78; // x19
  __int64 v79; // x9
  __int64 v80; // x8
  __int64 v81; // x9
  __int64 v82; // x10
  int v83; // w4
  __int64 v84; // x20
  __int64 v85; // x11
  __int64 v86; // x8
  __int64 v87; // x19
  __int64 v88; // x20
  __int64 v89; // x23
  _QWORD *v90; // x26
  int v91; // w22
  unsigned __int8 v92; // w27
  int v93; // w25
  __int64 v94; // x9
  _QWORD *v95; // x24
  __int64 v96; // x0
  _QWORD *v97; // x28
  _QWORD *v98; // x24
  _QWORD *v99; // x8
  int v100; // w19
  int v101; // w27
  unsigned __int8 v102; // w20
  __int64 v103; // x8
  int v104; // w19
  __int64 v105; // x8
  __int64 v106; // x20
  int v107; // w22
  __int64 v108; // x9
  _DWORD *v109; // x26
  __int64 v110; // x8
  __int64 *v111; // x27
  __int64 v112; // x28
  unsigned int v113; // w22
  __int64 v114; // x8
  unsigned int v115; // w20
  void (__fastcall *v116)(_QWORD); // x8
  unsigned int v117; // w19
  __int64 v118; // x0
  int v119; // w19
  __int64 v120; // [xsp+10h] [xbp-50h]
  __int64 v121; // [xsp+18h] [xbp-48h]
  __int64 v122; // [xsp+20h] [xbp-40h]
  char v123; // [xsp+34h] [xbp-2Ch]
  char v124; // [xsp+38h] [xbp-28h]
  __int64 v125; // [xsp+38h] [xbp-28h]
  unsigned __int8 v126; // [xsp+38h] [xbp-28h]
  _QWORD *v127; // [xsp+40h] [xbp-20h]
  _DWORD v128[5]; // [xsp+4Ch] [xbp-14h] BYREF

  result = 4294967274LL;
  *(_QWORD *)&v128[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_208;
  v5 = a1[17];
  _ReadStatusReg(SP_EL0);
  v127 = a1;
  if ( v5 )
  {
    v6 = *(_QWORD *)(v5 + 56);
    if ( v6 )
    {
      v7 = *(_QWORD *)(v6 + 8);
      if ( v7 )
      {
        if ( *(_QWORD *)(v7 + 2128) && *(_BYTE *)(v7 + 2136) == 1 )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "suspended, skip atomic_check\n");
          result = 4294967280LL;
          goto LABEL_208;
        }
      }
    }
  }
  v8 = a1[798];
  v9 = a1[19];
  if ( v8 )
    v10 = (_QWORD *)(v8 + 72);
  else
    v10 = nullptr;
  if ( v9 )
  {
    v124 = *(_BYTE *)(v9 + 20120);
    if ( !v10 )
      goto LABEL_157;
  }
  else
  {
    v124 = 0;
    if ( !v10 )
      goto LABEL_157;
  }
  if ( !v10[9] || !v10[2] || !*v10 )
  {
    v51 = -22;
    goto LABEL_100;
  }
  v11 = *(_QWORD *)(a2 + 8);
  for ( i = *(_QWORD **)(v11 + 864); i != (_QWORD *)(v11 + 864); i = (_QWORD *)*i )
  {
    v13 = i[249];
    if ( v13 && *(_QWORD *)(v13 + 1568) == 1 )
    {
      v14 = 1;
      goto LABEL_28;
    }
  }
  v14 = 0;
LABEL_28:
  if ( *(int *)(v11 + 860) < 1 )
    goto LABEL_157;
  v15 = 0;
  v16 = 0;
  LODWORD(v17) = 0;
  LODWORD(v18) = 0;
  v19 = 0;
  v122 = v5;
  v123 = 0;
  do
  {
    v21 = *(_QWORD *)(a2 + 32);
    if ( !*(_QWORD *)(v21 + v15) )
      goto LABEL_31;
    v22 = v21 + v15;
    v23 = *(_QWORD *)(v22 + 16);
    v24 = *(_QWORD *)(v22 + 24);
    if ( (*(_BYTE *)(v24 + 9) & 1) == 0 )
    {
      if ( *(_BYTE *)(v23 + 9) != 1 )
        goto LABEL_31;
      if ( (v124 & 1) != 0 && v23 && v24 )
      {
        v25 = v127[798];
        if ( v25 )
        {
          mutex_lock(v25);
          v26 = v127[798];
          if ( v26 )
          {
            v27 = *(__int64 (__fastcall **)(_QWORD))(v26 + 88);
            if ( v27 )
            {
              if ( *((_DWORD *)v27 - 1) != 1370937740 )
                __break(0x8229u);
              v28 = v27(v127);
              v26 = v127[798];
              v29 = v28;
              if ( !v26 )
              {
LABEL_78:
                v37 = *(unsigned __int8 *)(v23 + 9);
                v38 = *(unsigned __int8 *)(v24 + 9);
                v39 = 0;
                if ( v37 == 1 && (v38 & 1) == 0 && (v29 & 1) != 0 )
                {
                  if ( *(_DWORD *)(v24 + 1568) == 1 )
                    goto LABEL_35;
                  v40 = msm_property_set_property(*(_QWORD *)v24 + 2600LL, v24 + 768, 24, 1);
                  v37 = *(unsigned __int8 *)(v23 + 9);
                  v38 = *(unsigned __int8 *)(v24 + 9);
                  v39 = v40;
                }
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_kms_trusted_release_resources",
                  3516,
                  -1,
                  v37,
                  v38,
                  v29 & 1,
                  v39,
                  239);
LABEL_35:
                v18 = *(_QWORD *)(v24 + 1568);
                if ( v23 )
                  goto LABEL_36;
                goto LABEL_49;
              }
            }
            else
            {
              v29 = 1;
            }
            mutex_unlock(v26);
            goto LABEL_78;
          }
        }
        v29 = 1;
        goto LABEL_78;
      }
    }
    if ( v24 )
      goto LABEL_35;
    LODWORD(v18) = 0;
    if ( v23 )
    {
LABEL_36:
      v17 = *(_QWORD *)(v23 + 1568);
      goto LABEL_50;
    }
LABEL_49:
    LODWORD(v17) = 0;
LABEL_50:
    if ( (unsigned int)v17 | (unsigned int)v18 )
      v30 = 1;
    else
      v30 = v14;
    if ( v30 != 1 )
    {
      LODWORD(v18) = 0;
      LODWORD(v17) = 0;
      goto LABEL_31;
    }
    if ( (v19 & 1) == 0 )
    {
      v31 = v127[798];
      if ( v31
        && (mutex_lock(v31), (v32 = v127[798]) != 0)
        && (v33 = *(__int64 (__fastcall **)(_QWORD))(v32 + 88)) != nullptr )
      {
        if ( *((_DWORD *)v33 - 1) != 1370937740 )
          __break(0x8228u);
        v123 = v33(v127);
      }
      else
      {
        v123 = 1;
      }
    }
    v34 = (_DWORD *)v10[9];
    if ( *(v34 - 1) != -258417003 )
      __break(0x8228u);
    v35 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD))v34)(v127, (unsigned int)v17, (unsigned int)v18);
    if ( v35 )
    {
      v51 = v35;
      printk(&unk_27736B, "sde_kms_check_vm_request");
      v118 = v127[798];
      if ( v118 )
        mutex_unlock(v118);
      goto LABEL_100;
    }
    if ( (_DWORD)v17 != 2 || (_DWORD)v18 )
      goto LABEL_71;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "VM transition valid; ignore further checks\n");
    if ( (v19 & 1) != 0 )
    {
      LODWORD(v18) = 0;
      LODWORD(v17) = 2;
LABEL_71:
      v19 = 1;
      goto LABEL_31;
    }
    v36 = v127[798];
    if ( v36 )
      mutex_unlock(v36);
    v19 = 0;
    LODWORD(v18) = 0;
    LODWORD(v17) = 2;
LABEL_31:
    ++v16;
    v15 += 56;
    v20 = *(int *)(*(_QWORD *)(a2 + 8) + 860LL);
  }
  while ( v16 < v20 );
  a1 = v127;
  v5 = v122;
  if ( (v19 & 1) != 0 )
  {
    v41 = v127[798];
    v42 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
    v43 = v127[19];
    if ( v41 )
      v44 = v41 + 72;
    else
      v44 = 0;
    if ( (_DWORD)v20 )
    {
      v45 = nullptr;
      v46 = 0;
      v47 = 0;
      LODWORD(v48) = 0;
      v49 = (_QWORD *)(*(_QWORD *)(a2 + 32) + 16LL);
      do
      {
        if ( *(v49 - 2) && ((v50 = v49[1], (*(_BYTE *)(v50 + 9) & 1) != 0) || *(_BYTE *)(*v49 + 9LL) == 1) )
        {
          if ( v50 )
            v48 = *(_QWORD *)(v50 + 1504);
          else
            LODWORD(v48) = 0;
          ++v47;
          v45 = (_DWORD *)*(v49 - 2);
        }
        else
        {
          v50 = v46;
        }
        --v42;
        v49 += 7;
        v46 = v50;
      }
      while ( v42 );
    }
    else
    {
      LODWORD(v48) = 0;
      v47 = 0;
      v50 = 0;
      v45 = nullptr;
    }
    v52 = v127[17];
    v53 = *(_QWORD **)(v52 + 864);
    v54 = (_QWORD *)(v52 + 864);
    if ( v53 == v54 )
    {
      v56 = 0;
      v55 = nullptr;
      v125 = v44;
      if ( !v45 )
        goto LABEL_115;
    }
    else
    {
      v55 = nullptr;
      v56 = 0;
      do
      {
        v57 = v53[249];
        v58 = v53 - 2;
        v53 = (_QWORD *)*v53;
        LODWORD(v57) = *(unsigned __int8 *)(v57 + 9);
        v56 += v57;
        if ( (_DWORD)v57 )
          v55 = v58;
      }
      while ( v53 != v54 );
      v125 = v44;
      if ( !v45 )
      {
LABEL_115:
        v61 = 0;
        goto LABEL_116;
      }
    }
    v59 = *(__int64 **)(*(_QWORD *)v45 + 816LL);
    v60 = *(_QWORD *)v45 + 816LL;
    if ( v59 == (__int64 *)v60 )
      goto LABEL_115;
    v61 = 0;
    do
    {
      v62 = *((_DWORD *)v59 + 15);
      v59 = (__int64 *)*v59;
      v61 += (*(_DWORD *)(v50 + 20) >> v62) & 1;
    }
    while ( v59 != (__int64 *)v60 );
LABEL_116:
    v63 = *(unsigned int *)(a2 + 40);
    if ( (_DWORD)v63 )
    {
      v64 = *(__int64 **)(a2 + 48);
      v65 = 0;
      while ( 1 )
      {
        v66 = *v64;
        if ( *v64 )
        {
          if ( ((*(_DWORD *)(v50 + 16) >> *(_DWORD *)(v66 + 152)) & 1) != 0 )
            break;
        }
        ++v65;
        v64 += 5;
        if ( v63 == v65 )
          goto LABEL_129;
      }
      v121 = v127[19];
      if ( v45 )
        v67 = v45[28];
      else
        v67 = -1;
      v120 = *(_QWORD *)(v66 + 2760);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_kms_validate_vm_request",
        3440,
        -1,
        *(_DWORD *)(v66 + 64),
        v67,
        v65,
        *(_DWORD *)(v120 + 832),
        *(_BYTE *)(v120 + 1641));
      v43 = v121;
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v45 )
          v68 = v45[28];
        else
          v68 = -1;
        _drm_dev_dbg(
          0,
          0,
          0,
          "VM display:%s, conn:%d, crtc:%d, type:%d, tvm:%d\n",
          *(const char **)(v120 + 32),
          *(_DWORD *)(v66 + 64),
          v68,
          *(_DWORD *)(v120 + 832),
          *(unsigned __int8 *)(v120 + 1641));
        v43 = v121;
      }
    }
LABEL_129:
    if ( v45 )
    {
      if ( v55 )
      {
        v69 = *(_DWORD *)(v43 + 21472);
        if ( v47 > v69 || v56 > v69 || v45 != v55 )
        {
          printk(&unk_273F10, "_sde_kms_validate_vm_request");
          a1 = v127;
          v70 = v122;
          v72 = -7;
          v71 = v123;
          goto LABEL_152;
        }
      }
    }
    if ( (_DWORD)v18 == 2 )
    {
      a1 = v127;
      v70 = v122;
      v71 = v123;
      if ( (v123 & 1) != 0 )
        goto LABEL_151;
      v73 = *(__int64 (__fastcall **)(_QWORD *))v125;
      if ( *(_DWORD *)(*(_QWORD *)v125 - 4LL) != 925264262 )
        __break(0x8228u);
      v74 = v73(v127);
      if ( v74 )
      {
        v119 = v74;
        printk(&unk_24CCEC, "_sde_kms_validate_vm_request");
        v72 = v119;
        goto LABEL_152;
      }
      v75 = *(_DWORD **)(v125 + 104);
      if ( !v75 )
      {
LABEL_151:
        v72 = 0;
        goto LABEL_152;
      }
      if ( *(v75 - 1) != -307910306 )
        __break(0x8228u);
      v72 = ((__int64 (__fastcall *)(_QWORD *, __int64))v75)(v127, a2);
      if ( v72 )
      {
        v76 = *(__int64 (__fastcall **)(_QWORD))(v125 + 8);
        if ( v76 )
        {
          if ( *((_DWORD *)v76 - 1) != 925264262 )
            __break(0x8228u);
          v72 = v76(v127);
        }
      }
    }
    else
    {
      a1 = v127;
      v70 = v122;
      if ( (_DWORD)v18 == 1 && ((_DWORD)v48 == 1 || v61 >= 2) )
      {
        printk(&unk_22E69A, "_sde_kms_validate_vm_request");
        v71 = v123;
        v72 = -22;
      }
      else
      {
        v71 = v123;
        v72 = 0;
      }
    }
LABEL_152:
    v51 = v72;
    v77 = a1[798];
    if ( v77 )
      mutex_unlock(v77);
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_check_vm_request", 3602, -1, v17, v18, 1, v71 & 1, v51);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "VM  o_state:%d, n_state:%d, hw_owner:%d, rc:%d\n", v17, v18, v71 & 1, v51);
    v5 = v70;
    if ( v51 )
    {
LABEL_100:
      printk(&unk_269307, "sde_kms_atomic_check");
      goto LABEL_101;
    }
  }
LABEL_157:
  result = drm_atomic_helper_check(v5, a2);
  if ( !(_DWORD)result )
  {
    v86 = *(_QWORD *)(a2 + 8);
    v87 = a1[17];
    memset(v128, 0, 12);
    if ( *(int *)(v86 + 860) < 1 )
    {
      v93 = 0;
      v92 = 0;
      v91 = 0;
      v90 = nullptr;
    }
    else
    {
      v88 = 0;
      v89 = 0;
      v90 = nullptr;
      v91 = 0;
      v92 = 0;
      v93 = 0;
      do
      {
        v94 = *(_QWORD *)(a2 + 32);
        v95 = *(_QWORD **)(v94 + v88);
        if ( v95 )
        {
          v96 = *(_QWORD *)(v94 + v88 + 24);
          if ( *(_BYTE *)(v96 + 9) == 1 )
          {
            ++v91;
            sde_crtc_state_find_plane_fb_modes(v96, &v128[2], &v128[1], v128);
            v90 = v95;
            v86 = *(_QWORD *)(a2 + 8);
            v92 |= v128[0] != 0;
            v93 |= v128[1] != 0;
          }
        }
        ++v89;
        v88 += 56;
      }
      while ( v89 < *(int *)(v86 + 860) );
    }
    v97 = *(_QWORD **)(v87 + 864);
    v98 = (_QWORD *)(v87 + 864);
    v126 = v92;
    if ( v97 == (_QWORD *)(v87 + 864) )
    {
      v102 = 0;
      v101 = 0;
      v100 = 0;
      v99 = nullptr;
    }
    else
    {
      v99 = nullptr;
      v100 = 0;
      v101 = 0;
      v102 = 0;
      do
      {
        if ( *(_BYTE *)(v97[249] + 9LL) == 1 )
        {
          ++v100;
          if ( v97 - 2 != v90 )
          {
            memset(v128, 0, 12);
            sde_crtc_find_plane_fb_modes(v97 - 2, &v128[2], &v128[1], v128);
            v102 |= v128[0] != 0;
            v99 = v97 - 2;
            v101 |= v128[1] != 0;
          }
        }
        v97 = (_QWORD *)*v97;
      }
      while ( v97 != v98 );
    }
    if ( ((v102 | v126) & 1) != 0 && ((v93 | v101) & 1) != 0 )
    {
      a1 = v127;
      printk(&unk_2430E6, "sde_kms_check_secure_transition");
      result = 0xFFFFFFFFLL;
      goto LABEL_158;
    }
    if ( ((v102 | v126) & 1) != 0 )
    {
      if ( v100 > 1 || v91 >= 2 )
      {
        printk(&unk_25B1D9, "sde_kms_check_secure_transition");
      }
      else
      {
        if ( !v99 || !v90 || v99 == v90 )
          goto LABEL_191;
        printk(&unk_22B0B4, "sde_kms_check_secure_transition");
      }
      a1 = v127;
      result = 0xFFFFFFFFLL;
      goto LABEL_158;
    }
LABEL_191:
    a1 = v127;
    v103 = v127[19];
    if ( (*(_QWORD *)(v103 + 22008) & 0x8000000000000LL) != 0 )
    {
      result = sde_kms_check_frame_trigger_transition(v127, a2);
      if ( (_DWORD)result )
        goto LABEL_158;
      v103 = v127[19];
    }
    v104 = *(_DWORD *)(v103 + 21584);
    if ( !v104 || (v105 = *(_QWORD *)(a2 + 8), *(int *)(v105 + 860) < 1) )
    {
LABEL_207:
      result = 0;
      goto LABEL_208;
    }
    v106 = 0;
    v107 = 0;
    while ( 1 )
    {
      v108 = *(_QWORD *)(a2 + 32) + 56 * v106;
      v109 = *(_DWORD **)v108;
      if ( *(_QWORD *)v108 )
      {
        v110 = *(_QWORD *)v109;
        v111 = *(__int64 **)(*(_QWORD *)v109 + 816LL);
        if ( v111 != (__int64 *)(*(_QWORD *)v109 + 816LL) )
        {
          v112 = *(_QWORD *)(v108 + 24);
          do
          {
            if ( ((*(_DWORD *)(v112 + 1812) >> *((_DWORD *)v111 + 15)) & 1) != 0 )
            {
              ++v107;
              if ( (_drm_debug & 4) != 0 )
              {
                _drm_dev_dbg(0, 0, 0, "crtc%d has cwb%d attached to it\n", v109[28], *((_DWORD *)v111 + 4));
                v110 = *(_QWORD *)v109;
              }
            }
            v111 = (__int64 *)*v111;
          }
          while ( v111 != (__int64 *)(v110 + 816) );
        }
        if ( v107 > v104 )
        {
          printk(&unk_27049F, "sde_kms_check_cwb_concurreny");
          a1 = v127;
          result = 4294967201LL;
          break;
        }
        v105 = *(_QWORD *)(a2 + 8);
      }
      if ( ++v106 >= *(int *)(v105 + 860) )
        goto LABEL_207;
    }
  }
LABEL_158:
  v78 = a1[798];
  if ( !v78 )
    goto LABEL_208;
  v79 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
  if ( (int)v79 < 1 )
    goto LABEL_208;
  v80 = *(_QWORD *)(a2 + 32);
  v81 = 56 * v79;
  v82 = 0;
  while ( 2 )
  {
    v84 = *(_QWORD *)(v80 + v82);
    if ( !v84 )
    {
LABEL_163:
      v82 += 56;
      if ( v81 == v82 )
        goto LABEL_208;
      continue;
    }
    break;
  }
  v85 = *(_QWORD *)(v80 + v82 + 24);
  if ( (*(_BYTE *)(v85 + 9) & 1) != 0 )
  {
    if ( !v85 )
      goto LABEL_163;
  }
  else if ( !v85 || (*(_BYTE *)(*(_QWORD *)(v80 + v82 + 16) + 9LL) & 1) == 0 )
  {
    goto LABEL_163;
  }
  v83 = *(_DWORD *)(v85 + 1568);
  if ( !v83 )
    goto LABEL_163;
  if ( (_drm_debug & 4) != 0 )
  {
    v113 = result;
    _drm_dev_dbg(0, 0, 0, "valid vm request:%d found on crtc-%d\n", v83, *(_DWORD *)(v84 + 112));
    result = v113;
    a1 = v127;
    v80 = *(_QWORD *)(a2 + 32);
  }
  v114 = *(_QWORD *)(v80 + 56LL * *(unsigned int *)(v84 + 160) + 24);
  if ( v114 && *(_DWORD *)(v114 + 1568) == 2 )
  {
    if ( a1[798] )
    {
      v115 = result;
      mutex_lock(a1[798]);
      result = v115;
    }
    v116 = *(void (__fastcall **)(_QWORD))(v78 + 152);
    if ( v116 )
    {
      v117 = result;
      if ( *((_DWORD *)v116 - 1) != 925264262 )
        __break(0x8228u);
      v116(a1);
      result = v117;
    }
    if ( a1[798] )
    {
      v51 = result;
      mutex_unlock(a1[798]);
LABEL_101:
      result = v51;
    }
  }
LABEL_208:
  _ReadStatusReg(SP_EL0);
  return result;
}
