__int64 __fastcall dsi_message_tx(__int64 a1, __int64 a2, char a3)
{
  int *v5; // x2
  int v7; // w1
  __int64 result; // x0
  int v9; // w8
  int v10; // w0
  const char *v11; // x3
  unsigned int v12; // w19
  unsigned int v13; // w10
  char v14; // w11
  void *v15; // x0
  unsigned int v16; // w9
  int v17; // w8
  unsigned int v18; // w10
  const void *v19; // x1
  size_t v20; // x2
  _BYTE *v21; // x20
  unsigned __int64 v22; // x23
  size_t v23; // x0
  __int64 v24; // x8
  _QWORD *v25; // x28
  _DWORD *v26; // x8
  _DWORD *v27; // x8
  int v28; // w8
  unsigned int v29; // w24
  unsigned int v30; // w22
  int v31; // w8
  __int64 v32; // x8
  _DWORD *v33; // x8
  unsigned int v34; // w12
  int v35; // w10
  unsigned int v36; // w25
  int v37; // w6
  __int64 v38; // x8
  _DWORD *v39; // x8
  int v40; // w10
  int v41; // w9
  int v42; // w21
  unsigned __int64 v43; // x23
  _BYTE *v44; // x0
  unsigned __int64 v45; // x8
  char v46; // w9
  __int64 v47; // x21
  int v48; // w22
  void (__fastcall *v49)(__int64, unsigned __int64 *, __int64); // x8
  __int64 v50; // x0
  unsigned __int64 *v51; // x1
  __int64 v52; // x2
  void (__fastcall *v53)(__int64, unsigned __int64 *, __int64); // x8
  __int64 v54; // x0
  unsigned __int64 *v55; // x1
  __int64 v56; // x2
  __int64 (__fastcall *v57)(__int64, __int64); // x8
  __int64 v58; // x1
  unsigned int v59; // w0
  __int64 v60; // x10
  __int64 v61; // x9
  unsigned __int64 v62; // x13
  char v63; // w13
  char v64; // w8
  int v65; // w10
  int v66; // w8
  unsigned int v67; // w8
  size_t v68; // x0
  char v69; // w10
  char v70; // w12
  int v71; // w11
  unsigned __int64 v72; // x9
  __int64 v73; // x8
  __int64 v74; // x10
  char v75; // w12
  unsigned int v76; // w11
  __int64 v77; // x0
  int v78; // w8
  int v79; // w6
  int v80; // w7
  size_t v81; // x0
  int v82; // w4
  void (__fastcall *v83)(_QWORD); // x8
  void (__fastcall *v84)(_QWORD); // x8
  char v85; // [xsp+0h] [xbp-5E0h]
  unsigned __int64 v86; // [xsp+8h] [xbp-5D8h] BYREF
  int v87; // [xsp+10h] [xbp-5D0h]
  _BYTE *v88; // [xsp+18h] [xbp-5C8h] BYREF
  __int64 v89; // [xsp+20h] [xbp-5C0h]
  unsigned __int64 v90; // [xsp+28h] [xbp-5B8h] BYREF
  __int64 v91; // [xsp+30h] [xbp-5B0h]
  __int64 v92; // [xsp+38h] [xbp-5A8h]
  __int64 v93; // [xsp+40h] [xbp-5A0h]
  _QWORD dest[179]; // [xsp+48h] [xbp-598h] BYREF

  v5 = (int *)(a2 + 52);
  dest[177] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a2 + 8);
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = nullptr;
  v89 = 0;
  v87 = 0;
  v86 = 0;
  if ( (unsigned int)dsi_message_validate_tx_mode(a1, v7, v5) )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Cmd tx validation failed, cannot transfer cmd\n",
      *(const char **)(a1 + 16));
    result = 4294966772LL;
