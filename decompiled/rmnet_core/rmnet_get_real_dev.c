__int64 __fastcall rmnet_get_real_dev(__int64 result)
{
  if ( result )
    return *(_QWORD *)result;
  return result;
}
