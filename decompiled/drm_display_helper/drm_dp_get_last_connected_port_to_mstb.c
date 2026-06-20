__int64 __fastcall drm_dp_get_last_connected_port_to_mstb(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 56);
  if ( result )
  {
    if ( *(_QWORD *)(result + 40) == a1 )
      return drm_dp_get_last_connected_port_to_mstb(*(_QWORD *)(result + 1616));
  }
  return result;
}
