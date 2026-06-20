void *__fastcall populate_dot11f_link_iden(__int64 *a1, _BYTE *a2, __int64 a3, char a4)
{
  _BYTE *v6; // x23
  _BYTE *v7; // x24
  void *v9; // x22
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
  __int64 v26; // x8
  const void *v27; // x1
  void *v28; // x0
  void *result; // x0
  __int64 v30; // [xsp+0h] [xbp-10h] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v6 = a2 + 7;
  v7 = a2 + 13;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v30) = a3;
  if ( a4 )
    v9 = a2 + 13;
  else
    v9 = a2 + 7;
  WORD2(v30) = WORD2(a3);
  qdf_mem_copy(a2 + 1, a1 + 3, 6u);
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1[2], v10, v11, v12, v13, v14, v15, v16, v17) & 1) == 0 )
  {
    v27 = (char *)a1 + 30;
    goto LABEL_8;
  }
  v26 = *(_QWORD *)(a1[2] + 1360);
  if ( v26 )
  {
    v27 = (const void *)(v26 + 17);
LABEL_8:
    qdf_mem_copy(v9, v27, 6u);
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: mlo_dev_ctx is NULL",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "lim_tdls_copy_self_mac",
    v30,
    v31);
LABEL_9:
  if ( a4 )
    v28 = v6;
  else
    v28 = v7;
  result = qdf_mem_copy(v28, &v30, 6u);
  *a2 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
