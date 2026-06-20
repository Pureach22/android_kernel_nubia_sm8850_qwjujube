__int64 __fastcall cm_get_ml_partner_info(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x24
  int v11; // w22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x25
  unsigned int v23; // w21
  unsigned __int8 *v24; // x26
  int v25; // w10
  __int64 v26; // x8
  __int64 v27; // x7
  int v28; // w8
  int v29; // w9
  int v30; // w10
  __int64 v32; // [xsp+0h] [xbp-20h]
  __int64 v33; // [xsp+8h] [xbp-18h]
  __int64 v34; // [xsp+10h] [xbp-10h]

  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 1016) + 24LL);
  *(_BYTE *)(a1 + 824) = 0;
  if ( !*(_QWORD *)(v10 + 1824) )
    return 16;
  if ( *(_BYTE *)(v10 + 1918) )
  {
    v11 = a2;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: sta mlo support link num: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_get_ml_partner_info",
      a2);
    if ( *(_BYTE *)(v10 + 1918) )
    {
      v22 = 0;
      v23 = 0;
      v24 = (unsigned __int8 *)(v10 + 1920);
      while ( v22 != 3 )
      {
        if ( v24 )
        {
          v27 = *v24;
          v28 = v24[1];
          v29 = v24[2];
          v30 = v24[5];
        }
        else
        {
          v29 = 0;
          v27 = 0;
          v28 = 0;
          v30 = 0;
        }
        LODWORD(v34) = v30;
        LODWORD(v33) = v29;
        LODWORD(v32) = v28;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: freq: %d, link id: %d is valid %d %02x:%02x:%02x:**:**:%02x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "cm_get_ml_partner_info",
          *((unsigned __int16 *)v24 + 3),
          v24[10],
          v24[40],
          v27,
          v32,
          v33,
          v34);
        if ( a2 && v11 - 1 <= (int)v23 )
          goto LABEL_18;
        if ( v24[40] == 1 )
        {
          if ( v23 > 2 )
            break;
          v25 = *(_DWORD *)v24;
          v26 = a1 + 832 + 48LL * v23++;
          *(_WORD *)(v26 + 4) = *((_WORD *)v24 + 2);
          *(_DWORD *)v26 = v25;
          *(_BYTE *)(v26 + 6) = v24[10];
          *(_WORD *)(v26 + 10) = *((_WORD *)v24 + 3);
        }
        ++v22;
        v24 += 48;
        if ( v22 >= *(unsigned __int8 *)(v10 + 1918) )
          goto LABEL_18;
      }
      __break(0x5512u);
      return 16;
    }
    v23 = 0;
LABEL_18:
    *(_BYTE *)(a1 + 824) = v23;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: sta and ap intersect num of partner link: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_get_ml_partner_info",
      v23);
  }
  return 0;
}
