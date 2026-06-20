__int64 __fastcall mlo_link_recfg_set_mac_addr_resp(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w20
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x22
  __int64 v15; // x23
  _DWORD *v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 (__fastcall *v25)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w21
  const char *v36; // x2
  const char *v37; // x2
  __int64 v38; // [xsp+0h] [xbp-40h]
  __int64 v39; // [xsp+8h] [xbp-38h]

  v3 = a2;
  _ReadStatusReg(SP_EL0);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !v3 )
  {
    if ( mlo_ctx )
    {
      if ( *(_QWORD *)(*(_QWORD *)(mlo_ctx + 360) + 24LL) )
      {
        v13 = *(_QWORD *)(a1 + 1360);
        if ( v13 )
        {
          v14 = *(_QWORD *)(v13 + 3888);
          if ( v14 )
          {
            v15 = mlo_ctx;
            v16 = (_DWORD *)(v14 + 3209);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: Dynamic vdev %d resp received, updating vdev %d old mac %02x:%02x:%02x:**:**:%02x new %02x:%02x:%02x:**:**:%02x",
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              "mlo_link_recfg_set_mac_addr_resp",
              *(unsigned __int8 *)(a1 + 168),
              *(unsigned __int8 *)(v14 + 3208),
              *(unsigned __int8 *)(v14 + 3209),
              *(unsigned __int8 *)(v14 + 3210),
              *(unsigned __int8 *)(v14 + 3211),
              *(unsigned __int8 *)(v14 + 3214),
              *(unsigned __int8 *)(a1 + 74),
              *(unsigned __int8 *)(a1 + 75),
              *(unsigned __int8 *)(a1 + 76),
              *(unsigned __int8 *)(a1 + 79));
            if ( *(unsigned __int8 *)(a1 + 168) == *(unsigned __int8 *)(v14 + 3208) )
            {
              if ( *v16 | *(unsigned __int16 *)(v14 + 3213) )
              {
                v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v15 + 360) + 24LL);
                if ( *((_DWORD *)v25 - 1) != -812663418 )
                  __break(0x8228u);
                result = v25(a1, v14 + 3209, a1 + 74);
                if ( (_DWORD)result )
                {
                  v35 = result;
                  LODWORD(v39) = *(unsigned __int8 *)(v14 + 3214);
                  LODWORD(v38) = *(unsigned __int8 *)(v14 + 3211);
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: VDEV %d OSIF MAC addr update failed %d old mac %02x:%02x:%02x:**:**:%02x",
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    "mlo_link_recfg_set_mac_addr_resp",
                    *(unsigned __int8 *)(a1 + 168),
                    (unsigned int)result,
                    *(unsigned __int8 *)(v14 + 3209),
                    *(unsigned __int8 *)(v14 + 3210),
                    v38,
                    v39);
                  result = v35;
                }
                goto LABEL_23;
              }
              v37 = "%s: vdev old mac zero";
            }
            else
            {
              v37 = "%s: vdev id mismatch";
            }
            qdf_trace_msg(0x8Fu, 2u, v37, v17, v18, v19, v20, v21, v22, v23, v24, "mlo_link_recfg_set_mac_addr_resp");
            result = 4;
LABEL_23:
            *v16 = 0;
            *(_BYTE *)(v14 + 3208) = -1;
            *(_WORD *)(v14 + 3213) = 0;
            goto LABEL_19;
          }
          v36 = "%s: recfg_ctx null";
        }
        else
        {
          v36 = "%s: mlo_ctx null";
        }
      }
      else
      {
        v36 = "%s: mlo_link_recfg_osif_update_mac_addr NULL";
      }
    }
    else
    {
      v36 = "%s: global mlo ctx NULL";
    }
    qdf_trace_msg(0x8Fu, 2u, v36, v5, v6, v7, v8, v9, v10, v11, v12, "mlo_link_recfg_set_mac_addr_resp");
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: VDEV %d set MAC address response %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "mlo_link_recfg_set_mac_addr_resp",
    *(unsigned __int8 *)(a1 + 168),
    v3);
LABEL_18:
  result = 4;
LABEL_19:
  *(_DWORD *)(a1 + 64) &= ~0x8000000u;
  _ReadStatusReg(SP_EL0);
  return result;
}
