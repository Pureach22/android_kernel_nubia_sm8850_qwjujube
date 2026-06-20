_DWORD *__fastcall hfi_setup_dspp_pa_dither_v1_7(_DWORD *result, __int64 a2)
{
  __int64 v2; // d14
  _DWORD *v3; // x19
  _DWORD *v4; // x8
  unsigned int v5; // w9
  unsigned __int64 v6; // x9
  _DWORD *v7; // x10
  int v8; // w9
  unsigned int v9; // w10
  __int64 v10; // x0
  __int64 v11; // x15
  __int64 v12; // d3

  if ( !a2 )
    return (_DWORD *)printk(&unk_27357F, a2);
  v3 = result;
  if ( *(_DWORD *)(a2 + 8) != 80 )
  {
    if ( *(_QWORD *)a2 )
      return (_DWORD *)printk(&unk_27357F, a2);
  }
  LODWORD(v4) = result[374];
  if ( (unsigned int)v4 >= 2 )
    return (_DWORD *)printk(&unk_26C383, (unsigned int)v4);
  v5 = *(_DWORD *)(a2 + 176);
  if ( v5 > 5 )
    goto LABEL_41;
  v6 = 76LL * v5 + 380LL * (unsigned int)v4;
  v4 = (_DWORD *)((char *)&hfi_pa_dither_cached + v6);
  if ( *(_QWORD *)a2 )
  {
    if ( v6 <= 0x2F7 )
    {
      *v4 = 1;
      if ( v6 <= 0x2EB )
      {
        v7 = *(_DWORD **)a2;
        v4[3] = *(_DWORD *)(*(_QWORD *)a2 + 16LL);
        if ( v6 <= 0x2E7 )
        {
          v4[4] = v7[5];
          if ( v6 <= 0x2E3 )
          {
            v4[5] = v7[6];
            if ( v6 <= 0x2DF )
            {
              v4[6] = v7[7];
              if ( v6 <= 0x2DB )
              {
                v4[7] = v7[8];
                if ( v6 <= 0x2D7 )
                {
                  v4[8] = v7[9];
                  if ( v6 <= 0x2D3 )
                  {
                    v4[9] = v7[10];
                    if ( v6 <= 0x2CF )
                    {
                      v4[10] = v7[11];
                      if ( v6 <= 0x2CB )
                      {
                        v4[11] = v7[12];
                        if ( v6 <= 0x2C7 )
                        {
                          v4[12] = v7[13];
                          if ( v6 <= 0x2C3 )
                          {
                            v4[13] = v7[14];
                            if ( v6 <= 0x2BF )
                            {
                              v4[14] = v7[15];
                              if ( v6 <= 0x2BB )
                              {
                                v4[15] = v7[16];
                                if ( v6 <= 0x2B7 )
                                {
                                  v4[16] = v7[17];
                                  if ( v6 <= 0x2B3 )
                                  {
                                    v4[17] = v7[18];
                                    if ( v6 <= 0x2AF )
                                    {
                                      v4[18] = v7[19];
                                      v4[1] = v7[2];
                                      v4[2] = v7[3];
                                      goto LABEL_27;
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
    goto LABEL_40;
  }
  if ( v6 > 0x2F7 )
  {
LABEL_40:
    __break(1u);
LABEL_41:
    __break(0x5512u);
    goto LABEL_42;
  }
  *v4 = 0;
LABEL_27:
  LODWORD(v4) = *(_DWORD *)(a2 + 172);
  v8 = *(_DWORD *)(a2 + 28);
  if ( *(_DWORD *)(a2 + 176) != (_DWORD)v4 + v8 - 1 )
    return result;
  if ( (unsigned int)v4 > 5 )
    goto LABEL_41;
  v9 = result[374];
  if ( v9 > 1 )
    goto LABEL_41;
  if ( (unsigned int)hfi_util_u32_prop_helper_add_prop(
                       *(int **)(a2 + 152),
                       7475473,
                       2,
                       (char *)&hfi_pa_dither_cached + 380 * v9 + 76 * (unsigned int)v4,
                       (unsigned int)(76 * v8)) )
  {
    printk(&unk_21204E, 7475473);
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "non-broadcast feature: submitted to prop_helper\n");
  }
  LODWORD(v4) = v3[374];
  if ( (unsigned int)v4 > 2 )
    goto LABEL_41;
  if ( (_DWORD)v4 == 2 )
  {
LABEL_42:
    v10 = _fortify_panic(15, (unsigned int)(-380 * (_DWORD)v4 + 760), 380);
    *(_QWORD *)(v11 - 24) = v2;
    *(_QWORD *)(v11 - 16) = v12;
    return (_DWORD *)hfi_setup_dspp_spr_dither_v2(v10);
  }
  return memset((char *)&hfi_pa_dither_cached + 380 * (unsigned int)v4, 0, 0x17Cu);
}
