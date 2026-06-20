__int64 __fastcall gsi_deregister_device(__int64 a1, char a2)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  unsigned int v4; // w19
  __int64 bit_map_array_size; // x0
  int v6; // w20
  unsigned int i; // w21
  unsigned int v8; // w19
  __int64 v9; // x0
  int v10; // w20
  unsigned int j; // w21
  unsigned int v12; // w19
  int v13; // w0
  int v14; // w20
  unsigned int k; // w21
  unsigned int v16; // w19
  unsigned int v17; // w19
  unsigned int v18; // w19
  unsigned int v19; // w19
  __int64 v20; // x2
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 result; // x0

  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_deregister_device", 1841);
    return 4294967288LL;
  }
  if ( (*(_BYTE *)(gsi_ctx + 176) & 1) == 0 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d no client registered\n", "gsi_deregister_device", 1846);
    return 4294967290LL;
  }
  if ( gsi_ctx != a1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
      "gsi_deregister_device",
      1852,
      a1,
      (const void *)gsi_ctx);
    return 4294967290LL;
  }
  if ( (a2 & 1) != 0 )
    goto LABEL_7;
  if ( *(_DWORD *)(gsi_ctx + 28580) )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d cannot deregister %u channels are still connected\n",
      "gsi_deregister_device",
      1858,
      *(_DWORD *)(gsi_ctx + 28580));
    return 4294967289LL;
  }
  if ( *(_DWORD *)(gsi_ctx + 28584) )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d cannot deregister %u events are still connected\n",
      "gsi_deregister_device",
      1864,
      *(_DWORD *)(gsi_ctx + 28584));
    return 4294967289LL;
  }
LABEL_7:
  v2 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_read_reg_nk(0, v2, 0);
  v3 = gsihal_write_reg_nk(0, v2, 0);
  v4 = *(_DWORD *)(gsi_ctx + 20);
  if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
  {
    gsihal_read_reg_nk(1, v4, 0);
    gsihal_write_reg_nk(1, v4, 0);
    v16 = *(_DWORD *)(gsi_ctx + 20);
    gsihal_read_reg_nk(2, v16, 0);
    gsihal_write_reg_nk(2, v16, 0);
    v17 = *(_DWORD *)(gsi_ctx + 20);
    gsihal_read_reg_nk(3, v17, 0);
    gsihal_write_reg_nk(3, v17, 0);
  }
  else
  {
    bit_map_array_size = gsihal_get_bit_map_array_size(v3);
    if ( (_DWORD)bit_map_array_size )
    {
      v6 = bit_map_array_size;
      for ( i = 0; i != v6; ++i )
      {
        gsihal_read_reg_nk(127, v4, i);
        bit_map_array_size = gsihal_write_reg_nk(127, v4, i);
      }
    }
    v8 = *(_DWORD *)(gsi_ctx + 20);
    v9 = gsihal_get_bit_map_array_size(bit_map_array_size);
    if ( (_DWORD)v9 )
    {
      v10 = v9;
      for ( j = 0; j != v10; ++j )
      {
        gsihal_read_reg_nk(128, v8, j);
        v9 = gsihal_write_reg_nk(128, v8, j);
      }
    }
    v12 = *(_DWORD *)(gsi_ctx + 20);
    v13 = gsihal_get_bit_map_array_size(v9);
    if ( v13 )
    {
      v14 = v13;
      for ( k = 0; k != v14; ++k )
      {
        gsihal_read_reg_nk(132, v12, k);
        gsihal_write_reg_nk(132, v12, k);
      }
    }
  }
  v18 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_read_reg_nk(4, v18, 0);
  gsihal_write_reg_nk(4, v18, 0);
  v19 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_read_reg_nk(5, v19, 0);
  gsihal_write_reg_nk(5, v19, 0);
  v20 = gsi_ctx;
  if ( *(_DWORD *)(gsi_ctx + 28680) )
  {
    platform_device_msi_free_irqs_all(*(_QWORD *)(gsi_ctx + 8));
    v20 = gsi_ctx;
  }
  v21 = devm_free_irq(*(_QWORD *)(v20 + 8), *(unsigned int *)(v20 + 40));
  gsihal_destroy(v21);
  if ( gsi_ctx )
  {
    v22 = *(_QWORD *)(gsi_ctx + 8);
    if ( *(_QWORD *)gsi_ctx )
    {
      devm_iounmap(v22);
      *(_QWORD *)gsi_ctx = 0;
    }
    else
    {
      dev_err(v22, "%s:%d access to GSI HW has not been mapped\n", "gsi_unmap_base", 1334);
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_unmap_base", 1329);
  }
  result = 0;
  *(_BYTE *)(gsi_ctx + 176) = 0;
  return result;
}
