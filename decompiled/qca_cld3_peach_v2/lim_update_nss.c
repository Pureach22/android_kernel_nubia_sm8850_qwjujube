__int64 __fastcall lim_update_nss(
        __int64 result,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v12; // w9
  __int64 v13; // x19
  _WORD v15[2]; // [xsp+Ch] [xbp-14h] BYREF
  int v16; // [xsp+10h] [xbp-10h] BYREF
  __int16 v17; // [xsp+14h] [xbp-Ch]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 + 1 != *(unsigned __int8 *)(a2 + 364) )
  {
    if ( *(_BYTE *)(a4 + 8636) == 1 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Not Updating NSS for special AP",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "lim_update_nss");
    }
    else
    {
      *(_BYTE *)(a2 + 364) = a3 + 1;
      v17 = 0;
      v16 = 0;
      if ( a3 == 0xFF )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: Invalid rxNss value: %u",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_set_nss_change",
                   0);
      }
      else
      {
        v12 = *(unsigned __int8 *)(a4 + 10);
        v13 = result;
        v15[0] = (unsigned __int8)(a3 + 1);
        v15[1] = v12;
        qdf_mem_copy(&v16, (const void *)(a2 + 350), 6u);
        result = lim_send_rx_nss_update(v13, v15, a4);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
