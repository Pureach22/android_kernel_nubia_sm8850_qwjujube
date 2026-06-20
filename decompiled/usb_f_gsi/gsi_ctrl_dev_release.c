__int64 __fastcall gsi_ctrl_dev_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  char *v4; // x20
  char *v5; // x0
  __int64 v6; // x19

  v2 = **(unsigned int **)(a2 + 32);
  if ( (unsigned int)v2 >= 7 )
    goto LABEL_15;
  v3 = v2 << 6;
  v4 = (char *)&inst_status + 64 * v2;
  a1 = mutex_lock(v4);
  if ( (((unsigned __int64)(unsigned int)v2 << 6) | 0x30) > 0x180 )
    goto LABEL_14;
  if ( (v4[48] & 1) != 0 )
  {
    if ( (v3 | 0x38uLL) <= 0x180 )
    {
      v5 = (char *)&inst_status + 64 * v2;
      *(_BYTE *)(*(_QWORD *)(*((_QWORD *)v4 + 7) + 176LL) + 1232LL) = 0;
      v6 = *(_QWORD *)(*((_QWORD *)v4 + 7) + 176LL);
      mutex_unlock(v5);
      if ( v6 )
        ipc_log_string(
          *(_QWORD *)(v6 + 1344),
          "close ctrl dev %s\n",
          (const char *)(*(_QWORD *)(*((_QWORD *)v4 + 7) + 176LL) + 1056LL));
      return 0;
    }
    goto LABEL_14;
  }
  if ( (v3 | 0x38uLL) > 0x180 )
  {
LABEL_14:
    __break(1u);
LABEL_15:
    __break(0x5512u);
    return list_del(a1);
  }
  if ( *((_QWORD *)v4 + 7) )
  {
    gsi_inst_clean();
    *((_QWORD *)v4 + 7) = 0;
  }
  mutex_unlock((char *)&inst_status + 64 * v2);
  if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_release__rs, "gsi_ctrl_dev_release") )
    printk(&unk_10166, "gsi_ctrl_dev_release");
  return 4294967277LL;
}
