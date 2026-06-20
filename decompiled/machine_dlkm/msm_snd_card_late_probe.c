__int64 __fastcall msm_snd_card_late_probe(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x1
  __int64 pcm_runtime; // x0
  const char *v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x10
  __int64 v17; // x20
  __int64 v18; // x8
  int v19; // w8
  __int64 v20; // x8
  unsigned int v21; // w19
  __int128 v22; // [xsp+0h] [xbp-20h] BYREF
  int v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[98];
  if ( !v4 )
    goto LABEL_20;
  if ( !*(_DWORD *)(v4 + 96) )
  {
    v6 = a1[44];
    v23 = 0;
    v22 = 0u;
    pcm_runtime = snd_soc_get_pcm_runtime(a1, v6, a3, a4);
    if ( pcm_runtime )
    {
      if ( *(_DWORD *)(v4 + 148) == 2 )
        v9 = "wcd9378_codec";
      else
        v9 = "wcd939x_codec";
      v10 = *(_QWORD *)v9;
      v11 = *(_QWORD *)(v9 + 6);
      *(_QWORD *)&v22 = v10;
      *(_QWORD *)((char *)&v22 + 6) = v11;
      v12 = snd_soc_rtdcom_lookup(pcm_runtime, &v22);
      if ( v12 )
      {
        v14 = v12;
        v15 = _kmalloc_cache_noprof(kernel_kobj, 3520, 154);
        if ( !v15 )
        {
          result = 4294967284LL;
          goto LABEL_21;
        }
        v16 = a1[9];
        *(_WORD *)(v15 + 48) = 1700;
        v17 = v15;
        *(_BYTE *)(v15 + 65) = 8;
        *(_QWORD *)(v15 + 96) = 0x2B202B200C80064LL;
        *(_QWORD *)(v15 + 104) = 0x2B202B202B202B2LL;
        v18 = *(_QWORD *)(v16 + 744);
        qword_31B0 = v15;
        if ( of_find_property(v18, "qcom,usbss-hsj-connect-enabled", 0) )
          byte_3205 = 1;
        v19 = *(_DWORD *)(v4 + 148);
        if ( v19 == 1 )
        {
          result = wcd939x_mbhc_hs_detect(v14, &wcd_mbhc_cfg);
          if ( !(_DWORD)result )
            goto LABEL_21;
          goto LABEL_17;
        }
        if ( v19 == 2 )
        {
          result = wcd9378_mbhc_hs_detect(v14, &wcd_mbhc_cfg);
          if ( !(_DWORD)result )
            goto LABEL_21;
LABEL_17:
          v20 = *(_QWORD *)(v14 + 24);
          v21 = result;
          dev_err(v20, "%s: mbhc hs detect failed, err:%d\n", "msm_snd_card_late_probe", result);
          kfree(v17);
          result = v21;
          goto LABEL_21;
        }
      }
      else
      {
        printk(&unk_12349, "msm_snd_card_late_probe", v13);
      }
    }
    else
    {
      dev_err(a1[9], "%s: snd_soc_get_pcm_runtime for %s failed!\n", "msm_snd_card_late_probe", *(const char **)a1[44]);
    }
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
