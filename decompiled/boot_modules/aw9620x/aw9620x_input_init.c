__int64 __fastcall aw9620x_input_init(__int64 a1, _BYTE *a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x27
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 *v10; // x9
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w8
  const char *v15; // x2
  __int64 v16; // x4
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v20; // x21

  v4 = devm_kmalloc(*(_QWORD *)(a1 + 48), 384, 3520);
  *(_QWORD *)(a1 + 512) = v4;
  if ( !v4 )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] devm_kzalloc err\n", "aw9620x_input_init", 2593);
    return 0xFFFFFFFFLL;
  }
  v5 = 0;
  v6 = 16;
  while ( 1 )
  {
    v7 = snprintf((char *)(*(_QWORD *)(a1 + 512) + v6), 0x1Eu, "nubia_tgk_aw_sar%u_ch%u", *(_DWORD *)(a1 + 8), v5);
    *(_DWORD *)(*(_QWORD *)(a1 + 512) + v6 - 12) = 0;
    v8 = *(_QWORD *)(a1 + 512) + v6;
    if ( ((*(_DWORD *)(a1 + 24) >> v5) & 1) != 0 )
      break;
    *(_BYTE *)(v8 - 16) = 0;
    *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8) = 0;
LABEL_4:
    v6 += 48;
    ++v5;
    if ( v6 == 400 )
      return 0;
  }
  *(_BYTE *)(v8 - 16) = 1;
  *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8) = input_allocate_device(v7);
  v9 = *(_QWORD *)(a1 + 512) + v6;
  v10 = *(__int64 **)(v9 - 8);
  if ( !v10 )
  {
    *a2 = v5;
    if ( (_DWORD)v6 == 16 )
      return 0xFFFFFFFFLL;
    goto LABEL_16;
  }
  *v10 = v9;
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8);
  *(_QWORD *)(v11 + 40) |= 2uLL;
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8);
  *(_QWORD *)(v12 + 40) |= 1uLL;
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8);
  *(_QWORD *)(v13 + 48) |= 0x800000000000000uLL;
  v14 = *(_DWORD *)(a1 + 8);
  if ( v14 == 1 )
  {
    v15 = "[%s:%d] F8 event init\n";
    v16 = 2622;
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8);
    v18 = *(_QWORD *)(v17 + 56) | 4LL;
  }
  else
  {
    if ( v14 )
      goto LABEL_9;
    v15 = "[%s:%d] F7 event init\n";
    v16 = 2618;
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8);
    v18 = *(_QWORD *)(v17 + 56) | 2LL;
  }
  *(_QWORD *)(v17 + 56) = v18;
  dev_printk(&unk_13D4F, *(_QWORD *)(a1 + 48), v15, "aw9620x_input_init", v16);
LABEL_9:
  input_set_abs_params(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8), 25, 0xFFFFFFFFLL, 100, 0, 0);
  if ( !(unsigned int)input_register_device(*(_QWORD *)(*(_QWORD *)(a1 + 512) + v6 - 8)) )
    goto LABEL_4;
  dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] failed to register input device\n", "aw9620x_input_init", 2628);
  if ( (_DWORD)v6 == 16 )
    return 0xFFFFFFFFLL;
LABEL_16:
  v20 = 8;
  do
  {
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 512) + v20) )
      input_free_device();
    --v5;
    v20 += 48;
  }
  while ( v5 );
  return 0xFFFFFFFFLL;
}
