_DWORD *__fastcall peer_assoc_add_ml_partner_links(
        int *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v11; // x22
  _DWORD *v12; // x24
  int v14; // w0
  __int64 v15; // x4
  __int64 v16; // x5
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v25; // x25
  unsigned __int8 *v26; // x26
  int v27; // w13
  int v28; // w14
  int v29; // w15
  int v30; // w16
  int v31; // w0
  unsigned __int64 v32; // x8
  int v33; // w8
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  int v38; // w9
  unsigned int v39; // w8
  unsigned int v40; // w9
  int v41; // w9
  int v42; // w10
  int v43; // w11
  int v44; // w12
  __int64 v46; // [xsp+0h] [xbp-50h]
  __int64 v47; // [xsp+8h] [xbp-48h]
  __int64 v48; // [xsp+10h] [xbp-40h]
  __int64 v49; // [xsp+18h] [xbp-38h]
  __int64 v50; // [xsp+20h] [xbp-30h]
  __int64 v51; // [xsp+28h] [xbp-28h]
  __int64 v52; // [xsp+30h] [xbp-20h]
  __int64 v53; // [xsp+38h] [xbp-18h]
  __int64 v54; // [xsp+40h] [xbp-10h]

  *a1 = (68 * (*(unsigned __int8 *)(a2 + 866) + *(unsigned __int8 *)(a2 + 696))) | 0x120000;
  v11 = a1 + 1;
  v12 = a1 + 1;
  if ( *(_BYTE *)(a2 + 866) == 1 )
  {
    a1[1] = 63438912;
    a1[2] = *(_DWORD *)(a2 + 632);
    a1[6] = *(_DWORD *)(a2 + 604);
    a1[7] = *(_DWORD *)(a2 + 636);
    a1[8] = *(unsigned __int16 *)(a2 + 640);
    a1[16] = *(_DWORD *)(a2 + 688);
    a1[17] = *(unsigned __int16 *)(a2 + 692);
    a1[10] = *(unsigned __int16 *)(a2 + 648);
    a1[11] = *(_DWORD *)(a2 + 664);
    a1[12] = *(_DWORD *)(a2 + 668);
    v14 = wmi_host_to_fw_phymode(*(_DWORD *)(a2 + 676));
    v15 = (unsigned int)a1[6];
    v16 = (unsigned int)a1[2];
    a1[13] = a1[13] & 0xFFFFFFC0 | v14;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Send Link info with link_id: %d vdev_id: %d freq %d AP link addr: %02x:%02x:%02x:**:**:%02x, STA addr: %02x:%0"
      "2x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "peer_assoc_update_assoc_link_info",
      v15,
      v16,
      *(unsigned __int16 *)(a2 + 648),
      *(unsigned __int8 *)(a2 + 636),
      *(unsigned __int8 *)(a2 + 637),
      *(unsigned __int8 *)(a2 + 638),
      *(unsigned __int8 *)(a2 + 641),
      *(unsigned __int8 *)(a2 + 688),
      *(unsigned __int8 *)(a2 + 689),
      *(unsigned __int8 *)(a2 + 690),
      *(unsigned __int8 *)(a2 + 693));
    v12 = a1 + 18;
  }
  if ( *(_BYTE *)(a2 + 696) )
  {
    v25 = 0;
    v26 = (unsigned __int8 *)(a2 + 781);
    do
    {
      *v12 = 63438912;
      v33 = v12[3];
      v12[1] = *(_DWORD *)(v26 - 77);
      v12[2] = *(_DWORD *)(v26 - 73);
      v12[3] = v33 & 0xFFFFFFFE;
      v34 = v33 & 0xFFFFFFFC | *(_DWORD *)(v26 - 69) & 1;
      v12[3] = v34;
      v35 = v34 & 0xFFFFFFF9 | *(_DWORD *)(v26 - 69) & 2;
      v12[3] = v35;
      v36 = v35 & 0xFFFFFFF3 | *(_DWORD *)(v26 - 69) & 4;
      v12[3] = v36;
      v37 = v36 & 0xFFFFFBFF | *(_DWORD *)(v26 - 69) & 8;
      v12[3] = v37;
      v38 = (2 * *(_DWORD *)(v26 - 69)) & 0x400 | v37;
      v12[3] = v38;
      v39 = *(_DWORD *)(a2 + 584);
      v40 = v38 & 0xFFFFFEFF | (((v39 >> 13) & 1) << 8);
      v12[3] = v40;
      v12[3] = v40 & 0xFFFFFFBF | (((*(_DWORD *)(v26 - 69) >> 6) & 1) << 6);
      v12[4] = *(_DWORD *)(v26 - 65);
      v12[5] = *(_DWORD *)(v26 - 61);
      v41 = (_DWORD)v26 - 57;
      v12[6] = *(_DWORD *)(v26 - 57);
      v12[7] = *(unsigned __int16 *)(v26 - 53);
      v27 = (_DWORD)v26 - 5;
      v12[15] = *(_DWORD *)(v26 - 5);
      v12[16] = *(unsigned __int16 *)(v26 - 1);
      if ( v26 == (_BYTE *)&qword_38 + 1 )
      {
        v43 = 0;
        v42 = 0;
        v44 = 0;
      }
      else
      {
        v41 = *(v26 - 57);
        v42 = *(v26 - 56);
        v43 = *(v26 - 55);
        v44 = *(v26 - 52);
      }
      if ( v26 == (_BYTE *)&off_0 + 5 )
      {
        v29 = 0;
        v28 = 0;
        v30 = 0;
      }
      else
      {
        v27 = *(v26 - 5);
        v28 = *(v26 - 4);
        v29 = *(v26 - 3);
        v30 = *v26;
      }
      LODWORD(v53) = v30;
      LODWORD(v54) = (v39 >> 13) & 1;
      LODWORD(v52) = v29;
      LODWORD(v51) = v28;
      LODWORD(v50) = v27;
      LODWORD(v49) = v44;
      LODWORD(v48) = v43;
      LODWORD(v47) = v42;
      LODWORD(v46) = v41;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Send Link info with link_id: %d vdev_id: %d freq %d phymode %d AP link addr: %02x:%02x:%02x:**:**:%02x, STA "
        "addr: %02x:%02x:%02x:**:**:%02x mlo_link_add %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "peer_assoc_add_ml_partner_links",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54);
      v12[9] = *(unsigned __int16 *)(v26 - 45);
      v12[10] = *(_DWORD *)(v26 - 29);
      v12[11] = *(_DWORD *)(v26 - 25);
      v31 = wmi_host_to_fw_phymode(*(_DWORD *)(v26 - 17));
      ++v25;
      v26 += 80;
      v12[12] = v12[12] & 0xFFFFFFC0 | v31;
      v12 += 17;
      v32 = *(unsigned __int8 *)(a2 + 696);
    }
    while ( v25 < v32 );
  }
  else
  {
    LODWORD(v32) = 0;
  }
  return &v11[17 * (unsigned int)v32 + 17 * *(unsigned __int8 *)(a2 + 866)];
}
