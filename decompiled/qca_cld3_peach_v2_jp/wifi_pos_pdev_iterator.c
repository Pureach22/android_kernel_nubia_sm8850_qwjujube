void __fastcall wifi_pos_pdev_iterator(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 psoc; // x0
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  a10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(a9) = 0;
  psoc = wifi_pos_get_psoc(a1);
  if ( wifi_pos_get_psoc_priv_obj(psoc) )
  {
    if ( a3 )
    {
      if ( *a3 < 0x67uLL )
      {
        v13 = _qdf_mem_malloc(0x4C8u, "wifi_pos_pdev_iterator", 519);
        if ( v13 )
        {
          if ( (unsigned int)wlan_reg_get_channel_list_with_power_for_freq(
                               a2,
                               v13,
                               (_BYTE *)&a9 + 4,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19,
                               v20,
                               v21) )
            JUMPOUT(0x5FBB4C);
          JUMPOUT(0x5FBB8C);
        }
        JUMPOUT(0x5FBB6C);
      }
      JUMPOUT(0x5FBCD4);
    }
    JUMPOUT(0x5FBB60);
  }
  JUMPOUT(0x5FBB54);
}
