__int64 __fastcall drv_cmd_max_tx_power(__int64 *a1, __int64 a2, char *s)
{
  __int64 v5; // x8
  size_t v6; // x0
  unsigned __int8 *v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  char v17; // t1
  unsigned int v18; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x1
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  int v32; // w20
  __int64 v33; // x28
  int v34; // w27
  unsigned __int8 *v35; // x9
  unsigned __int8 *v36; // x10
  unsigned __int8 *v37; // x11
  unsigned __int16 *v38; // x12
  unsigned __int8 *v39; // x8
  unsigned int v40; // w23
  unsigned int v41; // w25
  unsigned int v42; // w24
  __int64 v43; // x20
  __int64 v44; // x26
  __int64 v45; // x27
  __int64 v46; // x21
  __int64 v47; // x9
  unsigned __int64 v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  _DWORD *v58; // x26
  __int64 v59; // [xsp+0h] [xbp-A0h]
  __int64 v60; // [xsp+8h] [xbp-98h]
  __int64 v61; // [xsp+10h] [xbp-90h]
  __int64 v62; // [xsp+18h] [xbp-88h]
  __int64 v63; // [xsp+20h] [xbp-80h]
  __int64 v64; // [xsp+28h] [xbp-78h]
  unsigned __int64 v65; // [xsp+38h] [xbp-68h]
  __int64 v66; // [xsp+40h] [xbp-60h]
  unsigned int v67; // [xsp+4Ch] [xbp-54h]
  __int64 v68; // [xsp+50h] [xbp-50h]
  int v69; // [xsp+5Ch] [xbp-44h]
  __int64 v70; // [xsp+60h] [xbp-40h]
  __int64 v71; // [xsp+68h] [xbp-38h]
  unsigned __int64 v72; // [xsp+70h] [xbp-30h]
  unsigned __int64 v73; // [xsp+78h] [xbp-28h]
  __int64 v74; // [xsp+80h] [xbp-20h] BYREF
  __int64 v75; // [xsp+88h] [xbp-18h] BYREF
  unsigned int v76; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+98h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v76 = 0;
  v74 = 0;
  v75 = v5;
  v6 = strlen(s);
  v7 = (unsigned __int8 *)strnchr(s, v6, 32);
  if ( !v7 )
    goto LABEL_9;
  v16 = *v7;
  if ( v16 != 32 )
    goto LABEL_9;
  while ( (unsigned __int8)v16 == 32 )
  {
    v17 = *++v7;
    LOBYTE(v16) = v17;
  }
  if ( !(_BYTE)v16 )
  {
    v18 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_15;
    goto LABEL_13;
  }
  kstrtoint(v7, 10, &v76);
  v18 = v76;
  if ( v76 - 101 < 0xFFFFFF37 )
  {
LABEL_9:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid MAXTXPOWER command",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "drv_cmd_max_tx_power");
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: SETMAXTXPOWER: %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "hdd_parse_setmaxtxpower_command",
    v76);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
LABEL_15:
    raw_spin_lock(a2 + 32);
    goto LABEL_16;
  }
LABEL_13:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    goto LABEL_15;
  raw_spin_lock_bh(a2 + 32);
  *(_QWORD *)(a2 + 40) |= 1uLL;
LABEL_16:
  hdd_get_front_adapter_no_lock(a2, &v75);
  if ( v75 )
  {
    hdd_adapter_dev_hold_debug(v75, 7);
    v21 = v75;
  }
  else
  {
    v21 = 0;
  }
  hdd_get_next_adapter_no_lock(a2, v21, &v74);
  if ( v74 )
    hdd_adapter_dev_hold_debug(v74, 7);
  v22 = *(_QWORD *)(a2 + 40);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 40) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 32);
    v31 = v75;
    if ( v75 )
      goto LABEL_23;
LABEL_45:
    result = 0;
    goto LABEL_11;
  }
  raw_spin_unlock(a2 + 32);
  v31 = v75;
  if ( !v75 )
    goto LABEL_45;
