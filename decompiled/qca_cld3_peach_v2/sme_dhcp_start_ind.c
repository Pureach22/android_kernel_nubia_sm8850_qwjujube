__int64 __fastcall sme_dhcp_start_ind(__int64 a1, char a2, const void *a3, unsigned __int8 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x25
  __int64 v18; // x0
  __int64 v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  __int64 v29; // [xsp+8h] [xbp-38h] BYREF
  __int64 v30; // [xsp+10h] [xbp-30h]
  __int64 v31; // [xsp+18h] [xbp-28h]
  __int64 v32; // [xsp+20h] [xbp-20h]
  __int64 v33; // [xsp+28h] [xbp-18h]
  __int64 v34; // [xsp+30h] [xbp-10h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( a4 <= 5u && (v17 = *(_QWORD *)(a1 + 17296) + 96LL * a4) != 0 )
    {
      *(_BYTE *)(v17 + 62) = 0;
      *(_BYTE *)(v17 + 88) = 1;
      v18 = _qdf_mem_malloc(0x12u, "sme_dhcp_start_ind", 4187);
      if ( !v18 )
      {
        v28 = 2;
        goto LABEL_9;
      }
      v19 = v18;
      *(_BYTE *)(v18 + 4) = a2;
      *(_DWORD *)v18 = 1183924;
      qdf_mem_copy((void *)(v18 + 5), a3, 6u);
      wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a4, (void *)(v19 + 11));
      LODWORD(v29) = 4276;
      v30 = v19;
      qdf_trace(52, 0xFBu, a4, 4276);
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x34u,
                            0x36u,
                            54,
                            (unsigned __int16 *)&v29,
                            0x1070u,
                            (__int64)"sme_dhcp_start_ind") )
      {
        v28 = 0;
        goto LABEL_9;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Post DHCP Start MSG fail",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "sme_dhcp_start_ind");
      _qdf_mem_free(v19);
      *(_BYTE *)(v17 + 88) = 0;
    }
    else
    {
      qdf_trace_msg(0x34u, 2u, "%s: Session: %d not found", v9, v10, v11, v12, v13, v14, v15, v16, "sme_dhcp_start_ind");
    }
    v28 = 16;
LABEL_9:
    qdf_mutex_release(a1 + 12848);
    result = v28;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
