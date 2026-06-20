__int64 __fastcall sde_cesta_force_db_update(int *a1, char a2, unsigned int a3, char a4, char a5, char a6)
{
  __int64 v9; // x20
  unsigned int v10; // w24
  unsigned int v11; // w23
  unsigned int v12; // w25
  _DWORD *v13; // x8
  __int64 v14; // x1

  if ( !a1 || a1[1] )
    return printk(&unk_213914, "sde_cesta_force_db_update");
  v9 = cesta_list_0;
  v10 = a5 & 1;
  v11 = a4 & 1;
  v12 = a6 & 1;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_force_db_update", 172, -1, *a1, a1[2], a2 & 1, a3, a4 & 1);
  mutex_lock(v9 + 800);
  v13 = *(_DWORD **)(v9 + 904);
  if ( v13 )
  {
    v14 = (unsigned int)*a1;
    if ( *(v13 - 1) != -1110483595 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v13)(
      v9,
      v14,
      a2 & 1,
      a3,
      v11,
      v10,
      v12);
  }
  return mutex_unlock(v9 + 800);
}
