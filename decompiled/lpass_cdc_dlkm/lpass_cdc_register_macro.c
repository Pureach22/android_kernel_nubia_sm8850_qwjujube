__int64 __fastcall lpass_cdc_register_macro(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x9
  __int16 v13; // w10
  char *v14; // x20
  unsigned int v15; // w0
  unsigned int v16; // w20

  if ( !a1 || !a3 )
  {
    printk(&unk_D521, "lpass_cdc_register_macro");
    return 4294967274LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "qcom,lpass-cdc") )
  {
    if ( a2 > 4u || (v7 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL)) == 0 )
    {
      dev_err(a1, "%s: priv is null or invalid macro\n", "lpass_cdc_register_macro");
      return 4294967274LL;
    }
    v8 = v7 + 112LL * a2;
    *(_WORD *)(v8 + 336) = *(_WORD *)(a3 + 104);
    *(_WORD *)(v8 + 338) = *(_WORD *)(a3 + 106);
    *(_QWORD *)(v8 + 232) = *(_QWORD *)a3;
    v9 = v8 + 232;
    *(_QWORD *)(v9 + 8) = *(_QWORD *)(a3 + 8);
    *(_QWORD *)(v9 + 96) = *(_QWORD *)(a3 + 96);
    *(_WORD *)(v9 + 16) = *(_WORD *)(a3 + 16);
    *(_QWORD *)(v9 + 32) = *(_QWORD *)(a3 + 32);
    *(_QWORD *)(v9 + 48) = *(_QWORD *)(a3 + 48);
    v10 = *(_QWORD *)(a3 + 64);
    *(_QWORD *)(v9 + 24) = a1;
    *(_QWORD *)(v9 + 64) = v10;
    *(_WORD *)(v7 + 2LL * a2 + 806) = lpass_cdc_mclk_mux_tbl[2 * a2];
    if ( a2 == 3 )
    {
      v12 = 56;
      v11 = 72;
    }
    else
    {
      if ( a2 )
        goto LABEL_16;
      v11 = 88;
      *(_QWORD *)(v9 + 56) = *(_QWORD *)(a3 + 56);
      *(_QWORD *)(v9 + 80) = *(_QWORD *)(a3 + 80);
      v12 = 72;
    }
    *(_QWORD *)(v9 + v11) = *(_QWORD *)(a3 + v11);
    *(_QWORD *)(v9 + v12) = *(_QWORD *)(a3 + v12);
LABEL_16:
    mutex_lock(v7 + 24);
    v13 = *(_WORD *)(v7 + 802);
    *(_WORD *)(v7 + 800) += *(_WORD *)(a3 + 16);
    *(_WORD *)(v7 + 802) = v13 + 1;
    *(_BYTE *)(v7 + 217 + a2) = 1;
    dev_info(a1, "%s: register macro successful:%d\n", "lpass_cdc_register_macro", a2);
    if ( *(unsigned __int16 *)(v7 + 802) == *(unsigned __int16 *)(v7 + 804) )
    {
      v14 = *(char **)(v7 + 792);
      if ( !v14 )
      {
        v14 = (char *)devm_kmalloc(*(_QWORD *)v7, 208LL * *(unsigned __int16 *)(v7 + 800), 3520);
        *(_QWORD *)(v7 + 792) = v14;
        if ( !v14 )
        {
          dev_err(a1, "%s: copy_dais failed\n", "lpass_cdc_register_macro");
          mutex_unlock(v7 + 24);
          return 4294967284LL;
        }
      }
      if ( *(_QWORD *)(v7 + 264) )
      {
        memcpy(v14, *(const void **)(v7 + 264), 208LL * *(unsigned __int16 *)(v7 + 248));
        v14 += 208 * *(unsigned __int16 *)(v7 + 248);
      }
      if ( *(_QWORD *)(v7 + 376) )
      {
        memcpy(v14, *(const void **)(v7 + 376), 208LL * *(unsigned __int16 *)(v7 + 360));
        v14 += 208 * *(unsigned __int16 *)(v7 + 360);
      }
      if ( *(_QWORD *)(v7 + 488) )
      {
        memcpy(v14, *(const void **)(v7 + 488), 208LL * *(unsigned __int16 *)(v7 + 472));
        v14 += 208 * *(unsigned __int16 *)(v7 + 472);
      }
      if ( *(_QWORD *)(v7 + 600) )
      {
        memcpy(v14, *(const void **)(v7 + 600), 208LL * *(unsigned __int16 *)(v7 + 584));
        v14 += 208 * *(unsigned __int16 *)(v7 + 584);
      }
      if ( *(_QWORD *)(v7 + 712) )
        memcpy(v14, *(const void **)(v7 + 712), 208LL * *(unsigned __int16 *)(v7 + 696));
      if ( !*(_BYTE *)(v7 + 217) )
      {
        word_418 = 2;
        *(_WORD *)(v7 + 810) = 2;
        word_41C = 3;
        *(_WORD *)(v7 + 812) = 3;
      }
      v15 = snd_soc_register_component(
              *(_QWORD *)(a1 + 96),
              &lpass_cdc,
              *(_QWORD *)(v7 + 792),
              *(unsigned __int16 *)(v7 + 800));
      if ( (v15 & 0x80000000) != 0 )
      {
        v16 = v15;
        dev_err(a1, "%s: register codec failed\n", "lpass_cdc_register_macro");
        mutex_unlock(v7 + 24);
        return v16;
      }
    }
    mutex_unlock(v7 + 24);
    return 0;
  }
  dev_err(a1, "%s: child device for macro:%d not added yet\n", "lpass_cdc_register_macro", a2);
  return 4294967274LL;
}
