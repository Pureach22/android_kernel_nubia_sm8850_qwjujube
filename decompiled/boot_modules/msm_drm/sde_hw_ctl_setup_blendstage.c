__int64 __fastcall sde_hw_ctl_setup_blendstage(__int64 result, int a2, unsigned int *a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x10
  unsigned __int64 v8; // x8
  unsigned int *v9; // x14
  __int64 v10; // x11
  unsigned __int64 v11; // x15
  unsigned int *v12; // x16
  __int64 v13; // x17
  __int64 v14; // x4
  unsigned int v15; // w5
  __int64 v17; // x4
  unsigned __int64 v18; // x4
  unsigned int *v19; // x5
  int v20; // w6
  __int64 v21; // x7
  unsigned int v22; // w6
  unsigned int v23; // w8
  unsigned int v24; // w22
  unsigned int v25; // w20
  unsigned int v26; // w21
  unsigned int v27; // w19
  int v28; // w24
  __int64 v29; // x23
  __int64 v30; // x1
  __int64 v31; // [xsp+0h] [xbp-20h]
  __int64 v32; // [xsp+8h] [xbp-18h]
  unsigned int v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v31 = 0;
  v32 = 0;
  if ( result )
  {
    v4 = *(unsigned int *)(result + 80);
    if ( (int)v4 >= 1 )
    {
      v5 = *(_QWORD *)(result + 88);
      v6 = v5 + 48;
      while ( *(_DWORD *)(v6 - 32) != a2 )
      {
        --v4;
        v6 += 96;
        if ( !v4 )
          goto LABEL_46;
      }
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 4LL);
      if ( (v7 & 0x80000000) == 0 )
      {
        if ( a3 )
        {
          v8 = 0;
          v9 = a3;
          if ( (*(_QWORD *)(v5 + 32) & 4LL) != 0 )
            v10 = 2;
          else
            v10 = 1;
LABEL_13:
          if ( v8 == 12 )
            __break(0x5512u);
          v11 = v8 + 1;
          v12 = v9;
          v13 = v10;
          while ( 1 )
          {
            v14 = *v12;
            v15 = v12[24];
            if ( (unsigned int)(v14 - 15) >= 0xFFFFFFF2 && v15 <= 2 )
            {
              v17 = 32 * v14;
              if ( v15 <= 1 )
                v15 = 1;
              v18 = v17 + 16LL * (v15 - 1);
              if ( (v18 | 8) > 0x1E0 )
              {
LABEL_30:
                __break(1u);
LABEL_31:
                v23 = v31;
                v24 = HIDWORD(v31);
                v26 = v32;
                v25 = HIDWORD(v32);
                v27 = v33;
                if ( (a4 & 1) != 0 )
                {
LABEL_42:
                  v28 = 4 * a2;
                  v29 = result;
                  if ( a2 == 6 )
                    v30 = 36;
                  else
                    v30 = (unsigned int)(4 * a2 - 4);
                  sde_reg_write(result, v30, v23, "CTL_LAYER(lm)");
                  sde_reg_write(v29, (unsigned int)(v28 + 60), v24, "CTL_LAYER_EXT(lm)");
                  sde_reg_write(v29, (unsigned int)(v28 + 108), v26, "CTL_LAYER_EXT2(lm)");
                  sde_reg_write(v29, (unsigned int)(v28 + 156), v25, "CTL_LAYER_EXT3(lm)");
                  result = sde_reg_write(v29, (unsigned int)(v28 + 180), v27, "CTL_LAYER_EXT4(lm)");
                  goto LABEL_46;
                }
LABEL_34:
                if ( !v23 && !v24 && !v26 && !v25 && !v27 || a3 && !*a3 )
                  v23 |= 0x1000000u;
                goto LABEL_42;
              }
              v19 = (unsigned int *)((char *)&sspp_reg_cfg_tbl + v18);
              v20 = *(_DWORD *)((char *)&sspp_reg_cfg_tbl + v18 + 8);
              if ( v20 )
              {
                if ( (v18 | 4) > 0x1E0 )
                  goto LABEL_30;
                if ( v18 > 0x1DF )
                  goto LABEL_30;
                v21 = *v19;
                if ( (unsigned int)v21 > 4 )
                  goto LABEL_30;
                v22 = v11 & ~(unsigned int)(-1LL << v20);
                *((_DWORD *)&v31 + v21) |= v22 << v19[1];
                if ( v8 >= v22 )
                {
                  if ( (v18 | 0xC) > 0x1E0 )
                    goto LABEL_30;
                  HIDWORD(v31) |= v19[3];
                }
              }
            }
            --v13;
            ++v12;
            if ( !v13 )
            {
              v9 += 2;
              ++v8;
              if ( v11 == v7 + 1 )
                goto LABEL_31;
              goto LABEL_13;
            }
          }
        }
        v27 = 0;
        v25 = 0;
        v26 = 0;
        v24 = 0;
        v23 = 0;
        if ( (a4 & 1) != 0 )
          goto LABEL_42;
        goto LABEL_34;
      }
    }
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
