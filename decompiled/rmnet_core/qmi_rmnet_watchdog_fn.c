__int64 __fastcall qmi_rmnet_watchdog_fn(__int64 a1)
{
  int v2; // w9
  unsigned int v3; // w8
  __int64 v4; // x2
  __int64 v5; // x8

  raw_spin_lock_bh(*(_QWORD *)(a1 - 8) + 332LL);
  if ( (*(_BYTE *)(a1 + 41) & 1) == 0 )
  {
    v2 = *(_DWORD *)(a1 + 44);
    v3 = *(_DWORD *)(a1 - 56);
    *(_DWORD *)(a1 - 36) = 0;
    *(_DWORD *)(a1 + 44) = v2 + 1;
    if ( v3 )
    {
      *(_DWORD *)(a1 - 52) = v3 / qmi_rmnet_scale_factor;
    }
    else
    {
      v4 = *(_QWORD *)(a1 - 8);
      *(_DWORD *)(a1 - 56) = 20480;
      *(_DWORD *)(a1 - 52) = 0x5000u / qmi_rmnet_scale_factor;
      dfc_bearer_flow_ctl(*(_QWORD *)(v4 + 32), a1 - 80, v4);
    }
  }
  v5 = *(_QWORD *)(a1 - 8);
  *(_BYTE *)(a1 + 40) = 0;
  return raw_spin_unlock_bh(v5 + 332);
}
