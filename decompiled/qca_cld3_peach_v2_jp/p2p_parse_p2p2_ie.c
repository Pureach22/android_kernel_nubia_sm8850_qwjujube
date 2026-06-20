__int64 __fastcall p2p_parse_p2p2_ie(__int64 a1, unsigned int a2, char a3, bool *a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w4
  unsigned __int16 v18; // w8
  unsigned __int8 *v19; // x9
  int v20; // w0
  char v21; // w16
  __int64 v22; // x15
  unsigned int v23; // w15
  int v24; // w17
  unsigned int v25; // w16
  int v26; // w0
  _BYTE *v27; // x17

  if ( !a4 )
    return 4;
  qdf_mem_set(a4, 0x6Bu, 0);
  result = p2p_get_p2p2_ie_ptr(a1, a2);
  if ( result )
  {
    v17 = *(unsigned __int8 *)(result + 1);
    if ( v17 > 5 )
    {
      v18 = v17 - 4;
      if ( v17 - 4 >= 3 )
      {
        v19 = (unsigned __int8 *)(result + 6);
        do
        {
          v23 = v19[1] | (v19[2] << 8);
          if ( v23 )
          {
            v24 = *v19;
            if ( v24 == 30 )
            {
              v25 = v19[1] / 0xCu;
              if ( v23 >= 0x78 )
                v25 = 10;
              if ( v25 && 12 * v25 <= v18 )
              {
                v26 = 0;
                v27 = v19 + 14;
                a4[4] = 1;
                do
                {
                  if ( (*(v27 - 11) & 1) != 0 || (a3 & 1) == 0 )
                  {
                    a4[7] = *(v27 - 11) & 1;
                    v20 = *(_DWORD *)(v27 - 10);
                    *(_WORD *)(a4 + 13) = *((_WORD *)v27 - 3);
                    *(_DWORD *)(a4 + 9) = v20;
                    a4[15] = *(v27 - 1);
                    a4[16] = *v27;
                    v21 = 1;
                    goto LABEL_9;
                  }
                  ++v26;
                  v27 += 12;
                }
                while ( v25 > (unsigned __int8)v26 );
                v21 = 0;
LABEL_9:
                a4[6] = v21;
              }
            }
            else if ( v24 == 29 )
            {
              a4[3] = 1;
              *a4 = (v19[3] & 0x40) != 0;
              a4[1] = v19[3] >> 7;
            }
          }
          v22 = v23 + 3;
          v18 -= v22;
          v19 += v22;
        }
        while ( v18 > 2u );
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(0x4Eu, 2u, "%s: Invalid IE len %d", v9, v10, v11, v12, v13, v14, v15, v16, "p2p_parse_p2p2_ie");
      return 4;
    }
  }
  return result;
}
