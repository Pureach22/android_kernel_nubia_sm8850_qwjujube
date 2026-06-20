__int64 __fastcall aw882xx_dev_deinit(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 640);
    if ( result )
    {
      result = kfree(result);
      *(_QWORD *)(v1 + 640) = 0;
      *(_DWORD *)(v1 + 624) = 0;
    }
  }
  return result;
}
