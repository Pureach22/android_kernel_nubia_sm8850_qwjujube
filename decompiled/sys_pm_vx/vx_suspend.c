__int64 __fastcall vx_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 120) == 1 )
  {
    v2 = ktime_get_with_offset(1);
    v3 = *(_DWORD *)(v1 + 132);
    *(_QWORD *)(v1 + 104) = v2;
    if ( v3 )
      sys_pm_vx_send_msg(v1);
  }
  return 0;
}
