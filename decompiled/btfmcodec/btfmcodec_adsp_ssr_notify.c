__int64 __fastcall btfmcodec_adsp_ssr_notify(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  void *v3; // x0
  __int64 v5; // [xsp+Ch] [xbp-14h] BYREF
  int v6; // [xsp+14h] [xbp-Ch]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 1 )
  {
    if ( a2 == 3 )
    {
      v3 = &unk_D7DE;
    }
    else
    {
      if ( a2 != 2 )
        goto LABEL_8;
      v3 = &unk_C67B;
    }
LABEL_11:
    printk(v3, "btfmcodec_adsp_ssr_notify");
    goto LABEL_12;
  }
  if ( !a2 )
  {
    v3 = &unk_D147;
    goto LABEL_11;
  }
  if ( a2 != 1 )
  {
LABEL_8:
    printk(&unk_C119, "btfmcodec_adsp_ssr_notify");
    goto LABEL_12;
  }
  v2 = *(_QWORD *)(a1 - 40);
  printk(&unk_C9CF, "btfmcodec_adsp_ssr_notify");
  v6 = 1;
  v5 = 0x458000003LL;
  btfmcodec_dev_enqueue_pkt(v2, &v5, 0xCu);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return 0;
}
