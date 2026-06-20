__int64 __fastcall hif_ce_bus_early_suspend(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v4; // x22
  __int64 v5; // x23
  unsigned __int64 v6; // x21
  unsigned __int64 StatusReg; // x25
  __int64 v8; // x8
  __int64 v9; // x27
  _BYTE v10[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v11[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v12[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v12[0] = 0;
  v2 = hif_map_service_to_pipe(a1, 256, v13, v12, v11, v10);
  if ( v2 )
  {
    qdf_trace_msg(61, 2, "%s: pipe_mapping failure", "hif_ce_bus_early_suspend");
  }
  else if ( *(_DWORD *)(a1 + 656) )
  {
    v4 = v13[0];
    v5 = v12[0];
    v6 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( v4 != v6 && v5 != v6 )
      {
        if ( v6 >= 0xC )
          __break(0x5512u);
        v9 = *(_QWORD *)(a1 + 480 + 8 * v6);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v9 + 168);
        }
        else
        {
          raw_spin_lock_bh(v9 + 168);
          *(_QWORD *)(v9 + 176) |= 1uLL;
        }
        if ( *(_DWORD *)(v9 + 20) == 2 )
          *(_DWORD *)(v9 + 20) = 1;
        v8 = *(_QWORD *)(v9 + 176);
        if ( (v8 & 1) != 0 )
        {
          *(_QWORD *)(v9 + 176) = v8 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v9 + 168);
        }
        else
        {
          raw_spin_unlock(v9 + 168);
        }
      }
      ++v6;
    }
    while ( v6 < *(unsigned int *)(a1 + 656) );
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
