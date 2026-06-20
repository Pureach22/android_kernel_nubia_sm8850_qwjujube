__int64 __fastcall aw_cali_svc_run_mute(__int64 a1, unsigned __int8 a2)
{
  __int64 *v3; // x8
  __int64 v4; // x1
  void *v5; // x0
  __int64 *v6; // x8
  __int64 *v7; // x8
  __int64 v8; // x1

  if ( *(_BYTE *)(a1 + 665) )
  {
    if ( a2 == 1 )
    {
      aw882xx_dev_mute(a1, 0);
      goto LABEL_13;
    }
    if ( a2 == 255 )
    {
      aw882xx_dev_mute(a1, 1);
      goto LABEL_13;
    }
    v6 = *(__int64 **)(a1 + 112);
    v4 = v6[14];
    if ( !v4 )
      v4 = *v6;
    v5 = &unk_24B5C;
  }
  else
  {
    v3 = *(__int64 **)(a1 + 112);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    v5 = &unk_23537;
  }
  printk(v5, v4, "aw_cali_svc_run_mute");
LABEL_13:
  v7 = *(__int64 **)(a1 + 112);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  return printk(&unk_22D82, v8, "aw_cali_svc_run_mute");
}
