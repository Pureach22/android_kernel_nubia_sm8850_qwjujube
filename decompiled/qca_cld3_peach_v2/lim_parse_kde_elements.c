__int64 __fastcall lim_parse_kde_elements(
        __int64 a1,
        _BYTE *a2,
        unsigned __int8 *a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int8 v12; // w19
  unsigned __int8 *v14; // x23
  int v16; // w8
  __int64 v17; // x22
  int v18; // w28
  int v19; // w4
  __int64 v20; // x4
  const char *v22; // x2

  v12 = a4;
  if ( !a3 )
  {
    v22 = "%s: kde_list NULL or kde_list_len %d";
    v20 = (unsigned __int8)a4;
    goto LABEL_19;
  }
  if ( (unsigned __int8)a4 >= 2u )
  {
    v14 = a3;
    v16 = a4;
    do
    {
      v17 = v14[1];
      v18 = v16 - 2;
      if ( (unsigned int)v17 > (unsigned __int8)(v16 - 2) || (unsigned int)v17 > v12 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid elem_len %d rem_len %d list_len %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "lim_parse_kde_elements",
          v14[1],
          (unsigned __int8)(v16 - 2),
          v12);
        return 16;
      }
      if ( (unsigned int)v17 <= 3 )
      {
        v22 = "%s: Not enough len to parse elem_len %d";
        v20 = v14[1];
        goto LABEL_19;
      }
      if ( (lim_check_if_vendor_oui_match(a5, a6, a7, a8, a9, a10, a11, a12, a1, &unk_B35EC0, 3u, v14, v17) & 1) != 0 )
      {
        v19 = v14[5];
        if ( v19 == 9 )
        {
          v20 = (unsigned __int8)(v17 - 4);
          if ( (unsigned int)v20 <= 7 )
          {
LABEL_24:
            v22 = "%s: Invalid KDE data_len %d";
LABEL_19:
            qdf_trace_msg(0x35u, 2u, v22, a5, a6, a7, a8, a9, a10, a11, a12, "lim_parse_kde_elements", v20);
            return 16;
          }
          a2[1327] = v17 - 12;
          qdf_mem_copy(a2 + 1328, v14 + 14, (unsigned int)(v20 - 8));
          qdf_mem_copy(a2 + 1583, v14 + 8, 6u);
        }
        else if ( v19 == 1 )
        {
          v20 = (unsigned __int8)(v17 - 4);
          if ( (unsigned int)v20 <= 1 )
            goto LABEL_24;
          qdf_mem_copy(a2 + 1071, v14 + 8, (unsigned int)(v20 - 2));
          a2[1070] = v17 - 6;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Unknown KDE data type %x",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "lim_parse_kde_elements");
        }
      }
      v16 = v18 - v17;
      v14 += v17 + 2;
    }
    while ( (unsigned __int8)(v18 - v17) > 1u );
  }
  if ( !a2[1070] )
  {
    qdf_trace_msg(0x35u, 2u, "%s: GTK not found in KDE", a5, a6, a7, a8, a9, a10, a11, a12, "lim_parse_kde_elements");
    return 16;
  }
  return 0;
}
