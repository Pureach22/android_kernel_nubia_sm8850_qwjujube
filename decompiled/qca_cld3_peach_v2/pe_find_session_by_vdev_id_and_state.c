__int64 __fastcall pe_find_session_by_vdev_id_and_state(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  __int64 v12; // x10
  unsigned __int8 v13; // w9
  __int64 result; // x0

  v11 = *(unsigned __int16 *)(a1 + 3992);
  if ( *(_WORD *)(a1 + 3992) )
  {
    v12 = *(_QWORD *)(a1 + 12264);
    v13 = 0;
    while ( 1 )
    {
      result = v12 + 14000LL * v13;
      if ( *(_BYTE *)(result + 70) )
      {
        if ( *(unsigned __int8 *)(result + 10) == a2 && *(_DWORD *)(result + 72) == a3 )
          break;
      }
      if ( v11 <= ++v13 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Session lookup fails for vdev_id: %d, mlm state: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "pe_find_session_by_vdev_id_and_state",
      a2,
      a3);
    return 0;
  }
  return result;
}
