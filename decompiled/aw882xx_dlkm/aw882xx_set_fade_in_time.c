__int64 __fastcall aw882xx_set_fade_in_time(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0

  v2 = *(_QWORD *)(a1 + 120);
  v3 = *(_QWORD *)(a2 + 72);
  if ( v3 <= *(int *)(v2 + 4) )
    aw882xx_dev_set_fade_time(v3, 1);
  return 0;
}
