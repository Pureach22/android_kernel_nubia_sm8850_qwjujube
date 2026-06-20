__int64 __fastcall dot11f_unpack_ie_measurement_request(
        __int64 a1,
        _BYTE *a2,
        char a3,
        _BYTE *a4,
        char a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x29
  __int64 v9; // x30
  __int64 result; // x0
  int v14; // w10
  __int64 v16; // x22
  char v17; // w23
  unsigned __int8 v18; // w8
  void *v19; // x3
  void *v20; // x4
  _BYTE *v21; // x1
  __int64 v22; // x2
  __int64 v23; // x6
  __int64 v24; // x0
  __int64 v25; // [xsp+8h] [xbp-38h]

  if ( *a4 )
    return 32;
  v25 = v9;
  *a4 = 1;
  if ( !a3 )
    goto LABEL_44;
  a4[1] = *a2;
  if ( a3 == 1 )
    goto LABEL_44;
  a4[2] = a2[1];
  if ( a3 == 2 )
    goto LABEL_44;
  v14 = (unsigned __int8)a2[2];
  result = 0;
  a4[3] = v14;
  if ( v14 > 4 )
  {
    if ( v14 > 7 )
    {
      if ( v14 == 8 )
      {
        if ( a3 != 3 )
        {
          v19 = &FFS_measurement_requestlci;
          v21 = a2 + 4;
          v22 = (unsigned __int8)(a3 - 4);
          a4[4] = a2[3];
          v23 = a5 & 1;
          v24 = a1;
          v20 = &IES_measurement_requestlci;
          return unpack_core(v24, v21, v22, v19, v20, a4, v23, a8, v8, v25);
        }
      }
      else
      {
        if ( v14 != 16 )
          return result;
        v16 = a1;
        if ( (unsigned __int8)(a3 - 3) > 1u )
        {
          v17 = a5;
          qdf_mem_copy(a4 + 4, a2 + 3, 2u);
          if ( a3 != 5 )
          {
            v19 = &FFS_measurement_requestftmrr;
            v20 = &IES_measurement_requestftmrr;
            v21 = a2 + 6;
            a4[6] = a2[5];
            v18 = a3 - 6;
            goto LABEL_39;
          }
        }
      }
    }
    else if ( v14 == 5 )
    {
      if ( a3 != 3 )
      {
        a4[4] = a2[3];
        if ( a3 != 4 )
        {
          v16 = a1;
          a4[5] = a2[4];
          if ( (unsigned __int8)(a3 - 5) > 1u )
          {
            v17 = a5;
            qdf_mem_copy(a4 + 6, a2 + 5, 2u);
            if ( (unsigned __int8)(a3 - 7) > 1u )
            {
              qdf_mem_copy(a4 + 8, a2 + 7, 2u);
              if ( a3 != 9 )
              {
                a4[10] = a2[9];
                if ( (unsigned __int8)(a3 - 10) > 5u )
                {
                  qdf_mem_copy(a4 + 11, a2 + 10, 6u);
                  v18 = a3 - 16;
                  v19 = &FFS_measurement_requestBeacon;
                  v20 = &IES_measurement_requestBeacon;
                  v21 = a2 + 16;
                  goto LABEL_39;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      if ( v14 != 7 )
        return result;
      if ( (unsigned __int8)(a3 - 3) > 5u )
      {
        qdf_mem_copy(a4 + 4, a2 + 3, 6u);
        if ( (unsigned __int8)(a3 - 9) > 1u )
        {
          qdf_mem_copy(a4 + 10, a2 + 9, 2u);
          if ( (unsigned __int8)(a3 - 11) > 1u )
          {
            qdf_mem_copy(a4 + 12, a2 + 11, 2u);
            if ( a3 != 13 )
            {
              a4[14] = a2[13];
              return 0;
            }
          }
        }
      }
    }
LABEL_44:
    *a4 = 0;
    return 4;
  }
  if ( v14 <= 2 )
  {
    if ( a3 != 3 )
    {
      a4[4] = a2[3];
      if ( (unsigned __int8)(a3 - 4) > 7u )
      {
        qdf_mem_copy(a4 + 5, a2 + 4, 8u);
        if ( (a3 & 0xFE) != 0xC )
        {
          qdf_mem_copy(a4 + 14, a2 + 12, 2u);
          return 0;
        }
      }
    }
    goto LABEL_44;
  }
  if ( v14 == 3 )
  {
    if ( a3 != 3 )
    {
      a4[4] = a2[3];
      if ( a3 != 4 )
      {
        v16 = a1;
        a4[5] = a2[4];
        if ( (unsigned __int8)(a3 - 5) > 1u )
        {
          v17 = a5;
          qdf_mem_copy(a4 + 6, a2 + 5, 2u);
          if ( (unsigned __int8)(a3 - 7) > 1u )
          {
            qdf_mem_copy(a4 + 8, a2 + 7, 2u);
            v18 = a3 - 9;
            v19 = &FFS_measurement_requestchannel_load;
            v20 = &IES_measurement_requestchannel_load;
            v21 = a2 + 9;
LABEL_39:
            v22 = v18;
            v23 = v17 & 1;
            v24 = v16;
            return unpack_core(v24, v21, v22, v19, v20, a4, v23, a8, v8, v25);
          }
        }
      }
    }
    goto LABEL_44;
  }
  return result;
}
