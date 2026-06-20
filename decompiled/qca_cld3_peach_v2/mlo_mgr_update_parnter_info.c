__int64 __fastcall mlo_mgr_update_parnter_info(__int64 result, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // x21
  __int64 v3; // x19
  unsigned __int8 *v4; // x20
  __int64 ap_link_by_link_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x4
  __int64 v17; // x5
  unsigned __int8 *v18; // x21
  __int64 v19; // x19
  unsigned __int8 *v20; // x20
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  int v31; // w9
  __int64 v32; // x4
  __int64 v33; // x5
  unsigned __int8 *v34; // x20
  unsigned __int8 *v35; // x19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 v45; // x4
  __int64 v46; // x5
  int v47; // w10
  unsigned int v48; // w8
  __int64 v49; // [xsp+0h] [xbp-10h]
  __int64 v50; // [xsp+8h] [xbp-8h]

  if ( (*(_BYTE *)(result + 60) & 2) == 0 && a2[160] )
  {
    if ( !result )
    {
      v48 = a2[160];
      if ( v48 < 3 )
        return result;
      goto LABEL_20;
    }
    v2 = a2 + 168;
    if ( a2 != (unsigned __int8 *)-168LL )
    {
      if ( *(_QWORD *)(result + 1360) )
      {
        v3 = result;
        v4 = a2;
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(result + 1360), a2[174]);
        a2 = v4;
        v14 = ap_link_by_link_id;
        result = v3;
        if ( v14 )
        {
          v15 = *(_DWORD *)v2;
          v16 = *(unsigned __int8 *)(v14 + 6);
          v17 = *(unsigned __int8 *)(v14 + 12);
          *(_WORD *)(v14 + 28) = *((_WORD *)v2 + 2);
          *(_DWORD *)(v14 + 24) = v15;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: update AP link addr link_id: %d, vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            "mlo_mgr_update_ap_mac",
            v16,
            v17,
            (unsigned __int8)v15,
            BYTE1(v15),
            BYTE2(v15),
            *(unsigned __int8 *)(v14 + 29));
          result = v3;
          a2 = v4;
        }
      }
    }
    if ( a2[160] > 1u )
    {
      v18 = a2 + 216;
      if ( a2 != (unsigned __int8 *)-216LL )
      {
        if ( *(_QWORD *)(result + 1360) )
        {
          v19 = result;
          v20 = a2;
          v21 = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(result + 1360), a2[222]);
          a2 = v20;
          v30 = v21;
          result = v19;
          if ( v30 )
          {
            v31 = *(_DWORD *)v18;
            v32 = *(unsigned __int8 *)(v30 + 6);
            v33 = *(unsigned __int8 *)(v30 + 12);
            *(_WORD *)(v30 + 28) = *((_WORD *)v18 + 2);
            *(_DWORD *)(v30 + 24) = v31;
            LODWORD(v50) = *(unsigned __int8 *)(v30 + 29);
            LODWORD(v49) = BYTE2(v31);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: update AP link addr link_id: %d, vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              "mlo_mgr_update_ap_mac",
              v32,
              v33,
              (unsigned __int8)v31,
              BYTE1(v31),
              v49,
              v50);
            result = v19;
            a2 = v20;
          }
        }
      }
      if ( a2[160] > 2u )
      {
        v34 = a2 + 264;
        if ( a2 != (unsigned __int8 *)-264LL )
        {
          result = *(_QWORD *)(result + 1360);
          if ( result )
          {
            v35 = a2;
            result = mlo_mgr_get_ap_link_by_link_id(result, a2[270]);
            a2 = v35;
            if ( result )
            {
              v44 = *(_DWORD *)v34;
              v45 = *(unsigned __int8 *)(result + 6);
              v46 = *(unsigned __int8 *)(result + 12);
              *(_WORD *)(result + 28) = *((_WORD *)v34 + 2);
              v47 = *(unsigned __int8 *)(result + 29);
              *(_DWORD *)(result + 24) = v44;
              LODWORD(v50) = v47;
              LODWORD(v49) = BYTE2(v44);
              result = qdf_trace_msg(
                         0x8Fu,
                         8u,
                         "%s: update AP link addr link_id: %d, vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
                         v36,
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         "mlo_mgr_update_ap_mac",
                         v45,
                         v46,
                         (unsigned __int8)v44,
                         BYTE1(v44),
                         v49,
                         v50);
              a2 = v35;
            }
          }
        }
        v48 = a2[160];
LABEL_20:
        if ( v48 > 3 )
        {
          __break(0x5512u);
          return mlo_send_link_connect(result, a2);
        }
      }
    }
  }
  return result;
}
