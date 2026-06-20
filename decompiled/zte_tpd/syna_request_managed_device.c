__int64 syna_request_managed_device()
{
  if ( p_device )
    return *(_QWORD *)(p_device + 112);
  else
    return 0;
}
