__int64 __fastcall hif_get_dp_rx_napi(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // d15
  __int64 v8; // d25

  if ( result )
  {
    if ( *(_DWORD *)(result + 27264) <= (unsigned int)(unsigned __int8)a2 )
    {
      return 0;
    }
    else if ( (unsigned __int8)a2 >= 0x12u )
    {
      __break(0x5512u);
      *(_QWORD *)(a7 + 56) = v7;
      *(_QWORD *)(a7 + 64) = v8;
      return hif_get_napi(result, a2);
    }
    else
    {
      return *(_QWORD *)(result + 8LL * (unsigned __int8)a2 + 27120) + 6208LL;
    }
  }
  return result;
}
