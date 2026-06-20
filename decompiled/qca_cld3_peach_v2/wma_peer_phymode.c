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
  unsigned __int8 v25; // w20
  unsigned __int8 v26; // w21
  unsigned __int8 v27; // w24
  char v28; // w23
  char v29; // w25
  __int64 v30; // x9
  _DWORD *v31; // x10
  unsigned __int8 v32; // w20
  unsigned __int8 v33; // w21
  unsigned __int8 v34; // w24
  char v35; // w23
  char v36; // w25
  int v37; // w9
  int v38; // w9

  v15 = a1;
  v16 = a5;
  if ( !a1 )
  {
    if ( !(a5 | a3) && (a6 & 1) == 0 && (a7 & 1) == 0 )
    {
      v17 = 1;
      goto LABEL_16;
    }
    if ( (a7 & 1) != 0 )
    {
      switch ( a4 )
      {
        case 2u:
          v17 = 37;
          break;
        case 3u:
          v17 = 39;
          break;
        case 7u:
          v17 = 40;
          break;
        default:
          if ( a4 )
            v17 = 33;
          else
            v17 = 31;
          break;
      }
      goto LABEL_16;
    }
    if ( (a6 & 1) != 0 )
    {
      if ( (unsigned __int8)(a4 - 2) >= 3u )
      {
        if ( a4 )
          v17 = 23;
        else
          v17 = 21;
        goto LABEL_16;
      }
      v30 = (unsigned __int8)(a4 - 2);
      v31 = &unk_B0AD60;
    }
    else
    {
      if ( !a5 )
      {
        if ( a4 )
          v17 = 7;
        else
          v17 = 5;
        goto LABEL_16;
      }
      if ( (unsigned __int8)(a4 - 2) >= 3u )
      {
        if ( a4 )
          v17 = 13;
        else
          v17 = 11;
        goto LABEL_16;
      }
      v30 = (unsigned __int8)(a4 - 2);
      v31 = &unk_B0AD6C;
    }
    v17 = v31[v30];
    goto LABEL_16;
  }
  if ( a1 != 2 )
  {
    if ( a1 == 1 )
    {
      if ( a2 == 4 )
      {
        if ( (a6 & 1) != 0 )
        {
          v17 = 22;
        }
        else if ( a5 )
        {
          v17 = 12;
        }
        else if ( a3 )
        {
          v17 = 6;
        }
        else
        {
          v17 = 2;
        }
      }
      else if ( a5 | a3 || (a6 & 1) != 0 || (a7 & 1) != 0 )
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
    }
    else
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
    }
    goto LABEL_16;
  }
  if ( !(a5 | a3) && (a6 & 1) == 0 && (a7 & 1) == 0 )
  {
    v17 = 3;
    goto LABEL_16;
  }
  if ( a4 >= 2u )
  {
    v25 = a3;
    v26 = a4;
    v27 = a5;
    v28 = a7;
    v29 = a6;
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
    a6 = v29;
    a7 = v28;
    a4 = v26;
    a3 = v25;
    a5 = v27;
    v15 = 2;
    goto LABEL_29;
  }
  if ( a4 )
  {
LABEL_29:
    if ( (a7 & 1) != 0 )
    {
      v17 = 36;
    }
    else
    {
      if ( v16 )
        v37 = 16;
      else
        v37 = 10;
      if ( (a6 & 1) != 0 )
        v17 = 26;
      else
        v17 = v37;
    }
    goto LABEL_16;
  }
  if ( (a7 & 1) != 0 )
  {
    v17 = 32;
  }
  else
  {
    if ( a5 )
      v38 = 12;
    else
      v38 = 6;
    if ( (a6 & 1) != 0 )
      v17 = 22;
    else
      v17 = v38;
  }
LABEL_16:
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
