__int64 __fastcall btl_set_temp_thresholds(_QWORD *a1, int *a2)
{
  int v3; // w8
  int v4; // w10
  int v6; // w11
  int v7; // w10
  int v8; // w11
  int v9; // w10
  int v10; // w11
  int v11; // w10
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 v16; // x10
  int *v17; // x9
  __int64 v18; // x24
  int v19; // w8
  __int64 v20; // x11
  int *v21; // x12
  int v22; // t1
  int v23; // w9
  __int64 v24; // x0
  int *v25; // x15
  int v26; // w10
  int v27; // w13
  int v28; // w11
  int v29; // w13
  bool v30; // zf
  char v31; // w8
  char v32[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v33[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int16 v34[2]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v35[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v32[0] = 1;
  if ( v3 != -40000 )
  {
    dev_err(*a1, "Error, Temperature threshold should start with %d\n", -40000);
    goto LABEL_41;
  }
  v4 = a2[1];
  if ( (unsigned int)(v4 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v4 <= -40000 )
    goto LABEL_40;
  v6 = a2[2];
  if ( (unsigned int)(v6 - 98001) < 0xFFFDE4EF )
  {
LABEL_39:
    dev_err(*a1, "Error, Temperature threshold should be within [%d %d]\n", -40000, 98000);
LABEL_41:
    result = 4294967274LL;
    goto LABEL_42;
  }
  if ( v6 <= v4 )
  {
LABEL_40:
    dev_err(*a1, "Error, Temperature thresholds should be in increasing order\n");
    goto LABEL_41;
  }
  v7 = a2[3];
  if ( (unsigned int)(v7 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v7 <= v6 )
    goto LABEL_40;
  v8 = a2[4];
  if ( (unsigned int)(v8 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v8 <= v7 )
    goto LABEL_40;
  v9 = a2[5];
  if ( (unsigned int)(v9 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v9 <= v8 )
    goto LABEL_40;
  v10 = a2[6];
  if ( (unsigned int)(v10 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v10 <= v9 )
    goto LABEL_40;
  v11 = a2[7];
  if ( (unsigned int)(v11 - 98001) < 0xFFFDE4EF )
    goto LABEL_39;
  if ( v11 <= v10 )
    goto LABEL_40;
  v12 = a1[1];
  v33[0] = 0;
  result = nvmem_device_write(v12, 74, 1, v33);
  if ( (result & 0x80000000) == 0 )
  {
    v14 = a1[1];
    v33[0] = 1;
    result = nvmem_device_write(v14, 229, 1, v33);
    if ( (result & 0x80000000) == 0 )
    {
      result = btl_reset_temp_counts((__int64)a1);
      if ( (result & 0x80000000) == 0 )
      {
        v15 = 0;
        while ( 1 )
        {
          v16 = *((unsigned int *)a1 + 24);
          v17 = (int *)a1[11];
          v18 = v15 + 1;
          if ( (int)v16 < 1 )
          {
LABEL_25:
            v23 = *v17;
          }
          else
          {
            v19 = a2[v18];
            v20 = 0;
            v21 = v17 + 1;
            while ( 1 )
            {
              v22 = *v21;
              v21 += 2;
              if ( v22 >= v19 )
                break;
              if ( v16 == ++v20 )
              {
                v20 = *((unsigned int *)a1 + 24);
                if ( !*((_DWORD *)a1 + 24) )
                  goto LABEL_25;
                goto LABEL_27;
              }
            }
            v20 = (unsigned int)v20;
            if ( !(_DWORD)v20 )
              goto LABEL_25;
LABEL_27:
            if ( v20 == v16 )
            {
              v23 = v17[2 * v16 - 2];
            }
            else
            {
              v25 = &v17[2 * v20];
              v26 = *(v25 - 2);
              v27 = *(v25 - 1);
              v28 = v19 - v27;
              if ( v19 == v27 )
              {
                LOWORD(v23) = *(v25 - 2);
              }
              else
              {
                LOWORD(v23) = *(v25 - 2);
                if ( *v25 != v26 )
                {
                  v23 = v25[1];
                  v29 = v23 - v27;
                  if ( v29 )
                  {
                    v30 = v23 == v19;
                    LOWORD(v23) = *v25;
                    if ( !v30 )
                      v23 = (*v25 - v26) * v28 / v29 + v26;
                  }
                  else
                  {
                    LOWORD(v23) = *v25;
                  }
                }
              }
            }
          }
          v24 = a1[1];
          v34[0] = v23;
          result = nvmem_device_write(v24, (unsigned int)(88 - 2 * v15), 2, v34);
          if ( (result & 0x80000000) != 0 )
            break;
          *((_DWORD *)a1 + v15++ + 5) = a2[v18];
          if ( v18 == 7 )
          {
            if ( (*((_BYTE *)a1 + 100) & 1) == 0 )
            {
              result = nvmem_device_write(a1[1], 72, 1, v32);
              if ( (result & 0x80000000) != 0 )
                break;
              *((_BYTE *)a1 + 100) = 1;
            }
            v31 = *((_BYTE *)a1 + 80);
            v35[0] = 1;
            if ( (v31 & 2) != 0 )
            {
              result = nvmem_device_write(a1[1], 74, 1, v35);
              if ( (result & 0x80000000) == 0 )
                result = nvmem_device_write(a1[1], 229, 1, v35);
            }
            else
            {
              result = 0;
            }
            break;
          }
        }
      }
    }
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
