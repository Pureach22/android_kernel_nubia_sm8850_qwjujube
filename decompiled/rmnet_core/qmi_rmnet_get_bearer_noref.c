__int64 qmi_rmnet_get_bearer_noref()
{
  __int64 result; // x0

  result = _qmi_rmnet_bearer_get();
  if ( result )
    --*(_DWORD *)(result + 20);
  return result;
}
