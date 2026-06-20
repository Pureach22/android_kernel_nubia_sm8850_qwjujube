__int64 __fastcall sde_dsc_populate_dsc_private_params(__int64 a1, int a2, char a3)
{
  int v3; // w4
  unsigned int v5; // w20
  int v6; // w22
  unsigned int v7; // w21
  int v8; // w24
  int v9; // w8
  int v10; // w23
  int v11; // w24
  int v12; // w8
  int v13; // w9
  unsigned int rc_table_index; // w0
  char *v16; // x8

  if ( a1 && (v3 = *(unsigned __int16 *)(a1 + 4), *(_WORD *)(a1 + 4)) && *(_WORD *)(a1 + 6) && v3 <= a2 )
  {
    v5 = *(unsigned __int8 *)(a1 + 1);
    v6 = (a2 + v3 - 1) / v3;
    v7 = (unsigned int)((*(unsigned __int16 *)(a1 + 16) >> 4) * v3 + 7) >> 3;
    v8 = 8 * v7 * v6;
    *(_DWORD *)(a1 + 164) = dword_28DF90[(unsigned int)(*(unsigned __int16 *)(a1 + 4)
                                                      - 3
                                                      * ((1431655766 * (unsigned __int64)*(unsigned __int16 *)(a1 + 4)) >> 32))];
    v9 = *(_DWORD *)(a1 + 168);
    *(_DWORD *)(a1 + 184) = 2 << (v5 - 8);
    if ( v9 > v6 )
      v10 = 1;
    else
      v10 = v9;
    *(_DWORD *)(a1 + 156) = (int)(v7 * v6) % 3;
    if ( (a3 & 1) != 0 )
    {
      v11 = v8 + msm_get_src_bpc(*(unsigned int *)(a1 + 180), v5) - 1;
      v12 = v11 / (int)msm_get_src_bpc(*(unsigned int *)(a1 + 180), v5);
    }
    else
    {
      v12 = (v8 + 23) / 24;
    }
    *(_DWORD *)(a1 + 160) = v12;
    *(_QWORD *)(a1 + 200) = 0;
    *(_DWORD *)(a1 + 148) = v7;
    *(_DWORD *)(a1 + 152) = v7 * v10;
    v13 = (2 * (_BYTE)v7) & 6;
    *(_DWORD *)(a1 + 144) = v6 / v10;
    if ( ((2 * (_BYTE)v7) & 6) != 0 )
    {
      v13 = 8 - v13;
      *(_DWORD *)(a1 + 200) = v13;
    }
    if ( (((_BYTE)v13 + 2 * (_BYTE)v7) & 0xF) != 0 )
      *(_DWORD *)(a1 + 204) = 16 - (((_BYTE)v13 + 2 * (_BYTE)v7) & 0xF);
    if ( *(_BYTE *)(a1 + 209) == 1
      && (rc_table_index = get_rc_table_index(a1, *(unsigned __int8 *)(a1 + 136)), rc_table_index <= 0xD) )
    {
      v16 = (char *)&sde_dsc_rc_range_bpg_override_v1 + 16 * rc_table_index - rc_table_index;
      *(_BYTE *)(a1 + 60) = *v16;
      *(_BYTE *)(a1 + 63) = v16[1];
      *(_BYTE *)(a1 + 66) = v16[2];
      *(_BYTE *)(a1 + 69) = v16[3];
      *(_BYTE *)(a1 + 72) = v16[4];
      *(_BYTE *)(a1 + 75) = v16[5];
      *(_BYTE *)(a1 + 78) = v16[6];
      *(_BYTE *)(a1 + 81) = v16[7];
      *(_BYTE *)(a1 + 84) = v16[8];
      *(_BYTE *)(a1 + 87) = v16[9];
      *(_BYTE *)(a1 + 90) = v16[10];
      *(_BYTE *)(a1 + 93) = v16[11];
      *(_BYTE *)(a1 + 96) = v16[12];
      *(_BYTE *)(a1 + 99) = v16[13];
      *(_BYTE *)(a1 + 102) = v16[14];
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_23618C, "sde_dsc_populate_dsc_private_params");
    return 4294967274LL;
  }
}
