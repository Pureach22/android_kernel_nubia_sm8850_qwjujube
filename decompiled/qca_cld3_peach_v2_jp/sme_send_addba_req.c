__int64 __fastcall sme_send_addba_req(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, __int16 a4)
{
  unsigned int v5; // w22
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  void *v18; // x0
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  __int64 v29; // [xsp+8h] [xbp-38h] BYREF
  __int64 v30; // [xsp+10h] [xbp-30h]
  __int64 v31; // [xsp+18h] [xbp-28h]
  __int64 v32; // [xsp+20h] [xbp-20h]
  __int64 v33; // [xsp+28h] [xbp-18h]
  __int64 v34; // [xsp+30h] [xbp-10h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  LOWORD(v5) = a4;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 21560);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( !cm_is_vdevid_connected(v8, a2) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: STA not infra/connected state session_id: %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "sme_send_addba_req",
      a2);
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( !a1 || a2 > 5u || (v17 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v17 + 96LL * a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: CSR session is invalid", v9, v10, v11, v12, v13, v14, v15, v16, "sme_send_addba_req");
    goto LABEL_15;
  }
  v18 = (void *)_qdf_mem_malloc(0xAu, "sme_send_addba_req", 8388);
  if ( v18 )
  {
    v19 = (__int64)v18;
    v5 = (unsigned __int16)v5;
    wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), a2, v18);
    if ( !(_WORD)v5 )
    {
      if ( *(_WORD *)(a1 + 21622) )
        v5 = *(unsigned __int16 *)(a1 + 21622);
      else
        v5 = 64;
    }
    *(_BYTE *)(v19 + 6) = a2;
    *(_BYTE *)(v19 + 7) = a3;
    *(_WORD *)(v19 + 8) = v5;
    LOWORD(v29) = 4526;
    v30 = v19;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x34u,
                         0x36u,
                         54,
                         (unsigned __int16 *)&v29,
                         0x20D8u,
                         (__int64)"sme_send_addba_req") )
    {
      _qdf_mem_free(v19);
      result = 4294967291LL;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: ADDBA_REQ sent to FW: tid %d buff_size %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "sme_send_addba_req",
        a3,
        v5);
      result = 0;
    }
  }
  else
  {
    result = 4294967291LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
