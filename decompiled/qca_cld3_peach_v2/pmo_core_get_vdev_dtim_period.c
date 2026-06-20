__int64 __fastcall pmo_core_get_vdev_dtim_period(__int64 a1)
{
  __int64 v2; // x8
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  bool v16; // w21
  __int64 v17; // x8
  _BYTE v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 216);
  v19[0] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v2 + 80), 4u);
  if ( !comp_private_obj )
    goto LABEL_10;
  v12 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1040);
    v14 = *(_DWORD **)(v12 + 1024);
    if ( v14 )
      goto LABEL_6;
LABEL_13:
    v16 = 0;
    v17 = *(_QWORD *)(v12 + 1048);
    if ( (v17 & 1) == 0 )
      goto LABEL_9;
LABEL_14:
    *(_QWORD *)(v12 + 1048) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 1040);
    if ( v16 )
      goto LABEL_11;
    goto LABEL_10;
  }
  raw_spin_lock_bh(comp_private_obj + 1040);
  *(_QWORD *)(v12 + 1048) |= 1uLL;
  v14 = *(_DWORD **)(v12 + 1024);
  if ( !v14 )
    goto LABEL_13;
LABEL_6:
  v15 = *(unsigned __int8 *)(a1 + 168);
  if ( *(v14 - 1) != -1427996311 )
    __break(0x8228u);
  v16 = ((unsigned int (__fastcall *)(__int64, _BYTE *))v14)(v15, v19) == 0;
  v17 = *(_QWORD *)(v12 + 1048);
  if ( (v17 & 1) != 0 )
    goto LABEL_14;
LABEL_9:
  raw_spin_unlock(v12 + 1040);
  if ( !v16 )
LABEL_10:
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to get to dtim period for vdevId %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "pmo_core_get_vdev_dtim_period",
      *(unsigned __int8 *)(a1 + 168));
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v19[0];
}
