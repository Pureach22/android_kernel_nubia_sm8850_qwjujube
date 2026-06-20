__int64 __fastcall dp_get_mon_vdev_from_pdev_wifi3(__int64 a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x8

  if ( !a2
    && (v2 = *(_QWORD *)(a1 + 72)) != 0
    && (v3 = *(_QWORD *)(v2 + 95560)) != 0
    && (v4 = *(_QWORD *)(v3 + 16)) != 0 )
  {
    return *(unsigned __int8 *)(v4 + 59);
  }
  else
  {
    return 234;
  }
}
