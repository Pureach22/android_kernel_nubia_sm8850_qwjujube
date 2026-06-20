void __fastcall hdd_wmm_select_queue(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18)
{
  __int64 v19; // x21

  _ReadStatusReg(SP_EL0);
  v19 = *(_QWORD *)(a1 + 2712);
  HIDWORD(a18) = 0;
  LOBYTE(a18) = 0;
  if ( v19 && (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 0x1E) == 0 )
  {
    if ( (_qdf_nbuf_is_ipv4_v6_pure_tcp_ack(a2) & 1) == 0 )
    {
      hdd_wmm_classify_critical_pkt(a2, (int *)&a18 + 1, &a18);
      if ( (a18 & 1) != 0 )
      {
        *(_DWORD *)(a2 + 144) = HIDWORD(a18);
        JUMPOUT(0x3ADCD4);
      }
      JUMPOUT(0x3ADD04);
    }
    JUMPOUT(0x3AE1A8);
  }
  JUMPOUT(0x3AE160);
}
