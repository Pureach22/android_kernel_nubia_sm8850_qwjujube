__int64 __fastcall ghost_debug_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x23
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  char *v12; // x22
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x2
  __int64 v18; // x2
  __int64 v19; // x2
  __int64 v20; // x2
  int v21; // w0
  __int64 v22; // x25
  __int64 v23; // x25
  __int64 v24; // x25
  __int64 v25; // x25
  __int64 v26; // x25
  __int64 v27; // x25
  __int64 v28; // x25
  __int64 v29; // x23

  if ( *a4 )
    return 0;
  v7 = tpd_cdev;
  v9 = _kmalloc_cache_noprof(init_timer_key, 3520, 4096);
  if ( v9 )
  {
    v12 = (char *)v9;
    printk(&unk_333B9, *(unsigned __int8 *)(v7 + 1169), v11);
    printk(&unk_35E38, *(unsigned __int8 *)(v7 + 1170), v13);
    printk(&unk_333DE, *(unsigned __int8 *)(v7 + 1171), v14);
    printk(&unk_33A77, *(unsigned __int8 *)(v7 + 1172), v15);
    printk(&unk_396F5, *(unsigned __int8 *)(v7 + 1173), v16);
    printk(&unk_38C31, *(unsigned int *)(v7 + 1176), v17);
    printk(&unk_364EF, *(unsigned int *)(v7 + 1180), v18);
    printk(&unk_31D70, *(unsigned int *)(v7 + 1184), v19);
    printk(&unk_33A9C, *(unsigned int *)(v7 + 1188), v20);
    strcpy(
      v12 + 41,
      "single_time,multi_time,single_count,multi_count,start_time,ignore_id,ignore_edge_area,ignore_corner_x,ignore_corne"
      "r_y \n"
      "echo 25,20,5,8,35,9,3201,801,801 > ghost_debug \n"
      "\n");
    strcpy(v12, "#######################################\n\n");
    strcpy(v12 + 209, "#######################################\n\n");
    v21 = snprintf(v12 + 250, 0x1000u, "ghost_check_single_time is %d\n", *(unsigned __int8 *)(v7 + 1169));
    v22 = v21
        + 250LL
        + snprintf(&v12[v21 + 250], 3846LL - v21, "ghost_check_multi_time is %d\n", *(unsigned __int8 *)(v7 + 1170));
    v23 = v22 + snprintf(&v12[v22], 4096 - v22, "ghost_check_single_count is %d\n", *(unsigned __int8 *)(v7 + 1171));
    v24 = v23 + snprintf(&v12[v23], 4096 - v23, "ghost_check_multi_count is %d\n", *(unsigned __int8 *)(v7 + 1172));
    v25 = v24 + snprintf(&v12[v24], 4096 - v24, "ghost_check_start_time is %d\n", *(unsigned __int8 *)(v7 + 1173));
    v26 = v25 + snprintf(&v12[v25], 4096 - v25, "ghost_check_ignore_id is %d\n", *(_DWORD *)(v7 + 1176));
    v27 = v26 + snprintf(&v12[v26], 4096 - v26, "ghost_check_ignore_edge_area is %d\n", *(_DWORD *)(v7 + 1180));
    v28 = v27 + snprintf(&v12[v27], 4096 - v27, "ghost_check_ignore_corner_x is %d\n", *(_DWORD *)(v7 + 1184));
    v29 = v28 + snprintf(&v12[v28], 4096 - v28, "ghost_check_ignore_corner_y is %d\n", *(_DWORD *)(v7 + 1188));
    simple_read_from_buffer(a2, a3, a4, v12, v29);
    kfree(v12);
    return v29;
  }
  else
  {
    printk(&unk_33404, v10, v11);
    return -12;
  }
}
