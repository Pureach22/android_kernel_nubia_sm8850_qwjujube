__int64 __fastcall csr_set_vdev_ies_per_band(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x20
  unsigned __int8 v8; // w23
  unsigned __int16 vdev_dot11_mode; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  result = _qdf_mem_malloc(0x10u, "csr_set_vdev_ies_per_band", 8376);
  if ( result )
  {
    v7 = result;
    v8 = csr_translate_to_wni_cfg_dot11_mode(a1, *(unsigned int *)(a1 + 17204));
    *(_DWORD *)(v7 + 4) = (unsigned __int8)a2;
    *(_DWORD *)(v7 + 12) = a3;
    vdev_dot11_mode = csr_get_vdev_dot11_mode(a1, a2, v8);
    *(_WORD *)(v7 + 8) = vdev_dot11_mode;
    *(_DWORD *)v7 = 1053824;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: SET_VDEV_IES_PER_BAND: vdev_id %d mlme_dot11_mode %d dot11mode %d dev_mode %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "csr_set_vdev_ies_per_band",
      (unsigned __int8)a2,
      v8,
      vdev_dot11_mode,
      a3);
    result = umac_send_mb_message_to_mac(v7);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x34u,
               2u,
               "%s: Send eWNI_SME_SET_VDEV_IES_PER_BAND fail",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "csr_set_vdev_ies_per_band");
  }
  return result;
}
