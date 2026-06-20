__int64 __fastcall tgt_reg_chan_list_ext_update_handler(
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 v24; // x8
  __int64 v25; // x22
  __int64 v26; // x24
  __int64 v27; // x0
  __int64 v28; // x19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int v38; // w20
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v49; // x2
  __int64 v50; // x21
  unsigned int (__fastcall *v51)(_QWORD); // x8

  qdf_trace_msg(0x49u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "tgt_reg_chan_list_ext_update_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v49 = "%s: psoc ptr is NULL";
LABEL_18:
    qdf_trace_msg(0x49u, 2u, v49, v15, v16, v17, v18, v19, v20, v21, v22, "tgt_reg_chan_list_ext_update_handler");
    return 4294967274LL;
  }
  v23 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_ops is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_regulatory_get_rx_ops");
    v49 = "%s: reg_rx_ops is NULL";
    goto LABEL_18;
  }
  if ( !*(_QWORD *)(v23 + 432) )
  {
    v49 = "%s: master_list_ext_handler is NULL";
    goto LABEL_18;
  }
  v24 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v24 || (v25 = *(_QWORD *)(v24 + 16)) == 0 )
  {
    v49 = "%s: invalid wmi handle";
    goto LABEL_18;
  }
  v26 = psoc_from_scn_hdl;
  v27 = _qdf_mem_malloc(0x178u, "tgt_reg_chan_list_ext_update_handler", 443);
  if ( !v27 )
    return 4294967284LL;
  v28 = v27;
  if ( (unsigned int)wmi_extract_reg_chan_list_ext_update_event(v25, a2, v27, a3) )
  {
    v37 = "%s: Extraction of ext channel list event failed";
  }
  else
  {
    if ( *(unsigned __int8 *)(v28 + 13) >= 3u )
    {
      v50 = jiffies;
      if ( tgt_reg_chan_list_ext_update_handler___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: phy_id %d is out of bounds",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "tgt_reg_chan_list_ext_update_handler");
        tgt_reg_chan_list_ext_update_handler___last_ticks = v50;
      }
      goto LABEL_10;
    }
    *(_QWORD *)v28 = v26;
    v51 = *(unsigned int (__fastcall **)(_QWORD))(v23 + 432);
    if ( *((_DWORD *)v51 - 1) != 218176786 )
      __break(0x8228u);
    if ( !v51(v28) )
    {
      v38 = 0;
      goto LABEL_11;
    }
    v37 = "%s: Failed to process master ext channel list handler";
  }
  qdf_trace_msg(0x49u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "tgt_reg_chan_list_ext_update_handler");
LABEL_10:
  v38 = -14;
LABEL_11:
  _qdf_mem_free(*(_QWORD *)(v28 + 64));
  _qdf_mem_free(*(_QWORD *)(v28 + 72));
  _qdf_mem_free(*(_QWORD *)(v28 + 344));
  v39 = *(_QWORD *)(v28 + 360);
  if ( v39 )
    _qdf_mem_free(v39);
  _qdf_mem_free(*(_QWORD *)(v28 + 248));
  _qdf_mem_free(*(_QWORD *)(v28 + 280));
  _qdf_mem_free(*(_QWORD *)(v28 + 288));
  _qdf_mem_free(*(_QWORD *)(v28 + 256));
  _qdf_mem_free(*(_QWORD *)(v28 + 296));
  _qdf_mem_free(*(_QWORD *)(v28 + 304));
  _qdf_mem_free(*(_QWORD *)(v28 + 264));
  _qdf_mem_free(*(_QWORD *)(v28 + 312));
  _qdf_mem_free(*(_QWORD *)(v28 + 320));
  _qdf_mem_free(*(_QWORD *)(v28 + 272));
  _qdf_mem_free(*(_QWORD *)(v28 + 328));
  _qdf_mem_free(*(_QWORD *)(v28 + 336));
  _qdf_mem_free(v28);
  qdf_trace_msg(0x49u, 8u, "%s: exit", v40, v41, v42, v43, v44, v45, v46, v47, "tgt_reg_chan_list_ext_update_handler");
  return v38;
}
