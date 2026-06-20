__int64 __fastcall qcom_llcc_edac_probe(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v5; // w20
  unsigned int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 *v9; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w8
  unsigned int v13; // w19

  v1 = a1[20];
  v3 = *(_QWORD *)(v1 + 8);
  result = regmap_update_bits_base(v3, *(unsigned int *)(*(_QWORD *)(v1 + 32) + 36LL), 1, 1, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    result = regmap_update_bits_base(v3, *(unsigned int *)(*(_QWORD *)(v1 + 32) + 28LL), 3, 3, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      result = regmap_write(v3, *(unsigned int *)(*(_QWORD *)(v1 + 32) + 44LL), 0x1000000);
      if ( !(_DWORD)result )
      {
        result = regmap_update_bits_base(v3, *(unsigned int *)(*(_QWORD *)(v1 + 32) + 36LL), 64, 64, 0, 0, 0);
        if ( !(_DWORD)result )
        {
          result = regmap_write(v3, *(unsigned int *)(*(_QWORD *)(v1 + 32) + 60LL), 3);
          if ( !(_DWORD)result )
          {
            v5 = *(_DWORD *)(v1 + 100);
            v6 = edac_device_alloc_index();
            v7 = edac_device_alloc_ctl_info(0, "qcom-llcc", 1, "bank", v5, 1, v6);
            if ( v7 )
            {
              v8 = v7;
              v9 = a1 + 2;
              *(_QWORD *)(v8 + 192) = a1 + 2;
              v10 = a1[16];
              if ( !v10 )
                v10 = *v9;
              *(_QWORD *)(v8 + 200) = v10;
              v11 = a1[16];
              if ( !v11 )
                v11 = *v9;
              *(_QWORD *)(v8 + 208) = "llcc";
              *(_QWORD *)(v8 + 216) = v11;
              *(_DWORD *)(v8 + 36) = 1;
              if ( *(int *)(v1 + 112) < 1 || (unsigned int)devm_request_threaded_irq() )
              {
                v12 = 0;
                *(_DWORD *)(v8 + 40) = 5000;
                *(_QWORD *)(v8 + 184) = llcc_ecc_check;
              }
              else
              {
                v12 = 2;
              }
              edac_op_state = v12;
              result = edac_device_add_device(v8);
              if ( (_DWORD)result )
              {
                v13 = result;
                edac_device_free_ctl_info(v8);
                return v13;
              }
              else
              {
                a1[21] = v8;
              }
            }
            else
            {
              return 4294967284LL;
            }
          }
        }
      }
    }
  }
  return result;
}
