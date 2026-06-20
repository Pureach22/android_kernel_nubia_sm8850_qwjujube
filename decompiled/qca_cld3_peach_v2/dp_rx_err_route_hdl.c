__int64 __fastcall dp_rx_err_route_hdl(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5, unsigned __int8 a6)
{
  __int64 v12; // x0
  unsigned int v13; // w25
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  _DWORD *v19; // x8
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned __int16 v21; // w0
  unsigned int v22; // w26
  __int64 result; // x0
  unsigned int v24; // w9
  unsigned int v25; // w8
  int v26; // w9
  int v27; // w9
  int v28; // w10
  __int64 (__fastcall *v29)(_QWORD); // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x26
  __int64 (*v39)(void); // x8
  _QWORD *v40; // x25
  __int64 v41; // x8
  unsigned __int64 v42; // x1
  __int64 v43; // x23
  __int64 v44; // x8
  void (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x0
  const void *v47; // x24
  int v48; // w8
  int v49; // w10
  __int64 v50; // x11
  __int64 v51; // x12
  int v52; // w10
  int v53; // w8
  __int64 v54; // x9
  _QWORD v55[2]; // [xsp+0h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 40);
  v55[0] = 0;
  LOWORD(v13) = wlan_cfg_rx_buffer_size(v12);
  v14 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 560LL);
  if ( *((_DWORD *)v14 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xFE | v14(a4) & 1;
  v15 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 576LL);
  if ( *((_DWORD *)v15 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xFB | (4 * (v15(a4) & 1));
  v16 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 496LL);
  if ( *((_DWORD *)v16 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xEF | (16 * (v16(a4) & 1));
  v17 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 568LL);
  if ( *((_DWORD *)v17 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xDF | (32 * (v17(a4) & 1));
  v18 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 512LL);
  if ( *((_DWORD *)v18 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xBF | ((v18(a4) & 1) << 6);
  v19 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
  if ( *(v19 - 1) != -177782713 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *))v19)(a4, v55);
  v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
  if ( *((_DWORD *)v20 - 1) != 855462014 )
    __break(0x8228u);
  v21 = v20(a4);
  if ( (*(char *)(a2 + 84) & 0x80000000) == 0 )
  {
    v22 = LOWORD(v55[0]) + v21 + *(unsigned __int16 *)(a1 + 1138);
    result = wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
    if ( v22 > (unsigned __int16)result )
    {
      if ( !a1 )
      {
LABEL_76:
        if ( a2 )
          result = _qdf_nbuf_free(a2);
        goto LABEL_78;
      }
      v54 = *(_QWORD *)(a1 + 13816) + v22;
      ++*(_QWORD *)(a1 + 13808);
      *(_QWORD *)(a1 + 13816) = v54;
      goto LABEL_59;
    }
    v24 = *(_DWORD *)(a2 + 112);
    if ( v22 >= (unsigned __int16)v13 )
      v13 = (unsigned __int16)v13;
    else
      v13 = v22;
    v25 = v13 - v24;
    if ( v13 < v24 )
    {
      skb_trim(a2, v13);
      goto LABEL_30;
    }
    if ( *(_DWORD *)(a2 + 116) )
    {
      v25 = v13 - v24;
      if ( v13 != v24 )
      {
        v26 = 0;
        goto LABEL_27;
      }
    }
    else
    {
      v28 = *(_DWORD *)(a2 + 208);
      v27 = *(_DWORD *)(a2 + 212);
      if ( v27 - v28 < v25 )
      {
        v26 = v28 - v27;
LABEL_27:
        if ( (unsigned int)pskb_expand_head(a2, 0, v26 + v25, 2080) )
          dev_kfree_skb_any_reason(a2, 1);
      }
    }
    skb_put(a2, v13 - *(_DWORD *)(a2 + 112));
  }
LABEL_30:
  v29 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1264LL);
  if ( *((_DWORD *)v29 - 1) != 855462014 )
    __break(0x8228u);
  result = v29(a4);
  if ( (_DWORD)result )
  {
    if ( !a3 )
      goto LABEL_58;
  }
  else
  {
    v38 = jiffies;
    if ( dp_rx_err_route_hdl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x45u, 2u, "%s: MSDU DONE failure", v30, v31, v32, v33, v34, v35, v36, v37, "dp_rx_err_route_hdl");
      dp_rx_err_route_hdl___last_ticks = v38;
    }
    v39 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1240LL);
    if ( *((_DWORD *)v39 - 1) != 343547449 )
      __break(0x8228u);
    result = v39();
    if ( !a3 )
    {
LABEL_58:
      if ( !a1 )
        goto LABEL_73;
      goto LABEL_59;
    }
  }
  v40 = *(_QWORD **)a3;
  if ( !*(_QWORD *)a3 )
  {
    v43 = jiffies;
    if ( dp_rx_err_route_hdl___last_ticks_78 - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(0x45u, 2u, "%s: Null vdev!", v30, v31, v32, v33, v34, v35, v36, v37, "dp_rx_err_route_hdl");
      dp_rx_err_route_hdl___last_ticks_78 = v43;
    }
    if ( !a1 )
      goto LABEL_76;
    ++*(_DWORD *)(a1 + 13748);
LABEL_59:
    if ( a5 == 2 )
    {
      ++*(_DWORD *)(a1 + 13712);
      goto LABEL_76;
    }
LABEL_73:
    if ( a1 && a5 == 1 )
      ++*(_DWORD *)(a1 + 13708);
    goto LABEL_76;
  }
  if ( *(char *)(a2 + 84) < 0 )
  {
    v44 = *(_QWORD *)(a2 + 40);
    v42 = *(unsigned __int16 *)(a1 + 1138);
    if ( v44 )
      *(_QWORD *)(a2 + 40) = v44 + v42;
  }
  else
  {
    v41 = *(_QWORD *)(a2 + 40);
    v42 = LOWORD(v55[0]) + (unsigned __int64)*(unsigned __int16 *)(a1 + 1138);
    if ( v41 )
      *(_QWORD *)(a2 + 40) = v42 + v41;
  }
  skb_pull(a2, v42);
  v45 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 832LL);
  if ( *((_DWORD *)v45 - 1) != 646946022 )
    __break(0x8228u);
  v45(a4);
  v46 = *(_QWORD *)(a2 + 224);
  *(_WORD *)(a2 + 62) = *(_WORD *)(a3 + 8);
  if ( !_qdf_nbuf_data_is_ipv4_eapol_pkt(v46) )
  {
    result = _qdf_nbuf_is_ipv4_wapi_pkt(a2);
    if ( (result & 1) == 0 )
      goto LABEL_58;
  }
  v47 = *(const void **)(a2 + 224);
  if ( (*(_BYTE *)(a3 + 10) & 8) == 0 || (unsigned int)qdf_mem_cmp(*(const void **)(a2 + 224), v40 + 13, 6u) )
  {
    result = qdf_mem_cmp(v47, v40 + 12, 6u);
    if ( (_DWORD)result )
      goto LABEL_58;
  }
  ++v40[358];
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v48 = *(unsigned __int16 *)(a2 + 66);
  else
    v48 = 0;
  v40[359] += (unsigned int)(*(_DWORD *)(a2 + 112) + v48);
  ++*(_QWORD *)(a3 + 32);
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v49 = *(unsigned __int16 *)(a2 + 66);
  else
    v49 = 0;
  v50 = a3 + 2288 + 4072LL * a6;
  v51 = *(_QWORD *)(v50 + 992);
  *(_QWORD *)(a3 + 40) += (unsigned int)(*(_DWORD *)(a2 + 112) + v49);
  *(_QWORD *)(v50 + 992) = v51 + 1;
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v52 = *(unsigned __int16 *)(a2 + 66);
  else
    v52 = 0;
  *(_QWORD *)(a3 + 2288 + 4072LL * a6 + 1000) += (unsigned int)(*(_DWORD *)(a2 + 112) + v52);
  v53 = *(_DWORD *)(a2 + 48);
  *(_QWORD *)a2 = 0;
  *(_DWORD *)(a2 + 48) = v53 | 0x80;
  result = dp_rx_deliver_to_stack(a1, (__int64)v40, a3, a2, 0);
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
