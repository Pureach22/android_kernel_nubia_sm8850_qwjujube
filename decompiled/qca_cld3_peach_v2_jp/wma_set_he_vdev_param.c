__int64 __fastcall wma_set_he_vdev_param(
        __int64 result,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30

  if ( a2 == 107 )
  {
    *(_BYTE *)(result + 145) = a3;
  }
  else if ( a2 == 106 )
  {
    *(_BYTE *)(result + 144) = a3;
  }
  else
  {
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Unhandled HE vdev param: %0x",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wma_set_he_vdev_param",
             a2,
             v11,
             v12);
  }
  return result;
}
