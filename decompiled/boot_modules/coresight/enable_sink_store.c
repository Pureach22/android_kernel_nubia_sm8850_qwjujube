__int64 __fastcall enable_sink_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  __int64 enabled_sink_from_bus; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v6 = kstrtoull(a3, 10, v9);
  if ( v6 )
  {
    a4 = v6;
  }
  else if ( v9[0]
         && (enabled_sink_from_bus = coresight_get_enabled_sink_from_bus(0)) != 0
         && *(_DWORD *)(enabled_sink_from_bus + 8) != *(_DWORD *)(a1 - 48) )
  {
    dev_err(a1, "Another type sink is enabled.\n");
    a4 = -22;
  }
  else
  {
    *(_BYTE *)(a1 + 925) = v9[0] != 0;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
