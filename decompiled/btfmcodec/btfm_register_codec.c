__int64 __fastcall btfm_register_codec(__int64 a1)
{
  _QWORD *btfmcodec; // x20
  _QWORD *v3; // x23
  unsigned __int64 v4; // x0
  unsigned int v5; // w21
  unsigned __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x10
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 v11; // x13
  __int64 v12; // x12
  __int64 v13; // x12
  __int64 v14; // x15
  __int64 v15; // x16
  __int64 v16; // x12
  __int64 v17; // x15
  __int64 v18; // x16
  __int64 v19; // x14
  __int64 v20; // x2
  unsigned __int64 v21; // x12
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x24
  unsigned __int64 v31; // x9
  unsigned __int64 v34; // x9

  btfmcodec = (_QWORD *)btfm_get_btfmcodec();
  v3 = (_QWORD *)btfmcodec[122];
  btfmcodec[127] = btfmcodec_adsp_ssr_notify;
  v4 = qcom_register_ssr_notifier("lpass", btfmcodec + 127);
  btfmcodec[126] = v4;
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = 208LL * *(int *)(a1 + 96);
    v7 = _kmalloc_noprof(v6, 3520);
    while ( 1 )
    {
      btfmcodec_dai_info = v7;
      if ( !v7 )
      {
        printk(&unk_CD85, "btfm_register_codec");
        return (unsigned int)-12;
      }
      if ( *(int *)(a1 + 96) < 1 )
        break;
      v8 = *(_QWORD *)(a1 + 80);
      v9 = 0;
      v10 = 0;
      while ( (v9 & 0x8000000000000000LL) == 0 )
      {
        if ( v6 <= v9 )
          break;
        *(_QWORD *)(v7 + v9) = *(_QWORD *)v8;
        if ( (v9 & 0x8000000000000000LL) != 0 )
          break;
        if ( v6 < v9 + 8 )
          break;
        v11 = v7 + v9;
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(v8 + 8);
        v12 = *(_QWORD *)(v8 + 24);
        *(_QWORD *)(v11 + 104) = *(_QWORD *)(v8 + 16);
        *(_QWORD *)(v11 + 112) = v12;
        v13 = *(_QWORD *)(v8 + 56);
        v14 = *(_QWORD *)(v8 + 32);
        v15 = *(_QWORD *)(v8 + 40);
        *(_QWORD *)(v11 + 136) = *(_QWORD *)(v8 + 48);
        *(_QWORD *)(v11 + 144) = v13;
        *(_QWORD *)(v11 + 120) = v14;
        *(_QWORD *)(v11 + 128) = v15;
        v16 = *(_QWORD *)(v8 + 104);
        v18 = *(_QWORD *)(v8 + 80);
        v17 = *(_QWORD *)(v8 + 88);
        *(_QWORD *)(v11 + 184) = *(_QWORD *)(v8 + 96);
        *(_QWORD *)(v11 + 192) = v16;
        *(_QWORD *)(v11 + 168) = v18;
        *(_QWORD *)(v11 + 176) = v17;
        v19 = *(_QWORD *)(v8 + 72);
        *(_QWORD *)(v11 + 152) = *(_QWORD *)(v8 + 64);
        *(_QWORD *)(v11 + 160) = v19;
        if ( (__int64)(v9 + 88) < 0 || v6 < v9 + 88 )
          break;
        v20 = *(int *)(a1 + 96);
        ++v10;
        v21 = v7 + v9;
        v9 += 208LL;
        v8 += 120;
        *(_QWORD *)(v21 + 88) = &btfmcodec_dai_ops;
        if ( v10 >= v20 )
          goto LABEL_15;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &btfm_register_codec__alloc_tag;
      v6 = 208LL * *(int *)(a1 + 96);
      v7 = _kmalloc_noprof(v6, 3520);
      *(_QWORD *)(StatusReg + 80) = v24;
    }
LABEL_15:
    printk(&unk_DD1B, "btfm_register_codec");
    printk(&unk_C3B4, "btfm_register_codec");
    v5 = snd_soc_register_component(
           btfmcodec,
           &btfmcodec_codec_component,
           btfmcodec_dai_info,
           *(unsigned int *)(a1 + 96));
    printk(&unk_CD06, "btfm_register_codec");
    printk(&unk_D5AE, "btfm_register_codec");
    printk(&unk_D667, "btfm_register_codec");
    printk(&unk_C656, "btfm_register_codec");
    v3[50] = 0xFFFFFFFE00000LL;
    v3[51] = v3 + 51;
    v3[52] = v3 + 51;
    v3[53] = btfmcodec_wq_hwep_shutdown;
    v3[54] = 0xFFFFFFFE00000LL;
    v3[55] = v3 + 55;
    v3[56] = v3 + 55;
    v3[57] = btfmcodec_wq_prepare_bearer;
    v3[58] = 0xFFFFFFFE00000LL;
    v3[59] = v3 + 59;
    v3[60] = v3 + 59;
    v3[61] = btfmcodec_wq_hwep_configure;
    if ( (isCpSupported() & 1) != 0 )
    {
      if ( !strcmp((const char *)(a1 + 8), "btfmslim") )
      {
        _X8 = (unsigned __int64 *)(a1 + 104);
        __asm { PRFM            #0x11, [X8] }
        do
          v31 = __ldxr(_X8);
        while ( __stxr(v31 | 1, _X8) );
      }
      else if ( !strcmp((const char *)(a1 + 8), "btfmswr_slave") )
      {
        _X8 = (unsigned __int64 *)(a1 + 104);
        __asm { PRFM            #0x11, [X8] }
        do
          v34 = __ldxr(_X8);
        while ( __stxr(v34 | 2, _X8) );
      }
      printk(&unk_C202, "btfm_register_codec");
    }
  }
  else
  {
    v5 = v4;
    printk(&unk_D212, "btfm_register_codec");
  }
  return v5;
}
