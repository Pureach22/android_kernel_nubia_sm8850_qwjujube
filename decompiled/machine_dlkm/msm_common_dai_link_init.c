__int64 __fastcall msm_common_dai_link_init(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x26
  __int64 v4; // x22
  __int64 v5; // x25
  __int64 v7; // x21
  char *v8; // x20
  __int64 v9; // x0
  __int64 v10; // x23
  char *v11; // x22
  unsigned int v12; // w21
  size_t v13; // x24
  char *v14; // x0
  __int64 kcontrol; // x0
  __int64 v16; // x2
  __int64 v17; // x24
  __int64 v18; // x10
  unsigned int v19; // w8
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x11
  __int64 v24; // x11
  __int64 v25; // x11
  __int64 v26; // x11
  __int64 v27; // x11
  __int64 v28; // x11
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x2
  unsigned int v32; // w0
  void *v33; // x0
  char *s1; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v36[2]; // [xsp+8h] [xbp-58h] BYREF
  const char *v37; // [xsp+18h] [xbp-48h]
  __int64 v38; // [xsp+20h] [xbp-40h]
  __int64 v39; // [xsp+28h] [xbp-38h]
  __int64 (__fastcall *v40)(__int64, __int64); // [xsp+30h] [xbp-30h]
  __int64 (__fastcall *v41)(__int64, __int64); // [xsp+38h] [xbp-28h]
  __int64 v42; // [xsp+40h] [xbp-20h]
  __int64 v43; // [xsp+48h] [xbp-18h]
  __int64 v44; // [xsp+50h] [xbp-10h]
  __int64 v45; // [xsp+58h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[2];
  v4 = *(_QWORD *)(a1[1] + 72LL);
  v5 = *(_QWORD *)(a1[193] + 8LL * *(unsigned int *)(v3 + 24));
  v41 = msm_channel_map_get;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v37 = "?";
  v38 = 0x300000000LL;
  v39 = 0;
  v40 = msm_channel_map_info;
  s1 = nullptr;
  v36[0] = 2;
  v36[1] = 0;
  if ( v5 )
  {
    v7 = *(_QWORD *)(v5 + 96);
    msm_common_get_backend_name(*(const char **)(v3 + 8), (__int64 *)&s1);
    v8 = s1;
    if ( s1 )
    {
      v9 = devm_kmalloc(v4, 72, 3520);
      if ( v9 )
      {
        v10 = v9;
        if ( strncmp(v8, "SLIM", 4u) && strncmp(v8, "CODEC_DMA", 9u) )
        {
          v11 = nullptr;
          v12 = 0;
          goto LABEL_30;
        }
        v13 = (unsigned int)strlen(*(const char **)(v3 + 8)) + 13;
        v14 = (char *)_kmalloc_noprof(v13, 3520);
        v11 = v14;
        if ( v14 )
        {
          snprintf(v14, v13, "%s %s", *(const char **)(v3 + 8), "Channel Map");
          v37 = v11;
          v44 = 0;
          v12 = snd_soc_add_component_controls(v7, v36, 1);
          kcontrol = snd_soc_card_get_kcontrol(a1[1], v11);
          if ( !kcontrol )
          {
            printk(&unk_137B4, v11, v16);
            v12 = -22;
            goto LABEL_35;
          }
          v8 = s1;
          v17 = kcontrol;
          *(_QWORD *)(v10 + 8) = v5;
          *(_DWORD *)(v10 + 4) = 1;
          if ( !strncmp(v8, "SLIM", 4u) )
          {
            *(_DWORD *)v10 = 1;
          }
          else
          {
            v18 = a1[2];
            *(_DWORD *)v10 = 2;
            v19 = *(_DWORD *)(v18 + 40);
            if ( v19 <= 8 )
            {
              *(_DWORD *)(v10 + 4) = v19;
              if ( v19 )
              {
                v20 = a1[193];
                v21 = *(unsigned int *)(v18 + 24);
                v22 = *(_QWORD *)(v20 + 8 * v21);
                if ( v22 )
                {
                  *(_QWORD *)(v10 + 8) = v22;
                  if ( v19 != 1 )
                  {
                    v23 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 1));
                    if ( v23 )
                    {
                      *(_QWORD *)(v10 + 16) = v23;
                      if ( v19 >= 3 )
                      {
                        v24 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 2));
                        if ( v24 )
                        {
                          *(_QWORD *)(v10 + 24) = v24;
                          if ( v19 != 3 )
                          {
                            v25 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 3));
                            if ( v25 )
                            {
                              *(_QWORD *)(v10 + 32) = v25;
                              if ( v19 >= 5 )
                              {
                                v26 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 4));
                                if ( v26 )
                                {
                                  *(_QWORD *)(v10 + 40) = v26;
                                  if ( v19 != 5 )
                                  {
                                    v27 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 5));
                                    if ( v27 )
                                    {
                                      *(_QWORD *)(v10 + 48) = v27;
                                      if ( v19 >= 7 )
                                      {
                                        v28 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 6));
                                        if ( v28 )
                                        {
                                          *(_QWORD *)(v10 + 56) = v28;
                                          if ( v19 == 8 )
                                          {
                                            v29 = *(_QWORD *)(v20 + 8LL * (unsigned int)(v21 + 7));
                                            if ( v29 )
                                              *(_QWORD *)(v10 + 64) = v29;
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
              }
            }
          }
          *(_QWORD *)(v17 + 128) = v10;
LABEL_30:
          if ( (kregister_pm_qos_latency_controls & 1) == 0 )
          {
            v30 = snd_soc_rtdcom_lookup(a1, "lpass-cdc");
            if ( v30 )
            {
              v32 = snd_soc_add_component_controls(v30, &card_mixer_controls, 3);
              if ( (v32 & 0x80000000) != 0 )
                printk(&unk_133F1, "msm_register_pm_qos_latency_controls", v32);
              else
                kregister_pm_qos_latency_controls = 1;
            }
            else
            {
              printk(&unk_12A17, "msm_register_pm_qos_latency_controls", v31);
            }
          }
          if ( !v11 )
          {
LABEL_36:
            if ( !v8 )
              goto LABEL_46;
            goto LABEL_45;
          }
LABEL_35:
          kfree(v11);
          v8 = s1;
          goto LABEL_36;
        }
      }
      v12 = -12;
LABEL_45:
      kfree(v8);
      goto LABEL_46;
    }
    v33 = &unk_12F29;
  }
  else
  {
    v33 = &unk_13A15;
  }
  printk(v33, "msm_common_dai_link_init", a3);
  v12 = -22;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v12;
}
