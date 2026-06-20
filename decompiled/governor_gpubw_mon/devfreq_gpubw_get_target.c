__int64 __fastcall devfreq_gpubw_get_target(_QWORD *a1, _QWORD *a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  _DWORD *v4; // x9
  _QWORD *v7; // x1
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x13
  __int64 v11; // x14
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x10
  __int64 v15; // x13
  __int64 v16; // x14
  unsigned int v17; // w12
  int v18; // w9
  unsigned int v19; // w9
  signed int v20; // w15
  int v21; // w9
  __int64 v22; // x14
  int v23; // w13
  unsigned int v24; // w14
  bool v25; // cc
  int v27; // w10
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x9
  __int64 v30; // x10
  int v31; // w9
  int v32; // w10
  __int64 v33; // [xsp+8h] [xbp-28h] BYREF
  __int64 v34; // [xsp+10h] [xbp-20h]
  __int64 v35; // [xsp+18h] [xbp-18h]
  __int64 v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[148];
  v3 = a1[122];
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( !v2 )
    goto LABEL_7;
  a1[147] = &v33;
  v4 = *(_DWORD **)(v3 + 24);
  if ( !v4 )
  {
    result = 4294967274LL;
    goto LABEL_43;
  }
  v7 = a1 + 144;
  v8 = a1[20];
  if ( *(v4 - 1) != -517377599 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))v4)(v8, v7);
  if ( !(_DWORD)result )
  {
    v10 = v33;
    v11 = v34;
    *a2 = a1[146];
    v12 = *(_QWORD *)(v2 + 48) + a1[144];
    v13 = *(_QWORD *)(v2 + 72);
    *(_QWORD *)(v2 + 48) = v12;
    v14 = v13 + a1[145];
    v15 = *(_QWORD *)(v2 + 56) + v10;
    v16 = *(_QWORD *)(v2 + 64) + v11;
    *(_QWORD *)(v2 + 56) = v15;
    *(_QWORD *)(v2 + 64) = v16;
    *(_QWORD *)(v2 + 72) = v14;
    if ( v12 < *(unsigned int *)(v3 - 28) )
    {
LABEL_7:
      result = 0;
      goto LABEL_43;
    }
    v17 = (unsigned int)v15 / (unsigned int)v12;
    if ( (unsigned int)v15 / (unsigned int)v12 > *(_DWORD *)(v2 + 84) && *(_BYTE *)(v2 + 136) == 1 )
    {
      v18 = *(_DWORD *)(v2 + 80);
      *(_DWORD *)(v2 + 84) = v17;
      if ( v18 )
      {
        v19 = 0;
        do
        {
          *(_DWORD *)(*(_QWORD *)(v2 + 96) + 4LL * (int)v19) = *(_DWORD *)(*(_QWORD *)(v2 + 112) + 4LL * (int)v19)
                                                             * v17
                                                             / 0x64;
          *(_DWORD *)(*(_QWORD *)(v2 + 104) + 4LL * (int)v19) = *(_DWORD *)(*(_QWORD *)(v2 + 120) + 4LL * (int)v19)
                                                              * v17
                                                              / 0x64;
          ++v19;
        }
        while ( v19 < *(_DWORD *)(v2 + 80) );
      }
    }
    else
    {
      v20 = 100 * (int)v16 / (unsigned int)v15;
      if ( v36 != *a2 || (*(_BYTE *)(v2 + 156) & 1) == 0 )
        goto LABEL_27;
      if ( v20 > 95 )
      {
        v21 = 2;
        goto LABEL_35;
      }
      if ( v20 <= 80 )
      {
LABEL_27:
        v22 = 1717986919LL * (int)(100 * (((int)v16 + (int)v15) / (unsigned int)v12));
        v23 = v35 & ~((int)v35 >> 31);
        if ( v23 >= *(_DWORD *)(v2 + 80) - 1 )
          v23 = *(_DWORD *)(v2 + 80) - 1;
        v24 = (v22 >> 37) + ((unsigned __int64)v22 >> 63);
        v25 = v20 > 10 || v24 > *(_DWORD *)(*(_QWORD *)(v2 + 96) + 4LL * v23);
        if ( !v25 || (int)(100 * (int)v14 / (unsigned int)v12) <= 75 )
        {
          if ( v24 >= *(_DWORD *)(*(_QWORD *)(v2 + 104) + 4LL * v23) || (_DWORD)v35 == 0 )
            v21 = 0;
          else
            v21 = 4;
LABEL_35:
          *(_DWORD *)(v3 - 32) = v21;
          v27 = *(_DWORD *)(v2 + 88);
          if ( v27 )
          {
            v28 = ((1000000 * (unsigned __int64)(unsigned int)(*(_DWORD *)(v2 + 56) / *(_DWORD *)(v2 + 48) * v27)) >> 20)
                + 49;
            v29 = v28
                - ((unsigned int)v28
                 - 50
                 * (((unsigned int)((1000000
                                   * (unsigned __int64)(unsigned int)(*(_DWORD *)(v2 + 56) / *(_DWORD *)(v2 + 48) * v27)) >> 20)
                   + 49)
                  / 0x32));
            v30 = -16;
          }
          else
          {
            if ( !v21 )
            {
LABEL_42:
              result = 0;
              *(_QWORD *)(v2 + 64) = 0;
              *(_QWORD *)(v2 + 72) = 0;
              *(_QWORD *)(v2 + 48) = 0;
              *(_QWORD *)(v2 + 56) = 0;
              goto LABEL_43;
            }
            v31 = *(_DWORD *)(v2 + 56) / *(_DWORD *)(v2 + 48);
            v32 = devfreq_gpubw_get_target_norm_ab_max;
            if ( v31 > devfreq_gpubw_get_target_norm_ab_max )
            {
              v32 = *(_DWORD *)(v2 + 56) / *(_DWORD *)(v2 + 48);
              devfreq_gpubw_get_target_norm_ab_max = v32;
            }
            LODWORD(v29) = 100 * v31 / v32;
            v30 = -24;
            v29 = (int)v29;
          }
          *(_QWORD *)(v3 + v30) = v29;
          goto LABEL_42;
        }
      }
    }
    v21 = 1;
    goto LABEL_35;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
