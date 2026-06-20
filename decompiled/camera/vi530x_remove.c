__int64 __fastcall vi530x_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x8
  unsigned __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  v1 = *(_QWORD *)(a1 + 184);
  v3 = *(_QWORD *)(v1 + 104);
  if ( v3 )
  {
    sysfs_remove_group(v3 + 560, &vi530x_attr_group);
    sysfs_remove_bin_file(*(_QWORD *)(v1 + 104) + 560LL, &vi530x_xtalk_data_attr);
    sysfs_remove_bin_file(*(_QWORD *)(v1 + 104) + 560LL, &vi530x_offset_data_attr);
    input_unregister_device(*(_QWORD *)(v1 + 104));
  }
  v4 = *(_QWORD *)(v1 + 160);
  if ( v4 <= 0xFFFFFFFFFFFFF000LL && v4 )
    misc_deregister(v1 + 112);
  v5 = *(unsigned int *)(v1 + 212);
  if ( (_DWORD)v5 )
  {
    v6 = gpio_to_desc(v5);
    gpiod_direction_output_raw(v6, 0);
    gpio_free(*(unsigned int *)(v1 + 212));
  }
  if ( *(_DWORD *)(v1 + 208) )
  {
    free_irq(*(unsigned int *)(v1 + 220), v1);
    gpio_free(*(unsigned int *)(v1 + 208));
  }
  v7 = *(unsigned int *)(v1 + 216);
  if ( (_DWORD)v7 )
  {
    v8 = gpio_to_desc(v7);
    gpiod_direction_output_raw(v8, 0);
    gpio_free(*(unsigned int *)(v1 + 216));
  }
  *(_QWORD *)(a1 + 184) = 0;
  return kfree(v1);
}
