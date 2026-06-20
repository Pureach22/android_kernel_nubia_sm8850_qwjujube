__int64 __fastcall lpass_cdc_dmic_clk_enable(__int64 a1, unsigned int a2, int a3, char a4)
{
  __int64 v5; // x9
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x10
  unsigned int v9; // w20
  _DWORD *v10; // x25
  unsigned int v11; // w21
  _DWORD *v12; // x26
  int *v13; // x27
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  int v16; // w0
  unsigned __int8 v17; // w24
  int v19; // w8
  unsigned int v20; // w25
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x9
  __int64 (*v26)(void); // x8
  int v27; // w0

  if ( a2 < 8 )
  {
    v5 = (__int64)*(&off_E328 + a2);
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
    v7 = (__int64)*(&off_E3A8 + a2);
    v8 = (__int64)*(&off_E368 + a2);
    v9 = dword_11338[a2];
    v10 = (_DWORD *)(v6 + v5);
    v11 = dword_11318[a2];
    v12 = (_DWORD *)(v6 + v8);
    if ( a3 )
      v13 = (int *)(v6 + v5);
    else
      v13 = (int *)(v6 + v8);
    if ( (a4 & 1) == 0 )
    {
      v19 = *v13 - 1;
      *v13 = v19;
      if ( *v10 + *v12 )
      {
        if ( v19 )
        {
          LOBYTE(v20) = 0;
        }
        else
        {
          v25 = 336;
          if ( a3 )
            v25 = 0;
          v26 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL) + v25 + 304);
          if ( v26 )
          {
            if ( *((_DWORD *)v26 - 1) != 1180180134 )
              __break(0x8228u);
            v27 = v26();
            if ( v27 < 0 )
              LOBYTE(v20) = 1;
            else
              LOBYTE(v20) = v27;
          }
          else
          {
            LOBYTE(v20) = 1;
          }
          if ( *(unsigned __int8 *)(v6 + v7) != (unsigned __int8)v20 )
          {
            snd_soc_component_update_bits(a1, 12436, v11, v11);
            snd_soc_component_update_bits(a1, v9, 14, 2 * (unsigned int)(unsigned __int8)v20);
            snd_soc_component_update_bits(a1, 12436, v11, 0);
          }
        }
      }
      else
      {
        snd_soc_component_update_bits(a1, v9, 1, 0);
        snd_soc_component_update_bits(a1, v9, 14, 0);
        LOBYTE(v20) = 0;
      }
      goto LABEL_27;
    }
    v14 = 336;
    if ( !a3 )
      v14 = 0;
    v15 = *(__int64 (**)(void))(v6 + v14 + 304);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != 1180180134 )
        __break(0x8228u);
      v16 = v15();
      if ( v16 < 0 )
        v17 = 1;
      else
        v17 = v16;
    }
    else
    {
      v17 = 1;
    }
    ++*v13;
    if ( *v12 + *v10 == 1 )
    {
      snd_soc_component_update_bits(a1, 12436, 128, 0);
      snd_soc_component_update_bits(a1, v9, 14, 2 * (unsigned int)v17);
      v21 = a1;
      v22 = v9;
      v23 = 1;
      v24 = 1;
    }
    else
    {
      v20 = *(unsigned __int8 *)(v6 + v7);
      if ( v20 <= v17 )
      {
LABEL_27:
        *(_BYTE *)(v6 + v7) = v20;
        return 0;
      }
      snd_soc_component_update_bits(a1, 12436, v11, v11);
      snd_soc_component_update_bits(a1, v9, 14, 2 * (unsigned int)v17);
      v21 = a1;
      v22 = 12436;
      v23 = v11;
      v24 = 0;
    }
    snd_soc_component_update_bits(v21, v22, v23, v24);
    LOBYTE(v20) = v17;
    goto LABEL_27;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_dmic_clk_enable__rs, "lpass_cdc_dmic_clk_enable") )
    dev_err(*(_QWORD *)(a1 + 24), "%s: Invalid DMIC Selection\n", "lpass_cdc_dmic_clk_enable");
  return 4294967274LL;
}
