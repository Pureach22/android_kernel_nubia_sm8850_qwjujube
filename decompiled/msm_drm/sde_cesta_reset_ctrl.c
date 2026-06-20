size_t __fastcall sde_cesta_reset_ctrl(int *a1, char a2)
{
  __int64 v4; // x21
  size_t result; // x0
  _DWORD *v6; // x8
  __int64 v7; // x1
  char v8; // [xsp+0h] [xbp+0h]

  if ( !a1 || a1[1] )
    return printk(&unk_213914, "sde_cesta_reset_ctrl");
  v4 = cesta_list_0;
  result = sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_reset_ctrl", 194, -1, *a1, a1[2], a2 & 1, -1059143953, v8);
  v6 = *(_DWORD **)(v4 + 896);
  if ( v6 )
  {
    v7 = (unsigned int)*a1;
    if ( *(v6 - 1) != 482064666 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v4, v7, a2 & 1);
  }
  return result;
}
