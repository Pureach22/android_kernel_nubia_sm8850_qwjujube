__int64 __fastcall aw882xx_monitor_hal_work(__int64 result, int *a2)
{
  __int64 v3; // x20
  int v4; // w8

  if ( *(_BYTE *)(result + 200) == 1 )
  {
    v3 = result;
    result = aw_monitor_work_func();
    v4 = *(_DWORD *)(v3 + 208);
  }
  else
  {
    v4 = -1;
  }
  *a2 = v4;
  return result;
}
