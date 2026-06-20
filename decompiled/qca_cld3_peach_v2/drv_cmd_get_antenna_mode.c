__int64 __fastcall drv_cmd_get_antenna_mode(__int64 a1, __int64 a2, const char *a3, __int64 a4, __int64 a5)
{
  __int64 vdev_by_user; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w8
  unsigned int v18; // w19
  __int64 v19; // x22
  __int64 dynamic_vdev_config; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  unsigned __int8 v30; // w0
  int v31; // w8
  __int64 v32; // x20
  unsigned __int64 v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v53; // x9
  _QWORD v54[5]; // [xsp+8h] [xbp-28h] BYREF

  v54[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v54, 0, 32);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "drv_cmd_get_antenna_mode");
  if ( vdev_by_user )
  {
    v17 = *(unsigned __int8 *)(a2 + 3752);
    v18 = *(_DWORD *)(a2 + 1452);
    if ( v17 == 1 )
    {
      v19 = vdev_by_user;
      dynamic_vdev_config = mlme_get_dynamic_vdev_config(vdev_by_user, v9, v10, v11, v12, v13, v14, v15, v16);
      if ( dynamic_vdev_config )
        v18 = *(_DWORD *)(dynamic_vdev_config + 8);
      else
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: nss chain dynamic config NULL",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "hdd_get_dynamic_antenna_mode");
      vdev_by_user = v19;
    }
    _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "drv_cmd_get_antenna_mode");
    scnprintf(v54, 32, "%s %d", a3, v18);
    v31 = *(_DWORD *)(a5 + 12);
    if ( v31 > v30 )
      LOBYTE(v31) = v30 + 1;
    v32 = (unsigned __int8)v31;
    if ( (unsigned __int8)v31 >= 0x21u )
    {
      _copy_overflow(32, (unsigned __int8)v31);
    }
    else
    {
      v33 = *(_QWORD *)a5;
      _check_object_size(v54, (unsigned __int8)v31, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v43 = v33, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v43 = v33 & ((__int64)(v33 << 8) >> 8);
      if ( 0x8000000000LL - v32 >= v43 )
      {
        v44 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v50 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v50 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v50);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v44);
        v32 = _arch_copy_to_user(v33 & 0xFF7FFFFFFFFFFFFFLL, v54, v32);
        v51 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v53 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v53 - 4096);
        _WriteStatusReg(TTBR1_EL1, v53);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v51);
      }
      if ( !v32 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Get antenna mode: %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "drv_cmd_get_antenna_mode",
          v18);
        result = 0;
        goto LABEL_19;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to copy data to user buffer",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "drv_cmd_get_antenna_mode");
    result = 4294967282LL;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "drv_cmd_get_antenna_mode");
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
