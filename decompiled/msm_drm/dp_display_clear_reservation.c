__int64 __fastcall dp_display_clear_reservation(__int64 a1, __int64 a2)
{
  __int64 v5; // x0

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 608);
    *(_DWORD *)(a1 + 716) -= *(_DWORD *)(a2 + 936);
    *(_DWORD *)(a2 + 936) = 0;
    return mutex_unlock(a1 + 608);
  }
  else
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    ipc_log_string(v5, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_24B695, "dp_display_clear_reservation");
  }
}
