__int64 __fastcall show_updown_migrate_handle(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 *v6; // x10
  char *v7; // x28
  _DWORD *v8; // x19
  _DWORD *v9; // x24
  _DWORD *v10; // x27
  _DWORD *v11; // x26
  _DWORD *v12; // x8
  _DWORD *v13; // x25
  int v14; // w22
  int v15; // w0
  int v16; // w19
  int v17; // w19
  int v18; // w19
  int v19; // w19
  int v20; // w19
  int v21; // w19
  int v22; // w19
  _DWORD *v24; // [xsp+8h] [xbp-8h]

  mutex_lock(&ud_value_data_lock);
  if ( (a4 & 1) != 0 )
    v6 = &sched_early_up_migrate;
  else
    v6 = &sched_early_down_migrate;
  if ( (a4 & 1) != 0 )
    v7 = (char *)&sched_early_up_migrate + 4;
  else
    v7 = (char *)&sched_early_down_migrate + 4;
  if ( (a4 & 1) != 0 )
    v8 = &unk_6ADF8;
  else
    v8 = &unk_6AE18;
  if ( (a4 & 1) != 0 )
    v9 = &unk_6ADFC;
  else
    v9 = &unk_6AE1C;
  if ( (a4 & 1) != 0 )
    v10 = &unk_6AE00;
  else
    v10 = &unk_6AE20;
  if ( (a4 & 1) != 0 )
    v11 = &unk_6AE04;
  else
    v11 = &unk_6AE24;
  v12 = &unk_6AE0C;
  if ( (a4 & 1) != 0 )
  {
    v13 = &unk_6AE08;
  }
  else
  {
    v12 = &unk_6AE2C;
    v13 = &unk_6AE28;
  }
  v24 = v12;
  v14 = scnprintf(a3, 4096, " %d", *(unsigned int *)v6);
  v15 = scnprintf(a3 + v14, 4096LL - v14, " %d", *(_DWORD *)v7);
  v16 = scnprintf(a3 + v15 + v14, 4096LL - (v15 + v14), " %d", *v8) + v15 + v14;
  v17 = scnprintf(a3 + v16, 4096LL - v16, " %d", *v9) + v16;
  v18 = scnprintf(a3 + v17, 4096LL - v17, " %d", *v10) + v17;
  v19 = scnprintf(a3 + v18, 4096LL - v18, " %d", *v11) + v18;
  v20 = scnprintf(a3 + v19, 4096LL - v19, " %d", *v13) + v19;
  v21 = scnprintf(a3 + v20, 4096LL - v20, " %d", *v24) + v20;
  v22 = scnprintf(a3 + v21, 4096LL - v21, "\n") + v21;
  mutex_unlock(&ud_value_data_lock);
  return v22;
}
