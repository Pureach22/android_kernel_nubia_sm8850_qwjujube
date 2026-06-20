__int64 __fastcall loopback_create_response_pkt(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x19
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x21
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x8
  int v14; // w9
  int v16; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+Ch] [xbp-24h]
  int v18; // [xsp+14h] [xbp-1Ch]
  __int64 v19; // [xsp+18h] [xbp-18h] BYREF
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v3 = v2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v16 = 0;
  v8 = _kmalloc_cache_noprof(devm_free_irq, 3520, 40);
  if ( !v8 )
  {
    printk(&unk_19B17, "loopback_create_response_pkt", 581, v3);
    goto LABEL_12;
  }
  *(_DWORD *)(v8 + 24) = 1;
  if ( (unsigned int)get_device_tx_buffer(a1, 3u, v8, v6, v7)
    || (v11 = *(_QWORD *)v8) == 0
    || (v12 = *(_QWORD *)(v8 + 16)) == 0 )
  {
    printk(&unk_1DF4E, "loopback_create_response_pkt", 590, v3);
    goto LABEL_10;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1E6B4, "loopback_create_response_pkt", 597, 3);
    v11 = *(_QWORD *)v8;
    v12 = *(_QWORD *)(v8 + 16);
  }
  v13 = *(_QWORD *)(a2 + 4);
  v14 = *(_DWORD *)(a2 + 12);
  v19 = v11;
  LODWORD(v20) = v12;
  v17 = v13;
  v18 = v14;
  if ( (unsigned int)hfi_create_header(&v19, &v16, v9, v10, v11) )
  {
    printk(&unk_19261, "loopback_create_response_pkt", 609, v3);
LABEL_10:
    v8 = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v8;
}
