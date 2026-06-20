__int64 __fastcall vdev_mgr_create_send(
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
  __int16 v11; // w10
  unsigned int v13; // w8
  int v14; // w9
  int v15; // w10
  __int64 result; // x0
  const char *v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  unsigned __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h] BYREF
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v30) = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_MLME is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "vdev_mgr_create_send",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31);
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  v9 = *(_QWORD *)(a1 + 520);
  if ( !v9 )
  {
    v17 = "%s: VDEV is NULL";
LABEL_8:
    qdf_trace_msg(
      0x68u,
      2u,
      v17,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "vdev_mgr_create_param_update",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "vdev_mgr_create_send",
      4);
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(v9 + 216);
  if ( !v10 )
  {
    v17 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(_WORD *)(a1 + 24);
  v13 = *(unsigned __int8 *)(v10 + 40);
  LOBYTE(v26) = *(_BYTE *)(v9 + 168);
  v14 = *(unsigned __int8 *)(a1 + 179);
  WORD2(v27) = v11;
  v15 = *(unsigned __int8 *)(a1 + 180);
  HIDWORD(v26) = v14;
  LODWORD(v27) = v15;
  LOBYTE(v15) = *(_BYTE *)(a1 + 468);
  v28 = __PAIR64__(*(_DWORD *)(a1 + 464), v13);
  LOBYTE(v13) = *(_BYTE *)(a1 + 196);
  LOBYTE(v29) = v15;
  BYTE1(v29) = v13;
  BYTE2(v26) = -1;
  qdf_mem_copy((char *)&v29 + 2, (const void *)(v9 + 80), 6u);
  LODWORD(v30) = *(_DWORD *)(v9 + 164);
  result = tgt_vdev_mgr_create_send(a1, &v26);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
