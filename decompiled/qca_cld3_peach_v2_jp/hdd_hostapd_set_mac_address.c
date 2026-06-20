__int64 __fastcall hdd_hostapd_set_mac_address(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x22
  __int64 *v14; // x21
  int v15; // w0
  unsigned int v16; // w19
  __int64 adapter_by_macaddr; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  __int64 v46; // [xsp+10h] [xbp-30h] BYREF
  bool v47; // [xsp+1Ch] [xbp-24h] BYREF
  unsigned int v48; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int16 v49; // [xsp+24h] [xbp-1Ch]
  __int64 v50; // [xsp+38h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  result = _osif_vdev_sync_op_start(a1, &v46, "hdd_hostapd_set_mac_address");
  if ( !(_DWORD)result )
  {
    v13 = (const char *)(a1 + 296);
    v47 = 0;
    v49 = 0;
    v48 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "__hdd_hostapd_set_mac_address",
      a1 + 296);
    v14 = *(__int64 **)(a1 + 2712);
    v15 = _wlan_hdd_validate_context(v14, "__hdd_hostapd_set_mac_address");
    if ( v15 )
      goto LABEL_3;
    qdf_mem_copy(&v48, (const void *)(a2 + 2), 6u);
    adapter_by_macaddr = hdd_get_adapter_by_macaddr(v14, &v48);
    if ( adapter_by_macaddr )
    {
      v26 = *(_QWORD *)(adapter_by_macaddr + 32);
      v15 = strcmp((const char *)(v26 + 296), v13);
      if ( v15 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: %s adapter exist with same address %02x:%02x:%02x:**:**:%02x",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__hdd_hostapd_set_mac_address",
          v26 + 296,
          (unsigned __int8)v48,
          BYTE1(v48),
          BYTE2(v48),
          HIBYTE(v49));
        v15 = -22;
      }
      goto LABEL_3;
    }
    if ( v48 | v49 )
    {
      if ( v48 == -1 && (__int16)v49 == -1 )
      {
        v45 = "%s: MAC is Broadcast";
      }
      else
      {
        if ( (v48 & 1) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Changing MAC to %02x:%02x:%02x:**:**:%02x of interface %s ",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "__hdd_hostapd_set_mac_address",
            a1 + 296);
          if ( !*(_QWORD *)(*(_QWORD *)(a1 + 55512) + 32LL) )
            goto LABEL_17;
          if ( (hdd_is_dynamic_set_mac_addr_allowed(a1 + 2688) & 1) == 0 )
          {
            v15 = -524;
            goto LABEL_3;
          }
          ucfg_psoc_mlme_get_11be_capab(*v14, &v47);
          v15 = hdd_dynamic_mac_address_set(*(_QWORD *)(a1 + 55512), v48 | ((unsigned __int64)v49 << 32), 0, 0, 0);
          if ( !v15 )
          {
LABEL_17:
            hdd_update_dynamic_mac(v14, a1 + 4305, &v48);
            ucfg_dp_update_intf_mac(
              *v14,
              (unsigned __int8 *)(a1 + 4305),
              (unsigned __int8 *)&v48,
              *(_QWORD *)(*(_QWORD *)(a1 + 55512) + 32LL));
            v36 = *(_DWORD *)(a2 + 2);
            *(_WORD *)(a1 + 4309) = *(_WORD *)(a2 + 6);
            *(_DWORD *)(a1 + 4305) = v36;
            dev_addr_mod(a1, 0, a2 + 2, 6);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "__hdd_hostapd_set_mac_address");
            v15 = 0;
          }
LABEL_3:
          v16 = v15;
          _osif_vdev_sync_op_stop(v46, "hdd_hostapd_set_mac_address");
          result = v16;
          goto LABEL_4;
        }
        v45 = "%s: MAC is Multicast";
      }
    }
    else
    {
      v45 = "%s: MAC is all zero";
    }
    qdf_trace_msg(0x33u, 2u, v45, v18, v19, v20, v21, v22, v23, v24, v25, "__hdd_hostapd_set_mac_address");
    v15 = -22;
    goto LABEL_3;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
