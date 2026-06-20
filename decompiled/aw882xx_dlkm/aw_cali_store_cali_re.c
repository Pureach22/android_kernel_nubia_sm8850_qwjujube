__int64 __fastcall aw_cali_store_cali_re(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w4
  __int64 *v4; // x8
  unsigned int v5; // w19
  __int64 v6; // x20
  __int64 v7; // x1
  __int64 *v8; // x8
  __int64 v9; // x1
  __int64 v10; // x19
  __int64 *v11; // x8
  __int64 v12; // x1

  v2 = *(_DWORD *)(a1 + 64);
  if ( v2 <= a2 && *(_DWORD *)(a1 + 60) >= a2 || *(_BYTE *)(a1 + 665) )
  {
    v4 = *(__int64 **)(a1 + 112);
    *(_DWORD *)(a1 + 652) = a2;
    v5 = a2;
    v6 = a1;
    v7 = v4[14];
    if ( !v7 )
      v7 = *v4;
    printk(&unk_2856C, v7, "aw_cali_store_cali_re");
    a2 = v5;
    a1 = v6;
    if ( *(_DWORD *)(v6 + 64) > v5 )
      goto LABEL_12;
  }
  else if ( v2 > a2 )
  {
    goto LABEL_12;
  }
  if ( *(_DWORD *)(a1 + 60) >= a2 )
  {
    if ( *(_BYTE *)(a1 + 665) )
      *(_BYTE *)(a1 + 664) = 1;
    return 0;
  }
LABEL_12:
  v8 = *(__int64 **)(a1 + 112);
  v9 = v8[14];
  if ( !v9 )
    v9 = *v8;
  v10 = a1;
  printk(&unk_266F3, v9, "aw_cali_store_cali_re");
  if ( *(_BYTE *)(v10 + 665) )
  {
    *(_BYTE *)(v10 + 664) = -1;
    aw882xx_dev_mute(v10, 1);
    v11 = *(__int64 **)(v10 + 112);
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    printk(&unk_22D82, v12, "aw_cali_svc_run_mute");
  }
  return 0;
}