LABEL_135:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_message_tx",
    1633,
    -1,
    *(_DWORD *)(a1 + 8),
    4369,
    *(_DWORD *)(a2 + 52),
    *(_DWORD *)(a1 + 2784),
    239);
  v9 = *(_DWORD *)(a2 + 52);
  if ( (v9 & 0x80) != 0 )
  {
    v13 = *(unsigned __int8 *)(a2 + 2);
    v14 = *(_BYTE *)(a2 + 1);
    v15 = *(void **)(a1 + 2792);
    BYTE1(v87) = (*(_DWORD *)(a2 + 52) & 2) != 0;
    v16 = *(_DWORD *)(a2 + 8);
    BYTE2(v87) = (v9 & 4) != 0;
    v17 = (v13 >> 1) & 1;
    v18 = *(_DWORD *)(a1 + 2780);
    *(_DWORD *)(a1 + 2784) = v16;
    v20 = *(_QWORD *)(a2 + 8);
    v19 = *(const void **)(a2 + 16);
    LOBYTE(v87) = v14;
    HIBYTE(v87) = v17;
    v86 = __PAIR64__(v16, v18);
    memcpy(v15, v19, v20);
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: %s: non-embedded mode , size of command =%zd\n",
      *(const char **)(a1 + 16),
      *(_QWORD *)(a2 + 8));
    v21 = nullptr;
    goto LABEL_7;
  }
  v10 = mipi_dsi_create_packet(&v90, a2);
  if ( v10 )
  {
    v11 = *(const char **)(a1 + 16);
    v12 = v10;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Failed to create message packet, rc=%d\n", v11, v10);
    result = v12;
    goto LABEL_135;
  }
  v43 = ((_DWORD)v90 + 3) & 0xFFFFFFFC;
  v44 = (_BYTE *)devm_kmalloc(*(_QWORD *)a1 + 16LL, v43, 3520);
  if ( !v44 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to copy message, rc=%d\n",
      *(const char **)(a1 + 16),
      -12);
    result = 4294967284LL;
    goto LABEL_135;
  }
  if ( !(_DWORD)v43 )
LABEL_139:
    __break(1u);
  v45 = v90;
  v21 = v44;
  if ( v90 == 1 )
    goto LABEL_49;
  if ( !v90 )
  {
    *v44 = -1;
LABEL_49:
    v46 = -1;
    v44[1] = -1;
    goto LABEL_50;
  }
  if ( v90 >= 4 )
    v46 = BYTE3(v91);
  else
    v46 = -1;
LABEL_50:
  v44[3] = v46;
  if ( (_DWORD)v43 == 4 )
  {
    if ( !v92 )
      goto LABEL_98;
    goto LABEL_97;
  }
  v60 = v93;
  v61 = 0;
  do
  {
    v62 = v61 + 4;
    if ( v45 <= v61 + 4 )
    {
      if ( v62 >= v43 )
        goto LABEL_139;
      v63 = -1;
    }
    else
    {
      if ( v62 >= v43 )
        goto LABEL_139;
      v63 = *(_BYTE *)(v60 + v61);
    }
    v44[v61++ + 4] = v63;
  }
  while ( v43 - 4 != v61 );
  if ( v92 )
  {
    v46 = v44[3];
LABEL_97:
    v44[3] = v46 | 0x40;
  }
LABEL_98:
  v64 = v91;
  v65 = v91 & 0x3D;
  *(_WORD *)v44 = *(_WORD *)((char *)&v91 + 1);
  v44[2] = v64;
  if ( v65 == 4 || (v66 = v64 & 0x3F, v66 == 36) || v66 == 20 )
    v44[3] |= 0x20u;
  v67 = *(_DWORD *)(a2 + 52);
  if ( (~(_BYTE)v67 & 0x22) == 0 && (v67 & 0x40) == 0 && (unsigned int)(*(_DWORD *)(a1 + 2784) + v43) >= 0xF1 )
  {
    v68 = sde_dbg_base_evtlog;
    *(_DWORD *)(a2 + 52) = v67 | 0x40;
    sde_evtlog_log(v68, "dsi_message_tx", 1679, -1, *(_DWORD *)(a1 + 8), 13107, v67 | 0x40, -1059143953, v85);
    v67 = *(_DWORD *)(a2 + 52);
  }
  if ( (v67 & 0x40) != 0 )
    v21[3] |= 0x80u;
  if ( (v67 & 0x20) != 0 )
  {
    v70 = *(_BYTE *)(a2 + 2);
    v71 = (v67 >> 1) & 1;
    v72 = 0;
    LODWORD(v86) = *(_DWORD *)(a1 + 2780);
    BYTE2(v87) = (v67 & 4) != 0;
    v73 = *(_QWORD *)(a1 + 2792);
    HIBYTE(v87) = (v70 & 2) != 0;
    if ( (unsigned int)v43 <= 1 )
      v74 = 1;
    else
      v74 = (unsigned int)v43;
    BYTE1(v87) = v71;
    do
    {
      if ( v72 >= v43 )
        goto LABEL_139;
      v75 = v21[v72];
      v76 = v72++ + *(_DWORD *)(a1 + 2784);
      *(_BYTE *)(v73 + v76) = v75;
    }
    while ( v74 != v72 );
    v77 = *(_QWORD *)(a1 + 2768);
    *(_DWORD *)(a1 + 2784) += v43;
    msm_gem_sync(v77);
    if ( (*(_BYTE *)(a2 + 52) & 0x40) == 0 )
      goto LABEL_132;
    v78 = *(_DWORD *)(a1 + 2784);
    *(_DWORD *)(a1 + 2784) = 0;
    HIDWORD(v86) = v78;
  }
  else if ( (v67 & 0x10) != 0 )
  {
    v69 = *(_BYTE *)(a2 + 2);
    v88 = v21;
    BYTE4(v89) = (v67 & 2) != 0;
    LODWORD(v89) = v43;
    BYTE5(v89) = (v67 & 4) != 0;
    BYTE6(v89) = (v69 & 2) != 0;
  }
