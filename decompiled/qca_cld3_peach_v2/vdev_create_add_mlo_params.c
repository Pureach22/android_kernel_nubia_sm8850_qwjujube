__int64 __fastcall vdev_create_add_mlo_params(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a2 + 26) | *(unsigned __int16 *)(a2 + 30) )
  {
    *(_QWORD *)a1 = 0x3D700080012000CLL;
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 26);
    *(_DWORD *)(a1 + 12) = *(unsigned __int16 *)(a2 + 30);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: MLD Addr = %02x:%02x:%02x:**:**:%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "vdev_create_add_mlo_params",
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 27),
      *(unsigned __int8 *)(a2 + 28),
      *(unsigned __int8 *)(a2 + 31));
    v11 = a1 + 16;
  }
  else
  {
    v11 = a1 + 4;
    *(_DWORD *)a1 = 1179648;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
