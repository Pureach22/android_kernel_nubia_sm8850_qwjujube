__int64 __fastcall wifi_pos_oem_rsp_handler(__int64 a1, unsigned int *a2)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  unsigned int v17; // w21
  _DWORD *v18; // x24
  unsigned int v19; // w9
  size_t v20; // x22
  __int64 v21; // x3
  __int64 v22; // x4
  const char *v23; // x2
  void *v25; // x0
  __int64 v26; // x23

  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( !psoc_priv_obj )
  {
    v23 = "%s: private object is NULL";
LABEL_18:
    qdf_trace_msg(0x25u, 2u, v23, v6, v7, v8, v9, v10, v11, v12, v13, "wifi_pos_oem_rsp_handler");
    return 4294967274LL;
  }
  v14 = psoc_priv_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_priv_obj + 88);
    v16 = *(_QWORD *)(v14 + 96);
  }
  else
  {
    raw_spin_lock_bh(psoc_priv_obj + 88);
    v16 = *(_QWORD *)(v14 + 96) | 1LL;
    *(_QWORD *)(v14 + 96) = v16;
  }
  v17 = *(_DWORD *)v14;
  v18 = *(_DWORD **)(v14 + 128);
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(v14 + 96) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v14 + 88);
  }
  else
  {
    raw_spin_unlock(v14 + 88);
  }
  if ( *a2 > 0x6BC || (v19 = a2[4], v19 >= 0x6BD) )
  {
    v23 = "%s: invalid length of Oem Data response";
    goto LABEL_18;
  }
  if ( !v18 )
  {
    v23 = "%s: invalid response handler";
    goto LABEL_18;
  }
  v20 = v19 + *a2 + a2[8];
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: oem data rsp, len: %d to pid: %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wifi_pos_oem_rsp_handler",
    (unsigned int)v20,
    v17);
  if ( !(a2[4] + a2[8]) )
  {
    v21 = *a2;
    v22 = *((_QWORD *)a2 + 1);
    if ( *(v18 - 1) != 1562231049 )
      __break(0x8238u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v18)(a1, v17, 5, v21, v22);
    return 0;
  }
  v25 = (void *)_qdf_mem_malloc(v20, "wifi_pos_oem_rsp_handler", 1266);
  if ( v25 )
  {
    v26 = (__int64)v25;
    qdf_mem_copy(v25, *((const void **)a2 + 1), *a2);
    qdf_mem_copy((void *)(v26 + *a2), *((const void **)a2 + 5), a2[8]);
    qdf_mem_copy((void *)(v26 + a2[8] + *a2), *((const void **)a2 + 3), a2[4]);
    if ( *(v18 - 1) != 1562231049 )
      __break(0x8238u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, __int64))v18)(a1, v17, 5, (unsigned int)v20, v26);
    _qdf_mem_free(v26);
    return 0;
  }
  return 4294967284LL;
}
