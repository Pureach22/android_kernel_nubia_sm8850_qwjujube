__int64 __fastcall tp_edge_report_limit_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x23
  char *v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  char *v12; // x22
  int v13; // w0
  __int64 v14; // x25
  __int64 v15; // x25
  __int64 v16; // x25
  __int64 v17; // x25
  __int64 v18; // x25
  __int64 v19; // x25
  unsigned __int64 v20; // x24
  unsigned __int64 v21; // x24
  unsigned __int64 v22; // x23

  if ( *a4 )
    return 0;
  v7 = tpd_cdev;
  v9 = (char *)_kmalloc_cache_noprof(init_timer_key, 3520, 4096);
  v12 = v9;
  if ( v9 )
  {
    strcpy(v9, "#######################################");
    strcpy(
      v9 + 183,
      "jitter_timer, echo jitter_timer:100 > edge_report_limit\n"
      "click_pixel, echo click_pixel:10 > edge_report_limit\n"
      "long_press_open, echo long_press_open:1 > edge_report_limit\n"
      "long_press_timer, echo long_press_timer:500 > edge_report_limit\n"
      "pixel limit level,user setting. echo 5 > edge_report_limit\n");
    strcpy(
      v9 + 39,
      "#######################################\n"
      "\n"
      "algo_open, echo algo_open:1 > edge_report_limit\n"
      "jitter_pixel, echo jitter_pixel:10 > edge_report_limit\n");
    strcpy(
      v9 + 475,
      "long_press_pixel, echo long_press_pixel:10,10,20,20 > edge_report_limit\n"
      "\n"
      "#######################################");
    strcpy(v9 + 587, "#######################################\n\n");
    v13 = snprintf(v9 + 628, 0xD8Cu, "algo_open:%5u\n", *(unsigned __int8 *)(v7 + 27));
    v14 = v13 + 628LL + snprintf(&v12[v13 + 628], 3468LL - v13, "jitter_pixel:%5u\n", *(unsigned __int8 *)(v7 + 36));
    v15 = v14 + snprintf(&v12[v14], 4096 - v14, "jitter_timer:%5u\n", *(unsigned __int16 *)(v7 + 62));
    v16 = v15 + snprintf(&v12[v15], 4096 - v15, "click_pixel:%5u\n", *(unsigned __int8 *)(v7 + 38));
    v17 = v16 + snprintf(&v12[v16], 4096 - v16, "long_press_open:%5u\n", *(unsigned __int8 *)(v7 + 37));
    v18 = v17 + snprintf(&v12[v17], 4096 - v17, "long_press_timer:%5u\n", *(unsigned __int16 *)(v7 + 60));
    v19 = v18 + snprintf(&v12[v18], 4096 - v18, "pixel limit level:%5u\n", *(unsigned __int8 *)(v7 + 56));
    v20 = v19 + snprintf(&v12[v19], 4096 - v19, "click_pixel width:");
    if ( v20 <= 0xFFA )
    {
      v20 += snprintf(&v12[v20], 4096 - v20, "%5u", *(unsigned __int8 *)(v7 + 39));
      if ( v20 <= 0xFFA )
      {
        v20 += snprintf(&v12[v20], 4096 - v20, "%5u", *(unsigned __int8 *)(v7 + 40));
        if ( v20 <= 0xFFA )
        {
          v20 += snprintf(&v12[v20], 4096 - v20, "%5u", *(unsigned __int8 *)(v7 + 41));
          if ( v20 <= 0xFFA )
            v20 += snprintf(&v12[v20], 4096 - v20, "%5u", *(unsigned __int8 *)(v7 + 42));
        }
      }
    }
    v21 = v20 + snprintf(&v12[v20], 4096 - v20, "\n long_press_pixel:");
    if ( v21 <= 0xFFA )
    {
      v21 += snprintf(&v12[v21], 4096 - v21, "%5u", *(unsigned __int8 *)(v7 + 52));
      if ( v21 <= 0xFFA )
      {
        v21 += snprintf(&v12[v21], 4096 - v21, "%5u", *(unsigned __int8 *)(v7 + 53));
        if ( v21 <= 0xFFA )
        {
          v21 += snprintf(&v12[v21], 4096 - v21, "%5u", *(unsigned __int8 *)(v7 + 54));
          if ( v21 <= 0xFFA )
            v21 += snprintf(&v12[v21], 4096 - v21, "%5u", *(unsigned __int8 *)(v7 + 55));
        }
      }
    }
    v22 = v21 + snprintf(&v12[v21], 4096 - v21, "\n");
    simple_read_from_buffer(a2, a3, a4, v12, v22);
    kfree(v12);
    return v22;
  }
  else
  {
    printk(&unk_33404, v10, v11);
    return -12;
  }
}
