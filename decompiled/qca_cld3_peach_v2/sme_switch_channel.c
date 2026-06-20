__int64 __fastcall sme_switch_channel(__int64 a1, int *a2, unsigned int a3, int a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int16 v17; // w8
  int v18; // w9
  __int64 v19; // x19
  char v20; // w0
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w9
  int v26; // w10
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // [xsp+0h] [xbp-50h]
  int v45; // [xsp+8h] [xbp-48h]
  __int64 v46; // [xsp+18h] [xbp-38h] BYREF
  __int64 v47; // [xsp+20h] [xbp-30h]
  __int64 v48; // [xsp+28h] [xbp-28h]
  __int64 v49; // [xsp+30h] [xbp-20h]
  __int64 v50; // [xsp+38h] [xbp-18h]
  __int64 v51; // [xsp+40h] [xbp-10h]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v8 = _qdf_mem_malloc(0x24u, "sme_switch_channel", 17311);
  if ( v8 )
  {
    v17 = *((_WORD *)a2 + 2);
    v18 = *a2;
    v19 = v8;
    *(_DWORD *)(v8 + 4) = a3;
    *(_WORD *)(v8 + 32) = v17;
    *(_DWORD *)(v8 + 28) = v18;
    *(_DWORD *)(v8 + 12) = a4;
    v20 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), a3, v9, v10, v11, v12, v13, v14, v15, v16);
    v21 = *(unsigned __int8 *)(v19 + 28);
    v22 = *(unsigned __int8 *)(v19 + 29);
    v23 = *(unsigned __int8 *)(v19 + 30);
    v24 = *(unsigned __int8 *)(v19 + 33);
    v25 = *(_DWORD *)(v19 + 4);
    v26 = *(_DWORD *)(v19 + 12);
    *(_BYTE *)v19 = v20;
    *(_BYTE *)(v19 + 8) = 1;
    v45 = v26;
    v44 = v25;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: bssid %02x:%02x:%02x:**:**:%02x freq %u width %u",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "sme_switch_channel",
      v21,
      v22,
      v23,
      v24,
      v44,
      v45);
    LODWORD(v46) = 5295;
    v47 = v19;
    result = scheduler_post_message_debug(
               0x34u,
               0x35u,
               53,
               (unsigned __int16 *)&v46,
               0x43B7u,
               (__int64)"sme_switch_channel");
    if ( (_DWORD)result )
    {
      _qdf_mem_free(v19);
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_CSA_OFFLOAD_EVENT to PE",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "sme_switch_channel");
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
