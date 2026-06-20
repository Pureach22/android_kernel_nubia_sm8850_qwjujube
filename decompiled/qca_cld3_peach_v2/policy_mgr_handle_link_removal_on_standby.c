__int64 __fastcall policy_mgr_handle_link_removal_on_standby(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  __int64 v12; // x21
  unsigned __int64 v14; // x27
  int v15; // w22
  unsigned __int16 *v16; // x28
  const char *v17; // x2
  __int64 result; // x0
  unsigned int v19; // w25
  unsigned __int8 *ap_link_by_link_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int8 *v29; // x26
  unsigned __int64 v36; // x8
  unsigned int v37; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // [xsp+0h] [xbp-50h]
  __int64 v47; // [xsp+8h] [xbp-48h]
  __int64 v48; // [xsp+10h] [xbp-40h]
  __int64 v49; // [xsp+18h] [xbp-38h]
  __int64 v50; // [xsp+20h] [xbp-30h]
  __int64 v51; // [xsp+28h] [xbp-28h]
  __int64 v52; // [xsp+30h] [xbp-20h]
  __int64 v53; // [xsp+38h] [xbp-18h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !*(_QWORD *)(a1 + 1360) )
  {
    v17 = "%s: invalid vdev or mlo_dev_ctx";
LABEL_9:
    qdf_trace_msg(0x4Fu, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "policy_mgr_handle_link_removal_on_standby");
    result = 4;
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v17 = "%s: psoc is null";
    goto LABEL_9;
  }
  if ( *(_BYTE *)(a2 + 6) )
  {
    v14 = 0;
    v15 = 0;
    v16 = (unsigned __int16 *)(a2 + 16);
    do
    {
      if ( v14 == 2 )
        __break(0x5512u);
      if ( *((_BYTE *)v16 - 1) && *v16 )
      {
        v19 = *((unsigned __int8 *)v16 - 8);
        ap_link_by_link_id = (unsigned __int8 *)mlo_mgr_get_ap_link_by_link_id(
                                                  *(_QWORD *)(a1 + 1360),
                                                  *((unsigned __int8 *)v16 - 8));
        if ( !ap_link_by_link_id )
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: link info null, id %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "policy_mgr_handle_link_removal_on_standby",
            v19);
          result = 29;
          goto LABEL_10;
        }
        v29 = ap_link_by_link_id;
        LODWORD(v50) = ap_link_by_link_id[24];
        LODWORD(v52) = ap_link_by_link_id[26];
        LODWORD(v53) = ap_link_by_link_id[29];
        LODWORD(v51) = ap_link_by_link_id[25];
        LODWORD(v49) = ap_link_by_link_id[5];
        LODWORD(v48) = ap_link_by_link_id[2];
        LODWORD(v47) = ap_link_by_link_id[1];
        LODWORD(v46) = *ap_link_by_link_id;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: AP removal tbtt %d vdev %d link %d flag 0x%x STA MAC %02x:%02x:%02x:**:**:%02x BSSID %02x:%02x:%02x:**:**:%02x",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "policy_mgr_handle_link_removal_on_standby",
          *v16,
          ap_link_by_link_id[12],
          v19,
          *((unsigned int *)ap_link_by_link_id + 4),
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53);
        if ( *((_DWORD *)v29 + 6) | *((unsigned __int16 *)v29 + 14) )
        {
          if ( v29[12] == 255 )
          {
            _X9 = (unsigned __int64 *)(v29 + 16);
            __asm { PRFM            #0x11, [X9] }
            do
              v36 = __ldxr(_X9);
            while ( __stlxr(v36 | 1, _X9) );
            __dmb(0xBu);
            if ( (v36 & 1) == 0 )
              v15 |= 1 << v19;
          }
        }
      }
      ++v14;
      v16 += 5;
    }
    while ( v14 < *(unsigned __int8 *)(a2 + 6) );
    if ( !v15 )
      goto LABEL_26;
    v37 = policy_mgr_mlo_sta_set_nlink(v12, *(unsigned __int8 *)(a1 + 168), 3u, 2u, 0, v15, 0, 0);
    result = 0;
    if ( v37 != 24 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: status %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "policy_mgr_handle_link_removal_on_standby",
        v37);
      result = v37;
    }
  }
  else
  {
LABEL_26:
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
