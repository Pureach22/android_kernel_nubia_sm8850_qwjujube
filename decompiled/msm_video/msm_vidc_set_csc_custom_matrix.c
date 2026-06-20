__int64 __fastcall msm_vidc_set_csc_custom_matrix(__int64 result, unsigned int a2)
{
  __int64 v2; // x4
  _QWORD *v3; // x20
  int *v4; // x9
  __int64 v5; // x19
  int *v6; // x9
  __int64 *v7; // x9
  __int64 v8; // [xsp+8h] [xbp-68h] BYREF
  __int64 v9; // [xsp+10h] [xbp-60h]
  __int64 v10; // [xsp+18h] [xbp-58h]
  __int64 v11; // [xsp+20h] [xbp-50h]
  __int64 v12; // [xsp+28h] [xbp-48h] BYREF
  int v13; // [xsp+30h] [xbp-40h]
  int v14; // [xsp+34h] [xbp-3Ch]
  int v15; // [xsp+38h] [xbp-38h]
  __int64 v16; // [xsp+3Ch] [xbp-34h]
  int v17; // [xsp+44h] [xbp-2Ch]
  int v18; // [xsp+48h] [xbp-28h]
  int v19; // [xsp+4Ch] [xbp-24h]
  int v20; // [xsp+50h] [xbp-20h]
  int v21; // [xsp+54h] [xbp-1Ch]
  int v22; // [xsp+58h] [xbp-18h]
  int v23; // [xsp+5Ch] [xbp-14h]
  int v24; // [xsp+60h] [xbp-10h]
  int v25; // [xsp+64h] [xbp-Ch]
  __int64 v26; // [xsp+68h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  v2 = *(_QWORD *)(result + 168LL * a2 + 4352);
  if ( v2 && *(_QWORD *)(result + 25184) )
  {
    v3 = *(_QWORD **)(*(_QWORD *)(result + 320) + 3912LL);
    v16 = 0x300000003LL;
    v4 = (int *)v3[36];
    v5 = result;
    v17 = *v4;
    v18 = v4[1];
    v19 = v4[2];
    v20 = v4[3];
    v21 = v4[4];
    v22 = v4[5];
    v23 = v4[6];
    v24 = v4[7];
    v25 = v4[8];
    result = ((__int64 (*)(void))msm_venc_set_csc_coeff)();
    if ( !(_DWORD)result )
    {
      v6 = (int *)v3[37];
      v12 = 0x300000001LL;
      v13 = *v6;
      v14 = v6[1];
      v15 = v6[2];
      result = msm_venc_set_csc_coeff(v5, "CSC_BIAS", 50331993, &v12, 20, 1, 3);
      if ( !(_DWORD)result )
      {
        v7 = (__int64 *)v3[38];
        v8 = 0x600000001LL;
        v9 = *v7;
        v10 = v7[1];
        v11 = v7[2];
        result = msm_venc_set_csc_coeff(v5, "CSC_LIMIT", 50331994, &v8, 32, 1, 6);
      }
    }
  }
  else if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_88AC0, "high", result + 340, "msm_vidc_set_csc_custom_matrix", v2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
