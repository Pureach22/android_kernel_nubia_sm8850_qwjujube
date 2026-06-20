__int64 __fastcall disa_core_encrypt_decrypt_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x24
  unsigned __int64 StatusReg; // x8
  int v26; // w25
  unsigned int v27; // w21
  __int64 v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int ref; // w0
  unsigned int v39; // w1
  double v41; // d0
  unsigned int v42; // w0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "disa_core_encrypt_decrypt_req");
  v24 = gp_disa_ctx;
  if ( gp_disa_ctx )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v24 + 24);
      v26 = *(unsigned __int8 *)(v24 + 16);
      if ( (v26 & 1) != 0 )
      {
LABEL_6:
        v27 = 4;
        goto LABEL_10;
      }
    }
    else
    {
      raw_spin_lock_bh(v24 + 24);
      *(_QWORD *)(v24 + 32) |= 1uLL;
      v26 = *(unsigned __int8 *)(v24 + 16);
      if ( (v26 & 1) != 0 )
        goto LABEL_6;
    }
    v27 = 0;
    *(_QWORD *)v24 = a3;
    *(_QWORD *)(v24 + 8) = a4;
    *(_BYTE *)(v24 + 16) = 1;
LABEL_10:
    v28 = *(_QWORD *)(v24 + 32);
    if ( (v28 & 1) != 0 )
    {
      *(_QWORD *)(v24 + 32) = v28 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v24 + 24);
      if ( v26 )
        goto LABEL_12;
    }
    else
    {
      raw_spin_unlock(v24 + 24);
      if ( v26 )
      {
LABEL_12:
        v37 = "%s: A request is already active!";
        goto LABEL_16;
      }
    }
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0x1Fu, v29, v30, v31, v32, v33, v34, v35, v36);
    if ( !ref )
    {
      v41 = tgt_disa_encrypt_decrypt_req(a1, a2);
      v27 = v42;
      wlan_objmgr_psoc_release_ref(a1, 0x1Fu, v41, v43, v44, v45, v46, v47, v48, v49);
      v37 = "%s: exit";
      v39 = 8;
      goto LABEL_17;
    }
    v27 = ref;
    v37 = "%s: DISA cannot get the reference out of psoc";
LABEL_16:
    v39 = 2;
LABEL_17:
    qdf_trace_msg(0x5Cu, v39, v37, v29, v30, v31, v32, v33, v34, v35, v36, "disa_core_encrypt_decrypt_req");
    return v27;
  }
  qdf_trace_msg(
    0x5Cu,
    2u,
    "%s: DISA context is NULL!",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "disa_core_encrypt_decrypt_req");
  return 4;
}
