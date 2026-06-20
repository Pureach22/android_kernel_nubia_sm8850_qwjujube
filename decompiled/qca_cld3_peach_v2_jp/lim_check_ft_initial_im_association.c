__int64 __fastcall lim_check_ft_initial_im_association(
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
  __int64 v12; // x8
  __int64 v13; // x20

  v12 = *(unsigned __int16 *)(result + 8);
  if ( (*(_WORD *)(result + v12) & 0xFC) == 0 )
  {
    *(_BYTE *)(result + 2457) = 1;
    if ( *(_BYTE *)(a2 + 7041) == 1 )
    {
      v13 = result;
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Frame subtype: %d and connection is %d",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "lim_check_ft_initial_im_association",
                 (unsigned __int8)*(_WORD *)(result + v12) >> 4,
                 1,
                 v10,
                 v11);
      *(_BYTE *)(v13 + 2456) = 1;
    }
  }
  return result;
}
