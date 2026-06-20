__int64 __fastcall hdd_link_rej_mac_addr_update(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        unsigned __int8 a11)
{
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 vdev_by_user; // x0
  int v33; // w25
  __int64 v34; // x19
  __int64 v35; // x24
  __int64 v36; // x27
  __int64 v37; // x21
  __int64 result; // x0
  const char *v39; // x2
  unsigned int v40; // w20
  __int64 v41; // x22
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x11
  __int64 v45; // x10
  char v46; // w12
  unsigned __int64 StatusReg; // x8
  __int64 v48; // x8
  __int64 v49; // x28
  unsigned __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x9
  int v53; // w10
  __int16 v54; // w8
  int v55; // w9
  int v56; // w9
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int64 v68; // x10
  unsigned __int64 v75; // x10
  int v76; // [xsp+Ch] [xbp-24h] BYREF
  char v77; // [xsp+10h] [xbp-20h]
  _BYTE v78[11]; // [xsp+11h] [xbp-1Fh]
  _DWORD v79[5]; // [xsp+1Ch] [xbp-14h] BYREF

  *(_QWORD *)&v79[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_link_rej_mac_addr_update", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD ctx NULL", v14, v15, v16, v17, v18, v19, v20, v21, "hdd_link_rej_mac_addr_update");
    result = 4;
    goto LABEL_19;
  }
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a11);
  if ( !link_info_by_vdev )
  {
    v39 = "%s: VDEV %d not found";
LABEL_14:
    qdf_trace_msg(0x33u, 2u, v39, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_link_rej_mac_addr_update", a11);
    result = 4;
    goto LABEL_19;
  }
  v31 = link_info_by_vdev;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(link_info_by_vdev, 6, "hdd_link_rej_mac_addr_update");
  if ( !vdev_by_user )
  {
    v39 = "%s: Invalid VDEV %d";
    goto LABEL_14;
  }
  v33 = a10;
  v34 = vdev_by_user;
  if ( a10 != 255 )
  {
    v35 = *(_QWORD *)v31;
    if ( *(_QWORD *)v31 )
    {
      v36 = 0;
      v37 = v35 + 52840;
      while ( 1 )
      {
        if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v36 >> 3)) > 2 )
          goto LABEL_16;
        if ( (unsigned int)hdd_cm_get_ieee_link_id(v37, 0) == v33 )
          break;
        v37 += 6088;
        v36 += 6088;
        if ( !v37 )
          goto LABEL_16;
      }
      if ( v31 == *(_QWORD *)(*(_QWORD *)v31 + 52832LL)
        || (v41 = *(_QWORD *)v37, v37 == *(_QWORD *)(*(_QWORD *)v37 + 52832LL)) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: deflink switched",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_link_rej_mac_addr_update");
        _cds_trigger_recovery(44, (__int64)"hdd_link_rej_mac_addr_update", 6658, v58, v59, v60, v61, v62, v63, v64, v65);
        goto LABEL_17;
      }
      v42 = 0x71B3F945A27B1F49LL * ((v31 - *(_QWORD *)v31 - 52840) >> 3);
      if ( (unsigned __int8)(73 * ((v31 - *(_QWORD *)v31 - 52840) >> 3)) > 2u
        || (v43 = 0x71B3F945A27B1F49LL * ((v35 - v41 + v36) >> 3), (unsigned __int8)(73 * ((v35 - v41 + v36) >> 3)) >= 3u) )
      {
        __break(0x5512u);
      }
      else
      {
        v44 = v42 & 3;
        v45 = v41 + 1632;
        LOBYTE(v36) = v43 & 3;
        v42 = 1LL << (v42 & 3);
        v46 = *(_BYTE *)(v41 + 1632 + (v43 & 3));
        *(_BYTE *)(v45 + (v43 & 3)) = *(_BYTE *)(v41 + 1632 + v44);
        *(_BYTE *)(v45 + v44) = v46;
      }
      _X9 = (unsigned __int64 *)(v41 + 1640);
      __asm { PRFM            #0x11, [X9] }
      do
        v68 = __ldxr(_X9);
      while ( __stxr(v68 & ~v42, _X9) );
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v31 + 16);
        v48 = *(_QWORD *)(v31 + 24);
      }
      else
      {
        raw_spin_lock_bh(v31 + 16);
        v48 = *(_QWORD *)(v31 + 24) | 1LL;
        *(_QWORD *)(v31 + 24) = v48;
      }
      v49 = *(_QWORD *)(v31 + 32);
      *(_QWORD *)(v31 + 32) = *(_QWORD *)(v37 + 32);
      *(_BYTE *)(v31 + 8) = *(_BYTE *)(v37 + 8);
      if ( (v48 & 1) != 0 )
      {
        *(_QWORD *)(v31 + 24) = v48 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v31 + 16);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_32;
      }
      else
      {
        raw_spin_unlock(v31 + 16);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_32;
      }
      v50 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v50 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v50 + 16) & 0xFF00) == 0 )
      {
        raw_spin_lock_bh(v37 + 16);
        v51 = *(_QWORD *)(v37 + 24) | 1LL;
        *(_QWORD *)(v37 + 24) = v51;
        goto LABEL_33;
      }
