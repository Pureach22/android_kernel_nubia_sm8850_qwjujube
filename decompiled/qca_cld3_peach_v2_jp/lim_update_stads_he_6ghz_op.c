__int64 __fastcall lim_update_stads_he_6ghz_op(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned __int64 v12; // x8
  unsigned int v13; // w8

  if ( *(_BYTE *)(result + 8764) == 1 )
  {
    if ( *(_BYTE *)(a2 + 836) )
    {
      v12 = *(_QWORD *)(a2 + 837);
      if ( (v12 & 0x20000000000000LL) != 0 )
      {
        v13 = 4;
      }
      else if ( (v12 & 0x10000000000000LL) != 0 )
      {
        v13 = 3;
      }
      else
      {
        v13 = (v12 >> 50) & 2;
      }
      if ( v13 >= *(_DWORD *)(result + 7176) )
        v13 = *(_DWORD *)(result + 7176);
      *(_DWORD *)(a2 + 348) = v13;
    }
    else
    {
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: HE cap not present in peer",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_update_stads_he_6ghz_op",
               v10,
               v11);
    }
  }
  return result;
}
