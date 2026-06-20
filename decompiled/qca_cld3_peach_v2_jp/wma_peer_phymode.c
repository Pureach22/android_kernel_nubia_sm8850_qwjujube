__int64 __fastcall wma_peer_phymode(
        unsigned int a1,
        char a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        char a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v15; // w8
  int v16; // w19
  unsigned int v17; // w19
  unsigned __int8 v18; // w20
  unsigned __int8 v19; // w21
  unsigned __int8 v20; // w22
  char v22; // w23
  char v23; // w24
  unsigned __int8 v24; // w20
  unsigned __int8 v25; // w21
  unsigned __int8 v26; // w24
  char v27; // w23
  char v28; // w25
  __int64 v29; // x9
  _DWORD *v30; // x10
  int v31; // w9
  unsigned __int8 v32; // w20
  unsigned __int8 v33; // w21
  unsigned __int8 v34; // w24
  char v35; // w23
  char v36; // w25
  bool v37; // zf
  int v38; // w9
  int v39; // w10
  int v40; // w9

  v15 = a1;
  v16 = a5;
  if ( !a1 )
  {
    if ( !(a5 | a3) && (a6 & 1) == 0 && (a7 & 1) == 0 )
    {
      v17 = 1;
      goto LABEL_52;
    }
    if ( (a6 & 1) != 0 )
    {
      if ( (unsigned __int8)(a4 - 2) < 3u )
      {
        v29 = (unsigned __int8)(a4 - 2);
        v30 = &unk_A18BE8;
LABEL_35:
        v17 = v30[v29];
        goto LABEL_52;
      }
      v37 = a4 == 0;
      v38 = 23;
      v39 = 21;
    }
    else if ( a5 )
    {
      if ( (unsigned __int8)(a4 - 2) < 3u )
      {
        v29 = (unsigned __int8)(a4 - 2);
        v30 = &unk_A18BF4;
        goto LABEL_35;
      }
      v37 = a4 == 0;
      v38 = 13;
      v39 = 11;
    }
    else
    {
      v37 = a4 == 0;
      v38 = 7;
      v39 = 5;
    }
LABEL_49:
    if ( v37 )
      v17 = v39;
    else
      v17 = v38;
    goto LABEL_52;
  }
  if ( a1 == 2 )
  {
    if ( !(a5 | a3) && (a6 & 1) == 0 && (a7 & 1) == 0 )
    {
      v17 = 3;
      goto LABEL_52;
    }
    if ( a4 < 2u )
    {
      if ( !a4 )
      {
        if ( a5 )
          v40 = 12;
        else
          v40 = 6;
        if ( (a6 & 1) != 0 )
          v17 = 22;
        else
          v17 = v40;
        goto LABEL_52;
      }
    }
    else
    {
      v24 = a3;
      v25 = a4;
      v26 = a5;
      v27 = a7;
      v28 = a6;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: 80/160 MHz BW sent in 11G, configured 40MHz",
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        "wma_peer_phymode");
      a6 = v28;
      a7 = v27;
      a4 = v25;
      a3 = v24;
      a5 = v26;
      v15 = 2;
    }
    if ( v16 )
      v31 = 16;
    else
      v31 = 10;
    if ( (a6 & 1) != 0 )
      v17 = 26;
    else
      v17 = v31;
    goto LABEL_52;
  }
  if ( a1 != 1 )
  {
    v18 = a3;
    v19 = a4;
    v20 = a5;
    v22 = a7;
    v23 = a6;
    qdf_trace_msg(0x36u, 2u, "%s: Invalid nw type %d", a8, a9, a10, a11, a12, a13, a14, a15, "wma_peer_phymode", a1);
    a6 = v23;
    a7 = v22;
    a4 = v19;
    a3 = v18;
    a5 = v20;
    v15 = a1;
    v17 = 0;
    goto LABEL_52;
  }
  if ( a2 == 4 )
  {
    if ( (a6 & 1) != 0 )
    {
      v17 = 22;
      goto LABEL_52;
    }
    if ( a5 )
    {
      v17 = 12;
      goto LABEL_52;
    }
    v37 = a3 == 0;
    v38 = 6;
    v39 = 2;
    goto LABEL_49;
  }
  if ( a5 | a3 || (a6 & 1) != 0 || (a7 & 1) != 0 )
  {
    v32 = a3;
    v33 = a4;
    v17 = 2;
    v34 = a5;
    v35 = a7;
    v36 = a6;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: HT/VHT is enabled with 11B NW type",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "wma_peer_phymode");
    a6 = v36;
    a7 = v35;
    a4 = v33;
    a3 = v32;
    a5 = v34;
    v15 = 1;
  }
  else
  {
    v17 = 2;
  }
LABEL_52:
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: nw_type %d is_ht %d ch_width %d is_vht %d is_he %d is_eht %d phymode %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "wma_peer_phymode",
    v15,
    a3,
    a4,
    a5,
    a6 & 1,
    a7 & 1,
    v17);
  return v17;
}
