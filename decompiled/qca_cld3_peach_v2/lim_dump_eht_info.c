__int64 __fastcall lim_dump_eht_info(__int64 result)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x21
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned int v8; // w21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  _BYTE *v26; // x22
  unsigned int v27; // w8
  int v28; // w4
  int v29; // w5
  int v30; // w6
  int v31; // w7
  _QWORD *v32; // x9
  unsigned __int8 v33; // w0
  unsigned __int8 v34; // w19
  int v35; // w4
  int v36; // w5
  int v37; // w6
  int v38; // w7
  char v39; // w0
  int v40; // w4
  int v41; // w5
  int v42; // w6
  int v43; // w7
  char v44; // w0
  int v45; // [xsp+28h] [xbp-78h] BYREF
  __int16 v46; // [xsp+2Ch] [xbp-74h]
  _QWORD v47[12]; // [xsp+30h] [xbp-70h] BYREF
  int v48; // [xsp+90h] [xbp-10h]
  __int64 v49; // [xsp+98h] [xbp-8h]

  v1 = result + 0x2000;
  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(result + 10071);
  v46 = 0;
  v45 = 0;
  v48 = 0;
  memset(v47, 0, sizeof(v47));
  if ( v2 != 1 )
    goto LABEL_30;
  v3 = *(_QWORD *)(result + 16);
  v4 = result;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v3 + 1344);
  }
  else
  {
    raw_spin_lock_bh(v3 + 1344);
    *(_QWORD *)(v3 + 1352) |= 1uLL;
  }
  v6 = *(_QWORD *)(v4 + 16);
  v7 = *(_QWORD *)(v6 + 1352);
  v8 = *(_DWORD *)(v6 + 48);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(v6 + 1352) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v6 + 1344);
  }
  else
  {
    raw_spin_unlock(v6 + 1344);
  }
  result = wlan_vdev_get_bss_peer_mld_mac(*(_QWORD *)(v4 + 16), &v45, v9, v10, v11, v12, v13, v14, v15, v16);
  v25 = *(_QWORD *)(v4 + 112);
  if ( !v25 )
    goto LABEL_30;
  v26 = (_BYTE *)(v25 + 4096);
  v27 = *(unsigned __int8 *)(v25 + 4368);
  if ( !v26[272] )
  {
    v32 = nullptr;
LABEL_29:
    result = qdf_trace_msg(
               0x35u,
               8u,
               " 802.11be D-3.0, MLD: %02x:%02x:%02x:**:**:%02x 320MHz %d num_sounding_dim_320 %d, eMLSR %d, partner_links %d, %s",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               (unsigned __int8)v45,
               BYTE1(v45),
               BYTE2(v45),
               HIBYTE(v46),
               ((unsigned int)*(_QWORD *)(v1 + 1881) >> 17) & 1,
               (*(_QWORD *)(v1 + 1881) >> 39) & 7,
               (v8 >> 10) & 1,
               v27,
               v32);
LABEL_30:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v26 == (_BYTE *)-280LL )
  {
    v30 = 0;
    v28 = 0;
    v29 = 0;
    v31 = 0;
  }
  else
  {
    v28 = (unsigned __int8)v26[280];
    v29 = (unsigned __int8)v26[281];
    v30 = (unsigned __int8)v26[282];
    v31 = (unsigned __int8)v26[285];
  }
  v17 = scnprintf(v47, 100, "Link %d: %02x:%02x:%02x:**:**:%02x", (unsigned __int8)v26[286], v28, v29, v30, v31);
  v27 = (unsigned __int8)v26[272];
  v34 = v33;
  if ( v27 < 2 || v33 > 0x63u )
    goto LABEL_26;
  if ( v26 == (_BYTE *)-328LL )
  {
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v38 = 0;
  }
  else
  {
    v35 = (unsigned __int8)v26[328];
    v36 = (unsigned __int8)v26[329];
    v37 = (unsigned __int8)v26[330];
    v38 = (unsigned __int8)v26[333];
  }
  v17 = scnprintf(
          (char *)v47 + (v33 & 0x7F),
          100 - (v33 & 0x7Fu),
          "Link %d: %02x:%02x:%02x:**:**:%02x",
          (unsigned __int8)v26[334],
          v35,
          v36,
          v37,
          v38);
  v27 = (unsigned __int8)v26[272];
  v34 += v39;
  if ( v27 < 3 || v34 > 0x63u )
    goto LABEL_26;
  if ( v26 == (_BYTE *)-376LL )
  {
    v42 = 0;
    v40 = 0;
    v41 = 0;
    v43 = 0;
  }
  else
  {
    v40 = (unsigned __int8)v26[376];
    v41 = (unsigned __int8)v26[377];
    v42 = (unsigned __int8)v26[378];
    v43 = (unsigned __int8)v26[381];
  }
  v17 = scnprintf(
          (char *)v47 + v34,
          100LL - v34,
          "Link %d: %02x:%02x:%02x:**:**:%02x",
          (unsigned __int8)v26[382],
          v40,
          v41,
          v42,
          v43);
  v27 = (unsigned __int8)v26[272];
  v34 += v44;
  if ( v27 < 4 || v34 >= 0x64u )
  {
LABEL_26:
    if ( v34 )
      v32 = v47;
    else
      v32 = nullptr;
    goto LABEL_29;
  }
  __break(0x5512u);
  return pe_get_active_session_count(v17);
}
