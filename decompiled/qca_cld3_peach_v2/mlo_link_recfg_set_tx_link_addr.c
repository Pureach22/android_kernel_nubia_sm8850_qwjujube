__int64 __fastcall mlo_link_recfg_set_tx_link_addr(
        __int64 *a1,
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
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 pdev_by_id; // x0
  __int64 v16; // x25
  __int64 v17; // x19
  int *v18; // x24
  int v19; // w9
  int v20; // w1
  const char *v21; // x2
  __int64 result; // x0
  __int64 v23; // x25
  int v24; // w9
  int v25; // w1
  __int64 v26; // x23
  int v27; // w9
  int v28; // w1
  unsigned __int16 v29; // w8
  int v30; // w9
  const char *v31; // x2
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20
  __int64 v42; // [xsp+0h] [xbp-30h]
  int v43; // [xsp+10h] [xbp-20h]
  unsigned __int16 v44; // [xsp+14h] [xbp-1Ch]

  _ReadStatusReg(SP_EL0);
  v11 = a1[1];
  v44 = 0;
  v43 = 0;
  if ( v11 )
  {
    v12 = *a1;
    if ( v12 )
    {
      pdev_by_id = wlan_objmgr_get_pdev_by_id(v12, 0, 0x6Cu);
      if ( pdev_by_id )
      {
        v16 = *(_QWORD *)(v11 + 3880);
        v17 = pdev_by_id;
        v18 = (int *)(v16 + 24);
        if ( *(_DWORD *)(v16 + 24) | *(unsigned __int16 *)(v16 + 28) )
        {
          v19 = *(unsigned __int8 *)(v16 + 6);
          if ( v19 != 255 )
          {
            if ( (*(_QWORD *)(v16 + 16) & 1) != 0 )
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: skip ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "mlo_link_recfg_set_tx_link_addr",
                *(unsigned __int8 *)(a2 + 257),
                *(unsigned __int8 *)(a2 + 258),
                *(unsigned __int8 *)(a2 + 259),
                *(unsigned __int8 *)(a2 + 262),
                *(_QWORD *)(v16 + 16));
            }
            else
            {
              v20 = *(unsigned __int8 *)(v16 + 12);
              if ( v20 == 255 )
              {
                if ( ((a3 >> v19) & 1) != 0 )
                {
                  v43 = *v18;
                  v44 = *(_WORD *)(v16 + 28);
                }
              }
              else if ( cm_is_vdevid_connected(pdev_by_id, v20) && ((a3 >> *(_BYTE *)(v16 + 6)) & 1) != 0 )
              {
                goto LABEL_30;
              }
            }
          }
        }
        v23 = *(_QWORD *)(v11 + 3880);
        v18 = (int *)(v23 + 72);
        if ( *(_DWORD *)(v23 + 72) | *(unsigned __int16 *)(v23 + 76) )
        {
          v24 = *(unsigned __int8 *)(v23 + 54);
          if ( v24 != 255 )
          {
            if ( (*(_QWORD *)(v23 + 64) & 1) != 0 )
            {
              LODWORD(v42) = *(_QWORD *)(v23 + 64);
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: skip ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "mlo_link_recfg_set_tx_link_addr",
                *(unsigned __int8 *)(a2 + 257),
                *(unsigned __int8 *)(a2 + 258),
                *(unsigned __int8 *)(a2 + 259),
                *(unsigned __int8 *)(a2 + 262),
                v42);
            }
            else
            {
              v25 = *(unsigned __int8 *)(v23 + 60);
              if ( v25 == 255 )
              {
                if ( ((a3 >> v24) & 1) != 0 )
                {
                  v43 = *v18;
                  v44 = *(_WORD *)(v23 + 76);
                }
              }
              else if ( cm_is_vdevid_connected(v17, v25) && ((a3 >> *(_BYTE *)(v23 + 54)) & 1) != 0 )
              {
                goto LABEL_30;
              }
            }
          }
        }
        v26 = *(_QWORD *)(v11 + 3880);
        v18 = (int *)(v26 + 120);
        if ( *(_DWORD *)(v26 + 120) | *(unsigned __int16 *)(v26 + 124) )
        {
          v27 = *(unsigned __int8 *)(v26 + 102);
          if ( v27 != 255 )
          {
            if ( (*(_QWORD *)(v26 + 112) & 1) != 0 )
            {
              LODWORD(v42) = *(_QWORD *)(v26 + 112);
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: skip ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "mlo_link_recfg_set_tx_link_addr",
                *(unsigned __int8 *)(a2 + 257),
                *(unsigned __int8 *)(a2 + 258),
                *(unsigned __int8 *)(a2 + 259),
                *(unsigned __int8 *)(a2 + 262),
                v42);
            }
            else
            {
              v28 = *(unsigned __int8 *)(v26 + 108);
              if ( v28 == 255 )
              {
                if ( ((a3 >> v27) & 1) != 0 )
                {
                  v43 = *v18;
                  v44 = *(_WORD *)(v26 + 124);
                }
              }
              else if ( cm_is_vdevid_connected(v17, v28) && ((a3 >> *(_BYTE *)(v26 + 102)) & 1) != 0 )
              {
LABEL_30:
                v29 = *((_WORD *)v18 + 2);
                v30 = *v18;
                v31 = "%s: selected tx ap link addr: %02x:%02x:%02x:**:**:%02x";
                goto LABEL_34;
              }
            }
          }
        }
        if ( !(v43 | v44) )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: no found valid peer mac",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "mlo_link_recfg_set_tx_link_addr");
          v41 = 4;
          goto LABEL_36;
        }
        v29 = v44;
        v30 = v43;
        v31 = "%s: selected tx ap link addr: %02x:%02x:%02x:**:**:%02x - standby";
LABEL_34:
        *(_WORD *)(a2 + 261) = v29;
        *(_DWORD *)(a2 + 257) = v30;
        qdf_trace_msg(
          0x8Fu,
          8u,
          v31,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "mlo_link_recfg_set_tx_link_addr",
          *(unsigned __int8 *)(a2 + 257),
          *(unsigned __int8 *)(a2 + 258),
          *(unsigned __int8 *)(a2 + 259),
          *(unsigned __int8 *)(a2 + 262));
        v41 = 0;
LABEL_36:
        wlan_objmgr_pdev_release_ref(v17, 0x6Cu, v32, v33, v34, v35, v36, v37, v38, v39, v40);
        result = v41;
        goto LABEL_37;
      }
      v21 = "%s: Invalid pdev";
    }
    else
    {
      v21 = "%s: psoc null";
    }
  }
  else
  {
    v21 = "%s: mlo_ctx null";
  }
  qdf_trace_msg(0x8Fu, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "mlo_link_recfg_set_tx_link_addr");
  result = 4;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
