__int64 __fastcall dp_peer_mlo_setup(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v16; // w8
  __int64 v17; // x9
  char *v18; // x8
  __int64 v19; // x3
  char v20; // w5
  char v21; // w9
  _DWORD *v22; // x8
  __int64 v23; // x1
  __int64 v24; // x20
  __int64 v25; // x8
  char *v26; // x9
  __int64 v27; // x3
  char v28; // w5
  unsigned __int8 *v29; // x12
  int v30; // w9
  int v31; // w10
  int v32; // w11
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 *v41; // x8
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // x8
  unsigned __int8 v47; // w9
  _BYTE *v48; // x8
  __int64 v49; // x8
  __int64 v50; // x3
  char v51; // w10
  _BYTE *v52; // x8
  unsigned int v53; // w8
  unsigned int v60; // w10
  char v62; // w23
  unsigned __int64 StatusReg; // x8
  int v64; // w24
  _BYTE *v65; // x21
  __int64 result; // x0
  char v67; // w8
  __int64 v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  const char *v77; // x4
  unsigned int v79; // w9
  __int64 v80; // [xsp+0h] [xbp-80h]
  __int64 v81; // [xsp+8h] [xbp-78h]
  __int64 v82; // [xsp+18h] [xbp-68h]
  __int64 v83; // [xsp+20h] [xbp-60h]
  __int64 v84; // [xsp+28h] [xbp-58h]
  __int64 v85; // [xsp+30h] [xbp-50h]
  __int64 v86; // [xsp+38h] [xbp-48h]
  __int64 v87; // [xsp+48h] [xbp-38h] BYREF
  __int64 v88; // [xsp+50h] [xbp-30h]
  __int64 v89; // [xsp+58h] [xbp-28h]
  __int64 v90; // [xsp+60h] [xbp-20h] BYREF
  __int64 v91; // [xsp+68h] [xbp-18h]
  __int64 v92; // [xsp+70h] [xbp-10h]
  __int64 v93; // [xsp+78h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = 0;
  v92 = 0;
  v90 = 0;
  if ( !a4 || !*a4 )
  {
    v25 = *(_QWORD *)(a2 + 24);
    if ( *(_DWORD *)(v25 + 32) == 3 )
    {
      v26 = *(char **)(v25 + 24);
      v88 = 0;
      v89 = 0;
      v87 = 0;
      v27 = *(unsigned __int16 *)(a2 + 16);
      v28 = *v26;
      LOBYTE(v87) = *(_BYTE *)(v25 + 59);
      BYTE1(v89) = v28;
      dp_wdi_event_handler(304, a1, &v87, v27, 0xFFFFFFFFLL);
    }
    goto LABEL_60;
  }
  v16 = *((_BYTE *)a4 + 8);
  if ( (v16 & 1) != 0 )
  {
    dp_peer_create_wifi3(a1, a3);
    v16 = *((_BYTE *)a4 + 8);
  }
  v17 = *(_QWORD *)(a2 + 24);
  if ( *(_DWORD *)(v17 + 32) == 3 && (v16 & 2) != 0 )
  {
    v18 = *(char **)(v17 + 24);
    v88 = 0;
    v89 = 0;
    v87 = 0;
    v19 = *(unsigned __int16 *)(a2 + 16);
    v20 = *v18;
    LOBYTE(v18) = *(_BYTE *)(v17 + 59);
    BYTE1(v89) = v20;
    LOBYTE(v87) = (_BYTE)v18;
    dp_wdi_event_handler(304, a1, &v87, v19, 0xFFFFFFFFLL);
    v16 = *((_BYTE *)a4 + 8);
  }
  v21 = *(_BYTE *)(a2 + 128) & 0xFE | v16 & 1;
  *(_BYTE *)(a2 + 128) = v21;
  *(_BYTE *)(a2 + 128) = v21 & 0xFD | a4[1] & 2;
  v22 = *(_DWORD **)(a1 + 1536);
  if ( v22 )
  {
    v23 = *a4;
    if ( *(v22 - 1) != 69695039 )
      __break(0x8228u);
    v24 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v22)(a1, v23, 0, 7, a3);
  }
  else
  {
    v24 = 0;
  }
  v29 = (unsigned __int8 *)*a4;
  if ( *a4 )
  {
    v30 = *v29;
    v31 = v29[1];
    v32 = v29[2];
    LODWORD(v29) = v29[5];
  }
  else
  {
    v32 = 0;
    v30 = 0;
    v31 = 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Peer %pK MAC %02x:%02x:%02x:**:**:%02x mld peer %pK MAC %02x:%02x:%02x:**:**:%02x first_link %d, primary_link %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_peer_mlo_setup",
    a2,
    *(unsigned __int8 *)(a2 + 44),
    *(unsigned __int8 *)(a2 + 45),
    *(unsigned __int8 *)(a2 + 46),
    *(unsigned __int8 *)(a2 + 49),
    v24,
    v30,
    v31,
    v32,
    (_DWORD)v29,
    *(_BYTE *)(a2 + 128) & 1,
    (*(unsigned __int8 *)(a2 + 128) >> 1) & 1);
  if ( v24 )
  {
    if ( (a4[1] & 1) != 0 )
    {
      *(_QWORD *)(v24 + 88) = *(_QWORD *)(a2 + 88);
      *(_DWORD *)(v24 + 240) = 1;
    }
    else
    {
      dp_peer_rx_tids_destroy(a2);
      *(_QWORD *)(a2 + 88) = *(_QWORD *)(v24 + 88);
    }
    if ( (a4[1] & 3) == 2 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Primary link is not the first link. vdev: %pK vdev_id %d vdev_ref_cnt %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "dp_peer_mlo_setup",
        *(_QWORD *)(v24 + 24),
        (unsigned __int8)a3,
        *(unsigned int *)(*(_QWORD *)(v24 + 24) + 43384LL));
      if ( *(_DWORD *)(*(_QWORD *)(a2 + 24) + 32LL) == 3 )
      {
        dp_mld_peer_change_vdev(a1, v24, a3);
      }
      else
      {
        v46 = *(_QWORD *)(v24 + 24);
        v47 = *(_BYTE *)(v46 + 59);
        v48 = *(_BYTE **)(v46 + 24);
        WORD1(v92) = v47;
        BYTE4(v92) = *v48;
        dp_mld_peer_change_vdev(a1, v24, a3);
        v49 = *(_QWORD *)(a2 + 24);
        LOBYTE(v92) = 0;
        v91 = v24 + 44;
        v50 = *(unsigned __int16 *)(a2 + 16);
        v51 = *(_BYTE *)(v49 + 59);
        v52 = *(_BYTE **)(v49 + 24);
        LOBYTE(v90) = v51;
        BYTE1(v92) = *v52;
        dp_wdi_event_handler(302, a1, &v90, v50, 0xFFFFFFFFLL);
      }
    }
    v53 = *(_DWORD *)(v24 + 40);
    while ( v53 )
    {
      _X12 = (unsigned int *)(v24 + 40);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v60 = __ldxr(_X12);
        if ( v60 != v53 )
          break;
        if ( !__stlxr(v53 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v60 == v53;
      v53 = v60;
      if ( _ZF )
      {
        _X8 = (unsigned int *)(v24 + 292);
        __asm { PRFM            #0x11, [X8] }
        do
          v79 = __ldxr(_X8);
        while ( __stxr(v79 + 1, _X8) );
        break;
      }
    }
    *(_QWORD *)(a2 + 416) = v24;
    v62 = *((_BYTE *)a4 + 11);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v24 + 480);
      if ( *(_BYTE *)(v24 + 437) )
        goto LABEL_42;
    }
    else
    {
      raw_spin_lock_bh(v24 + 480);
      *(_QWORD *)(v24 + 488) |= 1uLL;
      if ( *(_BYTE *)(v24 + 437) )
      {
LABEL_42:
        if ( *(_BYTE *)(v24 + 449) )
        {
          if ( *(_BYTE *)(v24 + 461) )
          {
            if ( *(_BYTE *)(v24 + 473) )
            {
              v64 = 4;
LABEL_54:
              v68 = *(_QWORD *)(v24 + 488);
              if ( (v68 & 1) != 0 )
              {
                *(_QWORD *)(v24 + 488) = v68 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v24 + 480);
              }
              else
              {
                raw_spin_unlock(v24 + 480);
              }
              if ( v64 == 4 )
                v77 = "Failed";
              else
                v77 = "Successful";
              LODWORD(v86) = v64;
              LODWORD(v85) = *(unsigned __int8 *)(v24 + 49);
              LODWORD(v84) = *(unsigned __int8 *)(v24 + 46);
              LODWORD(v83) = *(unsigned __int8 *)(v24 + 45);
              LODWORD(v82) = *(unsigned __int8 *)(v24 + 44);
              LODWORD(v81) = *(unsigned __int8 *)(a2 + 49);
              LODWORD(v80) = *(unsigned __int8 *)(a2 + 46);
              qdf_trace_msg(
                0x81u,
                5u,
                "%s: %s addition of link peer %pK (%02x:%02x:%02x:**:**:%02x) to MLD peer %pK (%02x:%02x:%02x:**:**:%02x)"
                ", idx %u num_links %u",
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                "dp_mld_peer_add_link_peer",
                v77,
                a2,
                *(unsigned __int8 *)(a2 + 44),
                *(unsigned __int8 *)(a2 + 45),
                v80,
                v81,
                v24,
                v82,
                v83,
                v84,
                v85,
                v86,
                *(unsigned __int8 *)(v24 + 476));
              *(_BYTE *)(*(_QWORD *)v24 + 10LL) |= 8u;
              dp_peer_unref_delete(v24, 7);
LABEL_60:
              result = 0;
              goto LABEL_61;
            }
            v65 = (_BYTE *)(v24 + 464);
            v64 = 3;
          }
          else
          {
            v65 = (_BYTE *)(v24 + 452);
            v64 = 2;
          }
        }
        else
        {
          v65 = (_BYTE *)(v24 + 440);
          v64 = 1;
        }
LABEL_53:
        qdf_mem_copy(v65, (const void *)(a2 + 44), 6u);
        v65[9] = 1;
        v67 = *(_BYTE *)(*(_QWORD *)(a2 + 24) + 59LL);
        v65[10] = 0;
        v65[11] = v62;
        v65[8] = v67;
        ++*(_BYTE *)(v24 + 476);
        goto LABEL_54;
      }
    }
    v64 = 0;
    v65 = (_BYTE *)(v24 + 428);
    goto LABEL_53;
  }
  *(_QWORD *)(a2 + 416) = 0;
  v41 = (unsigned __int8 *)*a4;
  if ( *a4 )
  {
    v42 = *v41;
    v43 = v41[1];
    v44 = v41[2];
    v45 = v41[5];
  }
  else
  {
    v44 = 0;
    v42 = 0;
    v43 = 0;
    v45 = 0;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: mld peer %02x:%02x:%02x:**:**:%02x not found!",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "dp_peer_mlo_setup",
    v42,
    v43,
    v44,
    v45);
  result = 16;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
