__int64 __fastcall dp_aux_set_sim_mode(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(); // x8
  __int64 v5; // x8

  if ( a1 )
  {
    mutex_lock(a1 + 144);
    *(_QWORD *)(a1 + 1792) = a2;
    if ( a2 )
    {
      *(_DWORD *)(a1 + 1832) = 0;
      v4 = dp_aux_transfer_debug;
    }
    else
    {
      v5 = *(_QWORD *)(a1 + 1784);
      if ( v5 && *(_QWORD *)(v5 + 56) )
        v4 = dp_aux_bridge_transfer;
      else
        v4 = dp_aux_transfer;
    }
    *(_QWORD *)(a1 + 1584) = v4;
    return mutex_unlock(a1 + 144);
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_set_sim_mode");
  }
}
