// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_1AA8D4@<X0>(unsigned int **a1@<X1>, __int64 a2@<X2>, int a3@<W6>, __int64 a4@<X8>)
{
  unsigned int *v4; // x19
  unsigned int v5; // w8
  __int64 v6; // x8
  unsigned __int64 v7; // x1
  _DWORD *v8; // x9
  unsigned __int64 v9; // x2
  unsigned __int64 v10; // x20
  __int64 result; // x0
  _QWORD v12[7]; // [xsp-38h] [xbp-38h] BYREF

  if ( !a3 )
    return sde_check_ai_scaler_v1();
  v4 = *a1;
  if ( !*a1 || *(_DWORD *)(a4 + 64) != a1[6][16] )
  {
    result = 0;
    goto LABEL_35;
  }
  v12[0] = 0;
  v12[1] = 0;
  v5 = *v4;
  if ( !*v4 )
  {
    _drm_err("Data size must be greater than 0\n");
    goto LABEL_34;
  }
  if ( v5 >= 0x1409 )
  {
    _drm_err("Data size exceeds max data size. Max - %d\t Actual - %u\n", 5128, v5);
LABEL_34:
    result = 4294967274LL;
    goto LABEL_35;
  }
  aiqe_get_common_values(a1, a2, v12);
  v6 = 2;
  v8 = v4 + 1;
  v7 = *v4;
  if ( (v12[0] & 0x200000000LL) == 0 )
    v6 = 4;
  if ( (_DWORD)v7 )
  {
    v9 = (unsigned int)(*v8 + 1);
    if ( (unsigned int)v9 < (unsigned int)v7 )
    {
      if ( (unsigned int)v9 >> 3 > 0x280 )
        goto LABEL_36;
      v9 += (unsigned int)(v8[v9] + 1);
      if ( v9 < v7 )
      {
        if ( v9 >> 3 > 0x280 )
          goto LABEL_36;
        v9 += (unsigned int)(v8[v9] + 1);
        if ( (v12[0] & 0x200000000LL) != 0 )
        {
LABEL_23:
          v10 = v9;
LABEL_24:
          _drm_err("Region count exceeds max. Max - %zu\t Actual - %zu\n", v6, v6 | 1);
          v7 = *v4;
          result = 4294967274LL;
          v9 = v10;
          goto LABEL_32;
        }
        if ( v9 < v7 )
        {
          if ( v9 >> 3 > 0x280 )
            goto LABEL_36;
          v9 += (unsigned int)(v8[v9] + 1);
          if ( v9 < v7 )
          {
            if ( v9 >> 3 > 0x280 )
              goto LABEL_36;
            v9 += (unsigned int)(v8[v9] + 1);
            if ( (v12[0] & 0x200000000LL) == 0 )
              goto LABEL_23;
            if ( v9 < v7 )
            {
              if ( v9 >> 3 > 0x280 )
                goto LABEL_36;
              v9 += (unsigned int)(v8[v9] + 1);
              if ( v9 < v7 )
              {
                if ( v9 >> 3 <= 0x280 )
                {
                  v10 = v9 + (unsigned int)(v8[v9] + 1);
                  goto LABEL_24;
                }
LABEL_36:
                __break(0x5512u);
                JUMPOUT(0x1A9F1C);
              }
            }
          }
        }
      }
    }
    result = 0;
  }
  else
  {
    result = 0;
    v9 = 0;
  }
LABEL_32:
  if ( v9 > v7 )
  {
    _drm_err("Region data exceeds reported size. Reported - %u\t Actual - %zu\n", v7, v9);
    goto LABEL_34;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
