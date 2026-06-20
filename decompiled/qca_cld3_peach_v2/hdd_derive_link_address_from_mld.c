__int64 __fastcall hdd_derive_link_address_from_mld(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  unsigned int v13; // w26
  int v14; // w23
  unsigned int v15; // w20
  unsigned int v17; // w21
  unsigned int v18; // w22
  __int16 v19; // w27
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  int v30; // w28
  __int64 result; // x0
  unsigned int v32; // w24
  unsigned int v33; // w23
  __int64 v34; // [xsp+0h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    if ( a2 )
    {
      v12 = a3;
      if ( a3 )
      {
        v13 = a4;
        if ( (unsigned int)a4 - 4 >= 0xFFFFFFFD )
        {
          if ( *(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2) )
          {
            v14 = *a2;
            v15 = a2[1];
            v17 = a2[2];
            v18 = a2[5];
            v19 = *(_WORD *)(a2 + 3);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: MLD addr: %02x:%02x:%02x:**:**:%02x",
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              "hdd_derive_link_address_from_mld",
              *a2,
              a2[1],
              a2[2],
              a2[5]);
            if ( (wlan_mlme_get_sta_same_link_mld_addr(a1) & 1) != 0 )
            {
              v29 = *(_DWORD *)a2;
              v30 = 1;
              *(_WORD *)(v12 + 4) = *((_WORD *)a2 + 2);
              *(_DWORD *)v12 = v29;
              v12 += 6;
              if ( v13 <= 1 )
                goto LABEL_13;
            }
            else
            {
              v30 = 0;
              if ( !v13 )
              {
LABEL_13:
                result = 0;
                goto LABEL_14;
              }
            }
            v32 = v18 >> 4;
            v33 = v14 | 2;
            do
            {
              *(_BYTE *)v12 = v33;
              *(_BYTE *)(v12 + 1) = v15;
              *(_BYTE *)(v12 + 2) = v17;
              *(_WORD *)(v12 + 3) = v19;
              *(_BYTE *)(v12 + 5) = (((v32 + v30) & 7) + v18) ^ 0x80;
              LODWORD(v34) = v30;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Derived link addr: %02x:%02x:%02x:**:**:%02x, idx: %d",
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                "hdd_derive_link_address_from_mld",
                v33,
                v15,
                v17,
                (unsigned __int8)(((v32 + v30++) & 7) + v18) ^ 0x80u,
                v34);
              v12 += 6;
            }
            while ( v13 != (unsigned __int8)v30 );
            goto LABEL_13;
          }
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 2u, "%s: Invalid values", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_derive_link_address_from_mld");
  result = 4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
