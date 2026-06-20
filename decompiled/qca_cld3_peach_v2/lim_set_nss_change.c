bool __fastcall lim_set_nss_change(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        const void *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v13; // w9
  _WORD v17[2]; // [xsp+Ch] [xbp-14h] BYREF
  int v18; // [xsp+10h] [xbp-10h] BYREF
  __int16 v19; // [xsp+14h] [xbp-Ch]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v18 = 0;
  if ( a3 )
  {
    v13 = *(unsigned __int8 *)(a2 + 10);
    v17[0] = a3;
    v17[1] = v13;
    qdf_mem_copy(&v18, a4, 6u);
    lim_send_rx_nss_update(a1, v17, a2);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid rxNss value: %u", a5, a6, a7, a8, a9, a10, a11, a12, "lim_set_nss_change", 0);
  }
  _ReadStatusReg(SP_EL0);
  return a3 != 0;
}
