__int64 __fastcall wsa884x_parse_port_params(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x0
  unsigned __int64 v4; // x20
  _DWORD *v5; // x19
  unsigned int variable_u32_array; // w0
  int v7; // w9
  int v8; // w8
  int v9; // w8
  int v10; // w8
  __int64 result; // x0
  unsigned int v12; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x24
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(a1 + 744);
  v15 = 0;
  if ( !of_find_property(v3, "qcom,swr-wsa-port-params", &v15) )
  {
    dev_err(a1, "missing port mapping prop %s\n", "qcom,swr-wsa-port-params");
LABEL_102:
    result = 4294967274LL;
    goto LABEL_106;
  }
  if ( v15 - 192 >= 0x30 )
  {
    dev_err(a1, "%s: port params not provided for all usecases\n", "wsa884x_parse_port_params");
    goto LABEL_102;
  }
  v4 = v15;
  v5 = (_DWORD *)_kmalloc_noprof(v15, 3520);
  if ( v5 )
  {
    while ( 1 )
    {
      variable_u32_array = of_property_read_variable_u32_array(
                             *(_QWORD *)(a1 + 744),
                             "qcom,swr-wsa-port-params",
                             v5,
                             48,
                             0);
      if ( (variable_u32_array & 0x80000000) != 0 )
        break;
      if ( v4 >= 4 )
      {
        *(_DWORD *)(v2 + 320) = *v5;
        if ( (v4 & 0xFFFFFFFC) != 4 )
        {
          *(_DWORD *)(v2 + 324) = v5[1];
          if ( v4 >= 8 && (v4 & 0xFFFFFFFC) != 8 )
          {
            *(_DWORD *)(v2 + 328) = v5[2];
            if ( v4 >= 0xC && (v4 & 0xFFFFFFFC) != 0xC )
            {
              *(_DWORD *)(v2 + 332) = v5[3];
              if ( v4 >= 0x10 && (v4 & 0xFFFFFFFC) != 0x10 )
              {
                *(_DWORD *)(v2 + 336) = v5[4];
                if ( v4 >= 0x14 && (v4 & 0xFFFFFFFC) != 0x14 )
                {
                  *(_DWORD *)(v2 + 340) = v5[5];
                  if ( v4 >= 0x18 && (v4 & 0xFFFFFFFC) != 0x18 )
                  {
                    *(_DWORD *)(v2 + 344) = v5[6];
                    if ( v4 >= 0x1C && (v4 & 0xFFFFFFFC) != 0x1C )
                    {
                      *(_DWORD *)(v2 + 348) = v5[7];
                      if ( v4 >= 0x20 && (v4 & 0xFFFFFFFC) != 0x20 )
                      {
                        *(_DWORD *)(v2 + 352) = v5[8];
                        if ( v4 >= 0x24 && (v4 & 0xFFFFFFFC) != 0x24 )
                        {
                          *(_DWORD *)(v2 + 356) = v5[9];
                          if ( v4 >= 0x28 && (v4 & 0xFFFFFFFC) != 0x28 )
                          {
                            *(_DWORD *)(v2 + 360) = v5[10];
                            if ( v4 >= 0x2C && (v4 & 0xFFFFFFFC) != 0x2C )
                            {
                              v7 = v5[11];
                              *(_QWORD *)(v2 + 512) = v2 + 320;
                              *(_DWORD *)(v2 + 364) = v7;
                              if ( v4 >= 0x30 && (v4 & 0xFFFFFFFC) != 0x30 )
                              {
                                *(_DWORD *)(v2 + 368) = v5[12];
                                if ( v4 >= 0x34 && (v4 & 0xFFFFFFFC) != 0x34 )
                                {
                                  *(_DWORD *)(v2 + 372) = v5[13];
                                  if ( v4 >= 0x38 && (v4 & 0xFFFFFFFC) != 0x38 )
                                  {
                                    *(_DWORD *)(v2 + 376) = v5[14];
                                    if ( v4 >= 0x3C && (v4 & 0xFFFFFFFC) != 0x3C )
                                    {
                                      *(_DWORD *)(v2 + 380) = v5[15];
                                      if ( v4 >= 0x40 && (v4 & 0xFFFFFFFC) != 0x40 )
                                      {
                                        *(_DWORD *)(v2 + 384) = v5[16];
                                        if ( v4 >= 0x44 && (v4 & 0xFFFFFFFC) != 0x44 )
                                        {
                                          *(_DWORD *)(v2 + 388) = v5[17];
                                          if ( v4 >= 0x48 && (v4 & 0xFFFFFFFC) != 0x48 )
                                          {
                                            *(_DWORD *)(v2 + 392) = v5[18];
                                            if ( v4 >= 0x4C && (v4 & 0xFFFFFFFC) != 0x4C )
                                            {
                                              *(_DWORD *)(v2 + 396) = v5[19];
                                              if ( v4 >= 0x50 && (v4 & 0xFFFFFFFC) != 0x50 )
                                              {
                                                *(_DWORD *)(v2 + 400) = v5[20];
                                                if ( v4 >= 0x54 && (v4 & 0xFFFFFFFC) != 0x54 )
                                                {
                                                  *(_DWORD *)(v2 + 404) = v5[21];
                                                  if ( v4 >= 0x58 && (v4 & 0xFFFFFFFC) != 0x58 )
                                                  {
                                                    *(_DWORD *)(v2 + 408) = v5[22];
                                                    if ( v4 >= 0x5C && (v4 & 0xFFFFFFFC) != 0x5C )
                                                    {
                                                      v8 = v5[23];
                                                      *(_QWORD *)(v2 + 520) = v2 + 368;
                                                      *(_DWORD *)(v2 + 412) = v8;
                                                      if ( v4 >= 0x60 && (v4 & 0xFFFFFFFC) != 0x60 )
                                                      {
                                                        *(_DWORD *)(v2 + 416) = v5[24];
                                                        if ( v4 >= 0x64 && (v4 & 0xFFFFFFFC) != 0x64 )
                                                        {
                                                          *(_DWORD *)(v2 + 420) = v5[25];
                                                          if ( v4 >= 0x68 && (v4 & 0xFFFFFFFC) != 0x68 )
                                                          {
                                                            *(_DWORD *)(v2 + 424) = v5[26];
                                                            if ( v4 >= 0x6C && (v4 & 0xFFFFFFFC) != 0x6C )
                                                            {
                                                              *(_DWORD *)(v2 + 428) = v5[27];
                                                              if ( v4 >= 0x70 && (v4 & 0xFFFFFFFC) != 0x70 )
                                                              {
                                                                *(_DWORD *)(v2 + 432) = v5[28];
                                                                if ( v4 >= 0x74 && (v4 & 0xFFFFFFFC) != 0x74 )
                                                                {
                                                                  *(_DWORD *)(v2 + 436) = v5[29];
                                                                  if ( v4 >= 0x78 && (v4 & 0xFFFFFFFC) != 0x78 )
                                                                  {
                                                                    *(_DWORD *)(v2 + 440) = v5[30];
                                                                    if ( v4 >= 0x7C && (v4 & 0xFFFFFFFC) != 0x7C )
                                                                    {
                                                                      *(_DWORD *)(v2 + 444) = v5[31];
                                                                      if ( v4 >= 0x80 && (v4 & 0xFFFFFFFC) != 0x80 )
                                                                      {
                                                                        *(_DWORD *)(v2 + 448) = v5[32];
                                                                        if ( v4 >= 0x84 && (v4 & 0xFFFFFFFC) != 0x84 )
                                                                        {
                                                                          *(_DWORD *)(v2 + 452) = v5[33];
                                                                          if ( v4 >= 0x88 && (v4 & 0xFFFFFFFC) != 0x88 )
                                                                          {
                                                                            *(_DWORD *)(v2 + 456) = v5[34];
                                                                            if ( v4 >= 0x8C && (v4 & 0xFFFFFFFC) != 0x8C )
                                                                            {
                                                                              v9 = v5[35];
                                                                              *(_QWORD *)(v2 + 528) = v2 + 416;
                                                                              *(_DWORD *)(v2 + 460) = v9;
                                                                              if ( v4 >= 0x90
                                                                                && (v4 & 0xFFFFFFFC) != 0x90 )
                                                                              {
                                                                                *(_DWORD *)(v2 + 464) = v5[36];
                                                                                if ( v4 >= 0x94
                                                                                  && (v4 & 0xFFFFFFFC) != 0x94 )
                                                                                {
                                                                                  *(_DWORD *)(v2 + 468) = v5[37];
                                                                                  if ( v4 >= 0x98
                                                                                    && (v4 & 0xFFFFFFFC) != 0x98 )
                                                                                  {
                                                                                    *(_DWORD *)(v2 + 472) = v5[38];
                                                                                    if ( v4 >= 0x9C
                                                                                      && (v4 & 0xFFFFFFFC) != 0x9C )
                                                                                    {
                                                                                      *(_DWORD *)(v2 + 476) = v5[39];
                                                                                      if ( v4 >= 0xA0
                                                                                        && (v4 & 0xFFFFFFFC) != 0xA0 )
                                                                                      {
                                                                                        *(_DWORD *)(v2 + 480) = v5[40];
                                                                                        if ( v4 >= 0xA4
                                                                                          && (v4 & 0xFFFFFFFC) != 0xA4 )
                                                                                        {
                                                                                          *(_DWORD *)(v2 + 484) = v5[41];
                                                                                          if ( v4 >= 0xA8
                                                                                            && (v4 & 0xFFFFFFFC) != 0xA8 )
                                                                                          {
                                                                                            *(_DWORD *)(v2 + 488) = v5[42];
                                                                                            if ( v4 >= 0xAC
                                                                                              && (v4 & 0xFFFFFFFC) != 0xAC )
                                                                                            {
                                                                                              *(_DWORD *)(v2 + 492) = v5[43];
                                                                                              if ( v4 >= 0xB0
                                                                                                && (v4 & 0xFFFFFFFC) != 0xB0 )
                                                                                              {
                                                                                                *(_DWORD *)(v2 + 496) = v5[44];
                                                                                                if ( v4 >= 0xB4 && (v4 & 0xFFFFFFFC) != 0xB4 )
                                                                                                {
                                                                                                  *(_DWORD *)(v2 + 500) = v5[45];
                                                                                                  if ( v4 >= 0xB8 && (v4 & 0xFFFFFFFC) != 0xB8 )
                                                                                                  {
                                                                                                    *(_DWORD *)(v2 + 504) = v5[46];
                                                                                                    if ( v4 >= 0xBC && (v4 & 0xFFFFFFFC) != 0xBC )
                                                                                                    {
                                                                                                      v10 = v5[47];
                                                                                                      *(_QWORD *)(v2 + 536) = v2 + 464;
                                                                                                      *(_DWORD *)(v2 + 508) = v10;
                                                                                                      kfree(v5);
                                                                                                      result = 0;
                                                                                                      goto LABEL_106;
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
                }
              }
            }
          }
        }
      }
      __break(1u);
      v4 = v15;
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &wsa884x_parse_port_params__alloc_tag;
      v5 = (_DWORD *)_kmalloc_noprof(v4, 3520);
      *(_QWORD *)(StatusReg + 80) = v14;
      if ( !v5 )
        goto LABEL_105;
    }
    v12 = variable_u32_array;
    dev_err(
      a1,
      "%s: Failed to read port mapping from prop %s\n",
      "wsa884x_parse_port_params",
      "qcom,swr-wsa-port-params");
    kfree(v5);
    result = v12;
  }
  else
  {
LABEL_105:
    result = 4294967284LL;
  }
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return result;
}
