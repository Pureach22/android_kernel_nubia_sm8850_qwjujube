__int64 __fastcall ddr_cdev_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x23
  __int64 v4; // x0
  __int64 v5; // x22
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x19
  unsigned __int64 v8; // x24
  unsigned int *v9; // x0
  unsigned int *v10; // x25
  __int64 v11; // x3
  int variable_u32_array; // w0
  int v13; // w8
  int v14; // w0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x10
  int v17; // w9
  unsigned __int64 v18; // x10
  int v19; // w26
  __int64 v20; // x12
  unsigned __int64 v21; // x13
  int *v22; // x11
  unsigned __int64 v23; // x12
  int v24; // w14
  unsigned __int64 v25; // x11
  int v26; // w0
  unsigned __int64 v27; // x0
  const char *v28; // x1
  const char *v29; // x1
  int v31; // [xsp+8h] [xbp-28h] BYREF
  int v32; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-20h] BYREF
  int v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v1 = a1 + 16;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v31 = 1;
  v32 = 0;
  v34 = 0;
  v33[0] = *(_QWORD *)"ddr-cdev";
  v33[1] = 0;
  v4 = devm_kmalloc(a1 + 16, 48, 3520);
  if ( !v4 )
  {
    LODWORD(v7) = -12;
    goto LABEL_37;
  }
  v5 = v4;
  v6 = of_icc_get(v1, 0);
  v7 = v6;
  *(_QWORD *)(v5 + 16) = v6;
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( of_find_property(v3, "qcom,freq-table", &v32) )
    {
      if ( v32 > 0 )
      {
        v8 = 4 * (((unsigned __int64)(unsigned int)v32 >> 2) + 1);
        v32 = ((unsigned int)v32 >> 2) + 1;
        v9 = (unsigned int *)devm_kmalloc(v1, v8, 3520);
        if ( v9 )
        {
          v10 = v9;
          v11 = v32 - 1;
          *v9 = 0;
          variable_u32_array = of_property_read_variable_u32_array(v3, "qcom,freq-table", v9 + 1, v11, 0);
          if ( variable_u32_array < 0 )
          {
            v19 = variable_u32_array;
            v29 = "DDR frequency read error:%d\n";
          }
          else
          {
            v13 = v32;
            *(_DWORD *)(v5 + 40) = v32;
            *(_DWORD *)v5 = 0;
            *(_DWORD *)(v5 + 4) = v13 - 1;
            *(_QWORD *)(v5 + 24) = v1;
            *(_QWORD *)(v5 + 32) = v10;
            v14 = of_property_read_variable_u32_array(v3, "qcom,bus-width", &v31, 1, 0);
            if ( v14 < 0 )
            {
              v19 = v14;
              v29 = "DDR bus width read error:%d\n";
            }
            else
            {
              v15 = (unsigned int)v32;
              if ( v32 >= 1 )
              {
                v16 = (unsigned int)v32 - 1LL;
                if ( v8 >> 2 < v16 )
                  v16 = v8 >> 2;
                v17 = v31;
                if ( v16 > 1 )
                {
                  v20 = (v16 + 1) & 1;
                  if ( !v20 )
                    v20 = 2;
                  v21 = ~v16;
                  v18 = v16 + 1 - v20;
                  v22 = (int *)(v10 + 1);
                  v23 = v21 + v20;
                  do
                  {
                    v23 += 2LL;
                    v24 = *v22 * v17;
                    *(v22 - 1) *= v17;
                    *v22 = v24;
                    v22 += 2;
                  }
                  while ( v23 );
                }
                else
                {
                  v18 = 0;
                }
                v25 = 4 * v18;
                do
                {
                  if ( v25 >= v8 )
                    __break(1u);
                  ++v18;
                  v10[v25 / 4] *= v17;
                  v25 += 4LL;
                }
                while ( v18 < v15 );
              }
              v26 = icc_set_bw(v7, 0, *v10);
              if ( (v26 & 0x80000000) == 0 )
              {
                v27 = devm_thermal_of_cooling_device_register(v1, v3, v33, v5, &ddr_cdev_ops);
                *(_QWORD *)(v5 + 8) = v27;
                if ( v27 < 0xFFFFFFFFFFFFF001LL )
                {
                  LODWORD(v7) = 0;
                  *(_QWORD *)(a1 + 168) = v5;
                  goto LABEL_37;
                }
                v19 = v27;
                dev_err(v1, "Cdev register failed for %s, ret:%d\n", (const char *)v33, v27);
                v7 = *(_QWORD *)(v5 + 16);
LABEL_36:
                icc_put(v7);
                LODWORD(v7) = v19;
                goto LABEL_37;
              }
              v19 = v26;
              v29 = "Error placing DDR freq request. err:%d\n";
            }
          }
          dev_err(v1, v29);
          goto LABEL_36;
        }
        v19 = -12;
        goto LABEL_36;
      }
      v28 = "No DDR frequency\n";
    }
    else
    {
      v28 = "No DDR frequency entries\n";
    }
    dev_err(v1, v28);
    v19 = -19;
    goto LABEL_36;
  }
  if ( (_DWORD)v6 == -517 )
    LODWORD(v7) = -517;
  else
    dev_err(v1, "Unable to register icc path: %d\n", v6);
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
