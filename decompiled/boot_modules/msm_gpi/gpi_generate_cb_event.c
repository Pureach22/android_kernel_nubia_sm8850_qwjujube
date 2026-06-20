__int64 __fastcall gpi_generate_cb_event(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x23
  unsigned int *v7; // x0
  unsigned int v8; // w22
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 (__fastcall *v12)(__int64, __int64 *, __int64); // x8
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-48h] BYREF
  __int64 v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 280);
  v7 = *(unsigned int **)(a1 + 296);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v8 = ((unsigned int)readl_relaxed(v7) >> 20) & 0xF;
  if ( *(_DWORD *)(v6 + 1068) < 2u )
  {
    v9 = *(_QWORD *)(v6 + 1056);
    if ( !v9 )
      goto LABEL_6;
    goto LABEL_3;
  }
  if ( a2 > 7 )
    goto LABEL_12;
  printk(
    &unk_14544,
    v6 + 1076,
    *(unsigned int *)(a1 + 256),
    "gpi_generate_cb_event",
    gpi_cb_event_str[a2],
    a3,
    gpi_ch_state_str[v8]);
  v9 = *(_QWORD *)(v6 + 1056);
  if ( v9 )
  {
LABEL_3:
    if ( *(_DWORD *)(v6 + 1064) < 2u )
      goto LABEL_6;
    if ( a2 <= 7 )
    {
      v9 = ipc_log_string(
             v9,
             "ch:%u %s: notifying event:%s with status:%llu ch_state:%s\n",
             *(_DWORD *)(a1 + 256),
             "gpi_generate_cb_event",
             gpi_cb_event_str[a2],
             a3,
             gpi_ch_state_str[v8]);
      goto LABEL_6;
    }
LABEL_12:
    __break(1u);
  }
LABEL_6:
  LODWORD(v14) = a2;
  v15 = a3;
  v10 = sched_clock(v9);
  v12 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(a1 + 368);
  v11 = *(_QWORD *)(a1 + 376);
  v16 = v10;
  if ( *((_DWORD *)v12 - 1) != 1361247836 )
    __break(0x8228u);
  result = v12(a1, &v14, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