LABEL_7:
  v22 = *(unsigned int *)(a2 + 52);
  v23 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_kickoff_msg_tx",
          1490,
          -1,
          *(_DWORD *)(a1 + 8),
          4369,
          *(_DWORD *)(a2 + 52),
          *(unsigned __int16 *)(a2 + 2),
          239);
  v24 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v24 >= 3 )
    goto LABEL_140;
  v25 = (_QWORD *)(a1 + 8 * v24);
  v26 = (_DWORD *)v25[195];
  if ( v26 && *(_BYTE *)(a1 + 2500) == 1 )
  {
    if ( *(v26 - 1) != 1388890007 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v26)(a1 + 96, a1 + 2444, (unsigned int)v22);
  }
  v27 = (_DWORD *)v25[189];
  if ( v27 )
  {
    if ( *(v27 - 1) != -1112488124 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v27)(a1 + 96, a1 + 2444, a3 & 1);
  }
  if ( (v22 & 0x100) == 0 )
  {
    v28 = *(_DWORD *)(a1 + 2440);
    if ( v28 != 1 )
    {
LABEL_55:
      v47 = (v22 >> 3) & 1;
      v48 = v22 & 0x1040;
      *(_BYTE *)(a1 + 2897) = v28 == 2;
      if ( (v22 & 8) == 0 )
      {
        *(_DWORD *)(a1 + 2852) = 0;
        dsi_ctrl_enable_status_interrupt((int *)a1, 0, nullptr);
        *(_DWORD *)(a1 + 2000) = 0;
        if ( (v22 & 0x20) != 0 )
        {
          if ( (v22 & 0x80) != 0 )
          {
            v49 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[63];
            if ( !v49 )
            {
LABEL_78:
              if ( *(_BYTE *)(a1 + 2896) == 1 )
              {
                v57 = (__int64 (__fastcall *)(__int64, __int64))v25[192];
                if ( v57 )
                {
                  v58 = *(unsigned __int8 *)(a1 + 2897);
                  if ( *((_DWORD *)v57 - 1) != 1825771015 )
                    __break(0x8228u);
                  v59 = v57(a1 + 96, v58);
                }
                else
                {
                  v59 = 0;
                }
                v79 = (unsigned __int16)v59;
                v80 = HIWORD(v59);
                v81 = sde_dbg_base_evtlog;
                v82 = *(_DWORD *)(a1 + 8);
                *(_DWORD *)(a1 + 2900) = v79;
                *(_DWORD *)(a1 + 2904) = v80;
                sde_evtlog_log(v81, "dsi_kickoff_msg_tx", 1587, -1, v82, 13107, v79, v80, 239);
              }
              v83 = (void (__fastcall *)(_QWORD))v25[69];
              if ( v83 )
              {
                if ( *((_DWORD *)v83 - 1) != 1133867105 )
                  __break(0x8228u);
                v83(a1 + 96);
              }
              if ( (v22 & 0x80) != 0 )
              {
                if ( *(_DWORD *)(a1 + 88) <= 2u )
                {
                  v84 = (void (__fastcall *)(_QWORD))v25[54];
                  if ( v84 )
                  {
                    if ( *((_DWORD *)v84 - 1) != 1133867105 )
                      __break(0x8228u);
                    v84(a1 + 96);
                  }
                }
                *(_DWORD *)(a1 + 2784) = 0;
              }
              goto LABEL_132;
            }
          }
          else
          {
            v49 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[60];
            if ( !v49 )
              goto LABEL_78;
          }
          v50 = a1 + 96;
          v51 = &v86;
          v52 = v48 | (unsigned int)v47;
          if ( *((_DWORD *)v49 - 1) != -2044904205 )
            __break(0x8228u);
        }
        else
        {
          if ( (v22 & 0x10) == 0 )
            goto LABEL_78;
          v49 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[66];
          if ( !v49 )
            goto LABEL_78;
          v50 = a1 + 96;
          v51 = (unsigned __int64 *)&v88;
          v52 = v48 | (unsigned int)v47;
          if ( *((_DWORD *)v49 - 1) != 1389313285 )
            __break(0x8228u);
        }
        v49(v50, v51, v52);
        goto LABEL_78;
      }
      if ( (v22 & 0x20) != 0 )
      {
        if ( (v22 & 0x80) != 0 )
        {
          v53 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[63];
          if ( !v53 )
            goto LABEL_132;
        }
        else
        {
          v53 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[60];
          if ( !v53 )
            goto LABEL_132;
        }
        v54 = a1 + 96;
        v55 = &v86;
        v56 = v48 | (unsigned int)v47;
        if ( *((_DWORD *)v53 - 1) != -2044904205 )
          __break(0x8228u);
      }
      else
      {
        if ( (v22 & 0x10) == 0 || (v53 = (void (__fastcall *)(__int64, unsigned __int64 *, __int64))v25[66]) == nullptr )
        {
LABEL_132:
          if ( v21 )
            devm_kfree(*(_QWORD *)a1 + 16LL);
          result = 0;
          goto LABEL_135;
        }
        v54 = a1 + 96;
        v55 = (unsigned __int64 *)&v88;
        v56 = v48 | (unsigned int)v47;
        if ( *((_DWORD *)v53 - 1) != 1389313285 )
          __break(0x8228u);
      }
      v53(v54, v55, v56);
      goto LABEL_132;
    }
  }
  memcpy(dest, (const void *)(a1 + 168), 0x588u);
  v29 = *(_DWORD *)(a1 + 2524);
  v30 = *(_DWORD *)(a1 + 2528);
  v23 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_configure_command_scheduling",
          1413,
          -1,
          *(_DWORD *)(a1 + 8),
          4369,
          v29,
          v30,
          239);
  v31 = *(_DWORD *)(a1 + 2440);
  if ( v31 != 1 )
  {
    v37 = 0;
    if ( v31 == 2 )
      goto LABEL_34;
LABEL_54:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_configure_command_scheduling",
      1454,
      -1,
      *(_DWORD *)(a1 + 8),
      8738,
      v37,
      v30,
      239);
    v28 = *(_DWORD *)(a1 + 2440);
    goto LABEL_55;
  }
  v32 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v32 >= 3 )
    goto LABEL_140;
  v33 = (_DWORD *)dest[v32 + 129];
  if ( !v33 || *(_DWORD *)(a1 + 1620) != 1 )
  {
    v37 = 0;
    goto LABEL_54;
  }
  if ( v29 <= 1 )
    v34 = 1;
  else
    v34 = v29;
  if ( v34 >= *(_DWORD *)(a1 + 2628) )
    v35 = 1;
  else
    v35 = v34;
  v36 = *(_DWORD *)(a1 + 2624) + *(_DWORD *)(a1 + 2620) + *(_DWORD *)(a1 + 2616) + v35;
  if ( *(v33 - 1) != 875778216 )
    __break(0x8228u);
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v33)(a1 + 96, v36, a3 & 1);
  v37 = v36;
  if ( *(_DWORD *)(a1 + 2440) != 2 )
    goto LABEL_54;
LABEL_34:
  v38 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v38 <= 2 )
  {
    v39 = (_DWORD *)dest[v38 + 162];
    if ( v39 )
    {
      v40 = *(_DWORD *)(a1 + 2616);
      if ( v29 )
        v41 = v29;
      else
        v41 = 5;
      if ( !v30 )
        v30 = *(_DWORD *)(a1 + 2616);
      v42 = v40 + v41;
      if ( *(v39 - 1) != -1266361083 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, unsigned __int64 *, _QWORD, _QWORD))v39)(
        a1 + 96,
        &v86,
        (unsigned int)(v40 + v41),
        v30);
      v37 = v42;
    }
    goto LABEL_54;
  }
LABEL_140:
  __break(0x5512u);
  return dsi_ctrl_transfer_cleanup(v23);
}
