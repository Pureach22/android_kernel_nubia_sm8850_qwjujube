void __fastcall csr_scan_event_handler(__int64 a1, __int64 a2, __int64 a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  if ( a3 && (util_is_scan_completed(a2, v12) & 1) != 0 && !(unsigned int)sme_acquire_global_lock(a3 + 12768) )
  {
    if ( *(_BYTE *)(a3 + 17114) == 1 )
      csr_update_channel_list(a3, v4, v5, v6, v7, v8, v9, v10, v11);
    sme_release_global_lock(a3 + 12768);
  }
  _ReadStatusReg(SP_EL0);
}
