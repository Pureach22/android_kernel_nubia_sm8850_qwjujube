_QWORD *__fastcall wma_get_beacon_buffer_by_vdev_id(
        unsigned __int8 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x22
  _QWORD *v22; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8
  int v25; // w9
  const char *v26; // x2
  unsigned int v27; // w20
  _QWORD *v28; // x0
  _QWORD *v29; // x22
  __int64 v30; // x8
  __int64 v31; // x8

  result = _cds_get_context(54, (__int64)"wma_get_beacon_buffer_by_vdev_id", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return result;
  if ( *((unsigned __int16 *)result + 81) <= (unsigned int)a1 )
  {
    v26 = "%s: Invalid vdev_id %u";
LABEL_13:
    qdf_trace_msg(0x36u, 2u, v26, v13, v14, v15, v16, v17, v18, v19, v20, "wma_get_beacon_buffer_by_vdev_id", a1);
    return nullptr;
  }
  v21 = result;
  if ( !wma_is_vdev_in_ap_mode((__int64)result, a1, v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    v26 = "%s: vdevid %d is not in AP mode";
    goto LABEL_13;
  }
  v22 = *(_QWORD **)(v21[65] + 488LL * a1 + 8);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: beacon invalid",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_get_beacon_buffer_by_vdev_id");
    return nullptr;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v22 + 13);
  }
  else
  {
    raw_spin_lock_bh(v22 + 13);
    v22[14] |= 1uLL;
  }
  v24 = *v22;
  if ( (*(_BYTE *)(*v22 + 68LL) & 4) != 0 )
    v25 = *(unsigned __int16 *)(v24 + 66);
  else
    v25 = 0;
  v27 = *(_DWORD *)(v24 + 112) + v25;
  v28 = (_QWORD *)_qdf_mem_malloc(v27, "wma_get_beacon_buffer_by_vdev_id", 3876);
  if ( !v28 )
  {
    v31 = v22[14];
    if ( (v31 & 1) != 0 )
    {
      v22[14] = v31 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v22 + 13);
    }
    else
    {
      raw_spin_unlock(v22 + 13);
    }
    return nullptr;
  }
  v29 = v28;
  qdf_mem_copy(v28, *(const void **)(*v22 + 224LL), v27);
  v30 = v22[14];
  if ( (v30 & 1) != 0 )
  {
    v22[14] = v30 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v22 + 13);
    result = v29;
    if ( a2 )
      goto LABEL_21;
  }
  else
  {
    raw_spin_unlock(v22 + 13);
    result = v29;
    if ( a2 )
LABEL_21:
      *a2 = v27;
  }
  return result;
}
