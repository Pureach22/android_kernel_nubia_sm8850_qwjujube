__int64 __fastcall wifi_pos_check_and_initiate_pasn_authentication(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w8
  __int64 result; // x0
  unsigned int v12; // w20
  unsigned int v14; // w20
  _QWORD *osif_callbacks; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD **v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _DWORD *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x4
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a2 + 12262);
  WORD2(v44) = -1;
  LODWORD(v44) = -1;
  if ( v10 || (v12 = *(unsigned __int8 *)(a2 + 6080), !*(_BYTE *)(a2 + 6080)) )
  {
    result = 0;
    goto LABEL_18;
  }
  if ( *(_DWORD *)(a1 + 16) )
  {
    v14 = 4;
LABEL_17:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Initiate Pasn Authentication failed",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wifi_pos_check_and_initiate_pasn_authentication",
      v44);
    wifi_pos_move_peers_to_fail_list(a1, &v44, 1);
    result = v14;
    goto LABEL_18;
  }
  osif_callbacks = (_QWORD *)wifi_pos_get_osif_callbacks(a1);
  if ( !osif_callbacks )
  {
    v43 = (const char *)&unk_98C763;
LABEL_15:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: OSIF %s cb is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wifi_pos_request_external_pasn_auth",
      v43,
      v44,
      v45);
LABEL_16:
    v14 = 16;
    goto LABEL_17;
  }
  if ( !*osif_callbacks )
  {
    v43 = "PASN";
    goto LABEL_15;
  }
  v25 = (_DWORD **)osif_callbacks;
  if ( !wifi_pos_get_vdev_priv_obj(a1) )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Wifi pos vdev priv obj is null",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wifi_pos_request_external_pasn_auth",
      v44,
      v45);
    goto LABEL_16;
  }
  v34 = *v25;
  if ( *(*v25 - 1) != 509300527 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v34)(a1, a2, v12, 1);
  if ( (_DWORD)result )
  {
    v14 = result;
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Initiate PASN auth failed",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wifi_pos_request_external_pasn_auth",
      v44,
      v45);
    goto LABEL_17;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
