__int64 __fastcall gsi_ctrl_dev_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  _DWORD *v3; // x22
  __int64 v4; // x8
  __int64 v5; // x24

  v2 = *(_QWORD *)(a1 + 656);
  if ( v2 == 16 )
  {
    if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_open__rs, "gsi_ctrl_dev_open") )
      printk(&unk_108EF, "gsi_ctrl_dev_open");
    return 4294967277LL;
  }
  v3 = (_DWORD *)(v2 - 848);
  v4 = *(unsigned int *)(v2 - 848);
  if ( (unsigned int)v4 >= 7 )
  {
    __break(0x5512u);
LABEL_18:
    __break(1u);
    return gsi_ctrl_dev_release();
  }
  v5 = v4 << 6;
  if ( v2 != 1072 )
    ipc_log_string(*(_QWORD *)(v2 + 272), "%s: open ctrl dev %s", "gsi_ctrl_dev_open", (const char *)(v2 - 16));
  mutex_lock((char *)&inst_status + v5);
  *(_QWORD *)(a2 + 32) = v3;
  if ( (v5 | 0x30uLL) > 0x180 )
    goto LABEL_18;
  if ( (*((_BYTE *)&inst_status + v5 + 48) & 1) == 0 )
  {
    mutex_unlock((char *)&inst_status + v5);
    if ( v2 != 1072 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 272),
        "%s: [prot_id = %d], GSI instance freed already\n",
        "gsi_ctrl_dev_open",
        *v3);
      printk(&unk_12347, "gsi_ctrl_dev_open");
    }
    return 4294967277LL;
  }
  if ( *(_BYTE *)(v2 + 160) == 1 )
  {
    mutex_unlock((char *)&inst_status + v5);
    if ( v2 != 1072 )
      ipc_log_string(*(_QWORD *)(v2 + 272), "%s: Already opened\n", "gsi_ctrl_dev_open");
    return 4294967280LL;
  }
  else
  {
    *(_BYTE *)(v2 + 160) = 1;
    mutex_unlock((char *)&inst_status + v5);
    return 0;
  }
}
