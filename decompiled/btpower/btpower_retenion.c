__int64 __fastcall btpower_retenion(int a1)
{
  unsigned int v2; // w21
  int v3; // w20
  __int64 result; // x0
  unsigned int v5; // w22
  int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x25
  __int64 v17; // x23
  _QWORD *v18; // x27
  int v19; // w0
  int v20; // w23
  void *v21; // x0
  __int64 v22; // x19
  bool v23; // zf
  unsigned int v24; // w19
  int v25; // w20
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x20
  __int64 v29; // x19
  __int64 v30; // x9
  __int64 v31; // x9
  unsigned int v32; // w19
  unsigned int v33; // w20

  mutex_lock(pwr_data + 224);
  v2 = *(_DWORD *)(pwr_data + 272);
  mutex_unlock(pwr_data + 224);
  mutex_lock(pwr_data + 224);
  v3 = *(_DWORD *)(pwr_data + 276);
  mutex_unlock(pwr_data + 224);
  if ( !v2 )
  {
    printk(&unk_129F4, "btpower_retenion");
    return 0xFFFFFFFFLL;
  }
  result = ((__int64 (__fastcall *)(bool, __int64))power_regulators)(a1 != 4, 2);
  if ( (result & 0x80000000) == 0 )
  {
    if ( v2 > 2 || v3 )
    {
      v5 = result;
      if ( v2 == 3 && !v3 )
      {
        if ( a1 == 4 )
          v6 = 1;
        else
          v6 = 3;
        mutex_lock(pwr_data + 224);
        v7 = pwr_data + 224;
        *(_DWORD *)(pwr_data + 276) = v6;
        mutex_unlock(v7);
        return v5;
      }
      if ( v2 == 3 && (v3 & 0xFFFFFFFD) == 1 )
      {
        v22 = *(unsigned int *)(pwr_data + 144);
        if ( (_DWORD)v22 )
        {
          printk(&unk_1241F, "platform_regulators_pwr");
          if ( (int)v22 >= 1 )
          {
            v27 = pwr_data;
            v28 = 0;
            v29 = 48 * v22;
            do
            {
              v30 = *(_QWORD *)(v27 + 80);
              result = v30 + v28;
              if ( v30 + v28 )
              {
                if ( *(_BYTE *)(v30 + v28 + 28) == 1
                  && *(_BYTE *)(v30 + v28 + 29) == 1
                  && (v31 = v30 + v28, *(_DWORD *)(v31 + 16))
                  && *(_DWORD *)(v31 + 20) )
                {
                  LODWORD(result) = vreg_configure(result, 1);
                  v27 = pwr_data;
                }
                else
                {
                  LODWORD(result) = 0;
                }
              }
              v28 += 48;
            }
            while ( v29 != v28 );
LABEL_64:
            if ( (_DWORD)result )
            {
              v32 = result;
              printk(&unk_1224B, "power_regulators");
              result = v32;
              if ( (v32 & 0x80000000) != 0 )
                return result;
            }
            goto LABEL_65;
          }
LABEL_48:
          LODWORD(result) = 0;
LABEL_65:
          v24 = result;
          mutex_lock(pwr_data + 224);
          v26 = pwr_data;
          *(_DWORD *)(pwr_data + 276) = 5;
          goto LABEL_66;
        }
      }
      else
      {
        if ( v3 != 4 )
        {
          result = (unsigned int)result;
          if ( v3 != 2 )
            return result;
        }
        v8 = *(unsigned int *)(pwr_data + 144);
        if ( (_DWORD)v8 )
        {
          printk(&unk_1241F, "platform_regulators_pwr");
          if ( (int)v8 >= 1 )
          {
            v9 = pwr_data;
            v10 = 0;
            v11 = 48 * v8;
            do
            {
              v12 = *(_QWORD *)(v9 + 80);
              result = v12 + v10;
              if ( v12 + v10 )
              {
                if ( *(_BYTE *)(v12 + v10 + 28) == 1
                  && *(_BYTE *)(v12 + v10 + 29) == 1
                  && (v13 = v12 + v10, *(_DWORD *)(v13 + 16))
                  && *(_DWORD *)(v13 + 20) )
                {
                  LODWORD(result) = vreg_configure(result, 1);
                  v9 = pwr_data;
                }
                else
                {
                  LODWORD(result) = 0;
                }
              }
              v10 += 48;
            }
            while ( v11 != v10 );
            goto LABEL_64;
          }
          goto LABEL_48;
        }
      }
      printk(&unk_12C11, "platform_regulators_pwr");
      goto LABEL_48;
    }
    v14 = *(unsigned int *)(pwr_data + 144);
    if ( !(_DWORD)v14 )
    {
      printk(&unk_12C11, "platform_regulators_pwr");
LABEL_45:
      LODWORD(result) = 0;
      goto LABEL_50;
    }
    printk(&unk_1241F, "platform_regulators_pwr");
    if ( (int)v14 < 1 )
      goto LABEL_45;
    v15 = pwr_data;
    v16 = 0;
    while ( 1 )
    {
      v17 = *(_QWORD *)(v15 + 80);
      v18 = (_QWORD *)(v17 + v16);
      if ( !(v17 + v16)
        || *(_BYTE *)(v17 + v16 + 28) != 1
        || *(_BYTE *)(v17 + v16 + 29) != 1
        || !*(_DWORD *)(v17 + v16 + 16)
        || !*(_DWORD *)(v17 + v16 + 20) )
      {
        LODWORD(result) = 0;
        goto LABEL_40;
      }
      v19 = regulator_set_voltage(*v18, 0);
      if ( v19 < 0 )
        break;
      LODWORD(result) = regulator_set_load(*v18, 0);
      if ( (result & 0x80000000) != 0 )
      {
        v20 = result;
        v21 = &unk_132AE;
        goto LABEL_44;
      }
LABEL_38:
      v15 = pwr_data;
LABEL_40:
      v16 += 48;
      if ( 48 * v14 == v16 )
      {
        if ( (_DWORD)result )
        {
          v33 = result;
          printk(&unk_1224B, "power_regulators");
          result = v33;
          if ( (v33 & 0x80000000) != 0 )
            return result;
        }
LABEL_50:
        v23 = a1 == 4;
        v24 = result;
        if ( v23 )
          v25 = 1;
        else
          v25 = 3;
        mutex_lock(pwr_data + 224);
        v26 = pwr_data;
        *(_DWORD *)(pwr_data + 276) = v25;
LABEL_66:
        mutex_unlock(v26 + 224);
        return v24;
      }
    }
    v20 = v19;
    v21 = &unk_13848;
LABEL_44:
    printk(v21, "vreg_configure");
    LODWORD(result) = v20;
    goto LABEL_38;
  }
  return result;
}
