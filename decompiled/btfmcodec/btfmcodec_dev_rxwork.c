__int64 __fastcall btfmcodec_dev_rxwork(_BYTE *a1)
{
  __int64 v2; // x26
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v5; // x23
  int v6; // w24
  int v7; // w28
  int v8; // w2
  char v9; // w8
  int v10; // w2
  char v11; // w8
  int v12; // w2
  char v13; // w8
  unsigned int v14; // w2
  int v15; // w2
  char v16; // w8
  int v17; // w2
  char v18; // w8
  void *v19; // x0
  void *v20; // x0
  void *v21; // x0
  void *v22; // x0
  void *v23; // x0
  void *v24; // x0
  void *v25; // x0
  void *v26; // x0
  void *v27; // x0
  int v28; // [xsp+Ch] [xbp-4h]

  v2 = btfmcodec;
  if ( (unsigned __int8)log_lvl >= 4u )
    printk(&unk_C70A, "btfmcodec_dev_rxwork");
  result = skb_dequeue(a1 - 48);
  if ( result )
  {
    v4 = result;
    v5 = 0;
    v28 = 0;
    do
    {
      v6 = **(_DWORD **)(v4 + 224);
      skb_pull(v4, 4);
      v7 = **(_DWORD **)(v4 + 224);
      skb_pull(v4, 4);
      if ( v6 == 1342177280 )
      {
        if ( (unsigned __int8)log_lvl >= 4u )
        {
          printk(&unk_C0E4, "btfmcodec_dev_rxwork");
          if ( v7 == 1 )
          {
LABEL_10:
            a1[379] = 0;
            btfmcodec_enqueue_transport((__int64)(a1 - 368), **(_BYTE **)(v4 + 224));
            if ( **(_BYTE **)(v4 + 224) == 3
              && (unsigned int)btfmcodec_get_current_transport(v2 + 912) == 1
              && (unsigned int)btfmcodec_get_prev_transport(v2 + 912) == 4 )
            {
              if ( (unsigned __int8)log_lvl <= 7u )
                v27 = &unk_D7B0;
              else
                v27 = &unk_DC77;
              printk(v27, "btfmcodec_dev_rxwork");
              a1[382] = 2;
              _wake_up(a1 + 328, 1, 1, 0);
              v5 = 6;
            }
            else
            {
              v5 = 0;
            }
            queue_work_on(32, *((_QWORD *)a1 - 7), a1 + 64);
            goto LABEL_6;
          }
        }
        else if ( v7 == 1 )
        {
          goto LABEL_10;
        }
        printk(&unk_C1AC, "btfmcodec_dev_rxwork");
        v5 = 0;
      }
      else
      {
        if ( v6 > 1476395011 )
        {
          switch ( v6 )
          {
            case 1476395012:
              if ( v7 == 1 )
              {
                v14 = **(unsigned __int8 **)(v4 + 224);
                log_lvl = **(_BYTE **)(v4 + 224);
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v14 = (unsigned __int8)log_lvl;
              }
              if ( v14 <= 7 )
                v20 = &unk_D1AE;
              else
                v20 = &unk_DB59;
              printk(v20, "btfmcodec_dev_rxwork");
              _wake_up(&a1[24 * v5 + 184], 1, 1, 0);
              goto LABEL_6;
            case 1476395015:
              if ( v7 == 2 )
              {
                v17 = *(unsigned __int8 *)(*(_QWORD *)(v4 + 224) + 1LL);
                if ( *(_BYTE *)(*(_QWORD *)(v4 + 224) + 1LL) )
                  v18 = 2;
                else
                  v18 = 1;
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v17 = v28;
                v18 = 2;
              }
              a1[382] = v18;
              v28 = v17;
              if ( (unsigned __int8)log_lvl <= 7u )
                v26 = &unk_D97A;
              else
                v26 = &unk_DDE7;
              printk(v26, "btfmcodec_dev_rxwork");
              _wake_up(a1 + 328, 1, 1, 0);
              v5 = 6;
              goto LABEL_6;
            case 1476395017:
              if ( v7 == 1 )
              {
                v10 = **(unsigned __int8 **)(v4 + 224);
                if ( **(_BYTE **)(v4 + 224) )
                  v11 = 2;
                else
                  v11 = 1;
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v10 = v28;
                v11 = 2;
              }
              a1[383] = v11;
              v28 = v10;
              if ( (unsigned __int8)log_lvl <= 7u )
                v22 = &unk_DB8C;
              else
                v22 = &unk_CEA6;
              printk(v22, "btfmcodec_dev_rxwork");
              _wake_up(a1 + 352, 1, 1, 0);
              v5 = 7;
              goto LABEL_6;
          }
        }
        else
        {
          switch ( v6 )
          {
            case 1342177283:
              if ( v7 == 2 )
              {
                v12 = *(unsigned __int8 *)(*(_QWORD *)(v4 + 224) + 1LL);
                if ( *(_BYTE *)(*(_QWORD *)(v4 + 224) + 1LL) )
                  v13 = 2;
                else
                  v13 = 1;
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v12 = v28;
                v13 = 2;
              }
              a1[377] = v13;
              v28 = v12;
              if ( (unsigned __int8)log_lvl <= 7u )
                v19 = &unk_D357;
              else
                v19 = &unk_C81A;
              printk(v19, "btfmcodec_dev_rxwork");
              _wake_up(a1 + 208, 1, 1, 0);
              v5 = 1;
              goto LABEL_6;
            case 1342177285:
              if ( v7 == 2 )
              {
                v15 = *(unsigned __int8 *)(*(_QWORD *)(v4 + 224) + 1LL);
                if ( *(_BYTE *)(*(_QWORD *)(v4 + 224) + 1LL) )
                  v16 = 2;
                else
                  v16 = 1;
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v15 = v28;
                v16 = 2;
              }
              a1[378] = v16;
              v28 = v15;
              if ( (unsigned __int8)log_lvl <= 7u )
                v23 = &unk_C8D0;
              else
                v23 = &unk_CB06;
              printk(v23, "btfmcodec_dev_rxwork");
              _wake_up(a1 + 232, 1, 1, 0);
              if ( (unsigned __int8)log_lvl <= 7u )
                v24 = &unk_CE43;
              else
                v24 = &unk_BF99;
              printk(v24, "btfmcodec_dev_rxwork");
              cancel_work_sync(a1 + 64);
              if ( (unsigned __int8)log_lvl < 8u )
                v25 = &unk_CB41;
              else
                v25 = &unk_C030;
              printk(v25, "btfmcodec_dev_rxwork");
              v5 = 2;
              goto LABEL_6;
            case 1476395009:
              if ( v7 == 1 )
              {
                v8 = **(unsigned __int8 **)(v4 + 224);
                if ( **(_BYTE **)(v4 + 224) )
                  v9 = 2;
                else
                  v9 = 1;
              }
              else
              {
                printk(&unk_C1AC, "btfmcodec_dev_rxwork");
                v8 = v28;
                v9 = 2;
              }
              a1[379] = v9;
              v28 = v8;
              if ( (unsigned __int8)log_lvl <= 7u )
                v21 = &unk_CE72;
              else
                v21 = &unk_D9B1;
              printk(v21, "btfmcodec_dev_rxwork");
              _wake_up(a1 + 256, 1, 1, 0);
              v5 = 3;
              goto LABEL_6;
          }
        }
        printk(&unk_D38B, "btfmcodec_dev_rxwork");
      }
LABEL_6:
      sk_skb_reason_drop(0, v4, 2);
      result = skb_dequeue(a1 - 48);
      v4 = result;
    }
    while ( result );
  }
  if ( (unsigned __int8)log_lvl >= 4u )
    return printk(&unk_D168, "btfmcodec_dev_rxwork");
  return result;
}
