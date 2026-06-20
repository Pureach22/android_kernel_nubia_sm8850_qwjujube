__int64 __fastcall dot11f_unpack_ie_measurement_report(__int64 a1, _BYTE *a2, char a3, _BYTE *a4, char a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 result; // x0
  int v11; // w8
  __int64 v14; // x7
  int v15; // w10
  _BYTE *v16; // x1
  unsigned __int8 v17; // w8
  char v18; // w9
  __int64 v19; // x0
  void *v20; // x3
  _UNKNOWN **v21; // x4
  unsigned __int8 v22; // w8
  __int64 v23; // x2
  __int64 v24; // x6
  __int64 v25; // [xsp+8h] [xbp-38h]

  if ( *a4 )
    return 32;
  v25 = v6;
  *a4 = 1;
  if ( !a3 )
    goto LABEL_91;
  a4[1] = *a2;
  if ( a3 == 1 )
    goto LABEL_91;
  a4[2] = a2[1];
  if ( a3 == 2 )
    goto LABEL_91;
  v11 = (unsigned __int8)a2[2];
  a4[3] = v11;
  if ( a3 == 3 )
    return 0;
  result = 0;
  if ( v11 <= 2 )
  {
    if ( (unsigned int)v11 < 2 )
    {
      a4[4] = a2[3];
      if ( (unsigned __int8)(a3 - 4) > 7u )
      {
        qdf_mem_copy(a4 + 8, a2 + 4, 4u);
        qdf_mem_copy(a4 + 12, a2 + 8, 4u);
        if ( (a3 & 0xFE) != 0xC )
        {
          qdf_mem_copy(a4 + 16, a2 + 12, 2u);
          if ( a3 != 14 )
          {
            a4[18] = a2[14];
            return 0;
          }
        }
      }
    }
    else
    {
      a4[4] = a2[3];
      if ( (unsigned __int8)(a3 - 4) > 7u )
      {
        qdf_mem_copy(a4 + 8, a2 + 4, 4u);
        qdf_mem_copy(a4 + 12, a2 + 8, 4u);
        if ( (a3 & 0xFE) != 0xC )
        {
          qdf_mem_copy(a4 + 16, a2 + 12, 2u);
          if ( a3 != 14 )
          {
            a4[18] = a2[14];
            if ( a3 != 15 )
            {
              a4[19] = a2[15];
              if ( a3 != 16 )
              {
                a4[20] = a2[16];
                if ( a3 != 17 )
                {
                  a4[21] = a2[17];
                  if ( a3 != 18 )
                  {
                    a4[22] = a2[18];
                    if ( a3 != 19 )
                    {
                      a4[23] = a2[19];
                      if ( a3 != 20 )
                      {
                        a4[24] = a2[20];
                        if ( a3 != 21 )
                        {
                          a4[25] = a2[21];
                          return 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LABEL_91;
  }
  switch ( v11 )
  {
    case 3:
      a4[4] = a2[3];
      if ( a3 == 4 )
        goto LABEL_91;
      a4[5] = a2[4];
      if ( (unsigned __int8)(a3 - 5) <= 7u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 8, a2 + 5, 4u);
      qdf_mem_copy(a4 + 12, a2 + 9, 4u);
      if ( (unsigned __int8)(a3 - 13) <= 1u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 16, a2 + 13, 2u);
      if ( a3 == 15 )
        goto LABEL_91;
      v20 = &FFS_reportchannel_load_report;
      v21 = (_UNKNOWN **)&IES_reportchannel_load_report;
      v16 = a2 + 16;
      a4[18] = a2[15];
      v22 = a3 - 16;
      break;
    case 5:
      a4[4] = a2[3];
      if ( a3 == 4 )
        goto LABEL_91;
      a4[5] = a2[4];
      if ( (unsigned __int8)(a3 - 5) <= 7u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 8, a2 + 5, 4u);
      qdf_mem_copy(a4 + 12, a2 + 9, 4u);
      if ( (unsigned __int8)(a3 - 13) <= 1u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 16, a2 + 13, 2u);
      if ( a3 == 15 )
        goto LABEL_91;
      a4[18] = a2[15];
      if ( a3 == 16 )
        goto LABEL_91;
      a4[19] = a2[16];
      if ( a3 == 17 )
        goto LABEL_91;
      a4[20] = a2[17];
      if ( (unsigned __int8)(a3 - 18) <= 5u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 21, a2 + 18, 6u);
      if ( a3 == 24 )
        goto LABEL_91;
      a4[27] = a2[24];
      if ( (unsigned __int8)(a3 - 25) <= 3u )
        goto LABEL_91;
      qdf_mem_copy(a4 + 28, a2 + 25, 4u);
      v22 = a3 - 29;
      v20 = &FFS_reportBeacon;
      v21 = (_UNKNOWN **)&IES_reportBeacon;
      v16 = a2 + 29;
      break;
    case 7:
      if ( (unsigned __int8)(a3 - 3) != 1 )
      {
        qdf_mem_copy(a4 + 4, a2 + 3, 2u);
        if ( a3 != 5 )
        {
          v15 = (unsigned __int8)a2[5];
          v16 = a2 + 6;
          v17 = a3 - 6;
          v18 = a5;
          v19 = a1;
          a4[6] = v15;
          if ( v15 > 1 )
          {
            if ( v15 == 2 )
            {
              if ( (unsigned __int8)(a3 - 6) > 3u )
              {
                qdf_mem_copy(a4 + 8, v16, 4u);
                if ( (unsigned __int8)(a3 - 10) > 3u )
                {
                  qdf_mem_copy(a4 + 12, a2 + 10, 4u);
                  if ( (unsigned __int8)(a3 - 14) > 3u )
                  {
                    qdf_mem_copy(a4 + 16, a2 + 14, 4u);
                    if ( (unsigned __int8)(a3 - 18) > 3u )
                    {
                      qdf_mem_copy(a4 + 20, a2 + 18, 4u);
                      if ( (unsigned __int8)(a3 - 22) > 3u )
                      {
                        qdf_mem_copy(a4 + 24, a2 + 22, 4u);
                        if ( (unsigned __int8)(a3 - 26) > 3u )
                        {
                          qdf_mem_copy(a4 + 28, a2 + 26, 4u);
                          if ( (unsigned __int8)(a3 - 30) > 3u )
                          {
                            qdf_mem_copy(a4 + 32, a2 + 30, 4u);
                            if ( (unsigned __int8)(a3 - 34) > 3u )
                            {
                              qdf_mem_copy(a4 + 36, a2 + 34, 4u);
                              if ( (unsigned __int8)(a3 - 38) > 3u )
                              {
                                qdf_mem_copy(a4 + 40, a2 + 38, 4u);
                                if ( (unsigned __int8)(a3 - 42) > 3u )
                                {
                                  qdf_mem_copy(a4 + 44, a2 + 42, 4u);
                                  if ( (unsigned __int8)(a3 - 46) > 3u )
                                  {
                                    qdf_mem_copy(a4 + 48, a2 + 46, 4u);
                                    if ( (unsigned __int8)(a3 - 50) > 3u )
                                    {
                                      qdf_mem_copy(a4 + 52, a2 + 50, 4u);
                                      if ( (unsigned __int8)(a3 - 54) > 3u )
                                      {
                                        qdf_mem_copy(a4 + 56, a2 + 54, 4u);
                                        v16 = a2 + 58;
                                        v17 = a3 - 58;
                                        goto LABEL_87;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else
            {
              if ( v15 != 10 )
              {
LABEL_88:
                v20 = &FFS_reportsta_stats;
                v21 = &IES_reportsta_stats;
                v23 = v17;
                v24 = v18 & 1;
                return unpack_core(v19, v16, v23, v20, v21, a4, v24, v14, v5, v25);
              }
              if ( a3 != 6 )
              {
                a4[8] = *v16;
                if ( a3 != 7 )
                {
                  a4[9] = a2[7];
                  if ( a3 != 8 )
                  {
                    a4[10] = a2[8];
                    if ( a3 != 9 )
                    {
                      a4[11] = a2[9];
                      if ( a3 != 10 )
                      {
                        a4[12] = a2[10];
                        if ( (unsigned __int8)(a3 - 11) > 1u )
                        {
                          qdf_mem_copy(a4 + 14, a2 + 11, 2u);
                          if ( a3 != 13 )
                          {
                            v16 = a2 + 14;
                            a4[16] = a2[13];
                            v17 = a3 - 14;
                            goto LABEL_87;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if ( v15 )
          {
            if ( (unsigned __int8)(a3 - 6) > 3u )
            {
              qdf_mem_copy(a4 + 8, v16, 4u);
              if ( (unsigned __int8)(a3 - 10) > 3u )
              {
                qdf_mem_copy(a4 + 12, a2 + 10, 4u);
                if ( (unsigned __int8)(a3 - 14) > 3u )
                {
                  qdf_mem_copy(a4 + 16, a2 + 14, 4u);
                  if ( (unsigned __int8)(a3 - 18) > 3u )
                  {
                    qdf_mem_copy(a4 + 20, a2 + 18, 4u);
                    if ( (unsigned __int8)(a3 - 22) > 3u )
                    {
                      qdf_mem_copy(a4 + 24, a2 + 22, 4u);
                      if ( (unsigned __int8)(a3 - 26) > 3u )
                      {
                        qdf_mem_copy(a4 + 28, a2 + 26, 4u);
                        v16 = a2 + 30;
                        v17 = a3 - 30;
LABEL_87:
                        v18 = a5;
                        v19 = a1;
                        goto LABEL_88;
                      }
                    }
                  }
                }
              }
            }
          }
          else if ( (unsigned __int8)(a3 - 6) > 3u )
          {
            qdf_mem_copy(a4 + 8, v16, 4u);
            if ( (unsigned __int8)(a3 - 10) > 3u )
            {
              qdf_mem_copy(a4 + 12, a2 + 10, 4u);
              if ( (unsigned __int8)(a3 - 14) > 3u )
              {
                qdf_mem_copy(a4 + 16, a2 + 14, 4u);
                if ( (unsigned __int8)(a3 - 18) > 3u )
                {
                  qdf_mem_copy(a4 + 20, a2 + 18, 4u);
                  if ( (unsigned __int8)(a3 - 22) > 3u )
                  {
                    qdf_mem_copy(a4 + 24, a2 + 22, 4u);
                    if ( (unsigned __int8)(a3 - 26) > 3u )
                    {
                      qdf_mem_copy(a4 + 28, a2 + 26, 4u);
                      if ( (unsigned __int8)(a3 - 30) > 3u )
                      {
                        qdf_mem_copy(a4 + 32, a2 + 30, 4u);
                        v16 = a2 + 34;
                        v17 = a3 - 34;
                        goto LABEL_87;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_91:
      *a4 = 0;
      return 4;
    default:
      return result;
  }
  v23 = v22;
  v24 = a5 & 1;
  v19 = a1;
  return unpack_core(v19, v16, v23, v20, v21, a4, v24, v14, v5, v25);
}
