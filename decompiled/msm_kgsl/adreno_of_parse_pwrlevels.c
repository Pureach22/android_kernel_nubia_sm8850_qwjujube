__int64 __fastcall adreno_of_parse_pwrlevels(_QWORD *a1, __int64 a2)
{
  __int64 next_child; // x0
  const void *v5; // x20
  unsigned int variable_u32_array; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w3
  int v11; // w9
  _DWORD *v12; // x22
  int v13; // w10
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w2
  __int64 v18; // x20
  unsigned __int64 v19; // x21
  unsigned int *v20; // x22
  unsigned int v21; // t1
  unsigned int v22; // w27
  int v24; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v26[4]; // [xsp+10h] [xbp-20h] BYREF

  v26[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *((_DWORD *)a1 + 2517) = 0;
  next_child = of_get_next_child(a2, 0);
  if ( next_child )
  {
    v5 = (const void *)next_child;
    do
    {
      LODWORD(v26[0]) = 0;
      v25 = 0;
      v24 = 0;
      variable_u32_array = of_property_read_variable_u32_array(v5, "reg", v26, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v22 = variable_u32_array;
        dev_err(*a1, "%pOF: powerlevel index not found\n", v5);
        goto LABEL_30;
      }
      v7 = of_property_read_variable_u32_array(v5, "qcom,gpu-freq", (char *)&v25 + 4, 1, 0);
      if ( (v7 & 0x80000000) != 0 )
      {
        v22 = v7;
        dev_err(*a1, "%pOF: Unable to read qcom,gpu-freq\n", v5);
        goto LABEL_30;
      }
      if ( HIDWORD(v25) )
      {
        v8 = of_property_read_variable_u32_array(v5, "qcom,level", &v25, 1, 0);
        if ( (v8 & 0x80000000) != 0 )
        {
          v22 = v8;
          dev_err(*a1, "%pOF: Unable to read qcom,level\n", v5);
          goto LABEL_30;
        }
        v9 = kgsl_of_property_read_ddrtype(v5, "qcom,bus-freq", &v24);
        if ( v9 )
        {
          v22 = v9;
          dev_err(*a1, "%pOF:Unable to read qcom,bus-freq\n", v5);
          goto LABEL_30;
        }
        v10 = v26[0];
        if ( LODWORD(v26[0]) >= 0x20 )
        {
          dev_err(*a1, "%pOF: Pwrlevel index %d is out of range\n", v5, LODWORD(v26[0]));
        }
        else
        {
          if ( LODWORD(v26[0]) >= *((_DWORD *)a1 + 2517) )
            *((_DWORD *)a1 + 2517) = LODWORD(v26[0]) + 1;
          v11 = v24;
          v12 = (_DWORD *)a1 + 7 * v10 + 2286;
          v13 = v25;
          *v12 = HIDWORD(v25);
          v12[1] = v11;
          v12[6] = v13;
          v12[5] = -1;
          of_property_read_variable_u32_array(v5, "qcom,acd-level", v12 + 4, 1, 0);
          of_property_read_variable_u32_array(v5, "qcom,cx-level", v12 + 5, 1, 0);
          v12[2] = v12[1];
          kgsl_of_property_read_ddrtype(v5, "qcom,bus-min", v12 + 2);
          v12[3] = v12[1];
          kgsl_of_property_read_ddrtype(v5, "qcom,bus-max", v12 + 3);
          if ( *(_DWORD *)a1[1783] == 524801 && !*((_DWORD *)a1 + 3296) )
          {
            v14 = v25;
            if ( (_DWORD)v25 == 51 )
            {
              if ( (adreno_of_parse_pwrlevels___print_once & 1) != 0 )
              {
                v14 = 51;
              }
              else
              {
                v15 = *a1;
                adreno_of_parse_pwrlevels___print_once = 1;
                dev_err(v15, "Voltage override due to CPR Rev ID: 0x%x\n", 0);
                v14 = v25;
              }
              v12[6] = 52;
            }
            if ( v14 == 50 )
            {
              if ( (adreno_of_parse_pwrlevels___print_once_110 & 1) == 0 )
              {
                v16 = *a1;
                v17 = *((_DWORD *)a1 + 3296);
                adreno_of_parse_pwrlevels___print_once_110 = 1;
                dev_err(v16, "Voltage override due to CPR Rev ID: 0x%x\n", v17);
              }
              v12[6] = 52;
            }
          }
        }
      }
      v5 = (const void *)of_get_next_child(a2, v5);
    }
    while ( v5 );
  }
  v18 = a1[1396];
  if ( (int)dev_pm_opp_get_opp_count(v18 + 16) <= 0 && *((_DWORD *)a1 + 2517) )
  {
    v19 = 0;
    v20 = (unsigned int *)(a1 + 1143);
    do
    {
      if ( v19 == 32 )
        __break(0x5512u);
      v21 = *v20;
      v20 += 7;
      v26[2] = 0;
      v26[0] = 0;
      v26[1] = v21;
      dev_pm_opp_add_dynamic(v18 + 16, v26);
      ++v19;
    }
    while ( v19 < *((unsigned int *)a1 + 2517) );
  }
  v22 = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v22;
}
