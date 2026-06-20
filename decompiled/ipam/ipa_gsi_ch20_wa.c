__int64 ipa_gsi_ch20_wa()
{
  __int64 v0; // x0
  unsigned int v1; // w20
  unsigned int v2; // w8
  unsigned int v3; // w0
  unsigned int v4; // w0
  unsigned int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v27; // [xsp+0h] [xbp-E0h] BYREF
  __int64 v28; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v29; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v30; // [xsp+18h] [xbp-C8h]
  __int64 v31; // [xsp+20h] [xbp-C0h]
  __int64 v32; // [xsp+28h] [xbp-B8h]
  __int64 v33; // [xsp+30h] [xbp-B0h]
  __int64 v34; // [xsp+38h] [xbp-A8h]
  __int64 v35; // [xsp+40h] [xbp-A0h]
  __int64 v36; // [xsp+48h] [xbp-98h]
  _BOOL8 v37; // [xsp+50h] [xbp-90h]
  __int64 v38; // [xsp+58h] [xbp-88h]
  __int64 v39; // [xsp+60h] [xbp-80h]
  __int64 (__fastcall *v40)(); // [xsp+68h] [xbp-78h]
  __int64 (__fastcall *v41)(); // [xsp+70h] [xbp-70h]
  __int64 v42; // [xsp+78h] [xbp-68h]
  __int64 v43; // [xsp+80h] [xbp-60h]
  __int64 v44; // [xsp+88h] [xbp-58h] BYREF
  __int64 v45; // [xsp+90h] [xbp-50h] BYREF
  __int64 v46; // [xsp+98h] [xbp-48h] BYREF
  __int64 v47; // [xsp+A0h] [xbp-40h] BYREF
  __int64 v48; // [xsp+A8h] [xbp-38h] BYREF
  __int64 v49; // [xsp+B0h] [xbp-30h] BYREF
  __int64 v50; // [xsp+B8h] [xbp-28h] BYREF
  __int64 v51; // [xsp+C0h] [xbp-20h] BYREF
  __int64 v52; // [xsp+C8h] [xbp-18h] BYREF
  _QWORD v53[2]; // [xsp+D0h] [xbp-10h] BYREF

  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v29 = 0x100000002LL;
  v30 = 0;
  v0 = *(_QWORD *)(ipa3_ctx + 34216);
  v52 = 0;
  v53[0] = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = nullptr;
  v41 = nullptr;
  v42 = 0;
  v43 = 0;
  v31 = -1;
  v32 = 0x4000000010LL;
  v36 = dma_alloc_attrs(v0, 64, &v28, 0, 0);
  v1 = 1;
  v34 = v28;
  v2 = *(_DWORD *)(ipa3_ctx + 32240);
  LOBYTE(v35) = 1;
  v40 = ipa_gsi_irq_tx_notify_cb;
  v41 = ipa_gsi_chan_err_cb;
  LOBYTE(v38) = 1;
  v37 = v2 < 0xE;
  LOBYTE(v30) = 0;
  v3 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v44);
  if ( v3 )
  {
    v16 = v3;
    v1 = 0;
LABEL_24:
    printk(&unk_3E0D6F, "ipa_gsi_ch20_wa");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d failed to alloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7472, v1, v16);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d failed to alloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7472, v1, v16);
    }
    goto LABEL_50;
  }
  LOBYTE(v30) = 1;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v45);
  if ( v4 )
    goto LABEL_23;
  v1 = 2;
  LOBYTE(v30) = 2;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v46);
  if ( v4 )
    goto LABEL_23;
  v1 = 3;
  LOBYTE(v30) = 3;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v47);
  if ( v4 )
    goto LABEL_23;
  v1 = 4;
  LOBYTE(v30) = 4;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v48);
  if ( v4 )
    goto LABEL_23;
  v1 = 5;
  LOBYTE(v30) = 5;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v49);
  if ( v4 )
    goto LABEL_23;
  v1 = 6;
  LOBYTE(v30) = 6;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v50);
  if ( v4 )
    goto LABEL_23;
  v1 = 7;
  LOBYTE(v30) = 7;
  v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v51);
  if ( v4
    || (v1 = 8, LOBYTE(v30) = 8, (v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v52)) != 0)
    || (v1 = 9, LOBYTE(v30) = 9, (v4 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), v53)) != 0) )
  {
LABEL_23:
    v16 = v4;
    goto LABEL_24;
  }
  LOBYTE(v30) = 29;
  v5 = gsi_alloc_channel(&v29, *(_QWORD *)(ipa3_ctx + 43296), &v27);
  if ( v5 )
  {
    v16 = v5;
    printk(&unk_3E0D6F, "ipa_gsi_ch20_wa");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d failed to alloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7483, 10, v16);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d failed to alloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7483, 10, v16);
    }
  }
  else
  {
    v6 = gsi_dealloc_channel(v44);
    if ( v6 )
    {
      v16 = v6;
      v1 = 0;
    }
    else
    {
      v7 = gsi_dealloc_channel(v45);
      if ( v7 )
      {
        v16 = v7;
        v1 = 1;
      }
      else
      {
        v8 = gsi_dealloc_channel(v46);
        if ( v8 )
        {
          v16 = v8;
          v1 = 2;
        }
        else
        {
          v9 = gsi_dealloc_channel(v47);
          if ( v9 )
          {
            v16 = v9;
            v1 = 3;
          }
          else
          {
            v10 = gsi_dealloc_channel(v48);
            if ( v10 )
            {
              v16 = v10;
              v1 = 4;
            }
            else
            {
              v11 = gsi_dealloc_channel(v49);
              if ( v11 )
              {
                v16 = v11;
                v1 = 5;
              }
              else
              {
                v12 = gsi_dealloc_channel(v50);
                if ( v12 )
                {
                  v16 = v12;
                  v1 = 6;
                }
                else
                {
                  v13 = gsi_dealloc_channel(v51);
                  if ( v13 )
                  {
                    v16 = v13;
                    v1 = 7;
                  }
                  else
                  {
                    v14 = gsi_dealloc_channel(v52);
                    if ( v14 )
                    {
                      v16 = v14;
                      v1 = 8;
                    }
                    else
                    {
                      v15 = gsi_dealloc_channel(v53[0]);
                      if ( !v15 )
                      {
                        v16 = 0;
                        goto LABEL_50;
                      }
                      v16 = v15;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    printk(&unk_3EEF20, "ipa_gsi_ch20_wa");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d failed to dealloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7492, v1, v16);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
        ipc_log_string(v25, "ipa %s:%d failed to dealloc channel %d err %d\n", "ipa_gsi_ch20_wa", 7492, v1, v16);
    }
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return v16;
}
