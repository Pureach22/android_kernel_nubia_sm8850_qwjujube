__int64 __fastcall ucfg_wifi_pos_process_req(
        __int64 a1,
        _DWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  unsigned int v28; // w24
  unsigned int v29; // w22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x8
  __int64 v39; // x5
  __int64 result; // x0
  _BYTE v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  v14 = qdf_trace_msg(0x25u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_wifi_pos_process_req");
  psoc = wifi_pos_get_psoc(v14);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  if ( !psoc_priv_obj )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: wifi_pos_psoc_obj is null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_wifi_pos_process_req");
LABEL_22:
    result = 29;
    goto LABEL_23;
  }
  v25 = psoc_priv_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(psoc_priv_obj + 88);
    v27 = *(_QWORD *)(v25 + 96);
  }
  else
  {
    raw_spin_lock_bh(psoc_priv_obj + 88);
    v27 = *(_QWORD *)(v25 + 96) | 1LL;
    *(_QWORD *)(v25 + 96) = v27;
  }
  *(_QWORD *)(v25 + 128) = a3;
  v28 = *(unsigned __int8 *)(v25 + 4);
  v29 = *(_DWORD *)v25;
  *(_DWORD *)(v25 + 176) = a2[9];
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(v25 + 96) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v25 + 88);
    v38 = *(_DWORD **)(v25 + 120);
    if ( v38 )
      goto LABEL_8;
    goto LABEL_19;
  }
  raw_spin_unlock(v25 + 88);
  v38 = *(_DWORD **)(v25 + 120);
  if ( !v38 )
  {
LABEL_19:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: wifi_pos_psoc_obj->wifi_pos_req_handler is null",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "ucfg_wifi_pos_process_req");
    v41[0] = 1;
    if ( *(a3 - 1) != 1562231049 )
      __break(0x8233u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _BYTE *))a3)(a1, v29, 6, 1, v41);
    goto LABEL_22;
  }
LABEL_8:
  if ( *a2 == 1 || (v39 = (unsigned int)a2[1], v28) && v29 == (_DWORD)v39 )
  {
    if ( *(v38 - 1) != 1722981501 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _DWORD *))v38)(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: requesting app is not registered, app_registered: %d, requesting pid: %d, stored pid: %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "ucfg_wifi_pos_process_req",
      v28,
      v39,
      v29);
    v41[0] = 2;
    if ( *(a3 - 1) != 1562231049 )
      __break(0x8233u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _BYTE *))a3)(a1, v29, 6, 1, v41);
    result = 4;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
