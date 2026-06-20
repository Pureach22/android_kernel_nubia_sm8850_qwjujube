__int64 __fastcall osif_p2p_service_protocol_type_convert_qca_enum_to_p2p_enum(
        int a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  switch ( a1 )
  {
    case 3:
      *a2 = 3;
      return 0;
    case 2:
      *a2 = 2;
      return 0;
    case 1:
      *a2 = 1;
      return 0;
    default:
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: invalid service protocol type %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "osif_p2p_service_protocol_type_convert_qca_enum_to_p2p_enum",
        v10,
        v11);
      return 4294967274LL;
  }
}
