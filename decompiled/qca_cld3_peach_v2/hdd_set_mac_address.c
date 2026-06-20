__int64 __fastcall hdd_set_mac_address(__int64 a1, __int64 a2)
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
  __int64 v13; // x23
  __int64 *v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  __int64 adapter_by_macaddr; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w9
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x2
  __int64 v70; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v71; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v72; // [xsp+1Ch] [xbp-14h]
  __int64 v73; // [xsp+28h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  result = _osif_vdev_sync_op_start(a1, &v70, "hdd_set_mac_address");
  if ( !(_DWORD)result )
  {
    v13 = *(_QWORD *)(a1 + 168);
    v71 = 0;
    v72 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v5, v6, v7, v8, v9, v10, v11, v12, "__hdd_set_mac_address", a1 + 296);
    v14 = *(__int64 **)(a1 + 2712);
    v23 = _wlan_hdd_validate_context(
            (__int64)v14,
            (__int64)"__hdd_set_mac_address",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( !v23 )
    {
      if ( (v13 & 1) != 0
        && (hdd_is_dynamic_set_mac_addr_allowed(a1 + 2688, v24, v25, v26, v27, v28, v29, v30, v31) & 1) == 0 )
      {
        v23 = -524;
      }
      else
      {
        qdf_mem_copy(&v71, (const void *)(a2 + 2), 6u);
        adapter_by_macaddr = hdd_get_adapter_by_macaddr((__int64)v14, &v71);
        if ( adapter_by_macaddr )
        {
          v42 = *(_QWORD *)(adapter_by_macaddr + 32);
          v23 = strcmp((const char *)(v42 + 296), (const char *)(a1 + 296));
          if ( v23 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: %s adapter exist with same address %02x:%02x:%02x:**:**:%02x",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "__hdd_set_mac_address",
              v42 + 296,
              (unsigned __int8)v71,
              BYTE1(v71),
              BYTE2(v71),
              HIBYTE(v72));
            v23 = -22;
          }
        }
        else
        {
          if ( v71 | v72 )
          {
            if ( v71 == -1 && (__int16)v72 == -1 )
            {
              v69 = "%s: MAC is Broadcast (via %s)";
            }
            else
            {
              if ( (v71 & 1) == 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "Changing MAC to %02x:%02x:%02x:**:**:%02x of the interface %s ",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  (unsigned __int8)v71,
                  BYTE1(v71),
                  BYTE2(v71),
                  HIBYTE(v72),
                  a1 + 296);
                if ( (v13 & 1) == 0
                  || !*(_QWORD *)(*(_QWORD *)(a1 + 55520) + 32LL)
                  || (v23 = ((__int64 (__fastcall *)(__int64, unsigned __int64))hdd_update_vdev_mac_address)(
                              a1 + 2688,
                              v71 | ((unsigned __int64)v72 << 32))) == 0 )
                {
                  hdd_update_dynamic_mac(
                    (__int64)v14,
                    (const void *)(a1 + 4305),
                    &v71,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59);
                  ucfg_dp_update_intf_mac(
                    *v14,
                    (unsigned __int8 *)(a1 + 4305),
                    (unsigned __int8 *)&v71,
                    *(_QWORD *)(*(_QWORD *)(a1 + 55520) + 32LL));
                  v60 = *(_DWORD *)(a2 + 2);
                  *(_WORD *)(a1 + 4309) = *(_WORD *)(a2 + 6);
                  *(_DWORD *)(a1 + 4305) = v60;
                  dev_addr_mod(a1, 0, a2 + 2, 6);
                  qdf_trace_msg(0x33u, 8u, "%s: exit", v61, v62, v63, v64, v65, v66, v67, v68, "__hdd_set_mac_address");
                  v23 = 0;
                }
                goto LABEL_3;
              }
              v69 = "%s: MAC is Multicast (via %s)";
            }
          }
          else
          {
            v69 = "%s: MAC is all zero (via %s)";
          }
          qdf_trace_msg(
            0x33u,
            2u,
            v69,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__wlan_hdd_validate_mac_address",
            "__hdd_set_mac_address");
          v23 = -22;
        }
      }
    }
LABEL_3:
    v32 = v23;
    _osif_vdev_sync_op_stop(v70, "hdd_set_mac_address");
    result = v32;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
