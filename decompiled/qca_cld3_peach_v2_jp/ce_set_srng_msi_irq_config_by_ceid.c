__int64 __fastcall ce_set_srng_msi_irq_config_by_ceid(__int64 a1, unsigned __int8 a2, __int64 a3, int a4)
{
  _QWORD *v4; // x19
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w12
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x20
  _DWORD *v12; // x9
  unsigned int *v13; // x8
  unsigned int v14; // w9
  _DWORD *v15; // x9
  _QWORD v16[3]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v17; // [xsp+18h] [xbp-48h]
  _DWORD v18[6]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v19; // [xsp+38h] [xbp-28h]
  __int64 v20; // [xsp+40h] [xbp-20h]
  __int64 v21; // [xsp+48h] [xbp-18h]
  __int64 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  memset(v18, 0, sizeof(v18));
  memset(v16, 0, sizeof(v16));
  if ( a2 >= 0xCu )
    __break(0x5512u);
  v4 = *(_QWORD **)(a1 + 8LL * a2 + 480);
  if ( v4 )
  {
    v5 = v4[17];
    v17 = a3;
    v18[0] = a4;
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 80);
      v18[2] = 1;
      LODWORD(v22) = 1;
    }
    else
    {
      if ( !v4[18] )
      {
        result = 16;
        goto LABEL_13;
      }
      v8 = *(unsigned __int8 *)(a1 + 3950);
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 2560) + 74392LL);
      v10 = *(_QWORD *)(v4[19] + 80LL);
      v11 = a1;
      v18[1] = *(unsigned __int16 *)(a1 + 3948);
      v18[2] = v8;
      v12 = *(_DWORD **)(v9 + 1848);
      if ( *(v12 - 1) != -117212941 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, _QWORD *))v12)(v10, v16);
      v13 = (unsigned int *)v4[18];
      a1 = v11;
      v14 = *v13;
      LODWORD(v22) = 1;
      v6 = *((_QWORD *)v13 + 10);
      *(_QWORD *)&v18[1] = 0x100000000LL;
      *(_QWORD *)&v18[3] = __PAIR64__(v18[4], v14 >> 3) | 0x1000000000000LL;
    }
    v15 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 2560) + 74392LL) + 1848LL);
    if ( *(v15 - 1) != -117212941 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD *))v15)(v6, v16);
    result = 0;
  }
  else
  {
    result = 11;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
