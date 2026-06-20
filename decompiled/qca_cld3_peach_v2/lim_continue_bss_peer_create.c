__int64 __fastcall lim_continue_bss_peer_create(unsigned __int8 *a1)
{
  unsigned int v2; // w19
  _BYTE v4[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v5[2]; // [xsp+10h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v4[0] = 0;
  if ( a1 )
  {
    lim_get_mld_info_sta(a1, v5, v4);
    v2 = wma_add_bss_peer_sta(*a1, a1 + 1, 1, v5[0], v4[0]);
    _qdf_mem_free((__int64)a1);
  }
  else
  {
    v2 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
