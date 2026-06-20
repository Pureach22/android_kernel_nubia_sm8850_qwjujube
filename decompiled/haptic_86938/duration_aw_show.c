__int64 __fastcall duration_aw_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x20
  __int64 v5; // x3

  v3 = *(_QWORD *)(a1 + 152);
  if ( (hrtimer_active(v3 + 648) & 1) != 0 )
    v5 = _hrtimer_get_remaining(v3 + 648, 0) / 1000000;
  else
    v5 = 0;
  return snprintf(a3, 0x1000u, "duration = %lldms\n", v5);
}