LABEL_23:
  v65 = _ReadStatusReg(SP_EL0);
  v67 = v18;
  v32 = 255;
  v33 = 0xFFFF;
  v34 = 255;
  v66 = a2;
  v69 = 255;
  v68 = 255;
  while ( 1 )
  {
    if ( (*(_DWORD *)(v31 + 40) | 2) == 3 )
    {
      v35 = (unsigned __int8 *)(v31 + 1617);
      v36 = (unsigned __int8 *)(v31 + 1618);
      v37 = (unsigned __int8 *)(v31 + 1619);
      v38 = (unsigned __int16 *)(v31 + 1620);
      v39 = (unsigned __int8 *)(v31 + 1622);
LABEL_26:
      v40 = *v35;
      v41 = *v36;
      v42 = *v37;
      v33 = *v38;
      v43 = *v39;
      goto LABEL_27;
    }
    v58 = *(_DWORD **)(v31 + 52832);
    v40 = v32;
    v42 = v69;
    v43 = v68;
    v41 = v34;
    if ( hdd_cm_is_vdev_associated(v58) )
    {
      v35 = (unsigned __int8 *)(v58 + 77);
      v36 = (unsigned __int8 *)v58 + 309;
      v37 = (unsigned __int8 *)v58 + 310;
      v38 = (unsigned __int16 *)((char *)v58 + 311);
      v39 = (unsigned __int8 *)v58 + 313;
      goto LABEL_26;
    }
LABEL_27:
    v44 = *(unsigned __int8 *)(v75 + 1617);
    v45 = *(unsigned __int8 *)(v75 + 1618);
    v46 = *(unsigned __int8 *)(v75 + 1619);
    v71 = *(unsigned __int16 *)(v75 + 1620);
    LODWORD(v64) = v43;
    v70 = *(unsigned __int8 *)(v75 + 1622);
    LODWORD(v63) = v42;
    LODWORD(v62) = v41;
    LODWORD(v61) = v40;
    LODWORD(v60) = *(unsigned __int8 *)(v75 + 1622);
    LODWORD(v59) = *(unsigned __int8 *)(v75 + 1619);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Device mode %d max tx power %d selfMac: %02x:%02x:%02x:**:**:%02x bssId: %02x:%02x:%02x:**:**:%02x",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "drv_cmd_max_tx_power",
      *(unsigned int *)(v75 + 40),
      v67,
      v44,
      v45,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64);
    v68 = v43;
    v47 = (v43 << 40) | (v33 << 24);
    v69 = v42;
    v32 = v40;
    v48 = v72 & 0xFFFF000000000000LL | v44 | (v45 << 8);
    v34 = v41;
    v72 = v48 | (v46 << 16) | (v71 << 24) | (v70 << 40);
    v73 = v47 | ((unsigned __int64)v42 << 16) | ((unsigned __int64)v41 << 8) | v40 | v73 & 0xFFFF000000000000LL;
    if ( (unsigned int)sme_set_max_tx_power(*(_QWORD *)(v66 + 16)) )
      break;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Set max tx power success",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "drv_cmd_max_tx_power");
    hdd_adapter_dev_put_debug(v75, 7);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v65 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v66 + 32);
    }
    else
    {
      raw_spin_lock_bh(v66 + 32);
      *(_QWORD *)(v66 + 40) |= 1uLL;
    }
    v75 = v74;
    hdd_get_next_adapter_no_lock(v66, v74, &v74);
    hdd_validate_next_adapter(&v75, &v74, 7);
    if ( v74 )
      hdd_adapter_dev_hold_debug(v74, 7);
    v57 = *(_QWORD *)(v66 + 40);
    if ( (v57 & 1) != 0 )
    {
      *(_QWORD *)(v66 + 40) = v57 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v66 + 32);
      v31 = v75;
      if ( !v75 )
        goto LABEL_45;
    }
    else
    {
      raw_spin_unlock(v66 + 32);
      v31 = v75;
      if ( !v75 )
        goto LABEL_45;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Set max tx power failed",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "drv_cmd_max_tx_power");
  hdd_adapter_dev_put_debug(v75, 7);
  if ( v74 )
    hdd_adapter_dev_put_debug(v74, 7);
LABEL_10:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
