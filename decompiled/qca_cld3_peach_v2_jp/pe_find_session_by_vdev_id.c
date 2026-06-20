__int64 __fastcall pe_find_session_by_vdev_id(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  __int64 v11; // x10
  unsigned __int8 v12; // w9
  __int64 result; // x0

  v10 = *(unsigned __int16 *)(a1 + 3992);
  if ( *(_WORD *)(a1 + 3992) )
  {
    v11 = *(_QWORD *)(a1 + 12264);
    v12 = 0;
    while ( 1 )
    {
      result = v11 + 10792LL * v12;
      if ( *(_BYTE *)(result + 70) )
      {
        if ( *(unsigned __int8 *)(result + 10) == a2 )
          break;
      }
      if ( v10 <= ++v12 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Session lookup fails for vdev_id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pe_find_session_by_vdev_id",
      a2);
    return 0;
  }
  return result;
}
