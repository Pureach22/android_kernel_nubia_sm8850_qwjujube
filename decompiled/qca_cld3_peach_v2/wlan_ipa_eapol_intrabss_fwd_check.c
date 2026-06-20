__int64 __fastcall wlan_ipa_eapol_intrabss_fwd_check(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 **v11; // x0
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  const void *v15; // x0

  v11 = *(__int64 ***)(a1 + 1456);
  if ( v11 && *v11 )
  {
    v12 = **v11;
    if ( v12 )
    {
      v13 = *(__int64 (**)(void))(v12 + 360);
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -1168872836 )
          __break(0x8228u);
        v15 = (const void *)v13();
        if ( v15 )
        {
          if ( !(unsigned int)qdf_mem_cmp(*(const void **)(a11 + 224), v15, 6u) )
            return 1;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_get_vdev_mac_addr");
  }
  return 0;
}
