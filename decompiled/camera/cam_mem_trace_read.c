__int64 __fastcall cam_mem_trace_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v7; // x22
  unsigned __int64 v8; // x24
  const char *v9; // x3
  int v10; // w8
  unsigned __int64 v11; // x23
  size_t v12; // x1
  size_t v13; // x0
  size_t v15; // x2
  size_t v16; // x0
  int v17; // w19
  size_t v19; // x2
  unsigned __int64 StatusReg; // x23
  __int64 v21; // x24

  v7 = (const char *)vzalloc_noprof(2048);
  while ( 1 )
  {
    v8 = 2048;
    if ( mem_trace_en )
      v9 = "enabled";
    else
      v9 = "disabled";
    v10 = 2048 - scnprintf(v7, 2048, "\nHeap mem trace is %s\n\n", v9);
    v11 = v10;
    if ( (unsigned __int64)v10 >= 0x800 )
      v12 = 2048;
    else
      v12 = v10;
    v13 = strnlen(v7, v12);
    if ( v13 >= 0x800 && v13 != v11 )
    {
      v19 = v13 + 1;
LABEL_27:
      _fortify_panic(2, 2048, v19);
      goto LABEL_28;
    }
    if ( v13 >= v11 )
      goto LABEL_23;
    if ( v13 >= 0x800 )
      goto LABEL_29;
    v8 = v13 + 1214 >= v11 ? v11 - 1 : v13 + 1214;
    if ( v8 < 0x800 )
      break;
LABEL_30:
    _fortify_panic(9, 2048, v8 + 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_mem_trace_read__alloc_tag;
    v7 = (const char *)vzalloc_noprof(2048);
    *(_QWORD *)(StatusReg + 80) = v21;
  }
  if ( v13 + 1214 >= v11 )
    v15 = ~v13 + v11;
  else
    v15 = 1214;
  memcpy(
    (void *)&v7[v13],
    "Usage:\n"
    "$DEBUGFS_NODE : /sys/kernel/debug/camera/memmgr/mem_trace\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Print usage or get output info     |cat $DEBUGFS_NODE                |\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Enable the heap memory trace       |echo enable > $DEBUGFS_NODE      |\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Disable the heap memory trace      |echo disable > $DEBUGFS_NODE     |\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Get allocated memory overview      |echo 0 > $DEBUGFS_NODE           |\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Print all allocated heap mem       |echo 1 > $DEBUGFS_NODE           |\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Print threshold based sedentary mem|echo 2 $THRESHOLD > $DEBUGFS_NODE|\n"
    "+-----------------------------------+---------------------------------+\n"
    "|Print records of massive memories  |echo 3 > $DEBUGFS_NODE           |\n"
    "+-----------------------------------+---------------------------------+\n"
    "\n"
    "#For enable/disable cmds - kill camera provider to effect the cmd.\n"
    "\n",
    v15);
  v7[v8] = 0;
LABEL_23:
  v16 = strnlen(v7, 0x800u);
  if ( v16 >= 0x801 )
  {
    v19 = v16 + 1;
    goto LABEL_27;
  }
  if ( v16 == 2048 )
  {
LABEL_28:
    v13 = _fortify_panic(4, 2048, 2049);
LABEL_29:
    _fortify_panic(8, 2048, v13 + 1);
    goto LABEL_30;
  }
  v17 = simple_read_from_buffer(a2, a3, a4, v7, v16);
  vfree(v7);
  return v17;
}
