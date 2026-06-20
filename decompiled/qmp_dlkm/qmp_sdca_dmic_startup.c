__int64 __fastcall qmp_sdca_dmic_startup(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  int v5; // w0
  int v6; // w20
  __int64 result; // x0
  int v8; // w21
  int v9; // w0
  int v10; // w27
  __int64 v11; // x0
  int v12; // w0
  int v13; // w27
  int logical_dev_num; // w0
  unsigned int variable_u32_array; // w0
  unsigned __int64 v16; // x20
  unsigned __int64 v17; // x21
  __int64 v18; // x8
  _BYTE v19[4]; // [xsp+Ch] [xbp-114h] BYREF
  _QWORD v20[34]; // [xsp+10h] [xbp-110h] BYREF

  v20[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  if ( *(_QWORD *)(v2 + 16) )
  {
    v3 = *(unsigned int *)(a2 + 8);
    v19[0] = 0;
    if ( (unsigned int)v3 >= 3 )
      goto LABEL_37;
    if ( !*(_BYTE *)(v2 + 56 + v3) )
      goto LABEL_32;
    if ( *(_QWORD *)(v2 + 48) )
    {
      v5 = regulator_enable(*(_QWORD *)(v2 + 48));
      if ( v5 )
      {
        v6 = v5;
        if ( (unsigned int)__ratelimit(&qmp_enable_regulator__rs, "qmp_enable_regulator") )
          dev_err(*(_QWORD *)(v2 + 8), "qmp regulator enable failed %d", v6);
        goto LABEL_8;
      }
      usleep_range_state(5000, 5500, 2);
      if ( !(unsigned int)swr_get_logical_dev_num(*(_QWORD *)(v2 + 16), *(_QWORD *)(*(_QWORD *)(v2 + 16) + 984LL), v19) )
        goto LABEL_22;
      v8 = 3;
      do
      {
        dev_err(*(_QWORD *)(v2 + 8), "error while getting logical device number\n");
        if ( *(_QWORD *)(v2 + 48) )
        {
          v9 = regulator_disable();
          if ( v9 )
          {
            v10 = v9;
            if ( (unsigned int)__ratelimit(&qmp_disable_regulator__rs, "qmp_disable_regulator") )
              dev_err(*(_QWORD *)(v2 + 8), "qmp regulator disable failed %d", v10);
          }
        }
        usleep_range_state(1000, 1500, 2);
        v11 = *(_QWORD *)(v2 + 48);
        if ( v11 )
        {
          v12 = regulator_enable(v11);
          if ( v12 )
          {
            v13 = v12;
            if ( (unsigned int)__ratelimit(&qmp_enable_regulator__rs, "qmp_enable_regulator") )
              dev_err(*(_QWORD *)(v2 + 8), "qmp regulator enable failed %d", v13);
          }
        }
        usleep_range_state(1000, 1500, 2);
        logical_dev_num = swr_get_logical_dev_num(*(_QWORD *)(v2 + 16), *(_QWORD *)(*(_QWORD *)(v2 + 16) + 984LL), v19);
        if ( !logical_dev_num )
          break;
        --v8;
      }
      while ( (_BYTE)v8 );
      if ( !logical_dev_num )
      {
LABEL_22:
        *(_BYTE *)(*(_QWORD *)(v2 + 16) + 64LL) = v19[0];
        *(_BYTE *)(*(_QWORD *)(v2 + 16) + 1010LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v2 + 16) + 1011LL) = 0;
        if ( !*(_BYTE *)(v2 + 207) )
        {
          memset(v20, 0, 256);
          variable_u32_array = of_property_read_variable_u32_array(
                                 *(_QWORD *)(*(_QWORD *)(v2 + 8) + 744LL),
                                 "reg-values",
                                 v20,
                                 0,
                                 64);
          if ( variable_u32_array == -75 )
          {
            dev_err(*(_QWORD *)(v2 + 8), "num of DT entries exceed expected\n");
          }
          else if ( (variable_u32_array & 0x80000000) == 0 )
          {
            if ( variable_u32_array )
            {
              v16 = 0;
              v17 = variable_u32_array;
              while ( v16 < 0x40 )
              {
                regmap_write(*(_QWORD *)v2, LODWORD(v20[v16 / 2]), HIDWORD(v20[v16 / 2]));
                v16 += 2LL;
                if ( v16 >= v17 )
                  goto LABEL_29;
              }
LABEL_37:
              __break(0x5512u);
            }
LABEL_29:
            *(_BYTE *)(v2 + 207) = 1;
            goto LABEL_30;
          }
          dev_err(*(_QWORD *)(v2 + 8), "failed to set qmp initialization blob\n");
        }
LABEL_30:
        swr_init_port_params(*(_QWORD *)(v2 + 16), 2, v2 + 128);
        *(_DWORD *)(v2 + 200) |= 1LL << *(_DWORD *)(a2 + 8);
        v18 = *(unsigned int *)(a2 + 8);
        if ( (unsigned int)v18 > 2 )
          goto LABEL_37;
        *(_BYTE *)(v2 + v18 + 204) = *(_BYTE *)(v2 + 56 + v18);
        update_ch_per_substream();
LABEL_32:
        result = 0;
        goto LABEL_33;
      }
      dev_err(
        *(_QWORD *)(v2 + 8),
        "%s get devnum %d for dev addr %llx failed\n",
        "qmp_sdca_dmic_startup",
        v19[0],
        *(_QWORD *)(*(_QWORD *)(v2 + 16) + 984LL));
      qmp_disable_regulator(v2);
    }
  }
LABEL_8:
  result = 4294967274LL;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
