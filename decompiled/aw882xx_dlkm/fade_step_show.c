__int64 __fastcall fade_step_show(__int64 a1, __int64 a2, char *a3)
{
  int fade_vol_step; // w0

  fade_vol_step = aw882xx_dev_get_fade_vol_step(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL));
  return snprintf(a3, 0x1000u, "step: %d\n", fade_vol_step);
}
