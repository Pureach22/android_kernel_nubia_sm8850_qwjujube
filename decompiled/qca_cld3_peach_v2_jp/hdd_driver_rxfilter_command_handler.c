__int64 __fastcall hdd_driver_rxfilter_command_handler(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x8
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _QWORD *v15; // x21
  __int64 result; // x0
  __int64 v17; // x20
  _BYTE *v18; // x25
  int v19; // w10
  __int64 v20; // x0
  __int64 v21; // x1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _DWORD *v30; // x21
  unsigned int v31; // w8
  unsigned __int64 v32; // x28
  unsigned int v33; // w27
  int *v34; // x26
  const char *v35; // x22
  const char *v36; // x2
  const char *v37; // x3
  unsigned int v38; // w1
  unsigned int v39; // w19
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  unsigned __int8 *v43; // x8
  int v44; // w10
  __int64 v45; // [xsp+0h] [xbp-20h]
  _BYTE v46[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a3 & 1) != 0 )
    v5 = 13;
  else
    v5 = 16;
  v46[0] = 0;
  v6 = kstrtou8(a1 + v5, 10, v46);
  if ( (v6 & 0x80000000) != 0 )
  {
    v36 = "%s: kstrtou8 failed invalid input value";
    v37 = "hdd_driver_rxfilter_command_handler";
LABEL_18:
    v38 = 2;
LABEL_19:
    qdf_trace_msg(0x33u, v38, v36, v7, v8, v9, v10, v11, v12, v13, v14, v37);
    result = 4294967274LL;
    goto LABEL_21;
  }
  if ( v46[0] != 2 )
  {
    v39 = v6;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Unsupported RXFILTER type %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_driver_rxfilter_command_handler");
    result = v39;
    goto LABEL_21;
  }
  v15 = *(_QWORD **)(a2 + 24);
  result = _wlan_hdd_validate_context(v15, "hdd_set_rx_filter");
  if ( (_DWORD)result )
  {
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v17 = v15[2];
  if ( !v17 )
  {
    v36 = "%s: MAC Handle is NULL";
    v37 = "hdd_set_rx_filter";
    goto LABEL_18;
  }
  if ( (ucfg_pmo_is_mc_addr_list_enabled(*v15) & 1) == 0 )
  {
    v36 = "%s: mc addr ini is disabled";
    v37 = "hdd_set_rx_filter";
    v38 = 3;
    goto LABEL_19;
  }
  v18 = (_BYTE *)(a2 + 39400);
  v19 = *(_DWORD *)(a2 + 40) | 2;
  *(_BYTE *)(a2 + 39616) = (a3 & 1) == 0;
  if ( v19 != 2 || !*v18 || !hdd_cm_is_vdev_associated(*(_DWORD **)(a2 + 52824)) )
  {
    qdf_trace_msg(0x33u, 8u, "%s: mode %d mc_cnt %d", v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_rx_filter");
    result = 0;
    goto LABEL_21;
  }
  v20 = _qdf_mem_malloc(0x5B4u, "hdd_set_rx_filter", 5892);
  if ( !v20 )
  {
    result = 4294967284LL;
    goto LABEL_21;
  }
  v30 = (_DWORD *)v20;
  *(_BYTE *)(v20 + 1456) = a3 & 1;
  v31 = (unsigned __int8)*v18;
  if ( !*v18 )
  {
    v33 = 0;
LABEL_36:
    *v30 = v33;
    sme_8023_multicast_list(v17, *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL), v30);
    _qdf_mem_free((__int64)v30);
    result = 0;
    goto LABEL_21;
  }
  v32 = 0;
  v33 = 0;
  v34 = (int *)(a2 + 39401);
  if ( (a3 & 1) != 0 )
    v35 = "setting";
  else
    v35 = "clearing";
  while ( v32 != 33 )
  {
    if ( *(_BYTE *)v34 == 1 )
    {
      if ( v33 > 0xEF )
        break;
      v44 = *v34;
      v43 = (unsigned __int8 *)v30 + 6 * v33 + 4;
      *((_WORD *)v43 + 2) = *((_WORD *)v34 + 2);
      *(_DWORD *)v43 = v44;
      if ( v43 )
      {
        v40 = *v43;
        v41 = v43[1];
        v42 = v43[2];
        LODWORD(v43) = v43[5];
      }
      else
      {
        v42 = 0;
        v40 = 0;
        v41 = 0;
      }
      LODWORD(v45) = (_DWORD)v43;
      v20 = qdf_trace_msg(
              0x33u,
              8u,
              "%s: %s RX filter : addr =%02x:%02x:%02x:**:**:%02x",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              "hdd_set_rx_filter",
              v35,
              v40,
              v41,
              v42,
              v45);
      if ( ++v33 == 240 )
        goto LABEL_36;
      v31 = (unsigned __int8)*v18;
    }
    ++v32;
    v34 = (int *)((char *)v34 + 6);
    if ( v32 >= v31 )
      goto LABEL_36;
  }
  __break(0x5512u);
  return hdd_alloc_chan_cache(v20, v21);
}
