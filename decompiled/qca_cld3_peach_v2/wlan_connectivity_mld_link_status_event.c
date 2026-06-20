__int64 __fastcall wlan_connectivity_mld_link_status_event(__int64 a1, unsigned __int8 *a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 result; // x0
  _QWORD *v14; // x21
  unsigned __int16 *v15; // x8
  int v16; // w20
  unsigned __int16 *v17; // x8
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  unsigned __int16 *v22; // x8
  __int16 v23; // w8
  const char *v24; // x2
  __int64 v25; // x8
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  int v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v31 = 0;
  v29 = 0;
  v30 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v27, 0x24u, 0);
  wlan_mlo_get_mlpeer_by_peer_mladdr(a2, &v26);
  if ( !v26 )
  {
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v20 = a2[2];
      v21 = a2[5];
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
    }
    v24 = "%s: mlo dev ctx for mld_mac: %02x:%02x:%02x:**:**:%02x not found";
    goto LABEL_20;
  }
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v11 = ktime_get(time_of_the_day_us);
  v12 = *((unsigned int *)a2 + 2);
  LOBYTE(v31) = 2;
  v30 = v11 / 1000;
  result = wlan_convert_link_id_to_diag_band(a2, v12);
  *(_WORD *)((char *)&v31 + 1) = *(_WORD *)((_BYTE *)&v31 + 1) & 0xFFE0 | result & 0x1F;
  if ( (result & 0x1F) == 0 )
    goto LABEL_24;
  result = wlan_convert_link_id_to_diag_band(a2, *((unsigned int *)a2 + 3));
  v14 = *(_QWORD **)(v26 + 3880);
  *(_WORD *)((char *)&v31 + 1) = *(_WORD *)((_BYTE *)&v31 + 1) & 0xFC1F | (32 * (result & 0x1F));
  if ( !v14 )
  {
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v24 = "%s: link ctx for mld_mac: %02x:%02x:%02x:**:**:%02x not found";
      v20 = a2[2];
      v21 = a2[5];
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
      v24 = "%s: link ctx for mld_mac: %02x:%02x:%02x:**:**:%02x not found";
    }
LABEL_20:
    result = qdf_trace_msg(
               0x38u,
               2u,
               v24,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "wlan_connectivity_mld_link_status_event",
               v18,
               v19,
               v20,
               v21);
    goto LABEL_24;
  }
  v15 = (unsigned __int16 *)v14[4];
  if ( v15 )
  {
    result = wlan_reg_freq_to_band(*v15);
    if ( (unsigned int)result <= 2 )
    {
      v16 = (unsigned __int8)(1LL << result);
      v17 = (unsigned __int16 *)v14[10];
      if ( !v17 )
        goto LABEL_13;
LABEL_11:
      result = wlan_reg_freq_to_band(*v17);
      if ( (unsigned int)result <= 2 )
        v16 |= (unsigned __int8)(1LL << result);
      goto LABEL_13;
    }
  }
  v16 = 0;
  v17 = (unsigned __int16 *)v14[10];
  if ( v17 )
    goto LABEL_11;
LABEL_13:
  v22 = (unsigned __int16 *)v14[16];
  if ( v22 )
  {
    result = wlan_reg_freq_to_band(*v22);
    v23 = *(_WORD *)((char *)&v31 + 1);
    if ( (unsigned int)result <= 2 )
    {
      *(_WORD *)((char *)&v31 + 1) = *(_WORD *)((_BYTE *)&v31 + 1) & 0x83FF
                                   | (((unsigned __int16)v16 | (unsigned __int16)(1LL << result)) << 10);
LABEL_23:
      v25 = (unsigned int)(1000 * *((_DWORD *)a2 + 4));
      HIBYTE(v31) = *((_DWORD *)a2 + 5);
      v29 = v25;
      result = host_diag_event_report_payload(3420, 36, &v27);
      goto LABEL_24;
    }
  }
  else
  {
    v23 = *(_WORD *)((char *)&v31 + 1);
  }
  *(_WORD *)((char *)&v31 + 1) = v23 & 0x83FF | ((_WORD)v16 << 10);
  if ( v16 )
    goto LABEL_23;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
