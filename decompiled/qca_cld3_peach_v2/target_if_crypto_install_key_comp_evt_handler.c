__int64 __fastcall target_if_crypto_install_key_comp_evt_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x20
  const char *v17; // x2
  __int64 result; // x0
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  int v22; // w9
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  __int64 comp_private_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x21
  void (__fastcall *v43)(__int64, __int128 *); // x8
  __int64 v44; // x0
  __int128 v45; // [xsp+28h] [xbp-38h] BYREF
  __int64 v46; // [xsp+38h] [xbp-28h] BYREF
  __int128 v47; // [xsp+40h] [xbp-20h] BYREF
  _QWORD v48[2]; // [xsp+50h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48[0] = 0;
  v47 = 0u;
  v46 = 0;
  if ( !a1 || !a2 )
  {
    v17 = "%s: invalid param";
    goto LABEL_11;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v17 = "%s: psoc is null";
    goto LABEL_11;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v17 = "%s: invalid wmi handle";
    goto LABEL_11;
  }
  v16 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_install_key_comp_event(v15, a2, a3, &v47) )
  {
    v17 = "%s: received invalid buf from target";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_crypto_install_key_comp_evt_handler");
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( v48 )
    v19 = LOBYTE(v48[0]);
  else
    v19 = 0;
  if ( v48 )
    v20 = BYTE1(v48[0]);
  else
    v20 = 0;
  if ( v48 )
    v21 = BYTE2(v48[0]);
  else
    v21 = 0;
  if ( v48 )
    v22 = BYTE5(v48[0]);
  else
    v22 = 0;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev %d mac %02x:%02x:%02x:**:**:%02x ix %x flags %x status %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_crypto_install_key_comp_evt_handler",
    (unsigned int)v47,
    v19,
    v20,
    v21,
    v22,
    DWORD1(v47),
    DWORD2(v47),
    HIDWORD(v47));
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          v16,
          (unsigned int)v47,
          19);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev %d is null",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "target_if_crypto_install_key_comp_evt_handler",
      (unsigned int)v47);
    goto LABEL_12;
  }
  v32 = v23;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v23, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: priv_obj is null",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "target_if_crypto_install_key_comp_evt_handler");
    wlan_objmgr_vdev_release_ref(v32, 19);
    goto LABEL_12;
  }
  v42 = comp_private_obj;
  v45 = v47;
  qdf_mem_copy(&v46, v48, 6u);
  v43 = *(void (__fastcall **)(__int64, __int128 *))(v42 + 440);
  if ( v43 )
  {
    v44 = *(_QWORD *)(v42 + 432);
    if ( *((_DWORD *)v43 - 1) != -895046096 )
      __break(0x8228u);
    v43(v44, &v45);
  }
  wlan_objmgr_vdev_release_ref(v32, 19);
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
