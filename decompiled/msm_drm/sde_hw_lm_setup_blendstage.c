__int64 __fastcall sde_hw_lm_setup_blendstage(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v8; // x22
  __int64 v9; // x8
  unsigned __int64 v10; // x24
  __int64 v11; // x19
  __int64 v12; // x2
  __int64 v13; // x8
  __int64 i; // x8
  int v15; // w12
  int v16; // w10
  __int64 v17; // x10
  unsigned int v18; // w9
  unsigned int v19; // w10
  __int64 v21; // x8
  int v22; // w9
  int v23; // w10
  __int64 v24; // [xsp+8h] [xbp-18h]
  _QWORD v25[2]; // [xsp+10h] [xbp-10h]

  result = 4294967274LL;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( (unsigned int)(a2 - 13) >= 0xFFFFFFF4 )
    {
      v5 = *(_QWORD *)(a1 + 40);
      v6 = *(unsigned int *)(*(_QWORD *)(v5 + 48) + 4LL);
      if ( (int)v6 >= 1 )
      {
        if ( (*(_QWORD *)(v5 + 32) & 4LL) != 0 )
          v8 = 2;
        else
          v8 = 1;
        if ( !a3 )
          sde_reg_write(a1, 20, 49344, "LM_BG_SRC_SEL_V1");
        v9 = v6 + 1;
        v10 = 1;
        v11 = a3;
        v24 = v9;
        do
        {
          v13 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL);
          if ( v10 > *(unsigned int *)(v13 + 4) )
          {
            result = 4294967274LL;
            goto LABEL_35;
          }
          if ( v10 == 13 )
            goto LABEL_36;
          result = *(unsigned int *)(v13 + 4 * v10 + 4);
          if ( (result & 0x80000000) != 0 )
            goto LABEL_35;
          v25[0] = 0;
          if ( a3 )
          {
            if ( v10 == 12 )
LABEL_36:
              __break(0x5512u);
            for ( i = 0; i != v8; ++i )
            {
              v17 = v11 + 4 * i;
              v18 = *(_DWORD *)(v17 + 8);
              v19 = *(_DWORD *)(v17 + 104);
              if ( v18 - 15 < 0xFFFFFFF2 || v19 > 2 )
              {
                v16 = 49344;
              }
              else
              {
                if ( v18 <= 8 )
                  v15 = 15;
                else
                  v15 = 7;
                v16 = ((v18 < 9) << 6) | (16 * (v19 > 1)) | (v15 + v18) & 0xF;
              }
              *((_DWORD *)v25 + i) = v16;
            }
            v21 = 0;
            v12 = 49344;
            do
            {
              v22 = *((_DWORD *)v25 + v21);
              if ( v22 != 49344 )
              {
                v23 = 8 * *(_DWORD *)(v11 + 4 * v21 + 200);
                v12 = (unsigned int)v12 & ~(255 << v23) | (v22 << v23);
              }
              ++v21;
            }
            while ( v8 != v21 );
          }
          else
          {
            v12 = 49344;
          }
          sde_reg_write(a1, (unsigned int)(result + 4), v12, "LM_BLEND0_FG_SRC_SEL_V1 + stage_off");
          ++v10;
          v11 += 8;
        }
        while ( v10 != v24 );
        result = 0;
      }
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
