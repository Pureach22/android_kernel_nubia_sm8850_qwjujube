__int64 __fastcall rmnet_get_qos_pt(__int64 result)
{
  if ( result )
    return *(_QWORD *)(result + 3168);
  return result;
}
