__int64 __fastcall wsa884x_set_pbr_parameters(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x10
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x12
  __int64 v6; // x11
  __int64 v7; // x6
  __int64 v8; // x7
  __int64 v9; // x19
  __int64 v10; // x5
  __int64 v11; // x4
  __int64 v12; // x3
  __int64 v13; // x1
  __int64 v14; // x17
  __int64 v15; // x16
  __int64 v16; // x15
  __int64 v17; // x14
  __int64 v18; // x13
  __int64 v19; // x12
  int v20; // w20
  int v21; // w6
  int v22; // w7
  char *v23; // x5
  int v24; // w5
  char *v25; // x4
  int v26; // w4
  char *v27; // x3
  int v28; // w6
  char *v29; // x1
  int v30; // w3
  char *v31; // x17
  int v32; // w1
  unsigned int v33; // w24
  int v34; // w17
  char *v35; // x15
  unsigned int v36; // w25
  int v37; // w15
  char *v38; // x14
  unsigned int v39; // w26
  int v40; // w14
  char *v41; // x3
  unsigned int v42; // w27
  char *v43; // x13
  int v44; // w10
  char *v45; // x12
  unsigned int v46; // w28
  char *v47; // x13
  int v48; // w9
  unsigned int v49; // w19
  int v50; // w8
  unsigned int v51; // w20
  unsigned int v52; // w21
  unsigned int v53; // w22
  unsigned int v56; // [xsp+Ch] [xbp-14h]
  unsigned int v57; // [xsp+10h] [xbp-10h]
  unsigned int v58; // [xsp+14h] [xbp-Ch]
  unsigned int v59; // [xsp+18h] [xbp-8h]
  unsigned int v60; // [xsp+1Ch] [xbp-4h]

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v2 = *(unsigned __int8 *)(v1 + 236);
  if ( v2 < 0x13 )
  {
    v3 = *(unsigned int *)(v1 + 228);
    if ( (unsigned int)v3 <= 6 )
    {
      v4 = *(unsigned int *)(v1 + 232);
      if ( (unsigned int)v4 <= 3 )
      {
        v5 = 16 * v3;
        if ( ((16 * v3 + 112LL * (unsigned int)v2) | (unsigned __int64)(4 * v4)) <= 0x84F )
        {
          v6 = 4 * v4;
          v7 = v5 + 112LL * (unsigned int)v2;
          if ( (v7 | (unsigned __int64)(4 * v4)) <= 0x84F )
          {
            v8 = v5 + 112LL * (unsigned int)v2;
            if ( (v8 | (unsigned __int64)v6) <= 0x84F )
            {
              v9 = v5 + 112LL * (unsigned int)v2;
              if ( (v9 | (unsigned __int64)v6) <= 0x84F )
              {
                v10 = v5 + 112LL * (unsigned int)v2;
                if ( (v10 | (unsigned __int64)v6) <= 0x84F )
                {
                  v11 = v5 + 112LL * (unsigned int)v2;
                  if ( (v11 | (unsigned __int64)v6) <= 0x84F )
                  {
                    v12 = v5 + 112LL * (unsigned int)v2;
                    if ( (v12 | (unsigned __int64)v6) <= 0x84F )
                    {
                      v13 = v5 + 112LL * (unsigned int)v2;
                      if ( (v13 | (unsigned __int64)v6) <= 0x84F )
                      {
                        v14 = v5 + 112LL * (unsigned int)v2;
                        if ( (v14 | (unsigned __int64)v6) <= 0x84F )
                        {
                          v15 = v5 + 112LL * (unsigned int)v2;
                          if ( (v15 | (unsigned __int64)v6) <= 0x84F )
                          {
                            v16 = v5 + 112LL * (unsigned int)v2;
                            if ( (v16 | (unsigned __int64)v6) <= 0x84F )
                            {
                              v17 = v5 + 112LL * (unsigned int)v2;
                              if ( (v17 | (unsigned __int64)v6) <= 0x84F )
                              {
                                v18 = v5 + 112LL * (unsigned int)v2;
                                if ( (v18 | (unsigned __int64)v6) <= 0x84F )
                                {
                                  v19 = v5 + 112LL * (unsigned int)v2;
                                  if ( (v19 | (unsigned __int64)v6) <= 0x84F )
                                  {
                                    v20 = *(_DWORD *)((char *)&pbr_vth2_data[v4] + v7);
                                    v21 = *(_DWORD *)((char *)&pbr_vth3_data[v4] + v8);
                                    v22 = *(_DWORD *)((char *)&pbr_vth4_data[v4] + v9);
                                    v23 = (char *)&pbr_vth5_data + v10;
                                    if ( v20 )
                                      v60 = (255 * v20 - 38250) / 2000 + 1;
                                    else
                                      v60 = 0;
                                    v24 = *(_DWORD *)&v23[4 * v4];
                                    v25 = (char *)&pbr_vth6_data + v11;
                                    if ( v21 )
                                      v59 = (255 * v21 - 38250) / 2000 + 1;
                                    else
                                      v59 = 0;
                                    v26 = *(_DWORD *)&v25[4 * v4];
                                    v27 = (char *)&pbr_vth7_data + v12;
                                    if ( v22 )
                                      v58 = (255 * v22 - 38250) / 2000 + 1;
                                    else
                                      v58 = 0;
                                    v28 = *(_DWORD *)&v27[4 * v4];
                                    v29 = (char *)&pbr_vth8_data + v13;
                                    if ( v24 )
                                      v57 = (255 * v24 - 38250) / 2000 + 1;
                                    else
                                      v57 = 0;
                                    v30 = *(_DWORD *)&v29[4 * v4];
                                    v31 = (char *)&pbr_vth9_data + v14;
                                    if ( v26 )
                                      v56 = (255 * v26 - 38250) / 2000 + 1;
                                    else
                                      v56 = 0;
                                    v32 = *(_DWORD *)&v31[4 * v4];
                                    if ( v28 )
                                      v33 = (255 * v28 - 38250) / 2000 + 1;
                                    else
                                      v33 = 0;
                                    v34 = *(_DWORD *)((char *)&pbr_vth10_data[v4] + v15);
                                    v35 = (char *)&pbr_vth11_data + v16;
                                    if ( v30 )
                                      v36 = (255 * v30 - 38250) / 2000 + 1;
                                    else
                                      v36 = 0;
                                    v37 = *(_DWORD *)&v35[4 * v4];
                                    v38 = (char *)&pbr_vth12_data + v17;
                                    if ( v32 )
                                      v39 = (255 * v32 - 38250) / 2000 + 1;
                                    else
                                      v39 = 0;
                                    v40 = *(_DWORD *)&v38[4 * v4];
                                    v41 = (char *)&pbr_vth13_data + v18;
                                    if ( v34 )
                                      v42 = (255 * v34 - 38250) / 2000 + 1;
                                    else
                                      v42 = 0;
                                    v43 = (char *)&pbr_vth15_data + 112 * (unsigned int)v2;
                                    v44 = *(_DWORD *)&v41[4 * v4];
                                    v45 = (char *)&pbr_vth14_data + v19;
                                    if ( v37 )
                                      v46 = (255 * v37 - 38250) / 2000 + 1;
                                    else
                                      v46 = 0;
                                    v47 = &v43[16 * v3];
                                    v48 = *(_DWORD *)&v45[4 * v4];
                                    if ( v40 )
                                    {
                                      v49 = (255 * v40 - 38250) / 2000 + 1;
                                      v50 = *(_DWORD *)&v47[4 * v4];
                                      if ( v44 )
                                        goto LABEL_50;
                                    }
                                    else
                                    {
                                      v49 = 0;
                                      v50 = *(_DWORD *)&v47[4 * v4];
                                      if ( v44 )
                                      {
LABEL_50:
                                        v51 = (255 * v44 - 38250) / 2000 + 1;
                                        if ( v48 )
                                          goto LABEL_51;
                                        goto LABEL_55;
                                      }
                                    }
                                    v51 = 0;
                                    if ( v48 )
                                    {
LABEL_51:
                                      v52 = (255 * v48 - 38250) / 2000 + 1;
                                      if ( v50 )
                                      {
LABEL_52:
                                        v53 = (255 * v50 - 38250) / 2000 + 1;
LABEL_57:
                                        ((void (*)(void))snd_soc_component_write)();
                                        snd_soc_component_write(a1, 13538, v60);
                                        snd_soc_component_write(a1, 13539, v59);
                                        snd_soc_component_write(a1, 13540, v58);
                                        snd_soc_component_write(a1, 13541, v57);
                                        snd_soc_component_write(a1, 13542, v56);
                                        snd_soc_component_write(a1, 13543, v33);
                                        snd_soc_component_write(a1, 13544, v36);
                                        snd_soc_component_write(a1, 13545, v39);
                                        snd_soc_component_write(a1, 13546, v42);
                                        snd_soc_component_write(a1, 13547, v46);
                                        snd_soc_component_write(a1, 13548, v49);
                                        snd_soc_component_write(a1, 13549, v51);
                                        snd_soc_component_write(a1, 13550, v52);
                                        return snd_soc_component_write(a1, 13551, v53);
                                      }
LABEL_56:
                                      v53 = 0;
                                      goto LABEL_57;
                                    }
LABEL_55:
                                    v52 = 0;
                                    if ( v50 )
                                      goto LABEL_52;
                                    goto LABEL_56;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        __break(1u);
      }
    }
  }
  __break(0x5512u);
  return wsa884x_parse_port_params();
}