LABEL_32:
      raw_spin_lock(v37 + 16);
      v51 = *(_QWORD *)(v37 + 24);
LABEL_33:
      *(_QWORD *)(v37 + 32) = v49;
      *(_BYTE *)(v37 + 8) = *(_BYTE *)(v49 + 168);
      if ( (v51 & 1) != 0 )
      {
        *(_QWORD *)(v37 + 24) = v51 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v37 + 16);
      }
      else
      {
        raw_spin_unlock(v37 + 16);
      }
      _X9 = (unsigned __int64 *)(v41 + 1640);
      __asm { PRFM            #0x11, [X9] }
      do
        v75 = __ldxr(_X9);
      while ( __stxr(v75 | (1LL << v36), _X9) );
      v52 = *(_QWORD *)(v37 + 5968);
      *(_QWORD *)(v37 + 5968) = *(_QWORD *)(v31 + 5968);
      *(_QWORD *)(v31 + 5968) = v52;
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v37 + 32) + 680LL) + 8LL) = v37;
      memset(v79, 0, 12);
      *(_QWORD *)&v78[3] = 0;
      if ( (*(_BYTE *)(v35 + 52800) & 1) != 0 )
      {
        v53 = *(_DWORD *)(v35 + 52912);
        v54 = *(_WORD *)(v35 + 52916);
        v77 = *(_BYTE *)(v35 + 52848);
        *(_DWORD *)v78 = v53;
        *(_WORD *)&v78[4] = v54;
        if ( v35 == -58928 )
        {
          v57 = 1;
        }
        else
        {
          v78[6] = *(_BYTE *)(v35 + 58936);
          v55 = *(_DWORD *)(v35 + 59000);
          LOWORD(v79[0]) = *(_WORD *)(v35 + 59004);
          *(_DWORD *)&v78[7] = v55;
          if ( v35 == -65016 )
          {
            v57 = 2;
          }
          else
          {
            BYTE2(v79[0]) = *(_BYTE *)(v35 + 65024);
            v56 = *(_DWORD *)(v35 + 65088);
            *(_WORD *)((char *)&v79[1] + 3) = *(_WORD *)(v35 + 65092);
            v57 = 3;
            *(_DWORD *)((char *)v79 + 3) = v56;
          }
        }
        v76 = v57;
        mlo_mgr_update_link_info_mac_addr(*(_QWORD *)(*(_QWORD *)(v35 + 52832) + 32LL), &v76);
      }
      sme_vdev_set_data_tx_callback(v34);
      ucfg_pmo_del_wow_pattern(v34);
      ucfg_pmo_register_wow_default_patterns(v34);
      v40 = 0;
      goto LABEL_18;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: NULL adapter or invalid link ID",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "hdd_get_link_info_by_ieee_link_id");
LABEL_16:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: VDEV %d not found for new link",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "hdd_link_rej_mac_addr_update",
    a11);
LABEL_17:
  v40 = 4;
LABEL_18:
  _hdd_objmgr_put_vdev_by_user(v34, 6, "hdd_link_rej_mac_addr_update");
  result = v40;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
