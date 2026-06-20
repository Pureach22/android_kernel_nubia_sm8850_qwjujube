__int64 __fastcall wcd939x_slave_register_notify(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( result )
  {
    v3 = *(_QWORD *)(result + 224);
    if ( v3 )
    {
      *(_QWORD *)(v3 + 48) = a2;
      *(_QWORD *)(v3 + 56) = a3;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
