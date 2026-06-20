__int64 __fastcall tgt_vdev_mgr_create_complete(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x8
  __int64 v13; // x21
  unsigned int (__fastcall *v14)(__int64, int *); // x8
  int v15; // w10
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  unsigned int (__fastcall *v27)(__int64, int *); // x10
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  __int64 (__fastcall *v37)(__int64, int *); // x10
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w20
  int v48; // [xsp+Ch] [xbp-14h] BYREF
  int v49; // [xsp+10h] [xbp-10h]
  int v50; // [xsp+14h] [xbp-Ch]
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 504);
  v10 = *(_QWORD *)(v9 + 152);
  v11 = *(unsigned __int8 *)(v9 + 104);
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 || (v13 = *(_QWORD *)(v12 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_18;
  }
  v14 = *(unsigned int (__fastcall **)(__int64, int *))(v13 + 1448);
  if ( !v14 )
  {
LABEL_18:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_vdev_mgr_create_complete",
      v11);
    result = 4;
    goto LABEL_19;
  }
  v15 = *(_DWORD *)(a1 + 276);
  v17 = *(_QWORD *)(a1 + 504);
  v48 = *(unsigned __int8 *)(v9 + 104);
  v49 = 8;
  v50 = v15;
  if ( *((_DWORD *)v14 - 1) != 736056775 )
    __break(0x8228u);
  if ( v14(v17, &v48) )
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Failed to set min idle inactive time!",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "tgt_vdev_mgr_create_complete",
      v11);
  v26 = *(_DWORD *)(a1 + 280);
  v27 = *(unsigned int (__fastcall **)(__int64, int *))(v13 + 1448);
  v49 = 9;
  v50 = v26;
  if ( *((_DWORD *)v27 - 1) != 736056775 )
    __break(0x822Au);
  if ( v27(v9, &v48) )
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Failed to set max idle inactive time!",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "tgt_vdev_mgr_create_complete",
      v11);
  v36 = *(_DWORD *)(a1 + 284);
  v37 = *(__int64 (__fastcall **)(__int64, int *))(v13 + 1448);
  v49 = 10;
  v50 = v36;
  if ( *((_DWORD *)v37 - 1) != 736056775 )
    __break(0x822Au);
  result = v37(v9, &v48);
  if ( (_DWORD)result )
  {
    v47 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Failed to set max unresponse inactive time!",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "tgt_vdev_mgr_create_complete",
      v11);
    result = v47;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
