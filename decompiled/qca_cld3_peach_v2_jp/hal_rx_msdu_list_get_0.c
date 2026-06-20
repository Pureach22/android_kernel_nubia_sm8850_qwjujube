_DWORD *__fastcall hal_rx_msdu_list_get_0(__int64 a1, __int64 a2, __int64 a3, __int16 *a4)
{
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  unsigned int *v10; // x25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *result; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  _DWORD *v21; // x22
  __int64 (*v22)(void); // x8
  void (__fastcall *v23)(unsigned int *, __int64 *); // x8
  char v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x24
  __int64 v34; // x28
  unsigned int *v35; // x25
  __int64 v36; // x21
  __int64 (*v37)(void); // x8
  void (__fastcall *v38)(unsigned int *, __int64 *); // x8
  char v39; // w9
  __int64 v40; // x6
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 (__fastcall *v49)(_QWORD); // x8
  _DWORD *v50; // x0
  _DWORD *v51; // x26
  __int16 v52; // w19
  __int64 (__fastcall *v53)(_QWORD); // x8
  __int16 *v54; // [xsp+0h] [xbp-20h]
  __int64 v55; // [xsp+8h] [xbp-18h] BYREF
  __int64 v56; // [xsp+10h] [xbp-10h]
  __int64 v57; // [xsp+18h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 74392);
  v55 = 0;
  v56 = 0;
  v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 424);
  if ( *((_DWORD *)v9 - 1) != -1437795666 )
    __break(0x8228u);
  v10 = (unsigned int *)v9(a2);
  result = (_DWORD *)qdf_trace_msg(
                       0x45u,
                       8u,
                       "[%s][%d] msdu_link=%pK msdu_details=%pK",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "hal_rx_msdu_list_get",
                       1436,
                       a2,
                       v10);
  if ( *v10 )
  {
    v54 = a4;
    v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 416LL);
    if ( *((_DWORD *)v20 - 1) != -1437795666 )
      __break(0x8228u);
    v21 = (_DWORD *)v20(v10);
    *v21 |= 1u;
    v22 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 74392) + 1480LL);
    if ( *((_DWORD *)v22 - 1) != 656476291 )
      __break(0x8228u);
    *(_DWORD *)a3 = v22();
    *(_WORD *)(a3 + 4) = (*v21 >> 3) & 0x3FFF;
    v23 = *(void (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(a1 + 74392) + 1456LL);
    if ( *((_DWORD *)v23 - 1) != -621572614 )
      __break(0x8228u);
    v23(v10, &v55);
    v24 = BYTE4(v56);
    *(_DWORD *)(a3 + 48) = v56;
    *(_BYTE *)(a3 + 72) = v24;
    *(_QWORD *)(a3 + 80) = *v10 | ((unsigned __int64)*((unsigned __int8 *)v10 + 4) << 32);
    qdf_trace_msg(
      0x45u,
      8u,
      "[%s][%d] i=%d sw_cookie=%d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hal_rx_msdu_list_get",
      1479,
      0);
    v33 = 0;
    v34 = a3 + 52;
    v35 = v10 + 4;
    v36 = a3;
    while ( *v35 )
    {
      v49 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 416LL);
      if ( *((_DWORD *)v49 - 1) != -1437795666 )
        __break(0x8228u);
      v50 = (_DWORD *)v49(v35);
      v51 = v50;
      if ( v33 == 4 )
        *v50 |= 2u;
      v37 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 74392) + 1480LL);
      if ( *((_DWORD *)v37 - 1) != 656476291 )
        __break(0x8228u);
      *(_DWORD *)(v36 + 8) = v37();
      v36 += 8;
      *(_WORD *)(v36 + 4) = (*v51 >> 3) & 0x3FFF;
      v38 = *(void (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(a1 + 74392) + 1456LL);
      if ( *((_DWORD *)v38 - 1) != -621572614 )
        __break(0x8228u);
      v38(v35, &v55);
      v39 = BYTE4(v56);
      *(_DWORD *)(v34 + 4 * v33) = v56;
      *(_BYTE *)(a3 + v33 + 73) = v39;
      *(_QWORD *)(a3 + 8 * v33 + 88) = *v35 | ((unsigned __int64)*((unsigned __int8 *)v35 + 4) << 32);
      v40 = *(unsigned int *)(v34 + 4 * v33++);
      result = (_DWORD *)qdf_trace_msg(
                           0x45u,
                           8u,
                           "[%s][%d] i=%d sw_cookie=%d",
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48,
                           "hal_rx_msdu_list_get",
                           1479,
                           (unsigned int)v33,
                           v40);
      v35 += 4;
      if ( v33 == 5 )
      {
        v52 = 6;
        goto LABEL_26;
      }
    }
    v52 = v33 + 1;
    v53 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 416LL);
    if ( *((_DWORD *)v53 - 1) != -1437795666 )
      __break(0x8228u);
    result = (_DWORD *)v53(v35 - 4);
    *result |= 2u;
LABEL_26:
    a4 = v54;
  }
  else
  {
    v52 = 0;
  }
  *a4 = v52;
  _ReadStatusReg(SP_EL0);
  return result;
}
